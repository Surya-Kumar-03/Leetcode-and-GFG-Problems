/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void clone(Node* node, unordered_map<Node*, Node*>& visited) {
        if(visited.find(node) != visited.end()) return;
        Node* newNode =  new Node(node->val);
        vector<Node*> neighbors;
        
        int n = node->neighbors.size();
        visited[node] = newNode;
        for(int i = 0; i < n; i++) {
            clone(node->neighbors[i], visited);
            neighbors.push_back(visited[node->neighbors[i]]);
        }
        newNode->neighbors = neighbors;
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*, Node*> visited;
        clone(node, visited);
        return visited[node];
    }
};