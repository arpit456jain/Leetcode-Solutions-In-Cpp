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
    double findavg(vector<int> &v)
    {
        double sum1 = 0;
        for(auto i : v)
            sum1 += i;
        int n = v.size();
        return sum1/n;
    }
    vector<double> LevelOrderTravesel(TreeNode *root)
    {
        vector<double> outer;
        if(root == NULL)
            return outer;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> inner = {};
            int count = q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left!=NULL)
                q.push(temp->left);

                if(temp->right!=NULL)
                q.push(temp->right);
                
                inner.push_back(temp->val);
            }
           
            double avg = findavg(inner);
            outer.push_back(avg);
           
        }
           
        return outer;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        
        return LevelOrderTravesel(root);
        
    }
};