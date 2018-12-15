t=input()
i=0
while i<t:
    n=input()
    a=input()
    b=input()
    arr=[]
    j=1
    while j<=n:
        arr.append((n-j)*a+(j-1)*b)
        j=j+1
    arr=list(set(arr))
    arr.sort()
    j=0
    while j<len(arr):
        print arr[j],
        j=j+1
    print
    i=i+1
