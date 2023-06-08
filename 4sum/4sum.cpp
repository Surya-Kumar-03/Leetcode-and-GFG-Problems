class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 4) return ans; 
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long ourTarget = (long long)target - nums[i] - nums[j];
                int left =  j + 1, right = n - 1;
                while(left < right) {
                    if(nums[left] + nums[right] == ourTarget) {
                        vector<int> quadruple(4);
                        quadruple[0] = nums[i];
                        quadruple[1] = nums[j];
                        quadruple[2] = nums[left];
                        quadruple[3] = nums[right];
                        ans.push_back(quadruple);
                        while(left < right && nums[left] == quadruple[2]) left++;
                        while(right > left && nums[right] == quadruple[3]) right--;
                    } else if((nums[left] + nums[right]) > ourTarget) {
                        right--;
                    } else left++;
                }
                // already our for loop increments 1 so
                // assume we have 2 2 2 3
                // we need to stop    | in the last duplicate and for loop automatically moves it past the duplicates
                while(j + 1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i + 1 < n && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};