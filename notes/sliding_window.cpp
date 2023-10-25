#include <vector>
using std::vector;

/**
 * ## Sliding Window
 *
 * @ref https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template/
 */

int sliding_window(vector<int> &nums) {
    int n = nums.size();
    int start = 0;
    int end = 0;

    int curr_value;
    int final_value;

    while (end < n) {
        // add element at `end` to curr_value

        while (start < end /* && condition for exclusion */) {
            int curr_len = end - start;

            // remove element at `start` from curr_value

            start++;
        }

        // update `final_value` using `curr_value`

        end++;  // position of this line may vary from problem to problem
    }

    return final_value;
}
