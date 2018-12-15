fon=open('C:/Users/srt/Desktop/srsResult.log','r')
l=fon.readlines()
fout=open('C:/Users/srt/Desktop/srsOUT.txt','w')
i=0
success=[0]*5200
while i<len(l):
    x=l[i].split(' ')
    if len(x)>=2 and x[0]==str('rntiSuccess'):
#       fout.write(str(x[3])+"\n")
        v=str(x[1])
        a=v.index('\n')
        success[int(v[0:a])]=1        
    i=i+1
cnt=[0]*5200
distinct=[]
lt=[]
lt1=[]
i=0
while i<len(l):
    x=l[i].split(' ')
    if len(x)>=4 and x[0]==str('Time'):
        if cnt[int(x[1])]==0:
            cnt[int(x[1])]=1
            distinct.append(int(x[1]))
            v=str(x[3])
            a=v.index('\n')
            num=int(v[0:a])
            lt.append([num])
            lt1.append([])
            if success[num]==1:
                lt1[len(distinct)-1].append(num)
        else:
            v=str(x[3])
            a=v.index('\n')
            num=int(v[0:a])
            lt[len(distinct)-1].append(num)
            if success[num]==1:
                lt1[len(distinct)-1].append(num)
    i=i+1
i=0
tot3rdmsg=0
totsched=0
while i<len(distinct):
    fout.write("TIME    "+str(distinct[i])+":\n")
    fout.write("                       3rd Message Success :"+str(len(lt[i]))+"\n")
    j=0
    fout.write("                       ")
    while j<len(lt[i]):
        fout.write(str(lt[i][j])+" ")
        j=j+1
    fout.write("\n")
    fout.write("                       Scheduling Success :"+str(len(lt1[i]))+"\n")
    j=0
    fout.write("                       ")
    while j<len(lt1[i]):
        fout.write(str(lt1[i][j])+" ")
        j=j+1
    fout.write("\n")
    tot3rdmsg=tot3rdmsg+len(lt[i])
    fout.write("                       Total 3rd Message Success: "+str(tot3rdmsg)+"\n")
    totsched=totsched+len(lt1[i])
    fout.write("                       Total Scheduling Success: "+str(totsched)+"\n")
    i=i+1
fon.close()
fout.close()
