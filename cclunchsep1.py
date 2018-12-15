t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    arr=[]
    j=0
    while j<n:
        arr.append(int(x[j]))
        j=j+1
    arr.sort()
    sm=0
    j=n-1
    while j>=0:
        sm=sm+arr[j]
        j=j-2
    print sm
    i=i+1
