# Headers
from flask import Flask
app = Flask(__name__) # The referce for flask to be the application that runs in this file

@app.route('/') # the base route to load the start of the web page
def index():
    return "Hello this is a test" # Quick test to see if it loads the txt
	

@app.route('/<string:input>') # loads any input thats a part of the url
def userInput(input):
	return "Your input is: " + input
	
	
if __name__ == '__main__':
	app.run(host='0.0.0.0')


 