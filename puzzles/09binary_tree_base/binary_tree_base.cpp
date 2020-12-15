#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;
struct node
{
	node(int v) :value(v) {}
	int value;
	node* left = nullptr;
	node* right = nullptr;
	~node()
	{
		delete left;
		delete right;
	}
};

node* createTree(const vector<int>& vec)
{
	if (vec.empty())
	{
		return nullptr;
	}
	map<int, node*> dict;
	for (size_t i = 0; i < vec.size(); i++)
	{
		dict.emplace(i, new node(vec[i]));
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i*2+1< vec.size())
		{
			dict[i]->left = dict[i * 2+1];
		}
		if (i * 2+2 < vec.size())
		{
			dict[i]->right = dict[i * 2+2];
		}
	}
	return dict[0];
}


void preOrderRecur(node* n)
{
	if (n==nullptr)
	{
		return;
	}
	cout << n->value<<" ";
	preOrderRecur(n->left);
	preOrderRecur(n->right);
}

void preOrderunRecur(node* n)
{
	if (n == nullptr)
	{
		return;
	}
	stack<node*> stack;
	stack.push(n);
	while (!stack.empty())
	{
		n = stack.top();
		cout << n->value << " "; stack.pop();
		if (n->right!=nullptr)
		{
			stack.push(n->right);
		}
		if (n->left != nullptr)
		{
			stack.push(n->left);
		}
	}
}


void midOrderRecur(node* n)
{
	if (n == nullptr)
	{
		return;
	}
	midOrderRecur(n->left);
	cout << n->value << " ";
	midOrderRecur(n->right);
}

void posOrderRecur(node* n)
{
	if (n == nullptr)
	{
		return;
	}
	posOrderRecur(n->left);
	posOrderRecur(n->right);
	cout << n->value << " ";
}

int main()
{
	vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	auto tree = createTree(vec);
	cout << "preOrderRecur:" << endl;
	preOrderRecur(tree); cout << endl;
	preOrderunRecur(tree); cout << endl;
	cout << "midOrderRecur:" << endl;
	midOrderRecur(tree); cout << endl;
	cout  << "posOrderRecur:" << endl;
	posOrderRecur(tree);

	int a = 0;

	delete tree;
	cin.get();
	return 0;
}
