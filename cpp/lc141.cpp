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
        ListNode* front = head; 
        ListNode* second = head;
        while(second && second -> next != NULL)
        {
            front = front -> next;
            second = second -> next -> next;
            if(front == second)
                return true;
        }
        return false;
    }
};