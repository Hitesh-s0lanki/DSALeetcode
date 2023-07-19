#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int eval(string ch){
    stack<int> s;
    int i = 0;
    while(i != ch.length()){
        if(ch[i] < '0' || ch[i] > '9'){
            char op = ch[i];
            i++;
            if(op == '+'){
                s.top()+= ch[i]-'0';
            }
            else if(op == '-'){
                s.top()-= ch[i] - '0';
            }
            else{
                s.top()*= ch[i] - '0';
            }
        }
        else{
            int temp = ch[i]-'0';
            s.push(temp);
        }
        i++;
    } 
    return s.top();
}


void solve(string num, int target,string prefix,vector<string> &ans){
    if(num.length() == 0){
        if(eval(prefix) == target)
            ans.push_back(prefix);
        return;
    }

    vector<char> ch = {'+','-','*'};

    for(auto i:ch){
        prefix.push_back(i);
        prefix.push_back(num[0]);
        solve(num.substr(1),target,prefix,ans);
        prefix.pop_back();
        prefix.pop_back();
    }

}

vector<string> addOperators(string num, int target) {
    string prefix ="";
    prefix.push_back(num[0]);
    vector<string> ans;
    solve(num.substr(1),target,prefix,ans);   
    return ans; 
}
int main(){
    string num = "123";
    int target = 6;
   vector<string> ans = addOperators(num,target);
   for(auto i:ans)
    cout<<i<<'\t';
}