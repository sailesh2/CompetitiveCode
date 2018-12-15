n=1
s='1'

while(len(s)<=1000000): 
    n=n+1
    s=s+str(n)

t=input()
i=0
while i<t:
    x=input()
    print s[x-1]
    i=i+1
