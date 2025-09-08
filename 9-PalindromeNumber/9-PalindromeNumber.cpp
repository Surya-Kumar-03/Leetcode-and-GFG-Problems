// Last updated: 9/8/2025, 8:56:45 AM
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; 
        
        long rev = 0, copy = abs(x);
        while (copy > 0) {
            rev *= 10;
            rev += (copy % 10);
            copy /= 10;
        }

        return rev == x;
    }
};