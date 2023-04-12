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

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 4e5 + 5;
// int n, a, b, c;

// signed main()
// {

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> a >> b >> c;
//         if (a * b > c)
//         {
//             if (a < c)
//                 cout << "1 " << b << '\n';
//             else
//                 cout << "-1 " << b << '\n';
//         }
//         else if (a * b == c)
//         {
//             if (a < c)
//                 cout << "1 -1\n";
//             else
//                 cout << "-1 -1\n";
//         }
//         else
//         {
//             cout << "1 -1\n";
//         }
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
// int n, a, b, c;

// signed main()
// {

//     int t;
//     cin >> t;
//     string s;
//     while (t--)
//     {
//         cin >> s;
//         a = 0, b = 0;
//         for (int i = 0; i < s.length(); i++)
//         {
//             if (s[i] == '1')
//                 a++;
//             else
//                 b++;
//         }
//         c = min(a, b);
//         if (c % 2)
//             cout << "DA\n";
//         else
//             cout << "NET\n";
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
// int n, a, b, c;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     string s;
//     while (t--)
//     {
//         cin >> s;
//         int res = s.length(), cur = 0;
//         for (int i = 0, len = s.length(), tmp = 0; i < len; i++)
//         {
//             if (s[i] == '+')
//                 tmp++;
//             else
//                 tmp--;
//             if (cur + tmp < 0)
//             {
//                 cur++;
//                 res += i + 1;
//             }
//         }
//         cout << res << '\n';
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
// int n, a, b, c;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     string s;
//     while (t--)
//     {
//         cin >> a >> b;
//         if (a == 1)
//             cout << 0 << '\n';
//         else if (a < 3)
//             cout << b << '\n';
//         else
//             cout << 2 * b << '\n';
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
// const int N = 2e5 + 5;
// int n, a[N], q[N], p[N];

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     string s;
//     while (t--)
//     {
//         cin >> n;
//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//             if (~i & 1)
//                 ans += a[i];
//             else
//                 q[i] = a[i] - a[i - 1];
//         }
//         int t1 = 0, t2 = 0, m1 = 0, m2 = 0;
//         for (int i = 1; i < n; i += 2)
//         {
//             if (i + 1 < n)
//             {
//                 p[i] = a[i] - a[i + 1];
//                 if (t2 + p[i] >= 0)
//                     t2 += p[i];
//                 else
//                     t2 = 0;
//             }
//             if (t1 + q[i] >= 0)
//                 t1 += q[i];
//             else
//                 t1 = 0;
//             m1 = max(m1, t1);
//             m2 = max(m2, t2);
//         }
//         cout << ans + max(m1, m2) << '\n';
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
// const int N = 2e5 + 5;
// int n, a[N], b[N], k;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     string s;
//     while (t--)
//     {
//         cin >> n >> k;
//         for (int i = 1; i <= n; i++)
//             cin >> a[i];
//         for (int i = 1; i <= n; i++)
//             cin >> b[i];
//         sort(a + 1, a + 1 + n);
//         sort(b + 1, b + 1 + n);
//         for (int i = 1, j = n; i <= k; i++, j--)
//         {
//             if (a[i] >= b[j])
//                 break;
//             a[i] = b[j];
//         }
//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//             ans += a[i];
//         cout << ans << '\n';
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
// const int N = 2e5 + 5;
// int n, a[N], b[N], k;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     string s;
//     while (t--)
//     {
//         cin >> n;
//         int ans = 0;
//         for (int i = 2; i < n; i += 2)
//         {
//             ans += i * 4 * (i / 2);
//         }
//         cout << ans << '\n';
//     }

//     return 0;
// }

// #pragma GCC optimize(3)
// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define pii pair<int, int>
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;
// int n, a[N], b[N], cnt;

// struct node
// {
//     int s, l, r;
//     bool operator>(node e)const
//     {
//         if (s == e.s)
//             return l < e.l;
//         return s > e.s;
//     }
//     bool operator<(node e)const
//     {
//         if (s == e.s)
//             return l > e.l;
//         return s < e.s;
//     }
// };

// void bfs(int l, int r)
// {
//     priority_queue<node, vector<node>, less<node>> q;
//     q.push({r - l, l, r});
//     while (q.size() && cnt < n)
//     {
//         int s = q.top().s;
//         int l = q.top().l;
//         int r = q.top().r;
//         q.pop();
//         if (l > r)
//             continue;
//         // cout << s << ' ' << l << ' ' << r << '\n';
//         int mid = l + r >> 1;
//         a[mid] = ++cnt;
//         if (mid - 1 - l >= 0)
//             q.push({mid - 1 - l, l, mid - 1});
//         if (r - mid - 1 >= 0)
//             q.push({r - mid - 1, mid + 1, r});
//     }
// }

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     string s;
//     while (t--)
//     {
//         cin >> n;
//         cnt = 0;
//         bfs(1, n);
//         for (int i = 1; i <= n; i++)
//             cout << a[i] << ' ';
//         cout << '\n';
//         // cout << "\n______________\n";
//     }

//     return 0;
// }
//

// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;

// int main()
// {
//     IO;
//     int t;
//     cin >> t;
//     string s;
//     int n, d;
//     while (t--)
//     {
//         cin >> n >> d >> s;
//         d += '0';
//         int f = 1;
//         for (int i = 0, len = s.length(); i < len; i++)
//         {
//             if (s[i] < d && f)
//             {
//                 cout << d - '0';
//                 f = 0;
//             }
//             cout << s[i];
//         }
//         if (f)
//             cout << d - '0';
//         cout << '\n';
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
// const int N = 2e5 + 5;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     int n, x1, x2, y1, y2, l1, l2, l, r;
//     while (t--)
//     {
//         cin >> n >> x1 >> y1 >> x2 >> y2;
//         l = n / 2;
//         r = l + 1;
//         if (x1 >= r)
//             x1 = l - x1 + r;
//         if (x2 >= r)
//             x2 = l - x2 + r;
//         if (y1 >= x1 && y1 <= n + 1 - x1)
//             l1 = x1;
//         else if (y1 <= l)
//             l1 = y1;
//         else
//             l1 = n + 1 - y1;
//         if (y2 >= x2 && y2 <= n + 1 - x2)
//             l2 = x2;
//         else if (y2 <= l)
//             l2 = y2;
//         else
//             l2 = n + 1 - y2;
//         // cout << l1 << ' ' << l2 << '\n';
//         cout << abs(l1 - l2) << '\n';
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
// const int N = 2e5 + 5;
// int a[N];

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     int n;
//     while (t--)
//     {
//         cin >> n;
//         for (int i = 1; i < n; i++)
//             cin >> a[i];
//         cout << a[1] << ' ';
//         for (int i = 2; i < n; i++)
//         {
//             cout << min(a[i], min(max(a[i], a[i - 1]), a[i - 1])) << ' ';
//         }
//         cout << a[n - 1] << '\n';
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
// const int N = 2e5 + 5;
// int a[N];

// signed main()
// {
//     IO;
//     int n;
//     double m, t;
//     cin >> n >> m;
//     while (n--)
//     {
//         cin >> t;
//         if (t < m)
//         {
//             printf("On Sale! %.1lf\n", t);
//         }
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
// const int N = 2e5 + 5;
// int a[N];

// signed main()
// {
//     IO;
//     int n, m, cnt = 0, f = 1;
//     cin >> n >> m;
//     string s;
//     getline(cin, s);
//     for (int i = 1; i <= n; i++)
//     {
//         getline(cin, s);
//         if (s.find("easy") != s.npos || s.find("qiandao") != s.npos)
//             continue;
//         if (cnt >= m && s.find("easy") == s.npos && s.find("qiandao") == s.npos)
//         {
//             if (f)
//             {
//                 cout << s;
//                 f = 0;
//             }
//             else
//                 continue;
//         }
//         cnt++;
//     }
//     if (f)
//         cout << "Wo AK le";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;
// int a[N];

// signed main()
// {
//     IO;
//     int t[24];
//     for (int i = 0; i < 24;i++)
//         cin >> t[i];
//     int a;
//     while(cin >> a, (a >= 0 && a <= 23)){
//         cout << t[a] << ' ';
//         if(t[a] > 50)
//             cout << "Yes\n";
//             else
//             cout << "No\n";
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
// const int N = 2e5 + 5;
// int a[N];

// signed main()
// {
//     IO;
//     int t, n, k;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> k;
//         if (n % 2 == 0)
//         {
//             cout << "YES\n";
//         }
//         else
//         {
//             if (n == 1)
//             {
//                 if (k == 1)
//                     cout << "YES\n";
//                 else
//                     cout << "NO\n";
//                 continue;
//             }
//             if (k % 2)
//             {
//                 if ((n - k) % 2 == 0)
//                     cout << "YES\n";
//                 else
//                     cout << "NO\n";
//             }
//             else
//                 cout << "NO\n";
//         }
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
// const int N = 2e5 + 5;
// int a[N];

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int a, b, ans = 0, g, sa, sb;
//         cin >> a >> b;
//         if (a == 0 && b == 0)
//         {
//             cout << "0\n";
//             continue;
//         }
//         if (!a || !b)
//         {
//             if (!a)
//                 swap(a, b);
//             sa = sqrt(a);
//             ans += sa - 1;
//             ans += a / sa;
//             ans += (a % sa);
//             cout << ans << '\n';
//             continue;
//         }
//         if (a > b)
//             swap(a, b);
//         if(b % a == 0){

//         }
//         sa = sqrt(a);
//         sb = sqrt(b);
//         if (a >= sb)
//             sa = sb;
//         ans += sa - 1;
//         ans += a / sa;
//         ans += (a % sa);
//         // cout << ans << '\n';
//         ans += sb - sa;
//         ans += b / sb;
//         ans += (b % sb) / sa;

//         cout << ans << '\n';
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
// const int N = 2e5 + 5;
// pair<int, int> a[N];

// signed main()
// {
//     IO;
//     int t, n, s1, s2, ms;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> s1 >> s2;
//         ms = min(s1, s2);
//         for (int t, i = 1; i <= n; i++)
//         {
//             cin >> t;
//             a[i] = make_pair(t, i);
//         }
//         sort(a + 1, a + n + 1, greater<pair<int, int>>());
//         // for (int i = 1; i <= n; i++)
//         //     cout << a[i].first << '\n';
//         vector<pair<int, int>> tt;
//         for (int i = 0, ti = s1; i <= n; ti += s1, i++)
//         {
//             tt.push_back({ti, 1});
//         }
//         for (int i = 0, ti = s2; i <= n; ti += s2, i++)
//         {
//             tt.push_back({ti, 2});
//         }
//         sort(tt.begin(), tt.end());
//         // for (auto [fi, se] : tt)
//         // {
//         //     cout << fi << ' ' << se << '\n';
//         // }
//         vector<int> ans[3];
//         for (int i = 1; i <= n; i++)
//             ans[tt[i - 1].second].push_back(a[i].second);

//         cout << ans[1].size() << ' ';
//         for (int i = 0, len = ans[1].size(); i < len; i++)
//             cout << ans[1][i] << ' ';
//         cout << '\n';
//         cout << ans[2].size() << ' ';
//         for (int i = 0, len = ans[2].size(); i < len; i++)
//             cout << ans[2][i] << ' ';
//         cout << '\n';
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     string s;
//     cin >> n >> s;
//     for (int i = 1; i < s.length(); i++)
//         if (s[i] == s[i - 1])
//         {
//             cout << "NO";
//             return 0;
//         }
//     cout << "YES";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     char s[10][10];
//     int x, y;
//     for (int i = 1; i <= 8; i++)
//         for (int j = 1; j <= 8; j++)
//         {
//             cin >> s[i][j];
//             if (s[i][j] == '*')
//             {
//                 x = i, y = j;
//             }
//         }
//     printf("%c%d", y + 'a' - 1, 9 - x);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 5;
// int n, x;
// int a[N], b[N];

// signed main()
// {
//     cin >> n >> x;
//     set<int> st;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         st.insert(a[i]);
//         b[i] = a[i] + x;
//     }
//     for (int i = 0; i < n; i++)
//         if (st.find(b[i]) != st.end())
//         {
//             cout << "Yes";
//             return 0;
//         }
//     cout << "No";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 5;
// int n, a, b;

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         a = b = 0;
//         cin >> n;
//         for (int i = 0, tmp; i < n; i++)
//         {
//             cin >> tmp;
//             if (tmp > 0)
//                 a += tmp;
//             else
//                 b -= tmp;
//         }
//         cout << abs(a - b) << '\n';
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
// const int N = 2e5 + 5;
// int n, a, b;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         vector<pair<int, int>> vec;
//         int l = 1, r = 3 * n;
//         while (l + 1 < r)
//         {
//             vec.push_back({l, r});
//             l += 3;
//             r -= 3;
//         }
//         cout << vec.size() << '\n';
//         for (auto [u, v] : vec)
//             cout << u << ' ' << v << '\n';
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define double long double
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;
// double n, m, s, ans;

// signed main()
// {
//     IO;
//     int t;
//     // cin >> t;
//     t = 1;
//     while (t--)
//     {
//         cin >> n >> m;
//         if (m > n * n || sqrt(m) > n || (double)m > (double)n * (double)n)
//         {
//             cout << -1;
//             return 0;
//         }
//         s = (int)sqrt(m);
//         ans = (s + 1) * (s + 1);
//         for (double i = s; i <= n; i += 1)
//             if ((s - 1) * i >= m)
//             {
//                 ans = min(ans, (s - 1) * i);
//                 break;
//             }
//         for (int i = s; i <= n; i++)
//             if (s * i >= m)
//             {
//                 ans = min(ans, s * i);
//                 break;
//             }
//         if (ans > n * n)
//             cout << -1;
//         else
//             cout << (int)ceil(ans);
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int unsigned long long
// #define double long double
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;
// int n, m, s, ans;

// signed main()
// {
//     IO;
//     cin >> n >> m;
//     if (m > n * n || sqrt(m) > n || (double)m > (double)n * (double)n)
//     {
//         cout << -1;
//         return 0;
//     }
//     s = (int)sqrt(m);
//     ans = (s + 1) * (s + 1);
//     if (s > 1)
//         for (int i = s; i <= n; i++)
//             if ((s - 1) * i >= m)
//             {
//                 ans = min(ans, (s - 1) * i);
//                 break;
//             }
//     for (int i = s; i <= n; i++)
//         if (s * i >= m)
//         {
//             ans = min(ans, s * i);
//             break;
//         }
//     cout << ans;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int unsigned long long
// #define double long double
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;
// int n, a[N], vis[N], cnt[N];

// signed main()
// {
//     IO;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];

//     int ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (!vis[i])
//         {
//             int cur = i;
//             while (cnt[cur] < 2)
//             {
//                 if (!cnt[cur] && vis[cur])
//                     break;
//                 if (cnt[cur]++)
//                     ans++;
//                 vis[cur] = 1;
//                 cur = a[cur];
//             }
//             memset(cnt, 0, sizeof cnt);
//         }
//     }

//     cout << ans;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int unsigned long long
// #define double long double
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;
// int n, a[N];

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> a[1];
//         a[1]--;
//         int ai = 2, bi = 1;
//         for (int i = 2; i <= n; i++)
//         {
//             cin >> a[i];
//             if (a[i] < a[ai])
//                 ai = i;
//         }
//         for (int i = 1; i <= n; i++)
//             if (i != ai)
//             {
//                 if (a[i] < a[bi])
//                     bi = i;
//             }
//         if (a[bi] < a[ai])
//             cout << "Bob\n";
//         else
//             cout << "Alice\n";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int MX = sqrt(LLONG_MAX);

// signed main()
// {
//     int n, m;
//     cin >> n >> m;
//     int s = ceil(sqrt(m * 1.0)), ans = s * s, f = 0;
//     for (int i = 1, t; i <= s && i <= n; i++)
//     {
//         t = (m * 1.0) / (1.0 * i);
//         if (t * i < m)
//             t++;
//         if (t <= n && t * i <= ans)
//         {
//             ans = t * i;
//             f = 1;
//         }
//     }
//     if (!f)
//         cout << -1;
//     else
//         cout << ans;

//     return 0;
// }

// #pragma GCC optimize(3)
// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;
// int n, a[N], fa[N], cnt[N];

// int find(int x)
// {
//     return fa[x] == x ? x : fa[x] = find(fa[x]);
// }

// void merg(int a, int b)
// {
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// signed main()
// {
//     IO;
//     cin >> n;
//     // n = N - 5;
//     for (int i = 1; i <= n; i++)
//         fa[i] = i;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         merg(a[i], i);
//     }
//     int ans = 0;
//     for (int i = 1, p, ct; i <= n; i++)
//         if (fa[i] == i)
//         {
//             p = i;
//             ct = 0;
//             while (cnt[p] < 2)
//             {
//                 ct++;
//                 if (cnt[p]++)
//                     ans++;
//                 p = a[p];
//             }
//             p = i;
//             while (ct--)
//             {
//                 cnt[p] = 0;
//                 p = a[p];
//             }
//         }

//     cout << ans;
//     return 0;
// }

// #pragma GCC optimize(3)
// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;

// signed main()
// {
//     IO;
//     int n;
//     cin >> n;
//     map<string, int> mp;
//     mp["and"] = 1;
//     mp["not"] = 1;
//     mp["the"] = 1;
//     mp["that"] = 1;
//     mp["you"] = 1;
//     int f = 0;
//     while (n--)
//     {
//         string s;
//         cin >> s;
//         if (mp[s])
//             f = 1;
//     }
//     if (f)
//         cout << "Yes";
//     else
//         cout << "No";
//     return 0;
// }

// #pragma GCC optimize(3)
// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;

// struct Node
// {
//     int value;
//     Node *next;
// };

// Node *createSortList()
// {
//     int v;
//     Node *ret = NULL, *head = (Node *)malloc(sizeof(Node));
//     head->next = NULL;
//     while (cin >> v, v)
//     {
//         Node *pre = head, *cur = pre->next;
//         while (cur)
//         {
//             if (cur->value <= v)
//                 break;
//             cur = cur->next;
//             pre = pre->next;
//         }
//         Node *tmp = (Node *)malloc(sizeof(Node));
//         tmp->value = v;
//         tmp->next = cur;
//         pre->next = tmp;
//     }
//     return head->next;
// }

// signed main()
// {
//     IO;
//     Node *head = NULL;
//     head = createSortList();
//     for (Node *p = head; p != NULL; p = p->next)
//         cout << p->value << '\n';
//     // cout << 1;
//     return 0;
// }

// #pragma GCC optimize(3)
// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 2e5 + 5;
// char mp[30][30];

// signed main()
// {
//     IO;
//     int x, y;
//     cin >> x >> y;
//     for (int i = 1; i <= x; i++)
//         for (int j = 1; j <= y; j++)
//             cin >> mp[i][j];
//     for (int i = 1; i <= x; i++)
//         for (int j = 1; j <= y; j++)
//             if (mp[i][j] >= '0' && mp[i][j] <= '9')
//             {
//                 for (int ii = 1; ii <= x; ii++)
//                     for (int jj = 1; jj <= y; jj++)
//                         if (abs(ii - i) + abs(jj - j) <= mp[i][j] - '0' && mp[ii][jj] == '#')
//                             mp[ii][jj] = '.';
//                 mp[i][j] = '.';
//             }

//     for (int i = 1; i <= x; i++)
//     {
//         for (int j = 1; j <= y; j++)
//             cout << mp[i][j];
//         cout << '\n';
//     }

//     return 0;
// }

// #pragma GCC optimize(3)
// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 5e5 + 5;
// int a[N];

// signed main()
// {
//     IO;
//     int n;
//     cin >> n;
//     unordered_map<int, int> mp;
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         ++mp[a[i]];
//     }
//     for (auto [s, v] : mp)
//         ans += v / 2;
//     cout << ans;

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
// const int N = 5e5 + 5;
// int a[N], num[10] = {1351991234, 784865646, 32131695, 218494738, 425138948, 64823325, 547849465, 861479535, 941596349, 123654987};

// signed main()
// {
//     IO;
//     string s;
//     cin >> s;
//     int t = 0;
//     unordered_map<int, int> mp;
//     mp[0]++;
//     for (int i = 0, len = s.length(); i < len; i++)
//     {
//         t = t ^ (s[i] + num[s[i] - '0']);
//         mp[t]++;
//         // cout << t << ' ';
//     }
//     // int ans = ((mp[0] - 1) + (mp[0] - 1) * (mp[0] - 1)) / 2;
//     int ans = 0;
//     for (auto [f, s] : mp)
//     {
//         ans += ((s - 1) + (s - 1) * (s - 1)) / 2;
//     }
//     cout << ans;

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
// const int N = 5e5 + 5;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<string> vec;
//         string s;
//         for (int i = 0; i < 2 * n - 2; i++)
//         {
//             cin >> s;
//             if (s.length() == n - 1)
//                 vec.push_back(s);
//         }

//         for (int i = 0; i < n - 1; i++)
//             if (vec[0][i] != vec[1][n - 2 - i])
//             {
//                 cout << "NO\n";
//                 goto ss;
//             }
//         cout << "YES\n";
//     ss:;
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
// const int N = 1e4 + 5;
// int a[N];

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> a[i];
//         }

//         for (int i = n; i > 1; i--)
//         {
//             if (a[i] % a[i - 1] == 0)
//                 a[i - 1]++;
//             if (a[i] % a[i - 1] == 0)
//             {
//                 a[i - 1]++;
//                 if (a[i] % a[i - 1] == 0)
//                 {
//                     a[i - 1]++;
//                     if (a[i] % a[i - 1] == 0)
//                     {
//                         a[i - 1]++;
//                         if (a[i] % a[i - 1] == 0)
//                         {
//                             a[i - 1] -= 4;
//                             a[i]++;
//                         }
//                     }
//                 }
//             }
//         }
//         for (int i = 1; i <= n; i++)
//             cout << a[i] << ' ';

//         cout << '\n';
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
// const int N = 1e5 + 5;
// int a[N];

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         for (int i = 1, l, r, mid; i <= n; i++)
//         {
//             cin >> a[i];
//             l = 1, r = i;
//             while (l <= r)
//             {
//                 mid = l + r >> 1;
//                 if (mid < 1 || mid > n)
//                     break;
//                 if (mid <= a[i + 1 - mid])
//                     l = mid + 1;
//                 else
//                     r = mid - 1;
//             }
//             cout << r << ' ';
//         }
//         cout << '\n';
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
// const int N = 1e4 + 5;
// int a[N];

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//             cin >> a[i];

//         for (int i = 1; i < n; i++)
//         {
//             if (a[i] == 1)
//             {
//                 a[i]++;
//                 if (i > 1 && a[i] % a[i - 1] == 0)
//                 {
//                     a[i]++;
//                 }
//             }
//             if (a[i + 1] % a[i] == 0)
//             {
//                 // if (a[i + 1] % (a[i] + 1))
//                 //     a[i]++;
//                 // else
//                 a[i + 1]++;
//             }
//         }
//         for (int i = 1; i <= n; i++)
//             cout << a[i] << ' ';
//         cout << '\n';
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// string s;
// int len, f = 0;

// struct node
// {
//     char v;
//     node *left, *right;
// };

// node *pre_create()
// {
//     node *ret = (node *)malloc(sizeof(node));
//     ret->v = s[f++];
//     if (ret->v == '#')
//     {
//         ret->left = ret->right = NULL;
//     }
//     else
//     {
//         ret->left = pre_create();
//         ret->right = pre_create();
//     }
//     return ret;
// }

// void mid_dfs(node *head)
// {
//     if (head->v == '#')
//         return;

//     mid_dfs(head->left);
//     cout << head->v << ' ';
//     mid_dfs(head->right);
// }

// int main()
// {
//     cin >> s;
//     len = s.length();
//     node *head = pre_create();

//     mid_dfs(head);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, mx, mn, a, b;
//     cin >> n;
//     cin >> a >> b;
//     mx = a / b;
//     mn = (int)ceil((a + 1) / (b + 1));
//     while (--n)
//     {
//         cin >> a >> b;
//         mx = min(mx, a / b);
//         mn = max(mn, (int)ceil((double)(a + 1) / (b + 1)));
//     }
//     cout << mn << ' ' << mx;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define pii pair<int, int>
// int n, s[15], e[15], val[15], vis[15], cur, f;

// void dfs(int id)
// {
//     if (cur > s[id] + e[id])
//         return;
//     vis[id] = 1;
//     int delt = max(cur + val[id], s[id] + val[id]) - cur;
//     cur += delt;
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//         if (!vis[i])
//             dfs(i), cnt++;

//     if (!cnt)
//         f = 1;

//     vis[id] = 0;
//     cur -= delt;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         for (int i = 0; i < n; i++)
//             cin >> s[i] >> e[i] >> val[i], vis[i] = 0;

//         f = 0;
//         for (int i = 0; i < n && !f; i++)
//         {
//             cur = 0;
//             dfs(i);
//         }

//         if (f)
//             cout << "YES\n";
//         else
//             cout << "NO\n";
//     }

//     return 0;
// }