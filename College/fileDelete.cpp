#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int status;
    char filename[20];
    cout<<"Enter the file name"<<endl;
    cin>>filename;
    status=remove(filename);
    if(status==0){
        cout<<"file deleted successfull"<<endl;
    }
    else{
        cout<<"Error occured"<<endl;
    }
}