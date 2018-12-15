x=raw_input().split(' ')
n=int(x[0])
q=int(x[1])
s=raw_input()
arr=[]
zero=[]
one=[]
two=[]
sumz=0
sumo=0
sumt=0
i=0
while i<n:
    arr.append(int(s[i]))
    if i!=0:
        arr[i]=(arr[i]+arr[i-1])%3
    if arr[i]==0:
        sumz=sumz+1
    elif arr[i]==1:
        sumo=sumo+1
    else:
        sumt=sumt+1
    zero.append(sumz)
    one.append(sumo)
    two.append(sumt)
    i=i+1
i=0
while i<q:
    y=raw_input().split(' ')
    p=int(y[0])
    a=int(y[1])
    b=int(y[2])
    if p==2:
        a=a-1
        b=b-1
        if (a!=0):
            sm=arr[a-1];
        else:
            sm=0;
        cntz=sm%3;
        cnto=(sm+1)%3;
        cntt=(sm+2)%3;
        
        if (cntz==0):
            if (a!=0):
                sumz=zero[b]-zero[a-1];
            else:
                sumz=zero[b];
        elif (cntz==1):
            if (a!=0):
                sumz=one[b]-one[a-1];
            else:
                sumz=one[b];
        else:
            if (a!=0):
                sumz=two[b]-two[a-1];
            else:
                sumz=two[b];
        
        if (cnto==0):
            if (a!=0):
                sumo=zero[b]-zero[a-1];
            else:
                sumo=zero[b];
        elif (cnto==1):
            if (a!=0):
                sumo=one[b]-one[a-1];
            else:
                sumo=one[b];
        else:
            if (a!=0):
                sumo=two[b]-two[a-1];
            else:
                sumo=two[b];
        
        if (cntt==0):
            if (a!=0):
                sumt=zero[b]-zero[a-1];
            else:
                sumt=zero[b];
        elif (cntt==1):
            if (a!=0):
                sumt=one[b]-one[a-1];
            else:
                sumt=one[b];
        else:
            if (a!=0):
                sumt=two[b]-two[a-1];
            else:
                sumt=two[b];
        
        print (sumz*(sumz+1))/2+(sumo*(sumo-1))/2+(sumt*(sumt-1))/2
        i=i+1
  
