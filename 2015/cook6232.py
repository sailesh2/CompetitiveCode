import math
t=input()
i=0
while i<t:
    
    
    x=raw_input().split(' ')
    a=int(x[0])
    r=int(x[1])

    val=math.log(a,2)
    valu=math.log(r,2)

    ctr=0
    if val==int(val):
        ctr=ctr+int(valu)-int(val)+1
    else:
        ctr=ctr+int(valu)-int(val)
    #print ctr
    
    #print a1,r1

    #print a,r
    j=6
    while j<=r:
        val6=j
        if j==0:
            a2=0
            r2=0
        else:
            a2=int(math.ceil(float(a)/val6))
            r2=int(math.floor(float(r)/val6))
        
        if a2<=r2:
            #if a2<1 and r2>=1:
             #   ctr=ctr+1
            
            if a2==0:
                val=0
            else:
                val=math.log(a2,2)
            if r2==0:
                valu=0
            else:
                valu=math.log(r2,2)

            #if a2!=0:
            if val==int(val):
                ctr=ctr+int(valu)-int(val)+1
            else:
                ctr=ctr+int(valu)-int(val)
            #else:
             #   ctr=ctr+int(valu)-int(val)
            #print ctr
            if a2==0:
                val=0
            else:
                val=math.log(a2,3)
            if r2==0:
                valu=0
            else:
                valu=math.log(r2,3)

            
            #if a2!=0:
            if val==int(val):
                if val!=0:
                    ctr=ctr+int(valu)-int(val)+1
                else:
                    ctr=ctr+int(valu)-int(val)
            else:
                ctr=ctr+int(valu)-int(val)
            #else:
             #   ctr=ctr+int(valu)-int(val)
        #print ctr
        j=j*6
    print ctr
    i=i+1
