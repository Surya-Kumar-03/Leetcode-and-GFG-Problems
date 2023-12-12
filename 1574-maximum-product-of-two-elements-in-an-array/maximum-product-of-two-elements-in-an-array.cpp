class Solution {
public:
    pair<int,int> find(vector<int>& nums) {
        int n = nums.size(), maxi = -1, sMaxi = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > maxi) {
                int temp = maxi;
                maxi = max(maxi, nums[i]);
                if(temp != maxi) {
                    sMaxi = temp;
                }
            } else sMaxi = max(sMaxi, nums[i]);
        }
        return {maxi, sMaxi};
    } 

    int maxProduct(vector<int>& nums) {
        auto maxEle = find(nums);
        return (maxEle.first - 1) * (maxEle.second - 1);
    }
};