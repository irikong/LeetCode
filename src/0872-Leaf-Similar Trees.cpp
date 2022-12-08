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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;

        Helper(root1, v1);
        Helper(root2, v2);

        return v1 == v2;
    }

private:
    void Helper(TreeNode* curr, vector<int>& leafs) {
        if (curr == nullptr) return;

        int leafCnt = leafs.size();

        if (curr->left)
            Helper(curr->left, leafs);
        if (curr->right)
            Helper(curr->right, leafs);

        if(leafCnt == leafs.size())
			leafs.push_back(curr->val);
    }
};