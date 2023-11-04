# bit全探索
# n人それぞれが「yes」「no」どちらかの全パターン
# yes=1,no=0
n = int(input().strip())
patterns = []

for i in range(2**n):
    p = [0] * n
    for j in range(n):
        if i >> j & 1:
            p[j] = 1
    patterns.append(p)

print(patterns)
