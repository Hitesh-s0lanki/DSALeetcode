#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int status=remove("hitesh1.txt");
    if(status==0){
        cout<<"delete success";
    }
    else{
        cout<<"not possible";
    }
}