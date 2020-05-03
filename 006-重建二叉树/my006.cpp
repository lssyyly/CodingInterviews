#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<char>> s;
int leftLayerIndex = 0;
int rightLayerIndex = 0;

struct nodeList
{
public:
	char value;
	nodeList *lchild=nullptr, *rchild=nullptr;
};

class Solution
{
public:
	static void reConstructBT(vector<char> pre, vector<char> in, int layer=0)
	{
		nodeList root;
		root.value = pre[0];
		s[layer].push_back(root.value);
		auto iter = find(in.begin(), in.end(), root.value);
		int rootIndexLeft = distance(in.begin(), iter);
		int rootIndexRight = distance(iter, in.end());
		if (rootIndexLeft > 1)
		{
			auto LeftPre = vector<char>(pre.begin() + 1, pre.begin() + rootIndexLeft + 1);
			auto LeftIn = vector<char>(in.begin(), in.begin() + rootIndexLeft);
			leftLayerIndex += 1;
			reConstructBT(LeftPre, LeftIn, leftLayerIndex);

		}
		else if (rootIndexLeft == 1)
		{
			leftLayerIndex += 1;
			s[leftLayerIndex].push_back(in[0]);
		}
		else
		{
			leftLayerIndex += 1;
			s[leftLayerIndex].push_back(' ');
		}

		if (rootIndexRight > 2)
		{
			auto RightPre = vector<char>(pre.end() - rootIndexRight + 1, pre.end());
			auto RightIn = vector<char>(in.end() - rootIndexRight + 1, in.end());
			rightLayerIndex += 1;
			reConstructBT(RightPre, RightIn, rightLayerIndex);
		}
		else if (rootIndexRight == 2)
		{
			rightLayerIndex += 1;
			s[rightLayerIndex].push_back(in[rootIndexLeft + 1]);
		}
		else
		{
			rightLayerIndex += 1;
			s[rightLayerIndex].push_back(' ');
		}			   		 
	}
	
};

int main()
{
	vector<char> preOrder{ '1', '2', '4', '7', '3', '5', '6', '8' };
	vector<char> inOrder = { '4', '7', '2', '1', '5', '3', '8', '6' };

	Solution::reConstructBT(preOrder, inOrder);

	for (int i = 0; i <= leftLayerIndex; i++)
	{
		for (int j = 0; j < s[i].size(); j++)
		{
			cout << s[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}
