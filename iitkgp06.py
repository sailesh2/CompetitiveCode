x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])
q=input()
i=0
while i<q:
    d=input()
    k1=0
    arr=[]
    while d>0:
        arr.append(d%2)
        k1=k1+1
        d=d/2
    p=1
    l=n
    j=0
    while j<k1:
        if arr[j]==1:
            p=p*l
        l=l*l
        j=j+1
    print ((p*(n-1-k)+k)/(n-1))%1000000007
    i=i+1
