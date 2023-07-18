// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int a, b, c;
//     cin >> a >> b;
//     cout << "1| " << a << '\n'
//          << "2| " << b << '\n';
//     for (int i = 3; 1; i++)
//     {
//         c = abs(a - b);
//         cout << i << "| " << c << '\n';
//         a = b;
//         b = c;
//         if (!b)
//             break;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 5e5 + 10;
// int n, m, a[N], pre[N];

// signed main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         pre[i] = pre[i - 1] + a[i];
//         // cout << pre[i] << ' ';
//     }
//     if (pre[n] % 3)
//     {
//         cout << 0;
//         return 0;
//     }
//     int l = pre[n] / 3;
//     int r = l * 2;
//     int ls = 0;
//     int ans = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if (pre[i] == r)
//         {
//             ans += ls;
//             // cout << "ans += ls\n";
//         }
//         if (pre[i] == l)
//         {
//             ls++;
//             // cout << "ls++\n";
//         }
//     }
//     cout << ans;
//     // cout << l << ' ' << r << ' ' << ls;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, m, a[N];

// void solve()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     if (a[1] == a[n])
//     {
//         m = 1;
//         for (int i = 2; i <= n; i++)
//             if (a[i] > a[i - 1])
//                 m++;
//             else
//                 break;
//         if (m & 1)
//         {
//             cout << "Alice";
//             return;
//         }

//         m = 1;
//         for (int i = n - 1; i >= 1; i--)
//             if (a[i] > a[i + 1])
//                 m++;
//             else
//                 break;
//         if (m & 1)
//         {
//             cout << "Alice";
//             return;
//         }
//         else
//         {
//             cout << "Bob";
//             return;
//         }
//     }
//     else if (a[1] > a[n])
//     {
//         m = 1;
//         for (int i = 2; i <= n; i++)
//             if (a[i] > a[i - 1])
//                 m++;
//             else
//                 break;
//         if (m & 1)
//         {
//             cout << "Alice";
//             return;
//         }

//         int cnt = 1;
//         for (int i = n - 1; i >= 1; i--)
//             if (a[i] > a[i + 1])
//                 cnt++;
//             else
//                 break;

//         if (cnt & 1)
//         {
//             cout << "Alice";
//             return;
//         }
//         else
//         {
//             cout << "Bob";
//             return;
//         }
//     }
//     else if (a[1] < a[n])
//     {
//         m = 1;
//         for (int i = n - 1; i >= 1; i--)
//             if (a[i] > a[i + 1])
//                 m++;
//             else
//                 break;
//         if (m & 1)
//         {
//             cout << "Alice";
//             return;
//         }

//         int cnt = 1;
//         for (int i = 2; i <= n; i++)
//             if (a[i] > a[i - 1])
//                 cnt++;
//             else
//                 break;

//         if (cnt & 1)
//         {
//             cout << "Alice";
//             return;
//         }
//         else
//         {
//             cout << "Bob";
//             return;
//         }
//     }
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
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// int n, q;
// string s;

// typedef array<int, 27> chas;

// chas tr[N << 2];
// chas operator+(const chas a1, const chas a2)
// {
//     chas ret = a1;
//     for (int i = 0; i < 27; i++)
//         ret[i] += a2[i];
//     return ret;
// }
// void up(int id)
// {
//     tr[id] = tr[lson] + tr[rson];
// }
// void build(int id, int l, int r)
// {
//     if (l == r)
//     {
//         tr[id][s[l] - 'a' + 1] = 1;
//         // cout << "tr[" << l << "][" << (int)(s[l] - 'a' + 1) << "] " << l << ' ' << s[l] - 'a' + 1 << '\n';
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// void change(int id, int l, int r, int x, char c)
// {
//     if (l == r)
//     {
//         tr[id][s[x] - 'a' + 1] = 0;
//         s[x] = c;
//         tr[id][s[x] - 'a' + 1] = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     if (x <= mid)
//         change(lson, l, mid, x, c);
//     else
//         change(rson, mid + 1, r, x, c);
//     up(id);
// }
// chas query(int id, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//         return tr[id];
//     int mid = l + r >> 1;
//     if (qr <= mid)
//         return query(lson, l, mid, ql, qr);
//     else if (ql > mid)
//         return query(rson, mid + 1, r, ql, qr);
//     else
//         return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
// }

// int fac[N];
// int inv[N];

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

// void init()
// {
//     fac[0] = 1;
//     inv[0] = 1;
//     for (int i = 1; i < N; i++)
//     {
//         fac[i] = (fac[i - 1] * i) % mod;
//         inv[i] = inv[i - 1] * qpow(i, mod - 2, mod) % mod;
//         // inv[i] = qpow(fac[i], mod - 2, mod);
//     }
// }

// signed main()
// {
//     init();
//     cin >> n >> q >> s;
//     s = ' ' + s;
//     build(1, 1, n);

//     while (q--)
//     {
//         int op, x, l, r;
//         char y;
//         cin >> op;
//         if (op == 1)
//         {
//             cin >> x >> y;
//             x++;
//             change(1, 1, n, x, y);
//         }
//         else
//         {
//             cin >> l >> r;
//             l++;
//             r++;
//             chas ans = query(1, 1, n, l, r);
//             int cnt = 0, len = r - l + 1;
//             for (int i = 1; i <= 26; i++)
//             {
//                 if (ans[i] & 1)
//                     cnt++;
//                 ans[i] /= 2;
//             }
//             if (cnt != (len & 1))
//             {
//                 cout << "0\n";
//                 continue;
//             }
//             len /= 2;
//             int ret = fac[len] % mod;
//             for (int i = 1; i <= 26; i++)
//                 if (ans[i])
//                     ret = (ret * inv[ans[i]]) % mod;
//             cout << ret << '\n';
//         }
//     }
//     // chas ans = query(1, 1, n, 1, 5);
//     // for (int i = 1; i <= n; i++)
//     // {
//     //     cout << (char)('a' + i - 1) << ' ' << ans[i] << '\n';
//     // }
//     // cout << n << ' ' << q << ' ' << s;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// int n, q;
// string s;

// typedef array<int, 27> chas;

// int fac[N];
// void init()
// {
//     fac[1] = 1;
//     for (int i = 2; i < N; i++)
//     {
//         fac[i] = (fac[i - 1] * i) % mod;
//     }
// }

// signed main()
// {
//     init();
//     cin >> n >> q >> s;
//     s = ' ' + s;

//     while (q--)
//     {
//         int op, x, l, r;
//         char y;
//         cin >> op;
//         if (op == 1)
//         {
//             cin >> x >> y;
//             x++;
//             change(1, 1, n, x, y);
//         }
//         else
//         {
//             cin >> l >> r;
//             l++;
//             r++;
//             chas ans = query(1, 1, n, l, r);
//             int cnt = 0, len = r - l + 1;
//             for (int i = 1; i <= 26; i++)
//             {
//                 if (ans[i] & 1)
//                     cnt++;
//                 ans[i] /= 2;
//             }
//             if (cnt != (len & 1))
//             {
//                 cout << "0\n";
//                 continue;
//             }
//             len /= 2;
//             int ret = fac[len] % mod;
//             for (int i = 1; i <= 26; i++)
//                 if (ans[i])
//                     ret = (ret / fac[ans[i]]) % mod;
//             cout << ret << '\n';
//         }
//     }
//     return 0;
// }