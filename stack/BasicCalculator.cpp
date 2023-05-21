#include <iostream>
#include <stack>
using namespace std;
// int calculate(string s)
// {
//     stack<int> q;
//     int i = 0;
//     int num = 0;
//     while (i < s.length())
//     {
//         if (s[i] == '+' || s[i] == '*' || s[i] == '-' || s[i] == '/')
//         {
//             char ch = s[i];
//             i++;
//             while (i < s.length() && s[i] >= '0' && s[i] <= '9')
//             {
//                 num = num * 10 + (s[i++] - '0');
//             }
//             if (ch == '+')
//             {
//                 q.top() += num;
//             }
//             else if (ch == '-')
//             {
//                 q.top() -= num;
//             }
//             else if (ch == '*')
//             {
//                 q.top() *= num;
//             }
//             else if (ch == '/')
//             {
//                 q.top() /= num;
//             }
//             num = 0;
//         }
//         else
//         {
//             while (i < s.length() && s[i] >= '0' && s[i] <= '9')
//             {
//                 num = num * 10 + (s[i++] - '0');
//             }
//             q.push(num);
//             num = 0;
//         }
//     }
//     return q.top();
// }
int calculate(string s){
    stack<int> q;
    int sign=0;
    int i=0;
    if(s[0]=='-'){
        i=1;
        sign=1;
    }
    while(i<s.length()){
        if(s[i]==')'){
            while(!q.empty()&&q.top()!='('){
                int num=q.top();
                q.pop();
                if(q.top()=='+'-'0'){
                    q.pop();
                    q.top()+=num;
                }
                else if(q.top()=='-'-'0'){
                    q.pop();
                    q.top()-=num;
                }
                else if(q.top()=='*'-'0'){
                    q.pop();
                    q.top()*=num;
                }
                else if(q.top()=='/'-'0'){
                    q.pop();
                    q.top()/=num;
                }
            }
            cout<<q.top()<<endl;
            int change=q.top();
                q.pop();
                q.pop();
                q.push(change);

                i++;
        }
        else if(s[i] >= '0' && s[i] <= '9'){
            int num=0;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i++] - '0');
            }
            q.push(num);
            num = 0;
        }
        else{
            q.push(s[i++]);
        }
    }
    return q.top();
}
int main()
{
    string s = "(1*2-3+4)";
    cout << calculate(s);
}
//without eval() bhai