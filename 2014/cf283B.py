lt=input()
x=raw_input()
mini=10**lt
sav=''
i=0
while i<lt:
    d=10-int(x[i])
    a1=''
    j=0
    while j<i:
        a1=a1+str((int(x[j])+d)%10)
        j=j+1
    b1=''
    j=i+1
    while j<lt:
        b1=b1+str((int(x[j])+d)%10)
        j=j+1
    s1=str(0)+b1+a1
    ans=int(s1)
    if ans<mini:
        mini=ans
        sav=s1
    i=i+1
print sav
    
        
