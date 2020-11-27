def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

n=int(input())

i=0
g=0
g2=0
arr=[]
brr=[]
while i<n:
    x=input().split(' ')
    a=int(x[0])
    b=int(x[1])
    arr.append(a)
    brr.append(b)
    g2=gcd(a,b)
    g=gcd(((a*b)//(g2*g2))*g2,g)
    i=i+1

if g==1:
    print("-1")
else:
    cnt=-1
    i=0
    while i<n:
        if arr[i]%g!=0 and brr[i]%g!=0:
            cnt=i
            if gcd(arr[i],brr[i])==1:
                break
        i=i+1

    if cnt==-1:
        print(g)
    else:
        save=cnt
        cnt2=0
        i=0
        while i<n:
            if arr[i]%gcd(arr[save],g)!=0 and brr[i]%gcd(arr[save],g)!=0:
                cnt2=1
                break
            i=i+1
    
        cnt3=0
        i=0
        while i<n:
            if arr[i]%gcd(brr[save],g)!=0 and brr[i]%gcd(brr[save],g)!=0:
                cnt3=1
                break
            i=i+1

        if cnt2==0 or cnt3==0:
            if gcd(arr[save],brr[save])>1:
                print(gcd(arr[save],brr[save]))
            else:
                if cnt2==0:
                    print(gcd(arr[save],g))
                else:
                    print(gcd(brr[save],g))
        else:
            print("-1")
