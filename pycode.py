n, m = map(int, input().split())

ans = 0

pw = [0] * (m + 1)
pw[1] = 2
for i in range(2, m + 1) :
    pw[i] = pw[i-1] * 2

for i in range(n) :
    a = input().split()
    for j in range(m) :
        a[j] = int(a[j])

    f = [[0] * m] * m
    for j in range(m) :
        for k in range(m-1, j-1, -1) :
            id = j + (m-k-1)
            if id == 0 : continue
            if j == 0 : 
                f[j][k] = f[j][k+1] + a[k+1] * pw[id]
            elif k == m-1 : f[j][k] = f[j-1][k] + a[j-1] * pw[id]
            else : f[j][k] = max(f[j-1][k] + a[j-1]*pw[id], f[j][k+1] + a[k+1]*pw[id])

    mx = 0
    for j in range(m) :
        mx = max(mx, f[j][j] + a[j] * pw[m])
    
    ans += mx

print(ans)