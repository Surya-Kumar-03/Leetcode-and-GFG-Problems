class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = m - 1
        j = n - 1

        for k in range(len(nums1) - 1, -1, -1):
            iPos = nums1[i] if i >= 0 else float('-inf')
            jPos = nums2[j] if j >= 0 else float('-inf')
            
            if iPos > jPos:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            

        
        