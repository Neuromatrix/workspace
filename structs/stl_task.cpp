#include <bits\stdc++.h>
//#include <C:\Users\grivi\source\repos\Info science\hash_int.cpp>

using namespace std;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
int binPow(int a, int pow)
{
	if (a == 1 || pow == 0) {
		return 1;
	}
	else if (pow == 1) {
		return a;
	}
	else {
		int part = binPow(a, pow >> 1);
		if (pow & 1) {
			return (((part * part)) * a);
		}
		else {
			return (part * part);
		}
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

void ug_chislo_1()
{
	int n, ups, max_pow, flag = 0;
	string command;

	set <int> yes;
	set <int> ins;
	set <int> no;
	set <int> tmp;
	set <int> zapr;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		yes.insert(i);
	}
	string g;
	vector <int> h;
	while (true)
	{
		cin >> g;
		if (g == "HELP")
			break;
		else if (g[0] >= '0' && g[0] <= '9')
		{
			h.push_back(stringToInt(g));
		}

		else if (g == "NO")
		{
			for (int i = 0; i < h.size(); i++)
			{
				no.insert(h[i]);
			}

			h.clear();
		}
		else if (g == "YES")
		{

			for (int i = 0; i < h.size(); i++)
			{
				zapr.insert(h[i]);
			}


			cout << endl;
			set_intersection(zapr.begin(), zapr.end(), yes.begin(), yes.end(), inserter(ins, ins.begin()));
			yes = ins;

			ins.clear();
			zapr.clear();
			h.clear();
		}
	}
	set_difference(yes.begin(), yes.end(), no.begin(), no.end(), inserter(tmp, tmp.begin()));
	for (auto a : tmp) cout << a << " ";
}
 
void  easy_dec()
{
	int k;
	string h;
	list <int> li;
	while (true)
	{
		cin >> h;
		if (h == "exit")
		{
			cout << "bye" << endl;
			return;
		}
		else if (h == "size")
		{
			cout << li.size() << endl;
		}
		else if (h == "clear")
		{
			li.resize(0);
			cout << "ok" << endl;
		}
		else if (h == "front")
		{
			cout << li.front() << endl;
		}
		else if (h == "back")
		{
			cout << li.back() << endl;
		}
		else if (h == "pop_front")
		{
			cout << li.front() << endl;
			li.pop_front();
		}
		else if (h == "push_front")
		{
			cin >> k;
			cout << "ok" << endl;
			li.push_front(k);
		}
		else if (h == "pop_back")
		{
			cout << li.back() << endl;
			li.pop_back();
		}
		else if (h == "push_back")
		{
			cin >> k;
			cout << "ok" << endl;
			li.push_back(k);
		}
	}
	return;
}

void easy_stack()
{
	int k;
	string h;
	stack <int> li;
	while (true)
	{
		cin >> h;
		if (h == "exit")
		{
			cout << "bye" << endl;
			return;
		}
		else if (h == "size")
		{
			cout << li.size() << endl;
		}
		else if (h == "clear")
		{
			while (!li.empty())
				li.pop();
			cout << "ok" << endl;
		}

		else if (h == "back")
		{
			if (li.size() == 0) cout << "error" << endl;
			else
				cout << li.top() << endl;
		}

		else if (h == "push")
		{
			cin >> k;
			cout << "ok" << endl;
			li.push(k);
		}
		else if (h == "pop")
		{
			if (li.size() == 0) cout << "error" << endl;
			else {
				cout << li.top() << endl;
				li.pop();
			}
		}

	}
	return;
}

void easy_queue()
{
	int k;
	string h;
	queue <int> li;
	while (true)
	{
		cin >> h;
		if (h == "exit")
		{
			cout << "bye" << endl;
			return;
		}
		else if (h == "size")
		{
			cout << li.size() << endl;
		}
		else if (h == "clear")
		{
			while (!li.empty())
				li.pop();
			cout << "ok" << endl;
		}

		else if (h == "front")
		{
			if (li.size() == 0) cout << "error" << endl;
			else
				cout << li.front() << endl;
		}

		else if (h == "push")
		{
			cin >> k;
			cout << "ok" << endl;
			li.push(k);
		}
		else if (h == "pop")
		{
			if (li.size() == 0) cout << "error" << endl;
			else {
				cout << li.front() << endl;
				li.pop();
			}
		}

	}
	return;
}

void ferzi()
{
	int temp;
	bool cross = false;
	vector <int> x, y;
	for (int i = 1; i <= 8; i++) {
		cin >> temp;
		x.push_back(temp);
		cin >> temp;
		y.push_back(temp);
	}
	for (int i = 0; i < x.size() - 1; i++) {
		for (int j = i + 1; j < x.size(); j++) {
			if (abs(int)(x[i] - x[j]) == abs(y[i] - y[j]) || x[i] == x[j] || y[i] == y[j]) {
				cross = true;
			}
		}
	}
	if (cross) cout << "YES";
	else cout << "NO";
	return;
}

void priority_q()
{
	priority_queue <int> kucha;
	int size, m;
	int com, num;
	cin >> size >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> com;
		if (com == 1)
		{
			if (kucha.size() == 0) {cout << "-1"; continue;}
			else {
				kucha.pop();
			}
		}
	}
}

void ug_chislo_2()
{
	int n, ea = 0, x;
	set <int> pool;
	cin >> n;
	char lo;
	set <int> intersection;
	set <int> difference;
	vector <vector<int>> matrix;
	matrix.push_back(vector <int>());
	vector <string> answers;

	for (int i = 1; i <= n; i++) {
		pool.insert(i);
	}
	lo = getchar();
	while (1)
	{
		if (cin.peek() == 'H') {
			break;
		}
		else if (cin.peek() == '\n')
		{
			lo = getchar();
			ea++;
			matrix.push_back(vector <int>());
		}
		else {
			cin >> x;
			matrix[ea].push_back(x);
		}

	}
	int msize = matrix.size() - 1;
	for (int i = 0; i < msize; i++)
	{
		set_intersection(pool.begin(), pool.end(), matrix[i].begin(), matrix[i].end(), inserter(intersection, intersection.begin()));
		set_difference(pool.begin(), pool.end(), matrix[i].begin(), matrix[i].end(), inserter(difference, difference.begin()));
		if (intersection.size() == difference.size())
		{
			pool = difference;
			answers.push_back("NO");

		}
		else if (intersection.size() < difference.size())
		{
			pool = difference;
			answers.push_back("NO");


		}
		else if (intersection.size() > difference.size())
		{
			pool = intersection;
			answers.push_back("YES");

		}
		difference.clear();
		intersection.clear();
	}
	for (const auto& a : answers) cout << a << endl;
	for (const auto& a : pool) cout << a << " ";



}

void elections_1()
{
	map <string, int> candidats;
	string cand;
	int num;
	int counter = 0;
	while (cin >> cand >> num) {
		candidats[cand] += num;

	}
	for (const auto& a : candidats) {
		cout << a.first << " " << a.second << endl;
	}
	return;
}

void fruit()
{
	map <string, int> fruits;
	string fr;
	int min = INT_MIN;
	int counter = 0;
	string min_str;
	while (cin >> fr) {
		fruits[fr] += 1;
	}
	for (const auto& a : fruits) {
		if (a.second > min) {
			min = a.second;
			min_str = a.first;
		}
		else if (a.second == min) {
			if (a.first < min_str)
				min_str = a.first;
		}
	}
	cout << min_str;
	return;
}

void bunks()
{
	int counter = 0;
	map <string, int> accounts;
	string command;
	string name, fename;
	double n;
	while (cin >> command) {
		if (command == "DEPOSIT") {
			cin >> name >> n;
			accounts[name] += n;
		}
		else if (command == "WITHDRAW") {
			cin >> name >> n;
			accounts[name] -= n;
		}
		else if (command == "BALANCE") {
			cin >> name;
			if (accounts.find(name) != accounts.end())
				cout << accounts[name] << endl;
			else
				cout << "ERROR" << endl;
		}
		else if (command == "INCOME") {
			cin >> n;
			for (auto& a : accounts) {
				if (a.second > 0)
					a.second = a.second * (1 + n / 100);
				else continue;
			}
		}
		else if (command == "TRANSFER") {
			cin >> name >> fename >> n;
			accounts[name] -= n;
			accounts[fename] += n;
		}
	}
	return;
}

void elections_2()
{
	int counter = 0;
	map <string, map<string, int>> states;
	map <string, int> res;
	map <string, int> people;
	vector <pair<string, int>> x;
	int n, num, max_voice = INT_MIN;
	string a, b, winner, u;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> u >> num;
		people[u] = num;
	}
	while (cin >> a) {
		//if (a == "00") break;
		cin >> b;
		states[a][b]++;
		counter++;
		res[b] = 0;
	}
	/*for (const auto& t : states)
	{
		cout << t.first << endl;
		for (const auto& b : t.second)
		{
			cout << b.first << " " << b.second<< endl;
		}
	}*/
	cout << endl;
	for (const auto& t : states) {
		for (const auto& b : t.second) {
			if (b.second > max_voice) {
				max_voice = b.second;
				winner = b.first;
			}
			else if (b.second == max_voice) {
				if (b.first < winner) winner = b.first;
			}
		}
		res[winner] = people[t.first];
		max_voice = 0;
		winner.clear();
	}
	x = reverse_map_print(res);
	for (const auto& y : x) cout << y.first << " " << y.second << endl;
}

void dict()
{
	int n;
	vector <string> _dict_;
	string a, word;
	bool tire = false;
	bool zap = false;
	map <string, vector<string>> dict;
	map <string, vector <string>> trans_dict;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		while (true) {
			cin >> a;
			if (a == "-") {

			}
		}
	}
	for (const auto& a : dict) {
		for (const auto& b : a.second) {
			cout << b << " ";
		}
		cout << endl;
	}
	return;
}