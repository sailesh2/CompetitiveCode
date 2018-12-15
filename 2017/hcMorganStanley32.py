import math
from fractions import Fraction
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
        ans=arr[0]
    else:
        j=0
        size=n/2 - 1
        sm=0
        while j<=size:
            sm=sm+float(arr[j])/(j+2) + float(arr[n-j-1])/(j+2) 
            j=j+1
        
        if n%2!=0:
            sm=sm+float(arr[j])/(j+2)
        parts=sm.as_integer_ratio()
        ans=str(Fraction(parts[0],parts[1]).limit_denominator())
    print ans
    i=i+1
