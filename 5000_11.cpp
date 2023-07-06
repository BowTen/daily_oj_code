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