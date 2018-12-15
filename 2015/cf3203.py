x=raw_input().split(' ')
a=int(x[0])
b=int(x[1])

if a<b:
    print "-1"
elif a==b:
    print "0"
else:
    val1=(a-b)/2
    ans1=float(a-b)/(2*val1)
    
    
    val2=(a+b)/2
    ans2=float(a+b)/(2*val2)

    print "%.12f"%min(ans1,ans2)
