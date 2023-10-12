// Ref: https://cp-algorithms.com/string/string-hashing.html
// Ref: https://youtu.be/FQ8hcOOzQMU?si=DoImhT7wQD-MgFsM
// Time Complexity: O(N)
// Space Complexity: O(1)
// Example 1: StaticHash hash;
// Example 2: StaticHash hash(31);
// Example 3: StaticHash hash(31, 'a');
// Example 4: StaticHash hash(31, 'a', 1e9+9);

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
