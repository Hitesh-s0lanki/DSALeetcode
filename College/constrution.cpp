#include<iostream>
using namespace std;
class A{
    public:
    int a;
    A(int a){
        this->a=a;
    }
};
class B{
    public:
    int b;
    B(int b){
        this->b=b;
    }
};
class C:public B,public A{
    int c;
    public:
    C(int a,int b,int c):A(a),B(b){
        this->c=c;
    }
    void print(){
        cout<<"value of a is "<<a<<endl;
        cout<<"value of b is "<<b<<endl;
        cout<<"value of c is "<<c<<endl;
    }
};
int main(){
    C *c1=new C(1,2,3);
    c1->print();
}