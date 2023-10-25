template <typename T>
class QueueUsingStack {
   private:
    stack<T> s1, s2;
    void preprocess() {
        if (!s2.empty()) return;
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

   public:
    QueueUsingStack() {
    }

    void push(T x) {
        s1.push(x);
    }

    void pop() {
        preprocess();
        s2.pop();
    }

    int top() {
        preprocess();
        return s2.top();
    }

    bool empty() {
        return s1.size() + s2.size() == 0;
    }
};