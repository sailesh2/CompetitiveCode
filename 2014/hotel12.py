n=input()
j=0
while j<n:
    x=raw_input().split(' ')
    sm=0
    i=0
    lt=len(x)
    while i<lt:
        
        if int(x[i])==10:
            sm=sm+10
            if i+2<lt:
                sm=sm+int(x[i+1])+int(x[i+2])
            i=i+1
        elif int(x[i])+int(x[i+1])==10:
            sm=sm+10
            if i+2<lt:
                sm=sm+int(x[i+2])
            i=i+2
        else:
            sm=sm+int(x[i])+int(x[i+1])
            i=i+2
    print sm
    j=j+1
    
