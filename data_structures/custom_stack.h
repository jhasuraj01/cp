#pragma once
#include <functional>
#include <stack>
#include <vector>

/**
 * ## Custom Stack
 * Can be used to build min/max/sum/xor Stack using any appropriate associative function
 *
 * ### Initialization:
 * ```cpp
 *  CustomStack<int> st(0, [&](int a, int b) {
 *      return std::max(a, b);
 *  });
 * ```
 * ### Operations:
 * ```cpp
 *  st.custom_value();
 *  st.empty();
 *  st.push(value);
 *  st.pop();
 *  st.size();
 *  st.top();
 * ```
 * 
 * ### References
 * @ref https://cp-algorithms.com/data_structures/stack_queue_modification.html#stack-modification
 */
template <typename T>
class CustomStack {
   private:
    std::stack<std::pair<T, T>> internal_stack;
    std::function<T(T, T)> customize;
    T default_value;

   public:
    CustomStack(T _default_value, std::function<T(T, T)> const &_customize) {
        this->default_value = _default_value;
        this->customize = _customize;
    }

    void push(T x) {
        T new_custom_value = customize(x, custom_value());
        internal_stack.push({x, new_custom_value});
    }

    void pop() {
        internal_stack.pop();
    }

    T top() {
        return internal_stack.top().first;
    }

    bool empty() {
        return internal_stack.empty();
    }

    int size() {
        return internal_stack.size();
    }

    T custom_value() {
        T value = default_value;
        if (!internal_stack.empty()) {
            value = internal_stack.top().second;
        }
        return value;
    }
};