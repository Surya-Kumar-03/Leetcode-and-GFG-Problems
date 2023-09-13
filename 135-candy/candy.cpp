class Solution {
public:
    int candy(vector<int>& ratings) {
        // requires both sides val for that child
        // give the max of both sides, cur

        int n = ratings.size();
        
        vector<int> right(n);
        right[n - 1] = 1;

        int cur = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i + 1] < ratings[i]) {
                cur++;
            } else cur = 1;
            right[i] = cur;
        }

        cur = 1;
        int used = max(1, right[0]);
        for(int j = 1; j < n; j++) {
            if(ratings[j - 1] < ratings[j]) {
                cur++;
            } else cur = 1;
            used += max(cur, right[j]);
        }
        return used;
    }
};