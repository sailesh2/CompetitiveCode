n=input()
x=raw_input().split(' ')
save=(0-int(x[0]))%n
cnt=0
i=1
while i<n:
    if i%2==0:
        if (i-int(x[i]))%n!=save:
            cnt=1
            break
    else:
        if (n-((i-int(x[i]))%n))%n!=save:
            cnt=1
            break
    i=i+1
if cnt==0:
    print "Yes"
else:
    print "No"
    
