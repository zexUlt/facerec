import datetime
import json
import os
import sys
import time
import multiprocessing as mp

import cv2
import insightface
import numpy as np

# import threading
timelog = open('D:/DAN/facerec/Timetimelog.timelog', 'a')
    
# model = insightface.app.FaceAnalysis(det_name='retinaface_r50_v1', rec_name='arcface_r100_v1', ga_name='genderage_v1')
model = insightface.app.FaceAnalysis(det_name='retinaface_mnet025_v2', rec_name='arcface_r100_v1', ga_name=None)
start = time.time()
model.prepare(ctx_id=0, nms=0.4)
timelog.write("Model preparing time: " + str(time.time() - start) + '\n')

def putText(image, text, text_offset_x, text_offset_y, font_scale=1.5):
    font = cv2.FONT_HERSHEY_PLAIN
    # set the rectangle background to white
    rectangle_bgr = (255, 255, 255)
    # get the width and height of the text box
    (text_width, text_height) = cv2.getTextSize(text, font, fontScale=font_scale, thickness=1)[0]
    # make the coords of the box with a small padding of two pixels
    box_coords = ((text_offset_x, text_offset_y), (text_offset_x + text_width - 2, text_offset_y - text_height - 2))
    image = cv2.rectangle(image, box_coords[0], box_coords[1], rectangle_bgr, cv2.FILLED)
    image = cv2.putText(image, text, (text_offset_x, text_offset_y), font, fontScale=font_scale, color=(0, 0, 0),
                        thickness=1)
    return image


def prepare_database(pathToIndentity):
    db = dict()
    global timelog

    # load all the images of individuals to recognize into the database
    identity = os.path.splitext(os.path.basename(pathToIndentity))[0]
    # embedding_norm, embedding, normed_embedding
    image = cv2.imread(pathToIndentity)
    scale_percent = 60  # percent of original size
    width = int(image.shape[1] * scale_percent / 100)
    height = int(image.shape[0] * scale_percent / 100)
    dim = (width, height)
    # resize image
    resized = cv2.resize(image, dim, interpolation=cv2.INTER_AREA)
    start = time.time()
    db[identity] = model.get(resized)[0].embedding
    timelog.write("Embedding construction: " + str(time.time() - start) + '\n')

    return db


def process_frame(image):
    faces = model.get(image, det_thresh=0.8, det_scale=1.0, max_num=0)
    
    found = False

    for idx, face in enumerate(faces):
        bbox = face.bbox.astype(np.int).flatten()
        
        identity = who_is_it(face.normed_embedding)
        if identity is not None:
            found = True
            image = cv2.rectangle(image, (bbox[0], bbox[1]), (bbox[2], bbox[3]), (255, 255, 255), 2)
            image = putText(image, identity, bbox[2], bbox[3])

    if not found:
        return None
    
    return image


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


def process(processList, pOut, startFrame, endFrame):
    global pVideo
    cap = cv2.VideoCapture(pVideo[0][0])
    log = open("D:/DAN/facerec/Process.log", 'a')

    frame_num = 0
    fps = cap.get(cv2.CAP_PROP_FPS)
    time_limit = 2*fps - 1

    for frame in range(startFrame, endFrame):
        cap.set(cv2.CAP_PROP_POS_FRAMES, frame)
        ret, img = cap.read()

        # if not ret:
        #     break
        log.write("Running " + mp.current_process().name)
        tmp = process_frame(img)
        if tmp is not None:
            log.write("Found " + mp.current_process().name)
            errn0 = cv2.imwrite(pOut + '/frame_at_' +
                                str(datetime.timedelta(seconds=(frame_num / fps))).replace(":", "-") + '.jpg', tmp)
            cap.set(cv2.CAP_PROP_POS_FRAMES, frame_num + time_limit)
            frame_num += time_limit
        cap.release()


if __name__ == "__main__":
    # pathToJson = sys.argv[1]
    pathToJson = "D:/DAN/facerec/JsonTest.json"

    with open(pathToJson) as packedData:
        data = json.load(packedData)

    pPhoto = data["photo"]
    pVideo = [(name, time) for name, time in data['video'].items()]
    pOut = data["out"]

    database = prepare_database(pPhoto)

    temp_cap = cv2.VideoCapture(pVideo[0][0])
    fileLen = int(temp_cap.get(cv2.CAP_PROP_FRAME_COUNT))
    temp_cap.release()

    inQ1 = mp.JoinableQueue()
    inQ2 = mp.JoinableQueue()
    processList = [inQ1, inQ2]

    processCount = len(processList)
    bunches = list()

    for startFrame in range(0, fileLen, fileLen // processCount):
        endFrame = startFrame + fileLen // processCount
        bunches.append((startFrame, endFrame))

    proc = list()

    for i in range(processCount):

        proc.append(mp.Process(target=process, args=(processList[i], pOut, bunches[i][0], bunches[i][1])))

    wcs = time.time()
    for pc in proc:
        start = time.time()
        pc.start()
        timelog.write("Partial cycle [" + str(i) + "]: " + str(time.time() - start))
    timelog.write("Whole cycle: " + str(time.time() - wcs))

    for Q in processList:
        Q.close()

    for pc in proc:
        pc.terminate()
        pc.join()
    # frameProcessTime = list()
    # iterTime = list()

    # while True:
    #     iter_start = time.time()
    #     frame_num += 1
    #
    #     ret, img = vs.read()
    #
    #     if not ret:
    #         break
    #
    #     frame_proc = time.time()
    #     tmp = process_frame(img)
    #     frameProcessTime.append(time.time() - frame_proc)
    #     if tmp is not None:
    #         print(str(datetime.timedelta(seconds=(frame_num/fps))).replace(":", "-"))
    #         errn0 = cv2.imwrite(pOut + '/frame_at_' +
    #                             str(datetime.timedelta(seconds=(frame_num/fps))).replace(":", "-") + '.jpg', tmp)
    #         print("Image Saved: ", errn0)
    #         vs.set(cv2.CAP_PROP_POS_FRAMES, frame_num + time_limit)
    #         frame_num += time_limit
    #
    #     if cv2.waitKey(1) & 0xFF == ord('q'):
    #         break
    #     iterTime.append(time.time() - iter_start)

    # timelog.write("Mean frame process time: " + str(sum(frameProcessTime)/len(frameProcessTime)) + '\n')
    # timelog.write("Mean iteration time: " + str(sum(iterTime)/len(iterTime)) + '\n')

    # vs.release()
    cv2.destroyAllWindows()
