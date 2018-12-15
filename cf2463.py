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
            #print i
            ctr=ctr+1
    if i>10000:
        break
    i=i+1
n=input()
x=raw_input().split(' ')
brr=[0]
has=[0]*100001
i=0
while i<n:
    brr.append(int(x[i]))
    has[brr[i+1]]=i+1
    i=i+1
ans=[]
ans2=[]
ctr=0
i=1
while i<=n:
    pos=has[i]
    #print pos
    
    while has[i]!=i:
        pos=has[i]
        if pos>i:
                k=pos-i+1
                while k not in arr:
                    k=k-1
                temp=brr[pos-k+1]
                brr[pos-k+1]=brr[pos]
                brr[pos]=temp
                has[brr[pos]]=pos
                has[brr[pos-k+1]]=pos-k+1
                ans.append(pos)
                ans2.append(pos-k+1)
                ctr=ctr+1
                
        else:
                k=i-pos+1
                while k not in arr:
                    k=k+1
                temp=brr[pos+k-1]
                brr[pos+k-1]=brr[pos]
                brr[pos]=temp
                has[brr[pos]]=pos
                has[brr[pos+k-1]]=pos+k-1
                ans.append(pos)
                ans2.append(pos+k-1)
                ctr=ctr+1
                
    i=i+1
print ctr
i=0
while i<ctr:
    print min(ans[i],ans2[i]),max(ans[i],ans2[i])
    i=i+1
