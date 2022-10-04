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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        return Helper(root, targetSum);
    }

private:
    bool Helper(TreeNode* curr, int targetSum) {
        targetSum -= curr->val;
        if (!curr->left && !curr->right) return targetSum == 0;

        bool left = curr->left ? Helper(curr->left, targetSum) : false;
        bool right = curr->right ? Helper(curr->right, targetSum) : false;

        return  left || right;
    }
};