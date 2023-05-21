#include <iostream>
#include <cstring>
using namespace std;
string str_repeat(string s, int n)
{
    if(n==0){
        return s;
    }
    string str = "";
    for (int i = 0; i < n; i++)
    {
        str += s;
    }
    return str;
}
string decode(string s)
{
    string ans = "";
    int i = 0;
    while (i < s.length())
    {
        int count = 0;
        if (s[i] >= '0' && s[i] <= '9')
        {
            while (s[i] != '[')
            {
                count = count * 10 + (s[i++] - '0');
            }
            i++;
        }
        string temp = "";
        while (i<s.length()&&s[i] != ']')
        {
            temp.push_back(s[i++]);
        }
        ans += str_repeat(temp, count);
        i++;
    }
    return ans;
}
int main()
{
    string s = "2[abc]3[cd]ef";
    cout << decode(s);
}