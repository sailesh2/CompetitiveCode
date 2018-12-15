n=1000
a=[0,1]

i=2
while i<=n**0.5:
    if i not in a:
        j=i*i
        while j<=n:
            a.append(j)
            j=j+i
    i=i+1
arr=[0]
ctr=0
i=1
while i<1000:
    if i not in a:
        cnt=0
        k=i
        while k>0:
            d=k%10
            if d==1:
                cnt=1
                break
            k=k/10
        if cnt==0:
            ctr=ctr+1
    arr.append(ctr)
    i=i+1
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n1=int(x[0])
    m1=int(x[1])
    if arr[m1]-arr[n1-1]==0:
        print "-1"
    else:
        print arr[m1]-arr[n1-1]
    i=i+1
