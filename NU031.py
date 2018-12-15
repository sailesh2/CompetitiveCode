t=input()
i=0
while i<t:
    s=raw_input()
    c=s[0]
    j=1
    ctr=0
    while j<len(s):
        if s[j]==c:
            ctr=ctr+1
        else:
            c=s[j]
        j=j+1
    print ctr
    i=i+1
