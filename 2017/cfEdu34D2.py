n=int(raw_input())
arr=[]
x=raw_input().split(' ')
i=0
while i<n:
    arr.append(int(x[i]))
    i=i+1

mp={}
totSum=0
sumi=0;

i=n-1
while i>=0:
    after=arr[i]+1;
    before=arr[i]-1;
    eq=arr[i];
    cntA=0;
    cntB=0;
    cntE=0;
    
    if (after in mp):
        cntA=mp[after]

    if (before in mp):
        cntB=mp[before]

    if (eq in mp):
        cntE=mp[eq]


    v=sumi-((cntA*after) + (cntB*before) + (cntE*eq));
    ctr=(n-1-i)-(cntA+cntB+cntE);
    totSum=totSum + (v-(ctr*arr[i]));
    sumi=sumi+arr[i]
    
    mp[arr[i]]=cntE+1
    
    i=i-1
    
print totSum
