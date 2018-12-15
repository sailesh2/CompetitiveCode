n=input()
x=raw_input().split(' ')
arr=[]
sm=0
cnt=-1
maxi=0
mini=10000000
sm2=0
i=0
while i<n:
    arr.append(int(x[i]))
    cnt=cnt*-1;
    sm=sm+cnt*arr[i];
    sm2=sm2+arr[i];
    if (sm>maxi):
        maxi=sm
    if (sm<mini):
        mini=sm;
    i=i+1

mini=min(0,mini);
maxi=max(0,maxi);
brr= [[0 for x in range(sm2)] for x in range(maxi-mini)]

cnt=0;
j=-1*mini;
k=0;
i=0
while i<n:
    
    ctr=0;
    if (cnt==0):
        while (ctr<arr[i]):
            brr[j][k]=ord('/')
            k=k+1;
            ctr=ctr+1;
            if (ctr<arr[i]):
                j=j+1
            
    else:
        while (ctr<arr[i]):
            brr[j][k]=ord('\\')
            k=k+1;
            ctr=ctr+1;
            if (ctr<arr[i]):
                j=j-1;
    cnt=1-cnt;
    i=i+1

i=maxi-mini-1
while i>=0:
    j=0;
    st=""
    while j<sm2:
        if(brr[i][j]==ord('/')):
            st=st+"/"
        elif (brr[i][j]==ord('\\')):
            st=st+"\\"
        else:
            st=st+" "
        j=j+1
    print st
    i=i-1
