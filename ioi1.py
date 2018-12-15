x=raw_input().split(' ')
n=int(x[0])
p=int(x[1])
rows=0
rowar=[0]*6001
cols=0
colar=[0]*6001
s=0
i=0
arr=[]
while i<p:
    y=raw_input().split(' ')
    if y[0]=="ROW":
        arr.append([1,int(y[1]),int(y[2])])
        rowar[int(y[1])]=i
    else:
        arr.append([0,int(y[1]),int(y[2])])
        colar[int(y[1])]=i
    i=i+1
i=0
while i<p:
    if arr[i][0]==1:
        if rowar[arr[i][1]]==i:
            s=s+n*arr[i][2]-cols
            rows=rows+arr[i][2]
    else:
        if colar[arr[i][1]]==i:
            s=s+n*arr[i][2]-rows
            cols=cols+arr[i][2]
    i=i+1
print s
