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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> q;

        if (root) q.push(root);

        while (!q.empty()) {
            int cnt = q.size(), last;

            while (cnt--) {
                TreeNode* tn = q.front();
                q.pop();

                last = tn->val;
                if (tn->left) q.push(tn->left);
                if (tn->right) q.push(tn->right);
            }

            ret.push_back(last);
        }

        return ret;
    }
};