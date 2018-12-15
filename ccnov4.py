def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)
def modinv(a, m):
    g, x, y = egcd(a, m)
    return x % m
t=input()
i=0
while i<t:
    n,m,q=map(int,raw_input().split())
    arr=[0]*1000
    arr1=[0]*1000
    j=2
    arr[0]=1
    arr1[0]=1
    arr[1]=1
    arr1[1]=modinv(1,m)
    while j<=n:
        arr[j]=(arr[j-1]*pow(j,j))
        #arr1[j]=(modinv(arr[j]))
        j=j+1
    #print arr[0:10]
    #print arr1[0:10]
    j=0
    while j<q:
        ink=input()
        print (arr[n]/(arr[ink]*arr[n-ink]))
        j=j+1
    i=i+1
        
