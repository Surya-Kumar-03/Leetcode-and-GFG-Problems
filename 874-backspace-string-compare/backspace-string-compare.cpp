class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // int m = s.size(), n = t.size();
        // string ss = "", tt = "";
        // for(int i = 0; i < m; i++) {
        //     if(s[i] == '#') {
        //         if(!ss.empty()) ss.pop_back();
        //     } 
        //     else ss += s[i];
        // }

        // for(int j = 0; j < n; j++) {
        //     if(t[j] == '#') {
        //         if(!tt.empty()) tt.pop_back();
        //     }
        //     else tt += t[j];
        // }
        // return (ss == tt);

        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) { 
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                }
                else if (skipS > 0) {
                    skipS--;
                    i--;
                }
                else break;
            }
            while (j >= 0) { 
                if (t[j] == '#') {
                    skipT++;
                    j--;
                }
                else if (skipT > 0) {
                    skipT--;
                    j--;
                }
                else break;
            }

            if (i >= 0 && j >= 0 && s[i] != t[j])
                return false;
            if ((i >= 0) != (j >= 0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};