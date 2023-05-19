// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     cout << "再写 5000 行就入门了，嘿嘿 >_< ^_^ ^^ !";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 5;
// int n, m;
// struct node
// {
//     int x, y, p, q;
// };
// node d[N];

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         // vector<vector<node>> vec(2 * n);
//         unordered_map<int, vector<node>> vec;
//         for (int i = 1, x, y, p, q; i <= n; i++)
//         {
//             cin >> d[i].x >> d[i].y >> d[i].p >> d[i].q;
//             // cin >> x >> y >> p >> q;
//             // vec[x + y].push_back({x, y, p, q});
//         }
//         sort(d + 1, d + 1 + n, [](node e1, node e2) -> int
//              { return e1.x < e2.x; });
//         for (int i = 1; i <= n; i++)
//         {
//             // cout << d[i].x << ' ' << d[i].p << '\n';
//             vec[d[i].x + d[i].y].push_back(d[i]);
//         }
//         int ans = 0, f = 0;
//         vector<int> line(n + 3);
//         for (auto &[id, vc] : vec)
//         {
//             // cout << vc[0].x << ' ' << vc[0].p << '\n';
//             int mx = vc[0].p;
//             ans += vc.front().p - vc.front().x;
//             for (int i = 1, len = vc.size(); i < len; i++)
//             {
//                 if (vc[i].x < mx)
//                 {
//                     if (!f)
//                         f = 1;
//                     if (vc[i].p <= mx)
//                         continue;
//                     else
//                     {
//                         ans += vc[i].p - mx;
//                         mx = vc[i].p;
//                     }
//                 }
//                 else
//                 {
//                     ans += vc[i].p - vc[i].x;
//                     mx = vc[i].p;
//                 }
//             }
//             // cout << ans << '\n';
//         }
//         if (f)
//             cout << "NO\n";
//         else
//             cout << "YES\n";
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
// const int N = 1e5 + 5;
// int n, k;
// pair<int, int> pi[N];

// signed main()
// {
//     IO;
//     cin >> n >> k;
//     map<int, stack<int>> mp;
//     for (int i = 1, a, b; i <= n; i++)
//     {
//         cin >> pi[i].first >> pi[i].second;
//     }
//     sort(pi + 1, pi + 1 + n, [](pair<int, int> e1, pair<int, int> e2) -> int
//          { return e1.second < e2.second; });
//     for (int i = 1; i <= n; i++)
//     {
//         // cout << pi[i].second << '\n';
//         mp[pi[i].first].push(pi[i].second);
//     }
//     cout << mp.size() << '\n';
//     map<int, int> ans;
//     while (mp.size() > 1)
//     {
//         auto p = mp.begin();
//         while (p != mp.end())
//         {
//             ans[p->first] += p->second.top() + (p->second.top() / k) * k;
//             if (p->second.top() % k == 0)
//                 ans[p->first] -= k;
//             p->second.pop();
//             if (p->second.empty())
//                 mp.erase(p++);
//             else
//                 p++;
//         }
//     }
//     if (mp.size())
//     {
//         int sum = 0;
//         while (mp.begin()->second.size())
//         {
//             sum += mp.begin()->second.top();
//             mp.begin()->second.pop();
//         }
//         ans[mp.begin()->first] += sum + (sum / k) * k;
//         if (sum % k == 0)
//             ans[mp.begin()->first] -= k;
//     }
//     for (auto &[id, as] : ans)
//     {
//         cout << id << ' ' << as << '\n';
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
// const int N = 1e5 + 5;
// int n, p[N], vis[N];
// vector<int> vec[N];

// signed main()
// {
//     IO;
//     cin >> n;
//     for (int i = 1, a, b; i < n; i++)
//     {
//         cin >> a >> b;
//         vec[a].push_back(b);
//         vec[b].push_back(a);
//     }
//     queue<int> que;
//     vis[n] = 1;
//     que.push(n);
//     while (que.size())
//     {
//         int u = que.front();
//         que.pop();
//         for (auto &v : vec[u])
//             if (!vis[v])
//             {
//                 p[v] = u;
//                 que.push(v);
//                 vis[v] = 1;
//             }
//     }
//     for (int i = 1; i < n; i++)
//         cout << p[i] << ' ';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 1e5 + 5;
// int n;

// signed main()
// {
//     IO;
//     int mx = 0, mn = 0, mx2;
//     cin >> n >> mn >> mx;
//     mx2 = mx;
//     for (int i = 1, l, r; i < n; i++)
//     {
//         cin >> l >> r;
//         if (l > 1 && (l < mn || mn == 1))
//             mn = l;
//         mx = max(mx, r);
//         mx2 = min(mx2, r);
//     }
//     cout << 1 << ' ' << 2 * n - 1;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 1e5 + 5;
// int n, a[N], pre[N], ex = 1, pay = 0;

// signed main()
// {
//     IO;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         pre[i] = pre[i - 1] + a[i];
//         // cout << pre[i] << '\n';
//     }
//     for (int i = 0; i <= n; i++)
//     {
//         ex += a[i];
//         // cout << i << ' ' << ex << ' ';
//         if (ex < a[i + 1])
//         {
//             pay += (a[i + 1] - ex) / (1 + pre[i]);
//             ex += ((a[i + 1] - ex) / (1 + pre[i])) * (1 + pre[i]);
//         }
//         if (ex < a[i + 1])
//         {
//             ex += (1 + pre[i]);
//             pay++;
//         }
//         // cout << pay << '\n';
//     }
//     cout << pay;
//     return 0;2
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// const int N = 1e5 + 5;
// int n, q, k, d[N], die[N], ad;

// int lowbit(int x)
// {
//     return x & -x;
// }

// int getsum(int x)
// {
//     x++;
//     int ret = 0;
//     while (x)
//     {
//         ret += d[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void add(int x, int v)
// {
//     x++;
//     while (x <= n + 1)
//     {
//         d[x] += v;
//         x += lowbit(x);
//     }
// }

// signed main()
// {
//     IO;
//     cin >> n >> q;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//         a[i] = i + 1;
//     int cur = 0, t;
//     while (q--)
//     {
//         cin >> k;
//         int ne = (cur + k - 1);
//         int rou = (ne - cur) / n;
//         int mor = ad * rou;
//         if ((ne % n) < cur)
//             mor += getsum(ne % n);
//         else
//             mor += getsum(ne % n) - getsum(cur);
//         k = mor;
//         cur = ne % n;
//         while (k)
//         {
//             ne = (cur + k);
//             rou = (ne - cur) / n;
//             mor = ad * rou;
//             if ((ne % n) < cur)
//                 mor += getsum(ne % n);
//             else
//                 mor += getsum(ne % n) - getsum(cur);
//             k = mor;
//             cur = ne % n;
//         }
//         cout << a[cur] << '\n';
//         ad++;
//         add(cur++, 1);
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int n, m, a[N];
// struct node
// {
//     int l, r, right, tag;
// };
// node d[N << 2];

// void settag(int id, int v)
// {
//     d[id].tag = max(d[id].tag, v);
//     if (d[id].l == d[id].r)
//     {
//         d[id].right = max(d[id].right, d[id].tag);
//         d[id].tag = 0;
//     }
// }

// void down(int id)
// {
//     if (!d[id].tag)
//         return;
//     settag(id << 1, d[id].tag);
//     settag(id << 1 | 1, d[id].tag);
// }

// void build(int id, int ql, int qr)
// {
//     d[id].l = ql;
//     d[id].r = qr;
//     if (ql == qr)
//         return;
//     int mid = ql + qr >> 1;
//     build(id << 1, ql, mid);
//     build(id << 1 | 1, mid + 1, qr);
// }

// void modify(int id, int ql, int qr, int v)
// {
//     int l = d[id].l;
//     int r = d[id].r;
//     if (l > qr || r < ql)
//         return;
//     if (l >= ql && r <= qr)
//         settag(id, v);
//     else
//     {
//         down(id);
//         int mid = ql + qr >> 1;
//         if (r <= mid)
//             modify(id << 1, ql, qr, v);
//         else if (l > mid)
//             modify(id << 1 | 1, ql, qr, v);
//         else
//         {
//             modify(id << 1, ql, qr, v);
//             modify(id << 1 | 1, ql, qr, v);
//         }
//     }
// }

// int getr(int id, int x)
// {
//     int l = d[id].l;
//     int r = d[id].r;
//     if (l == r && l == x)
//         return d[id].right;
//     int mid = l + r >> 1;
//     down(id);
//     if (x <= mid)
//         return getr(id << 1, x);
//     return getr(id << 1 | 1, x);
// }

// int main()
// {

//     cin >> n >> m;
//     build(1, 1, n);
//     while (m--)
//     {
//         int t, l, r, k;
//         cin >> t;
//         if (t == 1)
//         {
//             cin >> l >> r >> t;
//             modify(1, l, r, r);
//         }
//         else
//         {
//             cin >> k;
//             for (int i = 1; i <= k; i++)
//                 cin >> a[i];
//             int mx = getr(1, a[1]);
//             int ans = 1;
//             for (int i = 1; i <= k; i++)
//             {
//                 if (a[i] <= mx)
//                     continue;
//                 mx = getr(1, a[i]);
//                 if (mx < a[i])
//                 {
//                     cout << "-1\n";
//                     goto ss;
//                 }
//                 ans++;
//             }
//             cout << ans << '\n';
//         }

//     ss:;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int n, m, rgt[N], a[N];

// int lowbit(int x)
// {
//     return x & -x;
// }

// void change(int x, int v)
// {
//     while (x <= n)
//     {
//         rgt[x] = max(rgt[x], v);
//         x += lowbit(x);
//     }
// }

// int query(int r)
// {
//     int ret = 0;
//     while (r)
//     {
//         ret = max(rgt[r], ret);
//         r -= lowbit(r);
//     }
//     return ret;
// }

// int main()
// {

//     cin >> n >> m;
//     while (m--)
//     {
//         int t, l, r, w, k;
//         cin >> t;
//         if (t == 1)
//         {
//             cin >> l >> r >> w;
//             change(l, r);
//         }
//         else
//         {
//             cin >> k;
//             for (int i = 1; i <= k; i++)
//                 cin >> a[i];
//             int mx = query(a[1]);
//             int ans = 1;
//             for (int i = 1; i <= k; i++)
//             {
//                 if (mx >= a[i])
//                     continue;
//                 mx = query(a[i]);
//                 if (mx < a[i])
//                 {
//                     cout << "-1\n";
//                     goto ss;
//                 }
//                 ans++;
//             }
//             cout << ans << '\n';
//         }
//     ss:;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class ot
// {
// private:
//     static int st;

// public:
//     int a = 1;
//     class inn
//     {
//     public:
//         int b = 2;
//         void ptst()
//         {
//             cout << st;
//         }
//     };
// };

// int ot::st = 6;

// int main()
// {
//     ot::inn().ptst();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 5e5 + 10;
// int n, q, d[N], k, liv;

// int lowbit(int x)
// {
//     return x & -x;
// }

// void add(int x, int v)
// {
//     while (x <= n)
//     {
//         d[x] += v;
//         x += lowbit(x);
//     }
// }

// int getsum(int x)
// {
//     int ret = 0;
//     while (x)
//     {
//         ret += d[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// int main()
// {
//     cin >> n >> q;
//     liv = n;
//     for (int i = 1; i <= n; i++)
//         add(i, 1);
//     int id = 1;
//     while (q--)
//     {
//         cin >> k;
//         id = (id + k - 1) % liv;
//         if (!id)
//             id = liv;
//         int l = 1, r = n, mid;
//         while (l <= r)
//         {
//             mid = l + r >> 1;
//             if (getsum(mid) < id)
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//         }
//         cout << l << '\n';
//         add(l, -1);

//         liv--;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define int long long
// typedef long long ll;
// typedef unsigned long long ull;
// const ll N = 5e6 + 7;
// constexpr ll mod = 1e9 + 7;
// const ll inf = 0x3f3f3f3f;
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// ll qkpow(ll a, ll p)
// {
//     ll t = 1, tt = a;
//     while (p)
//     {
//         if (p & 1)
//             t = t * tt;
//         tt = tt * tt;
//         p >>= 1;
//     }
//     return t;
// }

// signed main()
// {
//     IOS;
//     int n, num = 0, sum0 = 0, sum = 0, bi = 1;
//     cin >> n;
//     while (n > 0)
//     {
//         if (n % 2 == 1)
//         {
//             sum0 += sum + 1 + num * 0.5 * qkpow(2, num);
//             sum += bi;
//         }
//         bi *= 2;
//         num++;
//         n /= 2;
//     }
//     cout << sum0;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define int long long
// const int N = 1e5 + 5;
// int n, a;

// signed main()
// {
//     IO;
//     a = 0;
//     cin >> n;
//     a = n / 2;
//     if (n & 1)
//         a++;
//     int pw = 4;
//     while (pw / 2 <= n)
//     {
//         a += ((n + 1) / pw) * (pw / 2) + max(((n + 1) % pw) - (pw / 2), (int)0);
//         pw *= 2;
//     }

//     cout << a;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 5;
// int n, a[N], b[N];

// signed main()
// {
//     cin >> n;

//     for (int i = 1; i <= n; i++)
//         cin >> a[i];

//     int ans = 0;
//     for (int j = 2; j < n; j++)
//     {
//         for (int i = 1; i <= n; i++)
//             b[i] = a[i];
//         sort(b + 1, b + j);
//         sort(b + 1 + j, b + n);
//         for (int i = 1; i < j; i++)
//         {
//             int l = j + 1, r = n, mid;
//             while (l <= r)
//             {
//                 mid = l + r >> 1;
//                 if (b[mid] + b[i] > b[j])
//                     r = mid - 1;
//                 else
//                     l = mid + 1;
//             }
//             ans += r - j;
//         }
//     }

//     cout << ans;

//     return 0;
// }

// #include <bits/stdc++.h>
// #define int long long
// #define IO                       \
//     ios::sync_with_stdio(false); \
//     cin.tie(0);                  \
//     cout.tie(0);
// using namespace std;
// const int P = 100000007;
// int n;

// int qpow(int a, int k, int p)
// {
//     int ret = 1;
//     while (k)
//     {
//         if (k & 1)
//             ret = (ret * a) % p;
//         a = (a * a) % p;
//         k >>= 1;
//     }
//     return ret;
// }

// signed main()
// {

//     cin >> n;
//     int pw = 1;
//     for (int i = 1; i < n; i++)
//         pw *= 2, pw %= P;
//     int ans = 0;
//     for (int i = 1, tmp; i <= n; i++)
//     {
//         cin >> tmp;
//         ans += (tmp * pw) % P;
//         ans %= P;
//     }

//     cout << (ans * qpow(n, P - 2, P)) % P;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// int n;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         string s;
//         cin >> s;
//         for (int i = 0, len = s.length() - 11; i <= len; i++)
//         {
//             if (s[i] == '8')
//             {
//                 cout << "YES\n";
//                 goto ss;
//             }
//         }

//         cout << "NO\n";
//     ss:;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// int n, a1, a2, a3, a4;
// vector<int> num = {4, 8, 15, 16, 23, 42};
// unordered_map<int, int> mp;
// unordered_map<int, int> nums;
// int ans[7];

// signed main()
// {
//     IO;
//     for (auto p : num)
//         nums[p]++;

//     cout << "? 1 2\n";
//     fflush(stdout);
//     cin >> a1;
//     int b1[2];
//     for (int i = 0; i < num.size(); i++)
//     {
//         if (a1 % num[i] == 0 && nums[a1 / num[i]])
//         {
//             b1[0] = num[i];
//             b1[1] = a1 / num[i];
//             mp[b1[0]]++;
//             mp[b1[1]]++;
//             break;
//         }
//     }

//     cout << "? 2 3\n";
//     fflush(stdout);
//     cin >> a2;
//     int b2[2];
//     for (int i = 0; i < num.size(); i++)
//     {
//         if (a2 % num[i] == 0 && nums[a2 / num[i]])
//         {
//             b2[0] = num[i];
//             b2[1] = a2 / num[i];
//             mp[b2[0]]++;
//             mp[b2[1]]++;
//             break;
//         }
//     }

//     if (mp[b1[0]] == 2)
//         swap(b1[0], b1[1]);
//     if (mp[b2[1]] == 2)
//         swap(b2[0], b2[1]);

//     // cout << b1[0] << ' ' << b1[1] << ' ' << b2[0] << ' ' << b2[1] << '\n';
//     ans[1] = b1[0];
//     ans[2] = b1[1];
//     ans[3] = b2[1];

//     for (int i = 1; i <= 3; i++)
//     {
//         nums[ans[i]] = 0;
//         for (int j = 0; j < num.size(); j++)
//         {
//             if (ans[i] == num[j])
//             {
//                 num.erase(num.begin() + j);
//                 break;
//             }
//         }
//     }

//     cout << "? 4 5\n";
//     fflush(stdout);
//     cin >> a1;
//     b1[2];
//     for (int i = 0; i < num.size(); i++)
//     {
//         if (a1 % num[i] == 0 && nums[a1 / num[i]])
//         {
//             b1[0] = num[i];
//             b1[1] = a1 / num[i];
//             mp[b1[0]]++;
//             mp[b1[1]]++;
//             break;
//         }
//     }

//     cout << "? 5 6\n";
//     fflush(stdout);
//     cin >> a2;
//     b2[2];
//     for (int i = 0; i < num.size(); i++)
//     {
//         if (a2 % num[i] == 0 && nums[a2 / num[i]])
//         {
//             b2[0] = num[i];
//             b2[1] = a2 / num[i];
//             mp[b2[0]]++;
//             mp[b2[1]]++;
//             break;
//         }
//     }

//     if (mp[b1[0]] == 2)
//         swap(b1[0], b1[1]);
//     if (mp[b2[1]] == 2)
//         swap(b2[0], b2[1]);

//     // cout << b1[0] << ' ' << b1[1] << ' ' << b2[0] << ' ' << b2[1] << '\n';
//     ans[4] = b1[0];
//     ans[5] = b1[1];
//     ans[6] = b2[1];

//     cout << "! ";
//     for (int i = 1; i <= 6; i++)
//     {
//         cout << ans[i];
//         if (i < 6)
//             cout << ' ';
//         else
//             cout << '\n';
//     }
//     fflush(stdout);

//     return 0;
// }

// C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 5e5 + 5;
// int n, m, fa[N], d[N];

// int find(int x)
// {
//     return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
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
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         fa[i] = i;
//     while (m--)
//     {
//         int k, tmp[2];
//         cin >> k;
//         if (k == 0)
//             continue;
//         cin >> tmp[0];
//         for (int i = 1; i < k; i++)
//         {
//             cin >> tmp[i % 2];
//             merg(tmp[(i - 1) % 2], tmp[i % 2]);
//         }
//     }

//     for (int i = 1; i <= n; i++)
//         d[find(i)]++;

//     for (int i = 1; i <= n; i++)
//         cout << d[fa[i]] << ' ';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 5;
// int n, ans[N], m;
// string s;

// signed main()
// {
//     IO;
//     cin >> n;
//     cin >> s;
//     s = " " + s;
//     vector<int> l, r;
//     for (int i = 1; i <= n; i++)
//     {
//         if (s[i] == '(')
//             l.push_back(i);
//         else
//             r.push_back(i);
//     }
//     for (int i = 0, len = l.size(); i < len; i += 2)
//         ans[l[i]] = ans[r[i]] = 1;

//     for (int i = 1; i <= n; i++)
//         cout << ans[i];

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 5;
// int n;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         int tmp[2];
//         int f = 1, s1 = 0, s2 = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> tmp[i & 1];
//             if (f)
//             {
//                 s1 += tmp[i & 1];
//                 s2 += i;
//                 if (s1 < s2)
//                     f = 0;
//             }
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
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1005;
// int n;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         int mx = 0, my = 0;
//         unordered_map<int, int> x, y;
//         for (int i = 1, t1, t2; i <= n; i++)
//         {
//             cin >> t1 >> t2;
//             mx = max(mx, ++x[t1]);
//             my = max(my, ++y[t2]);
//         }
//         int n1 = 0, n2 = 0;
//         for (auto &[k, v] : x)
//             if (v == mx)
//                 n1++;
//         for (auto &[k, v] : y)
//             if (v == my)
//                 n2++;

//         if (n1 & 1)
//             n1 = 1;
//         else
//         {
//             vector<int> tmp(n1);
//             int f = 0;
//             for (auto &[k, v] : x)
//                 if (v == mx)
//                     tmp[f++] = k;
//             sort(tmp.begin(), tmp.end());
//             n1 = abs(tmp[n1 / 2] - tmp[(n1 / 2) - 1]) + 1;
//         }

//         if (n2 & 1)
//             n2 = 1;
//         else
//         {
//             vector<int> tmp(n2);
//             int f = 0;
//             for (auto &[k, v] : y)
//                 if (v == my)
//                     tmp[f++] = k;
//             sort(tmp.begin(), tmp.end());
//             n2 = abs(tmp[n2 / 2] - tmp[(n2 / 2) - 1]) + 1;
//         }
//         cout << n1 * n2 << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// /* 请在此处编写Number类 */
// class Number
// {
// public:
//     int val;

//     Number(int a)
//     {
//         val = a;
//     }

//     Number &add(int a)
//     {
//         val += a;
//         return *this;
//     }

//     Number &sub(int a)
//     {
//         val -= a;
//         return *this;
//     }

//     void print()
//     {
//         cout << val;
//     }

//     bool operator>(Number e)
//     {
//         return val > e.val;
//     }
// };

// int main()
// {
//     int a, b, c;
//     cin >> a >> b >> c;
//     Number n(a);
//     n.add(c).sub(1);
//     n.print();

//     cout << boolalpha << '\n'
//          << (Number(3) > Number(2));

//     return 0;
// }

// MyVector::MyVector(const MyVector &e)
// {
//     x = e.x;
//     y = e.y;
//     z = e.z;
// }

// MyVector::display()
// {
//     cout << '(' << x << ',' << y << ',' << z << ')';
// }

// MyVector add(MyVector &v1, MyVector &v2)
// {
//     MyVector ret(v1);
//     ret.x += v2.x;
//     ret.y += v2.y;
//     ret.z += v2.z;
//     return ret;
// }

// MyVector sub(MyVector &v1, MyVector &v2)
// {
//     MyVector ret(v1);
//     ret.x -= v2.x;
//     ret.y -= v2.y;
//     ret.z -= v2.z;
//     return ret;
// }

// int dot(MyVector &v1, MyVector &v2)
// {
//     int ret = 0;
//     ret += v1.x * v2.x;
//     ret += v1.y * v2.y;
//     ret += v1.z * v2.z;
//     return ret;
// }

// MyVector cross(MyVector &v1, MyVector &v2)
// {
//     MyVector ret();
//     ret.x = v1.y * v2.z - v1.z * v2.y;
//     ret.y = v1.z * v2.x - v1.x * v2.z;
//     ret.z = v1.x * v2.y - v1.y * v2.x;
//     return ret;
// }

// MyVector::MyVector(const MyVector &e)
// {
//     x = e.x;
//     y = e.y;
//     z = e.z;
// }

// #include <iostream>
// using namespace std;
// class MyVector
// {
// public:
//     MyVector(int = 0, int = 0, int = 0);
//     int x, y, z;
// };

// MyVector::MyVector(int, int, int) : x(1), y(2), z(3) { ; }

// int main()
// {

//     MyVector v0;
//     MyVector v1(1);
//     MyVector v2(1, 2);
//     MyVector v3(1, 2, 3);
//     cout << v0.x << ' ' << v0.y << ' ' << v0.z << '\n';
//     return 0;
// }

// void fun(int a = 1);
// void fun(int a)
// {
//     cout << a;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 5;
// int n, m, a[N], pl[N], pr[N], l, r, mr[N], ml[N];

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         if (!pl[a[i]])
//             pl[a[i]] = i;
//         pr[a[i]] = i;
//     }

//     l = 1;
//     mr[1] = pr[1];
//     for (int i = 2; i <= m; i++)
//     {
//         if (pl[i] > mr[i - 1] || !pl[i])
//         {
//             l++;
//             mr[i] = max(mr[i - 1], pr[i]);
//         }
//         else
//             break;
//     }

//     r = m;
//     ml[m] = pl[m];
//     for (int i = m - 1; i >= 1; i--)
//     {
//         if (pr[i] < ml[i + 1] || !pr[i])
//         {
//             r--;
//             if (pl[i])
//                 ml[i] = min(ml[i + 1], pl[i]);
//             else
//                 ml[i] = ml[i + 1];
//         }
//         else
//             break;
//     }

//     // cout << l << ' ' << r << '\n';
//     for (int i = 1; i <= l; i++)
//         cout << mr[i] << ' ';
//     cout << '\n';
//     for (int i = r; i <= m; i++)
//         cout << ml[i] << ' ';
//     cout << '\n';
//     int ans = 0;
//     for (int q = 1, p = r; q <= l; q++)
//     {
//         while (mr[q] > ml[p] && p <= m)
//             p++;
//         if (p > m)
//             break;
//         ans += 1 + m - p;
//     }
//     cout << ans;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e6 + 5;
// int n;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         string s;
//         cin >> s;
//         unordered_set<string> st;
//         for (int i = 0, len = s.length(); i < len - 1; i++)
//         {
//             string tmp;
//             tmp.push_back(s[i]);
//             tmp.push_back(s[i + 1]);
//             st.insert(tmp);
//         }
//         cout << st.size() << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e6 + 5;
// int n;

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         string s;
//         cin >> s;
//         unordered_set<string> st;
//         for (int i = 0, len = s.length(); i < len - 1; i++)
//         {
//             string tmp;
//             tmp.push_back(s[i]);
//             tmp.push_back(s[i + 1]);
//             st.insert(tmp);
//         }
//         cout << st.size() << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// #define IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
// #define all(x) (x).begin(), (x).end()
// #define rson id << 1 | 1
// #define lson id << 1
// #define int long long
// #define endl '\n'
// using namespace std;
// typedef unsigned long long ULL;
// typedef long long ll;
// const int N = 2e5 + 10;

// int n;
// int a[N];

// void solve()
// {
//     cin >> n;
//     for (int i = 1; i <= n; ++i)
//         cin >> a[i];
//     sort(a + 1, a + n + 1);
//     // cout << a[1] << endl;
//     if (a[1] % 2 == 1)
//     {
//         cout << "YES" << endl;
//         return;
//     }
//     else
//     {
//         bool flag = false;
//         for (int i = 2; i <= n; ++i)

//         {
//             if (a[i] % 2 == 1)

//             {
//                 cout << "NO" << endl;
//                 return;
//             }
//         }
//     }
//     cout << "YES" << endl;
// }
// signed main(void)
// {
//     IO;
//     int T = 1;
//     cin >> T;
//     while (T--)

//     {
//         solve();
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// typedef long long ll;
// const int inf = 0x3f3f3f3f;
// const int N = 1e6 + 10;
// int b[N];
// struct node
// {
//     int x;
//     int id;
// } a[N];

// bool cmp(node a, node b)
// {
//     return a.x < b.x;
// }

// int ans[N];
// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> a[i].x;
//             a[i].id = i;
//         }
//         sort(a + 1, a + 1 + n, cmp);
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> b[i];
//         }
//         sort(b + 1, b + 1 + n);
//         for (int i = 1; i <= n; i++)
//         {
//             ans[a[i].id] = b[i];
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             cout << ans[i] << " ";
//             a[i].id = a[i].x = 0;
//             b[i] = 0;
//             ans[i] = 0;
//         }
//         cout << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2005;
// int n, a[N], b[N];

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> a[i];
//             b[i] = a[i];
//         }

//         int ask = n;
//         if (a[1] == n)
//             ask = n - 1;

//         int p = 0;
//         for (int i = 1; i <= n; i++)
//             if (a[i] == ask)
//             {
//                 p = i;
//                 break;
//             }

//         int fp = p - 1;
//         for (; fp > 1; fp--)
//         {
//             if (b[fp - 1] < b[1])
//                 break;
//         }

//         b[1] = ask;
//         for (int i = p - 1; i >= fp; i--)
//             b[1 + (p - i)] = a[i];
//         for (int i = 1; i < fp; i++)
//             b[p - fp + 1 + i] = a[i];

//         int f = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             if (a[n + 1 - 1] > b[i])
//             {
//                 f = 1;
//                 break;
//             }
//         }

//         if (f)
//             for (int i = n; i >= 1; i--)
//                 cout << a[i] << ' ';
//         else
//             for (int i = 1; i <= n; i++)
//                 cout << a[i] << ' ';

//         cout << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// #define IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
// #define all(x) (x).begin(), (x).end()
// #define rson id << 1 | 1
// #define lson id << 1
// #define int long long
// #define mpk make_pair
// #define endl '\n'
// using namespace std;
// typedef unsigned long long ULL;
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<double, double> pdd;
// const int inf = 0x3f3f3f3f;
// const ll INF = 0x3f3f3f3f3f3f3f3f;

// const int N = 2e5 + 10;

// int n;
// int a[N];

// bool cmp(vector<int> &a, vector<int> &b)
// {
//     if (a.size() != b.size())
//         return a.size() > b.size();
//     for (int i = 0; i < a.size(); ++i)
//     {
//         if (a[i] != b[i])
//             return a[i] > b[i];
//     }
//     return true;
// }

// void solve()
// {
//     cin >> n;
//     vector<int> v;
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> a[i];
//         if (i < n)
//             v.push_back(a[i]);
//     }
//     int p = 2;
//     for (int i = 2; i <= n; ++i)
//     {
//         if (a[i] > a[p])
//             p = i;
//     }
//     p--;
//     int pos = 1;
//     for (int i = p - 1; i >= 2; i--)
//     {
//         if (a[i] < a[1])
//         {
//             pos = i + 1;
//             break;
//         }
//     }
//     vector<int> ans;
//     for (int i = p + 1; i <= n; ++i)
//         ans.push_back(a[i]);
//     for (int i = p; i >= pos; --i)
//         ans.push_back(a[i]);
//     for (int i = 1; i <= pos - 1; ++i)
//         ans.push_back(a[i]);
//     bool flag = false;
//     vector<int> b;
//     if (p + 1 == n)
//     {
//         // reverse(all(v));
//         b.push_back(a[n]);
//         for (auto it : v)
//             b.push_back(it);
//         // for (auto it : b)
//         //     cout << it << " ";
//         // cout << endl;
//         if (cmp(ans, b))
//         {
//             for (auto it : ans)
//                 cout << it << " ";
//             cout << endl;
//         }
//         else
//         {
//             for (auto it : b)
//                 cout << it << " ";
//             cout << endl;
//         }
//         return;
//     }
//     for (auto it : ans)
//         cout << it << " ";
//     cout << endl;
// }
// signed main(void)
// {
//     IO;
//     int t = 1;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 5;
// int n, a[N], fa[N], mp[N];
// set<int> st;

// int find(int x)
// {
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }

// void merge(int a, int b)
// {
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// void init()
// {
//     for (int i = 1; i <= n; i++)
//         fa[i] = i;
// }

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         int cnt = 0;
//         for (int i = 1; i <= n; i++)
//             mp[i] = 0;
//         init();
//         for (int i = 1; i <= n; i++)
//         {
//             int x;
//             cin >> x;
//             mp[i] = x;
//             merge(x, i);
//             // if (mp[i] == x) cnt++;
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             int o = mp[i];
//             if (mp[o] == i)
//                 cnt++;
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             // cout << find(i) << endl;
//             st.insert(find(i));
//         }
//         cnt /= 2;
//         int w = st.size() - cnt;
//         int ans = st.size();
//         cout << min(w + 1, ans) << " " << st.size() << endl;
//         st.clear();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// #define IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
// #define all(x) (x).begin(), (x).end()
// #define rson id << 1 | 1
// #define lson id << 1
// #define int long long
// #define mpk make_pair
// #define endl '\n'
// using namespace std;
// typedef unsigned long long ULL;
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<double, double> pdd;
// const int inf = 0x3f3f3f3f;
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// const double eps = 1e-9;
// const int N = 2e5 + 10, M = 4e5 + 10;

// int n, m;
// unordered_map<int, int> mp;

// int qpow(int a, int b, int p)
// {
//     int res = 1;
//     while (b)
//     {
//         if (b & 1)
//             res = res * a % p;
//         b >>= 1;
//         a = a * a % p;
//     }
//     return res % p;
// }

// void solve()
// {
//     mp.clear();
//     vector<int> a;
//     cin >> n >> m;
//     for (int i = 1; i <= n; ++i)
//     {
//         int x;
//         cin >> x;
//         mp[x]++;
//         a.push_back(x);
//     }
//     sort(all(a));
//     a.erase(unique(all(a)), a.end());
//     int ans = 0;
//     int sum = mp[a[0]];
//     int pre = 0;
//     if (m > 1)
//     {
//         for (int i = 0; i < a.size() - 1; ++i)
//         {
//             if (a[i] == a[i + 1] - 1)
//             {
//                 sum = (sum * mp[a[i + 1]]) % mod;
//                 if (i + 1 - pre + 1 == m)
//                 {
//                     ans = (ans + sum) % mod;
//                     sum = sum * qpow(mp[a[pre]], mod - 2, mod) % mod;
//                     pre++;
//                 }
//             }
//             else
//             {
//                 sum = mp[a[i + 1]];
//                 pre = i + 1;
//             }
//         }
//     }
//     else
//     {
//         for (auto it : a)
//         {
//             ans = (ans + mp[it]) % mod;
//         }
//     }
//     cout << ans << endl;
// }
// signed main(void)
// {
//     IO;
//     int t = 1;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// #define Zeoy std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
// #define all(x) (x).begin(), (x).end()
// #define rson id << 1 | 1
// #define lson id << 1
// #define int long long
// #define mpk make_pair
// #define endl '\n'
// using namespace std;
// typedef unsigned long long ULL;
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<double, double> pdd;
// const int inf = 0x3f3f3f3f;
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// const double eps = 1e-9;
// const int N = 2e5 + 10, M = 4e5 + 10;

// int n;
// int sz[N];
// vector<int> g[N];
// vector<int> ans;

// map<pii, int> mp;

// void dfs(int u, int par)
// {

//     sz[u] = 1;
//     for (auto v : g[u])

//     {
//         if (v == par)
//             continue;
//         dfs(v, u);
//         sz[u] += sz[v];
//         if (sz[u] == 3)

//         {
//             if (par)
//                 ans.push_back(mp[mpk(u, par)]);
//             sz[u] = 0;
//         }
//     }
// }

// void solve()
// {
//     cin >> n;
//     mp.clear();
//     ans.clear();
//     if (n == 3)

//     {
//         cout << 0 << endl
//              << endl;
//         return;
//     }
//     if (n % 3)

//     {
//         cout << -1 << endl;
//         return;
//     }
//     for (int i = 1, u, v; i < n; ++i)
//     {
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//         mp[mpk(u, v)] = i;
//         mp[mpk(v, u)] = i;
//     }
//     dfs(1, 0);
//     cout << ans.size() << endl;
//     for (auto it : ans)
//         cout << it << " ";
//     cout << endl;
// }
// signed main(void)
// {
//     Zeoy;
//     int T = 1;
//     cin >> T;
//     while (T--)

//     {
//         solve();
//     }
//     return 0;
// }