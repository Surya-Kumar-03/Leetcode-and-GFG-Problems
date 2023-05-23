class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            unordered_map<int, int> ourMap;	// stores val and freq
            vector<int> ans;
            for (int i = 0; i < nums.size(); i++)
            {
                ourMap[nums[i]]++;
            }
            priority_queue<pair<int, int>> pq;
            for (auto ele: ourMap)
            {
                pq.push({ ele.second,
                    ele.first });
            }
            for (int i = 0; i < k; i++)
            {
                int topEle = pq.top().second;
                ans.push_back(topEle);
                pq.pop();
            }
            return ans;
        }
};