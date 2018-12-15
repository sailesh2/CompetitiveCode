x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
z=raw_input().split(' ')
arr=[]
i=0
while i<n:
    arr.append(int(z[i]))
    i=i+1
s=0
i=0
while i<m:
    y=raw_input().split(' ')
    if y[0]=='C':
        s=s+n-int(y[1])
    elif y[0]=='A':
        s=s+int(y[1])
    else:
        print arr[(int(y[1])-1-s)%n]
    i=i+1
