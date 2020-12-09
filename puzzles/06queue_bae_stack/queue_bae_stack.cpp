/*用数组实现一个队列*/
#include <iostream>
#include <stack>
using namespace std;

template<class T>
class myQueue
{
	/*
	help中有数据的时候不要trans
	trans的时候一定要清空data
	*/
	void trans()
	{
		if (!help.empty())
		{
			return;
		}
		while (!data.empty())
		{
			help.push(data.top()); data.pop();
		}
	
	}
public:
	T peek()
	{
		trans();
		return help.top();
	}
	void push(T obj)
	{
		data.push(obj); 
	}
	T pop()
	{
		trans();
		auto res = help.top(); help.pop();
		return res;
	}
private:
	std::stack<T> data;
	std::stack<T> help;
};

int main()
{
	cout << "myQueue" << endl;
	myQueue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	cout << queue.peek() << endl;
	cout << queue.pop() << endl;
	cout << queue.pop() << endl;
	cout << queue.pop() << endl;

	//cout << stack.array.size();

	cin.get();
	return 0;
}

