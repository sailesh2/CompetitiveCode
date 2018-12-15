t=input()
i=0
while i<t:
    n=input()
    j=0
    arr=[]
    x=raw_input().split(' ')
    while j<n:
        arr.append(int(x[j]))
        if j==0:
            mini=arr[j]
        else:
            mini=mini & arr[j]
        j=j+1
    print mini
    i=i+1
                   
