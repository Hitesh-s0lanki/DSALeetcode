#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr,int n ,int i){
    int index = i;
    int leftIndex = 2*i + 1 ;//as indexing is 0
    int rightIndex = 2*i + 2 ;//as indexing is 0

    if(leftIndex < n && arr[index] > arr[leftIndex]){
        index = leftIndex;
    }
    if(rightIndex < n && arr[index] > arr[rightIndex]){
        index = rightIndex;
    }

    if(index != i){
        swap(arr[index],arr[i]);
        heapify(arr,n,index);
    } 
    return;
}


vector<int> buildMinHeap(vector<int> &arr){
    //indexing is from 0
    int n = arr.size();
    for(int i = n/2 - 1 ; i >= 0 ;i--){
        heapify(arr,n,i);
    }
    return arr;
}
int main(){
    vector<int> arr= {9,3,2,6,7};
    vector<int> ans = buildMinHeap(arr);
    for(auto i : ans){
        cout<<i<<"\t";
    }
}