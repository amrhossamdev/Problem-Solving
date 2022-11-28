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


ll dp[1000][10000];

int main() {
    fast
    ll n, m;
    cin >> n >> m;
    ll arr[n][m];

    l(i, 0, n) {
        l(j, 0, m) {
            cin >> arr[i][j];
        }
    }
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (r == 0 && c == 0) dp[r][c] = arr[r][c];
            else {
                ll a, b;
                a = b = INT_MAX;//excluding edges 
                if (r > 0) a = dp[r - 1][c];
                if (c > 0) b = dp[r][c - 1];
                dp[r][c] = min(b, a) + arr[r][c];
            }
        }
    }
//    l(i, 0, n) {
//        l(j, 0, m) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << dp[n - 1][m - 1] << endl;

}
