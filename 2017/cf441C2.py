import math
n=int(raw_input())
s=1000
i=0
ls=[]
while i<=s:
    k=n-i
    if k<0:
        break
    ctr=0
    l=k
    while l>0:
        ctr=ctr+(l%10)
        l=l/10
    if ctr==i:
        ls.append(k)
    i=i+1
print len(ls)
ls.sort()
i=0
while i<len(ls):
    print ls[i],
    i=i+1
