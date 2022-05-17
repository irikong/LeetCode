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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return DFS(cloned, target->val);
    }

private:
    TreeNode* DFS(TreeNode* curr, const int& target) {
        if (curr->val == target) {
            return curr;
        }

        TreeNode* ret;
        if (curr->left) ret = DFS(curr->left, target);
        if (ret) return ret;

        if (curr->right) ret = DFS(curr->right, target);
        if (ret) return ret;

        return nullptr;
    }
};