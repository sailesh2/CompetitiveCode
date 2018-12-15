x=raw_input().split(' ')
a=int (x[0])
b=int (x[1])
c=int (x[2])
arr=[]
arr.append(a)
arr.append(b)
arr.append(c)

arr.sort()
arr.reverse()

sm=0
if arr[0]>arr[1]:
    sm=sm+(arr[0]-1-arr[1])+(arr[0]-1-arr[2])
elif arr[0]==arr[1]:
    if arr[1]>arr[2]:
        sm=sm+(arr[1]-1-arr[2])

print sm
