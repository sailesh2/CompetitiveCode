n=input()
x=raw_input()
if n==6:
    print "espeon"
elif n==8:
    print "vaporeon"
else:
    a=["jolteon","flareon","umbreon","leafeon","glaceon","sylveon"]
    j=0
    while j<len(a):
        i=0
        cnt=0
        while i<len(x):
            if x[i]!='.':
                if x[i]==a[j][i]:
                    cnt=1
                else:
                    cnt=0
                    break
            i=i+1
        if cnt==1:
            print a[j]
            break
        j=j+1
