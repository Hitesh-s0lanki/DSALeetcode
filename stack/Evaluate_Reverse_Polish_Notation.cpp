#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int evalRPN(vector<string> &tokens)
{
    stack<int> number;
    int n;
    int i = 0;
    while (i < tokens.size())
    {
        if (tokens[i] == "+")
        {
            n = number.top();
            number.pop();
            number.top() += n;
        }
        else if (tokens[i] == "-")
        {
            n = number.top();
            number.pop();
            number.top() -= n;
        }
        else if (tokens[i] == "*")
        {
            n = number.top();
            number.pop();
            number.top() *= n;
        }
        else if (tokens[i] == "/")
        {
            n = number.top();
            number.pop();
            number.top() /= n;
        }
        else
        {
            int j = 0;
            int num = 0;
            int sign = 0;
            while (j < tokens[i].length())
            {
                if (tokens[i][j] == '-')
                {
                    sign = 1;
                }
                else
                {
                    num = num * 10 + (tokens[i][j] - '0');
                }
                j++;
            }
            if (sign == 1)
             num *= (-1);
            number.push(num);
        }
        i++;
    }
    return number.top();
}
int main()
{
    // vector<string> tokens={"2","1","+","3","*"};
    // vector<string> tokens={"4","13","5","/","+"};
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens);
}