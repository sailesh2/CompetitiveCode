x=int(input())
last = x
p=1
while last>0:
    if int(last/10)<=0:
        val=last%10
    else:
        p=p*10
    last=int(last/10)
    
one = val*p-1
sec = x-one
s=0
while one>0:
    s=s+one%10
    one=int(one/10)

while sec>0:
    s=s+sec%10
    sec=int(sec/10)
print(s)
