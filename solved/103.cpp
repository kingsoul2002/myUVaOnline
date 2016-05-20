#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	unsigned int k,n;
	while(cin >> k >> n)
	{
		vector<unsigned int> box[k];
		vector<unsigned int> ordering[k];
		vector<int> in_edge;
		vector<int> pathsource;
		vector<int> pathlength;
		for(int i = 0; i < k; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int di;
				cin >> di;
				box[i].push_back(di);
			}
			sort(box[i].begin(), box[i].end());
			in_edge.push_back(0);
			pathsource.push_back(-1);
			pathlength.push_back(0);
		}
		
		for(int i = 0; i < k; i++)
		{
			for(int j = i + 1; j < k; j++)
			{
				int idx;
				//check i < j
				for(idx = 0; idx < n; idx++)
				{
					if(box[i][idx] >= box[j][idx]) break;
				}
				if(idx == n)
				{
					ordering[i].push_back(j);
					in_edge[j]++;
				}
				//check j < i
				for(idx = 0; idx < n; idx++)
				{
					if(box[j][idx] >= box[i][idx]) break;
				}
				if(idx == n)
				{
					ordering[j].push_back(i);
					in_edge[i]++;
				}
			}
		}
		unsigned int max_pathlength = 0;
		unsigned int idx_max_pathlength;
		while(true)
		{
			unsigned int idx = 0;
			while(idx < k)
			{
				for(; idx < k; idx++)
				{
					if(in_edge[idx] == 0) break;
				}
				if(idx == k)
				{
					break;
				}
				else
				{
					in_edge[idx] = -1;
					if(pathsource[idx] == -1) pathlength[idx] = 1;
					else pathlength[idx] = pathlength[pathsource[idx]] + 1;
					if(pathlength[idx] > max_pathlength)
					{
						max_pathlength = pathlength[idx];
						idx_max_pathlength = idx;
					}
					for(vector<unsigned int>::iterator it = ordering[idx].begin(); it != ordering[idx].end(); ++it)
					{
						in_edge[*it]--;
						if(pathlength[idx] > pathlength[pathsource[*it]]) pathsource[*it] = idx;
					}
				}
			}
			unsigned int b;
			for(b = 0; b < k; b++)
			{
				if(in_edge[b] > -1) break;
			}
			if(b == k) break;
		}
		cout << max_pathlength << endl;
		unsigned int pathidx = idx_max_pathlength;
		vector<unsigned int> sol;
		while(pathsource[pathidx] != -1)
		{
			sol.push_back(pathidx);
			pathidx = pathsource[pathidx];
		}
		sol.push_back(pathidx);
		for(vector<unsigned int>::reverse_iterator rit = sol.rbegin(); rit != sol.rend(); ++rit)
		{
			cout << (*rit + 1) << " ";
		}
		cout << endl;
	}
	return 0;
}