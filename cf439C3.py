def cal(n,m,dp):
    mod=998244353
    if n<=0 or m<=0:
        return 1
    s=0
    if dp[n-1][m]>0:
        s=s+dp[n-1][m]
    else:
        s=s+cal(n-1,m,dp)
        
    if dp[n-1][m-1]>0:
        s=s+m*dp[n-1][m-1]
    else:
        s=s+m*cal(n-1,m-1,dp)
    s=s%mod
    dp[n][m]=s
    
    return s


x=raw_input().split(' ')
a=int(x[0])
b=int(x[1])
c=int(x[2])
dp=[[0]*5001]*5001
sab=cal(a,b,dp)

dp=[[0]*5001]*5001
sac=cal(a,c,dp)

dp=[[0]*5001]*5001
sbc=cal(b,c,dp)
mod=998244353
print (((sab*sac)%mod)*sbc)%mod
