t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    m=int(x[1])
    y=raw_input().split(' ')
    arr=[]
    j=0
    tot=0
    while j<n:
        arr.append(int(y[j]))
        tot=tot+arr[j]
        j=j+1
    arr.sort()
    #mini=1000000
    j=0
    sm=0
    while j<m:
        sm=sm+arr[j]
        j=j+1
    print abs((tot-sm)-sm)
    i=i+1
