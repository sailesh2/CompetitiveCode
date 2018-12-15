i=3
ctr=1
arr=[2]
while 1:
    cnt=0
    if i%2!=0:
        j=0
        while j<ctr and arr[j]<=pow(i,0.5):
            if i%arr[j]==0:
                cnt=1
                break
            j=j+1
        if cnt==0:
            arr.append(i)
            #print i
            ctr=ctr+1
    if ctr==200:
        break
    i=i+1
t=input()
i=0
while i<t:
    n=input()
    j=0
    while j<ctr:
        if arr[j]>n:
            print arr[j]
            break
        j=j+1
    i=i+1
