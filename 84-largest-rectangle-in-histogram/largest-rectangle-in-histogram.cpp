class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<pair<int,int>> st;
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                st.push({i, heights[i]});
            } else if(heights[i] >= st.top().second) {
                st.push({i, heights[i]});
            } else {
                int start = i;
                while(!st.empty() && heights[i] < st.top().second) {
                    int lastBarHeight = st.top().second;
                    int lastBarIndex = st.top().first;
                    start = lastBarIndex;
                    maxArea = max(maxArea, lastBarHeight * (i - lastBarIndex));
                    st.pop();
                }
                st.push({start, heights[i]});
            }
        }
        return maxArea;
    }
};