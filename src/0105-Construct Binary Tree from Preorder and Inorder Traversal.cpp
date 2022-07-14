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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

private:
    TreeNode* helper(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if (ps == pe) return nullptr;

        TreeNode* root = new TreeNode(preorder[ps]);
        int dist = find(inorder.begin() + is, inorder.begin() + ie, preorder[ps]) - (inorder.begin() + is);

        root->left = helper(preorder, ps + 1, ps + dist + 1, inorder, is, is + dist);
        root->right = helper(preorder, ps + dist + 1, pe, inorder, is + dist + 1, ie);

        return root;
    }
};