#include <cstdlib>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    int NodeNum(ListNode* head)
    {
        int length = 0;
        while(head != NULL)
        {
            length++;
            head = head -> next;
        }
        return length;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head == NULL && head -> next != NULL)
            return head;
        int length = NodeNum(head);
        cout << length;
        int numberOfpair = length / 2;
        ListNode* result = head -> next;
        ListNode* pair_first = head;
        ListNode* pair_second = head -> next;
        while(numberOfpair--)
        {
            ListNode* next_pair = pair_second -> next;//保存下一对节点
            pair_second -> next = pair_first; //调整指针方向
            if(next_pair != NULL && next_pair -> next == NULL)   //奇数个节点的情况，最后剩一个节点
                pair_first -> next = next_pair;
            else if(next_pair != NULL && next_pair -> next != NULL)
                pair_first -> next = next_pair -> next;
            else if(next_pair == NULL)
                pair_first -> next = NULL;
            pair_first = next_pair;
            if(next_pair != NULL)
                pair_second = next_pair -> next;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    for(int i = 2; i < 4; ++i)
    {
        ListNode* iter = head;
        while(iter -> next != NULL)
        {
            iter = iter -> next;
        }
        ListNode* p = new ListNode(i);
        iter -> next = p;

    }
    Solution s; 
    ListNode* result = s.swapPairs(head);


    return 0;
}