#include <vector>
#include <algorithm>
#include <cassert>

/**
 * ## Combination : nCr
 * 
 * ### Initialization:
 * ```cpp
 * Combination combination(n, r);
 * ```
 * ### Operations:
 * ```cpp
 *  combination.is_selected(i);
 *  combination.next();
 *  combination.current_state();
 * ```
*/
class Combination {
private:
	std::vector<bool> selection_state;
	int n;
public:
	Combination(int _n, int _r) {
		n = _n;
		selection_state = std::vector<bool>(n, false);
		for(int i = 0; i < _r; ++i)
			selection_state[i] = true;
	}

	bool next() {
		return next_permutation(rbegin(selection_state), rend(selection_state));
	}

	bool is_selected(int i) {
		assert(i < n);
		return selection_state[i];
	}

	std::vector<bool> current_state() {
		return selection_state;
	}
};