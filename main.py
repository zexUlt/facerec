import insightface
import time
import datetime
import os
import cv2
import numpy as np
import glob
import urllib, base64
import threading

# Just disables the warning, doesn't enable AVX/FMA
# os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
os.environ["OPENCV_FFMPEG_CAPTURE_OPTIONS"] = "rtsp_transport;tcp"

# model = insightface.app.FaceAnalysis(det_name='retinaface_r50_v1', rec_name='arcface_r100_v1', ga_name='genderage_v1')
model = insightface.app.FaceAnalysis(det_name='retinaface_mnet025_v2', rec_name='arcface_r100_v1', ga_name=None)
model.prepare(ctx_id=0, nms=0.4)
database = {}
base64string = "Basic YWRtaW46MTIz"
request = urllib.request.Request('http://192.168.1.108/cgi-bin/snapshot.cgi?1')
request.add_header("Authorization", base64string)

last_frame = None


def get_image():
    # download the image, convert it to a NumPy array, and then read
    # it into OpenCV format
    resp = urllib.request.urlopen(request)
    image = np.asarray(bytearray(resp.read()), dtype="uint8")
    image = cv2.imdecode(image, cv2.IMREAD_COLOR)

    # return the image
    return image


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
    img = cv2.putText(img, text, (text_offset_x, text_offset_y), font, fontScale=font_scale, color=(0, 0, 0),
                      thickness=1)

    return img


def prepare_database():
    database = {}

    # load all the images of individuals to recognize into the database
    for file in glob.glob("database/*"):
        identity = os.path.splitext(os.path.basename(file))[0]
        database[identity] = model.get(cv2.imread(file))[0].embedding  # embedding_norm, embedding, normed_embedding

    return database


def process_frame(img):
    faces = model.get(img, det_thresh=0.8, det_scale=1.0, max_num=0)
    for idx, face in enumerate(faces):
        bbox = face.bbox.astype(np.int).flatten()
        # print("Face [%d]:"%idx)
        # print("\tembedding shape:%s"%face.embedding.shape)
        # print("\tbbox:%s"%(bbox))
        # print("\tlandmark:%s"%(face.landmark.astype(np.int).flatten()))

        identity = who_is_it(face.normed_embedding)
        if identity is None:
            img = cv2.rectangle(img, (bbox[0], bbox[1]), (bbox[2], bbox[3]), (0, 0, 255), 2)
        else:
            img = cv2.rectangle(img, (bbox[0], bbox[1]), (bbox[2], bbox[3]), (255, 255, 255), 2)
            img = putText(img, identity, bbox[2], bbox[3])

    # img = cv2.putText(img, identity, (bbox[2], bbox[3]), cv2.FONT_HERSHEY_SIMPLEX, 1, 255)
    return img


def process_last_frame():
    while True:
        cv2.imshow('Video', process_frame(last_frame))
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break


def who_is_it(embedding):
    max_sim = 0
    identity = None
    for (name, db_embedding) in database.items():
        sim = np.dot(db_embedding, embedding) / (np.linalg.norm(db_embedding) * np.linalg.norm(embedding))
        if sim > max_sim:
            max_sim = sim
            identity = name

    # print(str(identity))
    # print(max_sim)

    if max_sim <= 0.4:
        return None
    else:
        return str(identity)


def autotune(img):
    print('MXNET AUTOTUNE START: ')
    print(datetime.datetime.now())
    process_frame(img)
    print('MXNET AUTOTUNE END: ')
    print(datetime.datetime.now())


if __name__ == "__main__":
    database = prepare_database()

    # cv2.imwrite('test.jpg', process_frame(cv2.imread('content/test.jpg')))
    # exit()
    # vs = cv2.VideoCapture('rtsp://admin:123@192.168.1.108:554/live')
    vs = cv2.VideoCapture('test2.mp4')

    ret, img = vs.read()
    last_frame = img
    # autotune(img)

    # x = threading.Thread(target=process_last_frame)
    # x.start()

    while True:
        ret, img = vs.read()
        if ret == False:
            break

        # last_frame = img
        cv2.imshow('video', process_frame(img))  # Почему то не работает
    # cv2.imwrite('test.jpg', process_frame(img))

    print(datetime.datetime.now())
    vs.release()
    cv2.destroyAllWindows()
