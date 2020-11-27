x=input().split(' ')

n=int(x[0])
k=int(x[1])
m=int(x[2])

y=input().split(' ')
arr=[]
i=0
while i<n:
    arr.append(int(y[i]))
    i=i+1

arr.sort()
i=min(m,n-1)
m=m-i
sm=0
ctr=0
while i<n:
    if m>0:
        arr[i]=arr[i]+min(m,k)
        m=m-min(m,k)
    sm=sm+arr[i]
    ctr=ctr+1
    i=i+1

print(float(sm)/ctr)
