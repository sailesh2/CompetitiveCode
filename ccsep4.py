i=3
ctr=1
arr=[2]
while 1:
    cnt=0
    if i%2!=0:
        j=0
        while j<ctr and arr[j]<=pow(i,0.5):
            if i%arr[j]==0:
                cnt=1
                break
            j=j+1
        if cnt==0:
            arr.append(i)
            ctr=ctr+1
    if ctr==1000:
        break
    i=i+1
t=input()
i=0
while i<t:
    n=input()
    p=1
    k=0
    ans=[]
    j=0
    while j<1000:
        if n%arr[j]==0:
            p=p*arr[j]
            ans.append(arr[j])
            k=k+1
        j=j+1
    if n/p>1:
        ans.append(n/p)
        k=k+1
    print k
    j=0
    while j<k:
        print ans[j]
        j=j+1
    i=i+1
