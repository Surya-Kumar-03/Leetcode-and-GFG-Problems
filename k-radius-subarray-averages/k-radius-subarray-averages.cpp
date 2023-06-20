class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int expectedSize = (k * 2) + 1;
        if(expectedSize > n) return ans;
        int midIndex = k;
        long long cumSum = 0;
        int i = 0, j = 0;
        while(j < n) {
            cumSum += nums[j];
            if((j - i + 1) == expectedSize) {
                ans[midIndex] = cumSum / expectedSize;
                midIndex++;
                cumSum -= nums[i];
                i++;
            }
            j++;
        }
        return ans; 
    }
};