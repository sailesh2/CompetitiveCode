from sys import stdin, stdout

def fastPow(a,b,mod):
   bin=a%mod
   p=1
   while (b>0):
       if (b%2==1):
           p=(p*bin)%mod
       bin=(bin*bin)%mod
       b=b//2

   return p 
n=int(stdin.readline())
i=0
items=[]
has=[0]*1000005
while i<n:
    x=stdin.readline().split(' ')
    k=int(x[0])
    j=1
    a=[]
    while j<=k:
        a.append(int(x[j]))
        has[int(x[j])]=has[int(x[j])]+1
        j=j+1
    items.append(a)
    i=i+1

i=0
smNum=0
smDen=0
mod=998244353 
while i<n:
    k=len(items[i])

    j=0
    num=0
    while j<k:
        num=(num+n-has[items[i][j]])%mod
        j=j+1

    if i==0:
        smDen=k
        smNum=num
    else:
        smNum=(smNum*k + smDen*num)%mod
        smDen=(smDen*k)%mod
    i=i+1

smDen=(smDen*(n*n)%mod)%mod
smNum=smDen-smNum
ans = (smNum%mod * fastPow(smDen%mod,(mod-2),mod) )%mod
stdout.write(str(ans))


