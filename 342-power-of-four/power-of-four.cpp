class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        bitset<32> b(n);
        string s = b.to_string();
        bool msbFound = false;
        for(int i = 32; i >= 1; i--) {
            if(s[i] == '1') {
                if(msbFound || i % 2 == 0) return false;
                msbFound = true;
            }
        }
        return true;
    }
};