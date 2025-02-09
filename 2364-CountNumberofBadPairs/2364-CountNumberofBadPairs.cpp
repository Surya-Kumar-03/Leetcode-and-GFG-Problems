class Solution {
    public long countBadPairs(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        long good = 0;
        
        for(int i =0; i<nums.length; i++){
            int num = nums[i];
            int diff = num - i;
            good += map.getOrDefault(diff, 0);
            map.put(diff, map.getOrDefault(diff, 0)+1);
        }

        long total = ((long)nums.length*(nums.length-1))/2; 
        return total - good;
    }
}