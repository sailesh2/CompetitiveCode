s=str(raw_input())
maxi=0
i=0
save=-1
while i<len(s):
    if s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U':
        maxi=max(i-save,maxi)
        save=i
    i=i+1
maxi=max(len(s)-save)
if maxi==0:
    maxi=len(s)+1
print maxi
