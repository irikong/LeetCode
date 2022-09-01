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
    int goodNodes(TreeNode* root) {
        return Helper(root->left, root->val) + Helper(root->right, root->val) + 1;
    }

private:
    int Helper(TreeNode* curr, int greatest) {
        if (curr == nullptr) return 0;

        int ret = 0;
        if (curr->val >= greatest) {
            greatest = curr->val;
            ret++;
        }

        ret += Helper(curr->left, greatest);
        ret += Helper(curr->right, greatest);

        return ret;
    }
};