t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    d=int(x[1])
    p=input()
    if a%p==0:
        print "0"
    else:
        if p<=d:
            print "-1"
        else:
            if float(a)/(p-d)==a/(p-d):
                print a/(p-d)
            else:
                print "-1"
    i=i+1
