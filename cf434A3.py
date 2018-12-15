x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])

last=n*(10**k)
i=1
cnt=0
save=-1
while i<=min(10**k,10**6):
    if (n*i)%(10**k)==0:
        cnt=1
        save=n*i
        break
    i=i+1
if cnt==1:
    print min(last,save)
else:
    print last
