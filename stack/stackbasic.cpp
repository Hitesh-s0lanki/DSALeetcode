#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.pop();
    cout<<"peek element is "<<a.top()<<endl;
    cout<<"size of element is "<<a.size()<<endl;
    if(a.empty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
}