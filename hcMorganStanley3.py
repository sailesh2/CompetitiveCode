import math
def gcd(a,b):
    if (b==0):
        return a
    a%=b
    return gcd(b,a)

def generateFraction(inp):
    frac = inp;

    precision = 1000000000;
    
    gcd_ = gcd(int(round(frac * precision)), precision);

    denominator = precision / gcd_;
    numerator = int(round(frac * precision)) / gcd_;

    gcdA=gcd(numerator,denominator)
    if gcdA!=denominator:
        ans= str(numerator/gcdA) + " / " + str(denominator/gcdA)
    else:
        ans=str(numerator/gcdA)
    return ans

t=int(raw_input())
i=0
while i<t:
    n=int(raw_input())
    x=raw_input().split(' ')
    j=0
    arr=[]
    while j<n:
        arr.append(int(x[j]))
        j=j+1
    if n==1:
        ans='1'
    else:
        j=0
        size=n/2 - 1
        sm=0
        while j<=size:
            sm=sm+float(arr[j])/(j+2) + float(arr[n-j-1])/(j+2) 
            j=j+1
        
        if n%2!=0:
            sm=sm+float(arr[j])/(j+2)
        ans=generateFraction(sm)
    print ans
    i=i+1
