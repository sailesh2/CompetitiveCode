s=raw_input()
l=len(s)
q=input()
i=0
while i<q:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    if s[(a-1)%l]==s[(a-1)%l]:
        print "YES"
    else:
        print "NO"
    i=i+1
