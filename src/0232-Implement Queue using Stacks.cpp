class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        first.push(x);
    }

    int pop() {
        if (second.empty()) refill();

        int top = second.top();
        second.pop();

        return top;
    }

    int peek() {
        if (second.empty()) refill();

        return second.top();
    }

    bool empty() {
        return first.empty() && second.empty();
    }

private:
    stack<int> first;
    stack<int> second;

    void refill() {
        while (!first.empty()) {
            second.push(first.top());
            first.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */