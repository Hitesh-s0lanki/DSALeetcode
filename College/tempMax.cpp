#include<iostream>
using namespace std;
template<class t>
void maxNumber(t a,t b){
    if(a>b)
    cout<<"greater Number is "<<a;
    else
    cout<<"the greater number is "<<b;
}
int main(){
    int a=9,b=8;
    maxNumber(a,b);
}