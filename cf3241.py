x=raw_input().split(' ')
n=int(x[0])
t=int(x[1])
val=(10**(n-1))/t
if val*t>=(10**(n-1)) and val*t<(10**(n)):
    print val*t
elif (val+1)*t>=(10**(n-1)) and (val+1)*t<(10**(n)):
    print (val+1)*t
else:
    print "-1"
