t=input()
i=0
while i<t:
    x=raw_input().split(' ')
    a=int(x[0])
    b=int(x[1])
    c=int(x[2])
    if a%2==0 and b%2==0 and c%2==0:
        print "Aishwarya"
    else:
        print "Ashima"
    i=i+1
