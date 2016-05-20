#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	unsigned int n;
	cin >> n;
	stack<unsigned int> block[n];
	unsigned int pos[n];
	for(int i = 0; i < n; i++)
	{
		block[i].push(i);
		pos[i] = i;
	}
	string cmd;
	while(1)
	{
		cin >> cmd;
		if(cmd == "move")
		{
			unsigned int a, b;
			string cmdtype;
			cin >> a;
			cin >> cmdtype;
			cin >> b;
			if(pos[a] != pos[b])
			{
				if(cmdtype == "onto")
				{
					while(block[pos[a]].top() != a)
					{
						unsigned int topblock = block[pos[a]].top();
						block[pos[a]].pop();
						block[topblock].push(topblock);
						pos[topblock] = topblock;
					}
					while(block[pos[b]].top() != b)
					{
						unsigned int topblock = block[pos[b]].top();
						block[pos[b]].pop();
						block[topblock].push(topblock);
						pos[topblock] = topblock;
					}
					block[pos[a]].pop();
					block[pos[b]].push(a);
					pos[a] = pos[b]; 
				}
				else if(cmdtype == "over")
				{
					while(block[pos[a]].top() != a)
					{
						unsigned int topblock = block[pos[a]].top();
						block[pos[a]].pop();
						block[topblock].push(topblock);
						pos[topblock] = topblock;
					}
					block[pos[a]].pop();
					block[pos[b]].push(a);
					pos[a] = pos[b];	
				}
			}
		}
		else if(cmd == "pile")
		{
			unsigned int a, b;
			string cmdtype;
			cin >> a;
			cin >> cmdtype;
			cin >> b;
			if(pos[a] != pos[b])
			{
				if(cmdtype == "onto")
				{
					stack<unsigned int> blockpile;
					while(block[pos[a]].top() != a)
					{
						unsigned int topblock = block[pos[a]].top();
						block[pos[a]].pop();
						blockpile.push(topblock);
					}
					while(block[pos[b]].top() != b)
					{
						unsigned int topblock = block[pos[b]].top();
						block[pos[b]].pop();
						block[topblock].push(topblock);
						pos[topblock] = topblock;
					}
					block[pos[a]].pop();
					block[pos[b]].push(a);
					pos[a] = pos[b];
					while(!blockpile.empty())
					{
						unsigned int topblock = blockpile.top();
						blockpile.pop();
						block[pos[b]].push(topblock);
						pos[topblock] = pos[b];
					}
				}
				else if(cmdtype == "over")
				{
					stack<unsigned int> blockpile;
					while(block[pos[a]].top() != a)
					{
						unsigned int topblock = block[pos[a]].top();
						block[pos[a]].pop();
						blockpile.push(topblock);
					}
					block[pos[a]].pop();
					block[pos[b]].push(a);
					pos[a] = pos[b];
					while(!blockpile.empty())
					{
						unsigned int topblock = blockpile.top();
						blockpile.pop();
						block[pos[b]].push(topblock);
						pos[topblock] = pos[b];
					}
				}
			}
		}
		else if(cmd == "quit")
		{
			break;
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << i << ":";
		stack<unsigned int> printtemp;
		while(!block[i].empty())
		{
			printtemp.push(block[i].top());
			block[i].pop();
		}
		while(!printtemp.empty())
		{
			cout << " " << printtemp.top();
			printtemp.pop();
		}
		cout << endl;
	}
	return 0;
}