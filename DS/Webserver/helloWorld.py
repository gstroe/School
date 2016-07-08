# Headers
from flask import Flask, render_template
app = Flask(__name__) # The referce for flask to be the application that runs in this file

global text

@app.route('/') # the bas route to load the index file for the web application
def index():
    return render_template('index.html') # "Load the index file directory"
	
@app.route('/head') # the pulling route so flash can redirect the directories
def head():
	canFile= open("can.txt") # open the canbus file and read from it
	global text
	text = canFile.read(56)
	head = text[:19]
	return "<h2> " + head + "</h2>"

@app.route('/tail') # the pulling route for the cvan bus tail
def tail():
	global text
	tail = text[19:]
	return "<h2> " + tail + "</h2>"

if __name__ == '__main__':
    app.run()
	