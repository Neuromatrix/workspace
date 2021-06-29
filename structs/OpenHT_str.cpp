#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cctype>
using namespace std;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
enum State {EMPTY = 0, FILLED = 1, DELETED = -1};

struct Cell
{
	State s;
	string val="";
};

struct OpenHT
{
	Cell * table;
	int m;
	int size;
};

void makeHT (OpenHT & t, long long n)
{
	t.table = new Cell[n];
	for (long long i = 0 ; i < n; i ++) t.table[i].s = EMPTY;
	t.m = n;
	t.size = 0;
	return;
}

int h_linal(int x, int mod)
{
	return ((97 * x + 37) % 1000000009) % mod;
}
long long num;
long long a;
int per = 4;
int h_lin (string key,int k, int mod)
{
	long long u = 1;

	for (int i = 0; i < key.length(); i++)
	{
		for (int j = 0; j < i; j++) u *= per;
		num += key[i] * u;

	}
	a = (num+k*37) % mod;

	num = 0;
	return a;
}

int h_quad(int x , int i, int mod)
{
	return (h_linal(x, mod)+ i * 37 + i*i*17) % mod;
}

void PrintHT_deb(OpenHT& t)
{
	for (int i = 0; i < t.m; i++)
	{
		if (t.table[i].val != "")
			cout << t.table[i].val << endl;
		else
			if (t.table[i].s == EMPTY)
				cout << "emp" << endl;
			if (t.table[i].s == DELETED)
				cout << "del" << endl;
	}
	return;
}
void insert(OpenHT & t, string key )
{
	
	
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


int find(OpenHT & t, string key )
{

	int code = h_lin(key, 0, t.m);
	int i = 1;
	while (t.table[code].s == DELETED || t.table[code].s == FILLED &&t.table[code].val != key)
	{
		code = h_lin(key, i, t.m);
		i++;
	}
	if (t.table[code].val == key && t.table[code].s == FILLED) return code;
	else return -1;
}
void remove (OpenHT & t, string key )
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
			t.table[h_lin(key, i , t.m)].s = EMPTY;
			t.table[h_lin(key, i, t.m)].val = "";
		}
		else if (t.table[h_lin(key, i + 1, t.m)].s == FILLED) 
		{
			t.table[h_lin(key, i, t.m)].val = t.table[h_lin(key, i + 1, t.m)].val;
			t.table[h_lin(key, i + 1, t.m)].s = DELETED;
			t.table[h_lin(key, i, t.m)].val = "";
		}

		t.table[code].s = DELETED;
		t.table[code].val = "";
		t.size--;
	}
	return;
}


void PrintHT(OpenHT& t)
{
	for (int i = 0; i < t.m; i++)
	{
		if (t.table[i].val != "" && t.table[i].s==FILLED)
			cout<<t.table[i].val << endl;
	}
	return;
}
int empty(OpenHT& t) {
	if (t.size == 0) return -1;
	else return 1;
}

int main()
{
	OpenHT t;
	int n;
	string command;
	string str;
	int counter = 0;
	makeHT(t, 10000000);
	while (true)
	{
		cin >> command;
		if (command == "#")
			break;
		else if (command == "+")
		{
			cin >> str;
			if (find(t, str) == -1)
			{

				insert(t, str);
			}

		}
		else if (command == "?")
		{
			cin >> str;
			if (find(t, str) == -1) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
		else if (command == "-")
		{
			cin >> str;
			remove(t, str);

		}
	}

	 

	return 0;

}














