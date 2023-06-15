class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> pMap;
        int pSize = p.size();
        int sSize = s.size();

        for(int i = 0; i < pSize; i++) {
            pMap[p[i]]++;
        }

        int i = 0, j = 0;
        vector<int> ans;
        unordered_map<char,int> curMap;
        while(j < sSize) {
            if(j - i + 1 < pSize) {
                curMap[s[j]]++;
                j++;
            } else {
                curMap[s[j]]++;
                if(curMap == pMap) ans.push_back(i);
                if(curMap[s[i]] == 1) curMap.erase(s[i]);
                else curMap[s[i]]--;
                i++, j++;
            }
        }
        return ans;
    }
};