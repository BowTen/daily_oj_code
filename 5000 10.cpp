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

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int mod = 998244353;
// int n;

// int qpow(int a, int q, int p)
// {
//     int ret = 1;
//     while (q)
//     {
//         if (1 & q)
//             ret = ret * a % p;
//         a = a * a % p;
//         q >>= 1;
//     }
//     return ret;
// }

// signed main()
// {
//     IO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         int ans = 0;
//         int pw = qpow(2, n - 1, mod);
//         int px = 1;
//         for (int i = 1; i <= n; i++)
//         {
//             ans = (ans + pw * px) % mod;
//             pw /= 2;
//             px = px * 2 % mod;
//         }
//         cout << ans << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int x, y;
//         cin >> x >> y;
//         // 1 + (y-1)
//         // x - (y-1)

//         cout << x - y + 1 << '\n';
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int days[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// int isrn(int x)
// {
//     return ((x % 4 == 0 && x % 100) || x % 400 == 0);
// }

// int main()
// {
//     string a, b;
//     while (cin >> a >> b)
//     { // 注意 while 处理多个 case
//         if (a > b)
//             swap(a, b);
//         int y1, y2, m1, m2, d1, d2;
//         y1 = (a[0] - '0') * 1000 + (a[1] - '0') * 100 + (a[2] - '0') * 10 + a[3] - '0';
//         y2 = (b[0] - '0') * 1000 + (b[1] - '0') * 100 + (b[2] - '0') * 10 + b[3] - '0';
//         m1 = (a[4] - '0') * 10 + a[5] - '0';
//         m2 = (b[4] - '0') * 10 + b[5] - '0';
//         d1 = (a[6] - '0') * 10 + a[7] - '0';
//         d2 = (b[6] - '0') * 10 + b[7] - '0';

//         int ans = 0;
//         for (; y1 < y2 - 1; y1++)
//         {
//             if (isrn(y1))
//                 ans += 366;
//             else
//                 ans += 365;
//         }

//         if (y1 < y2)
//         {
//             for (; m1 < 12; m1++)
//             {
//                 if (m1 == 2)
//                     if (isrn(y1))
//                         ans += 29;
//                     else
//                         ans += 28;
//                 else
//                     ans += days[m1];
//             }
//             m1 = 1;
//             ans += 32 - d1;
//             d1 = 1;
//             y1++;
//         }

//         cout << ans << '\n';
//         cout << y1 << ' ' << m1 << ' ' << d1 << '\n';
//         for (; m1 < m2 - 1; m1++)
//         {
//             if (m1 == 2)
//                 if (isrn(y1))
//                     ans += 29;
//                 else
//                     ans += 28;
//             else
//                 ans += days[m1];
//         }
//         cout << ans << '\n';
//         cout << y1 << ' ' << m1 << ' ' << d1 << '\n';

//         if (m1 < m2)
//         {
//             if (m1 == 2)
//                 if (isrn(y1))
//                     ans += 30 - d1;
//                 else
//                     ans += 29 - d1;
//             else
//                 ans += days[m1] + 1 - d1;
//             d1 = 1;
//             m1++;
//         }

//         ans += d2 - d1 + 1;

//         cout << ans << '\n';
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// class A {
// public:
//     virtual void fun() {
//         cout << "Afun()\n";
//     }

//     int _a;
// };

// class B : public A {
// public:
//     //int fun(int a) {
//     //    cout << "Bfun()\n";
//     //    return a;
//     //}

//     void fun() {
//         cout << "redefine Afun()\n";
//     }
// };

// signed main()
// {
//     B b;
//     A& p = b;

//     //b.fun();
//     //b.fun(1ll);
//     //b.A::fun();

//     p.A::fun();
//     p.fun();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Vehicle
// {
// private:
//     int numberOfDoors;     // 车门数
//     int numberOfCylinders; // 气缸数
//     string color;          // 汽车颜色
//     double fueLevel;       // 油位（燃油数量）
//     int transmissionType;  // 变速箱类型
//     string className;      // 汽车类别

// public:
//     Vehicle(int nd, int nc, string col, double ful, int tran)
//     {
//         numberOfDoors = nd;
//         numberOfCylinders = nc;
//         color = col;
//         fueLevel = ful;
//         transmissionType = tran;
//     }

//     int getNumberOfDoors()
//     {
//         return numberOfDoors;
//     }

//     int getNumberOfCylinders()
//     {
//         return numberOfCylinders;
//     }

//     string getColor()
//     {
//         return color;
//     }

//     double getFuelLevel()
//     {
//         return fueLevel;
//     }

//     int getTransmissionType()
//     {
//         return transmissionType;
//     }

//     string getClassNme()
//     {
//         return className;
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     fstream fs;
//     fs.open("D:\\tttttttt\\example.txt", ios::out | ios::trunc | ios::in | ios::binary);
//     if (!fs.is_open())
//     {
//         cout << "创建文件失败\n";
//         exit(EXIT_FAILURE);
//     }
//     for (int i = 1, t; i <= 5; i++)
//     {
//         cin >> t;
//         fs << t;
//         if (i == 5)
//             fs << '\n';
//         else
//             fs << ' ';
//     }

//     for (int i = 1, t; i <= 5; i++)
//     {
//         cin >> t;
//         fs << t;
//         if (i != 5)
//             fs << ' ';
//     }
//     fs << '\0';

//     char s[30];
//     fs.seekg(0);

//     fs.read(s, sizeof(s));
//     cout << s;

//     // for (int i = 0; i < 30; i++)
//     //     cout << s[i];

//     fs.close();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     ifstream ifs("D:\\ttt\\plaintext.txt");
//     if (!ifs.is_open())
//     {
//         cout << "读取文件失败\n";
//         exit(EXIT_FAILURE);
//     }
//     ofstream ofs("D:\\ttt\\ciphertext.txt");
//     if (!ifs.is_open())
//     {
//         cout << "写入文件失败\n";
//         exit(EXIT_FAILURE);
//     }

//     char c;
//     while (ifs.get(c))
//         ofs.put(c + 2);

//     ofs.close();
//     ifs.close();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// string a, b;

// string add(string a, string b);
// string div(string a, string b);

// string add(string a, string b)
// {

//     int f = 0;
//     if (a[0] == '-' && b[0] == '-')
//     {
//         f = 1;
//         a = string(a.rbegin(), a.rend() - 1);
//         b = string(b.rbegin(), b.rend() - 1);
//     }
//     else
//     {
//         if (a[0] == '-')
//         {
//             return div(b, string(a.begin() + 1, a.end()));
//         }
//         else if (b[0] == '-')
//         {
//             return div(a, string(b.begin() + 1, b.end()));
//         }
//         else
//         {
//             reverse(a.begin(), a.end());
//             reverse(b.begin(), b.end());
//         }
//     }

//     if (b.size() > a.size())
//         swap(a, b);

//     for (int i = 0, len = b.size(); i < len; i++)
//     {
//         a[i] += b[i] - '0';
//         if (a[i] > '9')
//         {
//             a[i] -= 10;
//             if (i + 1 < a.size())
//                 a[i + 1]++;
//             else
//                 a.push_back('1');
//         }
//     }
//     if (a.back() > '9')
//     {
//         a.back()--;
//         a.push_back('1');
//     }

//     if (f)
//         a.push_back('-');
//     reverse(a.begin(), a.end());
//     return a;
// }

// string div(string a, string b)
// {
//     int f = 0;
//     if (a[0] == '-' && b[0] == '-')
//     {
//         a = string(a.begin() + 1, a.end());
//         b = string(b.begin() + 1, b.end());
//         swap(a, b);
//     }
//     else
//     {
//         if (a[0] == '-')
//         {
//             return add(a, "-" + b);
//         }
//         else if (b[0] == '-')
//             return add(a, string(b.begin() + 1, b.end()));
//     }

//     if (a.size() < b.size() || (a.size() == b.size() && b > a))
//     {
//         f = 1;
//         swap(a, b);
//     }

//     reverse(a.begin(), a.end());
//     reverse(b.begin(), b.end());

//     for (int i = 0, len = b.size(); i < len; i++)
//     {
//         a[i] -= b[i] - '0';
//         if (a[i] < '0')
//         {
//             a[i] += 10;
//             a[i + 1]--;
//         }
//     }

//     for (int i = a.size() - 1; i >= 1; i--)
//     {
//         if (a[i] > '0')
//             break;
//         a.pop_back();
//     }

//     if (f)
//         a.push_back('-');
//     reverse(a.begin(), a.end());
//     return a;
// }

// vector<int> multi(string &A, string &B) // 高精度乘法
// {
//     vector<int> res(A.size() + B.size(), 0);
//     for (int i = 0; i < A.size(); i++)
//         for (int j = 0; j < B.size(); j++)
//             res[i + j] += (A[i] - '0') * (B[j] - '0');
//     for (int i = 0, t = 0; i < res.size(); i++)
//     {
//         t += res[i];
//         res[i] = t % 10;
//         t /= 10;
//     }
//     while (res.size() > 1 && res.back() == 0)
//         res.pop_back();
//     string ret(res.size(), '0');
//     for (int i = 0, len = res.size(); i < len; i++)
//         ret[i] += res[i];
//     return res;
// }

// int main()
// {

//     cin >> a >> b;
//     // cout << add(a, b) << '\n';
//     // cout << div(a, b) << '\n';
//     // cout << multi(a, b) << '\n';
//     vector<int> ans = multi(a, b);
//     for (auto p : ans)
//         cout << p;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class vec
// {
// public:
//     vec(int x = 0)
//     {
//         pData = new int[x];
//     }

//     int &operator[](int id) const
//     {
//         return pData[id];
//     }

// private:
//     int *pData;
// };

// int main()
// {

//     int t;

//     cin >> t;

//     const int num = t;
//     // const vec a(num);
//     int a[num];
//     for (int i = 0; i < num; i++)
//         a[i] = i;

//     for (int i = 0; i < num; i++)
//         cout << a[i] << ' ';

//     cout << '\n';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int a = 5;

//     const int *pa = &a;
//     a = 10;

//     cout << a;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class person
// {
// public:
//     string name;
//     int age;
//     person(string name = "person", int age = 18) : name(name), age(age) { ; }

//     virtual void print()
//     {
//         cout << name << ' ' << age << " | " << pv << '\n';
//     }

// private:
//     string pv = "person pv";
// };

// class boy : public person
// {
// public:
//     string name;
//     int age;
//     boy(string na = "boy", int ag = 8) : name(na), age(ag) {}

//     virtual void print()
//     {
//         cout << name << ' ' << age << '\n';
//     }
// };

// class baby : public boy
// {
// public:
//     string name;
//     int age;
//     baby(string na = "baby", int ag = 1) : name(na), age(ag) {}

//     virtual void print()
//     {
//         cout << name << ' ' << age << '\n';
//     }
// };

// int main()
// {

//     baby b;
//     baby *cp = &b;
//     boy *bp = &b;
//     person *ap = &b;

//     cp->print();
//     bp->boy::print();
//     ap->person::print();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void FileWrite(string fileName, string writeData)
// {
//     fileName = "D:\\fileTest\\" + fileName;
//     // ofstream ofs(fileName);
//     ofstream ofs;
//     ofs.open(fileName, ios::app);
//     if (!ofs.is_open())
//     {
//         cout << "文件写入失败\n";
//         exit(EXIT_FAILURE);
//     }
//     ofs << writeData << '\n';
//     ofs.close();
// }

// void FilePrint(string fileName)
// {
//     fileName = "D:\\fileTest\\" + fileName;
//     ifstream ifs;
//     ifs.open(fileName);
//     // cout << ifs.tellg();
//     // ifs.seekg(0);
//     cout << ifs.fail();
//     if (!ifs.is_open())
//     {
//         cout << "文件打印失败\n";
//         exit(EXIT_FAILURE);
//     }
//     string tmp;
//     while (ifs >> tmp)
//         cout << tmp << '\n';
//     ifs.close();
// }

// int main()
// {

//     // FileWrite("test.txt", "哎呦~");
//     // FileWrite("test.txt", "你干嘛！");
//     // FileWrite("test.txt", "哈哈呦~");

//     // FilePrint("test.txt");

//     int m = 0, n = 0;
//     ofstream ofs("test.txt");
//     if (!ofs.is_open())
//     {
//         cout << "写入文件失败\n";
//         exit(EXIT_FAILURE);
//     }
//     for (int i = 0; i < 5; i++)
//         ofs << i;
//     ofs.close();
//     ifstream ifs("test.txt");
//     if (!ifs.is_open())
//     {
//         cout << "读入文件失败\n";
//         exit(EXIT_FAILURE);
//     }
//     ifs >> m >> n;
//     ifs.close();
//     cout << m << ' ' << n;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     ofstream ofs("D:\\fileTest\\test.txt");
//     if (!ofs.is_open())
//     {
//         cout << "写入文件失败\n";
//         exit(EXIT_FAILURE);
//     }
//     ofs << "123456789";
//     ofs.close();

//     ifstream ifs("D:\\fileTest\\test.txt");
//     if (!ifs.is_open())
//     {
//         cout << "读入文件失败\n";
//         exit(EXIT_FAILURE);
//     }
//     char c;
//     while (ifs >> c)
//     {
//         cout << '\n'
//              << ifs.tellg() << "->";
//         cout << c;
//         // ifs.ignore();
//         // ifs.seekg(1, ios::cur);
//         // ifs.seekg(-1, ios::cur);
//         // cout << ' ' << ifs.tellg() << '\n';
//         // ifs.seekg(-1, ios::cur);
//     }

//     ios_base::seekdir

//         return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class A
// {
// public:
//     virtual void fun()
//     {
//         cout << "useful Things\n";
//     }
// };

// class B : private A
// {
// public:
//     void fun()
//     {
//         A::fun();
//         cout << "Bfun()\n";
//     }
// };

// class A
// {

// private:
//     friend class B;
//     static int a;
// };

// int A::a = 888;

// class B
// {
// public:
//     void print()
//     {
//         cout << A::a;
//     }
// };

// int main()
// {
//     B b;
//     b.print();
//     // B b;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class A
// {
// public:
//     int t;
// };

// class B
// {
// public:
//     int t;
// };

// class C : virtual public A, virtual public B
// {

// public:
//     C()
//     {
//         B::t = 24;
//     }
// };

// int main()
// {

//     C c;
//     cout << c.A::t;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// class A
// {

// public:
//     using tp = int;
//     typedef double db;
//     tp a;
//     void fun()
//     {
//     }
// };

// int main()
// {
//     ll a = 123;
//     cout << a;

//     return 0;
// }

// class LinkedList
// {
// private:
//     class node
//     {
//     public:
//         int val;
//         node *next;
//         node(int v = 0, node *ne = nullptr) : val(v), next(ne) {}
//     };
//     node head;

// public:
//     LinkedList() : head() {}

//     void add(int x)
//     {
//         // cout << 1;
//         node *cur = &head;
//         while (cur->next != nullptr && cur->next->val > x)
//             cur = cur->next;
//         node *ins = new node(x, cur->next);
//         cur->next = ins;
//     }

//     void print()
//     {
//         node *cur = &head;
//         while (cur->next != nullptr)
//         {
//             cur = cur->next;
//             cout << cur->val << ' ';
//         }
//     }
// };

// int main()
// {

//     LinkedList ls;
//     ls.add(2);
//     ls.add(3);
//     ls.add(1);
//     ls.add(4);

//     ls.print();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class aa
// {
// protected:
//     int t = 45;
//     void fun(int)
//     {
//         cout << "aafun\n";
//     }
// };

// class bb : protected aa
// {
// public:
//     void fun()
//     {
//         cout << t;
//     }
// };

// class cc : protected bb
// {
// public:
//     void func()
//     {
//         cout << t;
//     }
// };

// int main()
// {

//     bb b;
//     b.fun();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 5;
// int n, k, a[110], d[110];

// signed main()
// {

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> k;
//         for (int i = 1; i <= n; i++)
//             d[i] = ceil((double)i / (double)k), a[i] = 0;

//         int q = 0, p = 0, ans = 0;
//         for (int i = 1, j = n; i < n; i++, j--)
//         {
//             if (a[i])
//                 p++, q++;
//             if (q < d[i])
//             {
//                 q++;
//                 p++;
//                 ans++;
//                 a[i] = 1;
//                 if (j > i)
//                     a[j] = 1, ans++;
//             }
//         }
//         cout << ans << '\n';

//         // int ans = ceil(double((n + 1) / 2) / k) * 2;
//         // int ans = d[(n + 1) / 2] * 2;
//         // if (n & 1 && d[(n + 1) / 2] > d[n / 2])
//         //     ans--;
//         // cout << d[n] << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 5;
// int n, a[N], b[N];

// signed main()
// {

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         map<int, vector<int>> mp;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> a[i] >> b[i];
//             mp[a[i]].push_back(b[i]);
//         }
//         for (auto &[k, v] : mp)
//         {
//             sort(v.begin(), v.end(), greater<int>());
//             // cout << k << " | ";
//             // for (auto p : v)
//             //     cout << p << ' ';
//             // cout << '\n';
//         }

//         // for (auto [k, v] : mp)
//         // {
//         //     cout << k << " | ";
//         //     for (auto p : v)
//         //         cout << p << ' ';
//         //     cout << '\n';
//         // }

//         auto p = mp.begin();
//         int p2 = 0;
//         int ans = 0;
//         for (int i = 0; i <= n; i++)
//         {
//             while (p != mp.end() && (i >= p->first || p2 >= p->second.size()))
//                 p++, i -= p2, p2 = 0;
//             if (p == mp.end())
//                 break;
//             if (p2 < p->second.size())
//             {
//                 // cout << '[' << p->first << ' ' << p2 << ' ' << p->second[p2] << ']' << '\n';
//                 ans += p->second[p2++];
//             }
//         }
//         cout << ans << '\n';
//         // cout << "___________\n";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class pla
// {
// public:
//     virtual void up() = 0;
//     virtual void down() = 0;
//     virtual void left() = 0;
//     virtual void right() = 0;
// };

// class dog : public pla
// {
// public:
//     void up()
//     {
//         cout << "向上移动\n";
//     }
//     void down()
//     {
//         cout << "向下移动\n";
//     }
//     void left()
//     {
//         cout << "向左移动\n";
//     }
//     void right()
//     {
//         cout << "向右移动\n";
//     }
// };

// int main()
// {
//     dog d;
//     pla &p = d;

//     p.up();
//     p.down();
//     p.left();
//     p.right();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     string a("hello world");
//     cout << "size:" << a.size() << ' ' << "capa:" << a.capacity() << '\n';
//     a.reserve(111);
//     cout << "size:" << a.size() << ' ' << "capa:" << a.capacity() << '\n';
//     a.resize(2);
//     cout << "size:" << a.size() << ' ' << "capa:" << a.capacity() << '\n';
//     a.reserve(50);
//     cout << "size:" << a.size() << ' ' << "capa:" << a.capacity() << '\n';
//     cout << a;
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// class person
// {
// public:
//     string name;
//     int age;
//     int height;
//     int weight;
//     person() = default;
//     person(string name = "name", int age = 1, int height = 1, int weight = 1) : name(name), age(age), height(height), weight(weight) {}
// };

// class student : public person
// {
// public:
//     using person::person;
//     void print()
//     {
//         cout << name << ' ' << age << "岁 " << height << "cm " << weight << "kg\n";
//     }
// };

// int main()
// {

//     student s1;
//     s1.print();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int t;
//     // cin >> t;
//     string n;
//     getline(cin, n);
//     for (int i = 0; i < n.size(); i++)
//     {
//         t *= 10;
//         t += n[i] - '0';
//     }
//     // cout << t << '\n';

//     map<string, string> mp;
//     mp["C++"] = "Course";
//     mp["Hangzhou Normal"] = "University";
//     mp["Nice to meet you"] = "Nice to meet you too";
//     // getchar();
//     while (t--)
//     {
//         string s;
//         getline(cin, s);
//         if (s == "C++")
//             cout << "Course\n";
//         else if (s == "Hangzhou Normal")
//             cout << "University\n";
//         else
//             cout << "Nice to meet you too\n";
//         // cout << mp[s];
//         // // if (t)
//         // cout << '\n';

//         // cout << s << '\n';
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {

//     int t;
//     scanf("%d", &t);
//     getchar();
//     while (t--)
//     {
//         char s[100];
//         gets(s);
//         // cout << s << '\n';
//         if (s[0] == 'C')
//             cout << "Course\n";
//         if (s[0] == 'H')
//             cout << "University\n";
//         if (s[0] == 'N')
//             cout << "Nice to meet you too\n";
//     }

//     return 0;
//}

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct stu {
// 	char clas[5];
// }data;

// typedef struct node {
// 	data a[1];
// }node;

// void test1() {
// 	node* s = (node*)malloc(sizeof(node));
// 	scanf_s("%s", s->a->clas);
// 	printf("%s\n", s->a->clas);
// }

// int main() {

// 	test1();

// 	return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;

// int cnt = 1;
// class dlist;
// class node
// {
// public:
//     node(int v = 0, node *pre = nullptr, node *ne = nullptr) : val(v), pre(pre), ne(ne) {}
//     int val;
//     node *pre;
//     node *ne;
// };
// node *ad[N];

// class dlist
// {
// public:
//     node head;
//     node tail;
//     int size = 0;

// public:
//     dlist() : head(0, nullptr, &tail), tail(0, &head, nullptr) {}

//     void push_left(int v)
//     {
//         node *t = new node(v, &head, head.ne);
//         ad[cnt++] = t;
//         head.ne->pre = t;
//         head.ne = t;
//     }

//     void push_right(int v)
//     {
//         node *t = new node(v, tail.pre, &tail);
//         ad[cnt++] = t;
//         tail.pre->ne = t;
//         tail.pre = t;
//     }

//     void remove(int x)
//     {
//         node *t = ad[x];
//         t->pre->ne = t->ne;
//         t->ne->pre = t->pre;
//         delete t;
//     }

//     void push_left_at(int x, int v)
//     {
//         node *t = new node(v, ad[x]->pre, ad[x]);
//         ad[cnt++] = t;
//         ad[x]->pre->ne = t;
//         ad[x]->pre = t;
//     }

//     void push_right_at(int x, int v)
//     {
//         node *t = new node(v, ad[x], ad[x]->ne);
//         ad[cnt++] = t;
//         ad[x]->ne->pre = t;
//         ad[x]->ne = t;
//     }

//     void print()
//     {
//         node *cur = head.ne;
//         while (cur->ne)
//         {
//             cout << cur->val << ' ';
//             cur = cur->ne;
//         }
//         cout << '\n';
//     }
// };

// dlist dl;

// void test()
// {
//     string s;
//     int a, b;
//     cin >> s >> a;
//     if (s[0] == 'L')
//     {
//         dl.push_left(a);
//     }
//     else if (s[0] == 'R')
//     {
//         dl.push_right(a);
//     }
//     else if (s[0] == 'D')
//     {
//         dl.remove(a);
//     }
//     else
//     {
//         cin >> b;
//         if (s[1] == 'L')
//         {
//             dl.push_left_at(a, b);
//         }
//         else
//         {
//             dl.push_right_at(a, b);
//         }
//     }
// }

// int main()
// {

//     int t;
//     cin >> t;
//     while (t--)
//         test();
//     dl.print();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;

// int ls[N], L[N], R[N], cnt;

// void push(int x, int v, int k)
// {
//     ls[++cnt] = v;
//     if (k)
//     { // right
//         R[cnt] = R[x];
//         L[cnt] = x;
//         R[L[cnt]] = cnt;
//         L[R[cnt]] = cnt;
//     }
//     else
//     { // left
//         R[cnt] = x;
//         L[cnt] = L[x];
//         R[L[cnt]] = cnt;
//         L[R[cnt]] = cnt;
//     }
// }

// void remove(int x)
// {
//     R[L[x]] = R[x];
//     L[R[x]] = L[x];
// }

// void test()
// {
//     string s;
//     int a, b;
//     cin >> s >> a;
//     if (s[0] == 'L')
//     {
//         push(0, a, 1);
//     }
//     else if (s[0] == 'R')
//     {
//         push(N - 1, a, 0);
//     }
//     else if (s[0] == 'D')
//     {
//         remove(a);
//     }
//     else
//     {
//         cin >> b;
//         if (s[1] == 'L')
//         {
//             push(a, b, 0);
//         }
//         else
//         {
//             push(a, b, 1);
//         }
//     }
// }

// void init()
// {
//     L[0] = -1;
//     R[N - 1] = -1;
//     R[0] = N - 1;
//     L[N - 1] = 0;
// }

// void print()
// {
//     int cur = R[0];
//     while (cur != N - 1)
//     {
//         cout << ls[cur] << ' ';
//         cur = R[cur];
//     }
//     cout << '\n';
// }

// int main()
// {

//     init();
//     int t;
//     cin >> t;
//     while (t--)
//         test();
//     print();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// stack<int> num;
// stack<char> op;
// unordered_map<char, int> wei;

// void calcu()
// {
//     char p = op.top();
//     int b = num.top();
//     num.pop();
//     int a = num.top();
//     num.pop();
//     op.pop();
//     if (p == '+')
//     {
//         // cout <<a << '+' <<b << '\n';
//         a += b;
//     }
//     else if (p == '-')
//     {
//         // cout <<a << '-' <<b << '\n';
//         a -= b;
//     }
//     else if (p == '*')
//     {
//         // cout <<a << '*' <<b << '\n';
//         a *= b;
//     }
//     else
//     {
//         // cout <<a << '/' <<b << '\n';
//         a /= b;
//     }
//     num.push(a);
// }

// int main()
// {
//     wei['+'] = wei['-'] = 1;
//     wei['*'] = wei['/'] = 2;

//     string s;
//     cin >> s;

//     for (int i = 0; i < s.size(); i++)
//     {
//         if (isdigit(s[i]))
//         {
//             int t = 0, j = i;
//             for (; j < s.size() && isdigit(s[j]); j++)
//             {
//                 t *= 10;
//                 t += s[j] - '0';
//             }
//             i = j - 1;
//             // cout << "push " << t << '\n';
//             num.push(t);
//         }
//         else
//         {
//             if (op.empty() || s[i] == '(')
//             {
//                 op.push(s[i]);
//             }
//             else
//             {
//                 if (s[i] == ')')
//                 {
//                     while (op.top() != '(')
//                         calcu();
//                     op.pop();
//                 }
//                 else if (wei[s[i]] > wei[op.top()])
//                     op.push(s[i]);
//                 else
//                 {
//                     while (!op.empty() && wei[op.top()] >= wei[s[i]])
//                         calcu();
//                     op.push(s[i]);
//                 }
//             }
//         }
//     }
//     while (op.size())
//         calcu();

//     cout << num.top();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 5;
// int n, k, a[N], que[N], head, tail;

// int main() {

//     cin >> n >> k;
//     for (int i = 1; i <= n; i++) cin >> a[i];

//     head = tail = 0;

//     for (int i = 1; i <= n; i++) {
//         if ((head % (k + 1)) != (tail % (k + 1)) && que[(head % (k + 1))] <= i - k) {head++; }
//         while ((head % (k + 1)) != (tail % (k + 1)) && a[que[((tail - 1) % (k + 1))]] > a[i])
//          tail--;
//         que[(tail % (k + 1))] = i;
//         tail++;
//         if (i >= k)
//             cout << a[que[(head % (k + 1))]] << ' ';
//     }

//     head = tail = 0;
//     cout << '\n';

//     for (int i = 1; i <= n; i++) {
//         if ((head % (k + 1)) != (tail % (k + 1)) && que[(head % (k + 1))] <= i - k) head++;
//         while ((head % (k + 1)) != (tail % (k + 1)) && a[que[((tail-1) % (k + 1))]] < a[i]) tail--;
//         que[(tail % (k + 1))] = i;
//         tail++;
//         if (i >= k)
//             cout << a[que[(head % (k + 1))]] << ' ';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// const int M = 1e6 + 5;
// char s[M], p[N];
// int ne[N], n, m;

// int main()
// {

//     cin >> n >> p + 1 >> m >> s + 1;

//     for (int i = 2, j = 0; i <= n; i++)
//     {
//         while (j && p[i] != p[j + 1])
//             j = ne[j];
//         if (p[i] == p[j + 1])
//             j++;
//         ne[i] = j;
//     }

//     for (int i = 1, j = 0; i <= m; i++)
//     {
//         while (j && s[i] != p[j + 1])
//             j = ne[j];
//         if (s[i] == p[j + 1])
//             j++;
//         if (j == n)
//             cout << i - n << ' ';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;

// int son[N][26], cnt[N], idx;

// void insert(const char s[])
// {
//     int p = 0;
//     for (int i = 0; s[i]; i++)
//     {
//         int ne = s[i] - 'a';
//         if (!son[p][ne])
//             son[p][ne] = ++idx;
//         p = son[p][ne];
//     }
//     cnt[p]++;
// }

// int query(const char s[])
// {
//     int p = 0;
//     for (int i = 0; s[i]; i++)
//     {
//         int ne = s[i] - 'a';
//         if (!son[p][ne])
//             return 0;
//         p = son[p][ne];
//     }
//     return cnt[p];
// }

// int main()
// {
//     int t;
//     cin >> t;
//     string a, b;
//     while (t--)
//     {
//         cin >> a >> b;
//         if (a[0] == 'I')
//         {
//             insert(b.c_str());
//         }
//         else
//         {
//             cout << query(b.c_str()) << '\n';
//         }
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;

// int son[N * 31][2], idx, n, a[N];

// void insert(int x)
// {
//     int p = 1, num[32] = {0};
//     while (x)
//     {
//         if (x & 1)
//             num[p] = 1;
//         x /= 2;
//         p++;
//     }
//     p = 0;
//     for (int i = 31; i >= 1; i--)
//     {
//         if (!son[p][num[i]])
//             son[p][num[i]] = ++idx;
//         p = son[p][num[i]];
//     }
// }

// int find(int x)
// {
//     int p = 1, num[32] = {0};
//     while (x)
//     {
//         if (x & 1)
//             num[p] = 1;
//         x /= 2;
//         p++;
//     }
//     p = 0;
//     int ret = 0;
//     for (int i = 31; i >= 1; i--)
//     {
//         ret *= 2;
//         int ne = num[i] ^ 1;
//         if (son[p][ne])
//         {
//             p = son[p][ne];
//             ret++;
//         }
//         else
//         {
//             p = son[p][num[i]];
//         }
//     }

//     return ret;
// }

// int main()
// {

//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         insert(a[i]);
//     }

//     int ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         ans = max(ans, find(a[i]));
//     }

//     cout << ans << '\n';

//     return 0;
// }

// #include <iostream>
// using namespace std;
// const int N = 5e4 + 5;
// int n, m, fa[N], a, b, c, d[N];

// int find(int x)
// {
//     if (x != fa[x])
//     {
//         int t = find(fa[x]);
//         d[x] += d[fa[x]];
//         fa[x] = t;
//     }
//     return fa[x];
// }

// int main()
// {

//     ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         fa[i] = i;
//     int ans = 0;
//     while (m--)
//     {
//         cin >> c >> a >> b;
//         if (a > n || b > n)
//         {
//             ans++;
//             continue;
//         }
//         if (c == 1)
//         {
//             int af = find(a);
//             int bf = find(b);
//             if (af == bf)
//             {
//                 if ((d[a] - d[b]) % 3)
//                     ans++;
//             }
//             else
//             {
//                 fa[af] = bf;
//                 d[af] -= (d[a] - d[b]) % 3;
//             }
//         }
//         else
//         {
//             int af = find(a);
//             int bf = find(b);
//             if (af == bf)
//             {
//                 if ((d[a] - d[b] - 1) % 3)
//                     ans++;
//             }
//             else
//             {
//                 fa[af] = bf;
//                 d[af] -= (d[a] - d[b] - 1) % 3;
//             }
//         }
//     }
//     cout << ans << '\n';

//     return 0;
// }

// #include<iostream>
// using namespace std;
// const int N = 1e5 + 5;

// int n, m, d[N], siz;

// void down(int x) {
//     int child = (x << 1) + 1;
//     while (child < siz) {
//         if (d[child] <= d[x]) child++;
//         if (child < siz && d[child] > d[x]) swap(d[child], d[x]);
//         else break;
//         x = child;
//         child = (x << 1) + 1;
//     }
// }

// void heap_sort() {
//     siz = n;
//     for (int i = (n - 2) >> 1; i >= 0; i--) //向下调整建大根堆
//         down(i);

//     while (--siz) {
//         swap(d[siz], d[0]);
//         down(0);
//     }
// }

// int main() {

//     cin >> n >> m;
//     for (int i = 0; i < n; i++) {
//         cin >> d[i];
//     }

//     heap_sort();

//     for (int i = 0; i < m; i++)
//         cout << d[i] << ' ';
//     cout << '\n';

//     return 0;
// }

// 模拟堆，push,pop,remove,change
//  #include <iostream>
//  using namespace std;
//  const int N = 1e5 + 5;
//  int a[N], siz, cnt = 1, num[N], p[N];

// void __swap(int i1, int i2)
// {
//     swap(a[i1], a[i2]);
//     swap(num[p[i1]], num[p[i2]]);
//     swap(p[i1], p[i2]);
// }

// void up(int x)
// {
//     int fa;
//     while (x)
//     {
//         fa = (x - 1) >> 1;
//         if (a[x] < a[fa])
//             __swap(x, fa);
//         else
//             break;
//         x = fa;
//     }
// }

// void down(int x)
// {
//     int son = (x << 1) + 1;
//     while (son < siz)
//     {
//         if (son + 1 < siz && a[son] > a[son + 1])
//             son++;
//         if (a[x] > a[son])
//             __swap(x, son);
//         else
//             break;
//         x = son;
//         son = (x << 1) + 1;
//     }
// }

// void push(int x)
// {
//     a[siz] = x;
//     p[siz] = cnt;
//     num[cnt++] = siz;
//     up(siz++);
// }

// void pop()
// {
//     __swap(0, --siz);
//     down(0);
// }

// void remove(int k)
// {
//     int x = num[k];
//     __swap(x, --siz);
//     down(x);
//     up(x);
// }

// void change(int k, int v)
// {
//     int x = num[k];
//     a[x] = v;
//     up(x);
//     down(x);
// }

// int main()
// {

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         string s;
//         cin >> s;
//         if (s[0] == 'I')
//         {
//             int x;
//             cin >> x;
//             push(x);
//         }
//         else if (s[0] == 'P')
//         {
//             cout << a[0] << '\n';
//         }
//         else if (s == "DM")
//         {
//             pop();
//         }
//         else if (s[0] == 'D')
//         {
//             int k;
//             cin >> k;
//             remove(k);
//         }
//         else
//         {
//             int k, x;
//             cin >> k >> x;
//             change(k, x);
//         }
//     }

//     return 0;
// }

// 拉链法哈希表
//  #include <iostream>
//  using namespace std;
//  const int N = 100003;

// int h[N], n, a[N], ne[N], x, idx = 1;

// void insert(int x)
// {
//     int k = (x % N + N) % N;
//     a[idx] = x;
//     ne[idx] = h[k];
//     h[k] = idx++;
// }

// bool find(int x)
// {
//     int k = (x % N + N) % N;
//     int cur = h[k];
//     while (cur)
//     {
//         if (a[cur] == x)
//             return true;
//         cur = ne[cur];
//     }
//     return false;
// }

// int main()
// {

//     cin >> n;
//     while (n--)
//     {
//         char s[2];
//         cin >> s >> x;
//         if (s[0] == 'I')
//         {
//             insert(x);
//         }
//         else
//         {
//             if (find(x))
//                 cout << "Yes\n";
//             else
//                 cout << "No\n";
//         }
//     }

//     return 0;
// }

// 开放寻址法哈希表
//  #include <iostream>
//  #include <cstring>
//  using namespace std;
//  const int N = 200003;
//  const int nul = 0x3f3f3f3f;

// int h[N], n, x;

// int find(int x)
// {
//     int k = (x % N + N) % N;
//     while (h[k] != nul && h[k] != x)
//     {
//         k++;
//     }
//     return k;
// }

// int main()
// {

//     memset(h, 0x3f, sizeof(h));
//     cin >> n;
//     while (n--)
//     {
//         char s[2];
//         cin >> s >> x;
//         if (s[0] == 'I')
//         {
//             int k = find(x);
//             if (h[k] == nul)
//                 h[k] = x;
//         }
//         else
//         {
//             if (h[find(x)] == x)
//                 cout << "Yes\n";
//             else
//                 cout << "No\n";
//         }
//     }

//     return 0;
// }
//

// test

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     cout << "test\n";

//     return 0;
// }

// test

// vsocde

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 55;
// int n, m, a[N], b[N];

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int s1 = 0, s2 = 0;
//         cin >> n >> m;
//         for (int i = 1; i <= n; i++)
//             cin >> a[i], s1 += a[i];
//         for (int i = 1; i <= m; i++)
//             cin >> b[i], s2 += b[i];

//         if (s1 > s2)
//             cout << "Tsondu\n";
//         else if (s1 == s2)
//             cout << "Draw\n";
//         else
//             cout << "Tenzing\n";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 5;
// int n, m, a[N], b[N], c[N], x;

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int ans = 0;
//         cin >> n >> x;
//         for (int i = 1; i <= n; i++)
//             cin >> a[i];
//         for (int i = 1; i <= n; i++)
//             cin >> b[i];
//         for (int i = 1; i <= n; i++)
//             cin >> c[i];

//         for (int i = 1; i <= n; i++)
//         {
//             if ((x | a[i]) != x)
//                 break;
//             // cout << a[i] << ' ';
//             ans |= a[i];
//         }
//         // cout << "\n____________\n";
//         for (int i = 1; i <= n; i++)
//         {
//             if ((x | b[i]) != x)
//                 break;
//             // cout << b[i] << ' ';
//             ans |= b[i];
//         }
//         // cout << "\n____________\n";
//         for (int i = 1; i <= n; i++)
//         {
//             if ((x | c[i]) != x)
//                 break;
//             // cout << c[i] << ' ';
//             ans |= c[i];
//         }
//         // cout << "\n____________\n";

//         if (ans == x)
//             cout << "Yes\n";
//         else
//             cout << "No\n";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 5;
// int n, m, a[N];

// signed main()
// {
//     srand(time(0));
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         a[i] = 1 + (rand() % n);
//         cout << a[i] << ' ';
//     }

//     return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;
// #define int long long
// const int N = 2e5 + 5;
// int n, a[N], dp[N], lastp[N];

// signed main()
// {

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         memset(lastp, 0, sizeof(lastp));
//         memset(dp, 0, sizeof(dp));
//         for (int i = 1; i <= n; i++)
//             cin >> a[i];
//         for (int i = 1; i <= n; i++)
//         {
//             dp[i] = dp[i - 1] + 1;
//             if (lastp[a[i]])
//             {
//                 dp[i] = min(dp[i], dp[lastp[a[i]] - 1]);
//                 if (dp[lastp[a[i]] - 1] > dp[i - 1])
//                     lastp[a[i]] = i;
//             }
//             else
//                 lastp[a[i]] = i;
//         }
//         cout << n - dp[n] << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 5;
// int n, m, k, x;

// signed main()
// {

//     int t = 1;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> k >> x;
//         if (x != 1)
//         {
//             cout << "YES\n";
//             cout << n << '\n';
//             while (n--)
//                 cout << "1 ";
//             cout << '\n';
//         }
//         else // 禁1
//         {
//             if (k == 1)
//             {
//                 cout << "NO\n";
//             }
//             else
//             {
//                 if (n == 1)
//                 {
//                     cout << "NO\n";
//                 }
//                 else
//                 {

//                     if (n & 1)
//                     {
//                         if (k >= 3)
//                         {
//                             cout << "YES\n"
//                                  << n / 2 << '\n';
//                             cout << 3 << ' ';
//                             n -= 3;
//                             while (n)
//                             {
//                                 cout << 2 << ' ';
//                                 n -= 2;
//                             }
//                             cout << "\n";
//                         }
//                         else
//                         {
//                             cout << "NO\n";
//                         }
//                     }
//                     else
//                     {
//                         cout << "YES\n"
//                              << n / 2 << '\n';
//                         while (n)
//                         {
//                             cout << "2 ";
//                             n -= 2;
//                         }
//                         cout << "\n";
//                     }
//                 }
//             }
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 5;
// int xa, ya, xb, yb, xc, yc;

// signed main()
// {

//     int t = 1;
//     cin >> t;
//     while (t--)
//     {
//         cin >> xa >> ya >> xb >> yb >> xc >> yc;
//         xb -= xa;
//         yb -= ya;
//         xc -= xa;
//         yc -= ya;
//         int ans = 1;
//         if (xb * xc > 0)
//         {
//             // cout << "*1 ";
//             // ans = max(ans, min(abs(xb), abs(xc)) + 1);
//             ans += min(abs(xb), abs(xc));
//         }
//         if (yb * yc > 0)
//         {
//             // cout << "*2 ";
//             // ans = max(ans, min(abs(yb), abs(yc)) + 1);
//             ans += min(abs(yb), abs(yc));
//         }
//         cout << ans << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 3e5 + 5;
// int n, a[N], lim[N], m[N], f[N];

// signed main()
// {

//     int t = 1;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;

//         for (int i = 1; i <= n; i++)
//             cin >> a[i], lim[i] = m[i] = f[i] = 0;
//         for (int i = 1; i <= n; i++)
//             if (a[i] > 0)
//             {
//                 lim[i] = lim[i - 1];
//                 f[i] = f[i - 1];
//                 m[i] = m[i - 1] + a[i];
//             }
//             else
//             {
//                 int ori = m[i - 1] + a[i] < lim[i - 1] ? lim[i - 1] : m[i - 1] + a[i];
//                 int chg = m[i - 1] + f[i - 1];
//                 if (chg > ori)
//                 {
//                     m[i] = chg;
//                     lim[i] = chg;
//                     f[i] = a[i];
//                 }
//                 else
//                 {
//                     m[i] = ori;
//                     lim[i] = lim[i - 1];
//                     // cout << "* " << i << ' ' << f[i] << ' ';
//                     f[i] = f[i - 1] + a[i];
//                     // cout << f[i] << '\n';
//                 }
//             }
//         // for (int i = 1; i <= n; i++)
//         // {
//         //     cout << lim[i] << ' ' << f[i] << ' ' << m[i] << '\n';
//         // }
//         cout << lim[n] << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 3e5 + 5;
// int m, ans, len, ffr[10][N];
// string s, l, r;

// void dfs(int p, int it)
// {
//     while (l[p] <= r[p] && ans)
//     {
//         if (ffr[l[p] - '0'][it])
//         {
//             if (p + 1 < m)
//                 dfs(p + 1, ffr[l[p] - '0'][it] + 1);
//         }
//         else
//             ans = 0;
//         l[p]++;
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         ans = 1;

//         cin >> s >> m >> l >> r;
//         len = s.length();
//         s = ' ' + s;
//         int lt[10] = {0};
//         for (int i = 1; i <= len; i++)
//         {
//             int k = s[i] - '0';
//             for (int j = lt[k]; j <= i; j++)
//                 ffr[k][j] = i;
//             lt[k] = i + 1;
//         }
//         for (int i = 0; i < 10; i++)
//         {
//             for (int j = lt[i]; j <= len; j++)
//                 ffr[i][j] = 0;
//         }
//         dfs(0, 1);
//         if (ans)
//             cout << "NO\n";
//         else
//             cout << "YES\n";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 3e5 + 5;
// int m, ffr[10][N], len;
// string s, l, r;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> s >> m >> l >> r;
//         len = s.size();
//         s = ' ' + s;
//         for (int i = 0; i < 10; i++)
//             ffr[i][len + 1] = 0;
//         for (int i = len; i >= 1; i--)
//         {
//             for (int j = 0; j < 10; j++)
//                 ffr[j][i] = ffr[j][i + 1];
//             ffr[s[i] - '0'][i] = i;
//         }
//         int it = 1, ans = 1;
//         for (int i = 0; i < m && ans; i++)
//         {
//             int mx = 0;
//             for (int ll = l[i] - '0', rr = r[i] - '0'; ll <= rr; ll++)
//             {
//                 if (ffr[ll][it])
//                     mx = max(mx, ffr[ll][it]);
//                 else
//                 {
//                     ans = 0;
//                     break;
//                 }
//             }
//             it = mx + 1;
//         }
//         if (ans)
//             cout << "NO\n";
//         else
//             cout << "YES\n";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 3e5 + 5;
// int n, a[N], sum[N];

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         int mx = 0, delt = 0, ans;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> a[i];
//             sum[i] = sum[i - 1] + a[i];
//             mx = max(mx, sum[i]);
//             if (mx - sum[i] > delt)
//             {
//                 delt = mx - sum[i];
//                 ans = mx;
//             }
//         }
//         cout << ans << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// const int N = 650000;
// int n, a[N], s, t, d[N], vis[N], psize = 0;
// vector<pair<int, int>> vec[N];
// int pre[N];
// bool isprim[N];
// int prim[30000];

// void precal()
// {
//     for (int i = 2; i < N; i++)
//         isprim[i] = true;
//     for (int i = 2; i < N; i++)
//     {
//         if (isprim[i])
//             prim[++psize] = i;
//         for (int j = 1; j <= psize && i * prim[j] < N; j++)
//         {
//             isprim[i * prim[j]] = false;
//             if (i % prim[j] == 0)
//                 break;
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//     // precal();
//     memset(d, 0x3f, sizeof(d));
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         int tmp = a[i];
//         for (int j = 2; j <= tmp / j; ++j)
//         {
//             if (tmp % j == 0)
//             {
//                 vec[n + j].push_back({i, 1});
//                 vec[i].push_back({n + j, 0});
//                 while (tmp % j == 0)
//                     tmp /= j;
//             }
//         }
//         if (tmp > 1)
//         {
//             vec[n + tmp].push_back({i, 1});
//             vec[i].push_back({n + tmp, 0});
//         }
//     }
//     cin >> s >> t;

//     d[s] = 0;
//     d[0]++;
//     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
//     q.push({0, {s, s}});
//     while (q.size())
//     {
//         int u = q.top().second.second;
//         pre[u] = q.top().second.first;
//         q.pop();
//         if (vis[u])
//             continue;
//         vis[u] = 1;
//         if (u == t)
//             break;
//         for (auto [v, w] : vec[u])
//             if (d[u] + w < d[v])
//             {
//                 d[v] = d[u] + w;
//                 q.push({d[v], {u, v}});
//             }
//     }

//     if (d[t] == 0x3f3f3f3f)
//         cout << -1;
//     else
//     {
//         cout << d[t] + 1 << '\n';
//         stack<int> st;
//         int cur = t;
//         while (cur != pre[cur])
//         {
//             if (cur <= n)
//                 st.push(cur);
//             cur = pre[cur];
//         }
//         st.push(cur);
//         while (st.size())
//         {
//             cout << st.top() << ' ';
//             st.pop();
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 5e5 + 5;
// int n, m, a[N];
// struct node
// {
//     pair<int, int> pi;
//     int v;
// };
// node nd[N];

// int tree[N << 2];

// void up(int id)
// {
//     tree[id] = a[tree[id << 1]] < a[tree[id << 1 | 1]] ? tree[id << 1] : tree[id << 1 | 1];
// }

// void build(int id, int l, int r)
// {
//     if (l == r)
//     {
//         tree[id] = l;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(id << 1, l, mid);
//     build(id << 1 | 1, mid + 1, r);
//     up(id);
// }

// int getmin(int id, int l, int r, int ql, int qr)
// {
//     if (l >= ql && r <= qr)
//         return tree[id];
//     int mid = l + r >> 1;
//     if (qr <= mid)
//         return getmin(id << 1, l, mid, ql, qr);
//     else if (ql > mid)
//         return getmin(id << 1 | 1, mid + 1, r, ql, qr);
//     else
//     {
//         int m1 = getmin(id << 1, l, mid, ql, qr);
//         int m2 = getmin(id << 1 | 1, mid + 1, r, ql, qr);
//         return a[m1] < a[m2] ? m1 : m2;
//     }
// }

// int tr[N];

// int lowbit(int x)
// {
//     return x & -x;
// }

// void add(int x, int v)
// {
//     while (x <= n)
//     {
//         tr[x] += v;
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

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int ans = 0;
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//             cin >> a[i], tr[i] = 0;
//         build(1, 1, n);
//         cin >> m;
//         for (int i = 1; i <= m; i++)
//             cin >> nd[i].pi.first >> nd[i].pi.second, nd[i].v = 0;
//         sort(nd + 1, nd + 1 + m, [](node e1, node e2) -> int
//              { return e1.pi.second - e1.pi.first < e2.pi.second - e2.pi.first; });
//         for (int i = 1; i <= m; i++)
//         {
//             if (getsum(nd[i].pi.second) - getsum(nd[i].pi.first - 1) == 0)
//             {
//                 int p = getmin(1, 1, n, nd[i].pi.first, nd[i].pi.second);
//                 nd[i].v = a[p];
//                 // ans += a[p];
//                 add(p, 1);
//             }
//         }
//         sort(nd + 1, nd + 1 + m, [](node e1, node e2) -> int
//              { if(e1.pi.first == e2.pi.first)
//                 return e1.pi.second < e2.pi.second;
//                 return e1.pi.first < e2.pi.first; });
//         for (int i = 1; i < m; i++)
//         {
//             if (nd[i].pi.second >= nd[i + 1].pi.first)
//             {
//                 int p = getmin(1, 1, n, nd[i + 1].pi.first, min(nd[i].pi.second, nd[i + 1].pi.second));
//                 // nd[i + 1].pi.first = nd[i].pi.first;
//                 nd[i + 1].pi.second = min(nd[i].pi.second, nd[i + 1].pi.second);
//                 nd[i + 1].v += nd[i].v;
//                 nd[i].v = 0;
//                 nd[i + 1].v = min(nd[i + 1].v, a[p]);
//             }
//         }
//         for (int i = 1; i <= m; i++)
//             ans += nd[i].v;
//         cout << ans << '\n';
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e4 + 5;
// int n, dep[N], par[N][20], dis[N][20];
// vector<pair<int, int>> vec[N];

// void dfs(int u, int fa)
// {
//     dep[u] = dep[fa] + 1;
//     par[u][0] = fa;
//     for (int i = 1; i < 20; i++)
//     {
//         par[u][i] = par[par[u][i - 1]][i - 1];
//         dis[u][i] = dis[u][i - 1] + dis[par[u][i - 1]][i - 1];
//     }
//     for (auto [v, w] : vec[u])
//         if (v != fa)
//         {
//             dis[v][0] = w;
//             dfs(v, u);
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
//             ret += dis[u][i] + dis[v][i];
//             u = par[u][i];
//             v = par[v][i];
//         }
//     ret += dis[u][0] + dis[v][0];
//     return ret;
// }

// int lca(int u, int v)
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

// int getkth(int u, int v, int k)
// {
//     int ca = lca(u, v);
//     if (ca == u || ca == v)
//     {
//         if (u == ca)
//         {
//             int len = dep[v] - dep[u] + 1;
//             k = len - k + 1;
//             swap(u, v);
//         }
//     }
//     else
//     {
//         if (k > dep[u])
//         {
//             k -= dep[u];
//             k = dep[v] - k;
//             swap(u, v);
//         }
//     }
//     k--;
//     int jp = 0;
//     while (k)
//     {
//         if (1 & k)
//             u = par[u][jp];
//         jp++;
//         k /= 2;
//     }
//     return u;
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     int a, b, c;
//     while (t--)
//     {
//         cin >> n;
//         for (int i = 0; i <= n; i++)
//         {
//             vec[i].clear();
//             dep[i] = 0;
//             for (int j = 0; j < 20; j++)
//                 par[i][j] = dis[i][j] = 0;
//         }
//         for (int i = 1; i < n; i++)
//         {
//             cin >> a >> b >> c;
//             vec[a].push_back({b, c});
//             vec[b].push_back({a, c});
//         }
//         dfs(1, 0);
//         string k;
//         while (cin >> k, k != "DONE")
//         {
//             if (k[0] == 'D')
//             {
//                 cin >> a >> b;
//                 cout << getdis(a, b) << '\n';
//             }
//             else
//             {
//                 cin >> a >> b >> c;
//                 cout << getkth(a, b, c) << '\n';
//             }
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e4 + 5;
// int n, dis, kth, dep[N], par[N][20], tohead[N];
// vector<pair<int, int>> vec[N];

// void dfs(int u, int fa)
// {
//     dep[u] = dep[fa] + 1;
//     par[u][0] = fa;
//     for (int i = 1; i < 20; ++i)
//     {
//         par[u][i] = par[par[u][i - 1]][i - 1];
//     }
//     for (auto [v, w] : vec[u])
//     {
//         if (v == fa)
//             continue;
//         tohead[v] = tohead[u] + w;
//         dfs(v, u);
//     }
// }

// int lca(int u, int v)
// {
//     if (dep[u] < dep[v])
//         swap(u, v);
//     for (int i = 19; i >= 0; --i)
//     {
//         if (dep[par[u][i]] >= dep[v])
//             u = par[u][i];
//     }
//     if (u == v)
//         return u;
//     for (int i = 19; i >= 0; --i)
//     {
//         if (par[u][i] != par[v][i])
//         {
//             u = par[u][i], v = par[v][i];
//         }
//     }
//     return par[u][0];
// }
// int getkth(int u, int v, int k)
// {
//     int ca = lca(u, v);
//     // if (ca == u || ca == v)
//     // {
//     //     if (u == ca)
//     //     {
//     //         int len = dep[v] - dep[u] + 1;
//     //         k = len - k + 1;
//     //         swap(u, v);
//     //     }
//     // }
//     // else
//     // {
//     //     if (k > dep[u])
//     //     {
//     //         k -= dep[u];
//     //         k = dep[v] - k;
//     //         swap(u, v);
//     //     }
//     // }
//     int h1 = dep[u] - dep[ca] + 1;
//     int h2 = dep[v] - dep[ca] + 1;
//     if (k > h1)
//     {
//         k -= h1;
//         k = h2 - k;
//         swap(v, u);
//     }
//     k--;
//     int jp = 0;
//     while (k)
//     {
//         if (1 & k)
//             u = par[u][jp];
//         jp++;
//         k /= 2;
//     }
//     return u;
// }

// void solve()
// {
//     cin >> n;
//     int a, b, c;
//     for (int i = 0; i <= n; i++)
//         vec[i].clear();
//     for (int i = 1; i < n; i++)
//     {
//         cin >> a >> b >> c;
//         vec[a].push_back({b, c});
//         vec[b].push_back({a, c});
//     }
//     dfs(1, 0);
//     string s;
//     while (cin >> s, s != "DONE")
//     {
//         if (s[0] == 'D')
//         {
//             cin >> a >> b;
//             int ca = lca(a, b);
//             cout << (tohead[a] + tohead[b] - 2 * tohead[ca]) << '\n';
//         }
//         else
//         {
//             cin >> a >> b >> c;
//             cout << getkth(a, b, c) << '\n';
//         }
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