map="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

x, y, z = input().split()

x = int(x)
y = int(y)

s = 0
for c in z :
	s *= x
	s += map.find(c)


ans = ""
f = 0
if(s == 0) :
	f = 1
while(s > 0) :
	m = int(s%y)
	ans += map[m]
	s //= y

ans = ans[::-1]
if(f == 1) :
	ans = "0"
print(ans)