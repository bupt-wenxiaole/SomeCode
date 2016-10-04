/***********************
Leetcode 382 Linked List Random Node
algorithms : reserviors sampling
author : xiaolewen_bupt
time complexity : O(N), space complexity : O(1)
test the leetcode's 
linkList problem 
in the loacal environment
***********************/


#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
};


void addToTail(ListNode **head,int val)
{
    ListNode *node =new ListNode(val);
    if (!*head)                         
    {
        *head = node;
    }
    else
    {
        ListNode *tmp=*head;
        while(tmp->next)
            tmp=tmp->next;
        tmp->next=node;
    }

}

void printList(ListNode *head)
{
    ListNode* tmp;
    tmp=head;
    if (tmp==NULL)
        cout<<"empty list";
    else
    {
        while (tmp!=NULL)
        {
            cout<<tmp->val<<',';
            tmp=tmp->next;
        }
        cout<<endl;
    }

}

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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next;
        while(head != NULL)
        {
            next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
            
        }
        return pre;
        
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        ListNode* pre_first = NULL;
        ListNode* first = head;
        ListNode* second = head;
        while(second && second -> next != NULL)   //利用快慢指针定位中间位置
        {
            pre_first = first;
            first = first -> next;
            second = second -> next -> next;
        }
        ListNode* new_head = reverseList(first);  //翻转链表的后半部分
        if(pre_first != NULL)
            pre_first -> next = NULL; //将前后部分拆分
        while(head != NULL && new_head != NULL)
        {
            if(head -> val != new_head -> val)
            {
                return false;
            }
            else
            {
                head = head -> next;
                new_head = new_head -> next;
            }
        }
        return true;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
int main()
{
    int lt=time(NULL);
    srand(lt);
    int len = 3;
    if (len<1)
        return 0;
    ListNode *root=NULL;
    int temp_val;
    for (int i=0;i<len;i++)
    {
        cin >> temp_val;
        addToTail(&root, temp_val);
    }
        
    printList(root);
    // fill the parameters in your function below
    Solution* solution = new Solution;
    bool res = solution -> isPalindrome(root);
    cout << res << endl;
    delete solution;
}