#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
//#include <C:\Users\grivi\source\repos\Info science\RB_Tree.cpp>
using namespace std;


int main() {
    
    multiset<long> numbers;
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        long number;
        cin >> number;
        numbers.insert(number);
    }
    double cost = 0;
    while (numbers.size() > 1) {
        auto first = numbers.begin(),
            second = next(first),
            third = next(second);
        long sum = *first + *second;
        numbers.erase(first, third);
        cost += sum;
        numbers.insert(sum);
    }
    cout << setprecision(2) << std::fixed << cost * 0.05;
}