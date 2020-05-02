#include <iostream>

using namespace std;

class Solution
{
public:
	static void replaceSpace(char *a)
	{
		int length = strlen(a);
		int count = 0;
		for (int i = 0; i < length; i++)
		{
			if (a[i] == ' ')
			{
				count++;
			}
		}
		int length2 = length + count * 2;
		for (int i = length2-1, j = length-1; i >= 0 && j >= 0; j--) 
		{
			if (a[j] == ' ')
			{
				a[i] = '0';
				a[i - 1] = '2';
				a[i - 2] = '%';
				i -= 3;
			}
			else
			{
				a[i] = a[j];
				i--;
			}
		}
		a[length2] = '\0';
	}
};

int main()
{
    //std::cout << "Hello World!\n"; 
	char a[100];
	cin.getline(a, 99);
	Solution::replaceSpace(a);
	cout << a << endl;
}

