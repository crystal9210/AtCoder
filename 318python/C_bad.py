import itertools

# 関数: 最初の2つの数字が同じで3つ目が異なる場合の確率を求める。
def disappointment_prob(line):
    total_perms = list(itertools.permutations(line))
    disappointing_perms = [p for p in total_perms if p[0] == p[1] and p[1] != p[2]]
    return len(disappointing_perms) / len(total_perms)

matrix = [list(map(int, input().split())) for _ in range(3)]

lines = [
    [matrix[i][j] for j in range(3)] for i in range(3)
] + [
    [matrix[j][i] for j in range(3)] for i in range(3)
] + [
    [matrix[i][i] for i in range(3)],
    [matrix[i][2 - i] for i in range(3)]
]

probabilities = [disappointment_prob(line) for line in lines]
print(probabilities)

# 縦、横、斜めでそれぞれのがっかりする確率を計算
A = (1-probabilities[0])*(1-probabilities[1])*(1-probabilities[2])
B = (1-probabilities[3])*(1-probabilities[4])*(1-probabilities[5])
C = 1-probabilities[6]
D = 1-probabilities[7]

# print(f"Vertical disappointment probability (A): {A:.12f}")
# print(f"Horizontal disappointment probability (B): {B:.12f}")
# print(f"Diagonal disappointment probability (C): {C:.12f}")

ans = A*B*C*D
# ans=1-(1-A)*(1-B)*(1-C)*(1-D) ：×
print(ans)
