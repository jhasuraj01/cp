#include <cassert>
#include <queue>
#include <string>

/**
 * ## Rolling Hash
 *
 * Examples:
 * 1. `RollingHash hash;`
 * 2. `RollingHash hash(31);`
 * 3. `RollingHash hash(31, 'a');`
 * 4. `RollingHash hash(31, 'a', 1e9+9);`
 *
 * @ref https://cp-algorithms.com/string/string-hashing.html
 * @ref https://youtu.be/FQ8hcOOzQMU?si=DoImhT7wQD-MgFsM
 */
class RollingHash {
   private:
    std::vector<long long> p_power_cache;
    long long p, m;
    int start_ascii;
    long long hash_value;
    int str_len;
    std::queue<char> char_queue;

    // Avg. Time Complexity: O(1)
    // Max. Time Complexity: O(N)
    // Space Complexity: O(N)
    long long p_power(int i) {
        int len = p_power_cache.size();

        while (len <= i) {
            long long next_power = (p_power_cache[len - 1] * p) % m;
            p_power_cache.push_back(next_power);
            len++;
        }

        return p_power_cache[i];
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)
    long long char_hash_value(char const& c) {
        return (long long)c - start_ascii + 1;
    }

   public:
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    RollingHash(int const p = 257, int const start_ascii = 0, int const m = 1e9 + 7) {
        this->p = (long long)p;
        this->m = (long long)m;
        this->start_ascii = start_ascii;
        this->p_power_cache.push_back(1);
        this->clear();
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)
    long long value() {
        return hash_value;
    }

    // Time Complexity: O(N)
    // Space Complexity: O(1)
    void push_back(std::string const& s) {
        for (char const& c : s) push_back(c);
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)
    void push_back(char const& c) {
        str_len += 1;
        char_queue.push(c);
        hash_value *= p;
        hash_value %= m;
        hash_value += char_hash_value(c);
        hash_value %= m;
    }

    // Avg. Time Complexity: O(1)
    // Max. Time Complexity: O(N)
    // Space Complexity: O(N)
    void pop_front() {
        assert(str_len > 0);

        long long char_hash = char_hash_value(char_queue.front());
        long long power = p_power(str_len - 1);

        hash_value -= (char_hash * power) % m;
        hash_value += m;
        hash_value %= m;

        char_queue.pop();
        str_len -= 1;
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)
    void clear() {
        str_len = 0;
        hash_value = 0;
        char_queue = std::queue<char>();
    }

    // Time Complexity: O(N)
    // Space Complexity: O(1)
    long long compute(std::string const& s) {
        long long computed_hash = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            computed_hash *= p;
            computed_hash %= m;
            computed_hash += char_hash_value(s[i]);
            computed_hash %= m;
        }
        return computed_hash;
    }
};
