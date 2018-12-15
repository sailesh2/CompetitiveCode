n=input()
x=raw_input().split(' ')
i=0
arr=[]
while i<n:
    arr.append(int(x[i]))
    i=i+1
arr.sort()
i=0
save=arr[0]
ctr1=0
while i<n:
    if arr[i]==save:
        ctr1=ctr1+1
    i=i+1
i=n-1
save2=arr[n-1]
ctr2=0
while i>=0:
    if arr[i]==save2:
        ctr2=ctr2+1
    i=i-1
print save2-save,
if save==save2:
    print (ctr1*(ctr2-1))/2
else:
    print ctr2*ctr1
