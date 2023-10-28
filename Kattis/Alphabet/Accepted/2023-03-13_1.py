s = input()
n = len(s)

dp = [1] * n

for i in range(1, n):
    for j in range(i):
        if s[j] < s[i]:
            dp[i] = max(dp[i], dp[j] + 1)

print(26 - max(dp))