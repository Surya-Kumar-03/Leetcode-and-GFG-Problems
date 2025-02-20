class Solution {
public:
    bool binaryBacktracker(unordered_set<string>& numsSet, string& ans) {
        if(ans.size() == numsSet.size()) {
            if (numsSet.find(ans) == numsSet.end()) {
                return true;
            } else {
                return false;
            }
        } 


        for(char ch : {'0', '1'}) {
            ans += ch;
            if (binaryBacktracker(numsSet, ans)) {
                return true;
            }
            ans.pop_back();
        }

        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> numsSet(nums.begin(), nums.end());
        string ans = "";
        
        if(binaryBacktracker(numsSet, ans)) {
            return ans;
        }

        return "";
    }
};