global dp


def ways(N):
    total_ways = 0
#    print N
    if N==1:
        return 1

    i=1
    while i<=N:
        if (i == 1 or i == N):
            if dp[N-1]==-1:
                total_ways = total_ways + ways(N - 1)
            else:
                total_ways = total_ways + dp[N-1]
            total_ways = total_ways + 2
        else:
            if dp[i-1]==-1:
                total_ways = total_ways + ways(i - 1)
            else:
                total_ways = total_ways + dp[i - 1]
            if dp[N-i]==-1:
                total_ways = total_ways + ways(N - i)
            else:
                total_ways = total_ways + dp[N - i]
            total_ways = total_ways + 1
        i=i+1
    dp[N]=total_ways
    return total_ways
dp=[-1]*1000000
dp[1]=1
ways(10001)
t=input()
i=0
while i<t:
    n=input()
    print dp[n]-pow(2,n-1)
    i=i+1
