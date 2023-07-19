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
        isTerminal = false;
    }
};
class Trie {
    public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        
        //Base case
        if( word.length() == 0 ){
            root -> isTerminal = true;
            return ;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root ->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root ->children [index] = child; 
        }

        insertUtil(child,word.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root,string word){
        //Base case
        if( word.length() == 0 ){
            return root -> isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root ->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child,word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root,word);
    }
    
    bool startsWithUtil(TrieNode* root,string prefix) {
        //Base case
        if( prefix.length() == 0 ){
            return true;
        }

        int index = prefix[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root ->children[index];
        }
        else{
            return false;
        }

        return startsWithUtil(child,prefix.substr(1));        
    }
    bool startsWith(string prefix) {
        return startsWithUtil(root,prefix);
    }
    void longestCommonPrefixUtil2(TrieNode* root,string &ans){
        int cnt=0;
        int index=0;
        for(int i=0;i<26;i++){
            if(root->children[i] != NULL){
                index=i;
                cnt++;
            }
        }
        if(cnt > 1 || cnt < 1 || root ->isTerminal)
            return;
        
        root = root -> children[index];
        ans.push_back(root->data);
        
        longestCommonPrefixUtil2(root,ans);
    }
    void longestCommonPrefixUtil(string &ans){
        longestCommonPrefixUtil2(root,ans);
    }
};
string longestCommonPrefix(vector<string>& strs) {
     Trie * root =new Trie();
     for(auto i:strs)
        root->insert(i); 
    string ans;
    root->longestCommonPrefixUtil(ans);

    return ans;
    
}
int main(){
    vector<string> strs = {"flower","flow","flo"};
    cout<<longestCommonPrefix(strs);
}