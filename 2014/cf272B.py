def fun(i,cntr,y,lt,ctr):
    global save
    if i>=lt:
        if cntr==ctr:
            save=save+1
        return
    if y[i]=='+':
        fun(i+1,cntr+1,y,lt,ctr)
    elif y[i]=='-':
        fun(i+1,cntr-1,y,lt,ctr)
    else:
        fun(i+1,cntr+1,y,lt,ctr)
        fun(i+1,cntr-1,y,lt,ctr)
    return

global save
save=0
x=raw_input()
y=raw_input()
ctr=0
lt=len(x)
i=0
while i<lt:
    if x[i]=='+':
        ctr=ctr+1
    else:
        ctr=ctr-1
    i=i+1
fun(0,0,y,lt,ctr)
ctr=0
i=0
while i<lt:
    if y[i]=='?':
        ctr=ctr+1
    i=i+1
print "%.12f" %(float(save)/(2**ctr))
