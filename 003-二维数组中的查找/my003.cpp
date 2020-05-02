
// findOffer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	static bool Find1(vector<vector<int>> array, int n) {
		//int row(0), col(0);

		for (int i = 0; i < array.size(); i++)
		{
			for (int j = 0; j < array[0].size(); j++)
			{
				if (array[i][j]==n)
				{
					return true;
				}
			}
		}
		return false;
	}
	static bool Find2(vector<vector<int>> array, int n) {
		int row = array.size();
		int col = array[0].size();
		for (int i = 0, j = col - 1; i < row && j >= 0;) {
			if (array[i][j] == n)
				return true;
			else if (array[i][j] > n)
				j--;
			else
				i++;
		}
		return false;
	}
};

int main()
{
    //std::cout << "Hello World!\n"; 
	vector<vector<int>> array = { {1,2,8,9},{2,4,9,12},
	{4,7,10,13},{6,8,11,15} };
	int n;
	cin >> n;
	cout << Solution::Find1(array, n) << endl;
	cout << Solution::Find2(array, n) << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
