n=input()
x=raw_input()
i=0
while i<n:
    if x[i]=='0':
        break
    i=i+1
if i>=n:
    i=n-1
print i+1
