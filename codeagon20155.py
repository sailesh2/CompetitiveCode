x=raw_input().split(' ')
k=int(x[0])
n=int(x[1])

y=raw_input().split(' ')
i=0
arr=[]
while i<n:
    arr.append(int(y[i]))
    i=i+1

p=1
i=0
mini==10000000
while i<n:
    j=i
    p=1
    save=-1
    while j<n:
        p=p*arr[j]
        if p%k==0:
            save=j
            break
        j=j+1
    if save!=-1:
        if save-i+1<mini:
            mini=save-i+1
    i=i+1
if mini=10000000:
    print "NONE"
else:
    print "Minimum interval length:",mini
    print "Found intervals:"
    i=0
    while i<n:
        j=i
        p=1
        if i+mini-1<n:
            while j<i+mini:
               p=p*arr[j]
               j=j+1
            if p%k==0:
                print "["+str(i+1)+", "+str(j)+"]"
        i=i+1
