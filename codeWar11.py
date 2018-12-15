x=input()
y=input()
z=input()

a=x
b=y
if a>=b:
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
a=x
b=y
k=1
l=0
arr=[]
while k<=1000:
    if (z*k)>=(a+b) and (z*k)%gcd==0:
        z=z*k
        arr.append(z)
        l=l+1
        break
    k=k+1

mini=100000
i=0
while i<l:
    c=arr[i]
    cnt=0
    if a>=b:
        x=1
        while x<=c:
            y=1
            while y<=c:
                if a*x+b*y==c:
                    if x+y<=mini:
                        mini=x+y
                    cnt=1
                    break
                y=y+1
            if cnt==1:
                break
            x=x+1
    else:
        y=1
        while y<=c:
            x=1
            while x<=c:
                if a*x+b*y==c:
                    if x+y<=mini:
                        mini=x+y
                    cnt=1
                    break
                x=x+1
            if cnt==1:
                break
            y=y+1
    i=i+1
print mini

        
