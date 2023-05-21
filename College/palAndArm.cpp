#include<iostream>
#include<cmath>
using namespace std;
bool palindrome(int num){
    int rev=0;
    int store=num;
    while(num>0){
        rev=rev*10+num%10;
        num/=10;
    }
    return store==rev;
}
bool ArmStrong(int num){
    int arm=0;
    int store=num;
    while(num>0){
        arm=arm+pow(num%10,3);
        num/=10;
    }
    return store==arm;
}
int main(){
    int num;
    cout<<"Enter the Number "<<endl;
    cin>>num;
    if(palindrome(num))
    cout<<"Number is Palindrome"<<endl;
    else
    cout<<"Not a palindrome"<<endl;
    if(ArmStrong(num))
    cout<<"Number is ArmStrong"<<endl;
    else
    cout<<"Not a ArmStrong"<<endl;
}