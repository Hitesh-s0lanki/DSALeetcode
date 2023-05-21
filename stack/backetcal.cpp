#include <iostream>
#include <stack>

using namespace std;
int solve(string s)
{
    stack<int> st;
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            char ch = s[i];
            i++;
            bool sign = false;
            int num = 0;
            if (s[i] == '-')
            {
                sign = true;
                i++;
            }
            while (s[i] >= '0' && s[i] <= '9')
            {
                num = num + (s[i++] - '0');
            }
            if (sign)
            {
                num = -1 * num;
            }
             if (ch == '+')
            {
                st.top() += num;
            }
            else if (ch == '-')
            {
                if (num < 0)
                {
                    st.top() += (-1 * num);
                }
                else
                {
                    st.top() -= num;
                }
            }
            else if (ch == '*')
            {
                st.top() *= num;
            }
            else if (ch == '/')
            {
                st.top() /= num;
            }
        }
        else
        {
            if (s[i] == '(')
            {
                st.push(s[i++]);
            }
            else if (s[i] == ')')
            {
                i++;
            }
            else
            {
                int num = 0;
                bool sign = false;
                if (s[i] == '-')
                {
                    sign = true;
                    i++;
                }
                while (s[i] >= '0' && s[i] <= '9')
                {
                    num = num + (s[i++] - '0');
                }
                if (sign)
                {
                    num = -1 * num;
                }
                st.push(num);
            }
        }
    }
    while(st.size()!=1){
        int num=st.top();
        st.pop();
        st.pop();
        cout<<st.top()<<endl;
        char ch=st.top();
        st.pop();
        if (ch == '+')
            {
                st.top() += num;
            }
            else if (ch == '-')
            {
                if (num < 0)
                {
                    st.top() += (-1 * num);
                }
                else
                {
                    st.top() -= num;
                }
            }
            else if (ch == '*')
            {
                st.top() *= num;
            }
            else if (ch == '/')
            {
                st.top() /= num;
            }
    }
    return st.top();
}
int main()
{
    string s = "(1+2+3+(5+4*5))";
    cout << solve(s);
}