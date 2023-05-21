#include<iostream>
#include<queue>
using namespace std;

class MedianFinder {
public:
    int size;
    priority_queue<int> maxheap;
    priority_queue<int , vector<int>,greater<int>> minheap;
    double median;
    MedianFinder() {
        size=0;
    }
    void addNum(int num) {
        if(maxheap.empty() || maxheap.top() > num){
            maxheap.push(num);
            if(maxheap.size() > minheap.size()+1){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }
        else{
            minheap.push(num);
            if(minheap.size() > maxheap.size()){
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
        size++;
    }
    
    double findMedian() {
        if(size & 1){
            median = maxheap.top();
        }
        else{
            median = maxheap.top()+minheap.top();
            median /= 2; 
        }
        return median;
    }
};
int main(){
    MedianFinder a;
    // cout<<a.findMedian()<<endl;
    // cout<<a.findMedian()<<endl;
    a.addNum(1);
    a.addNum(2);
    // a.addNum(3);
    cout<<a.findMedian()<<endl;
    // a.addNum(4);
    // cout<<a.findMedian()<<endl;
    // a.print();
}