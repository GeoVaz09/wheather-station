from flask import Flask, render_template

app = Flask(__name__)

current_temp = None
current_hum = None

@app.route("/")
def index():
    return render_template('index.html', temp=current_temp, hum=current_hum)

@app.route("/post/<temp>/<hum>")
def post(temp, hum):
    global current_temp, current_hum
    current_temp = temp
    current_hum = hum
    return render_template('index.html', temp=current_temp, hum=current_hum)

app.run(host='0.0.0.0', port=80, debug=True)
