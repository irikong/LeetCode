class StockSpanner {
public:
    StockSpanner() {
        curr = 0;
    }

    int next(int price) {
        int idx = curr;

        while (!st.empty() && st.top().first <= price) {
            idx = st.top().second;
            st.pop();
        }
        st.emplace(price, idx);

        return ++curr - idx;
    }

private:
    stack<pair<int, int>> st; // price, idx
    int curr;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */