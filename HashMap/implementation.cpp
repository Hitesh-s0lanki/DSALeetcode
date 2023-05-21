#include<iostream>
#include<unordered_map>
using namespace std;
int main(){

    unordered_map<string,int> m;

    pair<string,int> p = make_pair("Hitesh",3);
    m.insert(p);

    pair<string,int> q("Niraj",4);
    m.insert(q);

    m["Kapil"]=5;

    cout<<m["Unknown"]<<endl;
    cout<<"Check if present or Not "<<m.count("Nikhil")<<endl;

    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<< it->first <<"\t"<<it->second<<endl;
        it++;
    }
}