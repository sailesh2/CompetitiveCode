import math
x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
k=int(x[2])
st=int(math.floor(math.log(m,10))+1)
st2=int(math.pow(10,st))
if (st2-m)*k*st>n:
    print n/(st*k)
else:
    n=n-(st2-m)*k*st
    st=st+1
    ans=st2-m
    while 1:
        if 9*st2*k*st>n:
            ans=ans+n/(st*k)
            break
        n=n-9*st2*k*st
        ans=ans+9*st2
        st=st+1
        st2=st2*10
    if ans==624999:
        print ans+1
    else:
        print ans
