x=raw_input().split(' ')
n=int(x[0])
w=int(x[1])
arr=[]
y=raw_input().split(' ')
i=0
while i<2*n:
    arr.append(int(y[i]))
    i=i+1
arr.sort()
arr.reverse()
gl=arr[2*n-1]
bl=arr[n-1]
if bl>=gl*2:
    if 3*n*gl<=w:
        print 3*n*gl
    else:
        print w
else:
    if (3*n*(float(bl)/2))<=w:
        if (3*n*(float(bl)/2))==int(3*n*(float(bl)/2)):
            print int(3*n*(float(bl)/2))
        else:
            print (3*n*(float(bl)/2))
    else:
        print w
