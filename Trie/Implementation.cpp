#include<iostream>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root , string word){

        //base case 
        if( word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        //assumtion small letter
        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        //Recuersion

        insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }
    bool isSearchWordUtil(TrieNode* root,string word){
        //Base case
        if(word.length() == 0 ){
            return root -> isTerminal;
        }

        int index = word[0] - 'a';

        TrieNode* child;
        //preset 
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            return false;
        }

        return isSearchWordUtil(child,word.substr(1));
    }
    bool isSearchWord(string word){
        return isSearchWordUtil(root,word);
    }
};

int main(){
    Trie* root = new Trie();
    root->insertWord("hitesh");
    root->insertWord("hitman");
    root->insertWord("hit");

    (root->isSearchWord("hiteshs")) ? cout<<"The word is there"<<endl : cout<<"the Word is Not There"<<endl;
}   