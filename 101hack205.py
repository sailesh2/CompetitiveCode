x=raw_input().split(' ')
p=int(x[0])
q=int(x[1])
s=raw_input()
lt=len(s)
brr=[]
j=0
while j<lt:
    rem=0
    arr=[]
    i=j
    while i<lt:
        num=rem*10+int(s[i])
        if num%p==0:
            arr.append(1)
        else:
            arr.append(0)
        rem=num%p
        i=i+1
    brr.append(arr)
    j=j+1
i=0
while i<q:
    y=raw_input().split(' ')
    b=int(y[0])
    e=int(y[1])
    sm=0
    j=b-1
    while j<=e-1:
        k=j
        while k<=e-1:
            sm=sm+brr[j][k-j]
            k=k+1
        j=j+1
    print sm
    i=i+1
