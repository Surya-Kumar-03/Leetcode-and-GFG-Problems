class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ins = 0, cur = 0;
        int k = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == val) {
                cur++;
            } else {
                k++;
                if(ins < cur) {
                    swap(nums[cur], nums[ins]);
                }
                ins++;
                cur++;
            }
        }
        return k;
    }
};