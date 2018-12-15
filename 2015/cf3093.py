n=input()
arr=[]
i=0
while i<n:
    x=input()
    arr.append(x)
    i=i+1
fac=[1]
i=1
p=1
while i<=1000:
    p=p*i
    fac.append(p)
    i=i+1
i=0
p=1
sm=0
while i<n-1:
    sm=sm+arr[i]
    p=(p* (fac[sm+arr[i+1]-1]/(fac[sm]*fac[arr[i+1]-1]))%1000000007)%1000000007
    i=i+1
print p%1000000007
