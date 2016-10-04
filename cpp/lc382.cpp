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
        while (tmp->next)
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        iter = head;
        head_temp = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        resetIter(&iter);
        //srand(time(NULL));
        int res = iter -> val;
        iter = iter -> next;
        for(int i = 1; iter != NULL; i++)
        {
            int randomNum = random(0, i);
            if(randomNum < 1)
                res = iter -> val;
            iter = iter -> next;
        }
        return res;
    }
private:
    void resetIter(ListNode** iter)  //if you want modify a pointer , please pass the pointer's pointer to the function
    {
        *iter = head_temp;
    }
    ListNode *head_temp;
    ListNode *iter;
    int random(int low, int high)
    {
        if(low > high)
            random(high, low);
        int res = low + rand() % (high - low + 1);
        return res;
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
    int len = rand()%20;
    cout<<len<< endl;
    if (len<1)
        return 0;
    ListNode *root=NULL;
    for (int i=0;i<len;i++)
        addToTail(&root,rand()%100);
    printList(root);
    // fill the parameters in your function below
    Solution* solution = new Solution(root);
    cout << solution -> getRandom() << endl;
    cout << solution -> getRandom() << endl;
    cout << solution -> getRandom() << endl;
    cout << solution -> getRandom() << endl;
    delete solution;
}
