
global alarms

def read(idx):
    
    global alarms
    sum = 0;
    while (idx > 0):
        sum += alarms[idx];
        idx -= (idx & -idx);
    
    return sum;
def update(idx ,val,MaxVal):
    global alarms
    while (idx <= MaxVal):
        alarms[idx] += val;
        idx += (idx & -idx);
    

x=raw_input().split(' ')
n=int(x[0])
m=int(x[1])
k=int(x[2])
alarms=[0]*1000002

y=raw_input().split(' ')
i=0
arr=[]
while i<n:
    update(int(y[i]),1,1000000)
    arr.append(int(y[i]))
    i=i+1

i=0
arr.sort()
off=0
while i<n:
    st=arr[i]
    en=st+m-1
    if en>1000000:
        break
    d=read(en)-read(st-1)
    if d>=k:
        off=off+(d-k)+1
    update(en-off+1,-off,1000000)
    i=i+1
print off
