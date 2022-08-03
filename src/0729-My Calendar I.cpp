class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        if (events.empty() || events.back().second <= start) {
            events.emplace_back(start, end);
            return true;
        }
        else if (end <= events[0].first) {
            events.insert(events.begin(), { start, end });
            return true;
        }

        int l = 0, r = events.size() - 1, m;

        while (l < r) {
            m = l + (r - l) / 2;

            if (start < events[m].second)
                r = m;
            else
                l = m + 1;
        }

        if (end <= events[r].first) {
            events.insert(events.begin() + r, { start, end });
            return true;
        }

        return false;
    }

private:
    vector<pair<int, int>> events;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */