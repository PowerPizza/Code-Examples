from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/set_file", methods=["POST"])
def st_file():
    data_ = request.data
    file_name = data_.split(b"!123!")[0].decode("utf-8")
    file_BINdata = data_.split(b"!123!")[1]
    print(file_name)
    print(file_BINdata)
    with open(file_name, "wb") as fp:
        fp.write(file_BINdata)
    return "200"


app.run(host="0.0.0.0", port=8080)