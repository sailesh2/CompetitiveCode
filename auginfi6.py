n=input()
x=raw_input().split(' ')
temp=[1]*(n+1)
temp2=[0]*(n+1)
ans=[0]*n
cnt=0
i=0
while i<n:
    j=n-1-i
    if cnt==0:
        temp2[n-i]=0
    else:
        temp[n-i]=0
    while j>=0:
        if cnt==0:
            temp2[j]=(((((int(x[j]))%100003)*(temp[j+1]%100003))%100003)+(temp2[j+1]%100003))%100003
        else:
            temp[j]=(((((int(x[j]))%100003)*(temp2[j+1]%100003))%100003)+(temp[j+1]%100003))%100003
        j=j-1
    if cnt==0:
        ans[i]=temp2[0]%100003
    else:
        ans[i]=temp[0]%100003
    cnt=1-cnt
    i=i+1
q=input()
i=0
while i<q:
    y=input()
    print ans[y-1]
    i=i+1
