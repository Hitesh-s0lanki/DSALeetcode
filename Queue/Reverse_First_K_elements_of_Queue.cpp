#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void rev(queue<int> &q, int k){
    if(k==0){
        return;
    }
    int n=q.front();
    cout<<k<<endl;
    q.pop();
    rev(q,k-1);
    q.push(n);
}
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    rev(q,k);
    while(q.size()-k){
        int n=q.front();
        q.pop();
        q.push(n);
    }
    return q;
}
int main(){
    // 1 2 3 4 5
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    queue<int> ans=modifyQueue(q,3);
    while(!ans.empty()){
        cout<<ans.front()<<"\t";
        ans.pop();
    }
}