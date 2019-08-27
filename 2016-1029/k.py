class Struct(object):
	pass
s = Struct()
place=[]
in1 = input()
temp = in1.split()
n = int(temp[0])
m = int(temp[1])
k = int(temp[2])

for i in range (n-1):
	tmp=[]
	s.data=i+1
	s.next=i+1
	tmp.append(s.data)
	tmp.append(s.next)
	place.append(tmp)

tmp1=[]
s.data=n
s.next=0
tmp1.append(s.data)
tmp1.append(s.next)
place.append(tmp1)
count=0
current=0
pre=0
i=0

while i<k:
	count=count+1
	if (count == m):
		place[pre][1]=place[current][1]
		count=0
		n=n-1
		i=i+1
	pre=current
	current=place[current][1]
print("%d" %place[current][0])
