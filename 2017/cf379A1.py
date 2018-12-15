l=int(raw_input())
s=raw_input()
a=0
d=0
i=0
while i<l:
    if s[i]=='A':
        a=a+1
    else:
        d=d+1
    i=i+1
if a>d:
    print "Anton"
elif a<d:
    print "Danik"
else:
    print "Friendship"
