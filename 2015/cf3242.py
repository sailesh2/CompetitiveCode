n=input()
if n==1:
    print "20"
else:
    p7=1
    p27=[]
    i=0
    power27=1
    while i<n:
        p27.append(power27)
        power27=(power27*27)%1000000007
        
        i=i+1
    #print p27
    i=0
    sm=0
    while i<n:
      #  print p7,p27[n-i-1]
        sm=sm+(p7*p27[n-i-1])%1000000007
        sm=sm%1000000007
        p7=(p7*7)%1000000007
        i=i+1
    print (sm*20)%1000000007
    
