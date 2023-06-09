class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ourSet;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            ourSet.insert(nums[i]);
        }

        int maxSeq = 0;
        for(int i = 0; i < size; i++) {
            if(ourSet.find(nums[i] - 1) != ourSet.end()) {
                continue;
            } else {
                int curSeq = 1, curNum = nums[i] + 1;
                while(ourSet.find(curNum) != ourSet.end()) {
                    curSeq++;
                    curNum += 1;
                }
                maxSeq = max(curSeq, maxSeq);
            }
        }
        return maxSeq;
    }
};