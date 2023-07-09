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

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lson id << 1
#define rson id << 1 | 1
const int N = 2e5 + 10;
int n, m, a[N];

struct info
{
    int ans;
    int len;
    int pre_len;
    int suf_len;
    int front;
    int back;
};
struct node
{
    info val;
} tr[N << 2];

info operator+(const info &a, const info &b)
{
    info c;
    c.ans = a.ans + b.ans;
    c.len = a.len + b.len;
    c.front = a.front;
    c.back = b.back;
    c.pre_len = a.pre_len;
    c.suf_len = b.suf_len;
    if (a.back <= b.front)
    {
        c.ans -= (a.suf_len * (a.suf_len + 1)) / 2 + (b.pre_len * (b.pre_len + 1)) / 2;
        int tmp = a.suf_len + b.pre_len;
        c.ans += tmp * (tmp + 1) / 2;
        if (a.len == a.pre_len)
            c.pre_len = a.len + b.pre_len;
        if (b.len == b.pre_len)
            c.suf_len = a.suf_len + b.suf_len;
    }
    return c;
}

void up(int id)
{
    tr[id].val = tr[lson].val + tr[rson].val;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        tr[id].val.ans = tr[id].val.len = tr[id].val.pre_len = tr[id].val.suf_len = 1;
        tr[id].val.back = tr[id].val.front;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(id);
}

void change(int id, int l, int r, int x, int v)
{
    if (l == r)
    {
        a[l] = v;
        tr[id].val.front = tr[id].val.back = v;
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        change(lson, l, mid, x, v);
    else
        change(rson, mid + 1, r, x, v);
}

info query(int id, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return tr[id].val;
    int mid = l + r >> 1;
    if (qr <= mid)
        return query(lson, l, mid, ql, qr);
    else if (ql > mid)
        return query(rson, mid + 1, r, ql, qr);
    else
        return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (m--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            change(1, 1, n, l, r);
        }
        else
        {
            cout << query(1, 1, n, l, r).ans << '\n';
        }
    }

    return 0;
}