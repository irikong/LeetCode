class TimeMap {
public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        um[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        for (auto rit = um[key].rbegin(); rit != um[key].rend(); rit++) {
            if (rit->first <= timestamp) return rit->second;
        }

        return string();
    }

private:
    unordered_map<string, map<int, string>> um;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */