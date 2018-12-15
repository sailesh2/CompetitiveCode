s=raw_input()
lt=len(s)
maxi=0
ctr=0
i=0
while i<lt:
    if s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9':
        ctr=1
        j=i-1
        cnt=0
        p=int(s[i])
        while j>=0:
            if s[j]=='0' or s[j]=='1' or s[j]=='2' or s[j]=='3' or s[j]=='4' or s[j]=='5' or s[j]=='6' or s[j]=='7' or s[j]=='8' or s[j]=='9':
                p=p*10+int(s[j])
            else:
                if cnt==0:
                    p=p*10+9
                    cnt=1
                else:
                    break
            j=j-1
        num=int(str(p)[::-1])
        if num>=maxi:
            maxi=num
        p=int(s[i])
        j=i+1
        cnt=0
        while j<lt:
            if s[j]=='0' or s[j]=='1' or s[j]=='2' or s[j]=='3' or s[j]=='4' or s[j]=='5' or s[j]=='6' or s[j]=='7' or s[j]=='8' or s[j]=='9':
                p=p*10+int(s[j])
            else:
                if cnt==0:
                    p=p*10+9
                    cnt=1
                else:
                    break
            j=j+1
        if p>=maxi:
            maxi=p
    i=i+1
if ctr==0:
    maxi=9
print maxi
