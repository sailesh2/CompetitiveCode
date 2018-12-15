x=raw_input().split(' ')
m1=int(x[0])
m2=int(x[1])
m3=int(x[2])
m4=int(x[3])
m5=int(x[4])

y=raw_input().split(' ')
w1=int(y[0])
w2=int(y[1])
w3=int(y[2])
w4=int(y[3])
w5=int(y[4])

z=raw_input().split(' ')
hs=int(z[0])
hw=int(z[1])

maxi1=500
maxi2=1000
maxi3=1500
maxi4=2000
maxi5=2500

s=0
s=s+max(0.3*maxi1,(((250-m1)*maxi1)/250)-50*w1)
s=s+max(0.3*maxi2,(((250-m2)*maxi2)/250)-50*w2)
s=s+max(0.3*maxi3,(((250-m3)*maxi3)/250)-50*w3)
s=s+max(0.3*maxi4,(((250-m4)*maxi4)/250)-50*w4)
s=s+max(0.3*maxi5,(((250-m5)*maxi5)/250)-50*w5)

s=s+100*hs-50*hw
print int(s)
