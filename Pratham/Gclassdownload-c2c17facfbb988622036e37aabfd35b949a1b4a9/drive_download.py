import os.path
import io
from googleapiclient.http import MediaIoBaseDownload


def drive_dl(drive_service, file_id, path):
    request = drive_service.files().get_media(fileId=file_id)
    fh = io.BytesIO()
    downloader = MediaIoBaseDownload(fh, request)
    done = False
    while done is False:
        status, done = downloader.next_chunk()
        print("Download %d%%." % int(status.progress() * 100))
    fh.seek(0)
    with open(os.path.join(path), 'wb') as f:
        f.write(fh.read())
        f.close()
