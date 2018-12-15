i=3
ctr=1
arr=[2]
crr=[0]*301
crr[2]=1
sm=2
while i<=300:
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
            crr[i]=1
            ctr=ctr+1
    i=i+1
t=input()
i=0
while i<t:
    s=raw_input()
    j=0
    cnt=0
    ans=[]
    while j<len(s):
        if crr[ord(s[j])]==1:
            cnt=1
        else:
            ans.append(s[j])
        j=j+1
    if cnt==1:
        print ''.join(ans)
    else:
        print "NULL"
    i=i+1
