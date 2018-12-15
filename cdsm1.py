t=input()
i=0
while i<t:
    s=raw_input()
    j=0
    crr=[0]*300
    maxi=0
    while j<len(s):
        crr[ord(s[j])]=crr[ord(s[j])]+1
        if crr[ord(s[j])]==maxi:
            if ord(s[j])<=ord(save):
                save=s[j]
        elif crr[ord(s[j])]>maxi:
            maxi=crr[ord(s[j])]
            save=s[j]
        j=j+1
 #   print save
    s=s.replace(save,'?')
    print s
    i=i+1
