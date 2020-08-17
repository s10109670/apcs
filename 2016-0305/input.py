f = open('test.in', 'w')
f.write('100000\n')
for i in range(100000):
	f.write("0 %d\n" % (i+1))
