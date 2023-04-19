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

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;
//     int i = 0, f = 0, even = 0, n = s.length(), num = 0, sum = n;
//     if (s[0] == '-')
//         f = 1, i++, sum--;
//     if ((s.back() - '0') % 2 == 0)
//         even = 1;

//     for (i; i < n; i++)
//         if (s[i] == '2')
//             num++;

//     double ans = ((double)num / sum) * 100.0;
//     if (f)
//         ans *= 1.5;
//     if (even)
//         ans *= 2.0;
//     printf("%.2lf%%", ans);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int a, b;
//     scanf("%d:%d", &a, &b);
//     int aa = a, bb = b;
//     if (b)
//         a++;
//     a -= 12;
//     if (a <= 0)
//         printf("Only %02d:%02d.  Too early to Dang.", aa, bb);
//     else
//     {
//         for (int i = 0; i < a; i++)
//             cout << "Dang";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 110;
// int a, b, n, a1[N], a2[N], b1[N], b2[N], as, bs;

// int main()
// {
//     cin >> a >> b >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> a1[i] >> a2[i] >> b1[i] >> b2[i];

//     for (int i = 1, s; i <= n; i++)
//     {
//         s = a1[i] + b1[i];
//         if ((a2[i] == s && b2[i] == s) || (a2[i] != s && b2[i] != s))
//             continue;

//         if (a2[i] == s)
//         {
//             as++;
//             if (as > a)
//             {
//                 cout << "A\n"
//                      << bs;
//                 return 0;
//             }
//         }
//         else
//         {
//             bs++;
//             if (bs > b)
//             {
//                 cout << "B\n"
//                      << as;
//                 return 0;
//             }
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 110;
// int n, k[110], m;
// unordered_set<string> st[110];

// int main()
// {
//     cin >> n;
//     string s;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> k[i];
//         for (int j = 0; j < k[i]; j++)
//         {
//             cin >> s;
//             st[i].insert(s);
//         }
//     }
//     cin >> m;
//     unordered_set<string> q;
//     queue<string> que;
//     while (m--)
//     {
//         cin >> s;
//         if (q.find(s) == q.end())
//         {
//             q.insert(s);
//             que.push(s);
//         }
//     }

//     int cnt = 0;
//     while (que.size())
//     {
//         string ss = que.front();
//         que.pop();
//         for (int i = 1; i <= n; i++)
//         {
//             if (k[i] > 1 && st[i].find(ss) != st[i].end())
//                 goto bk;
//         }
//         if(cnt++)
//             cout << ' ';
//         cout << ss;
//     bk:;
//     }

//     if (!cnt)
//         cout << "No one is handsome";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1100;
// int n, a, b;

// int main()
// {
//     cin >> n;
//     for (int i = 0, t; i < n; i++)
//     {
//         cin >> t;
//         if (t % 2)
//             a++;
//         else
//             b++;
//     }
//     cout << a << ' ' << b;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1100;
// int n, a, b;

// int main()
// {
//     cin >> n;
//     n += 2;
//     if (n > 7)
//         n -= 7;
//     cout << n;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1100;
// int g[200];
// char tmp[5] = "GPLT";

// int main()
// {
//     string s;
//     cin >> s;
//     int n = s.length();
//     for (int i = 0; i < n; i++)
//     {
//         if (s[i] >= 'a' && s[i] <= 'z')
//             s[i] -= 'a' - 'A';
//         g[s[i]]++;
//     }

//     // cout << g['G'] << ' ' << g['P'] << ' ' << g['L'] << ' ' << g['T'];

//     for (int i = 0; i < n * 4; i++)
//     {
//         if (g[tmp[i % 4]])
//         {
//             printf("%c", tmp[i % 4]);
//             g[tmp[i % 4]]--;
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e4 + 5;

// struct node
// {
//     int id, num;
//     int val;
// };
// node a[N];

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1, k; i <= n; i++)
//     {
//         a[i].id = i;
//         cin >> k;
//         int sum = 0, ni, pi;
//         for (int j = 0; j < k; j++)
//         {
//             cin >> ni >> pi;
//             sum += pi;
//             a[ni].val += pi;
//             a[ni].num++;
//         }
//         a[i].val -= sum;
//     }

//     sort(a + 1, a + 1 + n, [](node e1, node e2) -> int
//          {if(e1.val == e2.val)
//          {
//             if(e1.num == e2.num)
//             {
//                 return e1.id < e2.id;
//             }
//             return e1.num > e2.num;
//         }
//         return e1.val > e2.val; });

//     for (int i = 1; i <= n; i++)
//         printf("%d %.2lf\n", a[i].id, (double)a[i].val / 100.0);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 110;
// int n, k, m, fa[N], bad[N][N];

// int find(int x)
// {
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }

// void merg(int a, int b)
// {
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// int main()
// {
//     cin >> n >> m >> k;
//     for (int i = 1; i <= n; i++)
//         fa[i] = i;
//     for (int i = 0, a, b, c; i < m; i++)
//     {
//         cin >> a >> b >> c;
//         if (c == 1)
//             merg(a, b);
//         else
//             bad[a][b] = bad[b][a] = 1;
//     }

//     int a, b;
//     while (k--)
//     {
//         cin >> a >> b;
//         if (find(a) == find(b))
//         {
//             if (bad[a][b])
//                 cout << "OK but...\n";
//             else
//                 cout << "No problem\n";
//         }
//         else
//         {
//             if (bad[a][b])
//                 cout << "No way\n";
//             else
//                 cout << "OK\n";
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 50;
// int n, pre[N], mid[N];

// struct node
// {
//     int val, left, right;
// };
// node a[N];

// int creat(int l1, int r1, int l2, int r2)
// {
//     if (l1 > r1)
//         return 0;

//     int ret = l2;
//     int rt;
//     for (int i = l1; i <= r1; i++)
//         if (mid[i] == pre[ret])
//         {
//             rt = i;
//             break;
//         }

//     a[ret].val = pre[ret];
//     a[ret].left = creat(l1, rt - 1, l2 + 1, l2 + rt - l1);
//     a[ret].right = creat(rt + 1, r1, l2 + rt - l1 + 1, r2);

//     return ret;
// }

// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> mid[i];
//     for (int i = 1; i <= n; i++)
//         cin >> pre[i];

//     int head = creat(1, n, 1, n);

//     queue<int> que;
//     que.push(head);
//     int cnt = 0;
//     while (que.size())
//     {
//         int p = que.front();
//         que.pop();
//         if (cnt++)
//             cout << ' ';
//         cout << a[p].val;
//         if (a[p].right)
//             que.push(a[p].right);
//         if (a[p].left)
//             que.push(a[p].left);
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 50;

// int main()
// {
//     int a;
//     srand(time(0));
//     a = rand() % 101;
//     if (a > 50)
//         cout << 1;
//     else
//         cout << 0;

//     return 0;
// }

// #include <iostream>
// namespace sp
// {
//     int a = 1;
// }

// namespace sp
// {
//     int b = 2;
// }

// int main()
// {

//     std::cout << sp::a << '\n';

//     std::cout << sp::b << '\n';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int n, mx[10];

// int main()
// {

//     cin >> n;
//     string s;
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> s;
//         mx[s.back() - '0'] = max(mx[s.back() - '0'], mx[s[0] - '0'] + 1);
//         ans = max(ans, mx[s.back() - '0']);
//     }
//     cout << n - ans;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int a[1010], n, m;
// string s;

// void adjust(int i)
// {
//     int son = (i - 1) >> 1;
//     while (son >= 0 && a[son] > a[i])
//     {
//         swap(a[son], a[i]);
//         i = son;
//         son = (i - 1) >> 1;
//     }
// }

// void push(int x, int i)
// {
//     a[i] = x;
//     adjust(i);
// }

// int read1()
// {
//     int i = 0, f = 0, t1 = 0;
//     if (s[0] == '-')
//         i = 1, f = 1;
//     for (int len = s.length(); s[i] != ' '; i++)
//     {
//         t1 *= 10;
//         t1 += s[i] - '0';
//     }
//     if (f)
//         t1 = -t1;
//     return t1;
// }

// pair<int, int> read2()
// {
//     int i = 0, f1 = 0, f2 = 0, t1 = 0, t2 = 0;
//     if (s[0] == '-')
//         i = f1 = 1;
//     while (s[i] != ' ')
//     {
//         t1 *= 10;
//         t1 += s[i++] - '0';
//     }
//     if (f1)
//         t1 *= -1;
//     i += 5;
//     if (s[i] == '-')
//         i++, f2 = 1;
//     while (s[i] != ' ')
//     {
//         t2 *= 10;
//         t2 += s[i++] - '0';
//     }
//     if (f2)
//         t2 *= -1;
//     return {t1, t2};
// }

// pair<int, int> read3()
// {
//     int i = 0, f1 = 0, f2 = 0, t1 = 0, t2 = 0;
//     if (s[0] == '-')
//         i = f1 = 1;
//     while (s[i] != ' ')
//     {
//         t1 *= 10;
//         t1 += s[i++] - '0';
//     }
//     if (f1)
//         t1 *= -1;
//     i += 18;
//     if (s[i] == '-')
//         i++, f2 = 1;
//     while (i < s.length())
//     {
//         t2 *= 10;
//         t2 += s[i++] - '0';
//     }
//     if (f2)
//         t2 *= -1;
//     return {t1, t2};
// }

// pair<int, int> read4()
// {
//     int i = 0, f1 = 0, f2 = 0, t1 = 0, t2 = 0;
//     if (s[0] == '-')
//         i = f1 = 1;
//     while (s[i] != ' ')
//     {
//         t1 *= 10;
//         t1 += s[i++] - '0';
//     }
//     if (f1)
//         t1 *= -1;
//     i += 15;
//     if (s[i] == '-')
//         i++, f2 = 1;
//     while (i < s.length())
//     {
//         t2 *= 10;
//         t2 += s[i++] - '0';
//     }
//     if (f2)
//         t2 *= -1;
//     return {t1, t2};
// }

// int kind()
// {
//     for (int i = 0; 1; i++)
//     {
//         if (s[i] == ' ')
//         {
//             if (s[i + 4] == 't')
//                 return 3;
//             return 4;
//         }
//     }
// }

// int main()
// {

//     cin >> n >> m;
//     for (int i = 0, tmp; i < n; i++)
//     {
//         cin >> tmp;
//         push(tmp, i);
//     }

//     getchar();
//     int t1, t2;
//     while (m--)
//     {
//         getline(cin, s);
//         if (s.back() == 't')
//         {
//             t1 = read1();
//             if (a[0] == t1)
//                 cout << "T\n";
//             else
//                 cout << "F\n";
//         }
//         else if (s.back() == 's')
//         {
//             pair<int, int> t = read2();
//             t1 = t.first, t2 = t.second;
//             for (int i = 0; i < n; i++)
//             {
//                 if (a[i] == t1)
//                 {
//                     if (i % 2 && i + 1 < n && a[i + 1] == t2)
//                     {
//                         cout << "T\n";
//                         goto ss;
//                     }
//                     else if (i % 2 == 0 && i - 1 >= 0 && a[i - 1] == t2)
//                     {
//                         cout << "T\n";
//                         goto ss;
//                     }
//                 }

//                 if (a[i] == t2)
//                 {
//                     if (i % 2 && i + 1 < n && a[i + 1] == t1)
//                     {
//                         cout << "T\n";
//                         goto ss;
//                     }
//                     else if (i % 2 == 0 && i - 1 >= 0 && a[i - 1] == t1)
//                     {
//                         cout << "T\n";
//                         goto ss;
//                     }
//                 }
//             }
//             cout << "F\n";
//         ss:;
//         }
//         else if (kind() == 3)
//         {
//             pair<int, int> t = read3();
//             t1 = t.first, t2 = t.second;
//             for (int i = 1; i < n; i++)
//             {
//                 if (a[i] == t2 && a[(i - 1) / 2] == t1)
//                 {
//                     cout << "T\n";
//                     goto s3;
//                 }
//             }
//             cout << "F\n";
//         s3:;
//         }
//         else
//         {
//             pair<int, int> t = read4();
//             t1 = t.first, t2 = t.second;
//             for (int i = 1; i < n; i++)
//             {
//                 if (a[i] == t1 && a[(i - 1) / 2] == t2)
//                 {
//                     cout << "T\n";
//                     goto s4;
//                 }
//             }
//             cout << "F\n";
//         s4:;
//         }
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int sumDigits(int n)
// {
//     int ret = 0;
//     while (n)
//     {
//         ret += n % 10;
//         n /= 10;
//     }
//     return ret;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     cout << sumDigits(n);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int a1[30], a2[30];

// int main()
// {
//     unordered_map<int, int> mp;
//     int n1, n2;
//     cin >> n1;
//     for (int i = 1; i <= n1; i++)
//     {
//         cin >> a1[i];
//     }
//     cin >> n2;
//     for (int i = 1; i <= n2; i++)
//     {
//         cin >> a2[i];
//     }

//     int cnt = 0;
//     for (int i = 1; i <= n1; i++)
//     {
//         if (mp[a1[i]]++)
//             continue;
//         for (int j = 1; j <= n2; j++)
//             if (a2[j] == a1[i])
//             {
//                 goto ss;
//             }
//         if (cnt++)
//             cout << ' ';
//         cout << a1[i];
//     ss:;
//     }

//     for (int i = 1; i <= n2; i++)
//     {
//         if (mp[a2[i]]++)
//             continue;
//         for (int j = 1; j <= n1; j++)
//             if (a1[j] == a2[i])
//             {
//                 goto ss2;
//             }
//         if (cnt++)
//             cout << ' ';
//         cout << a2[i];
//     ss2:;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int a1[30], a2[30];

// int main()
// {
//     string s;
//     getline(cin, s);
//     int ans = 1;
//     for (int i = 0, len = s.length(); i < len;i++)
//     if(s[i] == ' ')
//         ans++;
//     cout << ans;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int di[1010];

// int main()
// {
//     string s1, s2;
//     cin >> s1 >> s2;

//     if (s1.length() == 1)
//     {
//         cout << "1 1";
//         return 0;
//     }

//     cout << (s1.length() + 1) / 2 << ' ';

//     int len = s1.length();
//     for (int i = 0, st, ed; i < len; i += 2)
//     {
//         st = s1[i] - '0';
//         ed = s2[i] - '0';
//         di[st]++;
//         di[ed]--;
//     }

//     int ans = di[0];
//     for (int i = 1; i <= 1000; i++)
//     {
//         di[i] = di[i] + di[i - 1];
//         ans = max(ans, di[i]);
//         // cout << di[i] << ' ';
//     }

//     cout << ans;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int a[105][105];
// pair<int, int> f[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//             cin >> a[i][j];

//     int ans = 0, cnt = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             int ok = 1, mn = INT_MAX;
//             for (int p = 0, x, y; p < 4; p++)
//             {
//                 x = i + f[p].first;
//                 y = j + f[p].second;
//                 if (x >= 1 && x <= n && y >= 1 && y <= n)
//                 {
//                     if (a[x][y] <= a[i][j])
//                     {
//                         ok = 0;
//                         break;
//                     }
//                     mn = min(mn, a[x][y]);
//                 }
//                 else
//                 {
//                     ok = 0;
//                     break;
//                 }
//             }
//             if (!ok)
//                 continue;
//             cnt++;
//             ans += mn - a[i][j];
//         }
//     }

//     cout << cnt << ' ' << ans;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class Position
// {
// public:
//     int x;
//     int y;
// };

// class Robot
// {
// public:
//     // initialize at (0, 0)
//     Robot()
//     {
//         currentPos.x = currentPos.y = 0;
//     }
//     // initialize at pos
//     Robot(const Position &pos)
//     {
//         currentPos = pos;
//     }
//     // dir could be 'N', 'E', 'S', 'W'
//     // for other characters, the robot don’t move
//     void Move(char dir)
//     {
//         if (dir == 'N')
//         {
//             currentPos.y++;
//         }
//         else if (dir == 'E')
//         {
//             currentPos.x++;
//         }
//         else if (dir == 'S')
//         {
//             currentPos.y--;
//         }
//         else if (dir == 'W')
//         {
//             currentPos.x--;
//         }
//     }
//     // return current position
//     Position GetPosition() const
//     {
//         return currentPos;
//     }

// private:
//     Position currentPos;
// };

// int main()
// {
//     int x, y;
//     cin >> x >> y;
//     Position c;
//     c.x = x;
//     c.y = y;
//     Robot a;
//     cout << a.GetPosition().x << " " << a.GetPosition().y << endl;
//     Robot b(c);
//     cout << b.GetPosition().x << " " << b.GetPosition().y << endl;
//     b.Move('E');
//     cout << b.GetPosition().x << " " << b.GetPosition().y << endl;
//     b.Move('N');
//     cout << b.GetPosition().x << " " << b.GetPosition().y << endl;
//     b.Move('W');
//     cout << b.GetPosition().x << " " << b.GetPosition().y << endl;
//     b.Move('S');
//     cout << b.GetPosition().x << " " << b.GetPosition().y << endl;
//     return 0;
// }

// #include <iostream>
// #include <iomanip>
// using namespace std;

// class Yuebao
// {
// private:
//     static double profitRate;

// public:
//     double balance;

//     Yuebao()
//     {
//         balance = 0;
//     }

//     Yuebao(double a)
//     {
//         balance = a;
//     }

//     void addProfit()
//     {
//         // cout << balance << ' ' << profitRate << '\n';
//         balance = balance * (1.0 + profitRate);
//     }

//     void deposit(double amount)
//     {
//         balance += amount;
//     }

//     void withdraw(double amount)
//     {
//         balance -= amount;
//     }

//     double getBalance()
//     {
//         return balance;
//     }

//     static void setProfitRate(double a)
//     {
//         profitRate = a;
//     }
// };

// int main()
// {
//     int n;
//     while (cin >> n)
//     {
//         double profitRate;
//         cin >> profitRate;
//         Yuebao::setProfitRate(profitRate); // 设定鱼额宝的利率
//         Yuebao y(0);                       // 新建鱼额宝账户，余额初始化为0
//         int operation;                     // 接受输入判断是存还是取
//         double amount;                     // 接受输入存取金额
//         for (int i = 0; i < n; ++i)
//         {
//             y.addProfit(); // 加入前一天余额产生的利息
//             // cout << profitRate << '\n';
//             cin >> operation >> amount;
//             if (operation == 0)
//                 y.deposit(amount); // 存入金额
//             else
//                 y.withdraw(amount); // 取出金额
//             // cout << fixed << setprecision(2) << y.getBalance() << endl; // 输出最终账户余额
//         }
//         cout << fixed << setprecision(2) << y.getBalance() << endl; // 输出最终账户余额
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class t
// {

// public:
//     static double dd;
//     static void setd(double a)
//     {
//         dd = a;
//     }

//     double getd()
//     {
//         return dd;
//     }
// };

// double t::dd = 0;

// int main()
// {
//     t a;
//     a.setd(1.9);
//     cout << a.getd();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int n, m, a, b;
// int s[1010][1010];
// const int mod = 998244353;

// struct node
// {
//     int v, x, y;
// };

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m >> a >> b;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             cin >> s[i][j];

//     long long ans = 0;
//     deque<node> q1, q2;
//     for (int i = 1; i + a - 1 <= n; i++)
//     {
//         for (int ii = i; ii <= i + a - 1; ii++)
//             for (int j = 1; j <= b; j++)
//             {
//                 while (q1.size() && (q1.back().v < s[ii][j] || q1.back().y > b || q1.back().x < i))
//                     q1.pop_back();
//                 while (q2.size() && (q2.back().v > s[ii][j] || q2.back().y > b || q2.back().x < i))
//                     q2.pop_back();
//                 while (q1.size() && (q1.front().y > b || q1.front().x < i))
//                     q1.pop_front();
//                 while (q2.size() && (q2.front().y > b || q2.front().x < i))
//                     q2.pop_front();
//                 q1.push_back({s[ii][j], ii, j});
//                 q2.push_back({s[ii][j], ii, j});
//             }

//         for (int j = 1; j + b - 1 <= m; j++)
//         {
//             for (int ii = i; ii <= i + a - 1; ii++)
//             {
//                 while (q1.size() && (q1.back().v < s[ii][j + b - 1] || q1.back().y > b || q1.back().x < i))
//                     q1.pop_back();
//                 while (q2.size() && (q2.back().v > s[ii][j + b - 1] || q2.back().y > b || q2.back().x < i))
//                     q2.pop_back();
//                 while (q1.size() && (q1.front().y < j || q1.front().y > j + b - 1 || q1.front().x < i))
//                     q1.pop_front();
//                 while (q2.size() && (q2.front().y < j || q2.front().y > j + b - 1 || q2.front().x < i))
//                     q2.pop_front();
//                 q1.push_back({s[ii][j + b - 1], ii, j + b - 1});
//                 q2.push_back({s[ii][j + b - 1], ii, j + b - 1});
//             }
//             ans += (q1.front().v * q2.front().v) % mod;
//             ans %= mod;
//         }
//     }

//     cout << ans;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int n, m, a, b;
// int s[1010][1010], mnr[1010][1010], mnc[1010][1010], mxr[1010][1010], mxc[1010][1010];
// const int mod = 998244353;

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     long long ans = 0;
//     cin >> n >> m >> a >> b;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             cin >> s[i][j];

//     for (int i = 1; i <= n; i++)
//     {
//         deque<int> q1, q2;
//         for (int j = 1; j < b; j++)
//         {
//             while (q1.size() && s[i][q1.back()] < s[i][j])
//                 q1.pop_back();
//             while (q2.size() && s[i][q2.back()] > s[i][j])
//                 q2.pop_back();
//             q1.push_back(j);
//             q2.push_back(j);
//         }
//         for (int j = b; j <= m; j++)
//         {
//             while (q1.size() && q1.front() < j - b + 1)
//                 q1.pop_front();
//             while (q2.size() && q2.front() < j - b + 1)
//                 q2.pop_front();
//             while (q1.size() && s[i][q1.back()] < s[i][j])
//                 q1.pop_back();
//             while (q2.size() && s[i][q2.back()] > s[i][j])
//                 q2.pop_back();
//             q1.push_back(j);
//             q2.push_back(j);
//             mxr[i][j] = s[i][q1.front()];
//             mnr[i][j] = s[i][q2.front()];
//         }
//     }

//     for (int j = b; j <= m; j++)
//     {
//         deque<int> q1, q2;
//         for (int i = 1; i < a; i++)
//         {
//             while (q1.size() && mxr[q1.back()][j] < mxr[i][j])
//                 q1.pop_back();
//             while (q2.size() && mnr[q2.back()][j] > mnr[i][j])
//                 q2.pop_back();
//             q1.push_back(i);
//             q2.push_back(i);
//         }
//         for (int i = a; i <= n; i++)
//         {
//             while (q1.size() && q1.front() < i - a + 1)
//                 q1.pop_front();
//             while (q2.size() && q2.front() < i - a + 1)
//                 q2.pop_front();
//             while (q1.size() && mxr[q1.back()][j] < mxr[i][j])
//                 q1.pop_back();
//             while (q2.size() && mnr[q2.back()][j] > mnr[i][j])
//                 q2.pop_back();
//             q1.push_back(i);
//             q2.push_back(i);
//             mxc[i][j] = mxr[q1.front()][j];
//             mnc[i][j] = mnr[q2.front()][j];
//             ans += (mxc[i][j] * mnc[i][j]) % mod;
//             ans %= mod;
//         }
//     }

//     cout << ans;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     while (cin >> s)
//     {
//         int len = s.length(), ans = 0, pw = 2;
//         for (int i = len - 1; i >= 0; i--)
//         {
//             ans += (s[i] - '0') * (pw - 1);
//             pw *= 2;
//         }
//         cout << ans << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     cout << "4/16 GPLT模拟赛";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     cout << "今天学习MySQL";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int a[11];
//     for (int i = 0; i < 10; i++)
//         cin >> a[i];
//     sort(a, a + 10, greater<int>());
//     for (int i = 0; i < 10; i++)
//         if (a[i] % 2)
//             cout << a[i] << ' ';
//     for (int i = 9; i >= 0; i--)
//         if (a[i] % 2 == 0)
//             cout << a[i] << ' ';
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// char s1[10010], s2[10010];

// int main()
// {
//     scanf("%s %s", s1, s2);
//     int n1 = strlen(s1), n2 = strlen(s2), ans = 0;
//     for (int i = 0; i < n1; i++)
//     {
//         for (int j = 0, t = 0; j < n2; j++)
//         {·
//             if ((s2[j] >= '0' && s2[j] <= '9') || s2[j] != s1[i + t])
//             {
//                 t = 0;
//             }
//             else
//             {
//                 t++;
//                 if (t > ans)
//                     ans = t;
//             }
//         }
//     }
//     printf("%d", ans);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     char a;
//     scanf("%d %c", &n, &a);
//     int n2 = round((double)n / 2.0);
//     for (int i = 0; i < n2; i++)
//     {
//         for (int j = 0; j < n; j++)
//             cout << a;
//         cout << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int a, b;
//     scanf("%d:%d", &a, &b);
//     int aa = a, bb = b;
//     if (b)
//         a++;
//     a -= 12;
//     if (a < 0)
//         printf("Only %02d:%02d.  Too early to Dang.", aa, bb);
//     else
//     {
//         for (int i = 0; i < a; i++)
//             cout << "Dang";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int t[] = {1, 0, 'X' + '0', 9, 8, 7, 6, 5, 4, 3, 2};
// int w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

// int main()
// {
//     int n;
//     cin >> n;
//     vector<string> vec;
//     while (n--)
//     {
//         string s;
//         cin >> s;
//         int sum = 0, f = 1;
//         for (int i = 0, tmp; i < 17; i++)
//         {
//             if (s[i] > '9' || s[i] < '0')
//             {
//                 f = 0;
//                 break;
//             }
//             tmp = s[i] - '0';
//             sum += w[i] * tmp;
//             sum %= 11;
//         }
//         if (f)
//         {
//             // cout << sum << '\n';
//             if (t[sum] + '0' != s.back())
//                 vec.push_back(s);
//         }
//         else
//             vec.push_back(s);
//     }
//     if (vec.size())
//     {
//         // cout << vec.size() << '\n';
//         for (int i = 0; i < vec.size(); i++)
//             cout << vec[i] << '\n';
//     }
//     else
//         cout << "All passed";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int hp[2], n;
// int s[2];

// int main()
// {
//     cin >> hp[0] >> hp[1] >> n;
//     int f = 1;
//     for (int i = 0; i < n; i++)
//     {
//         int a, b, c, d, f1 = 1, f2 = 1;
//         cin >> a >> b >> c >> d;
//         if (!f)
//             continue;
//         int sum = a + c;
//         if (b == sum)
//             f1 = 0;
//         if (d == sum)
//             f2 = 0;
//         if (f1 != f2)
//         {
//             if (!f1)
//             {
//                 s[0]++;
//                 hp[0]--;
//                 if (hp[0] < 0)
//                 {
//                     f = 0;
//                     cout << 'A' << '\n'
//                          << s[1];
//                 }
//             }
//             else
//             {
//                 s[1]++;
//                 hp[1]--;
//                 if (hp[1] < 0)
//                 {
//                     f = 0;
//                     cout << 'B' << '\n'
//                          << s[0];
//                 }
//             }
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;
//     int len = s.length();
//     int i = 0, f = 0, e = 0, cnt = 0, sum = len;
//     if (s[0] == '-')
//     {
//         f = 1;
//         i++;
//         sum--;
//     }
//     if ((s.back() - '0') % 2 == 0)
//     {
//         e = 1;
//     }

//     for (i; i < len; i++)
//     {
//         if (s[i] == '2')
//             cnt++;
//     }
//     double ans = (double)cnt / sum;
//     if (f)
//         ans *= 1.5;
//     if (e)
//         ans *= 2.0;
//     ans *= 100.0;
//     printf("%.2lf", ans);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int vis[10];
// vector<int> arr;
// int ind[11];

// int main()
// {
//     string s;
//     cin >> s;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (!vis[s[i] - '0'])
//         {
//             vis[s[i] - '0'] = 1;
//             arr.push_back(s[i] - '0');
//         }
//     }
//     sort(arr.begin(), arr.end(), greater<int>());
//     int siz = arr.size();
//     for (int i = 0; i < s.length(); i++)
//     {
//         for (int j = 0; j < siz; j++)
//         {
//             if (arr[j] == s[i] - '0')
//             {
//                 ind[i] = j;
//                 break;
//             }
//         }
//     }

//     printf("int[] arr = new int[]{");
//     int cnt = 0;
//     for (auto p : arr)
//     {
//         if (cnt++)
//             cout << ',';
//         cout << p;
//     }
//     printf("};\n");
//     printf("int[] index = new int[]{");
//     cnt = 0;
//     for (auto p : ind)
//     {
//         if (cnt++)
//             cout << ',';
//         cout << p;
//     }
//     printf("};");

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int vis[300];

// int main()
// {
//     string s1, s2;
//     getline(cin, s1);
//     getline(cin, s2);
//     for (int i = 0; i < s2.length(); i++)
//     {
//         vis[s2[i]] = 1;
//     }
//     for (int i = 0; i < s1.length(); i++)
//         if (!vis[s1[i]])
//             cout << s1[i];

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e4 + 5;
// int fa[N], vis[N], sum;

// int find(int x)
// {
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }

// void merg(int a, int b)
// {
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// int main()
// {

//     for (int i = 0; i < N; i++)
//         fa[i] = i;
//     int n;
//     cin >> n;
//     for (int k, i = 0, t, last; i < n; i++)
//     {
//         cin >> k >> last;
//         if (!vis[last])
//         {
//             vis[last] = 1;
//             sum++;
//         }
//         while (--k)
//         {
//             cin >> t;
//             merg(t, last);
//             last = t;
//             if (!vis[t])
//             {
//                 vis[t] = 1;
//                 sum++;
//             }
//         }
//     }

//     int cnt = 0;
//     for (int i = 0; i < N; i++)
//     {
//         if (vis[i] && fa[i] == i)
//             cnt++;
//     }
//     cout << sum << ' ' << cnt << '\n';
//     int q, a, b;
//     cin >> q;
//     while (q--)
//     {
//         cin >> a >> b;
//         if (fa[a] == fa[b])
//             cout << "Y\n";
//         else
//             cout << "N\n";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int n;

// struct node
// {
//     string ad, ne;
//     int data;
// };

// node a1[N], a2[N];

// int main()
// {
//     string head;
//     cin >> head >> n;
//     unordered_map<string, node> mp;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a1[i].ad >> a1[i].data >> a1[i].ne;
//         mp[a1[i].ad] = a1[i];
//     }
//     string cur = head;
//     for (int i = 0; cur != "-1"; i++)
//     {
//         a2[i] = mp[cur];
//         cur = mp[cur].ne;
//     }

//     for (int q = 0, p = n - 1; p >= q; p--, q++)
//     {
//         cout << a2[p].ad << ' ' << a2[p].data << ' ';
//         if (p == q)
//         {
//             cout << -1;
//             break;
//         }
//         cout << a2[q].ad << '\n'
//              << a2[q].ad << ' ' << a2[q].data << ' ';
//         if (q + 1 == p)
//         {
//             cout << -1;
//             break;
//         }
//         cout << a2[p - 1].ad << '\n';
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct node
{
    string name;
    int sum, mx;
};
vector<node> vec;

int main()
{
    int n;
    cin >> n;
    for (int i = 0, k, t; i < n; i++)
    {
        string s;
        cin >> s >> k;
        unordered_map<int, int> mp;
        int mx = 0;
        while (k--)
        {
            cin >> t;
            mx = max(mx, ++mp[t]);
        }
        node tmp;
        tmp.name = s;
        tmp.sum = mp.size();
        tmp.mx = mx;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), [](node e1, node e2) -> int
         { if(e1.sum == e2.sum)
            return e1.mx < e2.mx;
            return e1.sum > e2.sum; });

    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i >= vec.size())
        {
            if (cnt++)
                cout << ' ';
            cout << '-';
        }
        else
        {
            if (cnt++)
                cout << ' ';
            cout << vec[i].name;
        }
    }

    return 0;
}