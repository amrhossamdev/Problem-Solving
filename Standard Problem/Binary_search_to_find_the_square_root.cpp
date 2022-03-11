#include <bits/stdc++.h>
//binary search to find the square root of any number to a certain precision.
//https://codeforces.com/group/T3p02rhrmb/contest/343396/problem/T
//Created By @amrhossamdev
using namespace std;
typedef long long ll;
typedef long double lld;
typedef map<string, int> map1;
#define endl '\n';

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)                ((v).begin()), ((v).end())
#define pb                    push_back
#define MP                    make_pair
#define py cout<<"YES\n";
#define pn cout<<"NO\n"
#define clr(x, val) memset(x,val,sizeof(x))
const int N = 1e6 + 3;
#define OUT 0
#define IN 1
#define getin(n) for(int i =0;i<n;++i)
#define l(i, s, n) for(int i=s ; i<n ; i++)
#define le(i, s, n) for(int i=s ; i<=n ; i++)
#define lr(i, e, n) for (ll i= n ; i>=e ; i--)

void sieve(ll n) {
    int ans = 0;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = 0, isPrime[1] = 0;
    for (int i = 2; i * i <= n; ++i)
        if (isPrime[i])
            for (int j = i * 2; j <= n; j += i) isPrime[j] = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 2; j <= i; ++j) {
            if (isPrime[j]) {
                if (i % (j) == 0) {
                    ++cnt;
                }
            }
        }
        if (cnt == 2)++ans;

    }
    cout << ans;
}

ll fastpower(ll base, unsigned int exp) {
    if (exp == 0)
        return 1;
    int temp = fastpower(base, (exp / 2));
    if (exp % 2 == 0) return (temp * temp);
    else return (base * temp * temp);
}

bool isPrime(ll n) {
    if (n == 2) {
        return true;
    }
    if (n < 2 || n % 2 == 0) {
        return false;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

struct comp {
    template<typename T>
    bool operator()(const T &l,
                    const T &r) const {
        if (l.second != r.second) {
            return l.second > r.second;
        }
        return l.first > r.first;
    }
};

bool comp2(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
    if (a.first == b.first)
        return a.second.second > b.second.second;
    return (a.first < b.first);
}

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

bool isPowerOfTwo(int n) {
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

int binarySearch(vector<int> arr, int l, int r, int m) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (m == arr[mid]) return mid;
        else if (arr[mid] < m) l = mid + 1;
        else {
            r = mid - 1;
        }
    }
    return -1;
}

void solve() {
    double x;
    cin >> x;

    double l = 1;
    double r = x;
    double ans;
    while (l < r) {
        double mid = l + (r - l) / 2;
        if (mid * mid == x) {
            ans = mid;
            break;
        }
        if (mid * mid > x) {
            r = mid - 1;
        }
        if (mid * mid < x) {
            l = mid + 1;
            ans = mid;
        }

    }
    double inc = 0.1;
    l(i, 0, 9) { // number of precisions
        while (ans * ans <= x) {
            ans += inc;
        }
        ans -= inc;
        inc /= 10;
    }
    cout << fixed << setprecision(9) << ans;

}

int main() {

    fast
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}
