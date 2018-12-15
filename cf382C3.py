def fun(n):
    if n==1:
        return 0
    if n==2:
        return 1
    if n==3:
        return 2
    if n==4:
        return 2
    if n==5:
        return 3
    return fun(n/2) +1

n=int(raw_input())
print fun(n)
