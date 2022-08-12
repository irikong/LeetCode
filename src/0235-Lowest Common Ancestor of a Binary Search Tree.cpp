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
    int Helper(TreeNode* curr, TreeNode* p, TreeNode* q, TreeNode*& out) {
        int found = 0;

        if (out || !curr) return found;

        if (curr == p || curr == q) found++;
        found += Helper(curr->left, p, q, out);
        if (!out && found == 2) {
            out = curr;
            return found;
        }
        found += Helper(curr->right, p, q, out);
        if (!out && found == 2) {
            out = curr;
            return found;
        }

        return found;
    }
};