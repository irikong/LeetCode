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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ret = nullptr;
        Helper(root, p, q, ret);

        return ret;
    }

private:
    unsigned char Helper(TreeNode* curr, const TreeNode* p, const TreeNode* q, TreeNode*& out) {
        unsigned char ret = 0;

        if (curr) {
            ret |= Helper(curr->left, p, q, out);
            if (out) return ret;
            ret |= Helper(curr->right, p, q, out);
            if (out) return ret;

            if (curr == p) ret |= (1 << 0);
            else if (curr == q) ret |= (1 << 1);

            if (ret == 0b11) {
                out = curr;
            }
        }

        return ret;
    }
};