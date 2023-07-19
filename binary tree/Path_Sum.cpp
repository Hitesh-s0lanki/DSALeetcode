#include "TreeNode.h"
using namespace std;

bool solve(TreeNode* root, int targetSum,int sum){
    if(root == NULL){
        return false;
    }
    sum += root -> val;
    if(root->left == NULL || root ->right == NULL){
        if(sum == targetSum){
            return true;
        }
        return false;
    }
    bool left = solve(root->left,targetSum,sum);
    bool right = solve(root->right,targetSum,sum);

    return left || right ;
}
bool hasPathSum(TreeNode* root, int targetSum) {
    int sum = 0;
     return  solve(root,targetSum,sum);
}
int main(){

}