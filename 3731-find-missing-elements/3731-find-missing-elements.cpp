class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int minEle = nums[0];
        int maxEle = nums[size - 1];

        int curI = 0;
        vector<int> ans;
        for(int itr = minEle; itr <= maxEle; itr++) {
            if (curI >= size) {
                ans.push_back(itr);
            } else if (nums[curI] != itr) {
                ans.push_back(itr);
            } else {
                curI++;
            }
        }

        return ans;
    }
};