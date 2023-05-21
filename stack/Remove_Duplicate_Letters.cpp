#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
 void getString(stack<char> &ch,char c){
   if(ch.empty()){
    ch.push(c);
    return ;
   }
   if(ch.top()==c){
    ch.pop();
   }

   char d=ch.top();
   ch.pop();
   getString(ch,c);
   ch.push(d);
 }
   string removeDuplicateLetters(string s) {
    stack<char> ch;
    int i=0;
    while(i<s.length()){
        getString(ch,s[i]);
        i++;
    }
    string ans="";
        while(!ch.empty()){
            ans.push_back(ch.top());
            ch.pop();
        }
        return ans;
    }
int main(){
    string s="hitesh";
    cout<<removeDuplicateLetters(s);
}