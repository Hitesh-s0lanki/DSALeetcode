#include<iostream>
#include<vector>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char data){
        this->data=data;
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
    void insertUtil(TrieNode* root,string word){
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }
        int index = word[0]-'a';

        TrieNode* child;
        //present 
        if(root -> children[index] != NULL){
            child = root ->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        //Recursive call
        insertUtil(child,word.substr(1));

    }
    void insert(string word){
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode* root,string word){
        if(word.length() == 0){
            return root -> isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root -> children [index] != NULL){
            child = root ->children[index];
        }
        else{
            //absent
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
    bool search(string word){
        return searchUtil(root,word);
    }
    void getString(TrieNode* root,string &ans,string word){

        if(word.length() == 0 || root -> isTerminal)
            return;

        int index = word[0] - 'a';

        ans.push_back(root ->children[index]->data);

        TrieNode* child;
        //present
        child = root ->children[index];

        getString(child,ans,word.substr(1));
    }
    string replaceWordsUtil(string sentence){
        string ans;
        for(int i=0;i<sentence.size();i++){
            int index = sentence[i] - 'a';
            if(root -> children[index] == NULL){
                while(i<sentence.length() && sentence[i] != 32){
                    ans.push_back(sentence[i++]);
                }
                if(i<sentence.length() && sentence[i] == 32)
                    ans.push_back(' ');
            }
            else{
                string temp;
                while(i<sentence.length() && sentence[i] != 32)
                    temp.push_back(sentence[i++]);
                string ans2;
                getString(root,ans2,temp);
                ans+=ans2;
                if(i<sentence.length() && sentence[i] == 32)
                    ans.push_back(' ');

            }
        }
        return ans;
    }
};
string replaceWords(vector<string>& dictionary, string sentence) {
    Trie* root = new Trie();
    for(auto i:dictionary)
        root->insert(i);

    return root->replaceWordsUtil(sentence);
}
int main(){
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    cout<<replaceWords(dictionary,sentence);
}