def f(x):
    ret = 0
    while x > 0:
        ret *= 10
        ret += 1
        x -= 1
    return ret


a = int(input())
for i in range(1, 100) :
    k = f(i)
    # print(i, end=' ')
    # print(k)
    if k % a == 0 :
        print(int(k / a), end= ' ')
        print(i)
        break