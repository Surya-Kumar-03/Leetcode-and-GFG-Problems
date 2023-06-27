class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> temp(n, 1); // distribute one candy each
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                temp[i] = temp[i - 1] + 1;
            }
        }

        int right = 1; //saving space by using variable for right side instead of an array
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                right++;
            } else right = 1;
            temp[i] = max(temp[i], right);
        }

        int count = 0;
        for(auto candy : temp) count += candy;
        return count;
    }
};