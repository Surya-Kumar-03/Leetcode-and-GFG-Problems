class Solution {
public:
    // dp tle 2^N
    // int ourMin(vector<int>& nums, int i, int j, int x, 
    //     unordered_map<string, int>& memo) {

    //     if(x < 0) return -1;
    //     if(x == 0) return 0;
    //     if(i > j) return -1;

    //     string hash = to_string(i) + to_string(j) + to_string(x);
    //     if(memo.find(hash) != memo.end()) {
    //         return memo[hash];
    //     }
        
    //     int operations = -1, ifFirst = -1, ifLast = -1;
    //     if(nums[i]  <= x) {
    //         int temp = ourMin(nums, i + 1, j, x - nums[i], memo);
    //         if(temp != -1) ifFirst = temp;
    //     }
    //     if(nums[j] <= x) {
    //         int temp = ourMin(nums, i, j - 1, x - nums[j], memo); 
    //         if(temp != -1) ifLast = temp;
    //     }

    //     if(ifFirst != -1 && ifLast != -1) {
    //         return memo[hash] = min(ifFirst, ifLast) + 1;
    //     } else if(ifFirst > -1 || ifLast > -1) {
    //         return memo[hash] = max(ifFirst, ifLast) + 1;
    //     } else return memo[hash] = -1;
    // }

    // int minOperations(vector<int>& nums, int x) {
    //     int n = nums.size();
    //     unordered_map<string, int> memo;
    //     return ourMin(nums, 0, n - 1, x, memo);
    // }

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> prefix;
        prefix[0] = -1; // for the case of whole array
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];

        if(sum == x) return n; //we have to use all array elements to reduce x to 0, because all numbers are positive

        int target = sum - x; //we need to find the max size array we get with the sum equal to target, n - x would be the answer

        int curSum = 0;
        int maxLen = -1;
        for(int i = 0; i < n; i++) {
            curSum += nums[i];
            if(prefix.find(curSum - target) != prefix.end()) {
                int curLen = i - prefix[curSum - target];
                maxLen = max(curLen, maxLen); 
            } 
            prefix[curSum] = i;
        }
        return maxLen != -1 ? n - maxLen : -1;
    }
};

