#include "../data_structures/custom_stack.h"

#include <cassert>
#include <iostream>
#include <stack>

void custom_stack_test() {
    // this will work as min stack
    CustomStack<int> cs(0, [&](int a, int b) {
        return std::max(a, b);
    });

    std::stack<int> ns;

    cs.push(1);
    ns.push(1);
    assert(cs.top() == ns.top());
    assert(cs.custom_value() == 1);

    cs.push(2);
    ns.push(2);
    assert(cs.top() == ns.top());
    assert(cs.custom_value() == 2);

    cs.pop();
    ns.pop();
    assert(cs.top() == ns.top());
    assert(cs.custom_value() == 1);

    cs.push(3);
    ns.push(3);
    assert(cs.top() == ns.top());
    assert(cs.custom_value() == 3);

    cs.push(2);
    ns.push(2);
    assert(cs.top() == ns.top());
    assert(cs.custom_value() == 3);

    cs.pop();
    ns.pop();
    cs.pop();
    ns.pop();
    assert(cs.top() == ns.top());
    assert(cs.custom_value() == 1);

    cs.pop();
    ns.pop();
    assert(cs.empty());
    assert(ns.empty());

    cs.push(5);
    ns.push(5);
    assert(cs.top() == ns.top());
    assert(cs.custom_value() == 5);

    cs.pop();
    ns.pop();
    assert(cs.empty());
    assert(ns.empty());

    std::cout << "TEST[Custom Stack]: OK" << std::endl;
}
