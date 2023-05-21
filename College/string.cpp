#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int *arr=new int[3];
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    for(int i=0;i<3;i++){
        cout<<arr[i]<<"\t";
    }
    delete []arr;
}