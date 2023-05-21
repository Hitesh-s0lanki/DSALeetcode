#include<iostream>
using namespace std;
class member{
    public:
    static int count;
    member(){
        count++;
    }
    static int value(){
        return count;
    }
};
int member::count=0;
int main(){
    member m1,m2,m3;
    cout<<member::value();
}