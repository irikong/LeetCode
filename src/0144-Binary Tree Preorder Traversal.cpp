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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;

        Helper(root, ret);

        return ret;
    }

private:
    void Helper(TreeNode* curr, vector<int>& out) {
        if (curr == nullptr) return;

        out.push_back(curr->val);

        Helper(curr->left, out);
        Helper(curr->right, out);
    }
};