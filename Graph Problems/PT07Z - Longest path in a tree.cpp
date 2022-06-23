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

pair<int, int> bfs(int u) {
    pair<int, int> p{u, 0};
    queue<int> q;
    int level = 0;
    q.push(u);
    vis[u] = true;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int node = q.front();
            q.pop();
            for (int v:g[node]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    p = {v, level + 1};
                }
            }
        }
        ++level;
    }
    return p;
}

void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    fast
    cin >> n;
    m = n - 1;
    l(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    auto p = bfs(1);
    clr(vis, 0);
    p = bfs(p.first);
    cout << p.second << endl;
    return 0;
}
