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
    TreeNode* pruneTree(TreeNode* root) {
        return Helper(root) ? root : nullptr;
    }

private:
    bool Helper(TreeNode* curr) {
        if (!curr) return false;

        bool left = Helper(curr->left);
        if (!left) curr->left = nullptr;
        bool right = Helper(curr->right);
        if (!right) curr->right = nullptr;

        bool ret = curr->val || left || right;
        if (!ret) delete curr;

        return ret;
    }
};