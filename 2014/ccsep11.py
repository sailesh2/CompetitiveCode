
six=[1,6,15,20,15,6,1]

def fun(n,ctr,sumi):
    global s
    p=1
    if ctr>6:
        return
    if sumi==n:
        s=s+six[ctr]
        return
    elif sumi>n:
        return
    else:
        i=1
        while i<=6:
            if sumi+i>n:
                return
            fun(n,ctr+1,sumi+i)
            i=i+1
            
    

n=input()
n=n-13
if n<0:
    print "0"
elif n==0:
    print "1"
else:
    global s
    s=1
    while n>0:
        if n%2==0:
            fun(n/2,0,0)
            n=n-2
        else:
            n=n-1
    print s%1000000007
    
            
