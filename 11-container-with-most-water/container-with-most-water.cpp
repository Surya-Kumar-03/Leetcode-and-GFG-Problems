class Solution {
public:
    int maxArea(vector<int>& height) {
        int lmax = height[0]; 
        int rmax = height.back();
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;

        while (l < r) {
            int h = min(height[l], height[r]); 
            ans = max(ans, (r - l) * h); 
            if (height[l] <= height[r]) {
                l++;
            } else {
                r--; 
            }
            lmax = max(lmax, height[l]); 
            rmax = max(rmax, height[r]); 
        }
        return ans;
    }
};
