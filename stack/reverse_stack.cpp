#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &s,int n){
    if(s.empty()){
        s.push(n);
        return;
    }
    int num=s.top();
    s.pop();
    insertAtBottom(s,n);
    s.push(num);
}
void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num=s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,num);

}
void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<"\t";
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    print(s);
    reverse(s);
    print(s);
}