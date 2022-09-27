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

// #ifdef LOCAL
// #define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
// #else
// #define deb(...) 1
// #endif

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
// template<typename ...Args>
// void logger(string vars, Args&&... values) {
//     cout << vars << " = ";
//     string delim = "";
//     (..., (cout << delim << values, delim = ", "));
//     cout << '\n';
// }

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
    inp(s, string);

    int n = s.size();
    string ans = "";

    char minc = *min_element(all(s));
    char maxc = *max_element(all(s));

    int last = n-1;
    for(char c = maxc; c > minc; --c) {
        while(s[last] == c) last--;
        char rep = min((int) '9', c+1);

        string temp = "";
        for(int i = 0; i <= last; ++i) {
            if(s[i] != c)
                temp += s[i];
        }
        temp += string(count(s.begin(), s.begin() + last + 1, c), rep);
        for(int i = last+1; i < n; ++i) {
            temp += s[i];
        }
        s = temp;

        while(s[last] == rep) last--;
    }


    sort(all(s));

    cout << s;
}

// 314752277691991
// 314752277611999
// 314522611888999
// 314522117888999
// 314221167888999
// 312211567888999
// 122114567888999
// 111334567888999