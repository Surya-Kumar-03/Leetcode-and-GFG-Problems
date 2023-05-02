class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool isPositive = true;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) return 0;
            if(isPositive && (nums[i] < 0)){
                isPositive = false;
                continue;
            }
            if(!isPositive && (nums[i] < 0)){
                isPositive = true;
            }
        }
        return isPositive ?  1 : -1;
    }
};