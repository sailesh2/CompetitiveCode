x=raw_input().split(' ')
n=int(x[0])
x1=int(x[1])

y=raw_input().split(' ')
arr=[]
i=0
while i<n:
    arr.append(int(y[i]))
    i=i+1

cnt=[0]*1100005
i=0
sumi=0
while i<n:
    sumi=sumi+cnt[x1^arr[i]]
    cnt[arr[i]]=cnt[arr[i]]+1
    i=i+1
print sumi
