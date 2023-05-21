#include<iostream>
#include<queue>
using namespace std;

long long minCost(long long arr[], long long n) {
        //puting the value in pq
        priority_queue<long long,vector<long long> , greater<long long> > pq;
        for(long long i=0;i<n;i++){
            pq.push(arr[i]);
        }
        long long cost =0;
        //algo
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();

           long long sum=a+b;
            pq.push(sum);
            cost+=sum;
        }
    return cost;
}
int main(){
    long long arr[]={4, 3, 2, 6};

    cout<<minCost(arr,4);
}