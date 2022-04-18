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
    void Solve(TreeNode* curr, int k, int& cnt, int& ans) {
        if (ans != -1) return;

        if (curr->left) {
            Solve(curr->left, k, cnt, ans);
            cnt++;
        }
        else cnt++;

        if (cnt == k) ans = curr->val;

        if (curr->right) Solve(curr->right, k, cnt, ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans = -1;
        Solve(root, k, cnt, ans);
        return ans;
    }
};