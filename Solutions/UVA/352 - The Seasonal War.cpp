#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
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
#define read() freopen("Bumble.in", "r", stdin)

#define l(i, s, n) for (int i = s; i < n; i++)
#define le(i, s, n) for (int i = s; i <= n; i++)
#define ln(i, e, n) for (int i = n; i >= e; i--)
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isPrime(ll x) {
  for (ll j = 2; j * j <= x; ++j)
    if (x % j == 0) return false;
  return true;
}

ll n;
const int N = 1e4 + 7;
vector<string> g;

bool isValid(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < n); }

void dfs(ll i, ll j) {
  if (!isValid(i, j) || g[i][j] != '1') return;
  g[i][j] = '2';
  l(k, 0, 8) {
    int r = i + dx[k];
    int c = j + dy[k];
    dfs(r, c);
  }
}

void solve() {
  int test = 1;
  while (cin >> n) {
    l(i, 0, n) {
      string s;
      cin >> s;
      g.pb(s);
    }
    ll ans = 0;
    l(i, 0, n) {
      l(j, 0, n) {
        if (g[i][j] == '1') {
          ++ans;
          dfs(i, j);
        }
      }
    }
    cout << "Image number " << test++ << " contains " << ans << " war eagles."
         << endl;
    g = {};
  }
}

int main() {
  //read();
  fast int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
