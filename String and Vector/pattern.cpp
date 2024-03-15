#include <iostream>
using namespace std;

string convert(string s, int n)
{
    if (n == 1)
        return s;

    string ans;
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = 0; (k < s.length() || (k - 2 * i) < s.length()); j++)
        {
            if (j % (n - 1) == 0)
            {
                if (k < s.length())
                {
                    cout << s[k] << " ";
                    ans.push_back(s[k]);
                }
                k = k + (2 * n - 2);
            }
            else if (((j + i) % (n - 1)) == 0)
            {
                cout << s[k - 2 * i] << " ";
                ans.push_back(s[k - 2 * i]);
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return ans;
}

int main()
{
    cout << convert("PAYPALISHIRING", 6);
}