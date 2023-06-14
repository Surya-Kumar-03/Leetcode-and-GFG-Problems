class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // -1 -1 1 will output 0 if sliding window
        // negative values wont work in sliding window
        unordered_map<int,int> ourMap;
        int ans = 0, prefixSum = 0;
        ourMap[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            if(ourMap.find(prefixSum - k) != ourMap.end()) {
                ans += ourMap[prefixSum - k];
            }
            ourMap[prefixSum]++;
        }
        return ans;
    }
};
