// Last updated: 7/4/2025, 1:44:37 AM
class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + __builtin_popcount(k - 1);
    }
};