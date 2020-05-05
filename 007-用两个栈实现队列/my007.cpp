#include <iostream>
#include <stack>

using namespace std;

class solution
{
public:
	int push(int node)
	{
		if (stackin.empty()&&!stackout.empty())
		{
			while (!stackout.empty())
			{
				stackin.push(stackout.top());
				stackout.pop();
			}
			cout << "导入输入栈完成" << endl;
		}
		stackin.push(node);
		return node;
	}

	int pop()
	{
		int node;
		if (this->isempty())
		{
			cout << "error: 队列为空!" << endl;
			return -1;
		}
		if (stackout.empty() && !stackin.empty())
		{
			while (!stackin.empty())
			{
				stackout.push(stackin.top());
				stackin.pop();
			}
			cout << "导入输出栈完成" << endl;
		}
		node = stackout.top();
		stackout.pop();
		return node;
	}

	bool isempty()
	{
		return (stackin.empty() && stackout.empty());
	}

private:
	stack<int> stackin;
	stack<int> stackout;
};

int main()
{
	solution solu;
	for (int i = 0; i < 5; i++)
	{
		cout << solu.push(i) << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		cout << solu.pop() << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << solu.push(i * 2) << endl;
	}
	while (!solu.isempty())
	{
		cout << solu.pop() << endl;
	}

	return 0;

}

