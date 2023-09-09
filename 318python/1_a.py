# O(n)
n, m, p = map(int, input().split())
res = 0
while m <= n:
    res += 1
    m += p
print(res)
