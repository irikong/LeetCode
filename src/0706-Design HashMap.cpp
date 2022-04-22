class MyHashMap {
private:
    vector<list<pair<int, int>>> buckets;

    const int bucketSize = 10007;
    list<pair<int, int>>::iterator FindInBucket(int idx, int key) {
        return find_if(buckets[idx].begin(), buckets[idx].end(), [&key](const pair<int, int>& p) { return p.first == key; });
    }

public:
    MyHashMap() {
        buckets = vector<list<pair<int, int>>>(bucketSize, list<pair<int, int>>());
    }

    void put(int key, int value) {
        int idx = key % bucketSize;
        auto it = FindInBucket(idx, key);

        if (it != buckets[idx].end())
            it->second = value;
        else
            buckets[idx].emplace_back(key, value);
    }

    int get(int key) {
        int idx = key % bucketSize;
        auto it = FindInBucket(idx, key);

        return it == buckets[idx].end() ? -1 : it->second;
    }

    void remove(int key) {
        int idx = key % bucketSize;
        auto it = FindInBucket(idx, key);

        if (it != buckets[idx].end())
            buckets[idx].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */