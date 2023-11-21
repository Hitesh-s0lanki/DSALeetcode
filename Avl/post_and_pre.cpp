#include<iostream>
#include<stack>
using namespace std;

string postfix(string s){

    string ans = "";
    s += ")";
    stack<char> stack_use;
    stack_use.push('(');

    for(int i = 0; i < s.length() && !stack_use.empty(); i++){
        if((s[i] >= '0' && s[i] <= '9' )|| (s[i] >= 'a' && s[i] <= 'z')){
            ans.push_back(s[i]);
        }else if(s[i] == '('){
            stack_use.push(s[i]);
        }else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' ){
            if(s[i] == '*' || s[i] == '/' ){
                while(!stack_use.empty() && (stack_use.top() == '*' || stack_use.top() == '/')){
                    ans.push_back(stack_use.top());
                    stack_use.pop();
                }
            }else{
                while(!stack_use.empty() &&(stack_use.top() == '+' || stack_use.top() == '-' || stack_use.top() == '*' || stack_use.top() == '/' || stack_use.top() == '^')){
                    ans.push_back(stack_use.top());
                    stack_use.pop();
                }
            }
            stack_use.push(s[i]);
        }else if(s[i] == ')'){
            while(!stack_use.empty() && stack_use.top() != '('){
                ans.push_back(stack_use.top());
                stack_use.pop();
            }
            stack_use.pop();
        }
    }

    return ans;
}

float evalPostfix(string postfix){
    stack<float> ans;

    for(auto i:postfix){
        if(i >= '0' && i <= '9'){
            ans.push(float( i - '0'));
        }else {
            float a = ans.top();
            ans.pop();
            float b = ans.top();
            ans.pop();

            if(i == '+'){
                ans.push(b + a);
            }else if(i == '-'){
                ans.push(b - a);
            }else if(i == '*'){
                ans.push(b * a);
            }else if(i == '/'){
                ans.push(b / a);
            }
        }
    }

    return ans.top();
}
int main(){
    // string s = "(a-b)/c";
    string s = "1+(2*3-(4/5*6)*7)*8";
    // string s = "(6+2)*5-8/4";

    cout<<postfix(s)<<endl;
    cout<<evalPostfix(postfix(s))<<endl;
}