class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> colorsToBallsMap;
        unordered_map<int, int> ballsToColorsMap;
        int n = queries.size();
        vector<int> answer;

        for (auto &query : queries) {  
            int curBall = query[0];  
            int curColor = query[1];  

            // If the ball is colored already
            if (ballsToColorsMap.find(curBall) != ballsToColorsMap.end()) {
                // les go find the curball in colorsSet and say bye bye bye
                int prevColorOfCurBall = ballsToColorsMap[curBall];
                colorsToBallsMap[prevColorOfCurBall].erase(curBall);

                if (colorsToBallsMap[prevColorOfCurBall].empty()) {
                    colorsToBallsMap.erase(prevColorOfCurBall);
                }
            } 

            // Now ya got that new color shinee
            ballsToColorsMap[curBall] = curColor;
            colorsToBallsMap[curColor].insert(curBall);

            answer.push_back(colorsToBallsMap.size());
        }

        return answer;
    }
};