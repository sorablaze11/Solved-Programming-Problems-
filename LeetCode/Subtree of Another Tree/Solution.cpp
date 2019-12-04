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
    bool isPerfectSubtree(TreeNode *s, TreeNode *t){
        if(s == NULL && t == NULL) return true;
        if(s->val == t->val && s->left == NULL && t->left == NULL && s->right == NULL && t->right == NULL) return true;
        if(s->val != t->val) return false;
        if(s->left == NULL && t->left != NULL) return false;
        if(s->right == NULL && t->right != NULL) return false;
        if(s->left != NULL && t->left == NULL) return false;
        if(s->right != NULL && t->right == NULL) return false;
        return (isPerfectSubtree(s->right, t->right) && isPerfectSubtree(s->left, t->left));
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {    
        if(s == NULL || t == NULL) return false;
        bool matchFound = false;
        if(s->val == t->val) matchFound = isPerfectSubtree(s, t);
        return (matchFound || isSubtree(s->left, t) || isSubtree(s->right, t));
    }
};