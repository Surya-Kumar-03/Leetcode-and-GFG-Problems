class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.size(), n = t.size();
        string ss = "", tt = "";
        for(int i = 0; i < m; i++) {
            if(s[i] == '#') {
                if(!ss.empty()) ss.pop_back();
            } 
            else ss += s[i];
        }

        for(int j = 0; j < n; j++) {
            if(t[j] == '#') {
                if(!tt.empty()) tt.pop_back();
            }
            else tt += t[j];
        }

        cout << ss << " " << tt << endl;

        return (ss == tt);

        // int i = s.size() - 1, j = t.size() - 1;
        // while(true) {
        //     if(s[i] == '#') {
        //         int cur = 0;
        //         do {
        //             if(s[i] == '#') cur++;
        //             else cur--; 
        //             i--;
        //         } while(i >= 0 && cur > 0);
        //     } else if(t[j] == '#') {
        //         int cur = 0;
        //         do {
        //             if(t[j] == '#') cur++;
        //             else cur--; 
        //             j--;
        //         } while(j >= 0 && cur > 0);
        //     } else {
        //         if(s[i] != t[j]) return false;
        //         i--, j--;
        //     }
        // }
        // return true;
    }
};