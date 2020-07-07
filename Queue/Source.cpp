#include<iostream>
using namespace std;
struct node
{
	int key;
	node* pNext;
};
struct Queue
{
	node* pHead;
	node* pTail;
};
void CreateQueue(Queue& q)
{
	q.pHead = q.pTail = NULL;
}
node* GetNode(int x)
{
	node* p = new node;
	if (p == NULL)
		exit(-1);
	p->key = x;
	p->pNext = NULL;
	return p;
}
void EnQueue(Queue& q, node* p)
{
	if (q.pHead == NULL)
	{
		q.pHead = q.pTail = p;
	}
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;
	}
}
int DeQueue(Queue& q)
{
	if (q.pHead != NULL)
	{
		node* p = q.pHead;
		q.pHead = q.pHead->pNext;
		int x = p->key;
		delete p;
		if (q.pHead == NULL)
			q.pHead = q.pTail = NULL;
		return x;
	}
}
int main()
{
	return 0;
}