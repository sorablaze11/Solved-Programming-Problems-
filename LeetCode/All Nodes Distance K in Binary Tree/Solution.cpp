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
    void searchForNodes(TreeNode *root, int K, vector<int> &ans){
        if(root == NULL) return;
        // cout << root->val << ' ' << K << '\n';
        if(K == 0){
            ans.push_back(root->val);
            return;
        }
        searchForNodes(root->left, K - 1, ans);
        searchForNodes(root->right, K - 1, ans);
    }
    
    int searchForTarget(TreeNode *root, TreeNode *target, int K, vector<int> &ans){        
        if(root == NULL) return 0;
        // cout << root->val << '\n';
        if(root == target){
            searchForNodes(target, K, ans);
            return -1;
        }
        int isInLeft = searchForTarget(root->left, target, K, ans);
        // cout << isInLeft << '\n';
        if(isInLeft != 0){
            if(K + isInLeft == 0) ans.push_back(root->val);
            if(K + isInLeft > 0) searchForNodes(root->right, K - 1 + isInLeft, ans);
            return isInLeft - 1;
        }
        int isInRight = searchForTarget(root->right, target, K, ans);
        // cout << isInRight << '\n';
        if(isInRight != 0){
            if(K + isInRight == 0) ans.push_back(root->val);
            if(K + isInRight > 0) searchForNodes(root->left, K - 1 + isInRight, ans);
            return isInRight - 1;
        }
        return 0;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        if(root == target){
            searchForNodes(root, K, ans);
        }else{
            searchForTarget(root, target, K, ans);
        }
        return ans;
    }
};