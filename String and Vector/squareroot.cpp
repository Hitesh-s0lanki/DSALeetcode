#include<iostream>
using namespace std;
int sqrt(int num){
    int s=0;
    int e=num-1;
    int mid=s+(e-s)/2;
    int store;
    while(s<=e){
        int square=mid*mid;
        if(square==num){
            return mid;
        }
        else if(square<num){
            store=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return store;
}
float pointer(int num,float val,int size){
    float pt=0.1;
    int j=0;
    while(j<size){
        for(int i=0;i<9&&(val+pt)*(val+pt)<num;i++){
            val+=pt;
        }
        pt=pt/10;
        j++;
    }
    return val;
}
int main(){
    int a;
    cout<<"Enter the number"<<endl;
    cin>>a;
    cout<<"the square root of number is "<<pointer(a,float(sqrt(a)),10);
 return 0;
}