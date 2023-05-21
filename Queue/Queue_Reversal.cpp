#include <iostream>
#include<queue>
using namespace std;
//can do with stack
void recursive(queue<int> &q){
     if(q.empty()){
    return ;
   }
   int n=q.front();
   q.pop();
   recursive(q);
   q.push(n);
}
queue<int> rev(queue<int> q){
  recursive(q);
  return q;
}

int main()
{
    // 4 3 1 10 2 6
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    queue<int> a=rev(q);
    while(!a.empty()){
        cout<<a.front()<<"\t";
        a.pop();
    }
}