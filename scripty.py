f = open("list.txt","w");

for i in range(1,252):
	s = str(i)
	l = 9-len(s)
	f.write("3/" + (l*'0') + s + ".jpg\n")

f.close()
