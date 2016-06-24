import psutil
from flask import Flask, render_template
app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')
	
@app.route('/pull')
def pull():
	cpu = str(psutil.cpu_percent())
	return "<h2>The CPU: " + cpu + "</h2>"

if __name__ == '__main__':
    app.run()
	