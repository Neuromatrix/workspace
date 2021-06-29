#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <numeric>
#include <queue>
#include <stack>

using namespace std;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
int main()
{
	int n, max_price;
	int sum, max_paper, best = -1;
	vector <int> source; // number of books
	vector <int> price_books;
	vector <int > subset;
	vector <int > subset_price;
	cin >> n >> max_price;
	int hh;

	for (int i = 0; i < n; i++) {
		cin >> hh;
		price_books.push_back(hh);
	}
	for (int i = 0; i < n; i++) {
		cin >> hh;
		source.push_back(hh);
	}
	for (int i = 0; i < pow(2, n); i++)
	{
		subset.resize(0);
		subset_price.resize(0);
		int d = i, k = 0;
		sum = 0; max_paper = 0;
		while (d > 0)
		{
			if (d % 2 == 1) {
				subset.push_back(source[k]);
				subset_price.push_back(price_books[k]);
			}
			k++;
			d /= 2;
		}
		for (int j = 0; j < subset.size(); j++) {
			sum += subset_price[j];
			max_paper += subset[j];
		}
		if (sum <= max_price) {
			if (max_paper >= best)
				best = max_paper;

		}
		//Тут будет подмножество в subset
	}
	cout << best;
}













