a,b,c=map(int,raw_input().split())
i=1
cnt=0
arr=[]
while i<=90:
    x=pow(i,a)*b+c
    x1=x
    s=0
    while x>0:
        s=s+x%10
        x=x/10
    if s==i:
        cnt=cnt+1
        arr.append(x1)
    i=i+1
print cnt
i=0
while i<cnt:
    print arr[i],
    i=i+1
