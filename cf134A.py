n=input()
x=raw_input().split(' ')
i=0
array=[]
s=0
while i<n:
   s=s+int(x[i])
   i=i+1
i=0
while i<n:
    if float(s-int(x[i]))/(n-1)==int(x[i]):
        array.append(i+1)
    i=i+1
print len(array)
i=0
while i<len(array):
    print array[i],
    i=i+1
