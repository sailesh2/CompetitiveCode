n=input()
a=[1]*1000

i=2
while i<n**0.5:
    if a[i]==1:
        j=i*i
        while j<=n:
            a[j]=0
            j=j+i
    i=i+1
print a
i=2
while i<=n:
    if a[i]==1:
        print i
    i=i+1
