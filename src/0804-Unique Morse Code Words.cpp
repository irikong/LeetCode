class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morseCode[26] = { 
            ".-","-...","-.-.","-..",".",
            "..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",
            ".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--",
            "--.."
        };

        unordered_set<string> codeSet;
        for (string& word : words) {
            string code;
            for (char& c : word) {
                code += morseCode[c - 'a'];
            }

            codeSet.insert(code);
        }

        return codeSet.size();
    }
};