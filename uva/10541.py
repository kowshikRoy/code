t = int(input())
for _ in range(t):
    n, _, *arr = input().split()
    arr = list(map(int, arr))
    n = int(n)

    if len(arr) == 0:
        print(1)
        continue

    m = len(arr)
    dp = [0] * (n + 1)
    for i in range(arr[0], n + 1):
        dp[i] = 1
    for i in range(1, m):
        pdp = [0] * (n + 1)
        for j in range(n + 1):
            if j > 0:
                pdp[j] = pdp[j - 1]
            pdp[j] += dp[j]
            dp[j] = 0

        for j in range(arr[i] + 1, n + 1):
            dp[j] = pdp[j - arr[i] - 1]

    ans = 0
    for i in range(n + 1):
        ans += dp[i]
    print(ans)
