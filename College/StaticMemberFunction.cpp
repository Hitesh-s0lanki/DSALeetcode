#include<iostream>
using namespace std;
class Counter{
    static int count;
    public:
    Counter(){
        count++;
    }
    static int func(){
        return count;
    }
};
int Counter::count=0;
int main(){
    Counter c1,c2,c3;
    cout<<"Number of object created "<<Counter::func();
}