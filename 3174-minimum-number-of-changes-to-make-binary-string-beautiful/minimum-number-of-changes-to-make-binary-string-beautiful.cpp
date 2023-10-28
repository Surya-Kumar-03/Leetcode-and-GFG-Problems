class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int changes = 0;

        // Make Pairs Continously, we just care about min changes
        for(int i = 1; i < n; i += 2) {
            if(s[i] != s[i - 1]) changes++;
        }
        return changes;
    }
};
