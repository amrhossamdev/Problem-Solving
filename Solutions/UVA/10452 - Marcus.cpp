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
int dxx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dyy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
string d[] = {"forth", "right", "left"};
bool isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isPrime(ll x) {
  for (ll j = 2; j * j <= x; ++j)
    if (x % j == 0) return false;
  return true;
}

ll n, m;

const int N = 1e4 + 7;
vector<vector<char>> g;
string word = "IEHOVA#";

bool isValid(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < m); }

void dfs(ll i, ll j, ll len) {
  if (g[i][j] == '#') return;
  l(k, 0, 3) {
    int r = i + dx[k];
    int c = j + dy[k];
    if (isValid(r, c) && g[r][c] == word[len]) {
      cout << d[k];
      if (g[r][c] != '#') cout << " ";
      dfs(r, c, len + 1);
    }
  }
}

void solve() {
  cin >> n >> m;
  ll x, y;
  g = vector<vector<char>>(n, vector<char>(m));
  l(i, 0, n) {
    l(j, 0, m) {
      cin >> g[i][j];
      if (g[i][j] == '@') {
        x = i, y = j;
      }
    }
  }
  dfs(x, y, 0);
  cout << endl;
}

int main() {
  // read();
  fast int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
