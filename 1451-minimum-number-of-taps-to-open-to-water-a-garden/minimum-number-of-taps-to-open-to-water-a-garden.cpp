class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1);

        for (int i = 0; i < ranges.size(); i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);

            // Update the maximum reach for the leftmost position
            maxReach[start] = max(maxReach[start], end);
        }
        
        int taps = 0;
        int curCover = 0;
        int maxCoverSoFar = 0;

        // Just like the jumps problem
        for (int i = 0; i <= n; i++) {
            if (i > maxCoverSoFar) {
                return -1;
            }

            if (i > curCover) {
                taps++;
                curCover = maxCoverSoFar;
            }

            maxCoverSoFar = max(maxCoverSoFar, maxReach[i]);
        }

        return taps;
    }
};