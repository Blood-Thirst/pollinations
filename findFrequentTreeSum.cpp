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
    unordered_map<int,int>mp;
    int dfs(TreeNode*cur)
    {
        int sum=cur->val;
        if(cur->left)
        {
            sum+=dfs(cur->left);
        }
        if(cur->right)
        {
            sum+=dfs(cur->right);
        }
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        mp.clear();
        dfs(root);
        int mx=0;
        for(auto x:mp)
        {
            mx=max(mx,x.second);
        }
        vector<int>sol;
        for(auto x:mp)
        {
            if(x.second==mx)
            {
                sol.push_back(x.first);
            }
        }
        return sol;
    }
};
