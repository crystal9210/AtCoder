# N人に犬派、猫派どちらであるかを聞いた。
# 犬派なら1、猫派なら2のボタンを押してもらった。
# 西郷くんはどうやら大の犬好きらしい。そのため、
# i(1<=i<=n)番目の人が犬派ならi点貰えるらしい。
# 合計M点になる場合は何通りあるか？
# 参照：https://qiita.com/oyutaka_jp/items/822cafd0f8e6f1c59999
from itertools import product


def main(pro):
    sum = 0
    for i in range(N):
        if pro[i] == 1:  # タプルの要素p[i]を走査
            sum += i + 1

    if sum == M:
        return 1
    else:
        return 0


N, M = list(map(int, input().strip().split()))

ans = 0
for pro in product((0, 1), repeat=N):
    ans += main(pro)
    print(pro)

print(ans)
