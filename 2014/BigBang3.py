t=input()
mp=[]
i=0
while i<t:
    s=raw_input()
    lt=len(s)
    mp.append([])
    j=0
    while j<lt:
        k=j+1
        while k<=lt:
            strn=s[j:k]
            mp[i].append(strn)
            k=k+1
        j=j+1
    i=i+1
q=input()
i=0
while i<q:
    r=raw_input().split(' ')
    a=int(r[0])
    b=int(r[1])
    c=r[2]
    ctr=0
    j=a
    while j<=b:
        if c in mp[j-1]:
            ctr=ctr+1
        j=j+1
    print ctr
    i=i+1
