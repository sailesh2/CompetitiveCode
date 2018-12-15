import math
t=input()
cnt=0
i=0
while i<t:
    x=raw_input().split(' ')
    if x[0]=="Qi":
        cnt=1-cnt
    else:
        a=int(x[1])
        b=int(x[2])
        arr=[]
        acntr=0
        a1=a
        while a1!=0:
            acntr=acntr+1
            arr.append(a1)
            a1=a1/2
        bcntr=0
        ctrb=0
        b1=b
        chk=0
        while b1!=0:
            bcntr=bcntr+1
            if chk==0: 
                ctrb=ctrb+1
                if b1 in arr:
                    save=b1
                    chk=1
            b1=b1/2
        ctra=0
        a1=a
        while 1:
            ctra=ctra+1
            if a1==save:
                break
            a1=a1/2
        #print ctra,ctrb
        ht=(acntr-ctra)

        if cnt==0:
            if x[0]=="Qb":
                if (acntr-1)%2==0:
                    ctra=ctra/2+ctra%2
                else:
                    ctra=ctra/2
                if (bcntr-1)%2==0:
                    ctrb=ctrb/2+ctrb%2
                else:
                    ctrb=ctrb/2
            else:
                if (acntr-1)%2==0:
                    ctra=ctra/2
                else:
                    ctra=ctra/2+ctra%2
                if (bcntr-1)%2==0:
                    ctrb=ctrb/2
                else:
                    ctrb=ctrb/2+ctrb%2
        else:            
            if x[0]=="Qb":
                if (acntr-1)%2!=0:
                    ctra=ctra/2+ctra%2
                else:
                    ctra=ctra/2
                if (bcntr-1)%2!=0:
                    ctrb=ctrb/2+ctrb%2
                else:
                    ctrb=ctrb/2
            else:
                if (acntr-1)%2!=0:
                    ctra=ctra/2
                else:
                    ctra=ctra/2+ctra%2
                if (bcntr-1)%2!=0:
                    ctrb=ctrb/2
                else:
                    ctrb=ctrb/2+ctrb%2
        #print ht
        ht=ht%2
        if (cnt==0 and ht==0 and x[0]=="Qb") or (cnt==0 and ht==1 and x[0]=="Qr") or (cnt==1 and ht==1 and x[0]=="Qb") or (cnt==1 and ht==0 and x[0]=="Qr"):
            print ctra+ctrb-1
        else:
            print ctra+ctrb
    i=i+1
        

            
        
