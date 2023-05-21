#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
  int maxDepth(string s) {
        stack<int> ch;
        int maxcount=0;
        int i=0;
        while(i<s.length()){
            if(s[i]=='('){
                ch.push(s[i]);
            }
            else if(!s.empty()&&s[i]==')'){
                if(maxcount<ch.size()){
                    maxcount=ch.size();
                }
                ch.pop();
            }
            i++;
        }
        return maxcount;
    }
int main(){
    string s="(1+(2*3)+((8)/4))+1";
    cout<<maxDepth(s);
}