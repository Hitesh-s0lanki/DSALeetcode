#include<iostream>
using namespace std;
void fib(int n,int first,int second){
    if(n <= 0) return;
    cout<<first<<"\t";
    fib(n-1 , second, first + second);
}   
int main(){
    fib(10, 0, 1);
}