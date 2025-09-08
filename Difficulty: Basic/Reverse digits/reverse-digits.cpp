class Solution {
  public:
    int reverseDigits(int n) {
        // Code here
        int rev = 0;
        while (n > 0) {
            rev *= 10;
            rev += (n % 10);
            n /= 10;
        }
        
        return rev;
    }
};