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
    void goDown(TreeNode* parent, TreeNode* child, int v, int d, int currDepth, int left){
        if(currDepth == d){
            TreeNode *node = new TreeNode(v);
            if(left) {
                node->left = child;
                parent->left = node;
            }
            else{
                node->right = child;
                parent->right = node;
            }
            return;
        }
        if(child != NULL) goDown(child, child->left, v, d, currDepth + 1, 1);
        if(child != NULL) goDown(child, child->right, v, d, currDepth + 1, 0);
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            root = newroot;
        }else goDown(NULL, root, v, d, 1, 1);
        return root;
    }
};