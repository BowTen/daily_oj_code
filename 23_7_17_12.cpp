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

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// int n, q;
// string s;

// //快速幂
// int qpow(int a, int k, int p){
//     int ret = 1;
//     while(k){
//         if(k & 1) ret = a * ret % p;
//         a = a * a % p;
//         k >>= 1;
//     }
//     return ret;
// }

// //阶乘、逆元
// int fac[N], inv[N];
// void get_inv(){
//     inv[0] = fac[0] = 1;
//     for(int i = 1;i < N;i++){
//         fac[i] = fac[i-1] * i % mod;
//         inv[i] = inv[i-1] * qpow(i, mod - 2, mod) % mod;
//     }
// }

// //树状数组
// int tr[27][N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int c, int x, int v){
//     if(!x) return;
//     c = c - 'a' + 1;
//     while(x <= n){
//         tr[c][x] += v;
//         x += lowbit(x);
//     }
// }
// int getans(int l, int r){
//     int len = r - l + 1;
//     int cnt[27] = {0};
//     for(int i = 1;i <= 26;i++){
//         int x = r;
//         while(x > 0){
//             cnt[i] += tr[i][x];
//             x -= lowbit(x);
//         }
//     }
//     for(int i = 1;i <= 26;i++){
//         int x = l-1;
//         while(x > 0){
//             cnt[i] -= tr[i][x];
//             x -= lowbit(x);
//         }
//     }
//     int f = 0;
//     for(int i = 1;i <= 26;i++){
//         if(cnt[i] & 1) f ++;
//         cnt[i] /= 2;
//     }
//     if(f != (len & 1)) return 0;
//     len /= 2;
//     int ret = fac[len];
//     for(int i = 1;i <= 26;i++)if(cnt[i]){
//         ret = ret * inv[cnt[i]] % mod;
//     }
//     return ret;

// }

// signed main(){

//     get_inv();

//     cin >> n >> q >> s;
//     s = ' ' + s;
//     for(int i = 1;i <= n;i++)
//         add(s[i], i, 1);

//     while(q--){
//         int op, l, r, x;
//         char y;
//         cin >> op;
//         if(op == 1){
//             cin >> x >> y;
//             x++;
//             add(s[x], x, -1);
//             s[x] = y;
//             add(s[x], x, 1);
//         }else{
//             cin >> l >> r;
//             l ++;
//             r ++;
//             cout << getans(l, r) << '\n';
//         }
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 5;
// int n,m, a[N], b[N];

// int get_pos(int x, int y){
//     int z = abs(x-y);
//     int mn = y, cnt = 0, ret = 1;
//     while(z){
//         x = y;
//         y = z;
//         z = abs(x-y);
//         ret++;
//         if(mn == z) cnt++;
//         else if(z < mn) mn = z, cnt = 0;
//         if(cnt >= 3){
//             int tmp = y / (2*mn);
//             y -= tmp*2*mn;
//             x -= tmp*2*mn;
//             cnt = 0;
//         }
//     }
//     return ret % 3;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];

//     int fis_pos;
//     int i = 1;
//     for(i = 1;i <= n;i++){
//         if(a[i] || b[i]){
//             fis_pos = get_pos(a[i], b[i]);
//             break;
//         }
//     }

//     for(;i <= n;i++){
//         if((a[i] || b[i]) && get_pos(a[i], b[i]) != fis_pos){
//             cout << "NO\n";
//             return;
//         }
//     }

//     cout << "YES\n";
// }

// signed main(){
//     int t = 1;
//     cin >> t;
//     while(t--)solve();
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int s, k, mod;
// int b[5] = {0,2,4,8,6,};
// int preb[5] = {0,2,6,14,20,};

// int get_res(int x){
//     if(!x) return k*s;
//     if(x >= k || x < 0) return 0;

//     int xx = x, ss = s;
//     while(xx > 0 && ss % 10 != 2){
//         ss += ss%10;
//         xx--;
//     }

//     return (k-x) * (ss + preb[4] * (xx/4) + preb[xx%4]);
// }

// void solve(){
//     cin >> s >> k;
//     mod = s % 10;

//     if(!mod){//特判 0,5
//         cout << s*k << '\n';
//         return;
//     }else if(mod == 5){
//         cout << max((s+5)*(k-1), s*k) << '\n';
//         return;
//     }

//     int ans = 0;
//     if(k > 40){
//         int x = ((20*k-4*s) / 160)*4;
//         ans = max(get_res(0), get_res(k-1));
//         for(int i = x - 5;i <= x + 5;i++) ans = max(ans, get_res(i));
//         for(int i = 0;i <= 5;i++) ans = max(ans, get_res(i));

//     }else{
//         for(int i = 0;i < k;i++) ans = max(ans, get_res(i));
//     }
//     cout << ans << '\n';

// }

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 3e5 + 10;
// const int BLOW = 0;
// const int TOP = 1;
// const int sz = 3e5 + 5;
// int n;
// vector<array<int, 5>>evt;

// //线段树
// struct info{
//     int mx;
// };
// struct node{
//     int tag;
//     info val;
// }tr[N << 2];
// void settag(int id, int v){
//     tr[id].tag += v;
//     tr[id].val.mx += v;
// }
// void up(int id){
//     tr[id].val.mx = max(tr[lson].val.mx, tr[rson].val.mx);
// }
// void down(int id){
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag = 0;
// }
// void modify(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr){
//         settag(id, v);
//         return;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid)
//         modify(lson, l, mid, ql, qr, v);
//     else if(ql > mid)
//         modify(rson, mid+1, r, ql, qr, v);
//     else{
//         modify(lson, l, mid, ql, qr, v);
//         modify(rson, mid+1, r, ql, qr, v);
//     }
//     up(id);
// }

// int get_mx_x(int id, int l, int r, int mx){
//     if(l == r) return l;
//     down(id);
//     int mid = l + r >> 1;
//     int lv = tr[lson].val.mx;
//     if(lv == mx) return get_mx_x(lson, l, mid, mx);
//     return get_mx_x(rson, mid + 1, r, mx);
// }

// signed main(){

//     cin >> n;
//     evt.reserve(n*2);
//     for(int i = 1, l, v, r;i <= n;i++){
//         cin >> l >> v >> r;
//         evt.push_back({v, BLOW, l, v, i});
//         evt.push_back({r, TOP, l, v, i});
//     }
//     sort(all(evt));

//     int mx = 0, py, px;
//     for(auto [y, op, l, r, id] : evt) if (op == BLOW){
//         modify(1, 1, sz, l, r, 1);
//         if(tr[1].val.mx > mx){
//             mx = tr[1].val.mx;
//             px = get_mx_x(1, 1, sz, mx);
//             py = y;
//         }
//     }else{
//         modify(1, 1, sz, l, r, -1);
//     }

//     vector<int>ans;
//     for(auto [y, op, l, r, id] : evt) if (op && l <= px && px <= r && r <= py && py <= y) ans.push_back(id);

//     cout << ans.size() << '\n';
//     for(auto e : ans) cout << e << ' ';

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int x, y, a, b;

// int dfs(int x, int y){
//     if(x == y) return 2;
//     int ret = 0;
//     int fm = x + y;
//     if(fm & 1)return -1;
//     x *= 2;
//     y *= 2;
//     if(x >= fm) ret++, x -= fm;
//     if(y >= fm) ret++, y -= fm;
//     int ne = dfs(x/2, y/2);
//     if(ne == -1) return -1;
//     return ne + ret;
// }

// void solve(){
//     cin >> x >> y >> a >> b;
//     cout << dfs(x,y) << '\n';
// }

// signed main(){
//     int t = 1;
//     cin >> t;
//     while(t--) solve();
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mod = 1e9 + 7;
// const int N = 1e5 + 10;
// string s;

// //阶乘快速幂
// int fac[N];
// int inv[N];
// int qpow(int a, int q, int p){
//     int ret = 1;
//     while(q){
//         if(q & 1) ret = ret * a % p;
//         a = a * a % p;
//         q >>= 1;
//     }
//     return ret;
// }
// void init(){
//     fac[0] = inv[0] = 1;
//     for(int i = 1;i < N;i++){
//         fac[i] = fac[i-1] * i % mod;
//         inv[i] = qpow(fac[i], mod - 2, mod) % mod;
//     }
// }

// //组合数
// int C(int a, int b){
//     return ((fac[b] * inv[a])%mod) * inv[b-a] % mod;
// }

// void solve(){
//     cin >> s;
//     s = ' ' + s;
//     vector<int>line;
//     int last = 0;
//     for(int i = 1, len = s.length();i < len;i++){
//         if(s[i] == 'm' || s[i] == 'w'){
//             cout << "0\n";
//             return;
//         }
//         if(s[i] == 'u' || s[i] == 'n'){
//             if(s[i] == s[i-1]){
//                 last++;
//             }else{
//                 if(last >= 2) line.push_back(last);
//                 last = 1;
//             }
//         }
//     }
//     if(last >= 2) line.push_back(last);

//     // for(auto s : line) cout << s << ' ';
//     // cout << line.size();
//     // cout << s;

//     for(auto &s : line){
//         int cnt = s / 2;
//         int len = cnt + (s&1);
//         int tmp = 1;
//         for(int i = 1;i <= cnt;i++){
//             tmp = (tmp + C(i, len)) % mod;
//             cout << i << ' ' << len << ' ' << tmp << '\n';
//         }
//         s = tmp;
//     }
//     int ans = 1;
//     for(auto s : line) ans = ans * s % mod;
//     cout << ans << '\n';
// }

// signed main(){
//     init();
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();
//     // cout << C(6,8);
//     // cout << fac[3] << ' ' << fac[4];
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1010;
// int n,k,m,t;

// signed main(){

//     cin >> n >> k >> m >> t;
//     while(t--){
//         int op, x;
//         cin >> op >> x;
//         if(!op){
//             if(k <= x){
//                 n = x;
//             }else{
//                 n = n - x;
//                 k = k - x;
//             }
//         }else{
//             n++;
//             if(x <= k) k++;

//         }
//         cout << n << ' ' << k << '\n';
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n,q,a[N];

// //线段树
// struct node{
//     int tag;
//     int sum;
// }tr[102][N<<2];
// void up(int id){
//     for(int i = 1; i <= 100;i++)
//         tr[i][id].sum = tr[i][lson].sum + tr[i][rson].sum;
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[a[l]][id].sum = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// void modify(int num, int s, int id, int l, int r, int ql, int qr, int v){
//     if(l == r){
//         tr[num].sum
//     }
// }

// signed main(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         add(a[i], i, 1);
//         add(a[i], i+1, -1);
//     }
//     cin >> q;
//     while(q--){
//         int l, r, x, y;
//         cin >> l >> r >> x >> y;
//         add(x, l, -1);
//         add(x, r+1, 1);
//         add(x, l, -1);
//         add(x, r+1, 1);
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 55;
// int n, x[N], y[N], sum, xx[N], yy[N];

// signed main(){
//     cin >> n;
//     sum = 4*n + 1;
//     int mi = 1, ma = 1;
//     for(int i = 1;i <= sum;i++){
//         cin >> x[i] >> y[i];
//         // if(x[i] < x[mi] && y[i] < y[mi]) mi = i;
//         // if(x[i] > x[ma] && y[i] > y[ma]) ma = i;

//         xx[x[i]]++;
//         yy[y[i]]++;
//     }

//     int mx = 0, my = 0;
//     for(int i = 0;i <= 50;i++){
//         if(xx[i] >= xx[mx]) mx = i;
//         if(yy[i] >= xx[my]) my = i;
//     }

//     int sx[2], f1 = 0;
//     // for(int i = 0;i <= 50;i++) if(xx[i] == xx[mx]){sx[f1++] = i;break;}
//     for(int i = 0;i <= 50;i++) if(xx[i] >= 2){sx[f1++] = i;break;}
//     for(int i = 50;i > sx[0];i--) if(xx[i] >= 2){sx[f1++] = i;break;}
//     if(f1 == 1){
//         xx[mx]--;
//         f1 = 0;
//         for(int i = 0;i <= 50;i++) if(xx[i] == xx[mx]) sx[f1++] = i;
//     }

//     int sy[2], f2 = 0;
//     for(int i = 0;i <= 50;i++) if(yy[i] >= 2) {sy[f2++] = i; break;}
//     for(int i = 50;i > sy[0];i--) if(yy[i] >= 2) {sy[f2++] = i; break;}
//     if(f2 == 1){
//         yy[my]--;
//         f2 = 0;
//         for(int i = 0;i <= 50;i++) if(yy[i] == yy[my]) sy[f2++] = i;
//     }

//     // cout << sx[0] << ' ' << sx[1] << '\n';
//     // cout << sy[0] << ' ' << sy[1];
//     // cout << xx[mx];
//     // for(int i = 0; i< 3;i++)cout << xx[i]<<' ';

//     for(int i = 1;i <= sum;i++)
//         // if(!(x[i]==sx[0]||x[i]==sx[1]||y[i]==sy[0]||y[i]==sy[1]))
//         if(((x[i]==sx[0]||x[i]==sx[1])&&y[i]>=sy[0]&&y[i]<=sy[1])||((y[i]==sy[0]||y[i]==sy[1])&&x[i]>=sx[0]&&x[i]<=sx[1]))
//         ;
//         else
//     cout << x[i] << ' ' << y[i] << '\n';

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1010;
// int n, m, mp[N][N];
// bool vis[N*N];

// bool isp[N];
// int p[N];
// int tot;
// void init(){
//     memset(isp, true, sizeof(isp));
//     isp[1] = 0;
//     for(int i = 2;i < N;i++){
//         if(isp[i]) p[++tot] = i;
//         for(int j = 1;j <= tot && p[j] * i < N;j++){
//             isp[p[j] * i] = false;
//             if(i % p[j] == 0) break;
//         }
//     }
// }

// void solve(){
//     cin >> n >> m;
//     memset(vis, 0, sizeof(vis));
//     if((n&1)==0&&(m&1)==0){
//         int tmp = 2;
//         for(int i = n/2; i >= 1;i--)
//             for(int j = 1;j <= m;j++)
//                 mp[i][j] = tmp, tmp += 2;

//         tmp = 1;
//         for(int i = (n/2)+1; i <= n;i++)
//             for(int j = 1;j <= m;j++)
//                 mp[i][j] = tmp, tmp += 2;

//     }else if(n&1){
//         int mid = (n/2)+1;
//         for(int i = 1; i <= m;i++) mp[mid][i] = i, vis[i] = true; //中间行1-m

//         int cnt = m;
//         if(cnt%2==0) cnt ++;
//         while(isp[cnt-2]) cnt += 2;
//         for(int i = 2; i <= m;i+=2) mp[mid-1][i] = cnt, vis[cnt] = true, cnt += 2; //上面放奇数
//         cnt = m;
//         if(cnt%2==0) cnt ++;
//         for(int i = 1; i <= m;i+=2){
//             while(vis[cnt]) cnt+=2;
//             mp[mid-1][i] = cnt, vis[cnt] = true, cnt += 2;
//         }
//         for(int i = 1;i < mid-1;i++)
//             for(int j = 1;j <= m;j++)
//                 mp[i][j] = cnt, vis[cnt] = true, cnt += 2;

//         cnt = m;
//         if(cnt & 1) cnt ++;
//         while(isp[cnt-1]) cnt += 2;
//         for(int i = 1; i <= m;i+=2) mp[mid+1][i] = cnt, vis[cnt] = true, cnt += 2; //下面偶数
//         cnt = m;
//         if(cnt & 1) cnt ++;
//         while(isp[cnt-1]) cnt += 2;
//         for(int i = 1; i <= m;i+=2){
//             while(vis[cnt]) cnt+=2;
//             mp[mid+1][i] = cnt, vis[cnt] = true, cnt += 2;
//         }
//         for(int i = mid+2;i <= n;i++)
//             for(int j = 1;j <= m;j++)
//                 mp[i][j] = cnt, vis[cnt] = true, cnt += 2;

//     }else{
//         int mid = (m/2)+1;
//         for(int i = 1; i <= n;i++) mp[i][mid] = i, vis[i] = true; //中间行1-m

//         int cnt = n;
//         if(cnt & 1) cnt += 2;
//         while(isp[cnt-2]) cnt += 2;
//         for(int i = 2; i <= n;i+=2) mp[i][mid-1] = cnt, vis[cnt] = true, cnt += 2; //左面放奇数
//         cnt = n;
//         if(cnt & 1) cnt += 2;
//         for(int i = 1; i <= n;i+=2){
//             while(vis[cnt]) cnt+=2;
//             mp[i][mid-1] = cnt, vis[cnt] = true, cnt += 2;
//         }
//         for(int i = 1;i <= n;i++)
//             for(int j = 1;j < mid-1;j++){
//                 while(vis[cnt]) cnt+=2;
//                 mp[i][j] = cnt, vis[cnt] = true, cnt += 2;
//             }

//         cnt = n;
//         if((cnt & 1)==0) cnt += 2;
//         for(int i = 1; i <= n;i+=2) mp[i][mid+1] = cnt, vis[cnt] = true, cnt += 2; //下面偶数
//         cnt = n;
//         if((cnt & 1)==0) cnt += 2;
//         for(int i = 1; i <= n;i+=2){
//             while(vis[cnt]) cnt+=2;
//             mp[i][mid+1] = cnt, vis[cnt] = true, cnt += 2;
//         }
//         for(int i = 1;i <= n;i++)
//             for(int j = mid+2;j <= m;j++)
//                 mp[i][j] = cnt, vis[cnt] = true, cnt += 2;
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++)
//         cout << mp[i][j] << ' ';
//         cout << '\n';
//     }
//     cout << '\n';
// }

// signed main(){
//     init();
//     int t;
//     cin >> t;
//     while(t--)solve();

//     // for(int i = 1;i <= 10;i++)cout << p[i] << ' ';

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1010;
// int n,m, mp[N][N];

// void solve(){
//     cin >> n >> m;
//     int cnt = 1;

//     if(n%2==0){
//         for(int i = 1;i <= m;i++)
//             for(int j = 1;j <= n;j++)
//                 mp[j][i] = cnt++;
//     }else if(m % 2 == 0)
//         for(int i = 1;i <= n;i++)
//             for(int j = 1;j <= m;j++)
//                 mp[i][j] = cnt++;
//     else{
//         for(int i = 1;i <= n;i+=2)
//             for(int j = 1;j <= m;j++)
//                 mp[i][j] = cnt++;
//         for(int i = 2;i <= n;i+=2)
//             for(int j = 1;j <= m;j++)
//                 mp[i][j] = cnt++;
//     }

//     for(int i = 1; i <= n;i ++){
//     for(int j = 1;j <= m;j++)
//     cout << mp[i][j] << ' ' ;
//     cout << '\n';
//     }

//     cout << '\n';

// }

// int main(){

//     int t;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int cnt = 0;

// double dfs(double a, double b){
//     if(++cnt == 30) return 1;
//     return sqrt(a*a + b * dfs(a,b+a));
// }

// int main(){
//     double a,b;
//     cin >> a >> b;

//     cout << a + b;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int a[4] = {0,3,5,7};

// int main(){
//     int n;
//     cin >> n;
//     if(n <= 3) cout << a[n];
//     else{
//         n--;
//         if(n % 3 == 0){
//             cout << 4 * (n/3+1);
//         }else{
//             n -= n/3;
//             n += 2;
//             cout << n*2-1;
//         }
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
// int dp[N];

// signed main(){

//     string s;
//     cin >> s;
//     s = ' ' + s;
//     dp[0] = 1;
//     for(int i = 1, len = s.length(); i < len;i++){
//         if(s[i] == 'w' || s[i] == 'm'){
//             cout << 0;
//             return 0;
//         }
//         if((s[i] == 'u' || s[i] == 'n') && s[i] == s[i-1])
//             dp[i] = (dp[i-1] + dp[i-2]) % mod;
//         else
//             dp[i] = dp[i-1];

//     }

//         cout << dp[s.length()-1];

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, q, a[N];

// //线段树
// struct node{
//     int num[101];
//     bool flag;
//     node() : flag(false) {
//         for(int i = 1;i <= 100;i ++)
//             num[i] = i;
//     }
// }tr[N<<2];
// void down(int id){
//     if(!tr[id].flag) return;
//     for(int i = 1;i <= 100;i++) {
//         tr[lson].num[i] = tr[id].num[tr[lson].num[i]];
//         tr[rson].num[i] = tr[id].num[tr[rson].num[i]];
//     }
//     for(int i = 1;i <= 100;i++)
//         tr[id].num[i] = i;
//     tr[id].flag = false;
//     tr[lson].flag = tr[rson].flag = true;
// }

// void settag(int id,int x,int y)
// {
//     tr[id].flag = true;
//     for (int i=1;i<=100;++i)
//     {
//         if (tr[id].num[i] == x)
//             tr[id].num[i] = y;
//     }
// }
// void modify(int id, int l, int r, int ql, int qr, int x, int y){
//     if(ql <= l && r <= qr){
//         settag(id, x, y);
//         return;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid)
//         modify(lson, l, mid, ql, qr, x, y);
//     else if(ql > mid)
//         modify(rson, mid + 1, r, ql, qr, x, y);
//     else{
//         modify(lson, l, mid, ql, qr, x, y);
//         modify(rson, mid + 1, r, ql, qr, x, y);
//     }
// }

// void calcu(int id, int l, int r){
//     if(l == r){
//         a[l] = tr[id].num[a[l]];
//         return;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     calcu(lson, l, mid);
//     calcu(rson, mid + 1, r);
// }

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n;
//     for(int i = 1;i <= n;i++ ) cin >> a[i];
//     cin >> q;
//     int l,r,x,y;
//     while(q--){
//         cin >> l >> r >> x >> y;
//         modify(1,1,n,l,r,x,y);
//     }
//     calcu(1, 1, n);

//     for(int i = 1;i <= n;i++) cout << a[i] << ' ';

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1010;
// const int mod = 1e9 + 7;
// int n,x,pos, a[N];

// int C[N][N], fac[N], inv[N];
// int qpow(int a, int q, int p){
//     int ret = 1;
//     while(q){
//         if(q & 1) ret = ret * a % p;
//         a = a * a % mod;
//         q >>= 1;
//     }
//     return ret;
// }
// void init(){
//     fac[0] = inv[0] = 1;
//     for(int i  = 1;i < N;i++){
//         C[i][0] = C[i][i] = 1;          //组合数
//         fac[i] = fac[i-1] * i % mod;    //阶乘
//         inv[i] = qpow(fac[i], mod - 2, mod);
//         for(int j = 1;j < i;j++)
//             C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
//     }
//     C[0][0] = 1;
// }
// int A(int a, int b){
//     return fac[a] * inv[a - b] % mod;
// }

// int gret, les;

// signed main(){

//     init();
//     cin >> n >> x >> pos;
//     int l = 0, r = n;
//     while(l < r){
//         int mid = l + r >> 1;
//         if(mid <= pos) {
//             if(mid < pos)
//                 les++;
//             l = mid + 1;
//         }
//         else r = mid, gret++;
//     }

//     if(gret > n-x || les > x-1){
//         cout << 0;
//         return 0;
//     }

//     // cout << (((C[n-x][gret] * fac[gret] % mod) * (C[x-1][les]) * fac[les] % mod) % mod) * fac[n-gret-les-1] % mod << '\n';
//     cout << ( ((A(n-x,gret)%mod) * (A(x-1,les)%mod)%mod) * fac[n-gret-les-1]) % mod;

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, ans = 0, odd, eve;

// vector<int>G[N];
// int sz[N];
// void dfs(int u, int fa, int dep){
//     if(dep & 1) odd++;
//     else eve++;
//     sz[u] = 1;
//     for(auto v : G[u]) if(v != fa){
//         dfs(v, u, dep + 1);
//         sz[u] += sz[v];
//         ans += sz[v] * (n - sz[v]);
//     }
// }

// signed main(){

//     cin >> n;
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         G[u].push_back(v);
//         G[v].push_back(u);
//     }

//     dfs(1, 0, 1);

//     cout<<(ans+odd*eve)/2;

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mod = 1e9 + 7;
// int n;
// char c[] = {'b','i','t'};
// char s[10] = {0};

// void dfs(int i){
//     if(i == n){
//         cout << s << '\n';
//         return;
//     }
//     for(int j = 0;j < 3;j++){
//         s[i] = c[j];
//         dfs(i+1);
//     }
// }

// signed main(){
//     cin >> n;
//     dfs(0);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// int n, m, a[N];

// void solve(){
//     int a[3];
//     for(int i = 0;i < 3;i++)cin >> a[i];
//     sort(a,a+3);
//     if(a[1] + a[2] >= 10) cout << "YES\n";
//     else cout << "NO\n";
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// int n, m, a[N][2];

// void solve(){
//     cin >> n;
//     int ans = 0;
//     for(int i = 1; i <= n;i++){
//         cin >> a[i][0] >> a[i][1];
//         if(a[i][0] > 10) continue;
//         if(a[i][1] > a[ans][1])
//             ans = i;
//     }
//     cout << ans << '\n';
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// const int N = 1e5 + 10;
// int n, m;
// char s[10][10];

// void solve(){
//     string ss;
//     for(int i = 1;i <= 8;i++)
//         for(int j = 1;j <= 8;j++) {
//             cin >> s[i][j];
//             if(s[i][j] >= 'a' && s[i][j] <= 'z') ss = ss + s[i][j];
//         }

//         cout << ss << '\n';
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, k, a[N];

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++ ){
//         cin >> a[i];
//     }
//     sort(a+1, a+1+n);

//     int ans = 0, l = 1;
//     for(int i = 1;i <= n;i++){
//         if(a[i] - a[i-1] > k){
//             // ans += min(n-i+1, i-l);
//             // l =
//             if(n-i+1 <= i-l){
//                 ans += n-i+1;
//                 break;
//             }
//             ans += i-l;
//             l = i;
//             // break;
//         }
//         // cout << a[i] << ' ';
//     }
//     cout << ans << '\n';
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define int double
// typedef long long ll;
// const ll N = 2e5 + 10;
// int n, c, a[N];

// void solve(){
//     cin >> n >> c;
//     int sum = 0, all = 0;
//     for(int i = 1, t ;i <= n;i++){
//         cin >> t;
//         sum += t*t;
//         all += t;
//     }

//     c -= sum;
//     c /= 4;

//     cout << (ll)round(((int)sqrt(all*all + 4 * n * c)-all)/(2*n)) << '\n';
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, k, a[N];

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++ ){
//         cin >> a[i];
//     }
//     sort(a+1, a+1+n);

//     int ans = 0, len = 1;
//     for(int i = 2;i <= n;i++){
//         if(a[i] - a[i-1] <= k){
//             len++;
//         }else{
//             ans = max(ans, len);
//             len = 1;
//         }
//     }
//             ans = max(ans, len);
//     cout << n-ans << '\n';
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, k, a[N], v[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) v[i] = 0;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] == 1){
//             ans ++;
//             continue;
//         }
//         for(int j = 0; j <= n;j+=a[i]) v[j] ++;
//     }

//     int mx = 0;
//     for(int i = 1;i <= n;i++) mx = max(v[i], mx);

//     cout << ans + mx << '\n';
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, k, a[N], v[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) v[i] = 0;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] == 1){
//             ans ++;
//             continue;
//         }
//         for(int j = 0; j <= n;j+=a[i]) v[j] ++;
//     }

//     int mx = 0;
//     for(int i = 1;i <= n;i++) mx = max(v[i], mx);

//     cout << ans + mx << '\n';
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, k, a[N], v[N];

// void solve(){
//     cin >> n;
//     int x,y;
//     unordered_map<int,int>X;
//     unordered_map<int,int>Y;
//     unordered_map<int,int>D;
//     unordered_map<int,int>P;
//     for(int i = 1;i <= n;i++){
//         cin >> x >> y;
//         X[x]++;
//         Y[y]++;
//         D[y-x]++;
//         P[x+y]++;
//         // cout << x << ' ' << y << '\n';
//     }
//     int ans = 0;
//     for(auto [k,v] : X) ans += max(0ll,(v*(v-1)));
//     for(auto [k,v] : Y) ans += max(0ll,(v*(v-1)));
//     for(auto [k,v] : D) ans += max(0ll,(v*(v-1)));
//     for(auto [k,v] : P) ans += max(0ll,(v*(v-1)));

//     cout << ans << '\n';
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, m, p[N];
// bool vis[N];

// int ax[N];
// int fa[N];
// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(x);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) vis[i] = 0, fa[i] = i;
//     int a,b,d;
//     int ans = 1;
//     while(m--){
//         cin >> a >> b >> d;
//         if(vis[a] && vis[d]) {
//             if(find(a) == find(b)){
//                 if(p[a] + d != p[b]) ans = 0;
//             }else{
//                 a = find(a);
//                 b = find(b);
//             }
//         }
//         else if(!vis[a] && !vis[b]) {p[a] = 0; p[b] = d; vis[a] = vis[b] = 1;}
//         else if()
//     }
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
// int n, a[N];

// void solve(){
//     cin >> n;
//     unordered_map<int,int>mp;
//     for(int i = 1;i <= n;i++) cin >> a[i], mp[a[i]]++;

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         int tmp = 0;
//         int sq = sqrt(i);
//         for(int j = 1;j < sqrt(i);j++) if(i % j == 0)
//             tmp += mp[j] + mp[i / j];
//         if(sq*sq == i)
//             tmp += mp[sq];

//         ans = max(ans, tmp);
//     }

//     cout << ans << '\n';
// }

// int main(){

//     int t;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     cin >> n >> m;
//     vector<vector<pair<int,int>>>G(n+1);
//     for(int i = 1;i <= m;i++){
//         int a,b,d;
//         cin >> a >> b >> d;
//         G[a].push_back({b, d});
//         G[b].push_back({a, -d});
//     }

//     vector<bool>vis(n+1);
//     vector<int>f(n+1);
//     for(int i = 1;i <= n;i++) if(!vis[i]){
//         vis[i] = true;
//         queue<int>q;
//         q.push(i);
//         while(q.size()){
//             int u = q.front();
//             q.pop();
//             for(auto [v, d] : G[u]) if(!vis[v]){
//                 q.push(v);
//                 vis[v] = true;
//                 f[v] = f[u] + d;
//             }else if(f[v] != f[u] + d) {
//                 cout << "NO\n";
//                 return;
//             }
//         }
//     }

//     cout << "YES\n";
// }

// signed main(){

//     int t;
//     cin >> t;
//     while(t-) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e6 + 10;
// int n, m;
// int a[N];
// bool check(int x)
// {
//     for(int i=1;i<=n;i++)
//     {
//         x=x+a[i];
//         if(x<0) return false;
//     }
//     return true;
// }

// void solve(){
//     cin>>n;
//     for(int i=1;i<=n;i++) cin>>a[i];
//     int l=0,r=1e17;
//     while(l<=r)
//     {
//         int mid=l+r>>1;
//         if(check(mid)) r=mid-1;
//         else l=mid+1;
//     }
//     cout<<l<<endl;
// }

// signed main(){

//     int t;
//     //cin >> t;
//     t=1;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e6 + 10;

// int n;
// queue<pair<int,int>> q;

// void solve(){
//     cin >> n;
//     int now = 0;
//     for (int i=1;i<=n;++i)
//     {
//         int t,d;
//         cin >> t >> d;
//         if (i == 1)
//         {
//             now = t + d;
//             continue;
//         }
//         q.push({t, d});
//     }
//     // int now =
//     while (q.size())
//     {
//         if (now < q.front().first)
//         {
//             now = q.front().first;
//             now += q.front().second;
//             // q.pop();
//         }
//         else
//         {
//             now += q.front().second;
//         }
//         q.pop();
//     }
//     cout << now << endl;
// }

// signed main(){

//     int t;
//     //cin >> t;
//     t=1;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e6 + 10;

// void solve(){
//     int a[6];
//     for(int i = 1;i <= 4;i++) cin >> a[i];
//     sort(a+1, a+5);
//     if(a[1] == a[2] && a[2] == a[3] && a[3] == a[4]){
//         cout << "YES\n";
//         return;
//     }
//     if(a[1] == a[2] && a[3] == a[4] && a[2] != a[3]){
//         cout << "YES\n";
//         return;
//     }
//     if(a[1] + a[4] == a[2] + a[3]){
//         cout << "YES\n";
//         return;
//     }

//     cout << "NO\n";
// }

// signed main(){

//     int t;
//     //cin >> t;
//     t=1;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n,m;
// vector<pair<int, char>>g[N];
// int vis[N];

// pair<int,char>fa[N];

// string dfs(int v){
//     if(v == 0) return "";
//     return dfs(fa[v].first) + fa[v].second;
// }

// void solve(){
//     cin >> n >> m;
//     while(m--){
//         int a,b;
//         char c;
//         cin >> a >> b >> c;
//         g[a].push_back({b, c});
//         g[b].push_back({a, c});
//     }

//     queue<pair<int,int>>q; //顶点、深度
//     q.push({1,1});
//     fa[1] = {0,0};
//     int ed = 0;            //是否到终点
//     int mns = 0;           //最短路劲长
//     vector<int>ansfa;
//     while(q.size()){
//         int u = q.front().first;
//         int dep = q.front().second;
//         q.pop();
//         if(vis[u] || dep >= mns) continue;
//         vis[u] = 1;
//         for(auto [v, c] : g[u]){
//             fa[v] = {u, c};
//             if(v == n){
//                 if(!ed) mns = dep+1;
//                 ansfa.push_back(u);
//                 ed = 1;
//             }
//             else
//                 q.push({v, dep+1});
//         }
//     }

//     vector<string>ss;
//     for(auto v : ansfa){
//         ss.push_back(dfs(v));
//     }

//     string ret = ss.front();
//     for(auto s : ss) ret = min(ret, s);
//     ret = ret +

//     cout << ret;
// }

// signed main(){

//     int t;
//     //cin >> t;
//     t=1;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define Acode ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
// const int N = 2e5 + 10;
// int n;

// void solve(){
//     cin >> n;
//     // vector<int>arr[N];
//     unordered_map<int, vector<int>>arr;
//     for(int i = 1;i <= n;i++){
//         int a, c;
//         cin >> a >> c;
//         arr[c].push_back(a);
//     }

//     for(auto &[k,ar] : arr) if(ar.size()) if(!is_sorted(ar.begin(), ar.end())){
//         cout << "NO\n";
//         return;
//     }

//     // for(int i = 1;i < N;i++) if(!is_sorted(arr[i].begin(), arr[i].end())){
//     //     cout << "NO\n";
//     //     return;
//     // }

//     cout << "YES\n";
// }

// signed main(){
// Acode;
//     int t;
//     //cin >> t;
//     t=1;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define Acode ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
// const int N = 2e5 + 10;
// int n, t, a[N];

// void solve()
// {
//     int n;
//     int w;
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)  cin>>a[i];
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         int temp=a[i]+w;
//         int l=1,r=n;
//         while(l<=r)
//         {
//             int mid=l+r>>1;
//             if(a[mid]<=temp)
//             {
//                 l=mid+1;
//             }
//             else r=mid-1;
//         }
//         ans=max(ans,r-i+1);
//     }
//     cout<<ans<<endl;
// }

// signed main(){
// Acode;
//     int t;
//     //cin >> t;
//     t=1;
//     while(t--) solve();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define Acode ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// const int N = 2e5 + 10;
// int a[N];

// void solve()
// {
//     int n, t;
//     cin >> n >> t;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];

//     int zer = lower_bound(a + 1, a + 1 + n, 0) - a;
//     if (a[zer] > 0 || zer > n)
//         zer--; // 从小于等于0开始

//     int ans = 0;
//     for (int i = zer; i >= 1; i--)
//     {
//         int til = t, as = 0;
//         // if (a[zer] == 0)
//         // as = 1;

//         if (abs(a[i]) > til) // 体力不够退出
//             break;

//         til -= abs(a[i]) * 2;

//         as += zer - i + 1;
//         // cout << as << ' ' << til << '\n';

//         if (til > 0)
//         {
//             // if(a[zer] <= )
//             int *pos = lower_bound(a + zer + 1, a + n + 1, til);
//             // cout << (pos - (a + zer)) << '\n';

//             // cout << *(a + zer + 1) << '\n';
//             // cout << (pos - (a + zer + 1)) << '\n';
//             as += pos - (a + zer + 1);
//             if (*pos == til)
//                 as++;
//         }

//         ans = max(as, ans);
//     }

//     int as = 0;
//     int *pos = lower_bound(a + 1, a + n + 1, t);
//     as += pos - (a + zer + 1);
//     if (*pos == t)
//         as++;
//     ans = max(as, ans);

//     // cout << zer;

//     cout << ans << '\n';
// }

// signed main()
// {
//     Acode;
//     int t;
//     // cin >> t;
//     t = 1;
//     while (t--)
//         solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     int n;
//     string s;
//     cin >> n >> s;
//     s = ' ' + s;
//     int a = 0,b = 0, c = 0; 
//     for(int i = 1;i <= n;i++){
//         if(s[i] == 'A')a++;
//         else if(s[i] == 'B')b++;
//         else c++;
//         if(a&&b&&c){
//             cout << a + b + c;
//             break;
//         }
//     }
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// int n, d;
// int day[110];

// int main(){
    
//     cin >> n >> d;
//     for(int i = 1;i <= n;i++){
//         string s;
//         cin >> s;
//         for(int i = 0;i < s.length();i++)if(s[i] == 'x')day[i+1] = 1;
//     }

//     int len = 0;
//     if(day[1] == 0)len++;
//     int ans =0;
//     for(int i = 2;i <= d;i++){
//         if(day[i]==0) len++;
//         else{
//             ans = max(ans, len);
//             len = 0;
//         }
//     }
//             ans = max(ans, len);
//     cout << ans;
// // for(int i = 1;i <= d;i++) cout << day[i] << ' ';
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int n, d;
// const int N = 2e5 + 10;
// int to[N];
// int vis[N];

// int ans = 0;

// void dfs(int u){
//     if(++vis[u]==2) {
//         ans = u;
//         return;
//     }
//     dfs(to[u]);
    
// }

// int main(){
    
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> to[i];

//     for(int i = 1;i <= n;i++) if(!vis[i] && !ans) dfs(i);

//     int cur = to[ans];
//     int cnt = 1;
//     while(cur != ans){
//         cnt++;
//         cur = to[cur];
//     }

//     cout << cnt << '\n';
//     cur = to[ans];
//     cout << ans << ' ';
//     while(cur != ans){
//         cout << cur << ' ';
//         cur = to[cur];
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n, m, t;
// const int N = 3010;
// int dp[N][N];
// int mp[N][N];
// int hole[N][N];

// signed main(){
    
//     cin >> n >> m >> t;
//     for(int i = 1;i <= t;i++){
//         int a,b;
//         cin >> a >> b;
//         mp[a][b] = 1;
//     }

//     for(int i = 0;i <= n;i++) hole[i][0] = 1;
//     for(int i = 0;i <= m;i++) hole[0][i] = 1;


//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
//             if(mp[i][j]){
//                 hole[i][j] = 1;
//             }else{
//                 int mn = min({hole[i-1][j], hole[i][j-1], hole[i-1][j-1]});
//                 dp[i][j] += mn;
//                 hole[i][j] = mn + 1;
//             }
//         }
//     }

//     cout << dp[n][m];
    

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, k, a[N], v[N];

// void solve(){
//     cin >> n;
//     int x,y;
//     unordered_map<int,int>X;
//     unordered_map<int,int>Y;
//     unordered_map<int,int>D;
//     unordered_map<int,int>P;
//     for(int i = 1;i <= n;i++){
//         cin >> x >> y;
//         X[x]++;
//         Y[y]++;
//         D[y-x]++;
//         P[x+y]++;
//         // cout << x << ' ' << y << '\n';
//     }
//     int ans = 0;
//     for(auto [k,v] : X) ans += v*(v-1);
//     for(auto [k,v] : Y) ans += v*(v-1);
//     for(auto [k,v] : D) ans += v*(v-1);
//     for(auto [k,v] : P) ans += v*(v-1);

//     cout << ans << '\n';
// }

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }
