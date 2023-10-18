#include "../data_structures/static_hash.h"
#include "../data_structures/rolling_hash.h"
#include<cassert>
#include<string>
#include<iostream>

void hash_test() {
    std::string const test_str = "kwwgeawbqlbspvpzzihsluuidyrtxsnk";
    int n = test_str.size();

    StaticHash s_hash;
    assert(s_hash.compute(test_str) == 3229309);

    RollingHash hash;

    for (int i = 0; i < n; ++i)
    {
        assert(hash.value() == hash.compute(test_str.substr(0, i)));
        hash.push_back(test_str[i]);
    }

    assert(hash.value() == 3229309);
    assert(hash.compute(test_str) == 3229309);

    for (int i = 0; i < n; ++i)
    {
        assert(hash.value() == hash.compute(test_str.substr(i)));
        hash.pop_front();
    }
    assert(hash.value() == 0);
    
	std::cout << "TEST[Rolling Hash]: OK" << std::endl;
	std::cout << "TEST[Static Hash]: OK" << std::endl;
}