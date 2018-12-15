n=input()
st=[]
xarr=[]
yarr=[]
i=0
while i<n:
    z=raw_input().split(' ')
    x=int(z[0])
    y=int(z[1])
    xarr.append(x)
    yarr.append(y)
    st.append([x,y])
if n<=2:
    print 4-n
else:
    mini=100
    i=0
    while i<n:
        x1=xarr[i]
        y1=yarr[i]
        j=i+1
        while j<n:
            ctr=0
            x2=xarr[j]
            y2=yarr[j]

            ln=float((sqrt(abs(x2-x1)*abs(x2-x1)+abs(y2-y1)*abs(y2-y1))))
            if x1==x2:
                slope=0
            elif y1==y2:
                slope=100000000
            else:
                slope=-1*(float((x1-x2))/(y1-y2));
            m=slope
            if m==100000000:
                a=x1
                b=y1+ln
            else:
                a=x1+ln*(float(1)/(sqrt(1+m*m)))
                b=y1+ln*(float(m)/(sqrt(1+m*m)))
            if a==int(a) and b==int(b):
                if [a,b] in st:
                    ctr=ctr+1
            if m==100000000:
                a=x2
                b=y2+ln
            else:
                a=x2+ln*(float(1)/(sqrt(1+m*m)))
                b=y2+ln*(float(m)/(sqrt(1+m*m)))
            if a==int(a) and b==int(b):
                if [a,b] in st:
                    ctr=ctr+1
            if 2-ctr<=mini:
                mini=2-ctr
    print mini;
