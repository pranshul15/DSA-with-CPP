"""
This python code is used for downloading files from google drive given the proper authentication
"""
import os.path
import io
from googleapiclient.http import MediaIoBaseDownload


def drive_dl(drive_service, file_id, path):
    request = drive_service.files().get_media(fileId=file_id)
    fh = io.BytesIO()        # fh is a byte_based buffer to which the file will be downloaded before writing to the system. The buffer stores the file in RAM until it is written to disk
    downloader = MediaIoBaseDownload(fh, request)   # A download object which is used to download files to the above byte buffer
    done = False
    while done is False:
        status, done = downloader.next_chunk()
        print("Download %d%%." % int(status.progress() * 100))
    fh.seek(0)
    with open(os.path.join(path), 'wb') as f:   #writing from the byte buffer to the disk
        f.write(fh.read())
        f.close()
