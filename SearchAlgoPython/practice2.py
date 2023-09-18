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