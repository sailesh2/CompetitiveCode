
def binSearch():
    ctr=1
    save=0
    save2=0
    while 1:
        while save+ctr<=n and primes[save+ctr]<=A*palindromes[save+ctr]:
            save2=save+ctr
            ctr=ctr*2
        if save2==save:
            break
        else:
            save=save2
            ctr=1
    print save


def isPalindrome(x):
    dig=(bin(x))[2:]
    rev=dig[::-1]
    return dig==rev

x=raw_input().split(' ')

p=int(x[0])
q=int(x[1])

A=float(p)/q

n=100000

has=[0]*(n+1)
i=2
while i<=n:
    j=2*i
    while j<=n:
        has[j]=1
        j=j+i
    i=i+1


primes=[0,0]
i=2
ctr=0
while i<=n:
    if has[i]==0:
        ctr=ctr+1
    primes.append(ctr)
    i=i+1


palindromes=[0]
i=1
ctr=1
while i<=n:
    if isPalindrome(i):
        ctr=ctr+1
    palindromes.append(ctr)
    i=i+1

ans=0
i=1
while i<=n:
    if primes[i]<=A*palindromes[i]:
        ans=i
    i=i+1
        
if ans==0:
    print "Palindromic tree is better than splay tree"
else:
    print ans

