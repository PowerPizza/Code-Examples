from flask import Flask, render_template, Response
import time

app = Flask(__name__)

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/stream")
def stream():
    def create_stream():
        for x in range(1000):
            time.sleep(1)
            yield b"org"
    return Response(create_stream(), mimetype="application/octet-stream")


app.run(host="0.0.0.0", port=8080)