#include<iostream>
using namespace std;
string capitalizeTitle(string title) {
    int i=0;
    string ans;
        while(i<title.length()){
            int count=0;
            int j=i;
            while(j<title.length()&&title[j]!=32){
                count++;
                j++;
            }
            if(count<=2){
                if(title[i]>='A'&&title[i]<='Z'){
                    ans.push_back(title[i++]+32);
                }
                else if(title[i]==32){
                    ans.push_back(title[i++]);
                }
                else{
                    ans.push_back(title[i++]);
                }
            }
            else{
                if(i==0||title[i-1]==32){
                    if(title[i]>='a'&&title[i]<='z')
                    ans.push_back(title[i++]-32);
                    else
                    ans.push_back(title[i++]);
                }
                else if(title[i]==32){
                    ans.push_back(title[i++]);
                }
                else{
                     if(title[i]>='A'&&title[i]<='Z'){
                    ans.push_back(title[i++]+32);
                    }
                    else{
                        ans.push_back(title[i++]);
                    }
                }
            }
        }
        return ans;
    }
int main(){
    string s="First leTTeR of EACH Word";
    cout<<capitalizeTitle(s);
}