x=raw_input().split(' ')
t=int(x[0])
s=int(x[1])
q=int(x[2])

val=float((q*(t-s)))/(q-1)
if val%t==0:
    v=int(val/t)
    if v==0:
        print v+1
    else:
        print v
else:
    print int(val/t)+1
