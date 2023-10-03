class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int count = 0;
        
        for(auto num : nums) {
            count += freq[num];
            freq[num]++;
        }
        
        
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[i] == nums[j]) count++;
        //     }
        // }

        return count;
    }
};