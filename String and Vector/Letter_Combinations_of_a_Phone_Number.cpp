#include<iostream>
#include<vector>
using namespace std;
void solve(int index,string output,string digits,vector<string> &ans,string *mapping){
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }
    for(int i=0;i<mapping[digits[index]-'0'].length();i++){
        output.push_back(mapping[digits[index]-'0'][i]);
        solve(index+1,output,digits,ans,mapping);
        output.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string output;
        int index=0;
        solve(index,output,digits,ans,mapping);
        return ans;
    }
int main(){
    string s="232";
    vector<string> ans=letterCombinations(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\t";
    }
}