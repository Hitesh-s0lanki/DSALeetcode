#include<iostream>
using namespace std;
class heap{
    public:
    int *arr;
    int size;
    heap(){
        size=0;
        arr = new int[100];
    }
    void insert(int val){

        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){

            int parent= index/2;

            if(arr[index] > arr[parent]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void deleteTheNode(){

        int index = 1;
        arr[1] = arr [size];
        size--;

        while(index < size){
            int leftIndex = 2*index;
            int rightIndex = 2*index + 1 ;

            if(leftIndex <= size && arr[index] < arr[leftIndex]){
                swap(arr[index],arr[leftIndex]);
                index = leftIndex;
            }
            else if(rightIndex <= size && arr[index] < arr[rightIndex]){
                swap(arr[index],arr[rightIndex]);
                index = rightIndex;
            }
            else{
                return;
            }
        }
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
    h.print();
    h.deleteTheNode();
    h.print();
}