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

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
const int N = 1e5 + 5;
int n, q, k, d[N], die[N], ad;

int lowbit(int x)
{
    return x & -x;
}

int getsum(int x)
{
    int ret = 0;
    while (x)
    {
        ret += d[x];
        x -= lowbit(x);
    }
    return ret;
}

void add(int x, int v)
{
    while (x <= n)
    {
        d[x] += v;
        x += lowbit(x);
    }
}

signed main()
{
    IO;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    int cur = 0, t;
    // add(1, 2);
    // add(3, 3);
    // cout << getsum(1) << ' ';
    // cout << getsum(3);
    while (q--)
    {
        cin >> k;
        while (k)
        {
            int ne = (cur + k - 1);
            int rou = (ne - cur) / k;
            int mor = ad * rou;
            if ((ne % n) < cur)
                mor += getsum(ne % n);
            else
                mor += getsum(ne % n) - getsum(cur);
            k = mor;
            cur = ne % n;
            cout << k << ' ';
        }
        cout << a[cur] << '\n';
        ad++;
        add(cur, 1);
    }

    return 0;
}