#include<iostream>
#include<vector>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char data){
        this->data = data;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        //Base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;

        //Present
        if(root -> children [index] != NULL){
            child = root -> children [index];
        }
        else{
            child = new TrieNode(word[0]);
            root ->children[index] = child;
        }
        //Recursive call
        insertUtil(child,word.substr(1));
    }
    void insert(string word){
        insertUtil(root,word);
    }
    void printSuggestion(TrieNode* root,vector<string> &temp,string prefix){
        if(root -> isTerminal){
            temp.push_back(prefix);
        }

        TrieNode* prev = root;

        for(int i=0;i<26;i++){

            TrieNode * curr = prev -> children [i];

            if(curr != NULL){
                prefix.push_back('a' + i);
                printSuggestion(curr,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestion(string queryStr){
        vector<vector<string>> ans;
        TrieNode* prev = root;

        string prefix="";

        for(auto i:queryStr){

            TrieNode* curr = prev -> children[i - 'a'];

            if(curr == NULL){
                break;
            }
            //temp vector for storing data
            vector<string> temp;
            prefix.push_back(i);
            printSuggestion(curr,temp,prefix);

            ans.push_back(temp);
            prev = curr;
        }
        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr){
    Trie* root = new Trie();
    //Enter the Value in Trie
    for(auto i : contactList)
        root -> insert(i);

    return root -> getSuggestion(queryStr);
}
int main(){
//     cod coding codding code coly
// coding
    vector<string> contactList = {"cod","coding","codding","code","coly"};
    string a ="coding";
    vector<vector<string>> ans = phoneDirectory(contactList,a);
    for(auto i:ans){
        for(auto j : i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
}