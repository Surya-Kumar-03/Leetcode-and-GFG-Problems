class Solution {
public:
    string getNext(int k, vector<int> input) {
        while (--k > 0) {
            next_permutation(input.begin(), input.end());
        }
        
        string ans = "";
        for (int i = 0; i < input.size(); i++) {
            ans += to_string(input[i]);
        }
        return ans;
    }

    string getPermutation(int n, int k) {
        vector<int> input;
        for (int i = 1; i <= n; i++) {
            input.push_back(i);
        }
        return getNext(k, input);
    }
};