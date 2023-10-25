#include "../data_structures/queue_using_stack.h"

#include <cassert>
#include <iostream>
#include <queue>

void queue_using_stack_test() {
    QueueUsingStack<int> q1;
    std::queue<int> q2;

    q1.push(1);
    q2.push(1);
    assert(q1.front() == q2.front());

    q1.push(2);
    q2.push(2);
    assert(q1.front() == q2.front());

    q1.pop();
    q2.pop();
    assert(q1.front() == q2.front());

    q1.push(3);
    q2.push(3);
    assert(q1.front() == q2.front());

    q1.pop();
    q2.pop();
    assert(q1.front() == q2.front());

    q1.pop();
    q2.pop();
    assert(q1.empty());
    assert(q2.empty());

    q1.push(5);
    q2.push(5);
    assert(q1.front() == q2.front());

    q1.pop();
    q2.pop();
    assert(q1.empty());
    assert(q2.empty());

    std::cout << "TEST[Queue Using Stack]: OK" << std::endl;
}
