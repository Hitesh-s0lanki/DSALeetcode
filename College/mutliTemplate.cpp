#include<iostream>
using namespace std;
template<class T1,class T2>
void displayFunction(T1 a,T2 b){
    cout<<"value of a is "<<a<<endl;
    cout<<"value of b is "<<b<<endl;
}
template<class t1,class t2> class Dis{
    public:
    void displayFunction(t1 a,t2 b){
    cout<<"value of a is "<<a<<endl;
    cout<<"value of b is "<<b<<endl;
}
};
int main(){
    Dis<string,int> d1;
    d1.displayFunction("hitesh",43);
    Dis<int,string> d2;
    d2.displayFunction(25,"shakti");
}