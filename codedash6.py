n=input()
x=raw_input().split(' ')
k=int(x[0])
arr=[]
j=1
while j<n:
    if int(x[j])<=k:
        arr.append(int(x[j]))
    j=j+1
arr.append(k)
j=1
while j<n:
    if int(x[j])>k:
        arr.append(int(x[j]))
    j=j+1
i=0
while i<n:
    print arr[i],
    i=i+1
    
                       
