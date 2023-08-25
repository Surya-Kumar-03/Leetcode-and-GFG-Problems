class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        unordered_map<char,int> romans;
        romans['M'] = 1000;
        romans['D'] = 500;
        romans['C'] = 100;
        romans['L'] = 50;
        romans['X'] = 10;
        romans['V'] = 5;
        romans['I'] = 1;
        
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n - 1; i++) {
            if(romans[s[i]] < romans[s[i+1]]) {
                ans -= romans[s[i]];
            } else {
                ans += romans[s[i]];
            }
        }
        ans += romans[s[n-1]];
        return ans;
    }
};