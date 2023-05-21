#include<iostream>
using namespace std;
class A{
    public:
   virtual void dis()=0;
   ~A(){
    cout<<"Desturctor of A";
   }
};
class B:public A{
    public:
    virtual void dis(){
        cout<<"world";
    }
    ~B(){
    cout<<"Desturctor of B";
   }
};
int main(){
    A* ptr=new B;
    delete ptr;
}