MOD_VAL = 10 ** 9 + 7
validMoves = {
    1: [6, 8],
    2: [7, 9],
    3: [4, 8],
    4: [0, 3, 9],
    5: [],
    6: [7, 0, 1],
    7: [2, 6],
    8: [1, 3],
    9: [2, 4],
    0: [4, 6],
}

class Solution:            
    def knightDialer(self, n: int) -> int:
        cache = {}
        def backtrack(n, cur):
            if n == 0:
                return 1
            
            if (n, cur) in cache:
                return cache[(n, cur)]
            
            ways = 0
            for nextOption in validMoves[cur]:
                ways = (ways + backtrack(n - 1, nextOption)) % MOD_VAL
            cache[(n, cur)] = ways
            return ways

        if n == 0:
            return 0
        
        ans = 0
        for i in range(10):
            ans = (ans + backtrack(n - 1, i)) % MOD_VAL
        return ans  