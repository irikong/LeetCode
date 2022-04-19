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
private:
    void SearchErrorNode(TreeNode*& node, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
        if (!node) return;

        SearchErrorNode(node->left, prev, first, second);

        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }
        prev = node;

        SearchErrorNode(node->right, prev, first, second);
    }

public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        SearchErrorNode(root, prev, first, second);
        swap(first->val, second->val);
    }
};