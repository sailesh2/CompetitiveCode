a=input()
b=input()
i=a
maxi=0
while i<=b:
    j=a
    while j<=b:
        if i^j>=maxi:
            maxi=i^j
        j=j+1
    i=i+1
print maxi
