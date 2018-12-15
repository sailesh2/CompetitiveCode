import math

def gcd(a , b):
    if (b==0):
        return a;
    a%=b
    return gcd(b,a);

x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])

last=(10**k)
print (n*last)/gcd(last,n)
