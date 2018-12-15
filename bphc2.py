n=input()
x=raw_input().split(' ')
i=0
arr=[]
while i<n:
    arr.append(int(x[i]))
    i=i+1
print max(arr)-min(arr)
