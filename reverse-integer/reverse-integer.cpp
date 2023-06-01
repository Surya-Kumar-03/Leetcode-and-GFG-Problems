class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0) {
            int lastDig = x % 10;
            x /= 10;
            if((rev < INT_MIN/10 && lastDig < -8) || (rev > INT_MAX/10 && lastDig > 7)) return 0;
            if(rev < INT_MIN/10 || rev > INT_MAX/10) return 0;
            rev = rev * 10 + lastDig;
        }
        return rev;
    }
};