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
    int maxAncestorDiff(TreeNode* root) {
        return Helper(root, root->val, root->val);
    }

private:
    int Helper(TreeNode* curr, int low, int high) {
        if (curr == nullptr) return 0;

        int diff = max(abs(curr->val - low), abs(curr->val - high));
        
        low = min(low, curr->val);
        high = max(high, curr->val);
        int childDiff = max(Helper(curr->left, low, high), Helper(curr->right, low, high));

        return max(diff, childDiff);
    }
};