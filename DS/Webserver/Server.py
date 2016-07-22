# Headers
from flask import Flask, render_template, jsonify
import random
import json
app = Flask(__name__) # The referce for flask to be the application that runs in this file


#global vars
global dictID
dictID = []
global dictER
dictER = []
global dictGD
dictGD = []

global chkER
chkER = False
global chkGD
chkGD = False

global lastRead
lastRead = ""

@app.route('/') # the base route to load the index file for the web application
def index():
    return render_template('index.html') # "Load the index file directory"

	
@app.route('/data') # the pulling route so flash can redirect the directories
def data():
	global lastRead
	canFile = open("can.txt") # open the canbus file and read from it	
	read = canFile.read() #copy
	readJson = json.loads(read) # load as JSOn so python can understand
	
	#Checks
	if (chkGD & (lastRead != read)):
		checkGD(readJson[0]['ID'], readJson[0]['ERROR'])
	if (chkER & (lastRead != read)):
		checkER(readJson[0]['ID'], readJson[0]['ERROR'])
	if (lastRead != read): # add to filter ID if not last sent
		checkAddID(readJson[0]['ID'])			
	if (checkID(readJson[0]['ID'])): # check if its being filter and mark error as two if its is
		readJson[0]['ERROR'] = 2

	lastRead = read
	return jsonify(readJson)

# returns the filterd IDs
@app.route('/fID') # returns the filterd IDs
def fID():
	return jsonify(dictID)

@app.route('/fER') # returns the filterd IDs
def fER():
	return jsonify(dictER)

@app.route('/fGD') # returns the filterd IDs
def fGD():
	return jsonify(dictGD)

# Adds the ID to the list
@app.route('/addID/<int:ID>') 
def addID(ID):
	for x in xrange(0,len(dictID)):
		if (int(dictID[x]['ID']) == ID):
			return "ng"
	dictID.append({'ID': ID, 'count': 1})
	return "ok"

@app.route('/remID/<int:ID>')
def remID(ID):
	for x in xrange(0,len(dictID)):
		if (int(dictID[x]['ID']) == ID):
			del dictID[x]
			return "ok"
	return "ng"


# remove all IDs from the list
@app.route('/clearID')
def clearID():
	global dictID
	dictID = []
	return "ok"


# turn of error logging
@app.route('/offER')
def offER():
	global dictER
	dictER = []
	global chkER
	chkER = False
	return "ok"

# add error Logging
@app.route('/onER')
def onER():
	global chkER
	chkER = True
	return "ok"


# turn of good logging
@app.route('/offGD')
def offGD():
	global dictGD
	dictGD = []
	global chkGD
	chkGD = False
	return "ok"

# add good Logging
@app.route('/onGD')
def onGD():
	global chkGD
	chkGD = True
	return "ok"



# check and see if the id already exist
def checkAddID(ID):
	#first convert to decimal
	num = convert(ID)

	for x in xrange(0,len(dictID)):
		if (int(dictID[x]['ID']) == num):
			dictID[x]['count'] += 1		
			return True
	return False

# checsk without modifiying for theerror 2 flaging
def checkID(ID):
	#first convert to decimal
	num = convert(ID)

	for x in xrange(0,len(dictID)):
		if (int(dictID[x]['ID']) == num):
			return True
	return False

# Check to see if erro messages and adds it if it is
def checkER(ID, er):
	#first convert to decimal

	num = convert(ID)
	if (int(er) == 1):
		for x in xrange(0,len(dictER)):
			if (int(dictER[x]['ID']) == num):
				dictER[x]['count'] += 1
				return True
		dictER.append({'ID': num, 'count': 1})		
		return True
	return False

# Checkto see if a good message and adds it if it is
def checkGD(ID, er):
	#first convert to decimal
	open("txt.txt","w").write(str(dictGD))
	num = convert(ID)
	if (int(er) == 0):
		for x in xrange(0,len(dictGD)):
			if (int(dictGD[x]['ID']) == num):
				dictGD[x]['count'] += 1
				return True
		dictGD.append({'ID': num, 'count': 1})		
		return True
	return False



#convert from binary to int
def convert(array): 
	num = 0;
	for x in xrange(0,len(array)):
		num += array[x] * pow(2, len(array)-1-x)
	return num

if __name__ == '__main__':
    app.run()
	