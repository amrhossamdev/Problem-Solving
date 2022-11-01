//https://atcoder.jp/contests/dp/tasks/dp_d
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef map<string, int> map1;
#define endl '\n';

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

#define fast               \
      ios::sync_with_stdio(0); \
      cin.tie(0);              \
      cout.tie(0);
#define all(v) ((v).begin()), ((v).end())
#define pb push_back
#define MP make_pair
#define py cout << "YES\n";
#define pn cout << "NO\n"
#define clr(x, val) memset(x, val, sizeof(x))
#define OUT 0
#define IN 1
#define getin(n) for (int i = 0; i < n; ++i)
#define l(i, s, n) for (int i = s; i < n; i++)
#define le(i, s, n) for (int i = s; i <= n; i++)
#define ln(i, e, n) for (ll i = n; i >= e; i--)

vector<pair<ll, ll>> items;

ll n, w;
const int N = 102;
const int M = 1e5 + 20;

ll dp[N][M];


ll solve(int index, int curCapacity) {

    if (index == n) { return 0; }

    if (dp[index][curCapacity] != -1) {
        return dp[index][curCapacity];
    }
    ll leave = 0 + solve(index + 1, curCapacity);
    ll take = 0;
    if (curCapacity >= items[index].first) {
        take = items[index].second + solve(index + 1, curCapacity - items[index].first);
    }
    return dp[index][curCapacity] = max(leave,take);

}

void solve() {

    cin >> n >> w;
    memset(dp,-1,sizeof (dp));
    l(i, 0, n) {
        ll u, v;
        cin >> u >> v;
        items.pb({u, v});
    }
    cout << solve(0, w);

}

int main() {
    fast
    ll t = 1;
    //  cin >> t;
    while (t--) solve();
}
