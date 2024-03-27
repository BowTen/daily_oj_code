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