fact=[0]*100001
fact[0]=1
i=1
p=1
while i<100001:
    p=(p*i)%1000000007
    fact[i]=p
    i=i+1

t=input()
i=0
while i<t:
    n=input()
    if n%2==0:
        if n==0:
            print "0"
        elif n==2:
            print "1"
        else:
            n=n-2
            print int(pow(2,n-1,1000000007)+0.5*(fact[n]/(fact[n/2]*fact[n/2])))%1000000007
    else:
        print "0"
    i=i+1


