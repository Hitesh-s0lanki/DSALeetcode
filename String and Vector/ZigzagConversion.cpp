#include<iostream>
using namespace std;

string convert(string s, int n) {
    if (n==1)
        return s;
    
    int skip = n + (n-2);
    int number = 0;
    int index ;
    int cnt = 0;
    string ans;
    for(int i = 0;i<n && cnt != s.length();i++){
        int index = number;
        for(int j=0;index < s.length() && cnt != s.length();j++){
            if(j%(n-1) == 0){
                ans.push_back(s[index]);
                if(i == 0 || i == n-1){
                    index+=skip;
                }
                else{
                    int skip2 = (n-i) + (n - i - 2) ; 
                    index+=skip2;
                }
                cnt++;
            }
            else if(i%(n-1) != 0 && (j+i)%(n-1) == 0){
                int skip2 = (i + 1) + (i + 1 - 2) ; 
                ans.push_back(s[index]);
                index+=skip2;
                cnt++;
            }
        }
        number++;
    }
    return ans;   
}

int main(){

    string s = "PAYPALISHIRING";
    int n = 5;
    cout<<convert(s,n);
    // int skip = n + (n-2);
    // int number = 0;
    // int index ;
    // int cnt = 0;
    // string ans;
    // for(int i = 0;i<n && cnt != s.length();i++){
    //     int index = number;
    //     for(int j=0;index < s.length() && cnt != s.length();j++){
    //         if(j%(n-1) == 0){
    //             ans.push_back(s[index]);
    //             cout<<s[index]<<" ";
    //             if(i == 0 || i == n-1){
    //                 index+=skip;
    //             }
    //             else{
    //                 int skip2 = (n-i) + (n - i - 2) ; 
    //                 index+=skip2;
    //             }
    //             cnt++;
    //         }
    //         else if(i%(n-1) != 0 && (j+i)%(n-1) == 0){
    //             int skip2 = (i + 1) + (i + 1 - 2) ; 
    //             ans.push_back(s[index]);
    //             cout<<s[index]<<" ";
    //             index+=skip2;
    //             cnt++;
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     number++;
    //     cout<<endl;
    // }
    // cout<<ans;
}

// if(j%(n-1) == 0 || (i%(n-1) != 0 && (j+i)%(n-1) == 0))