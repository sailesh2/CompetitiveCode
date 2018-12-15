t=input()
i=0
while i<t:
    s=raw_input()
    n=input()
    x=raw_input().split(' ')
    arr=[]
    j=0
    while j<len(s):
        arr.append(int(s[j]))
        j=j+1
    arr.sort()
    s2=''
    j=len(s)-1
    while j>=0:
        s2=s2+str(arr[j])
        j=j-1
    print s2
    i=i+1
