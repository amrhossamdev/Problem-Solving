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

#define l(i, s, n) for (int i = s; i < n; i++)
#define le(i, s, n) for (int i = s; i <= n; i++)
#define ln(i, e, n) for (ll i = n; i >= e; i--)


const int S = 100005;
vector<int> g[S];
bool vis[S];

int dist[S];
ll n, m;

void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (q.size()) {
        int node = q.front();
        cout << node << endl;
        q.pop();
        for (int v:g[node]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int main() {
    fast
    cin >> n >> m;
    l(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int cnt = 0;
    le(i, 1, n) {
        if (!vis[i]) {
            dfs(i);
            ++cnt;
        }
    }
    cout << (m == n - 1 && cnt == 1 ? "YES\n" : "NO\n");
    return 0;
}
