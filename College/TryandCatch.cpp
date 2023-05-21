#include<iostream>
using namespace std;
//Zero valu
void Exception(){
    try{
        throw 0;
    }
    catch(int n){
        cout<< "hello"<< endl;
        throw n;
    }
}
int main(){
    int a=2,b=2,c=3;
    try{
        Exception();
    }

    catch(int err){
        cout<<"the value is  zero "<<err;
    }
    catch(...){
        cout<<"Default error"<<endl;
    }
}