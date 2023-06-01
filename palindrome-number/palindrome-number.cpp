class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long rev = 0;
        int temp = x;
        while (temp != 0) {
            int lastDig = temp % 10;
            rev = rev * 10 + lastDig;
            temp /= 10;
        }
        return rev == x;
    }
};