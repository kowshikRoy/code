import itertools as it
n = 8
perm= [i for i in range(n)]

def is_solution(p):
    for i in range(n):
        for j in range(i + 1, n):
            if abs(i-j) == abs(p[i] - p[j]):
                return False
    return True


cnt = 0
for p in it.permutations(perm):
    if is_solution(p):
        print(p)
        cnt += 1

print(cnt)
