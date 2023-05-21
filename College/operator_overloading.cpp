#include<iostream>
using namespace std;
class Complex{
    int real;
    int img;
    public:
    Complex(){
    }
    Complex(int real,int img){
        this->real=real;
        this->img=img;
    }
    Complex operator+(Complex c){
        Complex temp;
        temp.real=real+c.real;
        temp.img=img+c.img;
        return temp;
    }
    Complex operator*(Complex c){
        Complex temp;
        temp.real=real*c.real;
        temp.img=img*c.img;
        return temp;
    }
    void operator++(){
        ++real;
    }
    void disp(){
        cout<<real<<" + "<<img<<"i"<<endl;
    }
    void print(){
        cout<<"the Sum of two Complex number is "<<real<<" + "<<img<<"i"<<endl;
        cout<<"the Multply of two Complex number is "<<real<<" + "<<img<<"i"<<endl;
    }
};
int main(){
    Complex c1(1,2),c2(3,4),c3;
    cout<<"the first nUmber is ";
    c1.disp();
    cout<<"the Second nUmber is ";
    c2.disp();
    c3=c1*c2;
    ++c3;
    c3.print();
}