t=input()
i=0
while i<t:
    n=input()
    if n%2!=0:
        n=(n-1)/2
        s=bin(n)
        print s[2:]
    else:
        print "-1"
    i=i+1
