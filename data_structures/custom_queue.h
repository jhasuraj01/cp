#pragma once
#include <functional>
#include <stack>
#include <vector>

#include "custom_stack.h"

/**
 * ## Custom Queue
 * Can be used to build min/max/sum/xor Queue using any appropriate associative function
 *
 * ### Initialization:
 * ```cpp
 *  CustomQueue<int> qu(0, [&](int a, int b) {
 *      return std::max(a, b);
 *  });
 * ```
 * ### Operations:
 * ```cpp
 * qu.custom_value()
 * qu.empty()
 * qu.front()
 * qu.push(value)
 * qu.pop()
 * qu.size()
 * ```
 * 
 * ### References
 * @ref https://cp-algorithms.com/data_structures/stack_queue_modification.html#queue-modification-method-3
 */
template <typename T>
class CustomQueue {
   private:
    CustomStack<T> s1, s2;
    std::function<T(T, T)> customize;
    T default_value;

    void preprocess() {
        if (!s2.empty()) return;
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

   public:
    CustomQueue(T _default_value, std::function<T(T, T)> const &_customize) : s1(_default_value, _customize), s2(_default_value, _customize) {
        this->default_value = _default_value;
        this->customize = _customize;
    }

    T front() {
        preprocess();
        return s2.top();
    }

    void push(T x) {
        s1.push(x);
    }

    void pop() {
        preprocess();
        s2.pop();
    }

    bool empty() {
        return s1.size() + s2.size() == 0;
    }

    int size() {
        return s1.size() + s2.size();
    }

    T custom_value() {
        return customize(s1.custom_value(), s2.custom_value());
    }
};