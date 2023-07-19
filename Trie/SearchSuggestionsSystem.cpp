#include<iostream>
#include<vector>
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
    void printSuggestion(TrieNode* root,vector<string> &temp,string prefix){

        if(root -> isTerminal)
            temp.push_back(prefix);

        TrieNode* prev = root;
        for(int i=0;i<26 && temp.size() != 3;i++){
            TrieNode* next = prev->children[i];

            if(next != NULL ){
                prefix.push_back('a' + i);
                printSuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestion(string searchWord){

        vector<vector<string>> ans;
        TrieNode* prev = root;
        string prefix="";
        for(auto i:searchWord){

            TrieNode* next = prev->children [i - 'a'];

            if(next == NULL)
                break;

            prefix.push_back(i);
            vector<string> temp;
            printSuggestion(next,temp,prefix);

            ans.push_back(temp);
            prev = next;
        } 
        return ans;
    }
};
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Trie* root = new Trie();
        //put all Product
        for(auto i:products)
            root -> insertWord(i);

        return root -> getSuggestion(searchWord);

}
int main(){
    vector<string> products  = {"bags","baggage","banner","box","cloths"};
    string searchWord ="bags";
    vector<vector<string>> ans = suggestedProducts(products,searchWord);
    for(auto i:ans){
        for(auto j : i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
}