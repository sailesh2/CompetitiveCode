n=input()
n=n-3
sm=0
val=0
i=0
p=1
while i<=n:
    val=(val*2+p)%1000000009
    p=(p*2)%1000000009
    sm=(sm+val)%1000000009
    i=i+1
print sm%1000000009
