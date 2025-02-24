class Solution {
public:
    bool reachRoot(int curNode, int prevNode, vector<int> &bobPath, vector<vector<int>> &Tree) {
        if(curNode == 0) {
            bobPath.push_back(curNode);
            return true;
        }
        for(auto &nextNode : Tree[curNode]) {
            if(nextNode != prevNode) {
                if(reachRoot(nextNode, curNode, bobPath, Tree)) {
                    bobPath.push_back(curNode);
                    return true;
                }
            }
        }
        return false;
    }

    int solve(int curNode, int prevNode, int &curStep, vector<int> &amount, unordered_map<int, int> &visStep, vector<vector<int>> &Tree) {
        int pay;
        if(visStep.find(curNode) == visStep.end() || visStep[curNode] > curStep) {
            pay = amount[curNode];
        }
        else if(visStep[curNode] == curStep) {
            pay = amount[curNode] / 2;
        }
        else {
            pay = 0;
        }
        int futurePay = INT_MIN;
        curStep++;
        for(auto &nextNode : Tree[curNode]) {
            if(nextNode != prevNode) {
                futurePay = max(futurePay, solve(nextNode, curNode, curStep, amount, visStep, Tree));
            }
        }
        curStep--;
        return pay + (futurePay == INT_MIN ? 0 : futurePay);
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int nodes = amount.size();
        vector<vector<int>> Tree(nodes);
        vector<int> bobPath;
        for(auto &edge : edges) {
            Tree[edge[0]].push_back(edge[1]);
            Tree[edge[1]].push_back(edge[0]);
        }
        reachRoot(bob, bob, bobPath, Tree);
        reverse(bobPath.begin(), bobPath.end());
        unordered_map<int, int> visStep;
        for(int idx = 0; idx < bobPath.size(); idx++) {
            visStep[bobPath[idx]] = idx;
        }
        int curStep = 0;
        return solve(0, 0, curStep, amount, visStep, Tree);
    }
};