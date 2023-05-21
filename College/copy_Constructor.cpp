#include<iostream>
using namespace std;
class CopyVala{
    int rollno;
    string name;
    public:
    CopyVala(){
        cout<<"I m default "<<endl;
    }
    CopyVala(int rollno,string name){
        this->rollno=rollno;
        this->name=name;
    }
    void disp(){
        cout<<"roll no of Student is "<<rollno<<endl;
        cout<<"name of Student is "<<name<<endl;
    }
    CopyVala(CopyVala &c){
        this->rollno=c.rollno;
        this->name=c.name;
    }
};
int main(){
    CopyVala c1(43,"hitesh"),c2(c1);
    cout<<"Default construtor is"<<endl;
    c1.disp();
    cout<<"Copy  construtor is"<<endl;
    c2.disp();
}