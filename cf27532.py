import math
x=raw_input().split(' ')

cnt1=int(x[0])
cnt2=int(x[1])
a=int(x[2])
b=int(x[3])
cnt1s=cnt1
cnt2s=cnt2

if a==b:
    ans=int(math.floor(a*float(cnt1+cnt2)/(a-1)))
    if ans%a==0:
        ans=ans-1
    
    print ans
else:
    ans=int(math.floor(a*float(cnt1)/(a-1)))
    if ans%a==0:
        ans=ans-1
    if cnt2*a<=ans:
        mini=ans
    else:
        cnt2=cnt2-int(math.floor(float(ans)/a))
        save=ans
        save2=save
 #       print save,cnt2
        g=b*int(math.floor(float(ans)/b))
  #      print g
        ctr=1
        over=0
        while 1:
            save=save2
            while 1:
                f=b*int(math.floor(float(save+ctr)/b))
                if (save+ctr-ans)-((f-g)/b)>cnt2:
                    ctr=1
                    break
                save2=save+ctr
                ctr=ctr*2
            if save==save2:
                break
        mini=save
   #     print mini

    ans3=int(math.floor(b*float(cnt2s)/(b-1)))
    if ans3%b==0:
        ans3=ans3-1
    if cnt1s*b<=ans3:
        mini2=ans3
    else:
        cnt1s=cnt1s-int(math.floor(float(ans3)/b))
        save=ans3
        save2=save
#        print cnt1,save
        g=a*int(math.floor(float(ans3)/a))
        ctr=1
        while 1:
            save=save2
            while 1:
                f=a*int(math.floor(float(save+ctr)/a))
                if (save+ctr-ans3)-((f-g)/a)>cnt1s:
                    ctr=1
                    break
                save2=save+ctr
                ctr=ctr*2
            if save==save2:
                break
        mini2=save
        
#    print mini,mini2
    print min(mini,mini2)

