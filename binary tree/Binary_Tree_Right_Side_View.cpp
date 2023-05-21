#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
TreeNode* buildTree(TreeNode* root){
    cout<<"Enter the Data"<<endl;
    int data;
    cin>>data;
    root=new TreeNode(data);
    if(data==-1)
        return NULL;

        cout<<"Enter the data in left of "<<root->val<<endl;
        root->left=buildTree(root->left);
        cout<<"Enter the data in right of "<<root->val<<endl;
        root->right=buildTree(root->right);

    return root;
}
void preOrder(TreeNode* root){
    if(root==NULL)
        return;
    cout<<root->val<<"\t";
    preOrder(root->left);
    preOrder(root->right);

}
vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> ans;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                ans.push_back(temp->val);
            }
            result.push_back(ans[ans.size()-1]);
        }
        return result;
}
int main(){
    //1 2 3 -1 -1 -1 4 -1 -1
    TreeNode* root=buildTree(root);
    preOrder(root);
    cout<<endl;
    vector<int> ans=rightSideView(root);
    for(auto i:ans)
        cout<<i<<"\t";
}