#include <vector>
#include <numeric>
#include <cassert>

class DisjointSet {
private:
    int size;
	std::vector<int> parent;
	std::vector<int> rank;
public:
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    DisjointSet(int _size) {
        assert(_size > 0);

        this->size = _size;
        this->rank = std::vector<int>(_size, 0);
        this->parent = std::vector<int>(_size);
		iota(begin(parent), end(parent), 0);
    }

    // Avg. Time Complexity: O(1)
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    int find_set(int node) {

        assert(node >= 0);
        assert(node < this->size);

        int ans = node;

        while(ans != parent[ans])
            ans = parent[ans];
        
        // path compression optimization
        while(node != parent[node]) {
            int node_parent = parent[node];
            parent[node] = ans;
            node = node_parent;
        }

        return ans;
    }

    bool is_same_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        return a == b;
    }

    // Amortized Time Complexity: O(1)
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    int merge_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if(a == b) return a;

        if (rank[a] < rank[b]) std::swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;

        return a;
    }
};