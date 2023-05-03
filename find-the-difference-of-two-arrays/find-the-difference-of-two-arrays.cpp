class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        //using stl
        vector<int> v1, v2;
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        // back_inserter used to store the result
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(v1));
        set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), back_inserter(v2));
        return {v1, v2};
        
        // My approach
    //    unordered_map<int, bool> ourMap;
    //    int n1 = nums1.size();
    //    int n2 = nums2.size();
    //    for(int i = 0; i < n1; i++){
    //         ourMap[nums1[i]] = false;
    //    }

    //    vector<int> ans2;
    //    for(int i = 0; i < n2; i++){
    //        if(ourMap.find(nums2[i]) == ourMap.end()){
    //            ans2.push_back(nums2[i]);
    //        } 
    //        ourMap[nums2[i]] = true;
    //    }

    //    vector<int> ans1;
    //    for(auto ele: ourMap){
    //        if(ele.second == false){
    //            ans1.push_back(ele.first);
    //        }
    //    }
    //    return {ans1, ans2};
    }
};