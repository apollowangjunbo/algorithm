/*用数组实现一个队列*/
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class myQueue
{
public:
	myQueue(size_t size) :array(size, {}), nSize(size){}
	void add(T obj)
	{
		if (nSize == array.size())
		{
			std::runtime_error("越界");
		}
		array[end] = obj;
		end = end == array.size() ? 0 : end + 1;
		nSize++;
	}
	T pop()
	{
		if (nSize ==0)
		{
			std::runtime_error("越界");
		}
		auto res = array[start];
		start = start == array.size() ? 0 : start + 1;
		return res;
	}
private:
	int start = 0;
	int end = 0;
	size_t nSize = 0;
	std::vector<T> array;
};

#include <queue>
int main()
{
	std::queue<int> queue1;
	queue1.push(1);
	queue1.push(2);
	queue1.emplace(3);
	cout << "STL" << endl;
	cout << queue1.front() << endl; queue1.pop();
	cout << queue1.front() << endl; queue1.pop();
	cout << queue1.front() << endl; queue1.pop();

	cout << "myQueue" << endl;
	myQueue<int> queue2(3);
	queue2.add(1);
	queue2.add(2);
	queue2.add(3);
	cout << queue2.pop() << endl;
	cout << queue2.pop() << endl;
	cout << queue2.pop() << endl;

	//cout << stack.array.size();

	cin.get();
	return 0;
}

