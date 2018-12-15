def isViowel(ch):
    return (ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')
s=raw_input()
ans=''
i=0
ctr=0
while i<len(s):
    if isViowel(s[i]):
        ctr=0
    else:
        ctr=ctr+1
    if ctr>=3:
        if s[i-2]==s[i-1] and s[i-1]==s[i]:
            x=0
        else:
            ctr=1
            ans=ans+' '
    ans=ans+s[i]
    i=i+1
print ans
