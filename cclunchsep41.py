t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    arr=[]
    j=0
    while j<n:
        arr.append(int(x[j]))
        j=j+1
    m=input()
    j=0
    while j<m:
        z=raw_input().split(' ')
        a=int(z[1])
        b=int(z[2])
        if int(z[0])==1:
            ctr=0
            k=a
            while k<=b-1:
                if arr[k]!=arr[k-1]:
                    ctr=ctr+1
                k=k+1
            print ctr+1
        else:
            l=arr[a-1:b]
            del arr[a-1:b]
            arr=l+arr
        j=j+1
    i=i+1
            
    
            
