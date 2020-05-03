#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct nodeList
{
public:
	char value;
	nodeList *lchild, *rchild;
	nodeList *father;
};

class Solution
{
public:
	static void printBTreeByLayers(nodeList nl[], int size)
	{
		queue<nodeList> qn;
		//vector<nodeList> vn;
		qn.push(nl[0]);
		while (!qn.empty())
		{
			if (qn.front().lchild != nullptr)
			{
				qn.push(*qn.front().lchild);
			}
			if (qn.front().rchild != nullptr)
			{
				qn.push(*qn.front().rchild);
			}
			//vn.push_back(qn.front());
			cout << qn.front().value << endl;
			qn.pop();
		}
	}
};

int main()
{
	nodeList L[10];
	const char* values = "ABCDEFGHIJ";
	//const int index[10]{ 0,1,9,2,5,6,4,3,8,7 };
	for (int i = 0; i < 10; i++)
	{
		L[i].value = values[i];
		switch (i)
		{
		case 0:
			L[i].father = nullptr;
			L[i].lchild = &L[i + 1];
			L[i].rchild = &L[i + 2];
			break;
		case 1:
			L[i].father = &L[i - 1];
			L[i].lchild = &L[i + 2];
			L[i].rchild = &L[i + 3];
			break;
		case 2:
			L[i].father = &L[i - 2];
			L[i].lchild = &L[i + 3];
			L[i].rchild = &L[i + 4];
			break;
		case 3:
			L[i].father = &L[i - 2];
			L[i].lchild = &L[i + 4];
			L[i].rchild = &L[i + 5];
			break;
		case 4:
			L[i].father = &L[i - 3];
			L[i].lchild = &L[i + 5];
			L[i].rchild = nullptr;
			break;
		case 5:
			L[i].father = &L[i - 3];
			L[i].lchild = nullptr;
			L[i].rchild = nullptr;
			break;
		case 6:
			L[i].father = &L[i - 4];
			L[i].lchild = nullptr;
			L[i].rchild = nullptr;
			break;
		case 7:
			L[i].father = &L[i - 4];
			L[i].lchild = nullptr;
			L[i].rchild = nullptr;
			break;
		case 8:
			L[i].father = &L[i - 5];
			L[i].lchild = nullptr;
			L[i].rchild = nullptr;
			break;
		case 9:
			L[i].father = &L[i - 5];
			L[i].lchild = nullptr;
			L[i].rchild = nullptr;
			break;
		default:
			break;
		}
	}
	Solution::printBTreeByLayers(L, sizeof(L) / sizeof(nodeList));

	return 0;
}
