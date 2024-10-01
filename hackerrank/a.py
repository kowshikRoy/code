from math import log10, floor
t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    mod = 10**k;
    m = 2**(n-1) % mod
    f = (n-1) * log10(2)
    f = f - floor(f)
    f = 10 ** f
    while f * 10 < mod:
        f *= 10
    f = int(f)
    print(m + f)


