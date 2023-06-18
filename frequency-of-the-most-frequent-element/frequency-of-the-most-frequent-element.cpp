class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long sum = 0; 
        long long start = 0; 
        long long answer = 1; 

        for (long long end = 0; end < n; ++end) {
            sum += nums[end]; 
            // See neetcode video for why we did this
            // means that if we muliply the window size * the number we are trying to make the max freq, it should be less than the total sum + k(extra budget)
            while ((end - start + 1) * nums[end] > sum + k) {
                sum -= nums[start]; 
                start++; 
            }
            answer = max(answer, end - start + 1);
        }

        return answer;
    }
};
