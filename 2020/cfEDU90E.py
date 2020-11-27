t=int(input())
i=0
while i<t:
    z=input().split(' ')
    n=int(z[0])
    k=int(z[1])

    r=0
    cnt=0
    while r<=min(k,9):

        num = 2*n
        num = num - ((r)*(r+1) + (k-r)*(k-r+1))
        den = 2*(r+1)

        if num%den==0 and num//den>=0:
            if cnt==0:
                mini=num//den
            else:
                mini=min(mini,num//den)
            cnt=1

        r=r+1

    if cnt==0:
        print("-1")
    else:
        print(mini)

    i=i+1
        
