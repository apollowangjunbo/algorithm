/*ʵ��һ�������ջ����ʵ��ջ�Ļ������ܵĻ����ϣ���ʵ�ַ���ջ����СԪ�صĲ���
Ҫ��
1.pop��push��getMin������ʱ�临�Ӷȶ���O(1)
2.����ʹ���ֳɵ�ջ�ṹ
*/
#include <iostream>
#include <stack>
using namespace std;

template<class T>
class stack_with_getMin
{
public:
	void push(T obj)
	{
		m_stack.push(obj);
		helper.push(helper.empty()||obj < helper.top() ? obj : helper.top());
	}
	T pop()
	{
		helper.pop();
		auto res = m_stack.top();
		m_stack.pop();
		return res;
	}
	T getMin()
	{
		return helper.top();
	}
private:
	std::stack<T> m_stack;
	std::stack<T> helper;
};


int main()
{
	stack_with_getMin<int> stack;
	stack.push(5);
	stack.push(6);
	stack.push(1);
	stack.push(5);
	stack.push(2);
	stack.push(4);
	cout<<stack.getMin();

	cin.get();
	return 0;
}

