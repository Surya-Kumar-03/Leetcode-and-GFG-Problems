/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int getSplit(MountainArray &m, int s, int e, int len) {
        while(s <= e) {
            int mid = (s + e) / 2;
            int ele = m.get(mid);
            bool left = false;
            bool right = false;
            printf("\ns is %d e is %d mid is %d", s, e, mid);
            if(mid - 1 < 0) {
                left = true;
            } else if(m.get(mid - 1) < ele) {
                left = true;
            }

            if(mid + 1 >= len) {
                right = true;
            } else if(m.get(mid + 1) < ele) {
                right = true;
            }
            printf("\n left is %d right is %d", left, right);

            if(left && right) return mid;
            else if(left) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }

    int binarySearch(int s, int e, int target, MountainArray &m, bool flag) {
        while(s <= e) {
            int mid = (s + e) / 2;
            int ele = m.get(mid);
            if(ele == target) {
                return mid;
            } else if(target < ele) {
                flag ? e = mid - 1 : s = mid + 1;
            } else {
                flag ? s = mid + 1 : e = mid - 1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &m) {
        int len = m.length();
        int mlead = getSplit(m, 0, len - 1, len);
        cout << endl << mlead << endl;
        // flag indicates if the array is sorted in asc or desc
        int firstHalf = binarySearch(0, mlead, target, m, true);
        if(firstHalf != -1) return firstHalf;
        int secondHalf = binarySearch(mlead + 1, len - 1, target, m, false);
        if(secondHalf != -1) return secondHalf;
        return -1;
    }
};