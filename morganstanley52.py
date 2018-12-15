global dp


def ways(N):
    total_ways = 0
    if (N == 1):
        return 1
    i=1
    while i<=N:
        
        if (i == 1 or i == N):
            total_ways = total_ways + ways(N - 1)
            total_ways = total_ways + 2
        else:
            total_ways = total_ways + ways(i - 1)
            total_ways = total_ways + ways(N - i)
            total_ways = total_ways + 1
        i=i+1
    return total_ways
dp=[-1]*1000000

a=ways(3)
print a
t=input()
i=0
while i<t:
    n=input()
    print dp[n-1]
    i=i+1
