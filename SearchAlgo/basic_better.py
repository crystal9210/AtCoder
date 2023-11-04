#bit全探索の基本コード(itertools モジュール)
from itertools import product

n=int(input().strip())

for pro in product((0,1),repeat=n):
  print(pro)