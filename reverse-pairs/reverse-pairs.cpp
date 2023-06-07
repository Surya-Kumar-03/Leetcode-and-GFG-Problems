class Solution {
public:
    int merger(vector<int>& nums, vector<int>& temp, int s, int mid, int e) {
        int i = s;
        int j = mid + 1;
        int revPairs = 0;

        for(int i = s; i <=  mid; i++) {
            while(j <= e &&  (nums[i] > (long long)2 * nums[j])) {
                j++;
            }
            revPairs += (j - (mid + 1));
        }

        i = s;
        j = mid + 1;
        int k = s; // for inserting sorted

        while(i <= mid && j <= e) {
            if(nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else temp[k++] = nums[j++];
        }

        while(i <= mid) {
            temp[k++] = nums[i++];
        }

        while(j <= e) {
            temp[k++] = nums[j++];
        }
        
        for(int l = s; l <= e; l++) {
            nums[l] = temp[l];
        }

        return revPairs;
    }

    int mergeSort(vector<int>& nums, vector<int>& temp, int s, int e) {
        int revCount = 0;
        if(s < e) {
            int mid = (s + e) / 2;
            revCount += mergeSort(nums, temp, s, mid);
            revCount += mergeSort(nums, temp, mid + 1, e);
            revCount += merger(nums, temp, s, mid, e);
        }
        return revCount;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        return mergeSort(nums, temp, 0, n - 1);
    }
};
