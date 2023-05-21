#include<iostream>
#include<queue>
using namespace std;
int main(){
    // Max heap
    // priority_queue<int> pq;
    // pq.push(1);
    // pq.push(5);
    // pq.push(3);
    // pq.push(0);

    // cout<<"The highest element is "<<pq.top()<<endl;
    // pq.pop();
    // cout<<"The highest element is "<<pq.top()<<endl;
    // cout<<"the size of queue "<<pq.size()<<endl;
    // pq.empty() ? cout<<"Is EMpty":cout<<"Not";

    // Minheap
    priority_queue<int , vector<int> ,greater<int> > minheap;
    minheap.push(10);
    minheap.push(1);
    minheap.push(2);
    minheap.push(9);

    cout<<"The Smallest element is "<<minheap.top()<<endl; 
    minheap.pop();
    cout<<"The Smallest element is "<<minheap.top()<<endl;

}
