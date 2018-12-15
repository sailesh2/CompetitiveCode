x=raw_input().split(' ')
n=int(x[0])
q=int(x[1])
a=raw_input().split(' ')
arr=[]
i=0
while i<n:
    arr.append(int(a[i]))
    i=i+1
i=0
while i<q:
    val=input()
    if val in arr:
        print "YES"
    else:
        print "NO"
    i=i+1
