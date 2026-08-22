N = 105

s = [[0] * N for _ in range(N)]
s[0][0] = 1

for i in range(1,N):
    for j in range(1, i + 1):
        s[i][j] = (j * s[i - 1][j] + s[i - 1][j - 1])

while True:
    try:
        n, m = map(int, input().split())
        if n<m:print(0)
        else: print(s[n][m])
    except EOFError:
        break