n=input()
x=raw_input().split(' ')
arr=[]
i=0
while i<n:
    arr.append(int(x[i]))
    i=i+1
arr.sort()
i=1
sm=arr[0]
ctr=1
while i<n:
    if (arr[i]<sm or arr[i]>sm+4):
        sm=arr[i]
        ctr=ctr+1
    i=i+1
print ctr        
            
