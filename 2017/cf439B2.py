x=raw_input().split(' ')
a=int(x[0])
b=int(x[1])

if b-a>=10:
    print "0"
else:
    p=1
    a=a+1
    while a<=b:
        p=p*a
        a=a+1
    print p%10
