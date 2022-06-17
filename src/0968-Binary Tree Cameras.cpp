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
    int minCameraCover(TreeNode* root) {
        int ret = 0;

        if(PostOrder(root, ret) == MonitorFalse) ret++;

        return ret;
    }

private:
    enum State {
        MonitorFalse = -1,
        Camera,
        MonitorTrue
    };

    State PostOrder(TreeNode* node, int& ret) {
        if (!node) return MonitorTrue;
        
        State l = PostOrder(node->left, ret);
        State r = PostOrder(node->right, ret);
        
        if (l == MonitorFalse || r == MonitorFalse) {
            ret++;
            return Camera;
        }
        else if (l == Camera || r == Camera) {
            return MonitorTrue;
        }
        else {
            return MonitorFalse;
        }
    }
};