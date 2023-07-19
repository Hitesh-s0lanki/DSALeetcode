#include<iostream>
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
};
int main(){
    Trie* root = new Trie();
    root->insert("hitesh");
    root->insert("hitman");
    root->insert("hit");

    (root->startsWith("hi")) ? cout<<"The word is there"<<endl : cout<<"the Word is Not There"<<endl;
}