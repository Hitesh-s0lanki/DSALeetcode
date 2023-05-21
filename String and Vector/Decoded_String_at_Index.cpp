#include <iostream>
using namespace std;
string decodeAtIndex(string s, int k)
{
    if (k == 1)
    {
        string last;
        last.push_back(s[0]);
        return last;
    }
    int i = 0;
    string ans = "";
    while (i < s.length())
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int count = s[i] - '0';
            string temp = "";
            while (count)
            {
                int j = i - 1;
                while(j >= 0 &&s[j] >= '0' && s[j] <= '9'){
                    j--;
                }
                while (j >= 0 && s[j] >= 'a' && s[i] <= 'z')
                {
                    temp = s[j--] + temp;
                }
                count--;
                cout<<temp<<endl;
            }
            ans = ans + temp;
        }
        i++;
    }
    string last;
    last.push_back(ans.at(k - 1));
    return last;
}
int main()
{
    string s = "a23";
    cout << decodeAtIndex(s, 6);
}