mod = 998244353 
arr=[]

def xNonX(index, t, prod):
    v=k-taken[index]
    if t=='X':
        if index-2<0 or arr[index-2]!=-1:
            return (prod//v)
        return (xNonX(index-2,'N',prod)//v)
    else:
        if index-2<0 or arr[index-2]!=-1:
            return ((prod//v) * (k-1))
        return (((xNonX(index-2, 'X', prod)//v) * (k-1)) + ((xNonX(index-2, 'N', prod)//v) * (k-2)))

x=input().split(' ')
n=int(x[0])
k=int(x[1])

a=input().split(' ')

i=0
while i<n:
    arr.append(int(a[i]))
    i=i+1

taken=[0]*n
p=1
i=0
while i<n:
    if arr[i]==-1:
        left=-2
        right=-2
        
        if i-2>=0:
            left=arr[i-2]
        if i+2<n:
            right=arr[i+2]
        if left==right:
            if left==-1:
                p=(p*(k-1)%mod)%mod
            elif left==-2:
                p=(p*k)%mod
            else:
                p=(p*(k-2)%mod)%mod
        else:
            if left==-1:
                if right==-2:
                    p=(p*(k-1)%mod)%mod
                else:
                    p = ((xNonX(i-2,'X',p)*(k-1))%mod + (xNonX(i-2,'N',p)*(k-2)  )%mod)%mod
                    if p==0:
                        print("HIT")
                        print(i)
            elif left==-2:
                if right ==-1:
                    p=(p*k)%mod
                else:
                    p=(p*(k-1)%mod)%mod
            else:
                if right ==-1 or right == -2:
                    p=(p*(k-1)%mod)%mod
                else:
                    p=(p*(k-2)%mod)%mod

        if left==-1:
            taken[i]=1
        else:
            taken[i]=0

            
    else:
        left=-1
        right=-1
        
        if i-2>=0:
            left=arr[i-2]
        if i+2<n:
            right=arr[i+2]
        if left==arr[i] or right==arr[i]:
            p=0
            break

    i=i+1

print(p)
                
        
        
