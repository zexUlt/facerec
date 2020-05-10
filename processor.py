import base64
import datetime
import glob
import json
import os
import shutil
import sys
import time
import urllib

import cv2
import insightface
import numpy as np

# import threading

# os.environ["OPENCV_FFMPEG_CAPTURE_OPTIONS"] = "rtsp_transport;tcp"

input("1")
# model = insightface.app.FaceAnalysis(det_name='retinaface_r50_v1', rec_name='arcface_r100_v1', ga_name='genderage_v1')
model = insightface.app.FaceAnalysis(det_name='retinaface_mnet025_v2', rec_name='arcface_r100_v1', ga_name=None)
input("2")
model.prepare(ctx_id=0, nms=0.4)

input("3")

def putText(img, text, text_offset_x, text_offset_y, font_scale=1.5):
    font = cv2.FONT_HERSHEY_PLAIN
    # set the rectangle background to white
    rectangle_bgr = (255, 255, 255)
    # get the width and height of the text box
    (text_width, text_height) = cv2.getTextSize(text, font, fontScale=font_scale, thickness=1)[0]
    # set the text start position
    # text_offset_x = 10
    # text_offset_y = img.shape[0] - 25
    # make the coords of the box with a small padding of two pixels
    box_coords = ((text_offset_x, text_offset_y), (text_offset_x + text_width - 2, text_offset_y - text_height - 2))
    img = cv2.rectangle(img, box_coords[0], box_coords[1], rectangle_bgr, cv2.FILLED)
    img = cv2.putText(img, text, (text_offset_x, text_offset_y), font, fontScale=font_scale, color=(0, 0, 0), thickness=1)

    return img


def prepare_database(pathToIndentity):
    database = {}

    # load all the images of individuals to recognize into the database
    # for file in glob.glob("D:/DAN/facerec/database/*"):
    identity = os.path.splitext(os.path.basename(pathToIndentity))[0]
    # embedding_norm, embedding, normed_embedding
    database[identity] = model.get(cv2.imread(pathToIndentity))[0].embedding

    return database


def process_frame(img):
    faces = model.get(img, det_thresh=0.8, det_scale=1.0, max_num=0)
    
    finded = False

    for idx, face in enumerate(faces):
        bbox = face.bbox.astype(np.int).flatten()
        
        identity = who_is_it(face.normed_embedding)
        if identity is None:
            img = cv2.rectangle(img, (bbox[0], bbox[1]), (bbox[2], bbox[3]), (0, 0, 255), 2)
        else:
            finded = True
            img = cv2.rectangle(img, (bbox[0], bbox[1]), (bbox[2], bbox[3]), (255, 255, 255), 2)
            img = putText(img, identity, bbox[2], bbox[3])

    if not finded:
        return None
    
    return img


def who_is_it(embedding):
    max_sim = 0
    identity = None
    for (name, db_embedding) in database.items():
        sim = np.dot(db_embedding, embedding) / (np.linalg.norm(db_embedding) * np.linalg.norm(embedding))
        if sim > max_sim:
            max_sim = sim
            identity = name

    if max_sim <= 0.4:
        return None
    else:
        return str(identity)


def sendPhotosToDB(path):
    shutil.copy2(path, "database")


def autotune(img):
    print('MXNET AUTOTUNE START: ')
    print(datetime.datetime.now())
    process_frame(img)
    print('MXNET AUTOTUNE END: ')
    print(datetime.datetime.now())


if __name__ == "__main__":
    pathToJson = sys.argv[1]

    with open(pathToJson) as packedData:
        data = json.load(packedData)
    input("4")
    print(data)
    pPhoto = data["photo"]
    pVideo = [(name, time) for name, time in data['video'].items()]
    print(pVideo)
    input("5")
    pOut = data["out"]
    # videoTimeCodeStart = data["video"][1], data["video"][2]

    database = prepare_database(pPhoto)
    print('WORKING')
    vs = cv2.VideoCapture(pVideo[0][0])

    ret, img = vs.read()
    # cv2.imwrite('D:/DAN/facerec/out/test.jpg', img=img)
    # print(img)
    # autotune(img)

    frame_num = 0
    fps = vs.get(cv2.CAP_PROP_FPS)
    time_limit = 2*fps - 1

    start = time.time()
    while True:
        frame_num += 1

        ret, img = vs.read()

        if not ret:
            break
        # print('STILL WORKING')
        tmp = process_frame(img)
        # print(img)
        if tmp is not None:
            print('IMG IS NOT NONE')
            print(str(datetime.timedelta(seconds=(frame_num/fps))).replace(":", "-"))
            errn0 = cv2.imwrite(pOut + '/frame_at_' +
                                str(datetime.timedelta(seconds=(frame_num/fps))).replace(":", "-") + '.jpg', tmp)
            print("Image Saved: ", errn0)
            vs.set(cv2.CAP_PROP_POS_FRAMES, frame_num + time_limit)
            frame_num += time_limit

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    print(time.time() - start)
    vs.release()
    cv2.destroyAllWindows()
