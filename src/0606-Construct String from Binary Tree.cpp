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
    string tree2str(TreeNode* root) {
        return Helper(root);
    }

private:
    string Helper(TreeNode* curr) {
        if (!curr) return "";

        string ret = to_string(curr->val);

        if(curr->left) ret += "(" + Helper(curr->left) + ")";
        if (curr->right) {
            if (curr->left == nullptr) ret += "()";
            ret += "(" + Helper(curr->right) + ")";
        }

        return ret;
    }
};