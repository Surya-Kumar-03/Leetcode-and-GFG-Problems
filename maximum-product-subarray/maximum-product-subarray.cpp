class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int prefix = 1, suffix = 1;
        int n = nums.size();
        for(int i = 0;i < n; i++) {
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            maxProd = max(maxProd, max(prefix, suffix));
        }
        return maxProd;
    }
};