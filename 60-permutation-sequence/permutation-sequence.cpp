class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        for(int i = 1; i <= n; i++) {
            num.push_back(i);
        }

        for(int i = 0; i < k - 1; i++) {
            next_permutation(num.begin(), num.end());
        }

        string ans = "";
        for(auto ele : num) {
            ans += to_string(ele);
        }
        return ans;
    }
};