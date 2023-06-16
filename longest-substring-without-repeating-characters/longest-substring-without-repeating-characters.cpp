class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //brute force is to get all substrings and return the substring without repeating characters TC O(N^2)
        //optimising O(N) O(N) with the use of hashmap
        int left = 0, right = 0; //pointers
        int maxLength = 0; //max Length of Substring 
        unordered_map<char,int> ourMap; //character, indexLastSeen
        while(right < s.size())
        {
            // character found in ourMap
            if(ourMap.find(s[right]) != ourMap.end())
            {
            //move left pointer to the next index of where it was last seen and we ignore characters which aren't part of the current sliding window, so we take max of index and left
                left = max(ourMap[s[right]] + 1, left); 
            }
            ourMap[s[right]] = right; //char to index in map
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
        // unordered_map<char, int> ourMap;
        // int size = s.size();
        // int maxi = 0;
        // int i = 0, j = 0;
        // while(j < size) {
        //     if(ourMap.find(s[j]) != ourMap.end()) {
        //         i = max(ourMap[s[j]] + 1, i);
        //     }
        //     maxi = max(maxi, j - i + 1);
        //     ourMap[s[j]] = j;
        //     j++;
        // }
        // return maxi;
    }
};