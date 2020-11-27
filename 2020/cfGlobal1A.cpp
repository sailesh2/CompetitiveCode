x=input().split(' ')

b=int(x[0])
k=int(x[1])

y=input().split(' ')
a=[]
i=0
sm=0
pb=pow(b,k-1)
while i<k:
    sm=(sm+int(y[i])*pb)%10
    pb=pb//b
    i=i+1

if sm%2==0:
    print('even')
else:
    print('odd')

