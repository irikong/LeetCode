class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        
        while (--n) {
            string temp = "";
			char prev = ret[0];
			int cnt = 1;
            
            for (int i = 1; i < ret.size(); i++) {
                if (ret[i] != prev) {
                    temp.append(to_string(cnt));
                    temp.push_back(prev);
                    cnt = 0;
                }
                
                prev = ret[i];
                cnt++;
            }
            temp.append(to_string(cnt));
            temp.push_back(prev);

            ret = temp;
        }

        return ret;
    }
};