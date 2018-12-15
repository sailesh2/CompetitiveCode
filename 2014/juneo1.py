t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    b=int(x[0])
    g=int(x[1])
    if b>2*g:
        print "Little Jhool wins!"
    else:
        print "The teacher wins!"
    i=i+1
