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
    TreeNode *insertIntoBST(TreeNode *root, int val)
	{
		TreeNode **cur = &root;
		while( *cur )
			cur = (val > (*cur)->val) ? &(*cur)->right : &(*cur)->left;
		*cur = new TreeNode(val);
		return root;
	}
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++) root = insertIntoBST(root, preorder[i]);
        return root;
    }
};