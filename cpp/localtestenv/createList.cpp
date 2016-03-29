/***********************
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

//write your function below
ListNode * removeNthNodeFromEnd(ListNode *head,int n)
{
	if(head == NULL || n == 0)//防御性编程，增加健壮性
		return head;
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *p,*q,*tmp;
	p = dummy;
	q = dummy;
	
	//p先走n步
	for(int i=0;i<n;i++)
	{
		if(p->next != NULL)
			p = p->next;
		else
			return head;//如果n超过链表的长度，直接返回head
	}

	//然后p,q一起走
	while(p->next)
	{
		p = p->next;
		q = q->next;
	}

	//此时q指向的是待删除节点的前驱
	tmp = q->next->next;
	delete q->next;
	q->next = tmp;

	head = dummy->next;
	delete dummy;
	return head;
}

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
	ListNode *resultList=removeNthNodeFromEnd(root,4);
	printList(resultList);
}


