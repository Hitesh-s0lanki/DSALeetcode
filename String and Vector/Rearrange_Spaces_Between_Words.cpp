#include<iostream>
#include<vector>
using namespace std;
string reorderSpaces(string text) {
        int countSpace=0;
        int i=0;
        vector<string> ans;
        while(i<text.length()){
            if(text[i]==32){
                countSpace++;
                i++;
                continue;
            }
            string temp;
            while(text[i]>='a'&&text[i]<='z'){
                temp.push_back(text[i++]);
            }
            ans.push_back(temp);
        }
        string main="";
        if(ans.size()==1){
            main+=ans[0];
            while(countSpace){
                main.push_back(' ');
                countSpace--;
            }
            return main;
        }
        int NumberOfSpace=countSpace/(ans.size()-1);
        int rem=countSpace%(ans.size()-1);
        i=0;
        while(i<ans.size()){
            main+=ans[i];
            if(i!=ans.size()-1){
                int j=0;
                while(j<NumberOfSpace){
                    main.push_back(' ');
                    j++;
                }
            }
            else if(rem>0){
                while(rem){
                    main.push_back(' ');
                    rem--;
                }
            }
            i++;
        }
        return main;
    }
int main(){
    string s="  hello";
    cout<<reorderSpaces(s);
}