def fun(i,n,arr,sm):
    global p
    if sm==p:
        return 1
    j=i
    while j<n:
        if fun(j+1,n,arr,sm+arr[j])==1:
            return 1 
        j=j+1
    return 0
global p
p=input()
a=input()
b=input()
c=input()
d=input()
arr=[a,b,c,d]
if fun(0,4,arr,0)==1:
    print "YES"
else:
    print "NO"
