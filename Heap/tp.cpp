#include<iostream>
#include<vector>
using namespace std;

//max heap
void heapify(vector<int> &arr,int i,int size){
    int index = i;
    int leftIndex = 2* index;
    int rightIndex = 2 * index + 1;

    if(leftIndex < size && arr[index] < arr[leftIndex]){
        index = leftIndex;
    }
    if(rightIndex < size && arr[index] < arr[rightIndex]){
        index = rightIndex;
    }

    if(index != i){
        swap(arr[index], arr[i]);
        heapify(arr,index, size);
    }
}

//max heap
void minheapify(vector<int> &arr,int i){
    int index = i;
    int leftIndex = 2* index;
    int rightIndex = 2 * index + 1;

    if(leftIndex < arr.size() && arr[index] > arr[leftIndex]){
        index = leftIndex;
    }
    if(rightIndex < arr.size() && arr[index] > arr[rightIndex]){
        index = rightIndex;
    }

    if(index != i){
        swap(arr[index], arr[i]);
        minheapify(arr,index);
    }
}

void minheap(vector<int> &arr){
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0 ;i--){
        minheapify(arr,i);
    }
}

void heapSort(vector<int>& arr){
    int size = arr.size() - 1;

    while(size > 1){
        //swap
        swap(arr[1],arr[size--]);

        //heafiy them
        heapify(arr,1,size+1);  
    }
}


int main(){
    vector<int> arr = { -1, 54, 53, 55, 52, 50};

    for(int i = arr.size()/2-1 ;i > 0 ;i--){
        heapify(arr,i,arr.size());
    }
    // minheap(arr);

    heapSort(arr);
    for(auto i: arr){
        if(i != -1)
        cout<<i<<"\t";
    }

    return 0;
}