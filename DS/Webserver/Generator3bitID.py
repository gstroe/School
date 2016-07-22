# this file creates the random python messages
import random
import time
import json

while True: 
	wFile =  open("can.txt", "w") # open the write file
	num = []
	length = 0
	error = 0

	wFile.truncate() # clear the file first
	wFile.write("[{")# write the starting of json

	# add the SOF
	wFile.write("\"SOF\":[0],")

	# add the ID
	wFile.write("\"ID\":[")
	for x in xrange(0,3):
		y = random.randint(0,1)
		wFile.write(str(y))
		if (x < 10):
			wFile.write(",")
	wFile.write("0,0,0,0,0,0,0,0],")

	# add RR
	wFile.write("\"RR\":[0],")

	# add ConR
	wFile.write("\"ConR\":[0,0],")

	# add DL
	wFile.write("\"DL\":[")
	length = random.randint(1,8);
	temp = length
	v8 = length/8
	if(v8 == 1):
		length -= 8
	v4 = length/4
	if(v4 == 1):
		length -= 4
	v2 = length/2
	if(v2 == 1):
		length -= 2
	v1 = length/1
	if(v1 == 1):
		length -= 1
	wFile.write(str(v8)+","+str(v4)+","+str(v2)+","+str(v1)+"],")

	# add Data
	length = temp*8	
	wFile.write("\"Data\":[")
	for x in range(0,length):
		y = random.randint(0,1)
		wFile.write(str(y))
		if (x < (length-1)):
			wFile.write(",")
	wFile.write("],")	
		
	# add CRC
	wFile.write("\"CRC\":[")
	value = random.randint(0,7);
	if (value == 0):
		error = 1
	v4 = value/4
	if(v4 == 1):
		value -= 4
	v2 = value/2
	if(v2 == 1):
		value -= 2
	v1 = value/1
	if(v1 == 1):
		value -= 1
	wFile.write(str(v4)+","+str(v2)+","+str(v1)+",")
	for x in range(0,12):
		y = random.randint(0,1)
		wFile.write(str(y))
		if (x < (11)):
			wFile.write(",")
	wFile.write("],")

	# add Deli	
	wFile.write("\"Deli\":[")
	for x in xrange(0,3):
		y = random.randint(0,1)
		wFile.write(str(y))
		if (x < 2):
			wFile.write(",")
	wFile.write("],")

	# add EOF and IDS
	wFile.write("\"EOF\":[1,1,1,1,1,1,1],\"IFS\":[1,1,1],")

	# add error
	wFile.write("\"ERROR\":"+str(error)+"}]")

	wFile.close() # Close the flip
	time.sleep(1.5)  # 1.5 second sleep cycle.




