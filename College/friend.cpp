#include<iostream>
using namespace std;
class Complex{
    int real;
    int img;
    public:
    Complex(int real,int img){
        this->real=real;
        this->img=img;
    }
    friend void Sum(Complex ,Complex);
    void disp(){
        cout<<"the real number is "<<real<<endl;
        cout<<"the imaginary number is "<<img<<endl;
    }
};
void Sum(Complex c1,Complex c2){
    cout<<"Sum of real Number is "<<c1.real+c2.real<<endl;
    cout<<"Sum of img Number is "<<c1.img+c2.img<<endl;
}
int main(){
    Complex c1(1,2),c2(3,4);
    c1.disp();
    c2.disp();
    cout<<endl;
    Sum(c1,c2);
}