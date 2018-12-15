n=input()
save=""
cntr=0
cnt=0
i=0
while i<n:
    s=raw_input()
    v=0
    c=0
    j=0
    if cntr==0:
        while j<len(s):
            if s[j]=='a' or s[j]=='e' or s[j]=='i' or s[j]=='o' or s[j]=='u':
                v=v+1
                c=0
            else:
                c=c+1
                v=0
            if v>=2:
                if s[j]!=s[j-1]:
                    cnt=1
                    break
            if c>=3:
                cnt=1
                break
            j=j+1
    if cntr==0 and cnt==1:
        save=s
        cntr=1
    i=i+1
print save
