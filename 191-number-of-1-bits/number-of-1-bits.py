class Solution:
    def hammingWeight(self, n: int) -> int:
        bits = str(bin(n))
        return bits.count('1')