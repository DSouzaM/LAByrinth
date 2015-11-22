def mazeToArray(input, output):
	rows = filter(bool,open(input).read().split("\n"))
	str = "{"
	for row in range(len(rows)):
		str+="{"+rows[row]+"}"
		if row < len(rows)-1:
			str+=", "
	str+="}"
	f = open(output,"w")
	f.write(str)
	f.close()


