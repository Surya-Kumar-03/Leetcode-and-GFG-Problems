class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        bool isNeg = false;
        if(x == INT_MIN) {
            return 0;
        }

        if(x < 0) {
            isNeg = true;
            x *= -1;
        }
        while(x > 0) {
            int lastNum = x % 10;
            if((rev * 10) >= INT_MAX) {
                return 0;
            } else {
                rev *= 10;
            }
            rev += lastNum;
            x /= 10;
        }
        if(isNeg) {
            return -1 * rev;
        } else return rev;
    }
};