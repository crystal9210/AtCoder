s = input()
t = s[::-1]
n = len(s)
ans = 1
for l in range(n):
    for r in range(l+1, n+1):
        if s[l:r] in t:
          # print(s[l:r+1])
          ans = max(ans, len(s[l:r]))
            
print(ans)
