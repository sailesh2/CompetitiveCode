s=raw_input()
ch='hello'
i=0
j=0
cnt=0
while i<len(s):
    if s[i]==ch[j]:
        j=j+1
    if j==5:
        cnt=1
        break
    i=i+1
if cnt==0:
    print "NO"
else:
    print "YES"
