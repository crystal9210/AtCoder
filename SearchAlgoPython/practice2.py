# N個の正の整数A1,A2,...,ANを入力から受け取る。このとき、この中からいくつか整数を選んで、選んだ数を足し合わせた合計がWになる選び方が何通りあるか出力せよ
# 参照：https://qiita.com/u2dayo/items/8c1601a61841540b4947#%E9%83%A8%E5%88%86%E5%92%8C%E5%95%8F%E9%A1%8C
from itertools import product 

def judge(pro):
  S=0
  for i in range(N):
    if pro[i]:
      S+=A[i]
      
  if S==W:
    return 1
  else:
    return 0
  
  
N,W=map(int,input().split())
A=list(map(int,input().split()))

ans=0
for pro in product((0,1),repeat=N):
  ans+=judge(pro)
  
print(ans)
# add:product関数の返り値：イテレータ、このイテレータは入力されたイテラブルの要素の直積からなるタプルを順番に返す。→上記の例のようにfor文内で使うのが効果的。複数のイテラブルからなる全ての組み合わせを効率的に生成するのに使う。
# 第一引数：イテラブルを渡す。repeatオプション：生成するイテラブルの要素数の指定、
# イテラブル：その要素を1つずつ返すことができるオブジェクト。例として、以下の通り。
# リスト (list)
# 例：[1, 2, 3, 4, 5]

# タプル (tuple)
# 例：(1, 2, 3, 4, 5)

# 文字列 (string)
# 例："hello"

# 辞書 (dictionary)
# ただし、辞書を直接イテレートする場合、キーが返されます。
# 例：{'a': 1, 'b': 2, 'c': 3}

# 集合 (set)
# 例：{1, 2, 3, 4, 5}

# ファイルオブジェクト
# 例：file = open("sample.txt", "r")

# ジェネレータ (generator)
# 例：(x for x in range(5))