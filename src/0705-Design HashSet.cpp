class MyHashSet {
private:
    vector<list<int>> buckets;

    list<int>::iterator FindInBucket(int idx, int key) {
        return find(buckets[idx].begin(), buckets[idx].end(), key);
    }

public:
    MyHashSet() {
        buckets = vector<list<int>>(10007, list<int>());
    }

    void add(int key) {
        int idx = key % buckets.size();
        auto it = FindInBucket(idx, key);
        if (it == buckets[idx].end())
            buckets[idx].push_back(key);
    }

    void remove(int key) {
        int idx = key % buckets.size();
        auto it = FindInBucket(idx, key);
        if (it != buckets[idx].end())
            buckets[idx].erase(it);
    }

    bool contains(int key) {
        int idx = key % buckets.size();
        return FindInBucket(idx, key) != buckets[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */