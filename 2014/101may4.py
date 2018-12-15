n=input()
x=raw_input().split(' ')
arr=[]
i=0
maxi=0
ctr=0
s=0
while i<n:
    arr.append(int(x[i]))
    if arr[i]>=maxi:
        maxi=arr[i]
        ctr=ctr+1
    else:
        s=s+ctr*(ctr+1)/2
        ctr=1
        maxi=arr[i]
    i=i+1
print s+ctr*(ctr+1)/2
