class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> pathMap;
        
        for (string& s : paths) {
            int pos = s.find(' ');
            string path = s.substr(0, pos) + "/";

            int prev = pos;
            int fileEnd;
            string content;
            unordered_map<string, vector<string>>::iterator iter;

            while ((pos = s.find(' ', prev + 1)) != string::npos) {
                fileEnd = s.find('(', prev);
                content = s.substr(fileEnd + 1, pos - fileEnd - 2);

                pathMap[content].push_back(path + s.substr(prev + 1, fileEnd - prev - 1));
                prev = pos;
            }
            fileEnd = s.find('(', prev);
            content = s.substr(fileEnd + 1);
            content.pop_back();

            pathMap[content].push_back(path + s.substr(prev + 1, fileEnd - prev - 1));
        }

        vector<vector<string>> ret;

        for (auto it = pathMap.begin(); it != pathMap.end(); it++) {
            if(it->second.size() > 1)
				ret.push_back(it->second);
        }

        return ret;
    }
};