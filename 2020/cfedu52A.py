x=int(input())
i=0
while i<x:
    y=input().split(' ')
    s=int(y[0])
    a=int(y[1])
    b=int(y[2])
    c=int(y[3])

    print(int(s/c) + int(int(int(s/c)/a))*b)
    i=i+1
