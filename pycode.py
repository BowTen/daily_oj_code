n = int(input())
ans = 0
while n != 0 :
    n //= 6
    ans += 1
if ans == 0 : 
    ans = 1
print(ans)