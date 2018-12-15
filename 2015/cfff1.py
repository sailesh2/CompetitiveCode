x=raw_input().split(' ')
p=int(x[0])
n=int(x[1])
ar=[0]*(p+1)
cnt=0
save=-1
i=0
while i<n:
    num=input()
    if cnt==0:
        if ar[num%p]==1:
            cnt=1
            save=i+1
        else:
            ar[num%p]=1
    i=i+1
print save    
