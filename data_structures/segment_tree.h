#include <functional>
#include <vector>

/**
 * ## Segment Tree
 *
 * ### Initialization:
 * ```cpp
 *  SegmentTree<int> segment_tree(arr, 0, [&](int a, int b) {
 *  	return a+b;
 *  });
 * ```
 * ### Operations:
 * ```cpp
 *  segment_tree.update(i, value);
 *  segment_tree.get(i, j)
 * ```
 */
template <typename T>
class SegmentTree {
   private:
    int tree_size;
    int array_size;
    T default_value;
    std::vector<T> tree;
    std::function<T(T, T)> merge;

    // Time Complexity: O(N)
    // Space Complexity: O(N)
    void build(std::vector<T> const &arr) {
        tree = std::vector<T>(tree_size, default_value);

        int offset = index(0);
        for (int const &num : arr)
            tree[offset++] = num;

        for (int i = tree_size - 2; i > 0; i -= 2) {
            int parent = i / 2;
            int left = i;
            int right = i + 1;
            tree[parent] = merge(tree[left], tree[right]);
        }
    }

    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    void compute_tree_length(int n) {
        tree_size = 1;
        while (tree_size < n)
            tree_size <<= 1;
        tree_size <<= 1;
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)
    int index(int i) {
        return (tree_size >> 1) + i;
    }

    // Time Complexity: O(log N)
    // Space Complexity: O(log N)
    T range_query(int start_index, int end_index, int parent_node, int left_bound, int right_bound) {
        if (start_index == left_bound && end_index == right_bound)
            return tree[parent_node];

        int left_node = parent_node * 2;
        int right_node = left_node + 1;
        int mid = (left_bound + right_bound) / 2;

        T left_result = default_value;
        T right_result = default_value;

        if (start_index <= mid)
            left_result = merge(default_value, range_query(start_index, std::min(mid, end_index), left_node, left_bound, mid));

        if (end_index > mid)
            right_result = merge(range_query(std::max(mid + 1, start_index), end_index, right_node, mid + 1, right_bound), default_value);

        T result = merge(left_result, right_result);

        return result;
    }

   public:
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    SegmentTree(std::vector<T> const &arr, T _default_value, std::function<T(T, T)> const &_calc) {
        this->default_value = _default_value;
        this->merge = _calc;
        array_size = (int)arr.size();

        compute_tree_length(array_size);
        build(arr);
    }

    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    void update(int _idx, T const &value) {
        int idx = index(_idx);
        tree[idx] = value;

        int parent = idx / 2;

        while (parent != 0) {
            int left = parent * 2;
            int right = left + 1;
            tree[parent] = merge(tree[left], tree[right]);
            parent = parent / 2;
        }
    }

    // Time Complexity: O(log N)
    // Space Complexity: O(log N)
    T get(int start_index, int end_index) {
        return range_query(start_index, end_index, 1, 0, (tree_size >> 1) - 1);
    }
};
