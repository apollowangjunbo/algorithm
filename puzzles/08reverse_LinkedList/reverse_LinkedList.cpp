/*翻转一个链表*/

#include <iostream>
#include <list>
using namespace std;
struct node
{
	int v;
	node* next = nullptr;
};

void print(node* head)
{
	cout << "=="<< endl;
	while (head!=nullptr)
	{
		cout << head->v<<endl;
		head = head->next;
	}
}

void reverse(node* head)
{
	node* n1 = nullptr; node* n2 = nullptr; node* n3 = nullptr;

	n1 = nullptr;
	n2 = head;
	while (n2!=nullptr)
	{
		n3 = n2->next;
		n2->next = n1;
		n1 = n2;
		n2 = n3;
	}
	print(n1);

}
int main()
{
	node a1{ 1 };
	node a2{ 2 }; a1.next = &a2;
	node a3{ 3 }; a2.next = &a3;
	node a4{4 }; a3.next = &a4;
	node a5{5}; a4.next = &a5;


	auto head = &a1;
	print(head);
	reverse(head);
	cin.get();
	return 0;
}
