// Last updated: 6/1/2025, 12:10:19 AM
class Solution {
public:
    void getAllPermutationsWithFixed(vector<vector<int>>& answer, vector<int> permuteVec, 
        int fixedSize, const int& size) {
        
        if (fixedSize == size) { // 0 == 3
            answer.push_back(permuteVec);
            return;
        }

        for (int itr = fixedSize; itr < size; itr++) { // itr = 0 1 2
            swap(permuteVec[fixedSize], permuteVec[itr]);
            getAllPermutationsWithFixed(answer, permuteVec, fixedSize + 1, size);
            swap(permuteVec[fixedSize], permuteVec[itr]);
        }
    } 

    void permuteHelper(vector<vector<int>>& answer, vector<int>& nums) {
        int size = nums.size(); // 3
        getAllPermutationsWithFixed(answer, nums, 0, size);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        
        permuteHelper(answer, nums);
        return answer;
    }
};