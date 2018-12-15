t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    ans=[int(x[0])]
    j=1
    while j<n:
        a=int(x[j-1])
        b=int(x[j])
        if a>=b:
            while 1:
                if a%b==0:
                    break
                temp=a
                a=b
                b=temp%a
            gcd=b
        else:
            while 1:
                if b%a==0:
                    break
                temp=b
                b=a
                a=temp%b
            gcd=a
        ans.append((int(x[j])*int(x[j-1]))/gcd)
        j=j+1
    ans.append(int(x[n-1]))
    j=0
    while j<n+1:
        print ans[j],
        j=j+1
    print
    i=i+1
