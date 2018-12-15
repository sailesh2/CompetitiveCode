n=input()
x=raw_input().split(' ')
a=[]
p=1
i=0
while i<n:
    a.append(int(x[i]))
    p=p*a[i]
    i=i+1
b=[]
i=0
while i<n:
    b.append(p/a[i])
    i=i+1
m=input()
sav=[-1]*1000
pa=1
pb=1
i=0
cnt=1
while i<m:
    y=raw_input().split(' ')
    if int(y[0])==0:
        if sav[int(y[1])-1]==-1:
            if int(y[2])==0:
                cnt=0
            else:
                pb=pb*int(y[2])
            sav[int(y[1])-1]=int(y[2])
            pa=pa*a[int(y[1])-1]
        else:
            if int(y[2])==0:
                cnt=0
            else:
                if sav[int(y[1])-1]!=0:
                    pb=(pb/sav[int(y[1])-1])*int(y[2])
                else:
                    cnt=1
                    pb=pb*int(y[2])
            sav[int(y[1])-1]=int(y[2])
            if a[int(y[1])-1]!=0:
                pa=(pa/a[int(y[1])-1])*a[int(y[1])-1]
    else:
        if cnt==0:
            if sav[int(y[1])-1]==0:
                print (b[int(y[1])-1]/pa)*pb
            else:
                print "0"
        else:
            print (b[int(y[1])-1]/pa)*pb
    i=i+1
        
