x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
k=n/m
k=(m-(n%m))*(k*(k-1))/2+(n%m)*(k*(k+1))/2
l=n-(m-1)
print k,(l*(l-1))/2
