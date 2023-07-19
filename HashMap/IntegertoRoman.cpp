#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
string intToRoman(int num) {


    // string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        // string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        // string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        // string ths[]={"","M","MM","MMM"};
        
        // return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
      //mapping the value

      vector<pair<string,int>> val = {make_pair("I",1),make_pair("IV",4),make_pair("V",5),make_pair("IX",9),make_pair("X",10),make_pair("XL",40),make_pair("L",50),make_pair("XC",90),make_pair("C",100),make_pair("CD",400),make_pair("D",500),make_pair("CM",900),make_pair("M",1000)};
    reverse(val.begin(),val.end());

    string ans;
    while(num > 0){
        for(auto i:val){
            if(num >= i.second){
                int temp = num / i.second;
                num = num % i.second;
                while(temp){
                    ans+=i.first;
                    temp--;
                }
            }
        }
    }
    
    return ans;
}
int main(){
    int num = 4;
    cout<<intToRoman(num);
}
