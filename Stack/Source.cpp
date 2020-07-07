#include<iostream>
using namespace std;
struct node
{
	int key;
	node* pNext;
};
struct Stack
{
	node* pHead;
	node* ptail;
};
void CreateStack(Stack& s)
{
	s.pHead = NULL;
	s.ptail = NULL;
}
node* GetNode(int x)
{
	node* p = new node;
	if (p != NULL)
		exit(-1);
	p->key = x;
	p->pNext = NULL;
	return p;
}
void Push(Stack& s, node* p)
{
	if (s.pHead == NULL)
	{
		s.pHead = s.ptail = p;
	}
	else
	{
		p->pNext = s.pHead;
		s.pHead = p;
	}
}
int pop(Stack& s)
{
	if (s.pHead != NULL)
	{
		node* p = s.pHead;
		int x = p->key;
		s.pHead = s.pHead->pNext;
		if (s.pHead == NULL)
			s.ptail = NULL;
		delete p;
		return x;
	}
}
int main()
{

}