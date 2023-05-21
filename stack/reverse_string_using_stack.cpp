#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s="hitesh";
    stack<char> a;
    int i=0;
    while(i<s.length()){
        a.push(s.at(i));
        i++;
    }
    string str="";
    while(!a.empty()){
        str.push_back(a.top());
        a.pop();
    }
    cout<<"the reverse of string is "<<str;
}