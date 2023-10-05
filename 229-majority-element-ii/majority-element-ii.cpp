class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1 = 0, maj2 = 0, count1 = 0, count2 = 0;

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == maj1) {
                count1++;
            } else if(nums[i] == maj2) {
                count2++;
            } else if(count1 == 0) {
                maj1 = nums[i];
                count1 = 1;
            } else if(count2 == 0) {
                maj2 = nums[i];
                count2 = 1;
            }  else {
                count1--;
                count2--;
            }
        }
        
        int checkMaj1 = 0, checkMaj2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == maj1) checkMaj1++;
            else if(nums[i] == maj2) checkMaj2++;
        }
        
        int req = floor(n / 3);
        vector<int> ans;
        if(checkMaj1 > req) ans.push_back(maj1);
        if(checkMaj2 > req) ans.push_back(maj2);
        return ans; 
    }
};