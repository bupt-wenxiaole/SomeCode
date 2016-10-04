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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head; 
        ListNode* pre = NULL;
        while(cur != NULL)
        {
            if(cur -> val == val)
            {
                if(pre == NULL)  //待删除的是头结点
                {
                    ListNode* temp = cur;
                    cur = cur -> next;
                    head = head -> next;
                    delete temp;
                }
                else
                {
                    ListNode* temp = cur;
                    pre -> next = cur -> next;
                    cur = cur -> next;
                    delete temp;
                    
                }
            }
            else
            {
                pre = cur;
                cur = cur -> next;
            }
        }
        return head;
    }
};