n=raw_input()
if n[0]=='1' or n[0]=='2' or n[0]=='3' or n[0]=='4':
    if len(n)==1:
        print "0"
    else:
        print (int(n[0]))*4+(int(n[1])+1)
else:
    if n[0]!='9':
        print int(n[0])-4
    else:
        if len(n)==1:
            print "4"
        else:
            print "5"
