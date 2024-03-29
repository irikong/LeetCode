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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int numNode = q.size();
            double average = 0;
            for (int i = 0; i < numNode; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                average += curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            ret.push_back(average / numNode);
        }

        return ret;
    }
};