import math
n=input()
x=raw_input().split(' ')
q=input()
i=0
while i<q:
    y=raw_input().split(' ')
    k=int(y[0])-1
    l=int(y[1])-1
    p=int(y[2])
    ans=int(x[k])
    while k<=l:
        if ans==0:
            print "Yes"
            break
        a=ans
        b=p
        if a>=b:
            while 1:
                if a%b==0:
                    break
                temp=a
                a=b
                b=temp%b
            gcd=b
        else:
            while 1:
                if b%a==0:
                    break
                temp=b
                b=a
                a=temp%a
            gcd=a
        if gcd==p:
            print "Yes"
            break
        elif gcd==1:
            print "No"
            break
        else:
            ans=gcd
        if k==l:
            break
        ans=math.pow(ans,int(x[k+1]))
        k=k+1
    i=i+1
