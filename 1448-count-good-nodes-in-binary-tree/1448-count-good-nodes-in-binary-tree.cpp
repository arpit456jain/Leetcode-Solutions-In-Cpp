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
    int count = 0;
    int mxval = INT_MIN;
    void getans(TreeNode* root,int mx)
    {
        if(root == NULL)
            return;
        
        if(root->val >= mx)
        {
            count++;
            getans(root->left,root->val);
            getans(root->right,root->val);
        }
        else
        {
            getans(root->left,mx);
            getans(root->right,mx);
        }
        return ;
        
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
     
        getans(root,-100000);
        return count;
    
    }
};