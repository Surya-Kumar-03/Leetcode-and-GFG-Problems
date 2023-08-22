class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int iLast = -1;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(iLast != -1 && nums[i] == nums[iLast]) {
                continue;
            } else {
                iLast = i;
                int target = 0 - nums[i];
                int j = i + 1, k = n - 1;
                int jLast = -1, kLast = -1;
                while(j < k) {
                    if(jLast != -1 && nums[j] == nums[jLast]) j++;
                    else if(kLast != -1 && nums[k] == nums[kLast]) k--;
                    else if(nums[j] + nums[k] == target) {
                        ans.push_back({nums[i], nums[j], nums[k]});
                        jLast = j;
                        kLast = k;
                        j++;
                        k--;
                    } else if(nums[j] + nums[k] > target) {
                        k--;
                    } else {
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};