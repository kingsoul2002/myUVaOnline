#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	unsigned int grass[9];
	while(cin >> grass[0] >> grass[1] >> grass[2] >> grass[3] >>  grass[4] >> grass[5]>> grass[6] >> grass[7] >> grass[8])
	{
		unsigned int mingrass = -1;
		string mintype;
		unsigned int sumgrass = 0;
		for(int i = 0; i < 9; i++) 
		{
			sumgrass += grass[i];
		}
		if(mingrass > sumgrass - grass[0+0] - grass[3+2] - grass[6+1])//BCG
		{
			mingrass = sumgrass - grass[0+0] - grass[3+2] - grass[6+1];
			mintype = "BCG";
		}
		if(mingrass > sumgrass - grass[0+0] - grass[3+1] - grass[6+2])//BGC
		{
			mingrass = sumgrass - grass[0+0] - grass[3+1] - grass[6+2];
			mintype = "BGC";
		}
		if(mingrass > sumgrass - grass[0+2] - grass[3+0] - grass[6+1])//CBG
		{
			mingrass = sumgrass - grass[0+2] - grass[3+0] - grass[6+1];
			mintype = "CBG";
		}
		if(mingrass > sumgrass - grass[0+2] - grass[3+1] - grass[6+0])//CGB
		{
			mingrass = sumgrass - grass[0+2] - grass[3+1] - grass[6+0];
			mintype = "CGB";
		}
		if(mingrass > sumgrass - grass[0+1] - grass[3+0] - grass[6+2])//GBC
		{
			mingrass = sumgrass - grass[0+1] - grass[3+0] - grass[6+2];
			mintype = "GBC";
		}
		if(mingrass > sumgrass - grass[0+1] - grass[3+2] - grass[6+0])//GCB
		{
			mingrass = sumgrass - grass[0+1] - grass[3+2] - grass[6+0];
			mintype = "GCB";
		}
		cout << mintype << " " << mingrass << endl;
	}
	return 0;
}