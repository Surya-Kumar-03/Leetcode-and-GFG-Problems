// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         // check explanation
//         // using dutch national flag algorithm
//         int low = 0;  //will point to where 1's are starting
//         int mid = 0; // will be the traverser
//         int high = nums.size() - 1; // we be the point to place the next 2

//         // low to mid will be the 0's 
//         // mid to high will be the ones
//         // high to size - 1 will be the 2's
//         while(mid <= high)
//         {
//             cout << endl;
//             if(nums[mid] == 0)
//             {
//                 swap(nums[low], nums[mid]);
//                 low++;
//                 mid++;
//             }
//             else if(nums[mid] == 1)
//                 mid++;
//             else if(nums[mid] == 2) // nums[mid] is 2
//             {
//                 swap(nums[mid], nums[high]);
//                 high--;
//             }
//         }
//     }
// };

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++, mid++;
            } else if(nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--; 
            }
        }
    }
};
