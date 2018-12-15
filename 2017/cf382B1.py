x=raw_input().split(' ')
tw=int(x[0])
th=int(x[1])
f=int(x[2])
s=int(x[3])

mint = min(tw,min(f,s))

tw=tw-mint
f=f-mint
s=s-mint

sm=mint*256

print min(tw,th)*32 +sm
