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

        bool lCheck = curr->left ? curr->val > curr->left->val : true;
        bool rCheck = curr->right ? curr->val < curr->right->val : true;

        if (lCheck && rCheck)
            return Helper(curr->left, min, (long long)curr->val - 1) && Helper(curr->right, (long long)curr->val + 1, max);

        return false;
    }
};