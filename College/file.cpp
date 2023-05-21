#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream ptr;
    ptr.open("hitesh.txt",ios::in);
    if(!ptr){
        cout<<"no such file "<<endl;
    }
    else{
        char ch;
        while(1){
            ptr>>ch;
            if(ptr.eof()){
                break;
            }
            cout<<ch;
        }
    }
    ptr.close();

}