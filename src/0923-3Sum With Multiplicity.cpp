class Solution {
public:
    const int mod = pow(10, 9) + 7;

    int GetCombination(int n, int r) {
        long long ret = 1;
        for (int i = 1; i <= r; i++) {
            ret *= n--;
            ret /= i;
            ret %= mod;
        }

        return static_cast<int>(ret);
    }

    int threeSumMulti(vector<int>& arr, int target) {
        int ret = 0;
        map<int, int> m, tempMap;
        for (int num : arr) {
            m[num]++;
        }

        for (auto i = m.begin(); i != m.end(); i++) {
            for (auto j = i; j != m.end(); j++) {
                for (auto k = j; k != m.end(); k++) {
                    if (i->first + j->first + k->first == target) {
                        tempMap[i->first]++;
                        tempMap[j->first]++;
                        tempMap[k->first]++;

                        int temp = 1;
                        for (const auto& kv : tempMap) {
                            if (m[kv.first] < kv.second) {
                                temp = 0;
                                break;
                            }
                            else temp *= GetCombination(m[kv.first], kv.second);
                        }
                        ret = (ret + temp) % mod;
                        tempMap.clear();
                    }
                }
            }
        }

        return ret;
    }
};