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