class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        int nn = n;
        if(n < 0) {
            x = 1 / x;
            nn = abs(nn);
        } 
        if(n % 2 == 0) {
            return myPow(x * x, nn / 2);
        } else {
            return x * myPow(x * x, nn / 2);
        }
    }
};