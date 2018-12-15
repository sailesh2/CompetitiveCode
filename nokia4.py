n=input()
x=raw_input().split(' ')
y=raw_input().split(' ')
fuel=input()
i=0
maxi=0
while i<n:
	v=(float(fuel)/int(y[i]))*int(x[i])
	if v>maxi:
		maxi=v
	i=i+1
print "%.3f"%maxi
