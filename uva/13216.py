t = int(input())

for _ in range(t):
    n = int(input())
    if n == 0:
        print(1)
    elif n == 1:
        print(66)
    else:
        v = [56, 96, 36, 76, 16]
        print(v[(n - 2) % 5])
