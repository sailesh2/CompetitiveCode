n=input()
x=raw_input().split(' ')
arr=[]
k=0
arr2=[]
k2=0
i=0
while i<n:
    if int(x[i])%2==0:
        arr.append(int(x[i]))
        k=k+1
    else:
        arr2.append(int(x[i]))
        k2=k2+1
    i=i+1
arr.sort()
arr2.sort()
arr2.reverse()
i=0
while i<k:
    print arr[i],
    i=i+1
print
i=0
while i<k2:
    print arr2[i],
    i=i+1


    
