/*用数组实现一个栈*/
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class myStack
{
public:
	myStack(size_t size) :array(size, {}) {}
	T peek()
	{
		if (end == 0)
		{
			std::runtime_error("越界");
		}
		return array[end-1];
	}
	void add(T obj)
	{
		if (end== array.size())
		{
			std::runtime_error("越界"); 
		}
		array[end++] = obj;
	}
	T pop()
	{
		if (end==0)
		{
			std::runtime_error("越界");
		}
		return array[--end];
	}
private:
	int end = 0;
	std::vector<T> array;
};

#include <stack>

int main()
{
	std::stack<int> stack1;
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	cout << "STL" << endl;
	cout << stack1.top() << endl;
	stack1.pop();
	cout << stack1.top() << endl;
	stack1.pop();
	cout << stack1.top() << endl;
	cout << stack1.size() << endl;

	cout << "myStack" << endl;

	myStack<int> stack2(3);
	stack2.add(1);
	stack2.add(2);
	stack2.add(3);
	cout << stack2.pop() << endl;
	cout << stack2.pop() << endl;
	cout << stack2.pop() << endl;

	//cout << stack.array.size();

	cin.get();
	return 0;
}

