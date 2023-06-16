class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int i = 0, j = 0;
        int n = nums.size();
        while(j < n) {
            if(j - i + 1 < k) {
                while(!dq.empty() && (dq.back() < nums[j])) {
                    dq.pop_back();
                }
                dq.push_back(nums[j]);
                j++;
            } else {
                while(!dq.empty() && (dq.back() < nums[j])) {
                    dq.pop_back();
                }
                dq.push_back(nums[j]);
                ans.push_back(dq.front());
                if(dq.front() == nums[i]) dq.pop_front();
                i++, j++;
            }
        } 
        return ans;
    }
};