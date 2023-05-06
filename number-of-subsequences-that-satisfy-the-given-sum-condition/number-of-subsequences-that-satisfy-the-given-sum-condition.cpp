class Solution {
public:
    int mod = 1e9 + 7;
    
    long long power(long long base, int exponent) {
        long long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            if(nums[i] + nums[j] <= target){
                ans = (ans + (power(2, j - i) % mod)) % mod;
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};
