#include<iostream>
using namespace std;
template<class t>
void swapData(t &a,t &b){
    t temp=a;
    a=b;
    b=temp;
}
template<typename t> class Sum{
    public:
    t *arr;
    int n=0;
    Sum(int size){
        arr=new int[size];
    }
    void push(int n){
        arr[n];
    }
};
int main(){
    char a='c',b='h';
    swapData(a,b);
    cout<<"value of a "<<a<<endl;
    cout<<"value of b "<<b;
}