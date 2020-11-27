s=input()
n=len(s)
m=1000000007
fac=[1]
f=1
i=1
while i<=n+1:
    f=(f*i)%m
    fac.append(f)
    i=i+1
ctr=[0]*125
i=0
while i<n:
    ctr[ord(s[i])]=ctr[ord(s[i])]+1
    i=i+1

dupFac=1
chars=[]
c=ord('a')
while c<=ord('z'):
    dupFac=(dupFac*fac[ctr[c]])%m
    chars.append(c)
    c=c+1
    
c=ord('A')
while c<=ord('Z'):
    dupFac=(dupFac*fac[ctr[c]])%m
    chars.append(c)
    c=c+1

dict={}
i=0
while i<len(chars):
    c=chars[i]
    j=0
    while j<len(chars):
        c2=chars[j]
        villians = ctr[c]
        if c!=c2:
            villians = villians + ctr[c2]
        if villians>int(n/2):
            dict[(c,c2)]=0
            dict[(c2,c)]=0
        else:

            left = int(n/2)-villians
            ans = (2* (fac[int(n/2)] * fac[n-villians])%m )%m
            ans = (ans * pow(fac[left], m-2, m) )%m
            ans = (ans * pow(dupFac, m-2, m) )%m
            dict[(c,c2)]=ans
            if(c!=c2):
                dict[(c2,c)]=ans
        j=j+1
    i=i+1

q=int(input())
i=0
while i<q:
    z=input().split(' ')
    x=int(z[0])
    y=int(z[1])

    print(dict[(ord(s[x-1]),ord(s[y-1]))])
    i=i+1
