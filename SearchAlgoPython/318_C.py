N=int(input())

matrix=[list(map(int,input().split())) for _ in range(N)]

print(matrix)
print(matrix[0])
print(matrix[0][0])


# 2次元リストを1次元リストに変換
flattened_list=[item for sublist in matrix for item in sublist]

print("2D matrix:",matrix)
print("2D matrix:")
for row in matrix:
  print(' '.join(map(str,row)))
print("1D flattened list:",flattened_list)

