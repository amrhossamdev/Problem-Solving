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
#define IN 1ju

#define l(i, s, n) for (int i = s; i < n; i++)
#define le(i, s, n) for (int i = s; i <= n; i++)
#define ln(i, e, n) for (ll i = n; i >= e; i--)

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dxk[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dyk[8] = {1, 2, 2, 1, -1, -2, -2, -1};

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v) in >> x;
  return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v) {
  for (const T &x : v) out << x << ' ';
  return out;
}

void debug(vector<ll> v) {
  l(i, 0, v.size()) { cout << v[i] << " "; }
  cout << endl;
}

const int M = 1e9;

ll fastpow(ll a, ll b, ll m) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}

const int N = 2e5 + 10;

struct DSU {
  vector<int> par;
  vector<int> sz;
  vector<int> mx;

  void init(ll n) {
    par = vector<int>(N + 1);
    sz = vector<int>(N + 1, 1);
    mx = vector<int>(N + 1, 1);
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
      sz[i] = 1;
      mx[i] = i;
    }
  }

  ll findparent(ll u) {
    if (par[u] == u) return u;
    return par[u] = findparent(par[u]);
  }

  bool isConnected(ll u, ll v) {
    u = findparent(u);
    v = findparent(v);
    if (u == v) return true;
    return false;
  }

  bool merge(ll u, ll v) {
    u = findparent(u);
    v = findparent(v);
    if (u == v) return 0;  // can't connect
    if (sz[v] > sz[u]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    return 1;
  }
};

ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll add(ll a, ll b, ll m) {
  a %= m;
  b %= m;
  return (a + b) % m;
}

ll mul(ll a, ll b, ll MOD) { return (1ll * a * b) % MOD; }

const int INF = 1e9;

bool isValid(int x, int y, vector<vector<bool>> &vis) {
  if (x < 0 || x >= 8 || y < 0 || y >= 8 || vis[x][y] == 1) return false;
  return true;
}

int dijkstra(ll srx, ll sry, ll dex, ll dey) {
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>,
                 greater<pair<ll, pair<ll, ll>>>>
      pq;
  vector<vector<ll>> dist(8, vector<ll>(8, INF));
  vector<vector<bool>> vis(8, vector<bool>(8, false));
  dist[srx][sry] = 0;
  pq.push({0, {srx, sry}});
  while (!pq.empty()) {
    ll x = pq.top().second.first, y = pq.top().second.second,
       cost = pq.top().first;
    pq.pop();
    vis[x][y] = 1;
    l(i, 0, 8) {
      ll movx = dxk[i] + x;
      ll movy = dyk[i] + y;
      if (isValid(movx, movy, vis)) {
        ll moveCost = x * movx + y * movy;
        if (cost + moveCost < dist[movx][movy]) {
          dist[movx][movy] = moveCost + cost;
          pq.push({dist[movx][movy], {movx, movy}});
        }
      }
    }
  }
  return dist[dex][dey];
}

void solve(int test) {
  // cost -> (a*c) + (b*d)
  while (true) {
    ll a, b, c, d;
    a = -1;
    cin >> a >> b >> c >> d;
    if (a == -1) return;
    cout << dijkstra(a, b, c, d) << endl;
  }
}

int main() {
  fast int t = 1;
  // cin >> t;
  le(i, 1, t) { solve(i); }

  return 0;
}
