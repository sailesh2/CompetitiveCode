f=raw_input()
m=raw_input()
s=raw_input()
a=0
b=0
c=0
if f=="rock" and m=="scissors" and s=="scissors":
    a=1
if f=="paper" and m=="rock" and s=="rock":
    a=1
if f=="scissors" and m=="paper" and s=="paper":
    a=1

if m=="rock" and f=="scissors" and s=="scissors":
    b=1
if m=="paper" and f=="rock" and s=="rock":
    b=1
if m=="scissors" and f=="paper" and s=="paper":
    b=1

if s=="rock" and m=="scissors" and f=="scissors":
    c=1
if s=="paper" and m=="rock" and f=="rock":
    c=1
if s=="scissors" and m=="paper" and f=="paper":
    c=1
if a==1 and b==0 and c==0:
    print "F"
elif b==1 and a==0 and c==0:
    print "M"
elif c==1 and a==0 and b==0:
    print "S"
else:
    print "?"
