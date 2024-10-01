def find_digit(i):
    n = 1
    while True:
        k = n * (n + 1) // 2
        if i <= k:
            break
        i -= k
        n += 1
    i -= 1
    return (n + (i // n)) % 10

t = int(input())
for _ in range(t):
    n = int(input())
    print(find_digit(n))
