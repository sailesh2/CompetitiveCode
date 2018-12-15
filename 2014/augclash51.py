import math
t=input()
i=0
while i<t:
    n=input()
    if n==0:
        print n
    else:
        temp=n
        s=0
        h=int(math.floor(math.log10(n)))
        j=0
        arr=[0]*(h+1)
        while temp!=0:
            arr[h-j]=temp%10
            temp=temp/10
            j=j+1
        temp=n
        div=int(math.pow(10,h))
        fir=div
        las=int(math.pow(6,h))
        j=0
        while j<h+1:
            dig=arr[j]
            if dig>0:
                tmpsum=fir-las
                k=1
                while k<dig:
                    if k==2 or k==3 or k==5 or k==7:
                        tmpsum=tmpsum+fir
                    else:
                        tmpsum=tmpsum+fir-las
                    k=k+1
                s=s+tmpsum
                if k==2 or k==3 or k==5 or k==7:
                    s=s+1+n%(int(math.pow(10,h-j)))
                    break
            fir=fir/10
            las=las/6
            j=j+1
        print s
    i=i+1
