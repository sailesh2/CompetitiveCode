t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    y=raw_input().split(' ')
    arr=[]
    arr1=[]
    j=0
    while j<n:
        arr.append(int(x[j]))
        j=j+1
    j=0
    while j<n:
        arr1.append(int(y[j]))
        j=j+1
    arr.sort()
    arr1.sort()
    maxi=0
    j=0
    while j<n:
        if abs(arr[j]-arr1[j])>=maxi:
            maxi=abs(arr[j]-arr1[j])
        j=j+1
    print maxi
    i=i+1
    
