x=raw_input().split(' ')
n=int(x[0])
k=int(x[1])
p=int(x[2])


y=raw_input().split(' ')
odd=[]
even=[]
i=0
while i<n:
    if int(y[i])%2==0:
        even.append(int(y[i]))
    else:
        odd.append(int(y[i]))
    i=i+1
lene=len(even)
leno=len(odd)

if lene<p:
    i=0
    cnt=0
    while i<=leno:
        if lene+i/2==p:
            cnt=1
            break
        i=i+2
    if cnt==1:
        startodd=i
        if (k-p)<=(leno-startodd) and (((leno-startodd)%2==0 and (k-p)%2==0) or ((leno-startodd)%2!=0 and (k-p)%2!=0)):
            print "YES"
            j=0
            while j<lene:
                print "1",
                print even[j]
                j=j+1
            if k-p==0:
                j=0
                while j<startodd-2:
                    print "2",
                    print odd[j],odd[j+1]
                    j=j+2
                j=startodd-2
                if leno-j>0:
                    print leno-j,
                while j<leno:
                    print odd[j],
                    j=j+1

                
            else:
                
                j=0
                while j<startodd:
                    print "2",
                    print odd[j],odd[j+1]
                    j=j+2
                j=startodd
                ctr=0
                while j<leno:
                    if ctr==k-p-1:
                        break
                    print "1",
                    print odd[j]
                    j=j+1
                    ctr=ctr+1
                if leno-j>0:
                    print leno-j,
                    while j<leno:
                        print odd[j],
                        j=j+1
            #print
        else:
            print "NO"


        
    else:
        print "NO"
else:
    if (k-p)<=leno and ((leno%2==0 and (k-p)%2==0) or (leno%2!=0 and (k-p)%2!=0)):
        print "YES"
        if p!=0:
            cnt2=0
            j=0
            ctr=0
            while j<lene:
                if ctr==p-1:
                    break
                print "1",
                print even[j]
                ctr=ctr+1
                j=j+1
            if k-p==0:
                if lene-j+leno>0:
                    print lene-j+leno,
                    while j<lene:
                        print even[j],
                        j=j+1
                    j=0
                    while j<leno:
                        print odd[j],
                        j=j+1
            else:
                if lene-j>0:
                    print lene-j,
                    while j<lene:
                        print even[j],
                        j=j+1
                print
                j=0
                ctr=0
                while j<leno:
                    if ctr==k-p-1:
                        break
                    print "1",
                    print odd[j]
                    ctr=ctr+1
                    j=j+1
                if leno-j>0:
                    print leno-j,
                while j<leno:
                    print odd[j],
                    j=j+1
                
                    
        else:
            cnt2=1







        if cnt2==1:
                j=0
                ctr=0
                while j<leno:
                    if ctr==k-p-1:
                        break
                    print "1",
                    print odd[j]
                    ctr=ctr+1
                    j=j+1
                if leno-j+lene>0:
                    print leno-j+lene,
                while j<leno:
                    print odd[j],
                    j=j+1
                j=0
                while j<lene:
                    print even[j],
                    j=j+1
        
    else:
        print "NO"
        
