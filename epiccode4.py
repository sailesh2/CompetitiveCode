n=input()
x=raw_input().split(' ')
maxi=-10000000
i=0
while i<n:
    j=i
    k=i+1
    sm=0
    while j>=0 and k<n:
        sm=sm+int(x[j])*int(x[k])
        j=j-1
        k=k+1
        if sm<0:
            sm=0
        if sm>maxi:
            maxi=sm
    i=i+1

i=1
while i<n:
    j=i-1
    k=i+1
    sm=0
    while j>=0 and k<n:
        sm=sm+int(x[j])*int(x[k])
        j=j-1
        k=k+1
        if sm<0:
            sm=0
        if sm>maxi:
            maxi=sm
    i=i+1



print maxi
