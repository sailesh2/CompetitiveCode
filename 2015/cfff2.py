s=raw_input()
l=input()
x=raw_input().split(' ')
arr=[]
i=0
sm=0
maxi=0
while i<26:
    arr.append(int(x[i]))
    if arr[i]>maxi:
        maxi=arr[i]
    i=i+1
i=0
while i<len(s):
    sm=sm+arr[ord(s[i])-97]*(i+1)
    i=i+1
fir=l+len(s)
sec=len(s)
sm=sm+((fir*(fir+1))/2-(sec*(sec+1))/2)*maxi
print sm
