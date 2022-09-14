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
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> vec(10, 0);
        int ret = 0;
        DFS(root, vec, ret);

        return ret;
    }

private:
    void DFS(TreeNode* curr, vector<int>& vec, int& out) {
        bool hasChild = false;

        vec[curr->val]++;

        if (curr->left) {
            hasChild = true;
            DFS(curr->left, vec, out);
        }
        if (curr->right) {
            hasChild = true;
            DFS(curr->right, vec, out);
        }

        if (!hasChild) {
            int odd = 0;

            for (int num : vec)
                odd += num & 1;

            if (odd <= 1) out++;
        }

        vec[curr->val]--;
    }
};