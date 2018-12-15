global n
n=input()
global sm
sm=0
global ctr
ctr=0
global has
has=[0]*100005
global arr
arr= [[] for i in range(100005)]
def travel(index,sumi):

    global sm
    global ctr
    i=0
    cnt=0
    while i<len(arr[index]):
        node=arr[index][i];
        if(has[node]==0):
            cnt=1;
            has[node]=1;
            travel(node,sumi+1);
            has[node]=0;
        i=i+1
    if cnt==0:
       sm=sm+sumi;
       ctr=ctr+1

i=0
while i<n-1:
    x=raw_input().split(' ')
    u=int(x[0])
    v=int(x[1])
    arr[u].append(v)
    arr[v].append(u)
    i=i+1


if n>1:
    sm=0
    has[1]=1;
    travel(1,0);
    has[1]=0;
    
if(ctr==0 or n==1):
    cout<<"0.000000000000000";
else:
    print '{0:.15f}'.format(float(sm)/ctr);

    
