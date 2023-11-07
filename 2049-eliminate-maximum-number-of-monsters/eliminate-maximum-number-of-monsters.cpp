class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time;
        for (int i = 0; i < dist.size(); i++) {
            time.push_back((dist[i] - 1) / speed[i] + 1);  // Calculate the time needed for each monster
        }
        
        sort(time.begin(), time.end());
        
        int count = 0;
        for (int i = 0; i < dist.size(); i++) {
            if (i >= time[i]) {
                return count;  // We can't eliminate more monsters as they will reach us in time
            }
            count++;
        }
        
        return count;
    }
};
