#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
void print(stack<int> s){
    vector<int> a;
    while(!s.empty()){
        a.push_back(s.top());
        s.pop();
    }
    reverse(a.begin(),a.end());
    int i=0;
    while(i<a.size()){
        cout<<a[i++]<<"\t";
    }
    cout<<endl;
}
void placeSorted(stack<int> &s,int n){
    if(s.empty()){
        s.push(n);
        return;
    }
    int num=s.top();
    if(num<n){
        s.push(n);
        return;
    }
    s.pop();
    placeSorted(s,n);
    s.push(num);
}
void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num=s.top();
    s.pop();
    sortStack(s);
    placeSorted(s,num);
}
int main(){
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(1);
    s.push(2);
    s.push(0);
    print(s);
    sortStack(s);
    print(s);
}