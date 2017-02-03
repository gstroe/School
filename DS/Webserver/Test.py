# Headers
from flask import Flask

app.route('/') # the base route to load the start of the web page
def index():
    return "Hello this is a test" # Quick test to see if it loads the txt
	

app.route('/<str:input>')
def userInput(input):
	return "Your input is: " + input
	

 