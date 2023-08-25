class Solution {
public:
    unordered_map<string, bool> memo; 

    bool interleave(string s1, string s2, string s3) {
        string key = s1 + "|" + s2 + "|" + s3;  
        if (memo.find(key) != memo.end()) {
            return memo[key];  
        }
        
        if (s3.empty()) {
            return s1.empty() && s2.empty();
        }
        
        bool result = false;

        if (!s1.empty() && !s2.empty() && s3[0] == s1[0] && s3[0] == s2[0]) {
            bool continueLeft = interleave(s1.substr(1), s2, s3.substr(1));
            bool changeRight = interleave(s1, s2.substr(1), s3.substr(1));
            result = continueLeft || changeRight;
        } else if (!s1.empty() && s3[0] == s1[0]) {
            result = interleave(s1.substr(1), s2, s3.substr(1));
        } else if (!s2.empty() && s3[0] == s2[0]) {
            result = interleave(s1, s2.substr(1), s3.substr(1));
        }

        memo[key] = result; 
        return result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        return interleave(s1, s2, s3);
    }
};
