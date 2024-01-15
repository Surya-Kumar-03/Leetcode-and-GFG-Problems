class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> lost;
        for(auto players : matches) {
            int winner = players[0];
            int loser = players[1];
            if(lost.find(winner) == lost.end()) lost[winner] = 0;
            lost[loser]++;
        }

        vector<int> zeroLost, oneLost;
        for(auto playerDetails : lost) {
            int player = playerDetails.first;
            int matchesLost = playerDetails.second;
            if(matchesLost == 0) {
                zeroLost.push_back(player);
            } 

            if(matchesLost == 1) {
                oneLost.push_back(player);
            }
        }
        return {zeroLost, oneLost};
    }
};