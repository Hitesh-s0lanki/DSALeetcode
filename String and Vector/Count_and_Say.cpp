#include<iostream>
using namespace std;
string countAndSay(int n) {
    if(n==1)
    return "1";

       string ans=countAndSay(n-1);
       //count 
        int i=0;
        string final="";
        while(i<ans.size()){
            int count=0;
            int j=i;
            while(i<ans.size()&&ans[i]==ans[j]){
                i++;
                count++;
            }

            final+=to_string(count);
            final.push_back(ans[j]);
        }
        return final;
    }
int main(){
    int a=12;
    cout<<countAndSay(a);
}