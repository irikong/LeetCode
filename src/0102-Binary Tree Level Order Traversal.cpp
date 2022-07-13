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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;

        if (root) q.push(root);
        
        while (!q.empty()) {
            vector<int> levelVec;
            int cnt = q.size();

            while (cnt--) {
				TreeNode* curr = q.front();
                q.pop();

                if (curr) {
                    levelVec.push_back(curr->val);

                    q.push(curr->left);
                    q.push(curr->right);
                }
            }

            if (!levelVec.empty())
                ret.push_back(levelVec);
        }

        return ret;
    }
};