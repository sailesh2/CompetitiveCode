n=input()
i=0
arr=[]
while i<n:
    val=input()
    arr.append(val)
    i=i+1
brr=[]
lenbrr=0
i=0
while i<n:
    j=i+1
    while j<n:
        brr.append(abs(arr[i]-arr[j]))
        lenbrr=lenbrr+1
        j=j+1
    i=i+1
if lenbrr==1:
    gcd=brr[0]
else:
    a=brr[0]
    b=brr[1]
    if a>b:
        while 1:
            if a%b==0:
                gcd=b
                break
            temp=a
            a=b
            b=temp%b
    else:
        while 1:
            if b%a==0:
                gcd=a
                break
            temp=b
            b=a
            a=temp%a
    i=2
    while i<lenbrr:
        a=gcd
        b=brr[i]
        if a>b:
            while 1:
                if a%b==0:
                    gcd=b
                    break
                temp=a
                a=b
                b=temp%b
        else:
            while 1:
                if b%a==0:
                    gcd=a
                    break
                temp=b
                b=a
                a=temp%a
        i=i+1
i=2
ans=[]
while i*i<=gcd:
    if gcd%i==0:
        a=i
        b=gcd/i
        if a==b:
            ans.append(a)
        else:
            ans.append(a)
            ans.append(b)
    i=i+1
ans.append(gcd)
ans.sort()
i=0
while i<len(ans):
    print ans[i],
    i=i+1
