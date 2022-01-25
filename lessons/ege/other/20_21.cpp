#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <queue>
#include <algorithm>

using namespace std;

int h1(int x) {return x*2;}
int h2(int x) {return x+1;}
int neg_max(vector<int> V)
{
	int m;
	for (auto x : V) 
	{
		if (x<0) m = x;
	}
	return m;
}

int main()
{
	const int N = 107;
	const int F = 13;
	int D [N][N];
	for (int i = N-1; i>=0; i --)
		for (int j = N-1; j>=0; j--)
		{
			if (i+j >= N) 
			{
				D[i][j] = 0;
				continue;
			}
			vector <int> V1 = {h1(i)+j, h2(i)+j,i+h1(j),i+h2(j)};
			sort(V1.begin(),V1.end());
			if (V1[3] >=N) 
			{
				D[i][j]=1;
				continue;
			}
			vector <int> V2 = {D[h1(i)][j],D[h2(i)][j],D[i][h1(j)],D[i][h2(j)]};
			sort(V2.begin(),V2.end());
			if (V2[0]<0) D[i][j] = -neg_max(V2)+1;
			else D[i][j] = - V2[3];
			
		}
	for (int i =0; i < N; i++)
	{
		cout<<i<<' '<<D[F][i]<<endl;
	}
	return 0;
}






