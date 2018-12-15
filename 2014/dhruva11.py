t=input()
j=0
while j<t:
      sm=0;
      cnt=0;
      n=input()
      arr=[]
      x=raw_input().split(' ')
      i=0
      while i<n:
          arr.append(int(x[i]))
          i=i+1
      i=0
      while i<n-1:
          if cnt==0:
              if arr[i+1]<arr[i]:
                  cnt=1
                  save=i
                  saveval=arr[i]
          elif cnt==1:
              if arr[i+1]>arr[i]:
                  maxi=0
                  while i<n:
                      if arr[i]>saveval:
                          saved=i
                          maxi=saveval
                          break
                      if arr[i]>=maxi:
                          maxi=arr[i]
                          saved=i
                      i=i+1
                  k=save
                  while k<=saved:
                      if maxi-arr[k]>=0:
                          sm=sm+maxi-arr[k]
                      k=k+1
                  cnt=0
                  i=i-1
          i=i+1
      print sm%1000000007
      j=j+1

