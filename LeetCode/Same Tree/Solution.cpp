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
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) return true;
        if(s == NULL || t == NULL) return false;
        if(s->val != t->val) return false;
        return (isSameTree(s->right, t->right) && isSameTree(s->left, t->left));
    }
};