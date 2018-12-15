t=input()
i=0
while i<t:
    s=raw_input()
    has=[0]*300
    sm=0
    j=0
    while j<len(s):
        k=ord(s[j])
        if has[k]>0:
            sm=((sm%1000000007)+pow(2,j-has[k]+1,1000000007))%1000000007
        has[k]=j+1
        j=j+1
    print sm%1000000007
    i=i+1
