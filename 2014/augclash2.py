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
        div=int(math.pow(10,h))
        fir=div
        las=int(math.pow(6,h))
        while temp!=0:
            if div==0:
                break
            dig=(temp/div)
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
                    s=s+1+temp%div
                    break
            fir=fir/10
            las=las/6
            temp=temp%div
            div=div/10
        print s
    i=i+1
