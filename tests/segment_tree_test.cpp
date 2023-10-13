#include "../libs/segment_tree.h"
#include<iostream>
#include<cassert>
#include<vector>
#include<numeric>

void segment_tree_test() {

    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	SegmentTree<int> segment_tree(arr, 0, [&](int a, int b) {
		return a+b;
	});

	int n = (int) arr.size();

	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			int sum = accumulate(arr.begin() + i, arr.begin() + j + 1, 0);
			assert(segment_tree.get(i, j) == sum);
		}
	}

	segment_tree.update(5, -100);
	arr[5] = -100;

	segment_tree.update(1, 10);
	arr[1] = 10;

	segment_tree.update(3, 0);
	arr[3] = 0;

	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			int sum = accumulate(arr.begin() + i, arr.begin() + j + 1, 0);
			assert(segment_tree.get(i, j) == sum);
		}
	}

	std::cout << "TEST[Segment Tree]: OK" << std::endl;
}