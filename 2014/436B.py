x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
k=int(x[2])
i=0
arr=[]
while i<n:
    y=raw_input()
    arr.append(y)
    i=i+1
j=0
while j<m:
    ctr=0
    i=1
    while i<n:
        if (j+i)<m and arr[i][j+i]=='L':
            ctr=ctr+1
        if (j-i)>=0 and arr[i][j-i]=='R':
            ctr=ctr+1
        if (i+i)<n and arr[i+i][j]=='U':
            ctr=ctr+1
        i=i+1
    print ctr,
    j=j+1
