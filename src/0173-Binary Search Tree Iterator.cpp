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
class BSTIterator {
private:
    vector<int> elements;
    int currIdx;

    void InOrderTraversal(TreeNode* node) {
        if (node) {
            InOrderTraversal(node->left);
            elements.push_back(node->val);
            InOrderTraversal(node->right);
        }
    }

public:
    BSTIterator(TreeNode* root) {
        InOrderTraversal(root);
        currIdx = -1;
    }

    int next() {
        return elements[++currIdx];
    }

    bool hasNext() {
        return currIdx != elements.size() - 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */