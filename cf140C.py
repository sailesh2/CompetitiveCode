n=input()
x=raw_input().split(' ')
i=0
arr=[]
while i<n:
    arr.append(int(x[i]))
    i=i+1
arr.sort()
arr.reverse()
i=0
brr=[]
k=0
while i<len(arr):
    if i>0:
        if arr[i]==arr[i-1]:
            brr[k][1]=brr[k][1]+1
        else:
            k=k+1
            brr.append([arr[i],1])
    else:
        brr.append([arr[0],1])
    i=i+1
ans=[]
l=0
while 1:
    cnt=0
    i=0
    ctr=0
    while i<=k:
        if brr[i][1]>0:
            if ctr==0:
                save1=i
            elif ctr==1:
                save2=i
            else:
                save3=i
            ctr=ctr+1
            if ctr==3:
                ctr=0
                cnt=1
                ans.append([brr[save1][0],brr[save2][0],brr[save3][0]])
                brr[save1][1]=brr[save1][1]-1
                brr[save2][1]=brr[save2][1]-1
                brr[save3][1]=brr[save3][1]-1
                l=l+1
        i=i+1
    if cnt==0:
        break
print l
i=0
while i<l:
    print ans[i][0],ans[i][1],ans[i][2]
    i=i+1
