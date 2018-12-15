n=input()
x=raw_input().split(' ')
arr=[]
i=0
while i<n:
    arr.append(int(x[i]))
    i=i+1
mini=1000000000
arr.sort()
i=0
while i<n-1:
    if abs(arr[i]-arr[i+1])<=mini:
        mini=abs(arr[i]-arr[i+1])
    i=i+1
i=0
while i<n-1:
    if abs(arr[i]-arr[i+1])==mini:
        print arr[i],arr[i+1],
    i=i+1
