n=100
a=[1]*100000
a[0]=0
a[1]=0

i=2
while i<n**0.5:
    if a[i]==1:
        j=i*i
        while j<=n:
            a[j]=0
            j=j+i
    i=i+1
s=[0]*100000
s[2]=1
sm=2
i=3
while i<=n:
    if i%2!=0:
        if a[i]==1:
            sm=sm+i
    s[i]=sm
    i=i+1
print s
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    m=int(x[0])
    n=int(x[1])
    print s[n],s[m-1]
    if a[s[n]-s[m-1]]==1:
        print "YES"
    else:
        print "NO"
    i=i+1
