#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
   string makeGood(string s) {
        stack<char> ch;
        int i=0;
        while(i<s.length()){
            if(!ch.empty()&&(ch.top()==s[i]-32||ch.top()-32==s[i])){
                ch.pop();
            }
            else{
                ch.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!ch.empty()){
            ans.push_back(ch.top());
            ch.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){
    string s="leEeetcode";
    cout<<makeGood(s);
}