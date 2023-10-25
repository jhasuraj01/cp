#include "../algorithms/combination.cpp"

#include <iostream>
#include <vector>

void combination_test() {
    int n = 4;
    int r = 3;

    Combination combination(n, r);

    std::vector<std::vector<int>> all_combination;

    do {
        std::vector<int> current_combination;
        for (int i = 0; i < n; ++i)
            if (combination.is_selected(i))
                current_combination.push_back(i);
        all_combination.push_back(current_combination);
    } while (combination.next());

    std::vector<std::vector<int>> ans = {
        {0, 1, 2},
        {0, 1, 3},
        {0, 2, 3},
        {1, 2, 3}};

    assert(all_combination.size() == ans.size());

    int csize = (int)all_combination.size();

    for (int i = 0; i < n; ++i) {
        assert(all_combination[i].size() == ans[i].size());
        int sub_size = all_combination[i].size();

        for (int j = 0; j < sub_size; ++j) {
            assert(all_combination[i][j] == ans[i][j]);
        }
    }

    std::cout << "TEST[Combination]: OK" << std::endl;
}