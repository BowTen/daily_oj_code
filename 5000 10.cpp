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

#include <bits/stdc++.h>
using namespace std;
const int P = 100000007;
int n;
#define int long long
int fast(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = 1ll * res * a % P;
        a = 1ll * a * a % P;
        b >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int pw = 1;
    for (int i = 1; i < n; i++)
        pw *= 2, pw %= P;
    int ans = 0;
    for (int i = 1, tmp; i <= n; i++)
    {
        cin >> tmp;
        ans += (tmp * pw) % P;
    }
    // cout << (ans * ((int)pow(n, P - 2) % P)) % P;
    cout << ans;

    return 0;
}
