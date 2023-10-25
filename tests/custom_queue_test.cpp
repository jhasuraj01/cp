#include "../data_structures/custom_queue.h"

#include <cassert>
#include <iostream>
#include <queue>

void custom_queue_test() {
    // this will work as min stack
    CustomQueue<int> cq(0, [&](int a, int b) {
        return std::max(a, b);
    });

    std::queue<int> nq;

    // Queue: 1
    cq.push(1);
    nq.push(1);
    assert(cq.front() == nq.front());
    assert(cq.custom_value() == 1);

    // Queue: 1 2
    cq.push(2);
    nq.push(2);
    assert(cq.front() == nq.front());
    assert(cq.custom_value() == 2);

    // Queue: 2
    cq.pop();
    nq.pop();
    assert(cq.front() == nq.front());
    assert(cq.custom_value() == 2);

    // Queue: 2 3
    cq.push(3);
    nq.push(3);
    assert(cq.front() == nq.front());
    assert(cq.custom_value() == 3);

    // Queue: 2 3 2
    cq.push(2);
    nq.push(2);
    assert(cq.front() == nq.front());
    assert(cq.custom_value() == 3);

    // Queue: 2
    cq.pop();
    nq.pop();
    cq.pop();
    nq.pop();
    assert(cq.front() == nq.front());
    assert(cq.custom_value() == 2);

    // Queue:
    cq.pop();
    nq.pop();
    assert(cq.empty());
    assert(nq.empty());

    // Queue: 5
    cq.push(5);
    nq.push(5);
    assert(cq.front() == nq.front());
    assert(cq.custom_value() == 5);

    cq.pop();
    nq.pop();
    assert(cq.empty());
    assert(nq.empty());

    std::cout << "TEST[Custom Queue]: OK" << std::endl;
}
