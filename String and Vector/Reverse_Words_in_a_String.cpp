#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
   string reverseWords(string s) {
        vector<string> ans;
        int i=0;
        while(i<s.length()){
            if(s[i]==32){
                
            }
            else{
                string str="";
                while(i<s.length()&&s[i]!=32){
                    str.push_back(s[i]);
                    i++;
                }
                ans.push_back(str);
            }
            i++;
        }
        i=ans.size()-1;
        string str="";
        while (i>=0)
        {
            str=str+ans[i--]+" ";
        }
        str.pop_back();
        return str;
    }
int main(){
    string s="the sky is blue";
    cout<<reverseWords(s);
}