def gcd(a,b):
    if (b==0):
        return a
    a%=b
    return gcd(b,a)
n=int(raw_input())
i=1
save=-1
maxi=0
while i<n:
    j=n-i
    if i<j and gcd(i,j)==1:
        if float(i)/j > maxi:
            maxi=float(i)/j
            save=i
    i=i+1
print save,n-save
