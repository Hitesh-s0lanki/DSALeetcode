#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
string repeatString(string s,int n){
    string ans="";
    while(n){
        ans+=s;
        n--;
    }
    return ans;
}
string decodeString(string s) {
        stack<string> stk;
        int i=0;
        while(i<s.length()){
            if(s[i]==']'){
                string temp=stk.top();
                stk.pop();
                int num=0;
                int j=0;
                while(j<stk.top().length()){
                    num=num*10+(stk.top()[j]-'0');
                    j++;
                }
                cout<<num<<endl;
                stk.pop();
              string ans=repeatString(temp,num);
              if(stk.empty()){
                stk.push(ans);
              }
              else {
                stk.top()+=ans;
              }
              i++;
            }
            else{
                if(s[i]>='a'&&s[i]<='z'){
                    string temp="";
                    while(s[i]>='a'&&s[i]<='z'){
                        temp.push_back(s[i++]);
                    }
                    stk.push(temp);
                }
                else if(s[i]>='0'&&s[i]<='9'){
                    string temp="";
                    while(s[i]>='0'&&s[i]<='9'){
                        temp.push_back(s[i++]);
                    }
                    stk.push(temp);
                }
                else{
                    i++;
                }
            }
        }
        if(stk.size()>1){
            string ans=stk.top();
            stk.pop();
            stk.top()+=ans;
        }
        return stk.top();
    }
int main(){
    string s="3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    cout<<decodeString(s);
}