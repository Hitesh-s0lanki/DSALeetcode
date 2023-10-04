#include <iostream>
#include <stack>
using namespace std;

string postfixExpression(string equation){
    stack<char> s;
    s.push('(');
    equation.push_back(')');
    
    string postfix;

    for(char ch:equation){
        if(ch >= '0' && ch <= '9'){
            postfix.push_back(ch);
        } else if(ch == '('){
            s.push(ch);
        } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            if(ch == '+' || ch == '-'){
                while(!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == ch || (s.top() == '+' && ch == '-') || (s.top() == '-' && ch == '+'))){
                    postfix.push_back(s.top());
                    s.pop();
                }
            }
            s.push(ch);
        } else if(ch == ')'){
            while(!s.empty() && s.top() != '('){
                postfix.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
    }

    return postfix;

}

int calculate(string s) {
     string postfix = postfixExpression(s);

    stack<int> st;   
    cout<<postfix<<endl;
     for(char ch : postfix){
        if(ch >= '0' && ch <= '9'){
            st.push(ch - '0');
        }else{
            if(ch == '+'){
                int num = st.top();
                st.pop();
                num += st.top();
                st.pop();
                st.push(num);
            } else if(ch == '-'){
                int num = st.top();
                st.pop();
                num = st.top() - num;
                st.pop();
                st.push(num);
            } else if(ch == '*'){
                int num = st.top();
                st.pop();
                num *= st.top();
                st.pop();
                st.push(num);
            } else if(ch == '/'){
                int num = st.top();
                st.pop();
                num = st.top()/num;
                st.pop();
                st.push(num);
            }
        }
     }

     return st.top();

}
int main(){
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout<<calculate(s);
}
