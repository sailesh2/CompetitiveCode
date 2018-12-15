x=raw_input().split(' ')
n=int(x[0])
p=int(x[1])
l=int(x[2])

maxi=0
y=raw_input().split(' ')
i=0
while i<n:
    if p*int(y[i])>maxi:
        maxi=p*int(y[i])
        save=i+1
    p=p-l
    i=i+1
print save
