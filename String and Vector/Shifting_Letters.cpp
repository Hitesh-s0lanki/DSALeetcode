#include<iostream>
#include<vector>
using namespace std;
string shiftingLetters(string s, vector<int>& shifts) {
        string ans;
        int i=0;
        while(i<shifts.size()){
            int j=i;
            int count=0;
            while(j<shifts.size()){
                count+=shifts[j++];
            }
            cout<<count<<endl;
            while(count>=26){
                count-=26;
            }
            int n=s[i]-'a'+1;
            if(n+count>26){
            ans.push_back('a'+(n-count));
            }
            else
            ans.push_back(s[i]+count);

            i++;
        }
        return ans;
    }
int main(){
    vector<int> a={26,9,17};
    string s="ruu";
    cout<<shiftingLetters(s,a);
}