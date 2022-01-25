A = [
    [5, 6, 8, 0],
    [3, 5, 0, 1],
    [4, 4, 1, 1],
    [9, 9, 8, 8]
]
dp = [
    [5, 10000, 10000, 10000],
    [10000, 10000, 10000, 10000],
    [10000, 10000, 10000, 10000],
    [10000, 10000, 10000, 10000],
]
for i in range(0,len(A)):
    for j in range(0,len(A)):
        if i-1>=0:
            x = 10000
            for ll in range(0,i):
                x=min(x,dp[ll][j])
            dp[i][j]=min(x+A[i][j],dp[i][j])
        if j-1>=0:
            x = 10000
            for ll in range(0, j):
                x = min(x, dp[i][ll])
            dp[i][j]=min(x+A[i][j],dp[i][j])
for i in dp:
    print(i)