def findChar(ind,first,last,k):
    first2=first+init
    first2E=first2+pow(2,ind-1)-1
    last2=last-lastinit
    last2S=last2-pow(2,ind-1)+1
    if k<first2:
        i=0;
        while i<init:
            if i==k-first:
                break
            i=i+1
        return fir[i]
    elif k>last2:
        i=0
        while i<lastinit:
            if i==k-last2-1:
                break
            i=i+1
        return las[i]
    elif k>first2E and k<last2S:
        i=0
        while i<midinit:
            if i==k-first2E-1:
                break
            i=i+1
        return mid[i]
    else:
        if k>=first2S and k<=first2E:
            findChar(ind-1,first2S,first2E,k)
        else:
            findChar(ind-1,last2S,last2E,k)
            
t=int(raw_input())
i=0
while(i<t):
    x=raw_input().split(' ')
    n=int(x[0])
    k=int(x[1])
    
    i=i+1
    
