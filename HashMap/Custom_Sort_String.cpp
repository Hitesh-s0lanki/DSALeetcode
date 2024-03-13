#include <iostream>
#include<map>
using namespace std;

string customSortString(string order, string s) {
    //map a-z
    map<char, int> letter_map;
    for(int i = 0 ;  i < order.length() ; i++ ){
        letter_map[order[i]] = order.length() - i;
    }

    string ans = "";
    
    for(char ch:s){
        if(letter_map[ch] && ans.length() != 0){
            string new_ans = "";

            int i = 0;
            while(i < ans.length() && letter_map[ch] < letter_map[ans[i]]){
                new_ans.push_back(ans[i++]);
            }

            new_ans.push_back(ch);

            while(i < ans.length()){
                new_ans.push_back(ans[i++]);
            }

            ans = new_ans;
        }else{
            ans.push_back(ch);
        }
    }

    return ans;
}

int main(){
    string order = "bcafg", s = "abcd"; 

    cout<<customSortString(order, s);

}