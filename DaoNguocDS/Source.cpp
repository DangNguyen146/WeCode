#include<iostream>
using namespace std;
struct node
{
	int key;
	node* pNext;
};
struct List
{
	node* pHead;
	node* pTail;
};
void CreateList(List& l)
{
	l.pHead = l.pTail = NULL;
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
void GetList(List& l, node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void Nhap(List& l)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0)
			break;
		node* p = GetNode(x);
		GetList(l, p);
	}
}
void DeHead(List& l)
{
	if (l.pHead != NULL)
	{
		node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
		delete p;
	}
}
void DeleQ(List& l, node* q)
{
	node* p;
	if (q != NULL)
	{
		p = q->pNext;
		if (p != NULL)
		{
			if (p == l.pTail)
				l.pTail = q;
			q->pNext = p->pNext;
		}
		delete p;

	}
}
int SeachX(List& l, int x)
{
	node* p = l.pHead;
	node* q = NULL;
	while (p != NULL && p->key != x)
	{
		q = p;
		p = p->pNext;
	}
	if (p == NULL)
		return 0;
	else if (p == l.pHead)
		DeHead(l);
	else
		DeleQ(l, q);
	return 0;
}
void Xuat(List l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->key << " ";
		p = p->pNext;
	}
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	Xuat(l);
	cout << endl;

	for (node* p = l.pHead; p != NULL; p = p->pNext)
	{

		for (node* q = p; q != NULL; q = q->pNext)
		{
			if (q->pNext != NULL)
			{
				node* i = q->pNext;
				if (i->key == p->key)
					DeleQ(l, q);
			}
		}
	}

	for (node* p = l.pHead; p != NULL; p = p->pNext)
	{

		for (node* q = p; q != NULL; q = q->pNext)
		{
			if (q->pNext != NULL)
			{
				node* i = q->pNext;
				if (i->key == p->key)
					DeleQ(l, q);
			}
		}
	}


	Xuat(l);
	return 0;
}