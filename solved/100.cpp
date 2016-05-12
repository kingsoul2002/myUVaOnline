#include <iostream>
#include <stack>

using namespace std;

unsigned int n[1000000];

int main(int argc, char** argv)
{
	n[1] = 1;
	for(int idx = 2; idx < 1000000; idx++)
	{
		stack<int> pathmem;
		unsigned int cur = idx;
		int cyclemem;
		while(cur!=1) 
		{
			pathmem.push(cur);
			if(cur%2 == 0)
			{
				cur /= 2;
			}
			else
			{
				cur = 3 * cur + 1;
			}
			if(cur < 1000000)
			{
				if(n[cur] != 0)
				{
					cyclemem = n[cur];
					break;
				}
			}
		}
		while(!pathmem.empty())
		{
			cyclemem++;
			unsigned int path = pathmem.top();
			pathmem.pop();
			if(path < 1000000)
				n[path] = cyclemem;
		}
	}

	int i,j;
	while(cin >> i >> j)
	{
		cout << i << " " << j << " ";
		unsigned int maxcycle = 0;
		if(i > j)
		{
			swap(i,j);
		}
		for(int idx = i; idx <= j; idx++)
		{
			maxcycle = max(maxcycle, n[idx]);
		}
		cout << maxcycle << endl;
	}
}