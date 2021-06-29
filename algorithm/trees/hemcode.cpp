#include <bits\stdc++.h>
using namespace std;
inline void prepare(){
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\input.txt", "r", stdin);
    freopen("C:\\Users\\grivi\\vscodes\\.vscode\\output.txt", "w", stdout);
}
struct Report {
	string report;
	vector <bool> base;
	int mistake;
};
int binPow(int a, int pow){
	if (a == 1 || pow == 0) {
		return 1;
	} else if (pow == 1) {
		return a;
	} else {
		int part = binPow(a, pow >> 1);
		if (pow & 1) {
			return (((part * part)) * a);
		} else {
			return (part * part);
		}
	}
}

int stringToInt(string a){
	int max_pow = a.size() - 1;
	int res = 0;
	for (int i = 0; i < a.size(); i++){
		res += (a[i] - '0') * (binPow(10, max_pow));
		max_pow--;
	}
	return res;
}

int BinToInt(vector <bool> a){
	int max_pow = 0;
	int res = 0;
	for (int i = 0; i < a.size(); i++){
		res += a[i] * binPow(2, max_pow);
		max_pow++;
	}
	return res;
}
int fast_powtw(int k) {
	if (k == 0) return 1;
	else if (k == 1) return 2;
	else return 2 << (k - 1);
}
vector <bool> add_byte(vector <bool> data){
	if (data.size() == 0) return data;
	int sum=0;
	for (int i = 0; i < data.size(); i++) {
		sum += data[i];
	}
	data.push_back(sum % 2);
	return data;
}

vector <bool> hem_code(vector <bool> data)
{
	int size = logb(data.size())+1;
	int size_x = data.size() + size;
	int k, sum;
	if (logb(size_x)+1 > size) {size_x++; size++;}
	vector <bool> heming(size_x+1);
	heming[0]=0;
	for (int i = size_x; i > 0; i--){
		if (!(i && !(i & (i - 1)))) {
			heming[i] = data.back();
			data.pop_back();
		}
	}
	for (int j = 1; j <= size; j++){
	    k = j - 1;
		sum = 0;
		for (int i = 1; i <= size_x; i++) {
			if ((1 << k)&i)
				sum += heming[i];
		}
		if (k == 0) heming[1] = sum % 2;
		else if (k == 1) heming[2] = sum % 2;
		else heming[2 << (k - 1)] = sum % 2;
	}
	heming.erase(heming.begin());
	return heming;
}


Report hem_decodes(vector <bool> data, int report)//1 ошибка
{
	int size = logb(data.size()) + 1;
	int size_x = data.size();
	int sum,k,y;
	Report ans;
	for (int j = 0; j < size; j++) {
		sum = 0;
		for (int i = 0; i <size_x; i++) {
			if ((1 << j) & (i+1))
				sum += data[i];
		}
		ans.base.push_back((sum) % 2);
	}
	y = BinToInt(ans.base);
	if (y == 0) {
		if (report == 0) {
			ans.report = "success";
			ans.base = data;
			ans.mistake = report;
			return ans;
		}
		else if (report !=0) {
			ans.report = "one error,fixed";
			ans.base = data;
			ans.mistake = report;
			return ans;
		}
	}
	else {
		if (report == 0) {
			ans.mistake = y;
			data[y-1] = (data[y-1] + 1) % 2;
			ans.base = data;
			return ans;
		}
		else if (report != 0) {
			ans.report = "Many errors";
			return ans;
		}
	}
	return ans;

}
Report hem_secded(vector <bool> data) //находит 2 ошибки
{
	int size = logb(data.size()) + 1;
	int size_x = data.size(),i,sums=0,ep;
	int sum_ded_pre=0, sum_ded_pos=0,ded_t,ded_pre,ded_pos;
	vector <bool> bitto;
	vector <bool> reserve;
	Report ans;
	for (int j = 0; j < size_x; j++) {
		i = j + 1;
		if (!(i && !(i & (i - 1)))) {
			reserve.push_back(data[j]);
		}
	}
	reserve = hem_code(reserve);
	vector <bool> hems = hem_code(reserve);
	for (int i = 0; i < data.size(); i++) {
		if ((i+1) && !((i+1) & ((i+1) - 1))) {
			bitto.push_back((data[i] + reserve[i]) % 2);
			sum_ded_pre += data[i];
			sum_ded_pos += reserve[i];
		}
	}
	ded_pre = (sum_ded_pre % 2);
	ded_pos = (sum_ded_pos % 2);
	ep = BinToInt(bitto);
	ded_t = (ded_pre + ded_pos) % 2;
	if (ep && !(ep & (ep - 1))) ded_t = 0;
	if (ep == 0 && ded_t == 0){
		ans.base = data;
		ans.mistake = -1;
		ans.report = "no mistakes";
	}
	else if (ep != 0 && ded_t == 0) {
		data[ep - 1] = (data[ep - 1] + 1) % 2;
		ans.mistake = ep;
		ans.report = "one err";
		ans.base = data;
	}
	else if (ep != 0 && ded_t != 0){ 
		ans.report = "o lot of mistakes";
		ans.mistake = -2;
		ans.base = data;
	}
	return ans;
}
int main()
{

	prepare();
	size_t n;
	int ent;
	string command;
	cin >> n;
	Report gh;
	vector <bool> data(n), ans;
	for (int i = 0; i < n; i++) { cin >> ent; data[i] = ent;}
	cin >> command;
	if (command == "code")
	{
		ans=hem_code(data);
		for (const auto & a: ans) cout << a << " ";
		cout << endl;
	}
	else if ( command=="decode"){
		gh=hem_secded(data);
		cout << gh.report<<endl;
		cout << gh.mistake<<endl;
		for (const auto & a: gh.base) cout << a << " ";
		cout << endl;
	}
	return 0;
}



