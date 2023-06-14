class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //other approaches in notes but best is striver video approach 
        // we calculate product from beginning and the end
        // when we get the odd number of negatives, the competitors can be its left prod or its right product
        int prefix = 1;
        int suffix = 1;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(prefix == 0) prefix = 1; // handles the case of zero
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};