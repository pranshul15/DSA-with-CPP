"""
Used to update the courses, their announcements and classwork materials when the program is first used by a user or when using this with an account for the first time or in case of 
file deletion from the system
"""
import os
import drive_download

"""
The below function updates the list of courses to which the google account of the user is linked to. The courses joined after the previous update are added to the 'course_list.txt'
file along with their name and course_id. The directories for these courses are also created.
"""
def update_course_list(classroom_service):
    course_info = classroom_service.courses().list(fields='courses(id,name)').execute() #the fields parameter is used for fetching only the required fields from the server thus reducing load and improving performance
    available_courses = []
    no_of_avail_courses = len(course_info['courses'])
    for i in range(no_of_avail_courses):
        available_courses.append((course_info['courses'][i]['id'] + ' ' + course_info['courses'][i]['name']) + '\n')
        if not os.path.exists('/home/pratham/Classroom/' + course_info['courses'][i]['name']):
            os.makedirs('/home/pratham/Classroom/' + course_info['courses'][i]['name'] + '/update/courseWorkMaterials')
            os.makedirs('/home/pratham/Classroom/' + course_info['courses'][i]['name'] + '/update/announcements')
    if no_of_avail_courses == 0:
        print("No classes presently available")
        return None
    if not os.path.isfile('./course_list.txt'):
        open('./course_list.txt', 'a').close()
    new_courses = []
    with open('course_list.txt', 'r+') as course_list:
        course_list_arr = course_list.readlines()
        if set(course_list_arr) != set(available_courses):
            new_courses = list(set(available_courses) - set(course_list_arr))
            course_list.seek(0)
            course_list.writelines(available_courses)
            course_list.truncate()
    return new_courses

"""
This function is used for updating the courseWorkMaterial for the newly joined courses after the previous update. All the course_work material are downloaded to their respective 
directories
"""
def update_courseWorkMaterial(classroom_service, drive_service, new_courses):
    with open("./courseWorkMaterial_token.txt", "a") as courseWorkMaterial_token_file:
        for course in new_courses:
            (course_id, course_name) = (course.split()[0], course.split(" ", 1)[1].rsplit('\n')[0])
            course_work_material_info = classroom_service.courses().courseWorkMaterials().list(courseId=course_id,
                                                                                               orderBy='updateTime asc',
                                                                                               fields="courseWorkMaterial/materials/driveFile/driveFile(id,title)").execute()

            if 'courseWorkMaterial' in course_work_material_info:
                no_of_courseWorkMaterial = len(course_work_material_info['courseWorkMaterial'])
                courseWorkMaterial_token = classroom_service.courses().courseWorkMaterials().list(courseId=course_id,
                                                                                                  orderBy='updateTime asc',
                                                                                                  fields="nextPageToken",
                                                                                                  pageSize=no_of_courseWorkMaterial - 1).execute()
                """
                All of the above things are done for getting the nextPageToken which is used for accessing the next batch of results from the server. There is no way of getting
                the total number of courseWorkMaterials from the server provided by the API otherwise it could have been done in a much more easier way
                """
                courseWorkMaterial_token_file.write(courseWorkMaterial_token['nextPageToken'] + "\n")
                for course_work_material in course_work_material_info['courseWorkMaterial']:
                    for material in course_work_material['materials']:
                        file_id = material['driveFile']['driveFile']['id']
                        file_title = material['driveFile']['driveFile']['title']
                        drive_download.drive_dl(drive_service, file_id,
                                                "/home/pratham/Classroom/" + course_name + "/update/courseWorkMaterials/" + file_title)

"""
Similar to the above function but used for downloading announcements rather than courseWorkMaterials
"""
def update_course_announcements(classroom_service, drive_service, new_courses):
    with open("./announcement_tokens.txt", "a") as announcement_token_file:
        for course in new_courses:
            (course_id, course_name) = (course.split()[0], course.split(" ", 1)[1].rsplit('\n')[0])
            announcement_info = classroom_service.courses().announcments().list(course_id, orderBy='updateTime asc',
                                                                                fields='announcements/(id, '
                                                                                       'materials/driveFile'
                                                                                       '/driveFile(id,title))')
            if "announcements" in announcement_info:
                no_of_announcements = len(announcement_info['announcements'])
                announcement_token = classroom_service.courses().announcments().list(course_id,
                                                                                     orderBy='updateTime asc',
                                                                                     fields='nextPageToken',
                                                                                     pageSize=no_of_announcements - 1)
                announcement_token_file.write(announcement_token['nextPageToken'] + "\n")
                for announcement in announcement_info["announcements"]:
                    for material in announcement['materials']:
                        file_id = material['driveFile']['driveFile']['id']
                        file_title = material['driveFile']['driveFile']['title']
                        drive_download.drive_dl(drive_service, file_id,
                                                "/home/pratham/Classroom/" + course_name + "/update/announcements/" + file_title)
