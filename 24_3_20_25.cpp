// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// // #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n


// void solve(){
//     int x, t;
//     unordered_map<int,int>p;
//     cin >> x;
//     p[x] = 1;
//     for(int i = 2;i <= 1000;i++){
//         cout << "+ 1" << endl;
//         cin >> t;
//         if(p[t]){
//             cout << "! " << i-1 << endl;
//             return;
//         }
//         p[t] = i;
//     }

//     int ans = 1000;
//     while(1){
//         cout << "+ 1000" << endl;
//         cin >> t;
//         ans += 1000 - p[t];
//         if(p[t]) break;
//     }

//     cout << "! " << ans << endl;
// }

// signed main(){

//     IO;
//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// // #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n

// const int M = 300, sq = 350;

// void solve(){
//     int x, t;
//     cin >> x;
//     int mx = x;
//     for(int i = 1;i <= 300;i++){
//         cout << "+ " << 3300 << endl;
//         cin >> t;
//         mx = max(mx, t);
//     }

//     unordered_map<int,int>p;
//     p[t] = 1;
//     for(int i = 2;i <= 350;i++){
//         cout << "+ 1" << endl;
//         cin >> t;
//         if(p[t]){
//             cout << "! " << i-1 << endl;
//             return;
//         }
//         p[t] = i;
//     }

//     int ans = 350;
//     int d = mx - 350;
//     ans += d;
//     cout << "+ " << d << endl;
//     cin >> t;
//     while(1){
//         cout << "+ " << sq << endl;
//         cin >> t;
//         ans += sq - p[t];
//         if(p[t]) break;
//     }

//     cout << "! " << ans << endl;
// }

// signed main(){

//     IO;
//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n


// void solve(){
//     int n, m, q;
//     cin >> n >> m >> q;
//     n++, m++;
//     vector<vector<int>>f(n+5, vector<int>(m+5)), bad(n+5, vector<int>(m+5));
//     unordered_map<int, vector<array<int, 2>>>qur;
//     for(int i = 1, x, y, z;i <= q;i++){
//         cin >> x >> y >> z;
//         qur[x].push_back({y, z+1});
//     }

//     int t = n*m+2*q;

//     f[1][1] = 1;
//     for(int k = 1;k <= t;k++){
//         for(auto [op, x] : qur[k]){
//             if(op == 1){
//                 for(int j = 1;j <= m;j++){
//                     bad[x][j] = 1;
//                 }
//             }else{
//                 for(int j = 1;j <= n;j++){
//                     bad[j][x] = 1;
//                 }
//             }
//         }

//         for(int i = n;i >= 1;i--){
//             for(int j = m;j >= 1;j--) if(!bad[i][j]){
//                 f[i][j] |= f[i-1][j] | f[i][j-1];
//             }
//         }
//         // cerr << k << endl;
//         // for(int i = 1;i <= n;i++){
//         //     for(int j = 1;j <= m;j++) {
//         //         cerr << f[i][j] << ' ';
//         //     }
//         //     cerr << endl;
//         // }
//         // cerr << endl;

//         if(f[n][m]){
//             cout << k << endl;
//             return;
//         }

//         for(auto [op, x] : qur[k]){
//             if(op == 1){
//                 for(int j = 1;j <= m;j++){
//                     bad[x][j] = 0;
//                     f[x][j] = 0;
//                 }
//             }else{
//                 for(int j = 1;j <= n;j++){
//                     bad[j][x] = 0;
//                     f[j][x] = 0;
//                 }
//             }
//         }
//     }

//     cout << -1 << endl;
// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n

// const int N = 1e4 + 10;

// void solve(){
//     int n, m, q;
//     cin >> n >> m >> q;
//     // vector<vector<vector<bool>>> f(n+5, vector<vector<bool>>(m+5, vector<bool>(q+5))), bad(n+5, vector<vector<bool>>(m+5, vector<bool>(q+5)));
//     vector<vector<vector<int>>> f(n+5, vector<vector<int>>(m+5, vector<int>(q+5))), bad(n+5, vector<vector<int>>(m+5, vector<int>(q+5)));
//     for(int i = 1, x, y, z;i <= q;i++){
//         cin >> x >> y >> z;
//         if(y == 1){
//             for(int j = 0;j <= m;j++){
//                 int w = x - z - j;
//                 if(w >= 0 && w <= q) bad[z][j][w] = 1;
//             }
//         }else{
//             for(int j = 0;j <= n;j++){
//                 int w = x - z - j;
//                 if(w >= 0 && w <= q) bad[j][z][w] = 1;
//             }
//         }
//     }

//     f[0][0][0] = 1;
//     for(int k = 0;k <= q;k++){
//         for(int i = 0;i <= n;i++){
//             for(int j = 0;j <= m;j++) if(!bad[i][j][k]){
//                 if(i) f[i][j][k] |= f[i-1][j][k];
//                 if(j) f[i][j][k] |= f[i][j-1][k];
//                 if(k) f[i][j][k] |= f[i][j][k-1];
//             }
//         }

//         // for(int i = 0;i <= n;i++){
//         //     for(int j = 0;j <= m;j++) {
//         //         cerr << f[i][j][k] << ' ';
//         //     }
//         //     cerr << endl;
//         // }
//         // cerr << endl;

//         // cerr << n << ' ' << m << ' ' << k << endl;
//         if(f[n][m][k]){
//             cout << n+m+k << endl;
//             // cerr << k << endl;
//             return;
//         }
//     }
//     cout << -1 << endl;

// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n

// const int mod = 998244353;
// const int N = 1e6 + 10;
// int fac[N], pw[N];

// void solve(){
//     int k, n, ans = 1;
//     cin >> k;
//     n = (1 << k);
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     auto dfs = [&](auto self, int len, int l, int r) -> void {
//         // cerr << len << ' ' << l << ' ' << r << endl;
//         if(len == 1){
//             if(a[1] != 1 && a[1] != -1) ans = 0;
//             return;
//         } 
//         vector<int>vec(1);
//         int tw = 0, cnt = 0;
//         for(int i = 1;i <= len;i += 2){
//             if(a[i] > a[i+1]) swap(a[i], a[i+1]);
//             if(a[i] == -1){
//                 if(a[i+1] == -1){
//                     cnt++;
//                     tw++;
//                     vec.push_back(-1);
//                 }else if(a[i+1] < l){
//                     cnt++;
//                     vec.push_back(a[i+1]);
//                 }else if(a[i+1] >= l){
//                     vec.push_back(-1);
//                 }
//             }else{
//                 if(a[i] >= l || a[i+1] < l){
//                     ans = 0;
//                     return;
//                 }
//                 vec.push_back(a[i]);
//             }
//         }
//         ans = ((ans * fac[cnt]) % mod) * pw[tw] % mod;
//         a = vec;    
//         self(self, len / 2, (l-1)/2 + 1, l-1);
//     };


//     dfs(dfs, n, n / 2 + 1, n);

//     cout << ans << endl;
// }

// signed main(){

//     IO;

//     fac[0] = 1;
//     for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//     pw[0] = 1;
//     for(int i = 1;i < N;i++) pw[i] = pw[i-1] * 2 % mod;

//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n

// const int mod = 998244353;
// const int N = 1e6 + 10;


// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<int>dis(n+5);
//     vector<vector<int>>g(n+5);
//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         g[v].push_back(u);
//     }

//     queue<int>que;
//     dis[1] = 1;
//     que.push(1);
//     while(que.size()){
//         int u = que.front();
//         que.pop();
//         for(auto v : g[u]) if(!dis[v]){
//             dis[v] = dis[u] + 1;
//             que.push(v);
//         }
//     }

//     for(int i = 1;i <= n;i++) if(!dis[i]){
//         cout << "INFINITE\n";
//         return;
//     }
//     cout << "FINITE\n";

//     vector<vector<int>>vec(n+5);
//     int mx = 0;
//     for(int i = 1;i <= n;i++){
//         vec[dis[i]].push_back(i);
//         mx = max(mx, dis[i]);
//     }

//     vector<int>ans;
//     for(int i = mx;i >= 1;i--) {
//         for(int j = mx;mx-j+1 <= i;j--)
//             for(auto e : vec[j]) ans.push_back(e);
//     }

//     cout << ans.size() << endl;
//     for(auto e : ans) cout << e << " ";
//     cout << endl;

// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n

// const int mod = 998244353;
// const int N = 1e6 + 10;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     sort(all1(a));

//     int mid = (n+1) / 2;
//     int cnt = 0;
//     for(int i = mid;i <= n;i++){
//         cnt += (a[i] == a[mid]);
//     }

//     cout << cnt << endl;

// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n

// const int mod = 1e9+7;
// const int N = 1e6 + 10;


// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<int>a(n+4);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int mx = 0;
//     int cur = 0;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         ans = (ans + a[i] + mod) % mod;
//         cur += a[i];
//         cur = max(0ll, cur);
//         mx = max(mx, cur);
//     }

//     while(k--){
//         ans = (ans + mx + mod) % mod;
//         mx = mx * 2 % mod;
//     }

//     cout << ans << endl;

// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n

// const int mod = 1e9+7;
// const int N = 1e6 + 10;


// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<vector<int>>g(n+5);
//     vector<int>siz(n+5);
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     int mid;

//     auto dfs = [&](auto self, int u, int f) -> int {
//         int ret = 0;
//         for(auto v : g[u]) if(v != f){
//             ret += self(self, v, u);
//             siz[u] += siz[v];
//         }
//         if(u != 1 && siz[u] >= mid){
//             ret++;
//             siz[u] = 0;
//         }
//         return ret;
//     };

//     auto check = [&]() -> int {
//         for(int i = 1;i <= n;i++) siz[i] = 1;
//         int ct = dfs(dfs, 1, 0);
//         if(ct > k) return 1;
//         else if(ct == k){
//             if(siz[1] >= mid) return 1;
//             return 0;
//         }else{
//             return 0;
//         }
//     };  

//     int l = 1, r = n;;
//     while(l <= r){
//         mid = l + r >> 1;
//         if(check()) l = mid + 1;
//         else r = mid - 1;
//     }

//     cout << r << endl;

// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n

// const int mod = 1e9+7;
// const int N = 1e6 + 10;


// void solve(){
//     int n, x;
//     cin >> n >> x;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int ans = 0, cur = 0, cnt = 0;
//     for(int i = 1;i <= n;i++){
//         cur ^= a[i];
//         int f = 1;
//         for(int j = 0;j < 30;j++){
//             if(((x>>j)&1) == 0){
//                 if((cur>>j) & 1) {
//                     f = 0;
//                     break;
//                 }
//             }
//         }
//         if(f) {
//             cnt++;
//             cur = 0;
//         }
//     }
//     if(cur == 0) ans = cnt;

//     for(int k = 0;k < 30;k++) if((x >> k) & 1) {
//         cur = 0, cnt = 0;
//         for(int i = 1;i <= n;i++){
//             cur ^= a[i];
//             int f = 1;
//             if(((cur>>k)&1) == 0){
//                 for(int j = 29;j > k;j--) if(((x>>j) & 1) == 0){
//                     if((cur>>j) & 1) {
//                         f = 0;
//                         break;
//                     }
//                 }
//             }
//             else{
//                 f = 0;
//             }
//             if(f) {
//                 cnt++;
//                 cur = 0;
//             }
//         }
//         if(cur == 0){
//             ans = max(ans, cnt);
//         }
//     }

//     if(ans) cout << ans << endl;
//     else cout << -1 << endl;
// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }


// template<class Info>
// struct SGT {
//     #define l(p) (p << 1)
//     #define r(p) (p << 1 | 1)
//     int n;
//     std::vector<Info> info;
//     SGT() {}
//     SGT(int _n, Info _v = Info()) {
//         init(_n, _v);
//     }
//     template<class T>
//     SGT(std::vector<T> _init) {
//         init(_init);
//     }
//     void init(int _n, Info _v = Info()) {
//         init(std::vector(_n, _v));
//     }
//     template<class T>
//     void init(std::vector<T> _init) {
//         n = _init.size();
//         info.assign(4 << std::__lg(n), Info());
//         auto build = [&](auto self, int p, int l, int r) {
//             if (r - l == 1) {
//                 info[p] = _init[l];
//                 return;
//             }
//             int m = l + r >> 1;
//             self(self, l(p), l, m);
//             self(self, r(p), m, r);
//             pull(p);
//         };
//         build(build, 1, 0, n);
//     }
//     void pull(int p) { // pushup
//         info[p] = info[l(p)] + info[r(p)];
//     }
//     void modify(int p, int l, int r, int x, const Info &v) {
//         if (r - l == 1) {
//             info[p] = v;
//             return;
//         }
//         int m = l + r >> 1;
//         if (x < m) {
//             modify(l(p), l, m, x, v);
//         } else {
//             modify(r(p), m, r, x, v);
//         }
//         pull(p);
//     }
//     void modify(int p, const Info &v) {
//         modify(1, 0, n, p, v);
//     }
//     Info query(int p, int l, int r, int x, int y) {
//         if (l >= y or r <= x) {
//             return Info();
//         }
//         if (l >= x and r <= y) {
//             return info[p];
//         }
//         int m = l + r >> 1;
//         return query(l(p), l, m, x, y) + query(r(p), m, r, x, y);
//     }
//     Info query(int l, int r) {
//         return query(1, 0, n, l, r);
//     }
//     #undef l(p)
//     #undef r(p)
// };

// struct Info {
//     // 定义要存的变量，比如区间和 sum 或者最大公约数 d 等等，至于下标就不用存了
// };
// Info operator+(Info a, Info b) {
//     Info c;
//     // 对 a（左儿子） 和 b（右儿子） 一通操作合成 c（父结点）
//     return c;
// }



// #include<bits/stdc++.h>
// using namespace std;

// template<class Info>
// struct SGT {
//     #define l(p) (p << 1)
//     #define r(p) (p << 1 | 1)

//     int n;
//     std::vector<Info> info;

//     SGT() {}
//     SGT(int _n, Info _v = Info()) {
//         init(_n, _v);
//     }
//     template<class T>
//     SGT(std::vector<T> _init) {
//         init(_init);
//     }

//     void init(int _n, Info _v = Info()) {
//         init(std::vector(_n, _v));
//     }
//     template<class T>
//     void init(std::vector<T> _init) {
//         n = _init.size();
//         info.assign(4 << std::__lg(n), Info());
//         auto build = [&](auto self, int p, int l, int r) {
//             if (r - l == 1) {
//                 info[p] = _init[l];
//                 return;
//             }
//             int m = l + r >> 1;
//             self(self, l(p), l, m);
//             self(self, r(p), m, r);
//             pull(p);
//         };
//         build(build, 1, 0, n);
//     }
//     void pull(int p) { // pushup
//         info[p] = info[l(p)] + info[r(p)];
//     }
//     void modify(int p, int l, int r, int x, const Info &v) {
//         if (r - l == 1) {
//             info[p] = v;
//             return;
//         }
//         int m = l + r >> 1;
//         if (x < m) {
//             modify(l(p), l, m, x, v);
//         } else {
//             modify(r(p), m, r, x, v);
//         }
//         pull(p);
//     }
//     void modify(int p, const Info &v) {
//         modify(1, 0, n, p, v);
//     }
//     Info query(int p, int l, int r, int x, int y) {
//         if (l >= y or r <= x) {
//             return Info();
//         }
//         if (l >= x and r <= y) {
//             return info[p];
//         }
//         int m = l + r >> 1;
//         return query(l(p), l, m, x, y) + query(r(p), m, r, x, y);
//     }
//     Info query(int l, int r) {
//         return query(1, 0, n, l, r);
//     }
//     #undef l(p)
//     #undef r(p)
// };

// struct Info {
//     // 定义要存的变量，比如区间和 sum 或者最大公约数 d 等等，至于下标就不用存了
//     int mx;
//     Info(int x = 0) : mx(x) {};
// };
// Info operator+(Info a, Info b) {
//     Info c;
//     c.mx = max(a.mx, b.mx);
//     // 对 a（左儿子） 和 b（右儿子） 一通操作合成 c（父结点）
//     return c;
// }



// signed main(){

//     int n = 10;
//     vector<Info>vec(10);

//     for(int i = 0;i < 10;i++){
//         vec[i] = i+100;
//     }

//     // SGT<Info> tr(n, Info(1));
//     SGT<Info> tr(vec);

//     cout << tr.query(0, 1).mx;



//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define all(x) (x).begin(), (x).end()

// #define _pre pre[k]
// #define _mn mn[k]
// #define _d d[k]
// #define _idx idx[k]
// #define _tr tr[k]
// #define _id id[k]

// const int mod = 998244353;
// int n;
// const int I = 0;
// const int C = 1;
// const int P = 2;
// // const int rp = 0;
// // const int ri = 1;
// // const int rc = 2;
// char ch[3] = {'I', 'C', 'P'};
// char rch[3] = {'P', 'I', 'C'};

// int lowbit(int x){
//     return x & -x;
// }

// class BIT{
// public:
//     vector<int>tr;
//     int n;
//     BIT(int n = 0) : n(n), tr(n+5) {};
//     void resize(int x){
//         n = x;
//         tr.resize(x+5);
//     }
//     void add(int x, int v){
//         while(x <= n){
//             tr[x] = (tr[x] + v) % mod;
//             x += lowbit(x);
//         }
//     }
//     int getsum(int x){
//         int ret = 0;
//         while(x){
//             ret = (ret + tr[x]) % mod;
//             x -= lowbit(x);
//         }
//         return ret;
//     }
// };  

// void solve(){
//     string s;
//     cin >> s;
//     n = s.size();
//     s = ' ' + s;

//     vector<vector<int>>pre(3, vector<int>(n+5)), d(3, vector<int>(n+5)), id(3, vector<int>(n+5));
//     vector<vector<vector<int>>>idx(3, vector<vector<int>>(n+5));
//     vector<vector<BIT>>tr(3, vector<BIT>(n+5));
//     int mn[3] = {0};
//     for(int k = 0;k < 3;k++){
//         // auto& _pre = pre[k];
//         // auto& _mn = mn[k];
//         // auto& _d = d[k];
//         for(int i = 1;i <= n;i++){
//             _pre[i] = _pre[i-1];
//             if(s[i] == rch[k]) _pre[i]++;
//             else if(s[i] != ch[k]) _pre[i]--;
//             _mn = min(_mn, _pre[i]);

//             _d[i] = _d[i-1] + (s[i] == rch[k]);
//         }
//     }
//     for(int k = 0;k < 3;k++)
//         for(int i = 0;i <= n;i++){
//             _d[i] = i - 3*_d[i];
//             _pre[i] -= _mn;
//         }

//     for(int k = 0;k < 3;k++)
//         for(int i = 0;i <= n;i++) _idx[_pre[i]].push_back(i);

//     for(int k = 0;k < 3;k++)
//         for(int i = 0;i <= n;i++) if(_idx[i].size()){
//             _tr[i].resize(_idx[i].size());
//             sort(all(_idx[i]), [&](int i, int j) -> int {
//                 return _d[i] < _d[j];
//             });
//             for(int j = 0;j < _idx[i].size();j++) _id[_idx[i][j]] = j;
//         }

//     int ans;

//     for(int k = 0;k < 3;k++) {
//         _tr[_pre[0]].add(_id[0]+1, 1);
//     }
//     for(int i = 1;i <= n;i++){
//         int tmp = 0;
//         for(int k = 0;k < 3;k++){
//             int l = 0, r = _idx[_pre[i]].size() - 1;
//             while(l <= r){
//                 int mid = l + r >> 1;
//                 if(_d[_idx[_pre[i]][mid]] < _d[i]) l = mid + 1;
//                 else r = mid - 1;
//             }
//             tmp = (tmp + _tr[_pre[i]].getsum(r+1)) % mod;
//             // if(i == 2) {
//             //     cerr << r << ' ';
//             //     cerr << tmp << endl;
//             // }
//             // if(_pre[i] + _mn == 0 && _d[i] > 0) tmp = (tmp + 1) % mod;
//         }
//         for(int k = 0;k < 3;k++){
//             _tr[_pre[i]].add(_id[i]+1, tmp);
//         }
//         if(i == n) ans = tmp;
//         // cerr << tmp << ' ';
//     }
//     cout << ans << endl;

//     // for(auto e : idx[C][0]) cerr << e << ' ';

//     // for(int k = 0;k < 3;k++){
//     //     // for(int i = 0;i <= n;i++) cerr << _pre[i]+_mn << " ";
//     //     // cerr << endl;
//     //     // for(int i = 0;i <= n;i++) cerr << _d[i] << " ";
//     //     // cerr << endl;
//     //     // for(int i = 0;i <= n;i++) cerr << (_d[i]-i)/-3 << " ";
//     //     // cerr << endl;
//     // }
// }

// signed main(){

//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define all(x) (x).begin(), (x).end()

// const int N = 1e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int Log[N];

// class ST{
// public:
//     vector<vector<int>>f;
//     vector<int>&dep;
//     ST(int n, vector<int>a, vector<int>&dep) : dep(dep), f(n+4, vector<int>(20)) {
//         for(int i = 1;i <= n;i++) f[i][0] = a[i];
//         for(int j = 1;j < 20;j++){
//             for(int i = 1;i <= n && i+(1<<j)-1 <= n;i++){
//                 f[i][j] = min(f[i+(1<<(j-1))][j-1], f[i][j-1]);
//             }
//         }
//     }
//     int query(int l, int r){
//         int s = Log[r-l+1];
//         return min(f[l][s], f[r-(1<<s)+1][s]);
//     }
//     int min(int i, int j){
//         if(dep[i] <= dep[j]) return i;
//         return j;
//     }
// };

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<array<int,2>>>g(n+5), G(n+5);
//     vector<int>P, dep(n+5), h(n+5), dis(n+5), A(1), dfn(n+5), vis(n+5);

//     for(int i = 1, u, v, w;i <= m;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     auto dfs = [&](auto self, int u, int fa) -> void {
//         // cerr << u << endl;
//         dep[u] = dep[fa] + 1;
//         dfn[u] = A.size();
//         A.push_back(u);
//         for(auto [v, w] : g[u]) if(v != fa){
//             if(!dep[v]){
//                 h[v] = h[u] + w;
//                 self(self, v, u);
//                 A.push_back(u);
//             }else{
//                 dis[u] = dis[v] = inf;
//                 P.push_back(u);
//                 P.push_back(v);
//                 G[u].push_back({v, w});
//                 G[v].push_back({u, w});
//             }
//         }
//     };

//     dfs(dfs, 1, 0);
//     sort(all(P));
//     P.erase(unique(all(P)), P.end());
//     int M = P.size();
//     ST st(n*2-1, A, dep);

//     // for(auto p : A) cerr << p << ' ';
//     // cerr << endl;
//     // for(auto p : P) cerr << p << ' ';
//     // cerr << endl;

//     auto dist = [&](int a, int b) -> int {
//         if(dfn[a] > dfn[b]) swap(a, b);
//         int lca = st.query(dfn[a], dfn[b]);
//         return h[a] + h[b] - 2*h[lca];
//     };

//     for(int i = 0;i < P.size();i++){
//         for(int j = i+1;j < P.size();j++){
//             G[P[i]].push_back({P[j], dist(P[i], P[j])});
//             G[P[j]].push_back({P[i], dist(P[j], P[i])});
//         }
//     }

//     int q;
//     cin >> q;
//     while(q--){
//         int u, v;
//         cin >> u >> v;
//         for(auto p : P){
//             // if(u != p){
//                 G[u].push_back({p, dist(u, p)});
//             // }
//             // if(v != p){
//                 G[p].push_back({v, dist(p, v)});
//             // }
//         }

//         if(!dis[u]){
//             dis[u] = inf;
//             P.push_back(u);
//         }
//         if(!dis[v]){
//             dis[v] = inf;
//             P.push_back(v);
//         }

//         dis[u] = 0;
//         dis[v] = dist(u, v);
//         for(int i = 0;i < P.size();i++){
//             int mn = -1;
//             for(int j = 0;j < P.size();j++) if(!vis[P[j]]){
//                 if(mn == -1 || dis[P[j]] < dis[mn]) mn = P[j];
//             }
//             vis[mn] = 1;
//             for(auto [t, w] : G[mn]) if(!vis[t]){
//                 dis[t] = min(dis[t], dis[mn] + w);
//                 // if(t == v){
//                 //     cerr << mn << ' ' << t << ' ' << w << ' ' << dis[mn] << ' ' << dis[t] << endl;
//                 // }
//             }
//         }

//         cout << dis[v] << endl;

//         while(P.size() > M){
//             dis[P.back()] = vis[P.back()] = 0;
//             P.pop_back();
//         }

//         for(auto p : P){
//             vis[p] = 0;
//             dis[p] = inf;
//             G[u].pop_back();
//             G[p].pop_back();
//         }
//     }
// }

// signed main(){

//     ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

//     for(int i = 2;i < N;i++) Log[i] = Log[i/2] + 1;

//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long


// void solve(){
//     int n, m;
//     cin >> n >> m;
//     m++;
//     vector<int>a(n+5), fa(n+5), siz(n+5);
//     vector<vector<int>>g(n+5), f(n+5, vector<int>(m+5));
//     for(int i = 1;i <= n;i++){
//         cin >> fa[i] >> a[i];
//         f[i][1] = a[i];
//         g[fa[i]].push_back(i);
//     }


//     auto dfs = [&](auto self, int u) -> void {
//         siz[u] = 1;
//         for(auto v : g[u]) {
//             self(self, v);
//             for(int i = min(m, siz[u]);i >= 1;i--){
//                 for(int j = 1;j <= min(m, siz[v]) && i + j <= m;j++){
//                     f[u][i+j] = max(f[u][i+j], f[u][i] + f[v][j]);
//                 }
//             }
//             siz[u] += siz[v];
//         }
//     };

//     dfs(dfs, 0);

//     cout << f[0][m] << endl;
// }

// signed main(){

//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define all(x) (x).begin(), (x).end()
// #define int long long


// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>>a(n+5);
//     vector<int>c(m+5), idx(n), v(n+5);
//     for(int i = 1, t;i <= n;i++){
//         cin >> t;
//         a[i].resize(t);
//         for(auto &e : a[i]) cin >> e;
//     }

//     iota(all(idx), 1);
//     sort(all(idx), [&](int i, int j) -> int {return a[i].size() > a[j].size();});
//     v[0] = m;
//     for(int i = 0;i < n;i++) v[idx[i]] = i;

//     for(auto id : idx) if(a[id].size()) {
//         int f = c[a[id][0]];
//         for(auto p : a[id]) if(v[c[p]] > v[f]) f = c[p];

//         for(auto p : a[id]) if(c[p] != f) {
//             cout << "YES\n";
//             if(f) cout << f << ' ' << id << endl;
//             else cout << c[p] << ' ' << id << endl;
//             return;
//         }else{
//             c[p] = id;
//         }
//     }

//     cout << "NO\n";
// }

// signed main(){

//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define all(x) (x).begin(), (x).end()
// #define int unsigned long long

// const int mod = 998244353;
// const int base = 1e9+7;

// int qpow(int a, int b){
//     int ret = 1;
//     while(b){
//         if(b & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return ret;
// }

// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<int>>g(n+5);
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     vector<int>h(n+5), dep(n+5);
//     unordered_map<int,int>ok;

//     auto dfs = [&](auto self, int u, int fa) -> void {
//         h[u] = 1;
//         dep[u] = dep[fa] + 1;
//         for(auto v : g[u]) if(v != fa){
//             self(self, v, u);
//         }
//         sort(all(g[u]), [&](int i, int j) -> int {
//             return h[i] < h[j];
//         });

//         unordered_map<int,int>mp;
//         int cnt = 0;
//         for(auto v : g[u]) if(v != fa){
//             mp[h[v]]++;
//             cnt++;
//             // h[u] = h[v] * mod + h[u];
//             // h[u] = dep[v] * mod + h[u];
//             // h[u] = ((h[u] * base % mod) + h[v]) % mod;
//             // h[u] = ((h[u] * base % mod) + dep[v]) % mod;
//             h[u] = ((h[u] * base % mod) + qpow(h[v], dep[v])) % mod;
//         }
//         // h[u] = cnt * mod + h[u];
//         // h[u] = dep[u] * mod + h[u];
//         // h[u] = ((h[u] * base % mod) + cnt) % mod;
//         // h[u] = ((h[u] * base % mod) + dep[u]) % mod;
//         // h[u] = ((h[u] * base % mod) + qpow(cnt, dep[u])) % mod;

//         if(cnt & 1){
//             int j = 0;
//             for(auto [k, v] : mp) if(v & 1) {
//                 if(!ok[k]) return;
//                 if(j){
//                     return;
//                 }else{
//                     j = k;
//                 }
//             }
//             ok[h[u]] = 1;
//         }else{
//             for(auto [k, v] : mp) if(v & 1){
//                 return;
//             }
//             ok[h[u]] = 1;
//         }
//     };

//     dfs(dfs, 1, 0);

//     if(ok[h[1]]) cout << "YES\n";
//     else cout << "NO\n";
// }

// signed main(){

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// const int inf = 0x3f3f3f3f3f3f3f3f;

// signed main(){

//     int n, m, q;
//     cin >> n >> m >> q;
//     vector<vector<array<int,2>>>g(n+5), rg(n+5);
//     for(int i = 1, u, v, c, d;i <= m;i++){
//         cin >> u >> v >> c >> d;
//         g[u].push_back({v, c});
//         rg[v].push_back({u, d});
//     }
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     multiset<int>st;
//     vector<int>ds(n+5, inf), dt(n+5, inf);

//     priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>>que;
//     ds[1] = 0;
//     que.push({0, 1});
//     while(que.size()){
//         auto [d, u] = que.top();
//         que.pop();
//         for(auto [v, w] : g[u]) if(d + w < ds[v]){
//             ds[v] = d + w;
//             que.push({ds[v], v});
//         }
//     }
//     dt[n] = 0;
//     que.push({0, n});
//     while(que.size()){
//         auto [d, u] = que.top();
//         que.pop();
//         for(auto [v, w] : rg[u]) if(d + w < dt[v]){
//             dt[v] = d + w;
//             que.push({dt[v], v});
//         }
//     }

//     auto val = [&](int i) -> int {
//         return ds[i] + (dt[i] + a[i]-1) / a[i];
//     };
    
//     for(int i = 1;i <= n;i++) {
//         st.insert(val(i));
//     }

//     while(q--){
//         int xi, ai;
//         cin >> xi >> ai;
//         st.erase(st.find(val(xi)));
//         a[xi] = ai;
//         st.insert(val(xi));
//         cout << *st.begin() << endl;
//     }
    
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;


// signed main(){

//     int n, m;
//     cin >> n >> m;
//     vector<string>s;
//     string t;
//     string es = "easy";
//     string qd = "qiandao";    
//     getchar();
//     for(int i = 1;i <= n;i ++){
//         getline(cin, t);
//         int f = 1;
//         for(int j = 0;j < t.size();j++){
//             for(int k = 0;k < es.size() && k + j < t.size();k++){
//                 if(t[j+k] != es[k]) break;
//                 if(k == es.size() - 1) f = 0;
//             }
//         }
//         for(int j = 0;j < t.size();j++){
//             for(int k = 0;k < qd.size() && k + j < t.size();k++){
//                 if(t[j+k] != qd[k]) break;
//                 if(k == qd.size() - 1) f = 0;
//             }
//         }
//         if(f) s.push_back(t);
//     }

//     if(m >= s.size()) cout << "Wo Ak le"

    
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define all(x) (x).begin(), (x).end()

// signed main(){

//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>>ot(n+5, vector<int>(m));
//     map<vector<int>,int>mp;
//     for(int i = 1;i <= n;i++){
//         for(int j = 0;j < m;j++){
//             cin >> ot[i][j];
//         }
//         mp[ot[i]]++;
//     }

//     // cerr << "DEBUG\n";

//     vector<pair<int, vector<int>>>ans;

//     for(auto &[v1, v2] : mp){
//         ans.push_back({v2, v1});

//     }

//     // for(auto [v2, v1] : ans){
//     //     cerr << v2 << ' ';
//     //     for(auto e : v1) cerr << e << ' ';
//     //     cerr << endl;
//     // }

//     vector<int>id(ans.size());
//     iota(all(id), 0);
//     sort(all(id), [&](int i, int j) -> int {
//         if(ans[i].first == ans[j].first) return ans[i].second < ans[j].second;
//         return ans[i].first > ans[j].first;
//     });

//     cout << ans.size() << endl;
//     for(auto i : id){
//         cout << ans[i].first << ' ';
//         for(int j = 0;j < ans[i].second.size();j++){
//             cout << ans[i].second[j];
//             if(j != ans[i].second.size()-1) cout << ' ';
//         }
//         cout << endl;
//     }

    
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;


// signed main(){

//     int n, m;
//     cin >> n;
//     vector<int>h(n+5);
//     for(int i = 1; i <= n;i++) cin >> h[i];

//     cin >> m;
//     vector<int>siz(m+5);
//     vector<vector<int>>a(m+5);
//     for(int i = 1; i <= m;i++){
//         cin >> siz[i];
//         a[i].resize(siz[i]+3);
//         for(int j = 1;j <= siz[i];j++) cin >> a[i][j];
//     }

//     vector<vector<int>>vec(n+5);

//     for(int k = 1; k <= m;k++){
//         vector<int>ne(a[k].size());
//         for(int i = 2, j = 0;i <= siz[k];i++){
//             while(j && a[k][i] != a[k][j+1]) j = ne[j];
//             if(a[k][i] == a[k][j+1]) j++;
//             ne[i] = j;
//         }
//         for(int i = 1, j = 0; i <= n; i++){
//             while(j && h[i] != a[k][j+1]) j = ne[j];
//             if(h[i] == a[k][j + 1]) j++;
//             if(j == siz[k]){
//                 vec[i-siz[k]+1].push_back(k);
//                 j = ne[j];
//             }
//         }
//     }

//     // for(int i = 1; i<= n;i++){
//     //     cerr << i << " : ";
//     //     for(auto e : vec[i]) cerr << e << ' ' << a[e].size() << ' ';
//     //     cerr << endl;
//     // }

//     vector<int>ans;
//     int ok = 0;
    
//     auto dfs = [&](auto self, int p) -> void {
//         if(p == n) {
//             ok = 1;
//             return;
//         }
//         for(int i = 0;i < vec[p].size();i++){
//             ans.push_back(vec[p][i]);
//             self(self, p+siz[vec[p][i]]-1);
//             if(ok) return;
//             ans.pop_back();
//         }
//     };

//     dfs(dfs, 1);

//     for(auto e : ans) cout << e << ' ';
    
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int inf = 0x3f3f3f3f3f3f3f3f;

// void solve(){
//     int n, h;
//     cin >> n >> h;
//     vector<int>x(n+5);
//     vector<vector<int>>f(n+5, vector<int>(n+5, inf));
//     for(int i = 1;i <= n;i++){
//         cin >> x[i];
//         f[i][i] = h;
//     }

//     auto val = [&](int x, int y) -> int {
//         return max(0ll, h - (y - x - 1) / 2);
//     };

//     for(int len = 2;len <= n;len++){
//         for(int i = 1, j = len;j <= n;i++, j++){
//             for(int k = i;k < j;k++){
//                 f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] - val(x[i], x[j]));
//             }
//         }
//     }

//     cout << f[1][n] << endl;
// }

// signed main(){

//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int inf = 0x3f3f3f3f3f3f3f3f;

// void solve(){
//     int n;
//     cin >> n;

//     if(n == 0){
//         cout << "0 0";
//         return;
//     }

//     vector<int>f(n+10, inf);

//     auto v = [&](int x) -> int {
//         return x*(x-1) / 2;
//     };

//     int m = 2;
//     f[0] = 0;
//     for(int i = 2;v(i) <= n;i++){
//         m = i;
//         int val = v(i);
//         for(int j = val;j <= 2*val && j <= n;j++){
//             f[j] = min(f[j], f[j-val]+i);
//         }
//     }

//     // for(int i = 0;i <= n;i++) cerr << f[i] << ' ';
//     // cerr << endl;

//     vector<int>a;

//     int cur = n, i = m;
//     while(cur){
//         while(cur >= v(i) && f[cur] == f[cur-v(i)] + i){
//             a.push_back(i);
//             cur -= v(i);
//         }
//         i--;
//     }
//     // cerr << "DEBU\n";

//     // for(auto e : a) cerr << e << ' ';
//     // cerr << endl;

//     vector<int>suf(a);
//     for(int i = suf.size()-2;i >= 0;i--) suf[i] += suf[i+1];

//     int sum = 0;
//     for(int i = 0;i+1 < suf.size();i++){
//         sum += a[i] * suf[i+1];
//     }

//     cout << suf[0] << ' ' << sum;
// }

// signed main(){

//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int inf = 0x3f3f3f3f3f3f3f3f;

// vector<int>a;

// int btot(int x){
//     int ret = 0, pw = 1;
//     for(int i = 0;(1<<i) <= x;i++) {
//         if((1<<i)&x) ret += pw;
//         pw *= 10;
//     }
//     return ret;
// }

// int check(int x){
//     while(x){
//         if(x % 10 != 0 && x % 10 != 1) return 0;
//         x /= 10;
//     }
//     return 1;
// }

// int dfs(int x){
//     if(check(x)) return 1;
//     for(auto e : a) {
//         if(e > x) break;
//         if(x % e) continue;
//         if(dfs(x / e)) return 1; 
//     }
//     return 0;
// }

// void solve(){
//     int n;
//     cin >> n;

//     if(dfs(n)) cout << "YES\n";
//     else cout << "NO\n";

// }

// signed main(){


//     for(int i = 2;i < (1<<6);i++){
//         a.push_back(btot(i));
//     }

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;


// void solve(){
//     int n;
//     cin >> n;
//     string a, b;
//     cin >> a >> b;

//     reverse(b.begin(), b.end());

//     map<array<char, 2>, int>mp;
//     map<array<char, 2>, int>mp2;
//     int cnt = 0;
//     for(int i = 0;i < n;i++){
//         if(a[i] == b[i]){
//             cnt++;
//             mp2[{a[i], a[i]}]++;
//         }else{
//             array<char, 2>ar = {min(a[i], b[i]), max(a[i], b[i])};
//             mp[ar]++;
//         }
//     }

//     if((n - cnt) & 1){
//         cout << "NO\n";
//         return;
//     }

//     cnt = 0;
//     for(auto [k, v] : mp2){
//         cnt += (v & 1);
//     }

//     if(cnt > 1) {
//         cout << "NO\n";
//         return;
//     }

//     // for(auto [k, v] : mp) cerr << k[0] << ' ' << k[1] << endl;

//     for(auto [k, v] : mp) if(v & 1){
//         cout << "NO\n";
//         return;
//     }

//     cout << "YES\n";
// }

// signed main(){

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }


// abcabdaa
// adabcaba


// cada
// acad


// abadaa
// adaaba


// abadaa
// abaada


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long



// void solve(){
//     string s;
//     cin >> s;
//     int n = s.size();
//     s = ' ' + s;
//     vector<int>ne(n+20);
//     vector<array<int,30>>ch(n+20);

//     for(int i = 2, j = 0;i <= n;i++){
//         while(j && s[i] != s[j+1]) j = ne[j];
//         if(s[i] == s[j+1]) j++;
//         ne[i] = j;
//     }
//     for(int i = 1;i <= n;i++){
//         // cerr << ne[i] << ' ';
//         for(int j = 'a';j <= 'z';j++){
//             if(i+1 <= n && s[i+1] == j) ch[i][j-'a'] = i;
//             else ch[i][j-'a'] = ch[ne[i]][j-'a'];
//         }
//     }

//     // for(int i = 1;i <= n;i++) cerr << ch[i][0] << ' ';
//     // cerr << endl;

//     int q;
//     cin >> q;
//     while(q--){
//         string t;
//         cin >> t;

//         for(auto c : t) s += c;

//         for(int i = max(2ll, n), j = ne[max(2ll, n)-1];i < s.size();i++){
//             while(j && s[i] != s[j+1]) j = ch[j][s[i]-'a'];
//             if(s[i] == s[j+1]) j++;
//             ne[i] = j;
//             for(int k = 'a';k <= 'z';k++){
//                 if(i+1 < s.size() && s[i+1] == k) ch[i][k-'a'] = i;
//                 else ch[i][k-'a'] = ch[ne[i]][k-'a'];
//             }
//         }

//         for(int i = n + 1;i < s.size();i++){
//             // if(i+1 < s.size()) cerr << ch[i][s[i+1]-'a'] << ' ';
//             cout << ne[i] << ' ';
//             ne[i] = 0;
//             for(int j = 'a';j <= 'z';j++) ch[i][j-'a'] = 0;
//         }
//         // cerr << endl;
//         cout << endl;

//         for(int i = 0;i < t.size();i++) s.pop_back();
//     }
// }

// signed main(){

//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()


// void solve(){
//     int n, k;
//     cin >> n >> k;
//     if(n == k){
//         for(int i = 1;i <= n;i++) cout << 1 << ' ';
//         cout << endl;
//     }else if(k == 1){
//         cout << 1 << ' ';
//         for(int i = 2;i <= n;i++) cout << 2 << ' ';
//         cout << endl;
//     }else{
//         cout << "-1\n";
//     }
// }

// signed main(){

//     IO;

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5), p(n+5), vis(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int cur = 0;
//     for(int i = 1, j = 1;i <= n;i++, j++){
//         // cerr << i << ' ';
//         while(a[j] < 0) j++;
//         p[j] = cur;
//         for(int k = i;k < j;k++){
//             p[k] = cur-a[k];
//             vis[p[k]] = 1;
//         }
//         vis[cur] = 1;
//         while(vis[cur]) cur++;
//         i = j;
//     }

//     for(int i = 1;i <= n;i++) cout << p[i] << ' ';
//     cout << endl;
// }

// signed main(){

//     IO;

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()

// const int N = 2e5 + 10;
// int f[N];

// void solve(){
//     int n, x, y;
//     cin >> n >> x >> y;
//     vector<int>a(x);
//     for(auto &e : a) cin >> e;

//     sort(all(a));
    
//     int ans = f[x];
//     for(int i = 0;i + 1 < x;i++){
//         if(a[i+1] - a[i] == 2) ans++;
//     }
//     if(a[x-1] + 2 - n == a[0]) ans++;

//     cout << ans << endl;
// }

// signed main(){

//     IO;

//     f[3] = 1;
//     for(int i = 4;i < N;i++){
//         f[i] = i/2 + f[(i+1)/2];
//     }

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()

// const int N = 2e5 + 10;
// int f[N];

// void solve(){
//     int n, x, y;
//     cin >> n >> x >> y;
//     int yy = y;
//     vector<int>a(x);
//     for(auto &e : a) cin >> e;

//     sort(all(a));
    
//     int ans = f[x];

//     vector<vector<int>>vec(2);

//     for(int i = 0;i < x;i++){
//         int d = (a[(i+1)%x] + n - a[i]) % n;
//         if(d == 2) ans++;
//         else if(d > 2) vec[d&1].push_back(d);
//     }

//     sort(all(vec[0]));
//     sort(all(vec[1]));

//     for(auto d : vec[0]) if(y >= 0){
//         if(y+1 >= d/2){
//             int g = d/2;
//             ans += g;
//             ans += g-1;
//             y -= g-1;
//         }else{
//             int g = y;
//             ans += g;
//             ans += g;
//             y = 0;
//         }
//     }
//     for(auto d : vec[1]) if(y >= 0){
//         int g = min(d/2, y);
//         ans += g;
//         ans += g;
//         y -= g;
//     }

//     cout << ans << endl;
// }

// signed main(){

//     IO;

//     f[3] = 1;
//     for(int i = 4;i < N;i++){
//         f[i] = i/2 + f[(i+1)/2];
//         // cerr << f[i] << endl;
//     }

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
 
 
 
// void solve(){
//     string s;
//     cin >> s;
//     int n = s.size();
//     s = ' ' + s;
//     vector<int>ne(n+20);
//     vector<array<int,30>>ch(n+20);
 
//     for(int i = 2, j = 0;i <= n;i++){
//         while(j && s[i] != s[j+1]) j = ne[j];
//         if(s[i] == s[j+1]) j++;
//         ne[i] = j;
//     }
//     for(int i = 1;i <= n;i++){
//         // cerr << ne[i] << ' ';
//         for(int j = 'a';j <= 'z';j++){
//             if(i+1 <= n && s[i+1] == j) ch[i][j-'a'] = i;
//             else ch[i][j-'a'] = ch[ne[i]][j-'a'];
//         }
//     }
 
//     // for(int i = 1;i <= n;i++) cerr << ch[i][0] << ' ';
//     // cerr << endl;
 
//     int q;
//     cin >> q;
//     while(q--){
//         string t;
//         cin >> t;
 
//         for(auto c : t) s += c;
 
//         for(int i = 'a';i <= 'z';i++){
//             if(s[2] == i) ch[1][i-'a'] = 1;
//             else ch[1][i-'a'] = 0;
//         }
//         for(int i = max(2ll, n), j = ne[max(2ll, n)-1];i < s.size();i++){
//             while(j && s[i] != s[j+1]) j = ch[j][s[i]-'a'];
//             if(s[i] == s[j+1]) j++;
//             ne[i] = j;
//             for(int k = 'a';k <= 'z';k++){
//                 if(i+1 < s.size() && s[i+1] == k) ch[i][k-'a'] = i;
//                 else ch[i][k-'a'] = ch[ne[i]][k-'a'];
//             }
//         }
 
//         for(int i = n + 1;i < s.size();i++){
//             // if(i+1 < s.size()) cerr << ch[i][s[i+1]-'a'] << ' ';
//             cout << ne[i] << ' ';
//             ne[i] = 0;
//             for(int j = 'a';j <= 'z';j++) ch[i][j-'a'] = 0;
//         }
//         // cerr << endl;
//         cout << endl;
 
//         for(int i = 0;i < t.size();i++) s.pop_back();
//     }
// }
 
// signed main(){
 
//     int T = 1;
//     // cin >> T;
//     while(T--) solve();
 
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long 
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()

// const int inf = 0x3f3f3f3f3f3f3f3f;

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<array<int, 2>>>g(n+5);
//     for(int i = 1, u, v, w;i <= m;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     vector<int>dis(n+5, inf);

//     priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>que;

//     int k;
//     cin >> k;
//     for(int i = 1, t;i <= k;i++){
//         cin >> t;
//         dis[t] = 0;
//         que.push({0, t});
//     }

//     while(que.size()){
//         auto [d, u] = que.top();
//         que.pop();
//         for(auto [v, w] : g[u]) if(d + w < dis[v]) {
//             dis[v] = w + d;
//             que.push({dis[v], v});
//         }
//     }

//     vector<int>fa(n+5), ans(n+5);
//     iota(all(fa), 0);
//     vector<set<int>>st(n+5);
//     int len = inf;

//     auto find = [&](auto self, int x) -> int {
//         return x == fa[x] ? x : fa[x] = self(self, fa[x]);
//     };
//     auto merg = [&](int a, int b) -> void {
//         a = find(find, a);
//         b = find(find, b);
//         if(a == b) return;
//         if(st[a].size() > st[b].size()) swap(a, b);
//         for(auto e : st[a]){
//             if(st[b].find(e) != st[b].end()){
//                 ans[e] = max(0ll, len-1);
//                 st[b].erase(e);
//             }else{
//                 st[b].insert(e);
//             }
//         }
//         st[a].clear();
//         fa[a] = b;
//     };

//     int q;
//     cin >> q;
//     for(int i = 1;i <= q;i++){
//         int s, t;
//         cin >> s >> t;
//         st[s].insert(i);
//         st[t].insert(i);
//     }

//     vector<int>P(n);
//     iota(all(P), 1);
//     sort(all(P), [&](int i, int j) -> int {return dis[i] > dis[j];});

//     for(auto e : P){
//         len = min(len, dis[e]);
//         for(auto [v, w] : g[e]) if(dis[v] >= len){
//             merg(e, v);
//         }
//     }

//     for(int i = 1;i <= q;i++) cout << ans[i] << endl;
// }

// signed main(){

//     IO;
//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define int long long
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define ls id << 1
// #define rs id << 1 | 1

// const int N = 1e5 + 10;
// int sum[N<<2], f[N<<2], a[N];

// vector<int>g[N];
// int n, q, tot, L[N], R[N], ta[N], liv[N];

// void up(int id){
//     sum[id] = sum[ls]*(f[ls]==0) + sum[rs]*(f[rs]==0);
// }
// void build(int id, int l, int r){
//     f[id] = 0;
//     if(l == r){
//         sum[id] = ta[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// void modify(int id, int l, int r, int ql, int qr, int x){
//     if(ql <= l && r <= qr) {
//         f[id] += x;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls, l, mid, ql, qr, x);
//     else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x);
//     else modify(ls, l, mid, ql, qr, x), modify(rs, mid + 1, r, ql, qr, x);
//     up(id);
// }
// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         sum[id] = v;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(ls, l, mid, x, v);
//     else change(rs, mid + 1, r, x, v);
//     up(id);
// }

// void dfs(int u, int fa){
//     L[u] = ++tot;
//     ta[tot] = a[u];
//     for(auto v : g[u]) if(v != fa){
//         dfs(v, u);
//     }
//     R[u] = tot;
// }

// void solve(){
//     cin >> n >> q;
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         liv[i] = 1;
//     }

//     dfs(1, 0);

//     build(1, 1, n);

//     while(q--){
//         int op, x, y;
//         cin >> op;
//         if(op == 1){
//             cin >> x >> y;
//             change(1, 1, n, L[x], y);
//         }else{
//             cin >> x;
//             if(liv[x]) modify(1, 1, n, L[x], R[x], -1);
//             else modify(1, 1, n, L[x], R[x], 1);
//             liv[x] ^= 1;
//         }
//         cout << sum[1] << endl;
//     }
// }

// signed main(){

//     IO;
    
//     solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define int long long
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define ls id << 1
// #define rs id << 1 | 1

// int mxn;
// const int N = 1e6 + 10;
// const ll M = N * 8;
// const ll mod = 1000000007;

// vector<int>idx;

// struct node{
//     ll sum, L, R, len;
//     bool tag;
//     node() : sum(0), L(0), R(0), tag(0), len(0) {};

//     node operator+(const node& e) const {
//         node ret;
//         ret.sum = (sum + e.sum) % mod;
//         // ret.len = (len + e.len) % mod;
//         ret.L = L;
//         ret.R = e.R;

//         if(R && e.L){
//             int tmp = (R + e.L) % mod;
//             ret.sum = (ret.sum-(R*(R+1)/2) + mod) % mod;
//             ret.sum = (ret.sum-(e.L*(e.L+1)/2) + mod) % mod;
//             ret.sum = (ret.sum + tmp*(tmp+1)/2) % mod;

//             if(L == len) ret.L = (ret.L+e.L) % mod;
//             if(e.R == e.len) ret.R = (ret.R + R) % mod;
//         }

//         return ret;
//     }   
// }tr[M];

// void settag(int id){
//     tr[id].tag = 1;
//     tr[id].sum = (tr[id].len * (tr[id].len+1) / 2) % mod;
//     tr[id].L = tr[id].R = tr[id].len;
// }
// void down(int id){
//     settag(ls);
//     settag(rs);
//     tr[id].tag = 0;
// }
// void up(int id){
//     int len = tr[id].len;
//     tr[id] = tr[ls] + tr[rs];
//     tr[id].len = len;
// }

// void modify(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         // cerr << l << " " << r << endl;
//         settag(id);
//         return;
//     }
//     if(tr[id].tag) return;
//     // if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls, l, mid, ql, qr);
//     else if(ql > mid) modify(rs, mid + 1, r, ql,qr) ;
//     else modify(ls, l, mid, ql, qr), modify(rs, mid + 1, r, ql, qr);
//     up(id);
// }

// node query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         // cerr << l << ' ' << r << endl;
//         // if(ql == qr) return tr[id];
//         // if(l == r && tr[id].sum){
//         //     node ret = tr[id];
//         //     if(l == ql){
//         //         ret.L = ret.R = ret.len = (idx[l]-idx[l-1]) % mod;
//         //     }else if(r-1 != ql) { 
//         //         ret.L = ret.R = ret.len = (idx[r-1]-idx[r-2]) % mod;
//         //     }
//         //     ret.sum = (ret.len*(ret.len+1)/2) % mod;
//         //     // cerr << l << ' ' << r << ' ' << ql << ' ' << qr << ' ';
//         //     // cerr << ret.len << ' ' << ret.sum << ' ' << ret.L << ' ' << ret.R << endl;
//         //     return ret;
//         // }
//         return tr[id];
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
// }

// void build(int id, int l, int r){
//     tr[id].len = (idx[r-1] - idx[l-1] + 1) % mod;
//     // cerr << id << ' ' << l << ' ' << r << ' ' << tr[id].len << endl;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
// }

// void solve(){
//     int q;
//     cin >> q;

//     vector<array<int,3>>vec(q+5);

//     for(int i = 1;i <= q;i++){
//         cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
//         idx.push_back(vec[i][1]);
//         idx.push_back(vec[i][2]);
//         idx.push_back(vec[i][1]-1);
//         idx.push_back(vec[i][1]+1);
//         idx.push_back(vec[i][2]-1);
//     }

//     sort(all(idx));
//     idx.erase(unique(all(idx)), idx.end());
//     mxn = idx.size();

//     for(int i = 1;i <= q;i++){
//         vec[i][1] = lower_bound(all(idx), vec[i][1]) - idx.begin() + 1;
//         vec[i][2] = lower_bound(all(idx), vec[i][2]) - idx.begin() + 1;

//         // cerr << vec[i][1] << ' ' << vec[i][2] << "  " << idx[vec[i][1]-1] << ' ' << idx[vec[i][2]-1] << endl;
//     }
//     // cerr << endl;

//     // for(int i = 0; i < idx.size();i++){
//     //     cerr << i+1 << ' ' << idx[i] << endl;
//     // }

//     build(1, 1, mxn);

//     for(int i = 1;i <= q;i++){
//         int op = vec[i][0];
//         int x = vec[i][1];
//         int y = vec[i][2];

//         // cout << op << ' ' << idx[x-1] << ' ' << idx[y-1] << endl;

//         if(op == 1){
//             modify(1, 1, mxn, x, y);
//             // cerr << endl;
//         }else{
//             // node ret = query(1, 1, mxn, x, y);
//             // cerr << ret.sum << ' ' << ret.len << endl;
//             cout << query(1, 1, mxn, x, y).sum << endl;
//         }
//     }
// }

// signed main(){

//     IO;
    
//     solve();

//     return 0;
// }


        // if(f && llen == 1){ //左为叶子
        //     llen = (idx[e.l-1] - idx[r-1]) % mod;
        //     ret.L = llen;
        //     ret.R = e.R;
        //     ret.sum = (llen*(llen+1)/2) % mod;
        //     ret.sum = (ret.sum + e.sum) % mod;
            
        //     if(e.L){
        //         ret.sum = (ret.sum - ((llen*(llen+1)/2)%mod) - ((e.L*(e.L+1)/2)%mod) + mod*2) % mod;
        //         ret.sum = (ret.sum + (((llen+e.L)*(llen+e.l+1)/2) % mod)) % mod;
        //         ret.L = llen + e.L;
        //         if(e.R == rlen) ret.R = ret.L;
        //     }

        //     return ret;
        // }

        // if(e.f && rlen == 1){ //右为叶子
        //     rlen = (idx[e.r-1] - idx[r-1]) % mod;
        //     ret.L = L;
        //     ret.R = rlen;
        //     ret.sum = (rlen*(rlen+1)/2) % mod;
        //     ret.sum = (ret.sum + sum) % mod;
            
        //     if(R){
        //         ret.sum = (ret.sum - ((rlen*(rlen+1)/2) % mod) - ((ret.sum + sum) % mod) + mod*2) % mod;
        //         ret.sum = (ret.sum + )
        //     }
        // }


// #include<bits/stdc++.h>
// using namespace std;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// using ll = long long;

// const int mod = 1000000007;
// const int N = 2e6 + 5;

// vector<ll>idx;
// ll Len(int l, int r){
//     return (idx[r] - idx[l] + 1) % mod;
// }

// struct node{
//     ll sum, L, R;
//     int l, r;
//     bool f, tag;

//     node() : sum(0), L(0), R(0), l(0), r(0), f(0), tag(0) {};
//     node(int x) : sum((x*(x+1)/2)%mod), L(x), R(x), f(1) {};

// }tr[N<<2];

// node operator+(node l, node r) {
//     node ret;

//     ret.l = l.l, ret.r = r.r;
//     ll len = Len(ret.l, ret.r);
//     ll llen = Len(l.l, l.r);
//     ll rlen = Len(r.l, r.r);

//     ret.f = l.f && r.f;
//     if(ret.f){
//         ret.L = ret.R = len;
//         ret.sum = (len*(len+1)/2) % mod;
//         return ret;
//     }

//     if(l.f && llen != (idx[r.l-1] - idx[l.l-1]) % mod){
//         l = node((idx[r.l-1] - idx[l.l-1]) % mod);
//     }

// }

// void build(int id, int l, int r) {
//     tr[id].l = l, tr[id].r = r;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
// }

// void up(int id){
//     tr[id] = tr[ls] + tr[rs];
// }
// void settag(int id){
//     tr[id].f = tr[id].tag = 1;
//     int len = (idx[tr[id].r-1] - idx[tr[id].l-1] + 1) % mod;
//     tr[id].sum = (len * (len+1) / 2) % mod;
//     tr[id].L = tr[id].R = len;
// }
// void down(int id){
//     settag(ls);
//     settag(rs);
//     tr[id].tag = 0;
// }

// void add(int id, int ql, int qr){
//     if(ql <= tr[id].l && tr[id].r <= qr) {
//         settag(id);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = tr[id].l + tr[id].r >> 1;
//     if(qr <= mid) add(ls, ql, qr);
//     else if(ql > mid) add(rs, ql, qr);
//     else add(ls, ql, qr), add(rs, ql, qr);
//     up(id);
// }
// node query(int id, int ql, int qr) {

// }


// void solve(){
//     int q;
//     cin >> q;

//     vector<array<ll, 3>>qur(q+3);
//     for(int i = 1;i <= q;i++){
//         cin >> qur[i][0] >> qur[i][1] >> qur[i][2];
//         idx.push_back(qur[i][1]);
//         idx.push_back(qur[i][2]);
//     }

//     sort(all(idx));
//     idx.erase(unique(all(idx)), idx.end());

//     for(int i = 1;i <= q;i++){
//         qur[i][1] = lower_bound(all(idx), qur[i][1]) - idx.begin() + 1;
//         qur[i][2] = lower_bound(all(idx), qur[i][2]) - idx.begin() + 1;
//     }

//     int n = idx.size();

//     build(1, 1, n);

//     for(int i = 1;i <= q;i++){
//         auto [op, l, r] = qur[i];
//         if(op == 1){
//             add(1, l, r);
//         }else{
//             cout << query(1, l, r).sum << endl;
//         }
//     }
// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;


// class Tree{
// public:
// 	vector<int>tr;
// 	int n;
// 	Tree(int n) : n(n), tr(n+5) {};
// 	static int lowbit(int x) {
// 		return x & -x;
// 	}
// 	void add(int x, int v){
// 		while(x <= n){
// 			tr[x] += v;
// 			x += lowbit(x);
// 		}
// 	}
// 	int getsum(int x){
// 		int ret = 0;
// 		while(x){
// 			ret += tr[x];
// 			x -= lowbit(x);
// 		}
// 		return ret;
// 	}
// };



// #include <bits/stdc++.h>
// #define int __int128
// using namespace std;
// const int mod=1e9+7;
// struct node{
// 	int sum,lzt,lmax,rmax,len;
// };
// node empty(){
// 	node x;
// 	x.sum=x.lzt=x.lmax=x.rmax=x.len=0;
// 	return x; 
// }
// int a[4000005],k,opt[1000005],ll[1000005],rr[1000005];
// struct sgt{
// 	node f[16000005];
// 	node merge(node x,node y){
// 		node z=empty();
// 		z.sum=x.sum+y.sum+x.rmax*y.lmax;
// 		if(y.rmax==y.len) z.rmax=x.rmax+y.rmax;
// 		else z.rmax=y.rmax;
// 		if(x.lmax==x.len) z.lmax=x.lmax+y.lmax;
// 		else z.lmax=x.lmax;
// 		z.len=x.len+y.len;
// 		return z;
// 	}
// 	void pushdown(int i){
// 		if(f[i].lzt==1){
// 			f[i*2].lmax=f[i*2].rmax=f[i*2].sum=f[i*2].len;
// 			f[i*2].sum=f[i*2].len*(f[i*2].len+1)/2;
// 			f[i*2].lzt=1;
// 			f[i*2+1].lmax=f[i*2+1].rmax=f[i*2+1].sum=f[i*2+1].len;
// 			f[i*2+1].sum=f[i*2+1].len*(f[i*2+1].len+1)/2;
// 			f[i*2+1].lzt=1;
// 			f[i].lzt=0;
// 		}
// 	}
// 	void build(int i,int l,int r){
// 		if(l==r){
// 			f[i]=empty();
// 			f[i].len=a[l]-a[l-1];
// 			return ;
// 		}
// 		int mid=(l+r)>>1;
// 		build(i*2,l,mid);
// 		build(i*2+1,mid+1,r);
// 		f[i]=merge(f[i*2],f[i*2+1]);
// 	}
// 	void change(int i,int l,int r,int ql,int qr){
// 		if(ql<=l&&qr>=r){
// 			f[i].lmax=f[i].rmax=f[i].sum=f[i].len;
// 			f[i].sum=f[i].len*(f[i].len+1)/2;
// 			f[i].lzt=1;
// 			return ;
// 		}
// 		if(r<ql||l>qr){
// 			return ;
// 		}
// 		pushdown(i);
// 		int mid=(l+r)>>1; 
// 		change(i*2,l,mid,ql,qr);
// 		change(i*2+1,mid+1,r,ql,qr);
// 		f[i]=merge(f[i*2],f[i*2+1]);
// 	}
// 	node qry(int i,int l,int r,int ql,int qr){
// 		if(ql<=l&&qr>=r){
// 			return f[i];
// 		}
// 		if(r<ql||l>qr){
// 			return empty();
// 		}
// 		pushdown(i);
// 		int mid=(l+r)>>1;
// 		return merge(qry(i*2,l,mid,ql,qr),qry(i*2+1,mid+1,r,ql,qr));
// 	}
// }tree;
// signed main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);
// 	int n;
// 	long long N;
// 	cin>>N;
// 	n=N;
// 	for(int i=1;i<=n;i++){
// 		long long OPT,LL,RR;
// 		cin>>OPT>>LL>>RR;
// 		opt[i]=OPT,ll[i]=LL,rr[i]=RR;
// 		k++;
// 		a[k]=ll[i]-1;
// 		k++;
// 		a[k]=rr[i];
// 	}
// 	sort(a+1,a+k+1);
// 	for(int i=1;i<=n;i++){
// 		ll[i]=(lower_bound(a+1,a+k+1,ll[i]-1)-a)+1;
// 		rr[i]=lower_bound(a+1,a+k+1,rr[i])-a;
// 	}

//     for(int i = 1;i <= k;i++){
//         cout<<i<< ' ' << a[i] << endl;
//     }
// 	tree.build(1,1,k);
// 	for(int i=1;i<=n;i++){
// 		if(opt[i]==1){
// 			tree.change(1,1,k,ll[i],rr[i]);
// 		}
// 		else{
// 			int tt=tree.qry(1,1,k,ll[i],rr[i]).sum%mod;
// 			long long TT=tt;
// 			cout<<TT<<endl;
// 		}
// 	}
// 	return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//         cout << "p n a e t y ";
//         cout << "r i t s f ";

//         return 0;

// }



// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
       
// }

// int main(){

//         cout << "NO NO";

//         // int t = 1;
//         // cin >> t;
//         // while(t--) solve();

//         return 0;

// }



// #include<bits/stdc++.h>
// #define int long long
// using namespace std;

// string ans;

// int pint(int x){
//         int f = (x < 0);
//         if(f) x = -x;
//         string s = to_string(x);
//         for(int q = 0, p = s.size()-1;q <= p;q++, p--){
//                 s[q] = (s[q]-'0')/2 + '0';
//                 s[p] = s[q];
//         }
//         if(f) return -stoll(s);
//         return stoll(s);
// }

// void push(int x){
//         if(x > 0){
//                 ans.push_back('+');
//                 ans += (to_string(x));
//                 ans.push_back('-');
//         }else{
//                 ans += (to_string(x));
//                 ans.push_back('+');
//         }
//         ans += '0';
// }
 
// void add(int x){

// }
// void sdiv(int x){

// }

// void solve(){
//         int a, b;
//         cin >> a >> b;
//         int d = a - b;
//         int s = 0;

//         ans += '0';
//         while(1){
//                 int nd = pint(d-s);
//                 if(!nd) break;
//                 s += nd;
//                 push(nd);
//         }

//         // cout << ans << endl;

//         while(1){
//                 int nd = d - s;
//                 if(!nd) break;
//                 int f = (nd < 0);
//                 if(f) nd = -nd;

//                 int x = 0;
//                 while(nd){
//                         x++;
//                         nd /= 10;
//                 }
//                 if(f){
//                         add(x);
//                         s += pow(10, x-1);
//                         if(x > 1) s++;
//                 }
//                 else{
//                         sdiv(x);
//                         s -= pow(10, x-1);
//                         if(x > 1) s--;
//                 }
//         }
// }

// signed main(){

//         solve();

//         return 0;

// }





// #include<bits/stdc++.h>
// #define int long long
// using namespace std;

// string ans, s;


// void solve(){
//         int a, b;
//         cin >> a >> b;
//         int d = a-b;
//         int cur = 0;

//         ans += '0';

//         if(abs(d) % 2){
//                 ans += "+12+0";
//                 cur = 12;
//                 d += 9;
//         }

//         if(d)
//         {
//                 s = to_string(d);
//                 if(d > 0) s = '+' + s;
//                 vector<int>vis(s.size() + 2);
//                 for(int i = 1;i < s.size();i++){
//                         if((s[i]-'0') & 1) vis[i+1] = 1;
//                         s[i] = (s[i]-'0')/2 + '0';
//                         if(vis[i]) s[i] += 5;
//                 }
//                 string tmp(1, s[0]);
//                 int fg = 0;
//                 for(int i = 1;i < s.size();i++) {
//                         if(s[i] != '0') fg = 1;
//                         if(fg) tmp += s[i];
//                 }
//                 fg = 0;

//                 if(tmp.size() > 1 && tmp.back() == '0'){
//                         fg = 1;
//                         tmp.back() = '1';
//                 }

//                 s = tmp;
//                 ans += s;
//                 ans += s;
//                 cur += stoll(s)*2;
//                 if(s[0] == '+'){
//                         ans += '-';
//                         if(fg){
//                                 ans += "0-1-1+";
//                                 cur -= 2;
//                         }
//                 }else{
//                         ans += '+';
//                         if(fg){
//                                 ans += "0+1+1-";
//                                 cur += 2;
//                         }
//                 }
//                 ans += '0';
//         }


//         while(cur != a){
//                 d = a - cur;
//                 s = to_string(d);
//                 if(d >= 0) s = '+' + s;
//                 for(int q = 1, p = s.size()-1;q <= p;q++, p--){
//                         s[p] = s[q];
//                 }
//                 ans += s + s[0] + '0';
//                 cur += stoll(s);
//         }

//         cout << ans << endl;

// }

// signed main(){

//         solve();

//         return 0;

// }




// #include<bits/stdc++.h>
// #define int long long
// using namespace std;



// void solve(){
//         int n;
//         cin >> n;
//         if(n == 1){
//                 cout << "1\n1 0\n";
//                 return;
//         }
//         vector<vector<int>>g(n+5);
//         for(int i = 1, u, v;i < n;i++){
//                 cin >> u >> v;
//                 g[u].push_back(v);
//                 g[v].push_back(u);
//         }

//         vector<int>dep(n+5), mx(n+5), R(n+5);
//         vector<array<int,2>>mxs(n+5);
//         mx[0] = -1;
        
//         auto MX = [&](int i, int j) -> int {
//                 if(mx[i] > mx[j]) return i;
//                 return j;
//         };

//         auto dfs = [&](auto self, int u, int fa) -> void {
//                 dep[u] = dep[fa] + 1;
//                 mx[u] = 0;
//                 mxs[u] = {0,0};
//                 for(auto v : g[u]) if(v != fa){
//                         self(self, v, u);
//                         mx[u] = max(mx[u], mx[v] + 1);
//                         mxs[u][1] = MX(mxs[u][1], v);
//                         if(MX(mxs[u][0], mxs[u][1]) == mxs[u][1]) swap(mxs[u][1], mxs[u][0]);
//                 }
//         };

//         int rt = 1;
//         auto dfs2 = [&](auto self, int u, int fa, int hdep) -> void {
//                 R[u] = max(hdep, mx[u]);
//                 if(R[u] < R[rt]) rt = u;
//                 // cerr << u << ' ' << hdep << endl;
//                 for(auto v : g[u]) if(v != fa){
//                         if(v == mxs[u][0]){
//                                 self(self, v, u, max(hdep+1, mxs[u][1] ? mx[mxs[u][1]]+2 : 0));
//                         }else{
//                                 self(self, v, u, max(hdep+1, mxs[u][0] ? mx[mxs[u][0]]+2 : 0));
//                         }
//                 }
//         };

//         dfs(dfs, 1, 0);
//         dfs2(dfs2, 1, 0, 0);
//         dfs(dfs, rt, 0);

//         int len = R[rt] + 1;

//         // cerr << rt << ' ' << len << endl;
//         // cerr << mxs[rt][0] << ' ' << mxs[rt][1] << endl;

//         if(len == 2){
//                 cout << "2\n" << rt << ' ' << 0 << '\n' << rt << ' ' << 1 << endl;
//                 return;
//         }

//         // cerr << len << endl;

//         vector<array<int, 2>>ans;

//         if(mx[mxs[rt][0]] == mx[mxs[rt][1]]){
//                 for(int i = 0;i < len;i++) ans.push_back({rt, i});
//         }else{
//                 if(((len-1)*2) % 4){
//                         for(int i = 0;i < len;i++) ans.push_back({rt, i});
//                 }else{
//                 // cerr << "len\n";
//                         for(int i = 1;i < len;i += 2){
//                                 ans.push_back({rt, i});
//                                 ans.push_back({mxs[rt][0], i});
//                         }
//                 }
//         }

//         cout << ans.size() << endl;
//         for(auto [x, y] : ans) cout << x << ' ' << y << endl;
// }

// signed main(){

//         int t = 1;
//         cin >> t;
//         while(t--)
//         solve();

//         return 0;

// }




// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// #define all(x) (x).begin(), (x).end()


// void solve(){
//         int n, m;
//         cin >> n >> m;
//         vector<vector<int>>g(n+5);
//         int mx = 0;
//         for(int i = 1, u, v;i <= m;i++){
//                 cin >> u >> v;
//                 g[u].push_back(v);
//                 mx = max(mx, (int)g[u].size());
//         }
//         vector<double>p(n+5);
//         vector<vector<double>>f(n+5, vector<double>(mx+5));


//         f[1][1] = 1;
//         f[2][1] = 0.5;
//         for(int i = 3;i <= mx;i++){
//                 f[i][1] = 1.0/i;
//                 for(int j = 2;j <= i;j++){
//                         f[i][j] = f[i-2][j-2] * ((1.0*j-2)/i) + f[i-2][j-1] * ((1.0*(i-j))/i);
//                 }
//         }

//         p[n] = 1;
//         for(int i = n-1;i >= 1;i--){
//                 sort(all(g[i]), [&](int i, int j) -> int {return p[i] > p[j];});
//                 // cerr << i << " : ";
//                 for(int j = 1;j <= g[i].size();j++){
//                         // cerr << g[i][j-1] << ' ';
//                         p[i] += f[g[i].size()][j] * p[g[i][j-1]];
//                 }
//                 // cerr << endl;
//         }

//         // for(int i = 1;i <= n;i++) cerr << p[i] << ' ';
//         // cerr << endl;

//         // for(int i = 1;i <= mx;i++) cerr << f[mx][i] << ' ';

//         printf("%.12lf\n", p[1]);
// }

// signed main(){

//         int t = 1;
//         cin >> t;
//         while(t--)
//         solve();

//         return 0;

// }





// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// #define all(x) (x).begin(), (x).end()


// void solve(){
//         int n;
//         cin >> n;
//         vector<int>a(n+5);
//         for(int i = 1;i <= n;i++){
//                 cin >> a[i];
//         }

//         int ans = n;
//         map<int,int>mp;
//         mp[0] = 1;
//         int x = 0;
//         for(int i = 1;i <= n;i++){
//                 x ^= a[i];
//                 if(mp[x]) {
//                         ans--;
//                         x = 0;
//                         mp.clear();
//                 }
//                 mp[x] = 1;
//         }

//         cout << ans << endl;
// }

// signed main(){

//         int t = 1;
//         cin >> t;
//         while(t--)
//         solve();

//         return 0;

// }




// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// #define all(x) (x).begin(), (x).end()


// void solve(){
//         int n;
//         int sum = 0;
//         priority_queue<array<int,2>>q;
//         cin >> n;
//         for(int i = 1, x;i <= n;i++){
//                 cin >> x;
//                 sum += x;
//                 q.push({x, i});
//         }

//         if(sum == 1){
//                 cout << "YES\n";
//                 return;
//         }
//         if(sum == 2){
//                 if(q.size() == 2) cout << "YES\n";
//                 else cout << "NO\n";
//                 return;
//         }

//         vector<int>a(2, 1);
//         int c1 = 1, c2 = 1;
//         sum -= 2;
//         while(sum > 0) {
//                 a.push_back(c1 + c2);
//                 sum -= a.back();
//                 c1 = c2;
//                 c2 = a.back();
//         }

//         if(sum < 0) {
//                 cout << "NO\n";
//                 return;
//         }

//         // for(auto e : a) cerr << e << ' ';
//         // cerr << endl;

//         int last = 0;
//         for(int i = a.size()-1;i >= 0;i--){
//                 int s = a[i];
//                 auto [v, k] = q.top();
//                 q.pop();
//                 if(s > v){
//                         cout << "NO\n";
//                         return;
//                 }
//                 if(k == last){
//                         if(q.size() && q.top()[0] == v){
//                                 auto [v2, k2] = q.top();
//                                 q.pop();
//                                 q.push({v, k});
//                                 v2 -= s;
//                                 q.push({v2, k2});
//                                 last = k2;
//                         }else{
//                                 cout << "NO\n";
//                                 return;
//                         }
//                 }else{
//                         v -= s;
//                         q.push({v, k});
//                         last = k;
//                 }
//         }

//         cout << "YES\n";
// }

// signed main(){

//         int t = 1;
//         cin >> t;
//         while(t--)
//         solve();

//         return 0;

// }




// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()


// const int N = 2e5 + 100;
// bool isprime[N];
// int prime[N];
// int cnt;

// void euler(){
//     memset(isprime, true, sizeof(isprime));
//     isprime[1] = false;
//     for(int i = 2;i < N;i++){
//         if(isprime[i]) prime[++cnt] = i;
//         for(int j = 1; j <= cnt && prime[j] * i < N;j++){
//             isprime[prime[j]*i] = false;
//             if(i % prime[j] == 0) break;
//         }
//     }
// }


// void solve(){
//         int n, q;
//         cin >> n >> q;
//         vector<int>a(n+5), fac;
//         for(int i = 1;i <= n;i++) cin >> a[i];

//         int tmp = n;
//         for(int i = 2;i <= tmp;i++) if(tmp % i == 0){
//                 fac.push_back(n/i);
//                 while(tmp % i == 0) tmp /= i;
//         }

//         fac.push_back(1);
//         for(int i = 2;i < n;i++) if(n % i == 0 && isprime[i]){
//                 fac.push_back(i);
//         }
//         vector<vector<int>>sum(fac.size());
//         multiset<int>st;

//         int ans = 0;
//         for(int i = 0;i < fac.size();i++){
//                 sum[i].resize(fac[i]);
//                 for(int j = 1;j <= n;j++){
//                         int m = j % fac[i];
//                         sum[i][m] += a[j];
//                 }
//                 for(int j = 0;j < fac[i];j++) st.insert(fac[i]*sum[i][j]);
//         }

//         cout << *st.rbegin() << endl;
//         while(q--){
//                 int p, x;
//                 cin >> p >> x;

//                 for(int i = 0;i < fac.size();i++){
//                         int m = p % fac[i];
//                         st.erase(st.find(sum[i][m]*fac[i]));
//                         sum[i][m] -= a[p];
//                         sum[i][m] += x;
//                         st.insert(sum[i][m]*fac[i]);
//                 }
//                 a[p] = x;

//                 cout << *st.rbegin() << endl;
//         }

// }

// signed main(){

//         IO;
//         euler();
//         // int t = 1;
//         // cin >> t;
//         // while(t--)
//         // solve();

//         int n = 176400;
//         vector<int>fac1;
//         vector<int>fac2;

//         int tmp = n;
//         for(int i = 2;i <= tmp;i++) if(tmp % i == 0){
//                 fac1.push_back(n/i);
//                 while(tmp % i == 0) tmp /= i;
//         }

//         fac2.push_back(1);
//         for(int i = 2;i < n;i++) if(n % i == 0 && isprime[i]){
//                 fac2.push_back(i);
//         }

//         for(auto e : fac1) cerr << e << ' ';
//         cerr << endl;
//         for(auto e : fac2) cerr << e << ' ';
//         cerr << endl;

//         return 0;

// }




// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()


// void solve(){
//         int n, m;
//         cin >> n >> m;
//         vector<int>a(n+5), b(m+5);
//         for(int i = 1;i <= n;i++) cin >> a[i];
//         for(int i = 1;i <= m;i++) cin >> b[i];

//         vector<int>f(n+1);
//         for(int i = n;i >= 1;i--){
//                 for(int j = n-i;j >= 1;j--){
//                         f[j] = min(max(0ll, f[j]-a[i]), f[j-1]);
//                 }
//                 f[0] = max(0ll, f[0]-a[i]);
//         }

//         // for(int i = 0;i <= n;i++) cerr << f[i] << ' ';
//         // cerr << endl;

//         for(int i = 1;i <= m;i++){
//                 cout << n-(upper_bound(f.rbegin(), f.rend(), b[i]) - f.rbegin() - 1) << endl;
//         }
// }

// signed main(){

//         IO;

//         solve();        

//         return 0;

// }



// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()

// const int mod = 998244353;

// void solve(){
//         int n, k;
//         cin >> n >> k;
//         vector<vector<vector<int>>>f(n+5, vector<vector<int>>(k+5, vector<int>(n/k+2))), suf(n+5, vector<vector<int>>(k+5, vector<int>(n/k+2)));

//         f[0][0][0] = 1;

//         for(int i = 1;i <= n;i++){
//                 for(int j = 0;j < k;j++){
//                         for(int c = 0;c <= n/k;c++){
//                                 if(j+c*k > i) break;

//                                 if(j == 0){
//                                         if(c) f[i][j][c] = (f[i-1][k-1][c-1] + f[i-1][0][c]) % mod;
//                                 }else{
//                                         f[i][j][c] = f[i-1][j-1][c] * (k-(j-1)) % mod;
//                                         f[i][j][c] = (f[i][j][c] + suf[i-1][j][c]) % mod;
//                                 }
//                         }
//                 }

//                 for(int c = 0;c <= n/k;c++){
//                         suf[i][k][c] = f[i][0][c];
//                         for(int j = k-1;j >= 1;j--){
//                                 // if(i == 1) cerr << j << ' ' << c << endl;
//                                 if(j+c*k > i) continue;
//                                 suf[i][j][c] = (f[i][j][c] + suf[i][j+1][c]) % mod;
//                         }
//                 }
//         }

//         int ans = 0;
//         for(int i = 0;i < k;i++){
//                 for(int j = 1;j <= n/k;j++){
//                         if(i+j*k > n) break;
//                         ans = (ans + (f[n][i][j] * j % mod)) % mod;
//                 }
//         }

//         cout << ans << endl;

//         // cerr << suf[1][1][0] << endl;
//         cerr << f[1][1][0] << endl;
//         cerr << f[2][1][0] << endl;
//         cerr << f[3][2][0] << endl;
//         cerr << f[4][0][1] << endl;
// }

// signed main(){

//         IO;

//         solve();        

//         return 0;

// }




// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()

// const int mod = 998244353;

// void solve(){
//         int n, k;
//         cin >> n >> k;
//         // vector<vector<vector<int>>>f(n+1, vector<vector<int>>(n/k+2, vector<int>(k+1))), suf(n+1, vector<vector<int>>(n/k+2, vector<int>(k+1)));
//         vector<vector<int>>f(n/k+5, vector<int>(k+5)), suf(n/k+5, vector<int>(k+5));

//         f[0][0] = 1;
//         for(int i = 1;i <= n;i++){
//                 for(int c = n/k;c >= 0;c--){
//                         if(c*k > i) continue;
//                         if(c) f[c][0] = f[c-1][k-1];
//                         for(int x = k-1;x >= 1;x--){
//                                 suf[c][x+1] = 0;
//                                 if(x+c*k > i) continue;

//                                 f[c][x] = ((f[c][x-1]*(k-x+1) % mod) + suf[c][x]) % mod;
//                         }
//                         for(int x = k-1;x >= 1;x--)
//                                 suf[c][x] = (f[c][x] + suf[c][x+1]) % mod;
//                 }
//         }

//         int ans = 0;
//         for(int i = 1;i <= n/k;i++){
//                 for(int j = 0;j < k;j++){
//                         if(i*k+j > n) break;
//                         ans = (ans + (f[i][j]*i%mod)) % mod;
//                 }
//         }

//         cout << ans << endl;

//         // cerr << f[3][1][0] << endl;
//         // cerr << f[6][2][0] << endl;
//         // cerr << f[9][3][0] << endl;
//         // cerr << f[10][3][1] << endl;

//         // cerr << f[2][1][0] << endl;

// }

// signed main(){

//         IO;

//         solve();        

//         return 0;

// }




// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()

// const int mod = 998244353;

// void solve(){
//         int n, k;
//         cin >> n >> k;
//         vector<vector<vector<int>>>f(2, vector<vector<int>>(n/k+2, vector<int>(k+1))), suf(2, vector<vector<int>>(n/k+2, vector<int>(k+1)));

//         f[0][0][0] = 1;
//         for(int i = 1;i <= n;i++){
//                 for(int c = 0;c <= n/k;c++){
//                         if(c*k > i) break;
//                         if(c) f[i&1][c][0] = f[!(i&1)][c-1][k-1];
//                         for(int x = 1;x < k;x++){
//                                 if(x+c*k > i) break;

//                                 f[i&1][c][x] = ((f[!(i&1)][c][x-1]*(k-x+1) % mod) + suf[!(i&1)][c][x]) % mod;
//                         }
//                         for(int x = k-1;x >= 1;x--) {
//                                 suf[i&1][c][x] = 0;
//                         }
//                         for(int x = k-1;x >= 1;x--) {
//                                 suf[i&1][c][x] = (f[i&1][c][x] + suf[i&1][c][x+1]) % mod;
//                         }
//                 }
//         }

//         int ans = 0;
//         for(int i = 1;i <= n/k;i++){
//                 for(int j = 0;j < k;j++){
//                         if(i*k+j > n) break;
//                         ans = (ans + (f[n&1][i][j]*i%mod)) % mod;
//                 }
//         }

//         cout << ans << endl;
// }

// signed main(){

//         IO;

//         solve();        

//         return 0;

// }



// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()

// const int mod = 998244353;

// void solve(){
//         int n, k;
//         cin >> n >> k;
//         vector<vector<vector<int>>>f(2, vector<vector<int>>(n/k+2, vector<int>(k+1))), suf(2, vector<vector<int>>(n/k+2, vector<int>(k+1)));

//         f[0][0][0] = 1;
//         for(int i = 1;i <= n;i++){
//                 for(int c = 0;c <= n/k;c++)
//                         for(int x = 0;x <= k;x++)
//                                 f[i&1][c][x] = suf[i&1][c][x] = 0;

//                 for(int c = 0;c <= n/k;c++){
//                         if(c*k > i) break;
//                         if(c) f[i&1][c][0] = f[(i&1)^1][c-1][k-1];
//                         for(int x = 1;x < k;x++){
//                                 if(x+c*k > i) break;

//                                 f[i&1][c][x] = ((f[(i&1)^1][c][x-1]*(k-x+1) % mod) + suf[(i&1)^1][c][x]) % mod;
//                         }
//                         for(int x = k-1;x >= 1;x--) {
//                                 suf[i&1][c][x] = (f[i&1][c][x] + suf[i&1][c][x+1]) % mod;
//                         }
//                 }
//         }

//         int ans = 0;
//         for(int i = 1;i <= n/k;i++){
//                 for(int j = 0;j < k;j++){
//                         if(i*k+j > n) break;
//                         ans = (ans + (f[n&1][i][j]*i%mod)) % mod;
//                 }
//         }

//         cout << ans << endl;

// }

// signed main(){

//         IO;

//         solve();        

//         return 0;

// }