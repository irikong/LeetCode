class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> alpha;
        for (char c : sentence) {
            alpha.insert(c);
        }

        return alpha.size() == 26;
    }
};