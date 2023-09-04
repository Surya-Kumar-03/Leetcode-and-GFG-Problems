/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // optimal approach floyd's cycle finding algo
        // tortoise hare method O(N) O(1)
        if(head == NULL) return false; //edge case
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
                return true;
        }
        return false;
        // intiution in description 
        //brute force is to use hashing TC O(N) SC O(N)
        // unordered_map<ListNode*,int> ourMap;
        // while(head != NULL)
        // {
        //     if(ourMap.find(head) != ourMap.end())
        //         return 1;
        //     else
        //         ourMap[head] = 1; //default value 1
        //     head = head->next;
        // }
        // return 0;
    }
};