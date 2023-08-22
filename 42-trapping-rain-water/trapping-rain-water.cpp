class Solution {
public:
    int trap(vector<int>& height)
    {
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int res = 0;

        while(l <= r) {
            if(height[l] <= height[r]) {
                if(height[l] >= leftMax) {
                    leftMax = height[l];
                    l++;
                } else {
                    res += (min(leftMax, height[r]) - height[l]);
                    l++;
                }
            } else { // height[l] > height[r]
                if(height[r] >= rightMax) {
                    rightMax = height[r];
                    r--;
                } else {
                    res += (min(height[l], rightMax) - height[r]);
                    r--;
                }
            }
        }
        
        return res;
    }
};