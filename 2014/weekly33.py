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
    if i>=10**4:
        break
    i=i+1
def fun(n,k):
    if k==0:
        if n==0:
            return 2
        else:
            return 1
    j=0
    while arr[j]<=n and j<10**5:
        if sav[n-arr[j]][k-1]==2:
            return 2
        elif sav[n-arr[j]][k-1]==1:
            continue
        else:
            a=fun(n-arr[j],k-1)
            if a==2:
                sav[n][k]=2
                return 2
            else:
                sav[n][k]=1
        j=j+1
    return 1
sav = [[0 for x in xrange(1000)] for x in xrange(1000)] 
t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    a=fun(n,k)
    if a==2:
        sav[n][k]=2
        print "Yes"
    else:
        sav[n][k]=1
        print "No"
    i=i+1
