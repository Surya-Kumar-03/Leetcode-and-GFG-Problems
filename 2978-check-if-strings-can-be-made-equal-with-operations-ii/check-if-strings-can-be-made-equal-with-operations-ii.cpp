class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<char> odd(26,0), even(26,0);
        for(int i = 0; i < s1.size(); ++i){
            if(i%2) { odd[s1[i] - 'a']++; odd[s2[i] - 'a']--; }
            else { even[s1[i] - 'a']++; even[s2[i] - 'a']--; }
        }
        
        for(int i = 0; i < odd.size(); ++i){
            if(odd[i] || even[i]) return false;
        }
        return true;

        // O(N^2)
        // for (int i = 0; i < s1.size(); i++)
        // {
        //     if (s1[i] != s2[i])
        //     {
        //         int j;
        //         for (j = i + 2; j < s1.size(); j += 2)
        //             if (s1[j] == s2[i])
        //                 break;

        //         if (j < s1.size())
        //             swap(s1[i], s1[j]);
        //     }
        // }
        // return s1 == s2;
    }
};
