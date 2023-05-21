#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s)
{
    stack<char> ch;
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            ch.push(s[i]);
        }
        else if (!ch.empty())
        {
            if (ch.top() == '(' && s[i] == ')' || ch.top() == '[' && s[i] == ']' || ch.top() == '{' && s[i] == '}')
            {
                ch.pop();
            }
            else
            {
                return false;
            }
        }
        else {
            return false;
        }
        i++;
    }
    if (ch.empty())
    {
        return true;
    }
    return false;
}
int main()
{
    string s = "()";
    if (isValid(s))
    {
        cout << "It is a valid Parentheses" << endl;
    }
    else
    {
        cout << "Not valid " << endl;
    }
}