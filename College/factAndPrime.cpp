#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int fact(int num){
        if(num==0||num==1)
        return 1;
        return num*fact(num-1);
    }
    void prime(int num){
        vector<bool> primeNumber(num+1,true);

        primeNumber[0]=primeNumber[1]=false;
        int i=2;
        while(i<=num){
            if(primeNumber[i]){
                cout<<i<<" , ";
                for(int j=2*i;j<=num;j=j+i){
                    primeNumber[j]=false;
                }
            }
            i++;
        }

    }
};
int main(){
    Solution s;
    cout<<"factorial of 5 is "<<s.fact(5)<<endl;
    s.prime(20);
}