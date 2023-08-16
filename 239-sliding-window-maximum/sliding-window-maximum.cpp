class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // this stores indexes of the elements, but can be done with the value itself
        vector<int> ans;
        int i = 0, j = 0;
        int n = nums.size();
        while(j < n) {
            if(j - i + 1 < k) {
                while(!dq.empty() && (nums[dq.back()] < nums[j])) {
                    dq.pop_back();
                }
                dq.push_back(j);
                j++;
            } else {
                while(!dq.empty() && (nums[dq.back()] < nums[j])) {
                    dq.pop_back();
                }
                dq.push_back(j);
                ans.push_back(nums[dq.front()]);
                if(dq.front() == i) dq.pop_front();
                i++, j++;
            }
        } 
        return ans;
    }
};