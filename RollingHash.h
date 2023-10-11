// Ref: https://cp-algorithms.com/string/string-hashing.html
// Time Complexity: O(N)
// Space Complexity: O(N)

class RollingHash {
private:
    vector<long long> p_power_cache;
    long long p,m;

    long long p_power(int i) {
        int len = p_power_cache.size();

        while(len <= i) {
            deb(len);
            long long next_power = (p_power_cache[len - 1] * p) % m;
            p_power_cache.push_back(next_power);
            len++;
        }

        return p_power_cache[i];
    }
public:
    RollingHash(int const p = 31, int const m = 1e9+7) {
        this->p = (long long) p;
        this->m = (long long) m;
        this->p_power_cache.push_back(1);
    }

    long long compute(string const& s) {
        long long hash_value = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            long long power_i = p_power(i);
            long long char_val = s[i] - 'a' + 1;
            hash_value += char_val * power_i;
            hash_value %= m;
        }
        return hash_value;
    }
};
