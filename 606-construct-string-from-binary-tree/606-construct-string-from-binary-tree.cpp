/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root,vector<string> &ans)
    {
         if(root == NULL)
         {
             return ;
         }
        
        ans[0] += to_string(root->val);
        if(root->left == NULL and root->right!=NULL)
            ans[0]+="()";
        if(root->left != NULL)
        {
            ans[0]+='(';
            preorder(root->left, ans);
            ans[0]+=')';
        }
        if(root->right != NULL)
        {
            ans[0]+='(';
            preorder(root->right, ans);
            ans[0]+=')';
        }
        
        
        return;
    }
    string tree2str(TreeNode* root) {
     
        vector<string> ans;
        ans.push_back("");
        preorder(root,ans);
        
        return ans[0];
        
    }
};