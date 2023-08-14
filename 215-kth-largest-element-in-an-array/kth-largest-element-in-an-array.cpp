class Solution {
public:
    // int partition(vector<int>& nums, int low, int high)
    // {
        // int pivot = nums[low];
        // int pivotCorrectIndex = low;

        // // calculating correct index for pivot
        // for(int i = low + 1; i <= high; i++)
        // {
        //     if(nums[i] <= pivot) pivotCorrectIndex++;
        // }
        
        // // placing pivot in corrct position
        // swap(nums[low], nums[pivotCorrectIndex]);

        // // keeping smaller values left and bigger value right of pivot
        // while(low < pivotCorrectIndex && high > pivotCorrectIndex)
        // {
        //     if(nums[low] <= pivot)
        //         low++;
        //     else if (nums[high] > pivot)
        //         high--;
        //     else  
        //     {
        //         swap(nums[low], nums[high]);
        //         low++, high--;
        //     }
        // }
        // return pivotCorrectIndex;
    // } 


    int partition(vector<int>& arr, int l, int r, int k) {
        int pivot = arr[r];
        int pivotIndex = r;

        int cur = l;
        for (int i = l; i < r; i++) {
            if (arr[i] <= pivot) {
                swap(arr[i], arr[cur]);
                cur++;
            }
        }

        swap(arr[pivotIndex], arr[cur]);

        // cur is now the index of the pivot after partitioning

        int numLarger = r - cur + 1;  // number of elements larger than or equal to the pivot

        if (numLarger == k) {
            return arr[cur];  // kth largest element found
        } else if (numLarger > k) {
            return partition(arr, cur + 1, r, k);  // search in the larger partition
        } else {
            return partition(arr, l, cur - 1, k - numLarger);  // search in the smaller partition for (k - numLarger)th largest
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return partition(nums, 0, nums.size() - 1, k);
        //optimise using quick select algorithm average case O(N) 
        // but worst case is O(N^2)
        // int low = 0;
        // int high = nums.size() - 1;
        // int ans = -1;
        // int searchIndex = nums.size() - k; //kth largest

        // while(low <= high)
        // {
        //     int pivotIndex = partition(nums, low, high);
        //     if(pivotIndex == searchIndex)
        //     {
        //         ans = nums[pivotIndex];
        //         break;
        //     }
        //     else if(searchIndex < pivotIndex) high = pivotIndex - 1;
        //     else low = pivotIndex + 1;
        // }
        // return ans;
    }

    // int findKthLargest(vector<int>& nums, int k) {
    //     /* using priority queue O(N lg K)
    //     push nums vector into priority queue */
    //     priority_queue<int> ourQueue(nums.begin(), nums.end());

    //     //Remove elements from max heap till k - 1
    //     for(int i = 0; i < k - 1; i++)
    //     {
    //         ourQueue.pop();
    //     }

    //     //return top which will be k
    //     return ourQueue.top();
    // }
};