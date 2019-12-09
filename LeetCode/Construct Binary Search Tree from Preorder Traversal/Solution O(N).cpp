/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int idx = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int upperBound = INT_MAX) {
        if(idx == preorder.size() || preorder[idx] > upperBound) return NULL;
        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, upperBound);
        return root;
    }
};