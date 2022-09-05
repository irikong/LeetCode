/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (!root) return ret;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> currLevel;
            int cnt = q.size();

            while (cnt--) {
                Node* temp = q.front();
                q.pop();

                currLevel.push_back(temp->val);

                for (Node* child : temp->children)
                    if (child) q.push(child);
            }

            ret.push_back(currLevel);
        }

        return ret;
    }
};