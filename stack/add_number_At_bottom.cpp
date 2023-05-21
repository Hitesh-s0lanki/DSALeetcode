#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void addNumberAtBottom(stack<int> &s,int size,int n){
    if(s.empty()){
        s.push(n);
        return;
    }
    int num=s.top();
    s.pop();
    addNumberAtBottom(s,size-1,n);
    s.push(num);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    addNumberAtBottom(s,s.size(),0);
    vector<int> a;
    while(!s.empty()){
        a.push_back(s.top());
        s.pop();
    }
    for(int i=a.size()-1;i>=0;i--){
        cout<<a[i]<<"\t";
    }
}