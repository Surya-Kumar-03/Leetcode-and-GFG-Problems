class Solution {
public:
    // read editorial, it is good
    int findRoot(int n, vector<int>& l, vector<int>& r) {
        unordered_set<int> children(l.begin(), l.end());
        children.insert(r.begin(), r.end());

        for(int i = 0; i < n; i++) {
            if(children.find(i) == children.end()) 
                return i;
        }

        return -1;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        int root = findRoot(n, l, r);
        if(root == -1) { // no root exists
            return false;
        }

        unordered_set<int> visited; // make sure all children have only one parent
        queue<int> pending;
        pending.push(root);
        
        while(!pending.empty()) {
            int top = pending.front();
            pending.pop();

            if(visited.find(top) != visited.end()) {
                return false;
            } 

            visited.insert(top);
            vector<int> children = {l[top], r[top]};
            for(int child : children) {
                if(child != -1) {
                    pending.push(child);
                }
            }
        }

        // make sure it is not disconnected
        return visited.size() == n;
    }
};