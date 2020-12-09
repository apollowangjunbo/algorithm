/*用队列实现一个栈*/
#include <iostream>
#include <queue>

using namespace std;

template<class T>
class myStack
{
public:
	void push(T obj)
	{
		data.push(obj);
	}
	T pop()
	{
		while (data.size() > 1)
		{
			help.emplace(data.front());
			data.pop();
		}
		auto temp = data.front(); data.pop();
		std::swap(data, help);
		return temp;
	}
	T peek()
	{
		if (data.empty())//别落下
		{
			std::runtime_error("越界");
		}
		while (data.size() > 1)
		{
			help.emplace(data.front());
			data.pop();
		}
		auto temp = data.front(); data.pop();
		help.push(temp());
		std::swap(data, help);
		return temp;
	}
private:
	std::queue<T> data;
	std::queue<T> help;
};

int main()
{
	myStack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;

	//cout << stack.array.size();

	cin.get();
	return 0;
}

