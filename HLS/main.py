from flask import Flask, Response
import pyautogui

app = Flask(__name__)

@app.route("/")
def home():
    return "<a href=\"/screen_stream\">Stream Start</a>"

@app.route("/screen_stream")
def screen_stream():
    def img_live():
        while 1:
            pyautogui.screenshot().save("a.png")
            with open("a.png", "rb") as fp:
                yield b"--123456\r\nContent-Type: image/png\r\n\r\n"+fp.read()+b"\r\n"
    return Response(img_live(), mimetype='multipart/x-mixed-replace; boundary=--123456', headers={"Content-Type": "image/png"})

app.run(host="0.0.0.0", port=80)