class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int target = n / 4, curFreq = 0, curEle = -1; 
        for(auto ele : arr) {
            if(ele != curEle) {
                curFreq = 1;
                curEle = ele;
            } else {
                curFreq++;
                if(curFreq > target) return curEle;
            }
        }
        return arr[0];
    }
};