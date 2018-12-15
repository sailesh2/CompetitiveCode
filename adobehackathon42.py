n=input()
x=raw_input().split(' ')

q=input()
i=0
while i<q:
    y=raw_input().split(' ')
    a=int(y[0])
    l=int(y[1])
    r=int(y[2])
    if a==0:
        print int(''.join(x[l-1:r]))%1000000007
    else:
        x[l-1]=y[2]
    i=i+1
