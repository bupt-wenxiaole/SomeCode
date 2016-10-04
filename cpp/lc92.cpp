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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre_reverse = NULL;  //指示翻转部分的前一个节点
        ListNode* iter = head;
        int temp_m = m; 
        while(--temp_m)
        {
            pre_reverse = iter;
            iter = iter -> next;
        }
        ListNode* reverse_head = iter; //指示翻转部分的头结点
        for(int i = m; i < n; i++)
        {
            iter = iter -> next;
        }
        ListNode* next_reverse = iter -> next; //指示翻转部分后的节点
        iter -> next = NULL; // 完成待翻转部分的剥离
        ListNode* new_head = reverseList(reverse_head);//翻转待翻转部分
        iter = new_head;
        while(iter -> next != NULL)
            iter = iter -> next;
        ListNode* new_tail = iter;
        if(pre_reverse == NULL)   //翻转部分包含原来的头结点
        {
            new_tail -> next = next_reverse;  //重新连接
            return new_head;
        }
        else
        {
            pre_reverse -> next = new_head;
            new_tail -> next = next_reverse;
            return head;
        }
        
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
    int len = 5;
    if (len<1)
        return 0;
    ListNode *root=NULL;
    for (int i=0;i<len;i++)
        addToTail(&root,rand()%100);
    printList(root);
    // fill the parameters in your function below
    Solution* solution = new Solution;
    solution -> reverseBetween(root, 2 , 4);
    printList(root);
    delete solution;
}