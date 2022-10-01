#include<bits/stdc++.h>
using namespace std;
#define ln '\n'
#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define inp(var, type) type var; cin >> var
#define loop(i,a,b) for (int i = a; i < b; ++i)
#define vec(type) vector< type >
#define all(name) name.begin(), name.end()
#define allr(name) name.rbegin(), name.rend()
#define pb push_back

#ifdef LOCAL
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define deb(...) 1
#endif

template <typename T>
ostream& operator<<(ostream& os, pair <T, T> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    for (auto e : v) os << e << " ";
    return os;
}
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << '\n';
}

// Example: https://www.codechef.com/viewsolution/54414764
long long const mod = 1e9+7;
long long inverse_modulo(long long p, long long q)
{
    long long expo = mod - 2;
    while (expo) {
        if (expo & 1) {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
        expo >>= 1;
    }
    return p;
}
// long long const inverse = inverse_modulo(1, 4);

long long binpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solution();

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    inp(T, int);
    loop(t, 0, T) {
        solution();
        cout << ln;
    }

    return 0;
}

void solution() {
    inp(n, int);

    vec(int) prices(n);

    loop(i, 0, n) {
        cin >> prices[i];
    }

    int ans = 0;
    int minp = prices[0];
    
    for(int i = 1; i < prices.size(); ++i) {
        int profit = prices[i] - minp;
        ans = max(ans, profit);
        minp = min(minp, prices[i]);
    }

    cout << ans;
}
