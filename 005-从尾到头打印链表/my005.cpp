#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct nodeList
{
public:
	int value;
	struct nodeList *next;
};


class Solution
{
public:
	static vector<int> printInverse(nodeList a[])
	{
		nodeList *b = a;
		stack<int> s;
		while (b != nullptr)
		{
			s.push(b->value);
			b = b->next;			
		}
		vector<int> vec;
		while (!s.empty())
		{
			vec.push_back(s.top());
			s.pop();
		}
		return vec;
	}
	
};

int main()
{
	nodeList lis[4];
	lis[0].value = 0;
	lis[0].next = &lis[1];
	lis[1].value = 1;
	lis[1].next = &lis[2];
	lis[2].value = 2;
	lis[2].next = &lis[3];
	lis[3].value = 3;
	lis[3].next = nullptr;

	vector<int> res = Solution::printInverse(lis);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i]  << endl;
	}
	return 0;


}

