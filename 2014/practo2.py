#arr=[2,3,5,7,11,13,15,17,23,29,31,37,41,43,47]
import math
arr=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59]
n=input()
lt=17
i=0
while i<n:
    x=raw_input().split(' ')
    h=int(x[0])
    m=int(x[1])
    s=int(x[2])
    sm=0
    j=0
    while j<lt:
        p=1
        lb=arr[j]*(math.ceil(float(h)/arr[j]))
        ub=arr[j]*(math.floor(float(23)/arr[j]))
        p=p*((ub-lb)/arr[j]+1)

        lb=arr[j]*(math.ceil(float(m)/arr[j]))
        ub=arr[j]*(math.floor(float(59)/arr[j]))
        p=p*((ub-lb)/arr[j]+1)

        lb=arr[j]*(math.ceil(float(s)/arr[j]))
        ub=arr[j]*(math.floor(float(59)/arr[j]))
        p=p*((ub-lb)/arr[j]+1)
        
        sm=sm+int(p)
        j=j+1
    d=(60-s)+60*(59-m)+60*60*(23-h)-sm
    a=sm
    b=d
#    print a,b
    gcd=1
    if a>0 and b>0:
        if a>b:
            while 1:
                if a%b==0:
                    gcd=b
                    break
                temp=a
                a=b
                b=temp%b
        else:
            while 1:
                if b%a==0:
                    gcd=a
                    break
                temp=b
                b=a
                a=temp%a
    print str(sm/gcd)+":"+str(d/gcd)
    i=i+1
