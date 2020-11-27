t=int(input())
i=0
while i<t:
    x=input().split(' ')
    n=int(x[0])
    g=int(x[1])
    b=int(x[2])

    req=n//2 + n%2

    c=n//(g+b)

    req=req-c*g

    left=n-c*(g+b)

    if req<=0:
        print(n)
    else:
        while req-min(left,g*(left//g))>0:
            left=left+b
        
            
                

    
