#include<iostream>
using namespace std;

int binarySearch(int arr[],int size,int data){
    int start=0;
    int end=size-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==data){
            return mid;
        }
        else if(arr[mid]<=data){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}
int linearSearch(int arr[],int size,int data){
    for(int i=0;i<size;i++){
        if(arr[i]==data){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int data;
    cout<<"Enter the data to be find : "<<endl;
    cin>>data;
    int binary;
    int linear;
    int user;
    cout<<"Enter 1 for bbinary search and 2 for linear search: ";
    cin>>user;
    switch(user){
        case 1:
            binary=binarySearch(arr,size,data);    
            cout<<"using the binary search the elements present at index(if -1 then not present): "<<binary<<endl;
            break;
        case 2:
            linear=linearSearch(arr,size,data);
            cout<<"using the linear search the elements present at index(if -1 then not present): "<<linear<<endl;
            break;
        default:
        cout<<"1 or 2 he enter karo bhai.";
    }



    
    return 0;
}