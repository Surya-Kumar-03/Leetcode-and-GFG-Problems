class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int s1Size = s1.size();
        int s2Size = s2.size();

        if (s1Size != s2Size) {
            return false;
        }

        int notSameCount = 0;
        string notMatchPair = "";
        string notMatchExpected = "";
        
        for(int iterator = 0; iterator < s1Size; iterator++) {
            if (s1[iterator] != s2[iterator]) {
                notSameCount++;
                notMatchPair += s1[iterator];
                notMatchExpected += s2[iterator];
            }
        }

        if (notSameCount == 0) {
            return true;
        }
 
        if ((notSameCount == 2) && 
        (notMatchPair == notMatchExpected || 
        notMatchPair == (std::string() + notMatchExpected[1] + notMatchExpected[0]))) {
            return true;
        }

        return false;
    }
};