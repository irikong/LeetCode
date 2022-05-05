class MyStack {
private:
    queue<int> q;

    void BackToFront() {
        int size = q.size() - 1;
        while (size--) {
            q.push(q.front());
            q.pop();
        }
    }

public:
    MyStack() { }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        BackToFront();

        int ret = q.front();
        q.pop();

        return ret;
    }

    int top() {
        BackToFront();

        int ret = q.front();
        q.push(q.front());
        q.pop();

        return ret;
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */