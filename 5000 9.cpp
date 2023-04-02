// #include <bits/stdc++.h>
// using namespace std;
// const int N = 4e5 + 5;
// int n, a[N], ct[N], sum[N], rt = 1;
// vector<int> vec[N];
// void dfs(int u, int fa)
// {
//     sum[u] = a[u];
//     ct[u] = 0;
//     for (auto v : vec[u])
//     {
//         if (v == fa)
//             continue;
//         dfs(v, u);
//         if (sum[v] < 0)
//         {
//             ct[u]++;
//         }
//         else if (sum[v] == 0)
//         {
//             ct[u] += min(ct[v], 1);
//         }
//         else
//         {
//             sum[u] += sum[v];
//             ct[u] += ct[v];
//         }
//     }
//     // if (sum[u] > sum[rt])
//     //     rt = u;
// }

// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     for (int u, v, i = 1; i < n; i++)
//     {
//         cin >> u >> v;
//         vec[u].push_back(v);
//         vec[v].push_back(u);
//     }
//     dfs(rt, 0);
//     for (int i = 1; i <= n; i++)
//         if (sum[i] >= sum[rt] && ct[i] < ct[rt])
//             rt = i;
//     if (rt != 1)
//         ct[rt]++;
//     cout << sum[rt] << ' ' << ct[rt];

//     return 0;
// }

// #pragma GCC optimize(3)
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;
// int n, m, q, dr[N], d[N], dd[N], st, ed, par[N][20], dep[N], dis[N][20], pos, vis[N];
// vector<pair<int, int>> vec[N];

// void pre_dfs(int u, int fa)
// {
//     par[u][0] = fa;
//     dep[u] = dep[fa] + 1;
//     for (int i = 1; i < 20; i++)
//     {
//         par[u][i] = par[par[u][i - 1]][i - 1];
//         dis[u][i] = dis[u][i - 1] + dis[par[u][i - 1]][i - 1];
//     }
//     for (auto [v, w] : vec[u])
//         if (v != fa)
//         {
//             dis[v][0] = w;
//             pre_dfs(v, u);
//         }
// }

// int getdis(int u, int v)
// {
//     int ret = 0;
//     if (dep[u] < dep[v])
//         swap(u, v);
//     for (int i = 19; i >= 0; i--)
//         if (dep[par[u][i]] >= dep[v])
//         {
//             ret += dis[u][i];
//             u = par[u][i];
//         }
//     if (u == v)
//         return ret;
//     for (int i = 19; i >= 0; i--)
//         if (par[u][i] != par[v][i])
//         {
//             ret += dis[u][i];
//             ret += dis[v][i];
//             u = par[u][i];
//             v = par[v][i];
//         }
//     ret += dis[u][0];
//     ret += dis[v][0];
//     return ret;
// }

// void dij()
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
//     que.push({0, pos});
//     while (que.size())
//     {
//         int u = que.top().second;
//         que.pop();
//         if (vis[u])
//             continue;
//         vis[u] = 1;
//         for (auto [v, w] : vec[u])
//         {
//             if (dd[v] > dd[u] + w)
//             {
//                 dd[v] = dd[u] + w;
//             }
//             if (!vis[v])
//                 que.push({dd[v], v});
//         }
//     }
// }

// signed main()
// {
//     IO;
//     memset(dd, 0x3f, sizeof dd);
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> pos;
//         dr[pos] = 1;
//         dd[pos] = 0;
//     }
//     for (int i = 1, u, v, w; i < n; i++)
//     {
//         cin >> u >> v >> w;
//         dis[u][v] = dis[v][u] = w;
//         vec[u].push_back({v, w});
//         vec[v].push_back({u, w});
//     }
//     pre_dfs(1, 0);
//     dij();
//     cin >> q;
//     while (q--)
//     {
//         cin >> st >> ed;
//         cout << min(getdis(st, ed), dd[st] + dd[ed]) << '\n';
//     }

//     return 0;
// }

// #pragma GCC optimize(3)
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;
// int n, m, q, par[N][20], dis[N][20], dep[N], d[N], dr[N], vis[N], st, ed;
// vector<pair<int, int>> vec[N];

// void dij()
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
//     for (int i = 1; i <= m; i++)
//         que.push({0, dr[i]});
//     while (que.size())
//     {
//         int u = que.top().second;
//         que.pop();
//         if (vis[u])
//             continue;
//         vis[u] = 1;
//         for (auto [v, w] : vec[u])
//         {
//             if (d[v] > d[u] + w)
//             {
//                 d[v] = d[u] + w;
//                 que.push({d[v], v});
//             }
//         }
//     }
// }

// void pre_dfs(int u, int fa)
// {
//     for (int i = 1; i < 20; i++)
//     {
//         par[u][i] = par[par[u][i - 1]][i - 1];
//         dis[u][i] = dis[u][i - 1] + dis[par[u][i - 1]][i - 1];
//     }
//     for (auto [v, w] : vec[u])
//         if (v != fa)
//         {
//             par[v][0] = u;
//             dis[v][0] = w;
//             dep[v] = dep[u] + 1;
//             pre_dfs(v, u);
//         }
// }

// int getdis(int u, int v)
// {
//     int ret = 0;
//     if (dep[u] < dep[v])
//         swap(u, v);
//     for (int i = 19; i >= 0; i--)
//     {
//         if (dep[par[u][i]] >= dep[v])
//         {
//             ret += dis[u][i];
//             u = par[u][i];
//         }
//     }
//     if (u == v)
//         return ret;
//     for (int i = 19; i >= 0; i--)
//     {
//         if (par[u][i] != par[v][i])
//         {
//             ret += dis[u][i];
//             ret += dis[v][i];
//             u = par[u][i];
//             v = par[v][i];
//         }
//     }
//     ret += dis[u][0];
//     ret += dis[v][0];
//     return ret;
// }

// signed main()
// {
//     IO;
//     cin >> n >> m;
//     memset(d, 0x3f, sizeof d);
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> dr[i];
//         d[dr[i]] = 0;
//     }
//     for (int i = 1, u, v, w; i < n; i++)
//     {
//         cin >> u >> v >> w;
//         vec[u].push_back({v, w});
//         vec[v].push_back({u, w});
//     }
//     dij();
//     pre_dfs(1, 0);
//     cin >> q;
//     while (q--)
//     {
//         cin >> st >> ed;
//         cout << min(getdis(st, ed), d[st] + d[ed]) << '\n';
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 4e5 + 5;
// int n;
// vector<int> vec[N];

// int dfs(int u, int fa)
// {
//     vector<int> son;
//     for (auto v : vec[u])
//         if (v != fa)
//         {
//             son.push_back(dfs(v, u));
//         }
//     sort(son.begin(), son.end(), greater<int>());
//     int mx = 0;
//     for (int i = 0, len = son.size(); i < len; i++)
//     {
//         son[i] += i;
//         mx = max(mx, son[i]);
//     }
//     return max(mx, (int)(son.size() + 1));
// }

// signed main()
// {
//     cin >> n;
//     for (int i = 1, u, v; i < n; i++)
//     {
//         cin >> u >> v;
//         vec[u].push_back(v);
//         vec[v].push_back(u);
//     }
//     cout << dfs(1, 0);

//     return 0;
// }