def solve():
    perfect_nums = {6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128, 2658455991569831744654692615953842176, 191561942608236107294793378084303638130997321548169216}
    n = int(input())
    
    if n in perfect_nums:
        print(f"YES, {n} is a perfect number!")
    else:
        print(f"NO, {n} is not a perfect number!")


T = int(input())
for _ in range(T):
    solve()
