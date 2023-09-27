class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long curLength = 0;
        char c = 0;
        
        for (int i = 0; i < S.length(); i++) {
            c = S[i];
            if (isdigit(c)) {
                curLength *= c - '0';
            }
            else {
                curLength++;
            }
        }
        
        for (int i = S.length() - 1; i >= 0; i--) {
            c = S[i];
            if (isdigit(c)) {
                curLength /= c - '0';
                K %= curLength;
            }
            else {
                if (K == 0 || K == curLength) {
                    string result = "";
                    result += c;
                    return result;
                }
                curLength--;
            }
        }
        
        throw nullptr;
    }
};