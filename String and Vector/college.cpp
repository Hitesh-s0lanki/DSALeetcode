#include<iostream>
using namespace std;

void insertElement(int *arr,int size){
    for(int i = 0; i < size ; i++){
        cout<<"Enter the Element at index : "<<i<<endl;
        cin>>arr[i];
    }
}

void display(int *arr,int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}


void addNewElement(int *arr,int &size,int newElement,int position){
    for(int i = size; i >= position ; i--){
        arr[i + 1] = arr[i];
    }
    arr[position] = newElement; 
    size++;
}

int main(){
    int *arr = new int[100];

    int size;
    cout<<"Enter the size of array"<<endl;
    cin>>size;

    insertElement(arr,size);
    display(arr,size);
    
    cout<<"Enter the element you want to insert"<<endl;
    int data;
    cin>>data;
    cout<<"Enter the position in which element you want to insert from 0 to "<<size<<endl;
    int position;
    cin>>position;
    addNewElement(arr,size,data,position);
    display(arr,size);
    
}