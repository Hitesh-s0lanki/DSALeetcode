#include<iostream>
#include<stack>
using namespace std;
  string removeStars(string s) {
        stack<char> ch;
        int i=0;
        while(i<s.length()){
            if(s[i]=='*'){
                ch.pop();
            }
            else{
                ch.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!ch.empty()){
            ans=ch.top()+ans;
            ch.pop();
        }
        return ans;
   }
int main(){
    string s="leet**cod*e";
    cout<<removeStars(s);
}