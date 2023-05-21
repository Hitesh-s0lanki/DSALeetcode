#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i){
    int index = i;
    int leftIndex = 2 * index; 
    int rightIndex = 2 * index + 1; 

    if(leftIndex <= n && arr[index] < arr[leftIndex]){
        index = leftIndex;
    }
    if(rightIndex <= n && arr[index] < arr[rightIndex]){
        index = rightIndex;
    }

    if(index != i){
        swap(arr[index],arr[i]);
        heapify(arr,n,index);
    }

    return;
}

int main(){
    //ans 55 53 54 52 50
    int arr[]={-1, 54, 53, 55, 52, 50};
    int n=5;
    //Making heap
    for(int i=n/2 ;i > 0 ;i--){
        heapify(arr,n,i);
    }
    //Printing the value
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<"\t";
    }
}