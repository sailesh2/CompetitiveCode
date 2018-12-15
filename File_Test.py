fon=open('C:/Users/srt/Desktop/20480.log','r')
l=fon.readlines()
fout=open('C:/Users/srt/Desktop/20480RES.txt','w')
i=0
sm=0.0
while i<len(l):
    x=l[i].split(' ')
    if x[0]==str('Flow'):
        fout.write(str(x[0])+" "+str(x[1])+":  ")
    if len(x)>=3 and x[2]==str('Throughput:'):
        fout.write(str(x[3])+"\n")
        v=str(x[3])
        a=v.index('Mbps')
        sm=sm+float(v[0:a])
    i=i+1
fout.write('TOTAL__THROUGHPUT  --  '+str(sm)+'Mbps')
fon.close()
fout.close()
