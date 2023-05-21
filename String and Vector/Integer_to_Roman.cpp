#include<iostream>
#include<map>
using namespace std;
string intToRoman(int num) {
        map<char,int> roman={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},
X             10
L             50
C             100
D             500
M             1000};
    }
int main(){
    int num=3;
    cout<<intToRoman(num);
}