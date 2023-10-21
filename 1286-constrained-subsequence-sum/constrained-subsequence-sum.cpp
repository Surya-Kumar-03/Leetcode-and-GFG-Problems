class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0], 0});
        int ans = nums[0];

        for(int i = 1; i < n; i++) {
            while(i - pq.top().second > k) {
                pq.pop();
            }

            // just like kadane's exclude negative
            int cur = max(0, pq.top().first) + nums[i];
            ans = max(ans, cur);
            pq.push({cur, i});
        }
        return ans;
    }
};