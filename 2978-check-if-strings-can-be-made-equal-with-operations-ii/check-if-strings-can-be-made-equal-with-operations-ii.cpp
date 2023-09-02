class Solution {
public:
    bool checkStrings(string s1, string s2) {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                int j;
                for (j = i + 2; j < s1.size(); j += 2)
                    if (s1[j] == s2[i])
                        break;

                if (j < s1.size())
                    swap(s1[i], s1[j]);
            }
        }
        return s1 == s2;
    }
};
