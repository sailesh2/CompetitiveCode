n=input()
s=raw_input()
arr=[0]*300
i=0
while i<len(s):
    arr[ord(s[i])]=arr[ord(s[i])]+1
    i=i+1
sm=0
i=ord('a')
while i<=ord('z'):
    sm=sm+(arr[i]*(arr[i]+1))/2
    i=i+1
print sm
