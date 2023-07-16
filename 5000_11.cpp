// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 5e5 + 5;
// int n, m, ans[N][5], psize;
// vector<int> idx;             // 离散化下标
// array<int, 2> point[N];      // 点初始坐标
// array<int, 8> q[N];          // 问题的四个点坐标
// vector<array<int, 4>> event; // 要扫描的点
// int tr[N * 5];               // 树状数组

// int lowbit(int x)
// {
//     return x & -x;
// }

// void add(int x)
// {
//     while (x <= psize)
//     {
//         tr[x]++;
//         x += lowbit(x);
//     }
// }

// int getsum(int x)
// {
//     int ret = 0;
//     while (x)
//     {
//         ret += tr[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// int getidx(int x)
// {
//     return lower_bound(idx.begin(), idx.end(), x) - idx.begin() + 1;
// }

// signed main()
// {
//     cin >> n >> m;
//     event.reserve(n + 4 * m + 5);
//     idx.reserve(n + m * 2 + 5);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> point[i][0] >> point[i][1];
//         idx.push_back(point[i][0]);
//     }
//     for (int i = 1; i <= m; i++)
//     {
//         int x1, x2, y1, y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         q[i][0] = x2; // 坐标
//         q[i][1] = y2; // 坐标
//         q[i][2] = x1 - 1;
//         q[i][3] = y2;
//         q[i][4] = x2;
//         q[i][5] = y1 - 1;
//         q[i][6] = x1 - 1;
//         q[i][7] = y1 - 1;
//         idx.push_back(x2);
//         idx.push_back(x1 - 1);
//     }
//     sort(idx.begin(), idx.end());
//     idx.erase(unique(idx.begin(), idx.end()), idx.end());

//     array<int, 4> e = {0};
//     for (int i = 1; i <= n; i++)
//     {
//         e[0] = getidx(point[i][0]);
//         e[1] = point[i][1];
//         event.push_back(e);
//     }
//     for (int i = 1; i <= m; i++)
//     {
//         e[3] = i;               // 问题序号
//         e[0] = getidx(q[i][0]); // 坐标
//         e[1] = q[i][1];         // 坐标
//         e[2] = 1;               // 点号
//         event.push_back(e);
//         e[0] = getidx(q[i][2]);
//         e[1] = q[i][3];
//         e[2] = 2;
//         event.push_back(e);
//         e[0] = getidx(q[i][4]);
//         e[1] = q[i][5];
//         e[2] = 3;
//         event.push_back(e);
//         e[0] = getidx(q[i][6]);
//         e[1] = q[i][7];
//         e[2] = 4;
//         event.push_back(e);
//     }

//     psize = event.size() + 5;

//     sort(event.begin(), event.end(), [](array<int, 4> a1, array<int, 4> a2) -> int
//          {
//         if(a1[1] == a2[1])
//             // return a1[0] < a2[0];
//             return a1[2] < a2[2];
//         return a1[1] < a2[1]; });

//     for (auto e : event)
//     {
//         int x = e[0];
//         int y = e[1];
//         int pid = e[2];
//         int qid = e[3];

//         if (qid)
//         {
//             ans[qid][pid] = getsum(x);
//             // cout << x << ' ' << y << '\n';
//         }
//         else
//         {
//             add(x);
//         }
//     }

//     for (int i = 1; i <= m; i++)
//     {
//         cout << ans[i][1] - ans[i][2] - ans[i][3] + ans[i][4] << '\n';
//         // cout << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << ' ' << ans[i][4] << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 5;
// int n;
// vector<int> idx;
// vector<array<int, 4>> evt;

// struct info
// {
//     int mn, cnt;
//     info operator+(const info &e) const
//     {
//         info ret;
//         ret.mn = min(mn, e.mn);
//         if (mn < e.mn)
//             ret.cnt = cnt;
//         else if (e.mn < mn)
//             ret.cnt = e.cnt;
//         else
//             ret.cnt = cnt + e.cnt;
//         return ret;
//     }
// };

// struct node
// {
//     int tag;
//     info val;
// } tr[N << 3];

// void settag(int id, int v)
// {
//     tr[id].val.mn += v;
//     tr[id].tag += v;
// }

// void down(int id)
// {
//     if (tr[id].tag)
//     {
//         settag(id << 1, tr[id].tag);
//         settag(id << 1 | 1, tr[id].tag);
//         tr[id].tag = 0;
//     }
// }

// void up(int id)
// {
//     tr[id].val = tr[id << 1].val + tr[id << 1 | 1].val;
// }

// void build(int id, int l, int r)
// {
//     if (l == r)
//     {
//         tr[id] = {0, (info){0, idx[l] - idx[l - 1]}};
//         return;
//     }
//     int mid = l + r >> 1;
//     build(id << 1, l, mid);
//     build(id << 1 | 1, mid + 1, r);
//     up(id);
// }

// void modify(int id, int l, int r, int ql, int qr, int v)
// {
//     if (l > qr || r < ql)
//         return;
//     if (l == ql && r == qr)
//     {
//         settag(id, v);
//         return;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if (qr <= mid)
//         modify(id << 1, l, mid, ql, qr, v);
//     else if (ql > mid)
//         modify(id << 1 | 1, mid + 1, r, ql, qr, v);
//     else
//     {
//         modify(id << 1, l, mid, ql, mid, v);
//         modify(id << 1 | 1, mid + 1, r, mid + 1, qr, v);
//     }
//     up(id);
// }

// int getidx(int x)
// {
//     return lower_bound(idx.begin(), idx.end(), x) - idx.begin();
// }

// signed main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         int x1, x2, y1, y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         evt.push_back({x1, 1, y1, y2});
//         evt.push_back({x2, -1, y1, y2});
//         idx.push_back(y1);
//         idx.push_back(y2);
//     }
//     sort(idx.begin(), idx.end());
//     idx.erase(unique(idx.begin(), idx.end()), idx.end());
//     build(1, 1, idx.size() - 1);

//     int ans = 0, len = tr[1].val.cnt, cov, prex = 0;
//     sort(evt.begin(), evt.end());
//     for (auto [x, v, y1, y2] : evt)
//     {
//         cov = len;
//         if (!tr[1].val.mn)
//             cov -= tr[1].val.cnt;
//         ans += (x - prex) * cov;
//         int l = getidx(y1) + 1;
//         int r = getidx(y2);
//         modify(1, 1, idx.size() - 1, l, r, v);
//         prex = x;
//     }
//     cout << ans;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 5e4 + 5;
// const int M = 2e5 + 5;
// int n, m, a[N], B, id[N], cnt, ans[M], preAns;
// unordered_map<int, int> num;

// void build()
// {
//     for (int i = 1; i <= n; i++)
//         id[i] = (i - 1) / B + 1;
// }

// struct Query
// {
//     int l, r, ID;
//     int operator<(const Query &e) const
//     {
//         if (id[l] == id[e.l])
//             if (id[l] & 1)
//                 return r < e.r;
//             else
//                 return r > e.r;
//         return id[l] < id[e.l];
//     }
// } q[M];

// void add(int x)
// {
//     if (!num[x])
//         preAns++;
//     num[x]++;
// }

// void del(int x)
// {
//     num[x]--;
//     if (!num[x])
//         preAns--;
// }

// signed main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     cin >> m;
//     B = n / sqrt(m);
//     build();
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> q[i].l >> q[i].r;
//         q[i].ID = i;
//     }
//     sort(q + 1, q + 1 + m);

//     for (int i = 1, l = 1, r = 0; i <= m; i++)
//     {
//         while (l < q[i].l)
//             del(a[l++]);
//         while (r < q[i].r)
//             add(a[++r]);
//         while (l > q[i].l)
//             add(a[--l]);
//         while (r > q[i].r)
//             del(a[r--]);
//         ans[q[i].ID] = preAns;
//     }

//     for (int i = 1; i <= m; i++)
//         cout << ans[i] << '\n';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 4e4 + 10;
// const int M = 5e4 + 10;
// const int mB = 250;
// int n, m, a[N], ql, qr, x, B, id[N], l[mB], r[mB], mxn[mB][mB];
// unordered_map<int, vector<int>> vec;

// void build()
// {
//     for (int i = 1; i <= n; i++)
//         id[i] = (i - 1) / B + 1;
//     for (int i = 1; i <= id[n]; i++)
//     {
//         l[i] = (i - 1) * B + 1;
//         r[i] = min(n, i * B);
//     }
//     for (int i = 1; i <= id[n]; i++)
//     {
//         unordered_map<int, int> mp;
//         int mx = 0;
//         for (int j = l[i]; j <= n; j++)
//         {
//             mp[a[j]]++;
//             if (mp[a[j]] > mp[mx] || (mp[a[j]] == mp[mx] && a[j] < mx))
//                 mx = a[j];
//             if (j == r[id[j]])
//             {
//                 mxn[i][id[j]] = mx;
//             }
//         }
//     }
// }

// int getsum(int ql, int qr, int v)
// {
//     auto st = lower_bound(vec[v].begin(), vec[v].end(), ql);
//     auto ed = lower_bound(vec[v].begin(), vec[v].end(), qr);
//     int ret = ed - st + 1;
//     if (ed == vec[v].end() || (ed != vec[v].end() && *ed != qr))
//         ret--;
//     return ret;
// }

// int query(int ql, int qr)
// {
//     int ret = 0, mx = 0, ll = ql, rr = qr;
//     if (id[ll] == id[ll - 1])
//     {
//         int R = min(r[id[ll]], rr);
//         for (int i = ll; i <= R; i++)
//         {
//             int tmp = getsum(ql, qr, a[i]);
//             if (tmp > mx || (tmp == mx && a[i] < ret))
//                 ret = a[i], mx = tmp;
//         }
//         if (R == rr)
//             return ret;
//         ll = R + 1;
//     }
//     if (id[rr] == id[rr + 1])
//     {
//         int L = max(l[id[rr]], ll);
//         for (int i = L; i <= rr; i++)
//         {
//             int tmp = getsum(ql, qr, a[i]);
//             if (tmp > mx || (tmp == mx && a[i] < ret))
//                 ret = a[i], mx = tmp;
//         }
//         if (L == ll)
//             return ret;
//         rr = L - 1;
//     }
//     int tmp = getsum(ql, qr, mxn[id[ll]][id[rr]]);
//     if (tmp > mx || (tmp == mx && mxn[id[ll]][id[rr]] < ret))
//         ret = mxn[id[ll]][id[rr]], mx = tmp;

//     return ret;
// }

// signed main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i], vec[a[i]].push_back(i);
//     B = sqrt(n);
//     build();

//     for (int i = 1; i <= m; i++)
//     {
//         cin >> ql >> qr;
//         ql = (ql + x - 1) % n + 1;
//         qr = (qr + x - 1) % n + 1;

//         cout << query(ql, qr) << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// const int M = 1e6 + 10;
// const int ADD = -1;
// const int DEL = 1;
// const int EDGE = 0;
// int n, m, ans = 1;
// vector<array<int, 4>> evt; // x,kind,(y,v)/(y1,y2)

// int tr[M];

// int lowbit(int x)
// {
//     return x & -x;
// }

// void add(int x, int v)
// {
//     while (x < M)
//     {
//         tr[x] += v;
//         x += lowbit(x);
//     }
// }

// int getsum(int x)
// {
//     int ret = 0;
//     while (x > 0)
//     {
//         ret += tr[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// signed main()
// {
//     cin >> n >> m;
//     evt.reserve(n * 2 + m + 10);
//     for (int i = 1; i <= n; i++)
//     {
//         int y, x1, x2;
//         cin >> y >> x1 >> x2;
//         if (x1 == 0 && x2 == 1000000)
//             ans++;
//         evt.push_back({x1, ADD, y, 1});
//         evt.push_back({x2, DEL, y, -1});
//     }
//     for (int i = 1; i <= m; i++)
//     {
//         int x, y1, y2;
//         cin >> x >> y1 >> y2;
//         if (y1 == 0 && y2 == 1000000)
//             ans++;
//         evt.push_back({x, EDGE, y1, y2});
//     }
//     sort(evt.begin(), evt.end());

//     for (auto e : evt)
//     {
//         if (e[1])
//         {
//             int y = e[2], v = e[3];
//             add(y, v);
//         }
//         else
//         {
//             int y1 = e[2], y2 = e[3];
//             ans += getsum(y2) - getsum(y1 - 1);
//         }
//     }

//     cout << ans;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 5;
// int n, m, a[N], ls[N * 50], rs[N * 50], rt[N * 50], tot, sum[N * 50];
// vector<int> idx;

// void up(int id)
// {
//     sum[id] += sum[ls[id]];
//     sum[id] += sum[rs[id]];
// }

// void newLine(int &cur, int pre, int l, int r, int v)
// {
//     cur = ++tot;
//     ls[cur] = ls[pre], rs[cur] = rs[pre], sum[cur] = sum[pre] + 1;
//     if (l == r)
//         return;
//     int mid = l + r >> 1;
//     if (v <= mid)
//         newLine(ls[cur], ls[pre], l, mid, v);
//     else
//         newLine(rs[cur], rs[pre], mid + 1, r, v);
// }

// int query(int cur, int pre, int l, int r, int k)
// {
//     if (l == r)
//         return l;
//     int mid = l + r >> 1;
//     int sl = sum[ls[cur]] - sum[ls[pre]];
//     if (k <= sl)
//         return query(ls[cur], ls[pre], l, mid, k);
//     else
//         return query(rs[cur], rs[pre], mid + 1, r, k - sl);
// }

// int getidx(int x)
// {
//     return lower_bound(idx.begin(), idx.end(), x) - idx.begin() + 1;
// }

// signed main()
// {
//     cin >> n >> m;
//     idx.reserve(n + 10);
//     for (int i = 1; i <= n; i++)
//         cin >> a[i], idx.push_back(a[i]);
//     sort(idx.begin(), idx.end());
//     idx.erase(unique(idx.begin(), idx.end()), idx.end());
//     for (int i = 1; i <= n; i++)
//     {
//         a[i] = getidx(a[i]);
//         newLine(rt[i], rt[i - 1], 1, n, a[i]);
//     }
//     for (int i = 1; i <= m; i++)
//     {
//         int l, r, k;
//         cin >> l >> r >> k;
//         cout << idx[query(rt[r], rt[l - 1], 1, n, k) - 1] << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 3e5 + 10;
// int n, m, a[N], ls[N * 50], rs[N * 50], rt[N * 50], tot, sum[N * 50];

// void newLine(int &cur, int pre, int l, int r, int v)
// {
//     cur = ++tot;
//     ls[cur] = ls[pre], rs[cur] = rs[pre], sum[cur] = sum[pre] + 1;
//     if (l == r)
//         return;
//     int mid = l + r >> 1;
//     if (v <= mid)
//         newLine(ls[cur], ls[pre], l, mid, v);
//     else
//         newLine(rs[cur], rs[pre], mid + 1, r, v);
// }

// int query(int cur, int pre, int l, int r, int k)
// {
//     if (l == r)
//         if (sum[cur] - sum[pre] > k)
//             return l;
//         else
//             return -1;
//     int mid = l + r >> 1;
// int sl = sum[ls[cur]] - sum[ls[pre]];
// int sr = sum[rs[cur]] - sum[rs[pre]];
// if (sl > k && sr > k)
//     return min(query(ls[cur], ls[pre], l, mid, k), query(rs[cur], rs[pre], mid + 1, r, k));
// if (sl > k)
//     return query(ls[cur], ls[pre], l, mid, k);
// else if (sr > k)
//     return query(rs[cur], rs[pre], mid + 1, r, k);
// else
//     return -1;
// }

// signed main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i], newLine(rt[i], rt[i - 1], 1, n, a[i]);
//     for (int i = 1; i <= m; i++)
//     {
//         int l, r, k;
//         cin >> l >> r >> k;
//         k = (r - l + 1) / k;
//         cout << query(rt[r], rt[l - 1], 1, n, k) << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// const int N = 3e5 + 10;
// const int M = N * 25;
// int n, q, a[N], tot, rt[M], ls[M], rs[M], sum[M];

// void newLine(int &cur, int pre, int l, int r, int v)
// {
//     cur = ++tot;
//     ls[cur] = ls[pre], rs[cur] = rs[pre], sum[cur] = sum[pre] + 1;
//     if (l == r)
//         return;
//     int mid = l + r >> 1;
//     if (v <= mid)
//         newLine(ls[cur], ls[pre], l, mid, v);
//     else
//         newLine(rs[cur], rs[pre], mid + 1, r, v);
// }

// int query(int cur, int pre, int l, int r, int k)
// {
//     if (l == r)
//         if (sum[cur] - sum[pre] > k)
//             return l;
//         else
//             return 1e7;
//     int mid = l + r >> 1;
//     int sl = sum[ls[cur]] - sum[ls[pre]];
//     int sr = sum[rs[cur]] - sum[rs[pre]];
//     if (sl > k && sr > k)
//         return min(query(ls[cur], ls[pre], l, mid, k), query(rs[cur], rs[pre], mid + 1, r, k));
//     if (sl > k)
//         return query(ls[cur], ls[pre], l, mid, k);
//     else if (sr > k)
//         return query(rs[cur], rs[pre], mid + 1, r, k);
//     else
//         return 1e7;
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> q;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     for (int i = 1; i <= n; i++)
//         newLine(rt[i], rt[i - 1], 1, n, a[i]);

//     for (int i = 1; i <= q; i++)
//     {
//         int l, r, k;
//         cin >> l >> r >> k;
//         k = (r - l + 1) / k;
//         int ret = query(rt[r], rt[l - 1], 1, n, k);
//         if (ret == 1e7)
//             cout << "-1\n";
//         else
//             cout << ret << '\n';
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// const int M = N * 25;
// int n, q, dep[N], par[N][20], tr[M], tot, ls[M], rs[M], sum[M];
// vector<array<int, 2>> G[N];

// void init()
// {
//     for (auto &vec : G)
//         vec.clear();
//     tot = 0;
// }

// void newLine(int &cur, int pre, int l, int r, int v)
// {
//     cur = ++tot;
//     ls[cur] = ls[pre], rs[cur] = rs[pre], sum[cur] = sum[pre] + 1;
//     if (l == r)
//         return;
//     int mid = l + r >> 1;
//     if (v <= mid)
//         newLine(ls[cur], ls[pre], l, mid, v);
//     else
//         newLine(rs[cur], rs[pre], mid + 1, r, v);
// }

// void dfs(int u, int fa)
// {
//     par[u][0] = fa;
//     dep[u] = dep[fa] + 1;
//     for (int i = 1; i < 20; i++)
//         par[u][i] = par[par[u][i - 1]][i - 1];

//     for (auto [v, w] : G[u])
//         if (v != fa)
//             newLine(tr[v], tr[u], 1, N, w), dfs(v, u);
// }

// int query(int u, int v, int ca, int l, int r, int k)
// {
//     if (l == r)
//         return l;
//     int mid = l + r >> 1;
//     int sl = sum[ls[u]] + sum[ls[v]] - 2 * sum[ls[ca]];
//     if (k <= sl)
//         return query(ls[u], ls[v], ls[ca], l, mid, k);
//     else
//         return query(rs[u], rs[v], rs[ca], mid + 1, r, k - sl);
// }

// int getlca(int u, int v)
// {
//     if (dep[u] < dep[v])
//         swap(u, v);
//     for (int i = 19; i >= 0; i--)
//         if (dep[par[u][i]] >= dep[v])
//             u = par[u][i];
//     if (u == v)
//         return u;
//     for (int i = 19; i >= 0; i--)
//         if (par[u][i] != par[v][i])
//         {
//             u = par[u][i];
//             v = par[v][i];
//         }
//     return par[u][0];
// }

// void solve()
// {
//     cin >> n;
//     init();
//     for (int i = 1; i < n; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         G[u].push_back({v, w});
//         G[v].push_back({u, w});
//     }
//     newLine(tr[1], tr[0], 1, N, 0);
//     dfs(1, 0);
//     cin >> q;
//     while (q--)
//     {
//         int u, v, lca, len;
//         cin >> u >> v;
//         lca = getlca(u, v);
//         len = dep[u] + dep[v] - 2 * dep[lca];
//         double ret = query(tr[u], tr[v], tr[lca], 1, N, (len + 1) / 2);
//         if (len % 2 == 0)
//         {
//             ret += query(tr[u], tr[v], tr[lca], 1, N, (len / 2) + 1);
//             ret /= 2.0;
//             // cout << "! " << (len / 2) + 1 << ' ';
//         }
//         // cout << u << ' ' << v << ": " << len << ' ' << (len + 1) / 2 << '\n';
//         // cout << u << ' ' << v << " lca " << lca << '\n';
//         printf("%.1lf\n", ret);
//     }
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 5;
// const int M = 1e6 + 5;
// int n, m, a[N], ls[N * 25], rs[N * 25], rt[N * 25], tot, sum[N * 25], pw[N], s[N * 25];
// vector<int> idx;

// int getidx(int x)
// {
//     return lower_bound(idx.begin(), idx.end(), x) - idx.begin() + 1;
// }

// void newLine(int &cur, int pre, int l, int r, int v)
// {
//     cur = ++tot;
//     ls[cur] = ls[pre], rs[cur] = rs[pre], sum[cur] = sum[pre] + 1, s[cur] = s[pre] + idx[v - 1];
//     if (l == r)
//         return;
//     int mid = l + r >> 1;
//     if (v <= mid)
//         newLine(ls[cur], ls[pre], l, mid, v);
//     else
//         newLine(rs[cur], rs[pre], mid + 1, r, v);
// }

// int query(int cur, int pre, int l, int r, int k)
// {
//     // cout << l << ' ' << r << ' ' << k << '\n';
//     if (l == r)
//         return idx[l - 1] * k;
//     int mid = l + r >> 1;
//     int sr = sum[rs[cur]] - sum[rs[pre]];
//     if (k > sr)
//         return query(ls[cur], ls[pre], l, mid, k - sr) + s[rs[cur]] - s[rs[pre]];
//     else if (k == sr)
//         return s[rs[cur]] - s[rs[pre]];
//     else
//         return query(rs[cur], rs[pre], mid + 1, r, k);
// }

// void init()
// {
//     tot = 0;
//     idx.clear();
//     idx.reserve(n + 10);
// }

// void solve()
// {
//     init();
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i], idx.push_back(a[i]);
//     sort(idx.begin(), idx.end());
//     idx.erase(unique(idx.begin(), idx.end()), idx.end());
//     for (int i = 1; i <= n; i++)
//     {
//         a[i] = getidx(a[i]);
//         newLine(rt[i], rt[i - 1], 1, n, a[i]);
//     }
//     cin >> m;
//     for (int i = 1; i <= m; i++)
//     {
//         int l, r, k;
//         cin >> l >> r >> k;
//         // cout << query(rt[r], rt[l - 1], 1, n, k) - 1 << '\n';
//         cout << query(rt[r], rt[l - 1], 1, n, k) + pw[r - l + 1] << '\n';
//     }
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     for (int i = 1; i < N; i++)
//     {
//         pw[i] = pw[i - 1] + i * i;
//     }
//     int t;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 5;
// int a[N], n;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         int ans = 0;
//         unordered_map<int, int> mp;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> a[i];
//             if (++mp[a[i]] <= 2)
//                 ans++;
//         }
//         cout << ((ans + 1) >> 1) << '\n';
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 5;
// int n, m, a[N], ls[N * 50], rs[N * 50], rt[N * 50], tot, sum[N * 50];
// vector<int> idx;

// void newLine(int &cur, int pre, int l, int r, int v)
// {
//     cur = ++tot;
//     ls[cur] = ls[pre], rs[cur] = rs[pre], sum[cur] = sum[pre] + 1;
//     if (l == r)
//         return;
//     int mid = l + r >> 1;
//     if (v <= mid)
//         newLine(ls[cur], ls[pre], l, mid, v);
//     else
//         newLine(rs[cur], rs[pre], mid + 1, r, v);
// }

// int query(int cur, int pre, int l, int r, int k)
// {
//     if (l == r)
//         return l;
//     int mid = l + r >> 1;
//     int sl = sum[ls[cur]] - sum[ls[pre]];
//     if (k <= sl)
//         return query(ls[cur], ls[pre], l, mid, k);
//     else
//         return query(rs[cur], rs[pre], mid + 1, r, k - sl);
// }

// int getidx(int x)
// {
//     return lower_bound(idx.begin(), idx.end(), x) - idx.begin() + 1;
// }

// signed main()
// {
//     cin >> n >> m;
//     idx.reserve(n + 10);
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     for (int i = 1; i <= n; i++)
//     {
//         // a[i] = getidx(a[i]);
//         newLine(rt[i], rt[i - 1], 1, n, a[i]);
//     }
//     for (int i = 1; i <= m; i++)
//     {
//         int l, r, k;
//         cin >> l >> r >> k;
//         cout << query(rt[r], rt[l - 1], 1, n, k) << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 5010;
// const int M = N * 15;
// int n, a[N], tot, tr[M], ls[M], rs[M], sum[M];

// void newLine(int &cur, int pre, int l, int r, int v)
// {
//     cur = ++tot;
//     ls[cur] = ls[pre], rs[cur] = rs[pre], sum[cur] = sum[pre] + 1;
//     if (l == r)
//         return;
//     int mid = l + r >> 1;
//     if (v <= mid)
//         newLine(ls[cur], ls[pre], l, mid, v);
//     else
//         newLine(rs[cur], rs[pre], mid + 1, r, v);
// }

// int query(int cur, int pre, int l, int r, int v)
// {
//     // cout << l << ' ' << r << '\n';
//     if (v < l)
//         return 0;
//     if (r <= v)
//         return sum[cur] - sum[pre];
//     int mid = l + r >> 1;
//     if (v <= mid)
//         return query(ls[cur], ls[pre], l, mid, v);
//     else
//         return query(rs[cur], rs[pre], mid + 1, r, v) + sum[ls[cur]] - sum[ls[pre]];
// }

// void init()
// {
//     tot = 0;
// }

// void solve()
// {
//     init();
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i], newLine(tr[i], tr[i - 1], 1, n, a[i]);
//     int ans = 0;
//     for (int i = 2; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             ans += query(tr[i - 1], tr[0], 1, n, a[j] - 1) * query(tr[n], tr[j], 1, n, a[i] - 1);
//         }
//     }
//     cout << ans << '\n';
// }

// signed main()
// {

//     int t;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 5;
// const int M = N * 20;
// const int mxn = 1e9 + 5;
// int n, m, a[N], tr[M], ls[M], rs[M], sum[M], tot;

// void newLine(int &cur, int pre, int l, int r, int v)
// {
//     cur = ++tot;
//     ls[cur] = ls[pre], rs[cur] = rs[pre], sum[cur] = sum[pre] + 1;
//     if (l == r)
//         return;
//     int mid = l + r >> 1;
//     if (v <= mid)
//         newLine(ls[cur], ls[pre], l, mid, v);
//     else
//         newLine(rs[cur], rs[pre], mid + 1, r, v);
// }

// int query(int cur, int pre, int l, int r, int k)
// {
//     if (l == r)
//         return l;
//     int mid = l + r >> 1;
//     int sl = sum[ls[cur]] - sum[ls[pre]];
//     if (k > sl)
//         return query(rs[cur], rs[pre], mid + 1, r, k - sl);
//     else
//         return query(ls[cur], ls[pre], l, mid, k);
// }

// signed main()
// {

//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i], newLine(tr[i], tr[i - 1], -mxn, mxn, a[i]);
//     while (m--)
//     {
//         int l, r, k;
//         cin >> l >> r >> k;
//         cout << query(tr[r], tr[l - 1], -mxn, mxn, k) << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// const int N = 5010;
// const int M = N * 15;
// int n, a[N], letc[N][N], letb[N][N];

// void init()
// {
//     for (int i = 0; i <= n + 1; i++)
//         for (int j = 0; j <= n + 1; j++)
//             letc[i][j] = letb[i][j] = 0;
// }

// void solve()
// {
//     cin >> n;
//     init();
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     for (int i = 3; i < n; i++)
//     {
//         // letc[i][0] = 0;
//         int cnt = 0;
//         for (int j = 1; j < i - 1; j++)
//         {
//             // letc[i][j] = letc[i][j - 1];
//             if (a[j] < a[i])
//                 cnt++;
//             letc[i][j] = cnt;
//         }
//     }
//     for (int i = n - 2; i > 1; i--)
//     {
//         // letb[i][n + 1] = 0;
//         int cnt = 0;
//         for (int j = n; j > i + 1; j--)
//         {
//             // letb[i][j] = letb[i][j + 1];
//             if (a[j] < a[i])
//                 cnt++;
//             letb[i][j] = cnt;
//         }
//     }
//     long long ans = 0;
//     for (int i = 2; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             ans += letb[i][j + 1] * letc[j][i - 1];
//         }
//     }
//     cout << ans << '\n';
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 3e5 + 5;
// int n, m, mnl, dep[N], f;
// vector<int> G[N];

// void dfs(int u, int fa)
// {
//     dep[u] = dep[fa] + 1;
//     if (G[u].size() == 1)
//     {
//         if (mnl > dep[u] || mnl == -1)
//             mnl = dep[u], f = 0;
//         return;
//     }
//     if (G[u].size() == 2 && u != 1)
//     {
//         dep[u]++;
//         if (mnl >= dep[u] || mnl == -1)
//             mnl = dep[u], f = 1;
//         return;
//     }
//     for (auto v : G[u])
//         if (v != fa)
//         {
//             dfs(v, u);
//         }
// }

// void solve()
// {
//     mnl = -1;
//     f = 0;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         G[i].clear();
//     for (int i = 1; i < n; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         G[u].push_back(v);
//         G[v].push_back(u);
//     }
//     if (G[1].size() == 1)
//     {
//         cout << n - 2 << '\n';
//         return;
//     }
//     dfs(1, 0);
//     int ans = n - max((mnl * 2 - 1), 2ll);
//     if (f)
//         ans++;
//     cout << ans << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 5;
// int n, m, a[N], s, x, siz, a1, a2, a3;

// void init()
// {
//     s = x = siz = 0;
// }

// void solve()
// {
//     cin >> n;
//     init();
//     for (int i = 1; i <= n; i++)
//         cin >> a[i], s += a[i], x ^= a[i];

//     a1 = (1ll << 50) + (s & 1);
//     s += a1;
//     x ^= a1;
//     a2 = a3 = ((2 * x) - s) / 2;
//     s += a2;
//     x ^= a2;
//     s += a2;
//     x ^= a2;
//     cout << "3\n"
//          << a1 << ' ' << a2 << ' ' << a2 << '\n';

//     // if (s == 2 * x)
//         // cout << "YES\n";
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 5;
// const int mod = 1e9 + 7;
// int n, a[N];

// void solve()
// {
//     int xo = 0, cnt = 0;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     xo = a[1];
//     for (int i = 1; i <= n; i++)
//         xo &= a[i];
//     for (int i = 1; i <= n; i++)
//         if (a[i] == xo)
//             cnt++;
//     int ans = cnt * (cnt - 1) % mod;
//     for (int i = n - 2; i > 0; i--)
//         ans = (ans * i) % mod;
//     cout << ans << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e9;
// int n, a, b;

// void solve()
// {
//     cin >> n >> a >> b;
//     if (b == 1)
//     {
//         cout << "Yes\n";
//         return;
//     }
//     if (a == 1)
//     {
//         if ((n - 1) % b == 0)
//             cout << "Yes\n";
//         else
//             cout << "No\n";
//         return;
//     }

//     int pw = 1;
//     for (pw; pw <= n; pw *= a)
//         if ((n - pw) % b == 0)
//         {
//             cout << "Yes\n";
//             return;
//         }
//     cout << "No\n";
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 5e5 + 10;
// int n, m, d, a[N], p[N], pos[N];

// void solve()
// {
//     cin >> n >> m >> d;
//     for (int i = 1; i <= n; i++)
//         cin >> p[i], pos[p[i]] = i;
//     for (int i = 1; i <= m; i++)
//         cin >> a[i];
//     int ans = 1e9;
//     if (d + 1 >= n)
//         for (int i = 1; i < m; i++)
//         {
//             ans = min(ans, max(0ll, pos[a[i + 1]] - pos[a[i]]));
//         }
//     else
//         for (int i = 1; i < m; i++)
//         {
//             ans = min(ans, max(0ll, min(pos[a[i + 1]] - pos[a[i]], 1 + pos[a[i]] + d - pos[a[i + 1]])));
//         }
//     cout << ans << '\n';
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int n, q, x, y, ad, di;
// string s;

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> s >> q;
//     for (auto c : s)
//         if (c == '+')
//             ad++;
//         else
//             di++;
//     if (ad > di)
//         swap(ad, di);
//     while (q--)
//     {
//         cin >> x >> y;
//         if (x < y)
//             swap(x, y);
//         if (ad == di)
//             cout << "YES\n";
//         else if (x == y)
//             cout << "NO\n";
//         else
//         {
//             int s1 = ad * x;
//             int s2 = di * x;
//             int det = s2 - s1;
//             if (det % (x - y) == 0 && det / (x - y) <= di)
//                 cout << "YES\n";
//             else
//                 cout << "NO\n";
//         }
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, q, a[N];

// struct node
// {
//     int ans, len, head, tail, front, back;
//     node operator+(const node &e) const
//     {
//         node ret;
//         ret.ans = ans + e.ans; // 答案先相加
//         ret.len = len + e.len; // 长度
//         ret.front = front;     // 第一个数
//         ret.back = e.back;     // 最后一个数
//         if (head == len && back <= e.front)
//             ret.head = head + e.head;
//         else
//             ret.head = head; // 最长非递减前缀
//         if (e.tail == len && back <= e.front)
//             ret.tail = tail + e.tail;
//         else
//             ret.tail = e.tail; // 最长非递减后缀
//         if (back <= e.front)
//         {
//             ret.ans -= tail * (tail + 1) / 2;
//             ret.ans -= e.head * (e.head + 1) / 2;
//             ret.ans += (tail + e.head) * (tail + e.head + 1) / 2;
//         }
//         return ret;
//     }
// } tr[N << 2];

// void up(int id)
// {
//     tr[id] = tr[id << 1] + tr[id << 1 | 1];
// }

// void build(int id, int ql, int qr)
// {
//     if (ql == qr)
//     {
//         tr[id].ans = tr[id].head = tr[id].tail = tr[id].len = 1;
//         tr[id].front = tr[id].back = a[ql];
//         return;
//     }
//     int mid = ql + qr >> 1;
//     build(id << 1, ql, mid);
//     build(id << 1 | 1, mid + 1, qr);
//     up(id);
// }

// void modify(int id, int l, int r, int x, int v)
// {
//     if (l == r)
//     {
//         a[l] = v;
//         tr[id].front = tr[id].back = v;
//         return;
//     }
//     int mid = l + r >> 1;
//     if (x <= mid)
//         modify(id << 1, l, mid, x, v);
//     else
//         modify(id << 1 | 1, mid + 1, r, x, v);
//     up(id);
// }

// node query(int id, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//         return tr[id];
//     int mid = l + r >> 1;
//     if (qr <= mid)
//         return query(id << 1, l, mid, ql, qr);
//     else if (ql > mid)
//         return query(id << 1 | 1, mid + 1, r, ql, qr);
//     else
//         return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> q;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     build(1, 1, n);
//     while (q--)
//     {
//         int k, l, r;
//         cin >> k >> l >> r;
//         if (k == 1)
//         {
//             modify(1, 1, n, l, r);
//         }
//         else
//         {
//             cout << query(1, 1, n, l, r).ans << '\n';
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, m, a[N];

// struct info
// {
//     int ans;
//     int len;
//     int pre_len;
//     int suf_len;
//     int front;
//     int back;
// };
// struct node
// {
//     info val;
// } tr[N << 2];

// info operator+(const info &a, const info &b)
// {
//     info c;
//     c.ans = a.ans + b.ans;
//     c.len = a.len + b.len;
//     c.front = a.front;
//     c.back = b.back;
//     c.pre_len = a.pre_len;
//     c.suf_len = b.suf_len;
//     if (a.back <= b.front)
//     {
//         c.ans -= (a.suf_len * (a.suf_len + 1)) / 2 + (b.pre_len * (b.pre_len + 1)) / 2;
//         int tmp = a.suf_len + b.pre_len;
//         c.ans += tmp * (tmp + 1) / 2;
//         if (a.len == a.pre_len)
//             c.pre_len = a.len + b.pre_len;
//         if (b.len == b.pre_len)
//             c.suf_len = a.suf_len + b.suf_len;
//     }
//     return c;
// }

// void up(int id)
// {
//     tr[id].val = tr[lson].val + tr[rson].val;
// }

// void build(int id, int l, int r)
// {
//     if (l == r)
//     {
//         tr[id].val.ans = tr[id].val.len = tr[id].val.pre_len = tr[id].val.suf_len = 1;
//         tr[id].val.back = tr[id].val.front = a[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// void change(int id, int l, int r, int x, int v)
// {
//     if (l == r)
//     {
//         a[l] = v;
//         tr[id].val.front = tr[id].val.back = v;
//         return;
//     }
//     int mid = l + r >> 1;
//     if (x <= mid)
//         change(lson, l, mid, x, v);
//     else
//         change(rson, mid + 1, r, x, v);
//     up(id);
// }

// info query(int id, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//         return tr[id].val;
//     int mid = l + r >> 1;
//     if (qr <= mid)
//         return query(lson, l, mid, ql, qr);
//     else if (ql > mid)
//         return query(rson, mid + 1, r, ql, qr);
//     else
//         return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
// }

// signed main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     build(1, 1, n);
//     while (m--)
//     {
//         int op, l, r;
//         cin >> op >> l >> r;
//         if (op == 1)
//         {
//             change(1, 1, n, l, r);
//         }
//         else
//         {
//             cout << query(1, 1, n, l, r).ans << '\n';
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 21;
// const int M = 410;
// int n, m, a[N][N];

// bool check(int x)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//             if (a[i][j] && (x & (1 << i)) && (x & (1 << j)))
//                 return 0;
//     }
//     return 1;
// }

// signed main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         u--, v--;
//         a[u][v] = a[v][u] = 1;
//     }
//     int ans = 0;
//     for (int i = 0; i < (1 << n); i++)
//     {
//         if (check(i))
//             ans++;
//     }
//     cout << ans << '\n';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 500;
// int n, a[N * 2], dp[N << 1][N << 1], sum[N * 2], mx[N << 1][N << 1];

// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i], a[n + i] = a[i];
//     for (int i = 1; i <= 2 * n; i++)
//         sum[i] = sum[i - 1] + a[i];

//     for (int len = 1; len <= n; len++)
//     {
//         for (int l = 1; l <= 2 * n; l++)
//         {
//             int r = min(2 * n, l + len - 1);
//             for (int k = l; k < r; k++)
//             {
//                 if (dp[l][r])
//                     dp[l][r] = min(dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1], dp[l][r]);
//                 else
//                     dp[l][r] = dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1];

//                 if (mx[l][r])
//                     mx[l][r] = max(mx[l][k] + mx[k + 1][r] + sum[r] - sum[l - 1], mx[l][r]);
//                 else
//                     mx[l][r] = mx[l][k] + mx[k + 1][r] + sum[r] - sum[l - 1];
//             }
//         }
//     }

//     for (int i = 1; i <= n; i++)
//         dp[1][n] = min(dp[1][n], dp[i][i + n - 1]), mx[1][n] = max(mx[1][n], mx[i][i + n - 1]);

//     cout << dp[1][n] << '\n'
//          << mx[1][n];

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 22;
// int n, a[N], b[N], k[N], dp[1 << N], ans;

// int getcnt(int i)
// {
//     int ret = 0;
//     while (i)
//     {
//         ret++;
//         i &= (i - 1);
//     }
//     return ret;
// }

// signed main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         int s, x;
//         cin >> a[i] >> b[i] >> s;
//         while (s--)
//         {
//             cin >> x;
//             k[i] |= (1 << (x - 1));
//         }
//     }

//     for (int i = 0; i < (1 << n); i++)
//         dp[i] = -INT_MAX;
//     dp[0] = 0;

//     for (int i = 1; i < (1 << n); i++)
//     {
//         int cnt = getcnt(i);
//         for (int j = 1; j <= n; j++)
//             if (i & (1 << (j - 1)))
//             {
//                 int pre = i ^ (1 << (j - 1));
//                 if (dp[pre] == -INT_MAX)
//                     continue;
//                 if ((pre & k[j]) == k[j])
//                 {
//                     dp[i] = max(dp[i], dp[pre] + cnt * a[j] + b[j]);
//                     ans = max(dp[i], ans);
//                 }
//             }
//     }

//     cout << ans << '\n';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 10;
// int n, k, dp[N][1 << N][N * N];
// vector<array<int, 2>> line;

// int getcnt(int x)
// {
//     int ret = 0;
//     while (x)
//     {
//         ret++;
//         x &= (x - 1);
//     }
//     return ret;
// }

// bool okLine(int n)
// {
//     return (!(n & (n << 1)));
// }

// bool isOk(int a, int b)
// {
//     return (!(a & b)) && (!((a << 1) & b)) && (!(a & (b << 1)));
// }

// signed main()
// {
//     cin >> n >> k;
//     line.reserve(1 << N);
//     for (int i = 0; i < (1 << n); i++)
//     {
//         int cnt = getcnt(i);
//         if (okLine(i) && cnt <= k)
//             line.push_back({i, cnt});
//     }

//     for (auto [l, s] : line)
//         dp[1][l][s] = 1;

//     for (int i = 2; i <= n; i++)
//         for (auto [l, s] : line)
//             for (auto [lpre, spre] : line)
//                 if (spre + s <= k && isOk(l, lpre))
//                     for (int j = 0; j + s + spre <= k; j++)
//                         dp[i][l][s + spre + j] += dp[i - 1][lpre][spre + j];

//     int ans = 0;
//     for (auto [l, s] : line)
//         ans += dp[n][l][k];
//     cout << ans << '\n';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int inf = 0x3f3f3f3f;
// const int N = 38;
// int n, m, w[N], mult[N], c[N], dis[N][N], dp[N][(1 << (N / 2))], nc, par[N], ans[N];
// vector<int> idx;

// void dfs(int u, int fa, int i)
// {
//     par[u] = fa;
//     if (mult[idx[c[u]]])
//     {
//         if (i & (1 << c[u]))
//         {
//             dp[u][i] = max(dp[fa][i], dp[u][i]);
//             ans[u] = max(dp[u][i], ans[u]);
//         }
//         else
//         {
//             dp[u][i + (1 << c[u])] = max(dp[u][i + (1 << c[u])], dp[fa][i] + w[idx[c[u]]]);
//             ans[u] = max(dp[u][i + (1 << c[u])], ans[u]);
//         }
//     }
//     else
//     {
//         dp[u][i + (1 << c[u])] = max(dp[u][i + (1 << c[u])], dp[fa][i] + w[idx[c[u]]]);
//         ans[u] = max(dp[u][i + (1 << c[u])], ans[u]);
//     }
// }

// signed main()
// {
//     memset(dis, 0x3f, sizeof(dis));
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         dis[i][i] = 0;
//         cin >> c[i];
//         idx.push_back(c[i]);
//     }
//     for (int i = 1; i <= n; i++)
//         cin >> w[i];

//     sort(idx.begin(), idx.end());
//     for (int i = 1; i < n; i++)
//         if (idx[i] == idx[i + 1])
//             mult[idx[i]] = 1;
//     idx.erase(unique(idx.begin(), idx.end()), idx.end());
//     nc = idx.size();

//     for (int i = 1; i <= n; i++)
//         c[i] = lower_bound(idx.begin(), idx.end(), c[i]) - idx.begin();

//     for (int i = 1, u, v; i <= m; i++)
//     {
//         cin >> u >> v;
//         dis[u][v] = dis[v][u] = 1;
//     }

//     for (int i = 1; i <= n; i++)
//         for (int j = 1; i <= n; j++)
//             for (int k = 1; k <= n; k++)
//                 if (dis[i][j] && dis[i][k] && dis[k][j])
//                     dis[i][j] = 0;

//     dfs(1, 0, 0);

//     for (int i = 1; i <= n; i++)
//         cout << ans[i] << '\n';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// double ans, m, n;

// signed main()
// {
//     cin >> m >> n;
//     for (double i = 1; i <= m; i++)
//         ans += i * ((pow(i / m, n) - pow((i - 1) / m, n)));
//     printf("%lf", ans);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 38;
// int n, m, c[N], w[N], dp[N][1 << (N >> 1)], cnt[N], d[N][N], cid[N], ans[N];
// vector<int> idx;
// vector<int> vec[N];

// void dfs(int u, int fa, int i)
// {
//     if (cnt[c[u]] > 1)
//     {
//         if (i & (1 << cid[u]))
//         {
//             dp[u][i] = max(dp[u][i], dp[fa][i]);
//         }
//         else
//         {
//             dp[u][i + (1 << cid[u])] = max(dp[u][i + (1 << cid[u])], dp[fa][i] + w[c[u]]);
//             i = i + (1 << cid[u]);
//         }
//     }
//     else
//     {
//         dp[u][i] = max(dp[u][i], dp[fa][i] + w[c[u]]);
//     }
//     ans[u] = max(ans[u], dp[u][i]);
//     for (auto v : vec[u])
//         if (v > u)
//             dfs(v, u, i);
// }

// signed main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> c[i];
//         cnt[c[i]]++;
//     }
//     for (int i = 1; i <= n; i++)
//         cin >> w[i];

//     for (int i = 1; i <= n; i++)
//         if (cnt[c[i]] > 1)
//             idx.push_back(c[i]);

//     sort(idx.begin(), idx.end());
//     idx.erase(idx.begin(), idx.end());

//     for (int i = 1; i <= n; i++)
//         if (cnt[c[i]] > 1)
//             cid[i] = lower_bound(idx.begin(), idx.end(), c[i]) - idx.begin();

//     for (int i = 1, u, v; i <= m; i++)
//     {
//         cin >> u >> v;
//         d[u][v] = 1;
//     }

//     for (int i = 1; i <= n; i++)
//         for (int j = i + 1; j <= n; j++)
//             for (int k = j + 1; k <= n; k++)
//                 if (d[i][k] && d[i][j] && d[j][k])
//                     d[i][k] = 0;

//     for (int i = 1; i <= n; i++)
//         for (int j = i + 1; j <= n; j++)
//             if (d[i][j])
//                 vec[i].push_back(j);

//     dfs(1, 0, 0);

//     for (int i = 1; i <= n; i++)
//         cout << ans[i] << '\n';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e4 + 10;
// int n, a[N], cnt, cut;
// vector<int> t[N];
// unordered_map<int, int> pos;

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     for (int i = 1, k; i <= n; i++)
//     {
//         cin >> k;
//         t[i].resize(k + 1);
//         for (int j = 1; j <= k; j++)
//             cin >> t[i][j], a[++cnt] = t[i][j];
//     }
//     sort(a + 1, a + 1 + cnt);
//     for (int i = 1; i <= cnt; i++)
//         pos[a[i]] = i;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1, siz = t[i].size(); j < siz - 1; j++)
//             if (t[i][j] > t[i][j + 1] || pos[t[i][j]] + 1 != pos[t[i][j + 1]])
//                 cut++;
//     }

//     cout << cut << ' ' << cut + n - 1;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, m[N], k[N], mxt, mxm[30];
// double mx;
// double val[N];
// vector<int> idx;
// unordered_map<int, int> mp;

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(0);
//     cin.tie(0);
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> m[i] >> k[i];
//         idx.push_back(m[i]);
//     }
//     sort(idx.begin(), idx.end());
//     idx.erase(unique(idx.begin(), idx.end()), idx.end());

//     for (int t = 1; t <= 20; t++)
//     {
//         memset(val, 0, sizeof(val));
//         for (int i = 1; i <= n; i++)
//             val[m[i]] += min(1.0, (double)k[i] / (double)t);
//         vector<pair<double, int>> vec;
//         for (int i = 1; i < N; i++)
//             vec.push_back({val[i], i});

//         sort(vec.begin(), vec.end(), [](pair<double, int> e1, pair<double, int> e2) -> int
//              { return e1.first > e2.first; });
//         double tmp = 0;
//         for (int i = 0; i < t; i++)
//             tmp += vec[i].first;

//         if (mx < tmp)
//         {
//             mx = tmp;
//             mxt = t;
//             for (int i = 0; i < t; i++)
//                 mxm[i] = vec[i].second;
//         }
//     }

//     cout << mxt << '\n';
//     for (int i = 0; i < mxt; i++)
//         cout << mxm[i] << ' ';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n;

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int a, b;
//         cin >> a >> b;
//         if (a > 1)
//             cout << "1\n";
//         else // a = 1
//         {
//             if (b == 2)
//                 cout << "3\n";
//             else
//                 cout << "2\n";
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int a[N];

// bool isprime[N];
// int prime[N]; // 现在已经筛出的素数列表
// int n;        // 上限，即筛出<=n的素数
// int cnt;

// void euler()
// {
//     memset(isprime, true, sizeof(isprime)); // 先全部标记为素数
//     isprime[1] = false;                     // 1不是素数
//     for (int i = 2; i <= n; ++i)            // i从2循环到n（外层循环）
//     {
//         if (isprime[i])
//             prime[++cnt] = i;
//         // 如果i没有被前面的数筛掉，则i是素数
//         for (int j = 1; j <= cnt && i * prime[j] <= n; ++j)

//         {
//             isprime[i * prime[j]] = false;
//             // 倍数标记为合数，也就是i用prime[j]把i * prime[j]筛掉了
//             if (i % prime[j] == 0)
//                 break;
//         }
//     }
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(0);
//     cin.tie(0);
//     n = N;
//     euler();
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         int q = 1, p = n;
//         for (int i = 1; i <= n; i++)
//             if (isprime[i])
//             {
//                 if (i & 1)
//                     a[p--] = i;
//                 else
//                     a[q++] = i;
//             }
//         for (int i = n; i >= 1; i--)
//             if (!isprime[i])
//                 if (i & 1)
//                     a[p--] = i;
//                 else
//                     a[q++] = i;

//         for (int i = 1; i <= n; i++)
//             cout << a[i] << ' ';
//         cout << '\n';
//     }
//     // n = 20;
//     // euler();
//     // for (int i = 1; i <= 20; i++)
//     //     if (isprime[i])
//     //         cout << i << ' ';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int a[N], n, dp[N], last[2];

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//             cin >> a[i], dp[i] = a[i];
//         int ans = a[1];
//         dp[0] = -INT_MAX;
//         last[0] = last[1] = 0;
//         last[1] = max(last[1], a[1]);
//         for (int i = 2; i <= n; i++)
//         {
//             dp[i] = max(dp[i], last[i & 1] + a[i]);
//             last[i & 1] = max(last[i & 1], dp[i]);
//             ans = max(ans, dp[i]);
//         }
//         // for (int i = 1; i <= n; i++)
//         //     cout << dp[i] << ' ';
//         cout << ans << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e6 + 10;
// int n, k;

// void solve()
// {
//     cin >> n;
//     k = n;
//     for (int i = 2; i < n; i++)
//         if (n % i)
//         {
//             k = i;
//             break;
//         }
//     int c = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         cout << (char)('a' + c++);
//         c %= k;
//     }
//     cout << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int a[N], n;

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         int mx = -INT_MAX;
//         for (int i = 1; i <= n; i++)
//             cin >> a[i], mx = max(mx, a[i]);
//         if (mx <= 0)
//         {
//             cout << mx << '\n';
//             continue;
//         }
//         int ans[2] = {0};
//         for (int i = 1; i <= n; i++)
//             ans[i & 1] += max(0ll, a[i]);

//         cout << max(ans[0], ans[1]) << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int a[N], n;

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         string s;
//         cin >> n >> s;
//         s = ' ' + s;
//         int len = 1;
//         cout << "1 ";
//         for (int i = 2; i < n; i++)
//         {
//             if (s[i] == s[i - 1])
//                 len++;
//             else
//                 len = 1;
//             cout << i - len + 1 << ' ';
//         }
//         cout << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, m;
// vector<int> vec[N];
// vector<int> vec2[N];

// void solve()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         vec[i].clear();
//         vec2[i].clear();
//         vec[i].resize(m + 1);
//         vec2[i].resize(m + 1);
//         for (int j = 1; j <= m; j++)
//             cin >> vec[i][j], vec2[i][j] = vec[i][j];
//         sort(vec2[i].begin() + 1, vec2[i].end());
//     }

//     int pos[2];
//     pos[0] = pos[1] = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         int cnt = 0;
//         for (int j = 1; j <= m; j++)
//         {
//             if (vec2[i][j] != vec[i][j])
//                 if (cnt == 2)
//                 {
//                     cout << "-1\n";
//                     return;
//                 }
//                 else
//                     pos[cnt++] = j;
//         }
//         if (cnt == 2)
//         {
//             break;
//         }
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         swap(vec[i][pos[0]], vec[i][pos[1]]);
//         if (!is_sorted(vec[i].begin() + 1, vec[i].end()))
//         {
//             cout << "-1\n";
//             return;
//         }
//     }
//     cout << pos[0] << ' ' << pos[1] << '\n';
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, k, a[N], ans;

// void solve()
// {
//     cin >> n >> k;
//     ans = 0;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     if (k <= n)
//     {
//         int sum = 0, l = 1, r = l + k - 1;
//         for (int i = 1; i <= r; i++)
//             sum += a[i];
//         ans = sum;
//         r++;
//         while (r <= n)
//         {
//             sum += a[r++];
//             sum -= a[l++];
//             ans = max(ans, sum);
//         }
//         ans += k * (k - 1) / 2;
//     }
//     else
//     {
//         for (int i = 1; i <= n; i++)
//             ans += a[i];
//         ans += n * (2 * k - n - 1) / 2;
//     }
//     cout << ans << '\n';
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 5e5 + 10;
// int n, m;

// void solve()
// {
//     cin >> n >> m;
//     vector<int> a(n);
//     for (auto &e : a)
//         cin >> e;
//     auto st(a);
//     sort(st.begin(), st.end());
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//         if (st[i] <= m)
//         {
//             m -= st[i];
//             cnt++;
//         }
//         else
//             break;

//     if (cnt != 0 && cnt < n && m + st[cnt - 1] >= a[cnt])
//         cnt++;

//     cout << n + 1 - cnt << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, m, a[N];

// void solve()
// {
//     cin >> n >> m;
//     int ans = 0;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     if (n == 1)
//     {
//         cout << "0\n";
//         return;
//     }
//     priority_queue<int, vector<int>, less<int>> q;
//     int sum = 0;
//     for (int i = m; i >= 1; i--)
//     {
//         sum += a[i];
//         if (a[i] > 0)
//             q.push(a[i]);
//         if (sum > 0)
//         {
//             ans++;
//             sum -= 2 * q.top();
//             q.pop();
//         }
//     }
//     priority_queue<int, vector<int>, greater<int>> p;
//     sum = 0;
//     for (int i = m + 1; i <= n; i++)
//     {
//         sum += a[i];
//         if (a[i] < 0)
//             p.push(a[i]);
//         if (sum < 0)
//         {
//             ans++;
//             sum -= p.top() * 2;
//             p.pop();
//         }
//     }
//     cout << ans << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define all(a) a.begin(), a.end()
// #define int long long
// const int N = 3e5 + 10;
// int n;

// void solve()
// {
//     cin >> n;
//     vector<int> a(n);
//     for (auto &e : a)
//         cin >> e;

//     auto ans = a;
//     int mx = a[0];
//     for (int i = 1; i < n; i++)
//     {
//         ans[i] += mx - i;
//         mx = max(mx, a[i] + i);
//     }
//     reverse(all(a));
//     mx = a[0];
//     for (int i = 1; i < n; i++)
//     {
//         ans[n - 1 - i] += mx - i;
//         mx = max(mx, a[i] + i);
//     }
//     cout << *max_element(all(ans)) << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 3e6 + 10;
// int n, m;

// void solve()
// {
//     cin >> n;
//     vector<vector<int>> a(N);
//     vector<int> dp(N);
//     for (int i = 1, x, y; i <= n; i++)
//     {
//         cin >> x >> y;
//         x++;
//         y++;
//         a[y].push_back(x);
//     }
//     int ans = 0;
//     for (int i = 1; i < N; i++)
//     {
//         if (a[i].size())
//         {
//             for (auto l : a[i])
//                 dp[i] = max(dp[i], i - l + 1 + dp[l - 1]);
//             dp[i] = max(dp[i], dp[i - 1]);
//         }
//         else
//             dp[i] = dp[i - 1];
//         ans = max(ans, dp[i]);
//     }
//     cout << ans << '\n';
// }

// signed main()
// {
//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, m, a[N];

// void solve()
// {
//     cin >> n >> m;
//     int ans = 0;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     priority_queue<int, vector<int>, less<int>> q;
//     int sum = 0;
//     // if (m > 1)
//     for (int i = m; i >= 2; i--)
//     {
//         sum += a[i];
//         // if (a[i] > 0)
//         q.push(a[i]);
//         if (sum > 0)
//         {
//             ans++;
//             sum -= 2 * q.top();
//             q.pop();
//         }
//     }
//     priority_queue<int, vector<int>, greater<int>> p;
//     sum = 0;
//     for (int i = m + 1; i <= n; i++)
//     {
//         sum += a[i];
//         // if (a[i] < 0)
//         p.push(a[i]);
//         if (sum < 0)
//         {
//             ans++;
//             sum -= p.top() * 2;
//             p.pop();
//         }
//     }
//     cout << ans << '\n';
// }

// signed main()
// {
//     int t = 0;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 5;
// int n;

// void solve()
// {
//     cin >> n;
//     vector<int> a(n + 1);
//     vector<int> last(n + 1, -INT_MAX);
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     vector<int> dp(a);

//     for (int i = 1; i <= n; i++)
//     {
//         dp[i] = max(dp[i - 1], last[a[i]] + i + 1);
//         last[a[i]] = max(last[a[i]], dp[i - 1] - i);
//     }

//     cout << dp[n] << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 5;
// int n;

// void solve()
// {
//     cin >> n;
//     vector<int> a(n + 1);
//     vector<int> last(n + 1, -INT_MAX);
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     vector<int> dp(a);

//     for (int i = 1; i <= n; i++)
//     {
//         dp[i] = max(dp[i - 1], last[a[i]] + i + 1);
//         last[a[i]] = max(last[a[i]], dp[i - 1] - i);
//     }

//     cout << dp[n] << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define all(a) a.begin(), a.end()
// #define int long long
// const int N = 5e5 + 10;
// int n, tr[N << 2];

// void up(int id)
// {
//     tr[id] = max(tr[id << 1], tr[id << 1 | 1]);
// }

// void change(int id, int l, int r, int x, int v)
// {
//     if (l == r)
//     {
//         tr[id] = max(tr[id], v);
//         return;
//     }
//     int mid = l + r >> 1;
//     if (x <= mid)
//         change(id << 1, l, mid, x, v);
//     else
//         change(id << 1 | 1, mid + 1, r, x, v);
//     up(id);
// }

// int query(int id, int l, int r, int ql, int qr)
// {
//     if (ql > qr)
//         return -INT_MAX;
//     if (ql <= l && r <= qr)
//         return tr[id];
//     int mid = l + r >> 1;
//     if (qr <= mid)
//         return query(id << 1, l, mid, ql, qr);
//     else if (ql > mid)
//         return query(id << 1 | 1, mid + 1, r, ql, qr);
//     else
//         return max(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr));
// }

// void build(int id, int l, int r)
// {
//     if (l == r)
//     {
//         tr[id] = -INT_MAX;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(id << 1, l, mid);
//     build(id << 1 | 1, mid + 1, r);
//     up(id);
// }

// void init()
// {
//     build(1, 1, n);
// }

// void solve()
// {
//     cin >> n;
//     // init();
//     vector<int> a(n + 1);
//     vector<int> pre(n + 1);
//     vector<int> vs;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         pre[i] = pre[i - 1] + a[i];
//         vs.push_back(pre[i]);
//     }
//     vs.push_back(0);

//     sort(all(vs));
//     vs.erase(unique(all(vs)), vs.end());
//     int siz = vs.size();
//     build(1, 1, siz);
//     vector<int> pre_idx(pre);
//     for (int i = 1; i <= n; i++)
//         pre_idx[i] = lower_bound(all(vs), pre[i]) - vs.begin() + 1;

//     vector<int> f(n + 1);
//     change(1, 1, siz, lower_bound(all(vs), 0) - vs.begin() + 1, 0);
//     for (int i = 1; i <= n; i++)
//     {
//         int tmp = query(1, 1, siz, 1, pre_idx[i] - 1);
//         // cout << tmp << '\n';
//         f[i] = max(f[i - 1] - 1, i + tmp);
//         if (a[i] == 0)
//             f[i] = max(f[i], f[i - 1]);
//         change(1, 1, siz, pre_idx[i], f[i] - i);
//     }

//     cout << f[n] << "\n";
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define all(a) a.begin(), a.end()
// #define int long long
// const int N = 5e5 + 10;
// int n, tr[N];

// int lowbit(int x)
// {
//     return x & -x;
// }

// void change(int x, int v)
// {
//     while (x < N)
//     {
//         if (v > tr[x])
//             tr[x] = v;
//         else
//             return;
//         x += lowbit(x);
//     }
// }

// int query(int x)
// {
//     int ret = -INT_MAX;
//     while (x)
//     {
//         ret = max(ret, tr[x]);
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void solve()
// {
//     cin >> n;
//     // init();
//     vector<int> a(n + 1);
//     vector<int> pre(n + 1);
//     vector<int> vs;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         pre[i] = pre[i - 1] + a[i];
//         vs.push_back(pre[i]);
//     }
//     vs.push_back(0);

//     sort(all(vs));
//     vs.erase(unique(all(vs)), vs.end());
//     int siz = vs.size();
//     for (int i = 0; i <= siz; i++)
//         tr[i] = -INT_MAX;
//     vector<int> pre_idx(pre);
//     for (int i = 1; i <= n; i++)
//         pre_idx[i] = lower_bound(all(vs), pre[i]) - vs.begin() + 1;

//     vector<int> f(n + 1);
//     change(lower_bound(all(vs), 0) - vs.begin() + 1, 0);
//     for (int i = 1; i <= n; i++)
//     {
//         int tmp = query(pre_idx[i] - 1);
//         f[i] = max(f[i - 1] - 1, i + tmp);
//         if (a[i] == 0)
//             f[i] = max(f[i], f[i - 1]);
//         change(pre_idx[i], f[i] - i);
//     }

//     cout << f[n] << "\n";
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 3e5 + 10;
// int n;

// int getans(vector<int> a, int mx)
// {
//     int ans = 0, sum = 0, cnt = 0;
//     for (auto &e : a)
//     {
//         e = mx - e;
//         if (e & 1)
//         {
//             e--;
//             cnt++;
//         }
//         sum += e;
//     }
//     if (sum <= (cnt - 1) * 2)
//     {
//         return (cnt * 2) - 1;
//     }
//     sum -= cnt * 2;
//     ans += cnt * 2;
//     ans += (sum / 3) * 2;
//     if (sum % 3 == 0)
//     {
//     }
//     else if (sum % 3 == 1)
//     {
//         ans++;
//     }
//     else
//     {
//         ans += 2;
//     }
//     return ans;
// }

// void solve()
// {
//     cin >> n;
//     int cnt = 0, sum = 0, ans = 0, mx = 0;
//     vector<int> a(n);
//     for (auto &e : a)
//     {
//         cin >> e;
//         mx = max(e, mx);
//     }
//     ans = min(getans(a, mx + 1), getans(a, mx));

//     cout << ans << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// signed main()
// {
//     int n;
//     while (cin >> n)
//     {
//         if (n % 3)
//             cout << "Kiki\n";
//         else
//             cout << "Cici\n";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define all(a) a.begin() + 1, a.end()
// const int N = 2e5 + 10;

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<array<int, 2>> a(n + 1);
//     for (int i = 1; i <= n; i++)
//         cin >> a[i][0], a[i][1] = i;

//     sort(all(a));

//     vector<array<int, 2>> ans;

//     int l = 1;
//     while (1)
//     {
//         if (!a[n - 1][0])
//             break;
//         while (a[l][0] == 0)
//             l++;
//         a[l][0]--;
//         a[n][0]--;
//         ans.push_back({a[l][1], a[n][1]});
//         if (a[n][0] < a[n - 1][0])
//         {
//             int ql = l, qr = n - 1;
//             while (ql <= qr)
//             {
//                 int mid = ql + qr >> 1;
//                 if (a[mid][0] < a[n - 1][0])
//                     ql = mid + 1;
//                 else
//                     qr = mid - 1;
//             }
//             if (a[qr][0] != a[n - 1][0])
//                 qr++;
//             swap(a[n], a[qr]);
//         }
//     }

//     cout << ans.size() << '\n';
//     for (auto e : ans)
//         cout << e[0] << ' ' << e[1] << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> w(n);
//     vector<int> b(n);
//     for (auto &e : w)
//         cin >> e;
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> b[i];
//         b[i] -= w[i] + 1;
//         sum ^= b[i];
//     }

//     if (sum)
//         cout << "white wins\n";
//     else
//         cout << "black wins\n";
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     for (int i = 1; i <= t; i++)
//     {
//         cout << "Case " << i << ": ";
//         solve();
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int a[110];

// signed main()
// {
//     int n;
//     while (scanf("%d", &n), n)
//     {
//         int xo = 0;
//         for (int i = 0; i < n; i++)
//             scanf("%d", &a[i]), xo ^= a[i];
//         int ans = 0;
//         for (int i = 0; i < n; i++)
//             if ((a[i] ^ xo) < a[i])
//                 ans++;
//         printf("%d\n", ans);
//     }
//     return 0;
// }

// #include <iostream>
// #include <cmath>
// using namespace std;

// signed main()
// {
//     int x, y;
//     double k = (sqrt(5.0) + 1) / 2;
//     while (scanf("%d %d", &x, &y), x && y)
//     {
//         if (x == (int)(k * (y - x)))
//         {
//             printf("0\n");
//         }
//         else
//         {
//             printf("1\n");
//             int a = k * (y - x);
//             int b = a + (y - x);
//             if (x - a == y - b)
//                 printf("%d %d\n", a, b);
//             a = x;
//             b = a * (k + 1.0) / k;
//             if (b < y && a == (int)(k * (b - a)))
//             {
//                 printf("%d %d\n", a, b);
//                 continue;
//             }
//             b = x;
//             a = (b * k) / (k + 1.0);
//             if (a < x && a == (int)(k * (b - a)))
//             {
//                 printf("%d %d\n", a, b);
//                 continue;
//             }

//             b = y;
//             a = (b * k) / (k + 1.0);
//             if (a < x && a == (int)(k * (b - a)))
//             {
//                 printf("%d %d\n", a, b);
//                 continue;
//             }
//         }
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// #define int long long
// const int N = 1010;
// int sg[N];
// vector<int> op;

// void getsg()
// {
//     op.push_back(1);
//     for (int i = 2; i < N; i *= 2)
//         op.push_back(i);

//     for (int i = 1; i < N; i++)
//     {
//         vector<bool> ne(N, false);
//         for (auto p : op)
//         {
//             if (p > i)
//                 break;
//             ne[sg[i - p]] = true;
//         }
//         for (int j = 0; j < N; j++)
//             if (!ne[j])
//             {
//                 sg[i] = j;
//                 break;
//             }
//     }
// }

// signed main()
// {
//     getsg();
//     int n;
//     while (cin >> n)
//         // for (int i = 0; i <= n; i++)
//         // cout << i << ' ' << sg[i] << '\n';
//         cout << (sg[n] ? "Kiki\n" : "Cici\n");
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// #define int long long
// const int N = 3e5 + 10;
// int n, p, a[N], sg[N];

// void getsg()
// {
//     vector<int> op;
//     if (p == 1)
//         op.push_back(1);
//     else
//         for (int i = 1; i <= 110; i *= p)
//         {
//             op.push_back(i);
//             // cout << i << " ";
//         }
//     for (int i = 1; i <= 100; i++)
//     {
//         vector<bool> st(n + 1, false);

//         for (auto pp : op)
//             if (pp <= i)
//                 st[sg[i - pp]] = true;
//             else
//                 break;
//         for (int j = 0; j <= n; j++)
//             if (!st[j])
//             {
//                 sg[i] = j;
//                 break;
//             }
//     }
// }

// signed main()
// {
//     ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//     cin >> n >> p;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     if (p & 1)
//     {
//         int xo = 0;
//         for (int i = 1; i <= n; i++)
//             if (a[i] & 1)
//                 xo ^= 1;
//         cout << (xo ? "GOOD" : "BAD");
//     }
//     else
//     {

//         int xo = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             int mod = a[i] % (p + 1);
//             if (mod == p)
//                 xo ^= 2;
//             else if (mod & 1)
//                 xo ^= 1;
//         }
//         cout << (xo ? "GOOD" : "BAD");
//     }

//     // getsg();
//     // int xo = 0;
//     // for (int i = 0; i <= n; i++)
//     //     cout << i << ' ' << sg[i] << '\n';
//     // xo ^= sg[i];
//     // cout << (xo ? "GOOD" : "BAD");

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// signed main()
// {
//     long long  L, R;
//     long long ans1 = 0, ans2 = 0;
//     // scanf("%d", &n);
//     long long  x, y;
//     cin >> x >> y;
//     x--;
//     for (L = 1; L <= y; L = R + 1)
//     {
//         R = y / (y / L);
//         ans2 += (y / L) * ((L + R) * (R - L + 1) / 2);
//         // cout << L << '~' << R << ':' << y / L << '\n';
//     }
//     for (L = 1; L <= x; L = R + 1)
//     {
//         R = x / (x / L);
//         ans1 += (x / L) * ((L + R) * (R - L + 1) / 2);
//         // cout << L << '~' << R << ':' << y / L << '\n';
//     }
//     printf("%lld\n", ans2 - ans1);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int n, k;

// signed main()
// {
//     cin >> n >> k;
// int L = 1, R, mn = min(n, k), ans = 0, len, S;
// for (L = 1; L <= mn; L = R + 1)
// {
//     // if (L > k)
//     //     R = n;
//     // else
//     R = min(mn, k / (k / L));
//     len = R - L + 1;
//     S = k / L;
//     ans += k * len - len * S * (L + R) / 2;
// }
//     if (n > k)
//         ans += (n - k) * k;
//     cout << ans;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int n, m;

// void solve()
// {
//     cin >> n >> m;
//     if (m <= n)
//     {
//         cout << n - m << '\n';
//         return;
//     }

//     int L = 1, R, ans = INT_MAX, len, S;
//     for (L = 1; L <= n; L = R + 1)
//     {
//         R = min(n, m / (m / L));
//         len = R - L + 1;
//         S = m / L;
//         ans = min({ans, (n - R) + ((m % R) ? (S + 1) * R - m : 0), (n - L) + (L - (m % L))});
//     }
//     cout << ans << '\n';
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <iostream>
// // #include <algorithm>
// using namespace std;
// #define int long long
// const int N = 2e5;
// int n, k, a[N], ans = 0;

// int gcd(int a, int b)
// {
//     return b ? gcd(b, a % b) : a;
// }

// int lcm(int a, int b)
// {
//     return a * b / gcd(a, b);
// }

// signed main()
// {
//     scanf("%lld %lld", &n, &k);
//     for (int i = 1; i <= n; i++)
//         scanf("%lld", &a[i]);

//     for (int i = 1, mx = (1 << k); i < mx; i++)
//     {
//         int cnt = 0;
//         int t = 1;
//         for (int j = 1; j <= k; j++)
//             if (i & (1 << (j - 1)))
//             {
//                 cnt++;
//                 t = lcm(t, a[j]);
//             }
//         t = n / t;
//         if (1 & cnt)
//             ans += t;
//         else
//             ans -= t;
//     }
//     printf("%lld", n - ans);
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 20;
// int n, k, a[N];

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> k;
//     for (int i = 1; i <= k; i++)
//         cin >> a[i];

//     int ans = 0;
//     for (int i = 1; i < (1 << k); i++)
//     {
//         int cnt = 0;
//         int t = 1;
//         for (int j = 1; j <= k; j++)
//             if (i & (1 << (j - 1)))
//             {
//                 cnt++;
//                 t = (t * a[j]) / __gcd(t, a[j]);

//             }
//         t = n / t;
//         if (cnt & 1)
//             ans += t;
//         else
//             ans -= t;
//     }
//     cout << n - ans;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 22;
// int m, n, k, sum, C[404][404];
// const int mod = 1000007;

// void init()
// {
//     for (int i = 1; i <= 400; i++)
//     {
//         C[i][0] = C[i][i] = 1;
//         for (int j = 1; j < i; j++)
//             C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
//     }
// }

// void solve()
// {
//     cin >> m >> n >> k;
//     sum = m * n;
//     int all = C[sum][k];
// }

// signed main()
// {
//     init();
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 110;
// int n, p, q, D[N];

// void solve()
// {
//     cin >> n >> p >> q;
//     int mn = INT_MAX;
//     for (int i = 1; i <= n; i++)
//         cin >> D[i], mn = min(mn, D[i]);
//     if (mn + q < p)
//         cout << mn + q;
//     else
//         cout << p;
// }

// signed main()
// {

//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// const int N = 110;
// int n, m;

// struct node
// {
//     int pric;
//     int siz;
//     bool func[N];
// } p[N];

// void solve()
// {
//     cin >> n >> m;
//     for (int i = 1, c; i <= n; i++)
//     {
//         cin >> p[i].pric >> p[i].siz;
//         for (int j = 0, tmp; j < p[i].siz; j++)
//             cin >> tmp, p[i].func[tmp] = 1;
//     }
//     sort(p + 1, p + 1 + n, [](node e1, node e2) -> int
//          { return e1.pric < e2.pric; });

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = i + 1; j <= n; j++)
//         {
//             bool isok = true;
//             if (p[i].pric == p[j].pric) // 价格相同
//             {
//                 bool mor = false;
//                 for (int f = 1; f <= m; f++)
//                 {
//                     if (p[j].func[f] && (!p[i].func[f]))
//                     {
//                         isok = false;
//                         break;
//                     }
//                     if (p[i].func[f])
//                         if (!p[j].func[f])
//                             mor = true;
//                 }
//                 // cout << p[i].func[1] << ' ' << p[i].func[2] << ' ' << p[j].func[1] << ' ' << p[j].func[2];
//                 if (isok)
//                     isok = mor;
//             }
//             else // 价格不同
//             {
//                 for (int f = 1; f <= m; f++)
//                 {
//                     if (p[j].func[f] && (!p[i].func[f]))
//                     {
//                         isok = false;
//                         break;
//                     }
//                 }
//             }
//             if (isok)
//             {
//                 cout << "Yes";
//                 return;
//             }
//         }
//     }
//     cout << "No";
// }

// signed main()
// {

//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// const int N = 2e5;
// int n, m;
// unordered_map<string, bool> mp;

// void solve()
// {
//     cin >> n;
//     string s;
//     int cnt = 0;
//     while (n--)
//     {
//         cin >> s;
//         if (mp[s])
//             continue;
//         reverse(s.begin(), s.end());
//         if (mp[s])
//             continue;
//         mp[s] = true;
//         ++cnt;
//     }
//     cout << cnt;
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// const int N = 12;
// int n, m, t, no[N][N], ans, te[N][N];

// void dfs(int team, int all)
// {
//     if()
// }

// void solve()
// {
//     cin >> n >> t >> m;
//     while (m--)
//     {
//         int a, b;
//         cin >> a >> b;
//         no[a][b] = 1;
//         no[b][a] = 1;
//     }
//     dfs(1, 0);
//     cout << ans;
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e6 + 10;
// int n;
// string s;

// void solve()
// {
//     cin >> n >> s;
//     int ans = 0;
//     int last = 0;
//     if (s[0] == '1')
//         ans++, last = 1;
//     for (int i = 1; i < n; i++)
//     {
//         if (s[i] == '0')
//         {
//             ans += i;
//             last = i;
//         }
//         else
//         {
//             int tmp = ans;
//             ans++;
//             ans += i - last;
//             // if (s[i - 1] == '0')
//             //     ans++;
//             last = ans - tmp;
//         }
//         // cout << ans << ' ';
//     }
//     cout << ans;
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 22;
// int m, n, k, sum, C[404][404];
// const int mod = 1000007;

// void init()
// {
//     for (int i = 1; i <= 400; i++)
//     {
//         C[i][0] = C[i][i] = 1;
//         for (int j = 1; j < i; j++)
//             C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
//     }
// }

// void solve()
// {
//     cin >> m >> n >> k;
//     sum = m * n;
//     int all = C[sum][k];
//     all = (all - 2 * C[(m - 1) * n][k] - 2 * C[(n - 1) * m][k] + 4 * mod) % mod;
//     all = (all + C[(m - 2) * n][k] + C[(n - 2) * m][k] + C[(n - 1) * (m - 1)][k] * 4 + 6 * mod) % mod;
//     all = (all - 2 * C[(m - 1) * (n - 2)][k] - C[(m - 2) * (n - 1)][k] * 2 + 4 * mod) % mod;
//     all = (all + C[(n - 2) * (m - 2)][k] + mod) % mod;
//     // all = (all - 2 * C[sum - m][k] - 2 * C[sum - n][k]) % mod;
//     // all = (all + C[sum - 2 * n][k] + C[sum - 2 * m][k] + C[sum - m - n + 1][k] * 4) % mod;
//     // all = (all - 2 * C[sum - 2 * n - m + 2][k] - C[sum - 2 * m - n + 2][k] * 2) % mod;
//     // all = (all + C[(n - 2) * (m - 2)][k]) % mod;
//     cout << all << '\n';
// }

// signed main()
// {
//     init();
//     int t;
//     cin >> t;
//     for (int i = 1; i <= t; i++)
//     {
//         cout << "Case " << i << ": ";
//         solve();
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, m, k;

// void solve()
// {
//     int x, y;
//     cin >> n >> m >> k >> x >> y;
//     int f = 0;
//     for (int i = 1, u, v; i <= k; i++)
//     {
//         cin >> u >> v;
//         if ((abs(u - x) + abs(v - y)) % 2 == 0)
//             f = 1;
//         // cout << (abs(u - x) + abs(v - y)) << '\n';
//     }
//     if (f)
//         cout << "NO\n";
//     else
//         cout << "YES\n";
// }

// signed main()
// {
//     int t = 1;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int k, n, c[N], mx[N], last[N], sd[N];

// void pt()
// {
//     for (int i = 1; i <= k; i++)
//         cout << mx[i] << ' ';
//     cout << '\n';
//     for (int i = 1; i <= k; i++)
//         cout << sd[i] << ' ';
//     cout << '\n';
// }

// void solve()
// {
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//         cin >> c[i];

//     int ans = INT_MAX;
//     for (int i = 1; i <= n; i++)
//     {
//         if (i - last[c[i]] - 1 > mx[c[i]])
//         {
//             sd[c[i]] = mx[c[i]];
//             mx[c[i]] = i - last[c[i]] - 1;
//         }
//         else
//             sd[c[i]] = max(sd[c[i]], i - last[c[i]] - 1);
//         last[c[i]] = i;
//     }
//     for (int i = 1; i <= k; i++)
//         if (n - last[i] > mx[i])
//         {
//             sd[i] = mx[i];
//             mx[i] = n - last[i];
//         }
//         else
//             sd[i] = max(sd[i], n - last[i]);
//     // pt();
//     for (int i = 1; i <= k; i++)
//         mx[i] = max(sd[i], mx[i] / 2);

//     for (int i = 1; i <= k; i++)
//         ans = min(ans, mx[i]);

//     cout << ans << '\n';
//     for (int i = 1; i <= k; i++)
//         mx[i] = last[i] = sd[i] = 0;
// }

// signed main()
// {
//     int t = 1;
//     cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }