t=int(input())

i=0
while i<t:
    n=int(input())
    x=input().split(' ')
    arr=[]
    j=0
    while j<n:
        arr.append((j+int(x[j]))%n)
        j=j+1

    j=0
    cnt=0
    has=[0]*n
    while j<n:
        if has[arr[j]]==1:
            cnt=1
            break
        has[arr[j]]=1
        j=j+1
    if cnt==0:
        print("YES")
    else:
        print("NO")
    
    i=i+1
