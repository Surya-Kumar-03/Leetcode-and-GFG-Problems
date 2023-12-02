class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = m - 1
        j = n - 1

        for k in range(len(nums1) - 1, -1, -1):
            iPos = float('-inf')
            jPos = float('-inf')
            if i >= 0:
                iPos = nums1[i]
            if j >= 0:
                jPos = nums2[j]
            
            if iPos > jPos:
                i -= 1
            else:
                j -= 1
            
            nums1[k] = max(iPos, jPos)

        
        