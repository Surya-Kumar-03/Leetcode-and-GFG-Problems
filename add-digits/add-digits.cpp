class Solution {
public:
    int addDigits(int num) {
        // Digital root O(1)
        if (num == 0) {
            return 0;
        } else if (num % 9 == 0) {
            return 9;
        } else {
            return num % 9;
        }

        // https://leetcode.com/problems/add-digits/solutions/1754049/easy-o-1-explanation-with-example/ -> intuition

        // iterative O(N)
        // while(num > 9) {
        //     int sum = 0;
        //     while(num) {
        //         sum += num % 10;
        //         num /= 10;
        //     }
        //     num = sum;
        // }
        // return num;
    }
};