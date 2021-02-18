from random import randint
from random import sample

if __name__ == '__main__':
    t = 60
    M = 10
    print(t)
    for _ in range(t):
        n, m = randint(1,M), randint(1,M)
        print(n,m)
        print(*[ randint(1,10) for _ in range(m)])
        for _ in range(n):
            k = randint(0,min(m+1,5))
            print(k, *sample(range(1,m+1), k))
        



        

