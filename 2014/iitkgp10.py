t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    a=n%(k+1)
    if a==0 or (a>1 and a<1+k):
        print "Rani"
    else:
        print "Nandu"
    i=i+1
    
    
