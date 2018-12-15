x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
k=int(x[2])

goFlights = [[] for x in xrange(n+2)]
returnFlights = [[] for x in xrange(n+2)]

i=0
while i<m:
    y=raw_input().split(' ')
    date=int(y[0])
    c1=int(y[1])
    c2=int(y[2])
    cost=int(y[3])
    if c1==0:
        returnFlights[c2].append([date,cost])
    else:
        goFlights[c1].append([date,cost])
    i=i+1

costMatrix=[0]*100005
goCount=[0]*100005
i=1
while i<=n:
    goFlights[i].sort()
    j=0
    prev=0
    cnt=0
    while j<len(goFlights[i]):
        flight=goFlights[i][j]
        costMatrix[flight[0]]=costMatrix[flight[0]]+flight[1]-prev
        prev=flight[1]
        if cnt==0:
            goCount[flight[0]]=1
        cnt=1
        j=j+1
    i=i+1

i=0
sm=0
go=0
while i<100005:
    sm=sm+costMatrix[i]
    go=go+goCount[i]
    costMatrix[i]=sm
    goCount[i]=go
    i=i+1




costMatrixR=[0]*100005
returnCount=[0]*100005
i=0
while i<=n:
    returnFlights[i].sort()
    j=len(returnFlights[i])-1
    prev=0
    cnt=0
    while j>=0:
        flight=returnFlights[i][j]
        costMatrixR[flight[0]]=costMatrixR[flight[0]]+flight[1]-prev
        prev=flight[1]
        if cnt==0:
            returnCount[flight[0]]=1
        cnt=1
        j=j-1
    i=i+1

i=100004
sm=0
r=0
while i>=0:
    sm=sm+costMatrixR[i]
    r=r+returnCount[i]
    costMatrixR[i]=sm
    returnCount[i]=r
    i=i-1

cnt=0
goDate=1
while goDate<100005:
    returnDate=goDate+k+1
    if returnDate<100005 and goCount[goDate]==n and returnCount[returnDate]==n:
        if cnt==0:
            mini=costMatrix[goDate]+costMatrixR[returnDate]
        else:
            mini=min(mini,costMatrix[goDate]+costMatrixR[returnDate])
        cnt=1
    goDate=goDate+1

if cnt==0:
    print "-1"
else:
    print mini
