t=input()
i=0
while i<t:
    n=input()
    a=input()
    b=input()
    arr=[]
    if a<=b:
        s=(n-1)*a
        arr.append(s)
        j=0
        while j<n-1:
            s=s-a+b
            arr.append(s)
            j=j+1
    else:
        s=(n-1)*b
        arr.append(s)
        j=0
        while j<n-1:
            s=s-b+a
            arr.append(s)
            j=j+1
    arr=list(set(arr))
    arr.sort()
    j=0
    while j<len(arr):
        print arr[j],
        j=j+1
    print
    i=i+1
        
