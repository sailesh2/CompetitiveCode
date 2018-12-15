import math
x=raw_input().split(' ')

cnt1=int(x[0])
cnt2=int(x[1])
cnt1s=cnt1
cnt2s=cnt2
a=int(x[2])
b=int(x[3])

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
        if ans%b!=0:
            t=b*int(math.ceil(float(ans)/b))
            tr=t-ans-1
            if tr>cnt2:
                ans2=ans+int(math.floor(b*float(cnt2)/(b-1)))
                if ans2%b==0:
                    ans2=ans2-1
            else:
                cnt2=cnt2-tr
                ans2=t+int(math.floor(b*float(cnt2)/(b-1)))
                if ans2%b==0:
                    ans2=ans2-1
        else:
            ans2=ans+int(math.floor(b*float(cnt2)/(b-1)))
            if ans2%b==0:
                ans2=ans2-1
        mini=ans2


    ans3=int(math.floor(b*float(cnt2s)/(b-1)))
    if ans3%b==0:
        ans3=ans3-1
    if cnt1s*b<=ans3:
        mini2=ans3
    else:
        cnt1s=cnt1s-int(math.floor(float(ans3)/b))
        if ans3%a!=0:
            t=a*int(math.ceil(float(ans3)/a))
            tr=t-ans3-1
            if tr>cnt1:
                ans4=ans3+int(math.floor(a*float(cnt1s)/(a-1)))
                if ans4%a==0:
                    ans4=ans4-1
            else:
                cnt1s=cnt1s-tr
                ans4=t+int(math.floor(a*float(cnt1s)/(a-1)))
                if ans4%a==0:
                    ans4=ans4-1
        else:
            ans4=ans3+int(math.floor(a*float(cnt1s)/(a-1)))
            if ans4%a==0:
                ans4=ans4-1
        mini2=ans4
#    print mini,mini2
    print min(mini,mini2)

