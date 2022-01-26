# Gclassdownload
Will check for new announcements or courseworkMaterials updated on google classroom and automatically download it and give a desktop notification.


In order to use this you must get a credentials.json file from console.cloud.google.com . You must start a new project and get OAuth2.0 credentials in a json file. Put this 
json file in the same directory as the code and the rest will be done by itself. The scopes to be enabled in the OAuth consent screen are as follows :

'https://www.googleapis.com/auth/classroom.courses.readonly',
'https://www.googleapis.com/auth/classroom.course-work.readonly',
'https://www.googleapis.com/auth/classroom.announcements.readonly',
'https://www.googleapis.com/auth/classroom.topics.readonly',
'https://www.googleapis.com/auth/classroom.courseworkmaterials.readonly',
'https://www.googleapis.com/auth/drive.readonly'
