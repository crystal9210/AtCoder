s = input()
t = s[::-1]

s = "#" + s
t = "#" + t

ans = 0

dp = [0] * len(t)
for i in range(1, len(s)):
  for j in reversed(range(len(t))):
    if s[i] == t[j]:
      dp[j] = dp[j-1] + 1
      ans = max(ans, dp[j])
    else:
      dp[j] = 0
print(ans)