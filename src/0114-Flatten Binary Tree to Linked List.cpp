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
    void flatten(TreeNode* root) {
        TreeNode dummy;
        TreeNode* pDummy = &dummy;
        Helper(root, pDummy);
    }

private:
    void Helper(TreeNode* node, TreeNode*& back) {
        if (!node) return;

        back->right = node;
        back->left = nullptr;
        back = node;

        TreeNode* rNode = node->right;
        Helper(node->left, back);
        Helper(rNode, back);
    }
};