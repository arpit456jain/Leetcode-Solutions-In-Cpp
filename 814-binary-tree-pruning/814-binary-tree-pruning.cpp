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
    int getans(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        if(root->left == NULL and root->right == NULL and root->val == 0)
            return 0;
        if(root->left == NULL and root->right == NULL and root->val == 1)
            return 1;
        
        int lc = getans(root->left);
        int rc = getans(root->right);
        
        if(lc==0)
            root->left = NULL;
        if(rc == 0)
            root->right = NULL;
        
        if(root->val == 1)
            return lc + rc + 1;
        else
            return lc + rc;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
            return root;
        
        int c = getans(root);
        if(c==0)
            return NULL;
        return root;
        
    }
};