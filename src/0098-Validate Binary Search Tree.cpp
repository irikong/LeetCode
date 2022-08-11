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
    bool isValidBST(TreeNode* root) {
        return Helper(root, INT_MIN, INT_MAX);
    }

private:
    bool Helper(TreeNode* curr, long long min, long long max) {
        if (curr == nullptr) return true;
        else if (!(min <= curr->val && curr->val <= max)) return false;
        return Helper(curr->left, min, (long long)curr->val - 1) && Helper(curr->right, (long long)curr->val + 1, max);
    }
};