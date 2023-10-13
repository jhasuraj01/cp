#include <string>

/**
 * ## Rolling Hash
 * 
 * Examples:
 * 1. `StaticHash hash;`
 * 2. `StaticHash hash(31);`
 * 3. `StaticHash hash(31, 'a');`
 * 4. `StaticHash hash(31, 'a', 1e9+9);`
 * 
 * @ref https://cp-algorithms.com/string/string-hashing.html
 * @ref https://youtu.be/FQ8hcOOzQMU?si=DoImhT7wQD-MgFsM
 */
class StaticHash {
private:
    long long p,m;
    int start_ascii;

public:
    StaticHash(int const p = 257, int const start_ascii = 0, int const m = 1e9+7) {
        this->p = (long long) p;
        this->m = (long long) m;
        this->start_ascii = start_ascii;
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)
    long long compute(std::string const& s) {
        long long computed_hash = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            computed_hash *= p;
            computed_hash %= m;
            computed_hash += (long long) s[i] - start_ascii + 1;
            computed_hash %= m;
        }
        return computed_hash;
    }
};
