t=int(input())
i=0
while i<t:
    x=input().split(' ')
    n=int(x[0])
    d=int(x[1])

    bac = (n-1)*(n-1) + 4*(n-d)
    sol = (n-1 + bac)/2

    if bac>=0 and sol>=0:
        print('YES')
    else:
        print('NO')
    i=i+1
