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
using namespace std;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
enum State {EMPTY = 0, FILLED = 1, DELETED = -1};

struct Cell
{
	State s;
	int val=INT_MIN;
};

struct OpenHT
{
	Cell * table;
	int m;
	int size;
};

void makeHT (OpenHT & t, int n)
{
	t.table = new Cell[n];
	for (int i = 0 ; i < n; i ++) t.table[i].s = EMPTY;
	t.m = n;
	t.size = 0;
	return;
}

int h_linal(int x, int mod)
{
	return ((97 * x + 37) % 1000000009) % mod;
}

int h_lin (int x , int i, int mod)
{
	return (h_linal(x,mod)+ i * 37) % mod;
}

int h_quad(int x , int i, int mod)
{
	return (h_linal(x, mod)+ i * 37 + i*i*17) % mod;
}

void PrintHT_deb(OpenHT& t)
{
	for (int i = 0; i < t.m; i++)
	{
		if (t.table[i].val != INT_MIN)
			cout << t.table[i].val << endl;
		else
			if (t.table[i].s == EMPTY)
				cout << "emp" << endl;
			if (t.table[i].s == DELETED)
				cout << "del" << endl;
	}
	return;
}
void insert(OpenHT & t, int key )
{
	PrintHT_deb(t);
	
	int code = h_lin(key,0,t.m);
	int i = 1;
	while (t.table[code].s != EMPTY)
	{
		code = h_lin(key,i,t.m);
		i++;
	}
	t.table[code].val = key;
	t.table[code].s = FILLED;
	t.size++;
	return;
}


int find(OpenHT & t, int key )
{

	int code = h_lin(key,0,t.m);
	
	int i = 1;
	while (t.table[code].val != key)
	{
		if (t.table[code].s == EMPTY) break;
		code = h_lin(key, i, t.m);
		if (t.table[code].val == key && t.table[code].s == FILLED) return code;
		i++;
	}
	return -1;
}
void remove (OpenHT & t, int key )
{
	int code = h_lin(key, 0, t.m);

	int i = 1;
	while (t.table[code].val != key)
	{
		code = h_lin(key, i, t.m);
		if (t.table[code].val == key && t.table[code].s == FILLED) break;
		i++;
	}
	if (code != -1 && t.table[code].s==FILLED) 
	{
		if (t.table[h_lin(key, i + 1, t.m)].s == EMPTY) {
			t.table[h_lin(key, i , t.m)].s == EMPTY;
			t.table[h_lin(key, i, t.m)].val == INT_MIN;
		}
		else if (t.table[h_lin(key, i + 1, t.m)].s == FILLED) 
		{
			t.table[h_lin(key, i, t.m)].val = t.table[h_lin(key, i + 1, t.m)].val;
			t.table[h_lin(key, i + 1, t.m)].s = DELETED;
			t.table[h_lin(key, i, t.m)].val == INT_MIN;
		}

		t.table[code].s = DELETED;
		t.table[code].val = INT_MIN;
		t.size--;
	}
	return;
}


void PrintHT(OpenHT& t)
{
	for (int i = 0; i < t.m; i++)
	{
		if (t.table[i].val != INT_MIN && t.table[i].s==FILLED)
			cout<<t.table[i].val << endl;
	}
	return;
}
int empty(OpenHT& t) {
	if (t.size == 0) return -1;
	else return 1;
}














