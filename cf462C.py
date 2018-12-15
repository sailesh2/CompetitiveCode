n=input()
x=raw_input().split(' ')
arr=[]
s=0
i=0
while i<n:
    arr.append(int(x[i]))
    i=i+1
arr.sort()
i=0
while i<n-1:
    s=s+(i+2)*arr[i]
    i=i+1
s=s+(i+1)*arr[i]
print s
