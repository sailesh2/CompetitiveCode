t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    y=raw_input().split(' ')
    z=raw_input().split(' ')
    j=0
    maxi=0
    while j<n:
        a=(k/int(y[j]))*int(z[j])
        if a>maxi:
            maxi=a
        j=j+1
    print maxi
    i=i+1
