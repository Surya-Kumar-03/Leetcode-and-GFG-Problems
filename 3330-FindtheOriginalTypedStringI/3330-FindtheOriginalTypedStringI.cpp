// Last updated: 7/2/2025, 1:08:51 AM
class Solution {
public:
    int possibleStringCount(string word) {
        int size = word.size();
        
        char curChar = word[0];
        int curCount = 1;
        int ansCount = 1;

        for (int itr = 1; itr < size; itr++) {
            if (word[itr] != curChar) {
                if (curCount > 1) {
                    ansCount += (curCount - 1);
                }
                
                curChar = word[itr];
                curCount = 1;
            } else {
                curCount++;
            }
        }

        if (curCount > 1) {
            ansCount += (curCount - 1);
        }

        return ansCount;
    }
};