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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> q;
        TreeNode* curr = nullptr;
        
        q.push(root);
        for (int d = 2; d < depth; d++) {
            int qSize = q.size();
            while (qSize--) {
                curr = q.front(); q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        while (!q.empty()) {
            curr = q.front(); q.pop();
            TreeNode* newNode = new TreeNode(val, curr->left, nullptr);
            curr->left = newNode;
            newNode = new TreeNode(val, nullptr, curr->right);
            curr->right = newNode;
        }

        return root;
    }
};