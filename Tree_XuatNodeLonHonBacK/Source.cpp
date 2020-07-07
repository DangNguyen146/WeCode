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
void ChieuCao(Tree T, int& max, int h)
{
	if (T == NULL)
		return;

	if (max < h)
		max = h;

	ChieuCao(T->pLeft, max, h + 1);
	ChieuCao(T->pRight, max, h + 1);
}

void XuatTheoMucH(Tree t, int h, int k)
{
	if (t == NULL)
		return;
	if (h == k)
		cout << t->key << " ";
	XuatTheoMucH(t->pLeft, h, k + 1);
	XuatTheoMucH(t->pRight, h, k + 1);

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
	

	int k;
	cin >> k;
	int max = 0, h = 0;
	ChieuCao(t, max, h);

	for (int i = 0; i <= max; i++)
	{
		cout << i << ": ";
		XuatTheoMucH(t, i, 0);
		cout << endl;
	}
}