#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
string digitSum(string s, int k)
{
    while (s.length() > k)
    {
        // divide the string in part
        vector<string> temp;
        int i = 0;
        while (i < s.length())
        {
            if (s.length() - i - 1 >= k)
            {
                int n = k;
                string st = "";
                while (n)
                {
                    st += s[i++];
                    n--;
                }
                temp.push_back(st);
            }
            else{
                string st = "";
                while (i < s.length())
                {
                    st += s[i++];
                }
                temp.push_back(st);
            }
        }
        //Adding individual String
        i=0;
        s="";
        while(i<temp.size()){
            int j=0;
             int num=0;
            while(j<temp[i].length()){
            num+=(temp[i][j++]-'0');
            }

            s+=to_string(num);
            i++;
        }
    }
    return s;
}
int main()
{
    string s = "00000000";
    int k = 3;
    cout << digitSum(s, k);
}