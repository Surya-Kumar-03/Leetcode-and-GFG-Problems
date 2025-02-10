class Solution {
public:
    string clearDigits(string s) {
        int itr = s.size() - 1;
        string resultString = "";
        int deletePendingCount = 0;
    
        while (itr >= 0) {
            if (s[itr] >= '0' && s[itr] <= '9') {
                deletePendingCount++;
            } else if (deletePendingCount > 0) {
                deletePendingCount--;
            } else {
                resultString += s[itr];
            }
            itr--;
        }

        reverse(resultString.begin(), resultString.end());
        return resultString;
    }
};