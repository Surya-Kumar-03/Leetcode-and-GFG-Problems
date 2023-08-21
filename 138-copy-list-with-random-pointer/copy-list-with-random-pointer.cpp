class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        unordered_map<Node*, Node*> nodes;

        // Create a mapping of original nodes to copied nodes
        Node* original = head;
        while (original) {
            nodes[original] = new Node(original->val);
            original = original->next;
        }

        // Assign next and random pointers for copied nodes
        original = head;
        while (original) {
            nodes[original]->next = nodes[original->next];
            nodes[original]->random = nodes[original->random];
            original = original->next;
        }

        return nodes[head];
    }
};
