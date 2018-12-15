t=input()

i=0
while i<t:
    
    ctr=0
    store_st=[]
    store_en=[]
    starts=raw_input()
    ends=raw_input()
    text=raw_input()
    j=0
    while j<len(text):
        cnt=0
        k=0
        while k<len(starts):
            
            if (j+k>=len(text)):
                cnt=1;
                break;
            if text[j+k]!=starts[k]:
                cnt=1;
                break;
            k=k+1
        if (cnt==0):
            save=j;
            j=j+len(starts)
                
            while j<len(text):
                cnt2=0;
                k=0
                while k<len(ends):
                    if (j+k>=len(text)):
                        cnt2=1;
                        break;
                    if (text[j+k]!=ends[k]):
                        cnt2=1;
                        break;
                    k=k+1
                if (cnt2==0):
                    j=j+len(ends)-1;
                    store_st.append(save)
                    store_en.append(j)
                    ctr=ctr+1
                    break;
                j=j+1
            
        j=j+1
    k=0;
    j=0
    st=""
    while j<len(text):
        if (k<ctr and j==store_st[k]):
            j=store_en[k];
            k=k+1
        else:
            st=st+str(text[j])
        j=j+1
    print st
    i=i+1
