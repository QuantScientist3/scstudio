import os
dirlist = os.listdir(__path__[0])
bcheckers = []
hcheckers = []
for i in dirlist:
	if i[-3:] == ".py" and i[0] != '_' and 'B' in i:
		bcheckers.append(i)
	if i[-3:] == ".py" and i[0] != '_' and 'H' in i:
		hcheckers.append(i)
