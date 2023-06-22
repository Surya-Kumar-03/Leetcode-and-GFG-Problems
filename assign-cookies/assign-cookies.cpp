class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int contentCount = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = 0; i < g.size(); i++) {
            while(j < s.size() && g[i] > s[j]) {
                j++;
            } 
            if(j >= s.size()) break;
            else {
                if(g[i] <= s[j]) {
                    contentCount++;
                    j++;
                } else break;
            }
        }
        return contentCount;
    }
};