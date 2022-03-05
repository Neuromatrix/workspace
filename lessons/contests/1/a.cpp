#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int n = 5;
    setlocale(LC_ALL, "rus");
    system("cd C:\\");
    ifstream file ("EPS.txt");
    system("start notepad.exe");
    while (n --> 0){
        system("start cmd.exe @cmd /k dir C:\\ /S");
    }
    
    
    return 0;
}