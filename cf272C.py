x=raw_input().split(' ')
a=int(x[0])
b=int(x[1])
m=4*1000000007
print (( ((  ((a*b)%m)*(b-1)  )%m) * (  ((a*b)%m) +b+2  ) )%m)/4
