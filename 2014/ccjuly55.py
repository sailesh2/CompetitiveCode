t=input()
i=0
while i<t:
    n=input()
    x=raw_input().split(' ')
    lt=[[]]
    dish=[0]
    arr=[0]
    s=[0]
    j=0
    while j<n:
        s.append(int(x[j]))
        dish.append(j+1)
        lt.append([j+1])
        arr.append(j+1)
        j=j+1
    q=input()
    j=0
    while j<q:
        x=raw_input().split(' ')
        c=int(x[0])
        if c==0:
            a=int(x[1])
            b=int(x[2])
            if arr[dish[a]]==arr[dish[b]]:
                print "Invalid query!"
            else:
                if s[a]>=s[b]:
                    if len(lt[dish[b]])<=len(lt[dish[a]]):
                        k=dish[b]
                        while len(lt[k])!=0:
                            popped=lt[k].pop()
        #                    print "1popped"
                            dish[popped]=dish[a]
                            lt[dish[a]].append(popped)
                    else:
                        save=arr[dish[a]]
                        k=dish[a]
                        while len(lt[k])!=0:
                            popped=lt[k].pop()
         #                   print "2popped"
                            dish[popped]=dish[b]
                            lt[dish[b]].append(popped)
                        arr[dish[b]]=save
                else:
                    if len(lt[dish[a]])<=len(lt[dish[b]]):
                        k=dish[a]
                        while len(lt[k])!=0:
                            popped=lt[k].pop()
           #                 print "3popped"
                            dish[popped]=dish[b]
                            lt[dish[b]].append(popped)
                    else:
                        save=arr[dish[b]]
                        k=dish[b]
                        while len(lt[k])!=0:
                            popped=lt[k].pop()
            #                print "4popped"+str(popped)
                            dish[popped]=dish[a]
                            lt[dish[a]].append(popped)
                        arr[dish[a]]=save
        else:
            a=int(x[1])
            print arr[dish[a]]
        j=j+1
    i=i+1
            
