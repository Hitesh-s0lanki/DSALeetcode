#include <iostream>
#include <vector>
using namespace std;
vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    int i = 0;
    vector<string> ans;
    while (i < words.size())
    {
        int count = 0;
        int j = i;
        while (j < words.size() && (count + words[j].length()) <= maxWidth)
        {
            count += words[j++].length() + 1;
        }

        int NumberOfWord = (j - i);
        vector<int> SpaceArray;
        if (NumberOfWord == 1)
        {
            SpaceArray.push_back(maxWidth - words[i].length());
        }
        else if(j==words.size()){
            int n=NumberOfWord;
            for(int h=0;h<NumberOfWord;h++){
                if (n > 1)
                {
                    SpaceArray.push_back(1);
                }
                else
                {
                    SpaceArray.push_back(maxWidth-count);
                }
                n--;
            }
        }
        else
        {
            int one = (maxWidth - (count - (j - i))) / (j - i - 1);
            int rem = (maxWidth - (count - (j - i))) % (j - i - 1);
            for (int h = 0; h < NumberOfWord - 1; h++)
            {
                if (rem > 0)
                {
                    SpaceArray.push_back(one + 1);
                }
                else
                {
                    SpaceArray.push_back(one);
                }
                rem--;
            }
        }
        // for ans
        string temp = "";
        int f = 0;
        while (i != j)
        {
            temp += words[i++];
            for (int h = 0; f < SpaceArray.size() && h < SpaceArray[f]; h++)
                temp.push_back(' ');

            f++;
        }
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    vector<string> s = {"What","must","be","shall","be."};
    vector<string> ans = fullJustify(s, 12);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "'" << ans[i] << "'" << endl;
    }
    return 0;
}
