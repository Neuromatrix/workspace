#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <climits>
#include <complex>
#include <list>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;
inline void prepare()
{
	freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
	freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}

int binPow(int a, int pow)
{
	if (a == 1 || pow == 0)
		return 1;
	else if (pow == 1)
		return a;
	else{
		int part = binPow(a, pow >> 1);
		if (pow & 1)
			return (((part * part)) * a);
		else
			return (part * part);
	}
}

int stringToInt(string a)
{
	int max_pow = a.size() - 1;
	int res = 0;
	for (int i = 0; i < a.size(); i++)
	{
		res += (a[i] - '0') * (binPow(10, max_pow));
		max_pow--;
	}
	return res;
}
