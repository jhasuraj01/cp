#include "../libs/disjoint_set.h"
#include <iostream>
#include <algorithm>

void dsu_test() {

    int n = 10;

    DisjointSet dsu(n);

    for(int i = 1; i < n; ++i) {
        assert(dsu.is_same_set(0, i) == false);
        dsu.merge_set(i-1, i);
        assert(dsu.is_same_set(0, i) == true);
    }


    DisjointSet dsu2(n);
    std::vector<int> index(n);
	iota(begin(index), end(index), 0);
    std::random_shuffle(begin(index) + 1, end(index));

    for(int i = 1; i < n; ++i) {
        int zero = index[0];
        int cur_num = index[i];
        int prev_num = index[i-1];

        assert(dsu2.is_same_set(zero, cur_num) == false);
        dsu2.merge_set(prev_num, cur_num);
        assert(dsu2.is_same_set(zero, cur_num) == true);
    }

	std::cout << "TEST[Disjoint Set]: OK" << std::endl;
}