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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* first = head;
        ListNode* second = head -> next;
        ListNode* even_head = second;
        while(second && second -> next != NULL)
        {
            first -> next = second -> next;
            second -> next = second -> next -> next;
            first = first -> next;
            second = second -> next;
        }
        first -> next = even_head;
        return head;
    }
};