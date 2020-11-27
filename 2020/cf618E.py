n=int(input())
x=input().split(' ')
arr=[]
i=0
while i<n:
    arr.append(int(x[i]))
    i=i+1

i=0
cnt=0
ans=[]
s=0
while i<n:
    if i+1<n and arr[i]>=arr[i+1]:
        s=s+arr[i]
        cnt=cnt+1
    else:
        if cnt>0:
            s=s+arr[i]
            v=s/(cnt+1)
            j=0
            while j<cnt+1:
                ans.append('%.9f'%v)
                j=j+1
            s=0
            cnt=0
        else:
          ans.append('%.9f'%arr[i])
    i=i+1

i=0
while i<n:
    print(ans[i])
    i=i+1
