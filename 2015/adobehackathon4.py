n=input()
z=raw_input().split(' ')
i=0
x=[]
while i<n:
    x.append(int(z[i]))
    i=i+1
arr=[]
i=0
sm=0
while i<n:
    sm=(sm*10)+x[i]
    arr.append(sm)
    i=i+1

q=input()
i=0
while i<q:
    y=raw_input().split(' ')
    a=int(y[0])
    l=int(y[1])
    r=int(y[2])
    if a==0:
        print (arr[r-1]%(pow(10,(r-l+1))))%1000000007
    else:
        x[l-1]=r
        sm=0

        if l-2>=0:
            sm=arr[l-2]
        j=l-1
        while j<n:
            sm=sm*10+x[j]
            arr[j]=sm
            j=j+1
    i=i+1
