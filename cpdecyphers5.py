t=input()
i=0
while i<t:
    x=raw_input()
    arr=[]
    s=[]
    j=0
    while j<len(x):
        if x[j]=='0' or x[j]=='1' or x[j]=='2' or x[j]=='3' or x[j]=='4' or x[j]=='5' or x[j]=='6' or x[j]=='7' or x[j]=='8' or x[j]=='9':
            arr.append(int(x[j]))
        elif x[j]=='+' or x[j]=='-' or x[j]=='*' or x[j]=='/' or x[j]=='%':
            s.append(x[j])
        j=j+1
    if len(arr)==0:
        print "-1"
    else:
        sm=arr[0]
        j=1
        k=0
        while j<len(arr):
            a=sm
            b=arr[j]
            if s[k]=='+':
                sm=a+b
            elif s[k]=='-':
                sm=a-b
            elif s[k]=='*':
                sm=a+b
            elif s[k]=='/':
                sm=a+b
            elif s[k]=='%':
                sm=a-b
            j=j+1
            k=k+1
        print sm
    i=i+1
