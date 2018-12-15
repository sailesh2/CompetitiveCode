t=input()
i=0
while i<t:
    orig=raw_input()
    co=raw_input()
    n=len(orig)
    m=len(co)
    arr=[]
    j=0
    while j<n:
        k=j+1
        while k<=n:
            arr.append(orig[j:k])
            k=k+1
        j=j+1
    maxi=0
    j=0
    while j<m:
        k=j+1
        while k<=m:
            if co[j:k] in arr:
                if k-j>maxi:
                    maxi=k-j
            k=k+1
        j=j+1
    print m-maxi
    i=i+1
