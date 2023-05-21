#include<iostream>
using namespace std;

class heap{
    public:
    int *arr;
    int size;
    heap(){
        arr = new int[100];
        size=0;
    }
    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[index] > arr [parent]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
        print();
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }
};
int main(){
    heap h;
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.insert(60);
}