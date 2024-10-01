class Solution:
    def maximumXorProduct(self, a: int, b: int, n: int) -> int:
        na, nb = a,b
        MOD = 10**9+7
        for i in reversed(range(n)):
            if (a & (1 << i)) == (b & (1 << i)):
                na |= 1 << i
                nb |= 1 << i
            else:
                if na <= nb:
                    na |= 1 << i
                    nb &= ~(1 << i)
                else:
                    nb |= 1 << i
                    na &= ~(1 << i)
        return (na * nb) % MOD
    
    def maximumXorProduct_another(self, a: int, b: int, n: int) -> int:
        for bt in (1 << i for i in range(n)):
            if a * b < (a ^ bt) * (b ^ bt):
                a ^= bt 
                b ^= bt
        return (a * b) % 1000000007
