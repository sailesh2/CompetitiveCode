n=input()
x=raw_input().split(' ')
i=0
s=0
while i<n:
   s=s^int(x[i])
   i=i+1
print s
