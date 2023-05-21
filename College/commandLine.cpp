#include<iostream>
using namespace std;
int main(int argu,char* argc[]){
    cout<<"File name "<<argc[0]<<endl;
    for(int i=1;i<argu;i++){
        cout<<"the agruments are "<<argc[i]<<endl;
    }
}