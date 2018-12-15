t=input()
i=0
while i<t:
    n=input()
    a=pow(2,n,100000)-1
    if a<0:
        a=a+100000
    print a
    i=i+1
