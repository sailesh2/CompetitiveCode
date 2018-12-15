x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])

b=raw_input().split(' ')
g=raw_input().split(' ')

brr=[]
grr=[]
i=0
while i<n:
    brr.append(int(b[i]))
    grr.append(int(g[i]))
    i=i+1
brr.sort()
grr.sort()

i=0
j=0
ctr=0
while i<n and j<n:
    if abs(brr[i]-grr[j])<=k:
        ctr=ctr+1
        i=i+1
        j=j+1
    else:
        if brr[i]>grr[j]:
            j=j+1
        else:
            i=i+1

print ctr
#i=0
#j=0
#ctr2=0
#while i<n and j<n:
#    if abs(brr[i]-grr[j])<=k:
#        ctr2=ctr2+1
#        i=i+1
#        j=j+1
#    else:
#        j=j+1
#print ctr2
#print max(ctr,ctr2)
    
