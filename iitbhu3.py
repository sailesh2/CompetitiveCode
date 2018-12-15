x=raw_input().split(' ')
a=int(x[0])
b=int(x[1])

y=raw_input().split(' ')
n=int(y[0])
m=int(y[1])

savea=a
saveb=b

if a>b:
    while 1:
        if a%b==0:
            gcd=b
            break
        temp=a
        a=b
        b=temp%b
else:
    while 1:
        if b%a==0:
            gcd=a
            break
        temp=b
        b=a
        a=temp%a
#print gcd
lcm=(savea*saveb)/gcd
#print lcm
if lcm/savea<=n and lcm/saveb<=m:
    print "Yes"
else:
    print "No"
