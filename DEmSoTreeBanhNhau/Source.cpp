#include<iostream>
using namespace std;
struct node
{
	int key;
	node* pLeft;
	node* pRight;
};
typedef node* Tree;
int InSertNode(Tree& t, int x)
{
	if (t)
	{
		if (t->key == x)
			return 0;
		if (t->key < x)
			return InSertNode(t->pRight, x);
		if (t->key > x)
			return InSertNode(t->pLeft, x);
	}
	t = new node;
	t->key = x;
	t->pLeft = t->pRight = NULL;
	return 1;
}
int DemTreeCon(Tree T)
{
	if (T==NULL)
		return 0;
	return 1 + DemTreeCon(T->pLeft) + DemTreeCon(T->pRight);

}
void LNR(Tree T)
{
	if (T)
	{
		LNR(T->pLeft);
		if (T->pLeft != NULL && T->pRight != NULL)
			if (DemTreeCon(T->pLeft) == DemTreeCon(T->pRight))
				cout << T->key << " ";
		LNR(T->pRight);
	}
}
int main()
{
	Tree t = NULL;
	int n;
	cin >> n;
	while (n != -1)
	{
		while (n < 1)
		{
			cin >> n;
		}
		InSertNode(t, n);
		cin >> n;
	}
	LNR(t);
	
}