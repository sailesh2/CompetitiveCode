n=input()
x=raw_input().split(' ')
arr=[]
i=0
while i<n:
    arr.append(int(x[i]))
    i=i+1
m=input()
i=0
while i<m:
    z=raw_input().split(' ')
    if int(z[0])==1:
        j=int(z[1])-1
        while j<=int(z[2])-1:
            if arr[j]%int(z[3])==0:
                arr[j]=arr[j]/int(z[3])
            j=j+1
    else:
        arr[int(z[1])-1]=int(z[2])
    i=i+1
i=0
while i<n:
    print arr[i],
    i=i+1
    
