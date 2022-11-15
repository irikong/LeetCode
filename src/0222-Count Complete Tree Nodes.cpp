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
    int countNodes(TreeNode* root) {
        TreeNode* l = root;
        TreeNode* r = root;
        int completeLevel = 0;

        while (r) {
            l = l->left;
            r = r->right;
            completeLevel++;
        }

        if (l == nullptr)
            return pow(2, completeLevel) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};