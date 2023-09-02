class Solution {
public:
    int memo(string& s, unordered_set<string>& mp, vector<int>& dp, int index)
    {
        if (index >= s.size()) return 0;
        if (dp[index] != -1) return dp[index]; 
        
        string currStr = "";
        int minExtra = s.size(); // max possible value
        for (int cutIdx = index; cutIdx < s.size(); cutIdx++)
        {
            currStr.push_back(s[cutIdx]);
            int currExtra = (mp.count(currStr))? 0 : currStr.size();
            int nextExtra = memo(s, mp, dp, cutIdx + 1);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
        }
        return dp[index] = minExtra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        vector<int>dp(s.size(), -1);
        unordered_set<string> mp(dictionary.begin(), dictionary.end());
        int ans = memo(s, mp, dp, 0);
        return ans;
        
    }
};