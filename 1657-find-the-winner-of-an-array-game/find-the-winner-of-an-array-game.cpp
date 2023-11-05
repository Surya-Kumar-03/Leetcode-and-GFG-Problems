class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxEle = *max_element(arr.begin(), arr.end());
        if (k >= n) {
            return maxEle;
        }

        int count = 0; 
        int currentElement = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] > currentElement) {
                currentElement = arr[i];
                count = 1;
            } else {
                count++;
            }

            if (count == k) {
                return currentElement;
            }
        }

        return maxEle;
    }
};
