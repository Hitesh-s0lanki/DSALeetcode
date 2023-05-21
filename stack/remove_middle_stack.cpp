#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void removeMiddle(stack<int> &s,int size){
    int num=s.top();
    s.pop();
    if(size==0){
        return;
    }
    removeMiddle(s,size-1);
    s.push(num);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    removeMiddle(s,s.size()/2);
    int n=s.size();
    vector<int> a;
    for(int i=0;i<n;i++){
        a.push_back(s.top());
        s.pop();
    }
    for(int i=a.size()-1;i>=0;i--){
        cout<<a[i]<<"\t";
    }
}