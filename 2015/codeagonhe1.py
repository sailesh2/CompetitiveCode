t=input()
n=input()
x=raw_input().split(' ')
j=0
sm=0
while j<n:
    sm=sm+int(x[j])
    j=j+1
each=float(sm)/t
sm=0
maxi=0
j=0
while j<n:
    sm=sm+int(x[j])
    if sm>each:
        if sm>=maxi:
            maxi=sm
        sm=0
    j=j+1
print maxi
