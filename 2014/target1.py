n=input()
x=raw_input().split(' ')
arr=[]
i=0
while i<n:
    arr.append(int(x[i]))
    i=i+1
arr.sort()
sm=0
sav=[0]*1000001
i=0
while i<n:
    sm=sm+1
    sav[arr[i]]=sm
    i=i+1
k=0
i=0
while i<n:
    k=k+n-sav[arr[i]]
    i=i+1
print "%.6f" % float(float(n*(n-1)-k)/(n*(n-1))),"%.6f" % float(float(k)/(n*(n-1)))

