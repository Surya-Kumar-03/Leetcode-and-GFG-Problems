class Solution {
public: 
    static bool ourComp(vector<int> pair1, vector<int> pair2) {
        return pair1[1] < pair2[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), ourComp);
        int n = pairs.size();
        int last = pairs[0][0] - 1;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(pairs[i][0] > last) {
                last = pairs[i][1];
                ans++;
            } 
        }
        return ans;
    }
};