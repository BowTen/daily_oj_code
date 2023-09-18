// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, k, a[N];

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     if(k == 1){
//         for(int i = 1;i <= n;i++) if(a[i] != i){
//             cout << "NO\n";
//             return;
//         }
//         cout << "YES\n";
//         return;
//     }

//     vector<int>vis(n + 1);
//     for(int i = 1;i <= n;i++) if(!vis[i]){
//         int cur = i;
//         vector<int>cyc;
//         while(!vis[cur]){
//             vis[cur] = 1;
//             cyc.push_back(cur);
//             cur = a[cur];
//         }
//         int siz = 0;
//         for(auto it = cyc.begin();it != cyc.end();it++){
//             if(*it == cur){
//                 siz = cyc.end() - it;
//                 break;
//             }
//         }
//         if(siz != k && siz){
//             cout << "NO\n";
//             return;
//         }
//     }
//     cout << "YES\n";
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, a[N];

// int tr[1<<9][2], tot;

// void init(){
//     tot = 0;
//     memset(tr, 0, sizeof(tr));
// }

// void insert(int x){
//     int p = 0;
//     for(int i = 7;i >= 0;i--){
//         int ne = (1 << i) & x;
//         if(!tr[p][ne]) tr[p][ne] = ++tot;
//         p = tr[p][ne];
//     }
// }

// int query(int x){
//     int ret = 0, p = 0;
//     for(int i = 7;i >= 0;i--){
//         ret <<= 1;
//         int ne = (1 << i) & x;
//         if(tr[p][!ne]){
//             ret++;
//             p = tr[p][!ne];
//         }else p = tr[p][ne];
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     init();
//     int ans = 0;
//     insert(0);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         a[i] ^= a[i-1];
//         ans = max(ans, query(a[i]));
//         insert(a[i]);
//     }
//     cout << ans << endl;
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, a[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     if(n & 1){
//         cout << 4 << '\n';
//         cout << 1 << ' ' << n << '\n' << 1 << ' ' << n - 1 << '\n' << n-1 << ' ' << n << '\n' << n-1 << ' ' << n << '\n';
//     }else{
//         cout << 2 << '\n';
//         cout << 1 << ' ' << n << '\n' << 1 << ' ' << n << '\n';
//     }
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, k, a, b, x[N], y[N];

// void solve(){
//     cin >> n >> k >> a >> b;
//     for(int i = 1;i <= n;i++) cin >> x[i] >> y[i];

//     int mntob = LLONG_MAX;
//     for(int i = 1;i <= k;i++){
//         mntob = min(mntob, abs(x[b] - x[i]) + abs(y[b] - y[i]));
//     }
//     int mntoa = LLONG_MAX;
//     for(int i = 1;i <= k;i++){
//         mntoa = min(mntoa, abs(x[a] - x[i]) + abs(y[a] - y[i]));
//     }
//     if(k == 0) cout << abs(x[a] - x[b]) + abs(y[a] - y[b]) << '\n';
//     else cout << min(mntoa + mntob, abs(x[a] - x[b]) + abs(y[a] - y[b])) << '\n';
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     cin >> n >> m;
//     if(m == 1){
//         for(int i = 0;i <= n;i++) cout << 0 << '\n';
//         return;
//     }
//     if(n >= m - 1) cout << m << '\n';
//     else cout << m - (m - 1 - n) << '\n';
//     for(int i = 1, k = m - 1;i <= n;i++){
//         int id = i % (m-1);
//         if(id == 0) id = m - 1;
//         k = m - id;
//         for(int j = 1;j <= m;j++, k = (k + 1) % m){
//             cout << k << ' ';
//         }
//         cout << '\n';
//     }
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m, a[N];

// int lowbit(int x){
//     return x & -x;
// }

// bool check(int x){
//     bool fs = false;
//     for(int i = 0;(1 << i) <= x;i++){
//         if((1 << i) & x){
//             fs = true;
//         }else{
//             if(fs) return false;
//         }
//     }
//     return true;
// }

// void solve(){
//     cin >> n;
//     int sum = 0;
//     for(int i = 1;i <= n;i++) cin >> a[i], sum += a[i];
//     if(sum % n){
//         cout << "NO\n";
//         return;
//     }
//     sum /= n;
//     map<int,int>mp;
//     for(int i = 1;i <= n;i++){
//         int d = abs(a[i] - sum);
//         if(!check(d)){
//             cout << "NO\n";
//             return;
//         }else if(d){
//             if(a[i] > sum){
//                 mp[lowbit(d)]++;
//                 mp[lowbit(d) + d]--;
//             }else{
//                 mp[lowbit(d)]--;
//                 mp[lowbit(d) + d]++;
//             }
//         }
//     }
//     for(auto [k, v] : mp) if(v){
//         cout << "NO\n";
//         return;
//     }
//     cout << "YES\n";
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m, a[N], age[N], ans[N];

// vector<int>g[N];
// vector<int>tag[N];
// int par[N][20];

// void dfs(int u, int fa){
//     par[u][0] = fa;
//     for(int i = 1;i < 20;i++)
//         par[u][i] = par[par[u][i-1]][i-1];
//     for(auto v : g[u]) dfs(v, u);
// }

// void add(int o, int l, int r){
//     int tp = o;
//     for(int i = 19;i >= 0;i--) if(age[par[tp][i]] <= r)
//         tp = par[tp][i];
//     tag[tp].push_back(l);
// }

// int tr[N];

// int lowbit(int x){
//     return x & -x;
// }

// void add(int x, int v){
//     while(x < N){
//         tr[x] += v;
//         x += lowbit(x);
//     }
// }

// int getsum(int x){
//     int ret = 0;
//     while(x > 0){
//         ret += tr[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void dfs2(int u){
//     for(auto v : tag[u]) add(v, 1);
//     ans[u] += getsum(age[u]);
//     for(auto v : g[u]) dfs2(v);
//     for(auto v : tag[u]) add(v, -1);
// }

// void solve(){
//     age[0] = INT_MAX;
//     cin >> n >> m;
//     int t;
//     cin >> age[1] >> t;
//     for(int i = 2;i <= n;i++){
//         cin >> age[i] >> t;
//         g[t].push_back(i);
//     }

//     dfs(1, 0);

//     for(int i = 1, o, l, r;i <= m;i++){
//         cin >> o >> l >> r;
//         add(o, l, r);
//     }

//     dfs2(1);

//     for(int i = 1;i <= n;i++) cout << ans[i] << ' ';

// }

// signed main(){

//     IO;

//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m;

// struct node{
//     int l, v, id;
//     node(int l = 0, int v = 0, int id = 0) : l(l), v(v), id(id) {}
// };
// vector<node>tim[88000];

// int f[88000][1030];

// void solve(){
//     cin >> n;
//     for(int i = 1, s;i <= n;i++){
//         cin >> s;
//         for(int j = 1, l, r, v;j <= s;j++){
//             cin >> l >> r >> v;
//             tim[r].push_back({l, v, i});
//         }
//     }

//     int all = (1 << n) - 1;
//     for(int i = 1;i <= 87000;i++){
//         for(int k = 0;k <= all;k++){
//             f[i][k] = f[i-1][k];
//             for(auto [l, v, id] : tim[i]) {
//                 if(((1 << (id - 1)) & k)&&(f[l][k]>0))f[i][k] = max(f[i][k], f[l][k] + v);
//                 if(f[l][k^(1<<(id-1))]>0||(k^(1<<(id-1)))==0)  f[i][k] = max(f[i][k], f[l][k ^ (1 << (id - 1))] + v);
//             }
//         }
//     }
//     // for(int i = 1;i <= 87000;i++){
//     //     for(auto [l, v, id] : tim[i]){
//     //         for(int k = 0;k <= all;k++) if((1 << (id - 1)) & k){
//     //         f[i][k] = f[i-1][k];
//     //             f[i][k] = max(f[i][k], f[l][k] + v);
//     //             if(f[l][k^(1<<(id-1))]>0||(k^(1<<(id-1)))==0)  f[i][k] = max(f[i][k], f[l][k ^ (1 << (id - 1))] + v);
//     //         }
//     //     }
//     // }

//     int ans = 0;
//     for(int i = 1;i <= 87000;i++)
//         ans = max(ans, f[i][all]);

//     cout << (ans ? ans : -1);
// }

// signed main(){

//     IO;

//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int as = 5782344;
// int n, q;

// struct node{
//     double l, r;
//     int id;
//     node(double l = 0, double r = 0, int id = 0) : l(l), r(r), id(id) {}
//     int operator<(const node& e) const {
//         return r < e.r;
//     }
//     int operator>(const node& e) const {
//         return r > e.r;
//     }
// }pt[N];

// int qpow(int a, int x){
//     int ret = 1;
//     while(x){
//         if(x & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         x >>= 1;
//     }
//     return ret;
// }

// //树状数组
// vector<node>tr[N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x, const node& e){
//     while(x < N){
//         tr[x].push_back(e);
//         x += lowbit(x);
//     }
// }
// vector<node> getvec(int x, int L){
//     vector<node>ret;
//     while(x > 0){
//         ret.insert(ret.end(), lower_bound(all(tr[x]), node(0, L, 0)), tr[x].end());
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void solve(){
//     cin >> n >> q;
//     vector<double>idx;
//     idx.reserve(2 * n + 1);
//     for(int i = 1;i <= n;i++){
//         double x, y;
//         cin >> x >> y;
//         x /= 2.0;
//         pt[i] = {y - x, y + x, i};
//         idx.push_back(y - x);
//         idx.push_back(y + x);
//     }
//     sort(idx.begin(), idx.end());
//     for(int i = 1;i <= n;i++){
//         pt[i].l = lower_bound(all(idx), pt[i].l) - idx.begin() + 1;
//         pt[i].r = lower_bound(all(idx), pt[i].r) - idx.begin() + 1;
//     }
//     sort(pt + 1, pt + 1 + n, [](const node& e1, const node& e2)->int {return e1.r < e2.r;});

//     for(int i = 1;i <= n;i++){
//         add(pt[i].l, pt[i]);
//         // cout << pt[i].l << endl;
//     }

//     for(int i = 1, a, b, p = 0;i <= q;i++){
//         cin >> a >> b;
//         int xm, ym;
//         double L, R;
//         xm = -1 - ((p + a) % mod);
//         ym = (p + b) % mod;
//         // cout << xm << ' ' << ym << endl;
//         double xx = xm / 2.0;
//         L = ym + xx;
//         R = ym - xx;
//         // cout << L << ' ' << R << '\n';
//         L = lower_bound(all(idx), L) - idx.begin() + 1;
//         R = lower_bound(all(idx), R) - idx.begin() + 1;

//         int ans = 0;
//         vector<node>res = getvec(R, L);
//         // cout << res.size() << ' ';
//         sort(all(res), [](const node& e1, const node& e2)->int {return e1.id < e2.id;});
//         for(int j = 0, len = res.size(); j < len;j++){
//             ans = (ans + res[j].id * qpow(as, j)) % mod;
//             // cout << res[j].id << endl;
//         }
//         cout << ans << '\n';
//         p = ans;
//     }

//     // cout << "End\n";
// }

// signed main(){

//     IO;

//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int mod = 1e9 + 7;
// int n;

// void solve(){
//     string s;
//     cin >> n;
//     cin >> s;
//     s = ' ' + s;
//     int E = 0, N = 0, ans = 0;
//     for(int i = n;i >= 1;i--){
//         if(s[i] == 'N') N++;
//         else if(s[i] == 'E') E = (E + N) % mod;
//         else if(s[i] == 'T') ans = (ans + E) % mod;
//     }
//     if(ans) cout << ans % mod;
//     else cout << "ten,win!!!";
// }

// signed main(){

//     IO;

//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e4 + 10;
// int n, m, a[N], b[N];

// //树状数组
// int tr[N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x){
//     while(x <= n){
//         tr[x] ++;
//         x += lowbit(x);
//     }
// }
// int getsum(int x){
//     int ret = 0;
//     while(x > 0){
//         ret += tr[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void solve(){
//     memset(tr, 0, sizeof(tr));
//     cin >> n >> m;
//     int f = 0;
//     vector<int>idx;
//     for(int i = 1;i <= n;i++) cin >> a[i], idx.push_back(a[i]);
//     for(int i = 1;i <= m;i++) cin >> b[i], f |= (b[i] & 1);

//     if(f){
//         cout << "Yes\n";
//         return;
//     }

//     sort(idx.begin(), idx.end());
//     idx.erase(unique(idx.begin(), idx.end()), idx.end());
//     if(idx.size() < n){
//         cout << "Yes\n";
//         return;
//     }
// 	int sum = 0;
//     for(int i = n;i >= 1;i--){
//         a[i] = lower_bound(idx.begin(), idx.end(), a[i]) - idx.begin() + 2;
//         sum += getsum(a[i] - 1);
//         add(a[i]);
//     }

// 	if(sum % 2 == 0) cout << "Yes\n";
// 	else cout << "No\n";
// }

// signed main(){

//     IO;

// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e4 + 10;
// int n, k, a[N], b[N], fac[11];

// int vis[11], num[11];

// int numat(int x){
//     int cnt = 0, ret = 1;
//     while(1){
//         if(vis[ret] == 0){
//             cnt++;
//         }
//         if(cnt == x) {
//             vis[ret] = 1;
//             return num[ret];
//         }
//         ret++;
//     }
// }

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++) cin >> num[i];
//     sort(num + 1, num + 1 + n);
//     fac[0] = 1;
//     for(int i = 1;i <= n;i++) fac[i] = i * fac[i-1];
//     k = fac[n] - k + 1;
//     for(int i = n;i >= 1;i--){
//         cout << numat(((max(0, k - 1)) / fac[i-1]) + 1);
//         k %= fac[i-1];
//         if(k == 0) k = fac[i-1];
//     }
// }

// signed main(){

//     IO;

// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e4 + 10;
// int n, k, a[N], b[N], fac[11], num[11];

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++) cin >> num[i];
//     sort(num + 1, num + 1 + n);
//     fac[0] = 1;
//     for(int i = 1;i <= n;i++) fac[i] = i * fac[i-1];
//     k = fac[n] - k + 1;
//     for(int i = 1;i < k;i++) next_permutation(num + 1, num + 1 + n);
//     for(int i = 1;i <= n;i++) cout << num[i];
// }

// signed main(){

//     IO;

// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int as = 5782344;
// int n, q;

// struct node{
//     int l, r, id;
//     node(int l = 0, int r = 0, int id = 0) : l(l), r(r), id(id) {}
//     int operator<(const node& e) const {
//         return r < e.r;
//     }
//     int operator>(const node& e) const {
//         return r > e.r;
//     }
// }pt[N];

// int qpow(int a, int x){
//     int ret = 1;
//     while(x){
//         if(x & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         x >>= 1;
//     }
//     return ret;
// }

// //树状数组
// vector<node>tr[N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x, const node& e){
//     while(x < N){
//         tr[x].push_back(e);
//         x += lowbit(x);
//     }
// }
// vector<node> getvec(int x, int L){
//     vector<node>ret;
//     while(x > 0){
//         ret.insert(ret.end(), lower_bound(all(tr[x]), node(0, L, 0)), tr[x].end());
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void solve(){
//     cin >> n >> q;
//     vector<int>idx;
//     idx.reserve(2 * n + 1);
//     for(int i = 1, x, y;i <= n;i++){
//         cin >> x >> y;
//         pt[i] = {2 * y - x, 2 * y + x, i};
//         idx.push_back(pt[i].l);
//         // idx.push_back(pt[i].r);
//     }
//     sort(idx.begin(), idx.end());
//     for(int i = 1;i <= n;i++){
//         pt[i].l = lower_bound(all(idx), pt[i].l) - idx.begin() + 1;
//         // pt[i].r = lower_bound(all(idx), pt[i].r) - idx.begin() + 1;
//     }
//     sort(pt + 1, pt + 1 + n, [](const node& e1, const node& e2)->int {return e1.r < e2.r;});

//     for(int i = 1;i <= n;i++){
//         add(pt[i].l, pt[i]);
//         // cout << pt[i].l << endl;
//     }

//     for(int i = 1, a, b, p = 0, xm, ym, L, R;i <= q;i++){
//         cin >> a >> b;
//         xm = -1 - ((p + a) % mod);
//         ym = (p + b) % mod;
//         // cout << xm << ' ' << ym << endl;
//         L = 2 * ym + xm;
//         R = 2 * ym - xm;
//         // cout << L << ' ' << R << '\n';
//         // L = upper_bound(all(idx), L) - idx.begin();
//         R = upper_bound(all(idx), R) - idx.begin();

//         int ans = 0;
//         vector<node>res = getvec(R, L);
//         // cout << res.size() << ' ';
//         sort(all(res), [](const node& e1, const node& e2)->int {return e1.id < e2.id;});
//         for(int j = 0, len = res.size(); j < len;j++){
//             ans = (ans + res[j].id * qpow(as, j)) % mod;
//             // cout << res[j].id << endl;
//         }
//         cout << ans << '\n';
//         p = ans;
//     }
// }

// signed main(){

//     IO;

//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// #include<ext/rope>
// using namespace std;
// using namespace __gnu_cxx;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// int n, m, tot, x;
// rope<char>* s[N];

// signed main(){

//     IO;

//     s[0] = new rope<char>;
//     cin >> n;
//     while(n--){
//         char op, c;
//         cin >> op;
//         if(op == 'T'){
//             cin >> c;
//             tot++;
//             s[tot] = new rope<char>(*s[tot-1]);
//             s[tot]->push_back(c);
//         }else if(op == 'U'){
//             cin >> x;
//             tot++;
//             s[tot] = new rope<char>(*s[tot-x-1]);
//         }else{
//             cin >> x;
//             cout << s[tot]->at(x-1) << '\n';
//         }
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int M = 1e7;
// int n, m, tot, x, len[N], cur;
// int rt[M], lson[M], rson[M];
// char tr[M];

// void newline(int &rt, int pre, int l, int r, int x, char c){
//     rt = ++tot;
//     lson[rt] = lson[pre];
//     rson[rt] = rson[pre];
//     if(l == r){
//         tr[rt] = c;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) newline(lson[rt], lson[pre], l, mid ,x, c);
//     else newline(rson[rt], rson[pre], mid + 1, r, x, c);
// }

// char query(int id, int l, int r, int x){
//     if(l == r) return tr[id];
//     int mid = l + r >> 1;
//     if(x <= mid) return query(lson[id], l, mid, x);
//     else return query(rson[id], mid + 1, r, x);
// }

// signed main(){

//     IO;

//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         char op, c;
//         cin >> op;
//         if(op == 'T'){
//             cin >> c;
//             cur++;
//             len[cur] = len[cur-1] + 1;
//             newline(rt[cur], rt[cur-1], 1, M, len[cur], c);
//         }else if(op == 'U'){
//             cin >> x;
//             cur++;
//             len[cur] = len[cur - x - 1];
//             rt[cur] = rt[cur - x - 1];
//         }else{
//             cin >> x;
//             cout << query(rt[cur], 1, M, x) << '\n';
//         }
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// const int M = 1e9 + 10;
// int n, a[N], q;

// //可持久化线段树
// int rt[N], lson[N * 101], rson[N * 101], xorsum[N * 101], tot;
// void newLine(int &cur, int pre, int l, int r, int x, int v){
//     cur = ++tot;
//     // if(r == M && l == 1){
//     //     cerr << pre << ' '  << cur << endl;
//     // }
//     xorsum[cur] = xorsum[pre] ^ v;
//     lson[cur] = lson[pre], rson[cur] = rson[pre];
//     if(l == r) return;
//     int mid = l + r >> 1;
//     if(x <= mid) newLine(lson[cur], lson[pre], l, mid, x, v);
//     else newLine(rson[cur], rson[pre], mid + 1, r, x, v);
// }
// int query(int lrt, int rrt, int l, int r){
//     if(l == r) return l;
//     int mid = l + r >> 1;
//     if(xorsum[lson[lrt]] ^ xorsum[lson[rrt]]) return query(lson[lrt], lson[rrt], l, mid);
//     else return query(rson[lrt], rson[rrt], mid + 1, r);
// }

// void solve(){
//     mt19937 rnd(time(0));
//     map<int,int>mp;
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         while(!mp[a[i]]) mp[a[i]] = rnd();
//         newLine(rt[i], rt[i-1], 1, M, a[i], mp[a[i]]);
//     }
//     cin >> q;
//     int x, y, l, r, ans = 0;
//     while(q--){
//         cin >> x >> y;
//         l = x ^ ans;
//         r = y ^ ans;
//         if((xorsum[rt[l - 1]] ^ xorsum[rt[r]]) == 0) ans = 0;
//         else ans = query(rt[l - 1], rt[r], 1, M);
//         cout << ans << endl;
//     }
//     // for(int i = 0;i <= n;i++)
//     //     cerr << mp[i] << endl;  
//     // for(int i = 0;i <= n;i++)
//     //     cerr << xorsum[i] << endl;  
// }

// signed main(){

//     IO;

//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// // #define endl '\n'
// #define all(a) a.begin(), a.end()
// const int N = 3e5 + 10;
// const int M = 1e7 + 10;
// int n, m, k;

// struct edge{
//     int l, r, p;
//     edge(int l = 0, int r = 0, int p = 0) : l(l), r(r), p(p) {}
//     int operator<(const edge& e) const {
//         return r < e.r;
//     }
// }g[N];

// int rt[N], lson[M], rson[M], mn[M], tot;
// void upDate(int &cur, int pre, int l, int r, int x, int v){
//     cur = ++tot;
//     lson[cur] = lson[pre], rson[cur] = rson[pre];
//     mn[cur] = mn[pre];
//     if(l == r){
//         mn[cur] = max(mn[cur], v);
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) upDate(lson[cur], lson[pre], l, mid, x, v);
//     else upDate(rson[cur], rson[pre], mid + 1, r, x, v);
//     mn[cur] = min(mn[lson[cur]], mn[rson[cur]]);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(l > qr || r < ql) return 1e9 + 10;
//     if(ql <= l && r <= qr) return mn[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson[id], l, mid, ql, qr);
//     else if(ql > mid) return query(rson[id], mid + 1, r, ql, qr);
//     else return min(query(lson[id], l, mid, ql, qr), query(rson[id], mid + 1, r, ql, qr));
// }

// void solve(){
//     scanf("%d%d%d", &n, &m, &k);
//     vector<int>idx;
//     for(int i = 1;i <= k;i++){
//         scanf("%d%d%d", &g[i].l, &g[i].r, &g[i].p);
//         idx.push_back(g[i].r);
//     }
//     sort(all(idx));
//     idx.erase(unique(all(idx)), idx.end());
//     sort(g + 1, g + 1 + k);
//     for(int i = 1;i <= k;i++){
//         g[i].r = lower_bound(all(idx), g[i].r) - idx.begin() + 1;
//     }
//     int ls = 0;
//     for(int i = 1;i <= k;i++){
//         upDate(rt[g[i].r], rt[ls], 1, n, g[i].p, g[i].l);
//         ls = g[i].r;
//     }
//     while(m--){
//         int a, b, x, y;
//         scanf("%d%d%d%d", &a, &b, &x, &y);
//         y = upper_bound(all(idx), y) - idx.begin();
//         if(y == 0) printf("no\n");
//         else{
//             if(query(rt[y], 1, n, a, b) >= x) printf("yes\n");
//             else printf("no\n");
//         }
//         fflush(stdout);
//     }
// }

// signed main(){

//     solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define lson id << 1
// #define rson id << 1 | 1
// #define endl '\n'
// const int N = 5e4 + 10;
// const int mod = 1e9 + 7;
// int n, m, q, a[N];

// struct Mat{
//     int mp[4][4];
//     Mat(int x){
//         mp[0][0] = mp[0][1] = mp[1][1] = mp[2][2] = mp[3][3] = 1;
//         mp[0][2] = mp[1][2] = (2 * x) % mod;
//         mp[2][3] = x % mod;
//         mp[0][3] = mp[1][3] = (x * x) % mod;
//         mp[1][0] = mp[2][0] = mp[2][1] = mp[3][0] = mp[3][1] = mp[3][2] = 0;
//     }

//     Mat(){
//         init();
//     }

//     void init(){
//         for(int i = 0; i < 4;i++){
//             for(int j = 0;j < 4;j++)
//                 if(i == j) mp[i][j] = 1;
//                 else mp[i][j] = 0;
//         }
//     }
//     void print(){
//         for(int i = 0;i < 4;i++){
//             for(int j = 0 ;j < 4;j++)
//                 cout << mp[i][j] << ' ';
//             cout << endl;
//         }
//     }
// };

// Mat operator*(const Mat& m1, const Mat& m2){
//     Mat ret;
//     for(int i = 0;i < 4;i++){
//         for(int j = 0;j < 4;j++){
//             ret.mp[i][j] = 0;
//             for(int k = 0;k < 4;k++){
//                 ret.mp[i][j] = (ret.mp[i][j] + (m1.mp[i][k] * m2.mp[k][j] % mod)) % mod;
//             }
//         }
//     }
//     return ret;
// }
// struct node{
//     int val[4]; //S A2 A len
//     Mat tag;

//     node operator+(const node& e) const{
//         node ret;
//         for(int i = 0;i < 4;i++){
//             ret.val[i] = (val[i] + e.val[i]) % mod;
//         }
//         return ret;
//     }

// }tr[N << 2];
// bool tagact[N << 2];

// node operator*(const Mat& mt, const node& nd) {
//     node ret;
//     for(int i = 0;i < 4;i++){
//         ret.val[i] = 0;
//         for(int j = 0;j < 4;j++){
//             ret.val[i] = (ret.val[i] + (mt.mp[i][j] * nd.val[j] % mod)) % mod;
//         }
//     }
//     ret.tag = mt * nd.tag;
//     return ret;
// }

// void up(int id){
//     tr[id] = tr[lson] + tr[rson];
// }

// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].val[0] = tr[id].val[1] = (a[l] * a[l]) % mod;
//         tr[id].val[2] = a[l] % mod;
//         tr[id].val[3] = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// void settag(int id, Mat mt){
//     tr[id] = mt * tr[id];
//     tagact[id] = true;
// }

// void down(int id){
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag.init();
//     tagact[id] = false;
// }

// void modify(int id, int l, int r, int ql, int qr, int x){
//     if(ql <= l && r <= qr){
//         settag(id, Mat(x));
//         return;
//     }
//     if(tagact[id]) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, x);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, x);
//     else modify(lson, l, mid, ql, qr, x) , modify(rson, mid + 1, r, ql, qr, x);
//     up(id);
// }

// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].val[0] % mod;
//     if(tagact[id]) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr) % mod;
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr) % mod;
//     else return (query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr)) % mod;
// }

// struct modi{
//     int l, r, x;
// }md[N];

// struct quer{
//     int l, r, x, id;
// };

// vector<quer>qur;
// int vis[N], ans[N];

// void solve(){
//     cin >> n >> m >> q;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         a[i] = (a[i] + mod) % mod;
//     }
//     build(1, 1, n);
//     for(int i = 1;i <= m;i++){
//         cin >> md[i].l >> md[i].r >> md[i].x;
//         md[i].x = (md[i].x + mod) % mod;
//     }
//     for(int i = 1, l, r, x, y;i <= q;i++){
//         cin >> l >> r >> x >> y;
//         // if(x == 0) vis[i] = 1;
//         // else if(x == 1){
//         //     vis[i] = 1;
//         //     ans[i] -= query(1, 1, n, l, r);
//         // }
//         // else qur.push_back({l, r, x - 1, i});
//         // if(y == 0) ans[i] = ans[i] + query(1, 1, n, l, r);
//         // else qur.push_back({l, r, y, i});
//         if(x == 0) vis[i] = 1;
//         else qur.push_back({l, r, x - 1, i});
//         qur.push_back({l, r, y, i});
//     }

//     sort(qur.begin(), qur.end(), [](const quer& e1, const quer& e2)->int {return e1.x < e2.x;});
//     int ti = 1;
//     for(auto [l, r, x, id] : qur){
//         while(ti <= x){
//             modify(1, 1, n, md[ti].l, md[ti].r, md[ti].x);
//             if(md[ti].l > 1) modify(1, 1, n, 1, md[ti].l - 1, 0);
//             if(md[ti].r < n) modify(1, 1, n, md[ti].r + 1, n, 0);
//             ti++;
//         }
//         if(vis[id]) ans[id] = ans[id] + query(1, 1, n, l, r);
//         else ans[id] -= query(1, 1, n, l, r), vis[id] = 1;
//     }
//     for(int i = 1;i <= q;i++) cout << (ans[i] + mod) % mod << '\n';
// }

// signed main(){

//     IO;

//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 1e5 + 10;
// int n, m, a[N];


// void solve(){
//     cin >> n;
//     int num[101] = {0};
//     int mx = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         mx = max(mx, a[i]);
//         num[a[i]]++;
//     }
//     for(int i = 1;i <= mx;i++){
//         if(num[i] > num[i-1]){
//             cout << "NO\n";
//             return;
//         }
//     }
//     cout << "YES\n";
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f;
// int n, m, a[N];

// struct Tree_b{
//     struct node{
//         int sum, len, tag;
//     }tr[N << 2];
//     int siz;
//     Tree_b() : siz(0) {}

//     void init(){
//         siz = 0;
//         build(1, 1, n);
//     }
//     void up(int id);
//     void settag(int id, int x);
//     void down(int id);
//     void build(int id, int l, int r);
//     void modify(int id, int l, int r, int ql, int qr, int x);
//     int query(int id, int l, int r, int ql, int qr);
//     void insert(int id, int l, int r, int x, int v);
// }B;
// void Tree_b::up(int id){
//     tr[id].len = tr[lson].len + tr[rson].len;
//     tr[id].sum = tr[lson].sum + tr[rson].sum;
// }
// void Tree_b::settag(int id, int x){
//     if(tr[id].len == 0) return;
//     tr[id].sum = tr[id].len * x - tr[id].sum;
//     tr[id].tag += x;
// }
// void Tree_b::down(int id){
//     if(tr[id].len == 0) return;
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag = 0;
// }
// void Tree_b::build(int id, int l, int r){
//     tr[id].tag = tr[id].sum = tr[id].len = 0;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
// }
// void Tree_b::modify(int id, int l, int r, int ql, int qr, int x){
//     if(tr[id].len == 0) return;
//     if(ql <= l && r <= qr){
//         settag(id, x);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, x);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, x);
//     else modify(lson, l, mid, ql, qr, x), modify(rson, mid + 1, r, ql, qr, x);
//     up(id);
// }
// int Tree_b::query(int id, int l, int r, int ql, int qr){
//     if(tr[id].len == 0) return 0;
//     if(ql <= l && r <= qr) return tr[id].sum;
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
// }
// void Tree_b::insert(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id].len = 1;
//         tr[id].sum = v;
//         siz++;
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(x <= mid) insert(lson, l, mid, x, v);
//     else insert(rson, mid + 1, r, x, v);
//     up(id);
// }

// struct Tree_a{
//     struct node{
//         int mn, sum, len, tag;
//     }tr[N << 2];

//     void up(int id);
//     void settag(int id, int x);
//     void down(int id);
//     void build(int id, int l, int r);
//     void modify(int id, int l, int r, int ql, int qr, int x);
//     int query(int id, int l, int r, int ql, int qr);
// }A;
// void Tree_a::up(int id){
//     tr[id].sum = (tr[lson].len ? tr[lson].sum : 0) + (tr[rson].len ? tr[rson].sum : 0);
//     tr[id].mn = min(tr[lson].mn, tr[rson].mn);
//     tr[id].len = tr[lson].len + tr[rson].len;
// }
// void Tree_a::settag(int id, int x){
//     if(tr[id].len == 0) return;
//     tr[id].tag += x;
//     tr[id].sum -= tr[id].len * x;
//     tr[id].mn -= x;
// }
// void Tree_a::down(int id){
//     if(tr[id].len == 0) return;
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag = 0;
// }
// void Tree_a::build(int id, int l, int r){
//     tr[id].tag = 0;
//     if(l == r){
//         tr[id].mn = tr[id].sum = a[l];
//         tr[id].len = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// void Tree_a::modify(int id, int l, int r, int ql, int qr, int x){
//     if(tr[id].len == 0) return;
//     if(ql <= l && r <= qr){
//         if(tr[id].mn >= x){
//             settag(id, x);
//             return;
//         }
//         if(l == r){
//             B.insert(1, 1, n, l, tr[id].sum);
//             tr[id].mn = inf;
//             tr[id].len = 0;
//             tr[id].sum = 0;
//             return;
//         }
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, x);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, x);
//     else modify(lson, l, mid, ql, qr, x), modify(rson, mid + 1, r, ql, qr, x);
//     up(id);
// }
// int Tree_a::query(int id, int l, int r, int ql, int qr){
//     if(tr[id].len == 0) return 0;
//     if(ql <= l && r <= qr) return tr[id].sum;
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     A.build(1, 1, n);
//     B.init();
//     for(int i = 1;i <= m;i++){
//         int op, l, r, x;
//         cin >> op >> l >> r;
//         if(op == 1){
//             cin >> x;
//             A.modify(1, 1, n, l, r, x);
//             B.modify(1, 1, n, l, r, x);
//         }else{
//             cout << A.query(1, 1, n, l, r) + B.query(1, 1, n, l, r) << endl;
//         }
//     }
//     // A.modify(1, 1, n, 1, 5, 3);
//     // B.modify(1, 1, n, 1, 5, 3);
//     // cout << A.query(1, 1, n, 2, 4) + B.query(1, 1, n, 2, 4) << endl;
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, m, a[N], k, mx[N], mn[N], vis[N], q, p;

// void setmn(int v, int x){
//     while(q <= v){
//         mn[q] = x;
//         q++;
//     }
// }

// void setmx(int v, int x){
//     while(p <= v){
//         mx[p] = x;
//         p++;
//     }
// }

// void solve(){
//     cin >> n >> k;
//     q = p = 1;
//     for(int i = 1;i <= k;i++) mx[i] = mn[i] = vis[i] = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         vis[a[i]] = 1;
//     }
//     for(int i = 1;i <= n;i++){
//         setmn(a[i], i);
//     }
//     for(int i = n;i >= 1;i--){
//         setmx(a[i], i);
//     }
//     for(int i = 1;i <= k;i++){
//         if(!vis[i]) cout << 0 << ' ';
//         else cout << (mx[i] - mn[i] + 1) * 2 << ' ';
//     }

//     cout << endl;
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, m, a[N], k, d[N], suf[N];

// struct node{
//     int mn, i;
// }tr[N << 2];
// void up(int id){
//     tr[id].mn = min(tr[lson].mn, tr[rson].mn);
//     if(tr[lson].mn < tr[rson].mn) tr[id].i = tr[lson].i;
//     else tr[id].i = tr[rson].i;
// }
// void build(int id, int l ,int r){
//     if(l == r){
//         tr[id].mn = a[l];
//         tr[id].i = l;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// int query(int id, int l, int r, int ql ,int qr){
//     if(ql <= l && r <= qr){
//         return tr[id].i;
//     }
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else {
//         int ld = query(lson, l, mid, ql, qr);
//         int rd = query(rson, mid + 1, r, ql, qr);
//         if(a[ld] < a[rd]) return ld;
//         else return rd;
//     }
// }

// void solve(){
//     cin >> n;
//     int mx = 0;
//     for(int i = 1;i <= n;i++) cin >> a[i], suf[i] = 0;
//     suf[n + 1] = 0;
//     cin >> k;
//     build(1, 1, n);
//     for(int i = 1;i <= n;i++) d[i] = k / a[i], mx = max(mx, d[i]);
//     int fs = 0;
//     for(int i = n;i >= 1;i--) if(d[i] == mx){
//         fs = i;
//         suf[fs] = d[i];
//         break;
//     }
//     if(fs == 0){
//         for(int i = 1;i <= n;i++) cout << 0 << ' ';
//     }else{
//         int cnt = k % a[fs];
//         int cur = fs + 1;
//         while(cur <= n){
//             int md = query(1, 1, n, cur, n);
//             int delt = a[md] - a[fs];
//             // cout << cur << ' ' << md << ' ' << delt << ' ' << cnt << endl;
//             if(cnt >= delt){
//                 int t = cnt / delt;
//                 suf[fs] -= t;
//                 suf[md] += t;
//                 cnt %= delt;
//             }else break;
//             cur = md + 1;
//             fs = md;
//         }
//         for(int i = n;i >= 1;i--){
//             suf[i] += suf[i+1];
//         }
//         for(int i = 1;i <= n;i++) cout << suf[i] << ' ';
//     }
//     // cout << fs;
//     cout << endl;
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }