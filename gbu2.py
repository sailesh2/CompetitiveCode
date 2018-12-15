i=1
p=1
ans=[1]
while i<=10000:
    p=p*i
    ans.append(p)
    i=i+1
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    r=int(x[1])
    n=n-1
    r=r-1
    print ans[n]/(ans[r]*ans[n-r])
    i=i+1
