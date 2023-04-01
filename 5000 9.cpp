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

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 5;
// int n, m, q, dr[N], d[N], dd[N], st, ed, par[N][20], dep[N], dis[N][20], pos, vis[N];
// vector<pair<int, int>> vec[N];

// void pre_dfs(int u, int fa)
// {
//     par[u][0] = fa;
//     dep[u] = dep[fa] + 1;
//     for (int i = 1; i < 20; i++)
//     {
//         par[u][i - 1] = par[par[u][i - 1]][i - 1];
//         dis[u][i - 1] = dis[par[u][i - 1]][i - 1] + dis[par[par[u][i - 1]][i - 1]][i - 1];
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
//             if (dd[v] > dd[u] + w)
//             {
//                 dd[v] = dd[u] + w;
//                 que.push({v, dd[v]});
//             }
//     }
// }

// int main()
// {
//     memset(dd, 0x3f, sizeof dd);
//     cin >> n >> m;
//     for (int i = 0, pos; i < m; i++)
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