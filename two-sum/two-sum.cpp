class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int,int> ourMap;
        vector<int> ans;
        for(int i = 0; i < size; i++) {
            if(ourMap.find(nums[i]) != ourMap.end()) {
                ans.push_back(i);
                ans.push_back(ourMap[nums[i]]);
            } else ourMap[target - nums[i]] = i;
        }
        return ans;
    }
};