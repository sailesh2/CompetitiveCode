x=raw_input().split(' ')
n=int(x[0])
q=int(x[1])
s=raw_input()
arr=[]
i=0
while i<n:
    arr.append(int(s[i]))
    i=i+1
i=0
while i<q:
    y=raw_input().split(' ')
    if y[0]=='1':
        arr[int(y[1])-1]=int(y[2])
    else:
        c=int(y[1])-1
        d=int(y[2])
        sm=0
        smz=0
        smo=0
        smt=0
        while c<d:
            sm=(sm+arr[c])%3
            if sm==0:
                smz=smz+1
            elif sm==1:
                smo=smo+1
            else:
                smt=smt+1
            c=c+1
        print (smz*(smz+1))/2+(smo*(smo-1))/2+(smt*(smt-1))/2
    i=i+1
