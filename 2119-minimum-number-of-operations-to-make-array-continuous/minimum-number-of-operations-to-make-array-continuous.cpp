class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minOps = n; // max number of operations

        vector<int> newNums;
        set<int> unique(nums.begin(), nums.end());
        for(auto num : unique) {
            newNums.push_back(num);
        }

        int j = 0; 
        int size = newNums.size();
        
        for(int i = 0; i < size; i++) {
            while(j < size && newNums[j] <= newNums[i] + (n - 1)) {
                j++;
            }
            minOps = min(minOps, n - (j - i));
        }
        return minOps;
    }
};