#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream ptr;
    ptr.open("hitesh.txt",ios::out);
    if(!ptr)
    cout<<"file doesn't exist";
    else{
        ptr<<"hello hitesh"<<endl;
        cout<<"writeen sucessfull";
    }
    ptr.close();
}