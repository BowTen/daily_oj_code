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


// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0) ,cout.tie(0);
// #define endl '\n'
// const int N = 1e6 + 10;
// const int mod = 998244353;
// int n;

// struct edge{
//     int to, ne;
//     edge(int _to = 0, int _ne = 0) : to(_to), ne(_ne) {}
// }g[N << 1];
// int head[N], tot;

// void add(int u, int v){
//     g[++tot].ne = head[u];
//     g[tot].to = v;
//     head[u] = tot;
// }

// int dep[N], par[N];
// void dfs(int u, int f){
//     dep[u] = dep[f] + 1;
//     par[u] = f;
//     for(int i = head[u]; i; i = g[i].ne) if(g[i].to != f){
//         dfs(g[i].to, u);
//     }
// }

// int fa[N], siz[N];
// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     // a = find(a);
//     // b = find(b);
//     // if(a == b) return;
//     if(dep[a] < dep[b]) fa[b] = a, siz[a] += siz[b];
//     else fa[a] = b, siz[b] += siz[a];
// }

// ll qpow(ll a, ll x){
//     ll ret = 1;
//     while(x){
//         if(x & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         x >>= 1;
//     }
//     return ret;
// }

// signed main(){
    
//     IO;

//     cin >> n;
//     for(int i = 1;i <= n;i++) fa[i] = i, siz[i] = 1;
//     vector<array<int, 2>>q(n + 1);
//     for(int i = 1;i < n;i++) cin >> q[i][0] >> q[i][1];
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         add(u, v);
//         add(v, u);
//     }
//     dfs(1, 0);
//     ll ans = 1;
//     for(int i = 1, u, v;i < n;i++){
//         u = find(q[i][0]), v = find(q[i][1]);
//         if( (find(par[u]) == v) || (find(par[v]) == u) ){
//             // ans = (ans * siz[u] % mod) * siz[v] % mod;
//             ans = ans * qpow(1ll * siz[u] * siz[v], mod - 2) % mod;
//             merg(u, v);
//         }else{
//             cout << 0;
//             return 0;
//         }
//     }
//     cout << ans;
//     // cout << qpow(ans, mod - 2);

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;
// #define Acode ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define ll long long
// #define endl '\n'
// const int N = 1e6 + 10;
// int n;
// const ll mod = 998244353;
// ll qpow(ll a, ll b, ll mod){
//     ll res = 1;
//     while (b){
//         if (b & 1)
//             res = res * a % mod;
//         b >>= 1;
//         a = a * a % mod;
//     }
//     return res;
// }

// struct edge{
//     int to, ne;
// }g[N << 1];
// int head[N], tot;
// void add(int a, int b){
//     g[++tot] = {b, head[a]};
//     head[a] = tot;
// }

// array<int, 2> q[N];
// int dep[N], par[N];
// void dfs(int u, int f){
//     par[u] = f;
//     dep[u] = dep[f] + 1;
//     for(int i = head[u]; i; i = g[i].ne) if(g[i].to != f){
//         dfs(g[i].to, u);
//     }
// }

// int fa[N], hi[N], siz[N];
// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     if (a == b)
//         return;
//     siz[b] += siz[a];
//     if (dep[hi[a]] < dep[hi[b]])
//         hi[b] = hi[a];
//     fa[a] = b;
// }

// signed main()
// {
//     Acode;

//     cin >> n;
//     for (int i = 1; i < n; i++)
//     {
//         cin >> q[i][0] >> q[i][1];
//     }
//     for (int i = 1; i < n; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         add(a, b);
//         add(b, a);
//     }
//     dfs(1, 0);
//     for (int i = 1; i <= n; i++)
//     {
//         fa[i] = hi[i] = i;
//         siz[i] = 1;
//     }

//     ll ans = 1;
//     for (int i = 1, a, b; i < n; i++)
//     {
//         a = find(q[i][0]), b = find(q[i][1]);
//         if ((find(par[hi[a]]) == b) || (find(par[hi[b]]) == a))
//         {
//             // ans = ((ans * siz[a] % mod) * siz[b]) % mod;
//             ans = ans * qpow((1ll * siz[a] * siz[b]) % mod, mod - 2, mod) % mod;
//             merg(a, b);
//         }
//         else
//         {
//             cout << 0;
//             return 0;
//         }
//     }
//     cout << ans;

//     return 0;
// }




// #include <bits/stdc++.h>
// using namespace std;
// #define Acode ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define ll long long
// #define int long long
// #define endl '\n'
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, m, a[N];

// //区间加乘线段树
// struct node2{
//     int sum, len, ad, mt;
// }tr2[N << 2];
// void settag2(int id, int x){
//     tr2[id].sum += x * tr2[id].len;
//     tr2[id].ad += x;
// }
// void settag3(int id, int x){
//     tr2[id].sum *= x;
//     tr2[id].mt *= x;
//     tr2[id].ad *= x;
// }
// void down2(int id){
//     settag3(lson, tr2[id].mt);
//     settag2(lson, tr2[id].ad);
//     settag3(rson, tr2[id].mt);
//     settag2(rson, tr2[id].ad);
//     tr2[id].ad = 0;
//     tr2[id].mt = 1;
// }
// void up2(int id){
//     tr2[id].sum = tr2[lson].sum + tr2[rson].sum;
//     tr2[id].len = tr2[lson].len + tr2[rson].len;
// }
// void build2(int id, int l, int r){
//     tr2[id] = {0, 0, 0, 1};
//     if(l == r) return;
//     int mid = l + r >> 1;
//     build2(lson, l, mid);
//     build2(rson, mid + 1, r);
// }
// void insert(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr2[id] = {v, 1, 0, 1};
//         return;
//     }
//     if(tr2[id].ad) down2(id);
//     int mid = l + r >> 1;
//     if(x <= mid) insert(lson, l, mid, x, v);
//     else insert(rson, mid + 1, r, x, v);
//     up2(id);
// }
// void modify2(int id, int l, int r, int ql, int qr, int x){
//     if(tr2[id].len == 0) return;
//     if(ql <= l && r <= qr){
//         settag2(id, x);
//         settag3(id, -1);
//         return;
//     }
//     if(tr2[id].ad) down2(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify2(lson, l, mid, ql, qr, x);
//     else if(ql > mid) modify2(rson, mid + 1, r, ql, qr, x);
//     else modify2(lson, l, mid, ql, qr, x), modify2(rson, mid + 1, r, ql, qr, x);
//     up2(id);
// }
// int query2(int id, int l, int r, int ql, int qr){
//     if(tr2[id].len == 0) return 0;
//     if(ql <= l && r <= qr) return tr2[id].sum;
//     if(tr2[id].ad) down2(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query2(lson, l, mid, ql, qr);
//     else if(ql > mid) return query2(rson, mid + 1, r, ql, qr);
//     else return query2(lson, l, mid, ql, qr) + query2(rson, mid + 1, r, ql, qr);
// }

// //区间减线段树
// struct node{
//     int mn, sum, len, tag;
// }tr[N << 2];
// void up(int id){
//     tr[id].len = tr[lson].len + tr[rson].len;
//     tr[id].sum = (tr[lson].len ? tr[lson].sum : 0) + (tr[rson].len ? tr[rson].sum : 0);
//     tr[id].mn = min(tr[lson].mn, tr[rson].mn);
// }
// void settag(int id, int x){
//     if(tr[id].len == 0) return;
//     tr[id].tag += x;
//     tr[id].sum -= x * tr[id].len;
//     tr[id].mn -= x;
// }
// void down(int id){
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag = 0;
// }
// void build(int id, int l, int r){
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
// void modify(int id, int l, int r, int ql, int qr, int x){
//     if(tr[id].len == 0) return;
//     if(ql <= l && r <= qr){
//         if(tr[id].mn >= x){
//             settag(id, x);
//             return;
//         }
//         if(l == r){
//             insert(1, 1, n, l, tr[id].sum);
//             tr[id] = {(int)(1e15), 0, 0, 0};
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
// int query(int id, int l, int r, int ql, int qr){
//     if(!tr[id].len) return 0;
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
//     build(1, 1, n);
//     build2(1, 1, n);
//     while(m--){
//         int op, l, r;
//         cin >> op >> l >> r;
//         if(op == 1){
//             int x;
//             cin >> x;
//             modify(1, 1, n, l, r, x);
//             modify2(1, 1, n, l, r, -x);
//         }else{
//             cout << query(1, 1, n, l, r) + query2(1, 1, n, l, r) << endl;
//         }
//     }
// }

// signed main()
// {
//     Acode;
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
//                 int t = min(cnt / delt, suf[fs]);
//                 suf[fs] -= t;
//                 suf[md] += t;
//                 cnt -= t * delt;
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


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m, num[20];

// int dp[20][20][2000][2];
// int dfs(int pos, int point, int sum, bool limited){
//     if(!pos) return (sum == 0);
//     if(sum < 0) return 0;
//     if(~dp[pos][point][sum][limited]) return dp[pos][point][sum][limited];
//     int top = (limited ? num[pos] : 9);
//     int ret = 0;
//     for(int i = 0;i <= top;i++) ret += dfs(pos - 1, point, sum + i * (pos - point), i == top && limited);
//     return dp[pos][point][sum][limited] = ret;
// }

// int f(int x){
//     if(x < 0) return 0;
//     if(x == 0) return 1;
//     memset(dp, -1, sizeof(dp));
//     int tot = 0;
//     while(x) num[++tot] = x % 10, x /= 10;
//     int ret = 0;
//     for(int i = 1;i <= tot;i++) ret += dfs(tot, i, 0, 1);
//     return ret - tot + 1;
// }

// void solve(){
//     int a, b;
//     cin >> a >> b;
//     cout << f(b) - f(a - 1) << endl;
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
// int n, m, num[20];

// int dp[20][2], cnt[11];

// int dfs(int pos, bool limited){
//     if(!pos) return 1;
//     if(~dp[pos][limited]) return dp[pos][limited];
//     int top = (limited ? num[pos] : 9);
//     int ret = 0;
//     for(int i = 0;i <= top;i++){
//         int tmp = dfs(pos - 1, i == top && limited);
//         cnt[i] += tmp;
//         ret += tmp;
//     }
//     return dp[pos][limited] = ret;
// }

// void f(int x){
//     memset(dp, -1, sizeof(dp));
//     memset(cnt, 0, sizeof(cnt));
//     if(x <= 0) return;
//     int tot = 0;
//     while(x) num[++tot] = x % 10, x /= 10;
//     dfs(tot, 1);
// }

// void solve(){
//     int ans[11];
//     int a, b;
//     cin >> a >> b;
//     f(b);
//     for(int i = 0;i <= 9;i++) ans[i] = cnt[i];
//     // f(a - 1);
//     // for(int i = 0;i <= 9;i++) ans[i] -= cnt[i];
//     for(int i = 0;i <= 9;i++) cout << ans[i] << ' ';
//     cout << endl << dp[2][0] << ' ' << dp[2][1] << endl;
    
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
// int n, m, v[N];
// array<int, 2>x[N];

// vector<int>idx;
// int tr[N], cnt[N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x, int v){
//     while(x <= n){
//         tr[x] += v;
//         cnt[x]++;
//         x += lowbit(x);
//     }
// }
// void clear(int x, int v){
//     while(x <= n){
//         tr[x] -= v;
//         cnt[x]--;
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
// int getcnt(int x){
//     int ret = 0;
//     while(x > 0){
//         ret += cnt[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> x[i][0], x[i][1] = i;
//     for(int i = 1;i <= n;i++) cin >> v[i], idx.push_back(v[i]);
//     sort(all(idx));
//     idx.erase(unique(all(idx)), idx.end());
//     for(int i = 1;i <= n;i++){
//         v[i] = lower_bound(all(idx), v[i]) - idx.begin() + 1;
//         add(v[i], x[i][0]);
//     }
//     int ans = 0;
//     sort(x + 1, x + 1 + n);
//     for(int i = n;i >= 1;i--){
//         int id = x[i][1], pos = x[i][0];
//         clear(v[id], pos);
//         ans -= getsum(v[id]);
//         ans += getcnt(v[id]) * pos;
//     }
//     cout << ans << endl;
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
// int n, m, now, num[20];

// int dp[20][2][2][20];

// int dfs(int pos, bool lead, bool limited, int sum){
//     if(!pos) return sum;
//     if(~dp[pos][lead][limited][sum]) return dp[pos][lead][limited][sum];
//     int top = (limited ? num[pos] : 9);
//     int ret = 0;
//     for(int i = 0;i <= top;i++){
//         ret += dfs(pos - 1, lead && i == 0, limited && i == top, sum + (i == now) - (now == 0 && lead && i == 0));
//     }
//     return dp[pos][lead][limited][sum] = ret;
// }

// int getsum(int x){
//     if(x < 0) return 0;
//     int tot = 0;
//     while(x) num[++tot] = x % 10, x /= 10;
//     memset(dp, -1, sizeof(dp));
//     return dfs(tot, 1, 1, 0);
// }

// void solve(){
//     int a, b;
//     cin >> a >> b;
//     for(int i = 0;i <= 9;i++){
//         now = i;
//         cout << getsum(b) - getsum(a - 1) << ' ';
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// const int N = 2e5 + 10;
// int n, a[N], k, x;

// void solve(){
//     cin >> n >> k >> x;
//     if((k * (2 * n - k + 1)) / 2 >= x && (k * (k + 1)) / 2 <= x) cout << "YES\n";
//     else cout << "NO\n";
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
// #define all(x) x.begin(), x.end()
// const int N = 2e5 + 10;
// int n, x[N], k, q, l[N], r[N], pre[N];

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++) pre[i] = 0;
//     string s;
//     cin >> s;
//     // reverse(s2.begin(), s2.end());
//     s = ' ' + s;
//     string s2(s);
//     for(int i = 1;i <= k;i++) cin >> l[i];
//     for(int i = 1;i <= k;i++) cin >> r[i], reverse(s2.begin() + l[i], s2.begin() + r[i] + 1);
//     cin >> q;
//     for(int i = 1;i <= q;i++) cin >> x[i];
//     sort(x + 1, x + 1 + q);
//     int p = 1;
//     x[q+1] = 0;
//     for(int i = 1;i <= q;i++){
//         if(x[i] == x[i+1]){
//             i++;
//             continue;
//         }
//         while(x[i] > r[p]){
//             p++;
//         }
//         int a = min(x[i], l[p] + r[p] - x[i]);
//         int b = max(x[i], l[p] + r[p] - x[i]);
//         pre[a] ^= 1;
//         if(b + 1 <= r[p])
//         pre[b+1] ^= 1;
//         // cout << x[i] << ' ' << a << ' ' << b  << endl;
//     }
//     p = 1;
//     int L = 0;
//     for(int i = 1;i <= n;i++) {
//         if(i > r[p]) {
//             p++, pre[i - 1] = 0;
//             // if(L){
//             //     reverse(s.begin() + L, s.begin() + l[p]);
//             //     L = 0;
//             // }

//         }
//         pre[i] ^= pre[i-1];
//         if(pre[i]) cout << s2[i];
//         else cout << s[i];
//         // if(!L && pre[i]) L = i;
//         // if(L && !pre[i]){
//         //     reverse(s.begin() + L, s.begin() + i);
//         //     L = 0;
//         // }
//         // cout << pre[i] <<  ' ';
//     }
//     // if(L){
//     //     reverse(s.begin() + L, s.end());
//     // }
//     // for(int i = 1;i <= n;i++) cout << s[i];
//     cout << endl;
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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, a[N], q;
// // const int inf = (1ll << 60) - 1;

// //线段树
// int tr[N << 2];
// void up(int id){
//     tr[id] = tr[lson] & tr[rson];
// }
// void build(int id, int l ,int r){
//     if(l == r){
//         tr[id] = a[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// int query(int id, int l, int r, int ql ,int qr){
//     if(ql <= l && r <= qr){
//         return tr[id];
//     }
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return (query(lson, l, mid, ql, qr) & query(rson, mid + 1, r, ql, qr));
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);
//     cin >> q;
//     while(q--){
//         int l, k;
//         cin >> l >> k;
//         if(a[l] < k){
//             cout << "-1 ";
//             continue;
//         }
//         int a = l, b = n;
//         while(a <= b){
//             int mid = a + b >> 1;
//             if(query(1, 1, n, l, mid) >= k) a = mid + 1;
//             else b = mid - 1;
//         }
//         cout << b << ' ';
//     }

//     cout << endl;
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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, a[N];
// const int inf = 0x3f3f3f3f;


// void solve(){
//     string s;
//     cin >> s;
//     int cnt = 0;
//     int cur = -inf;
//     for(auto c : s){
//         if(c == '1'){
//             cnt += max(0, cur);
//             cur = 0;
//         }else cur++;
//     }
//     cnt += max(0, cur);
//     cout << cnt << endl;
//     cout << ((cnt & 1) ? "Alice" : "Bob");
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
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, a[N];


// void solve(){
//     cin >> n;
//     int cur = 0;
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         cur++;
//         if(a[i] == cur) cur ++;
//     }
//     cout << cur << endl;

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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n;

// struct node{
//     int sz;
//     int vec[60];
//     map<int, int>mp;
//     int operator<(const node& e) const {
//         return sz > e.sz;
//     }
// };
// node a[60];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) a[i].mp.clear();
//     set<int>st;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i].sz;
//         for(int j = 1;j <= a[i].sz;j++) {
//             cin >> a[i].vec[j];
//             st.insert(a[i].vec[j]);
//             a[i].mp[a[i].vec[j]]++;
//         }
//     }
//     int ans = 0;
//     for(auto num : st){
//         set<int>sst;
//         for(int i = 1;i <= n;i++){
//             if(a[i].mp[num]) continue;
//             for(int j = 1;j <= a[i].sz;j++) sst.insert(a[i].vec[j]);
//         }
//         ans = max(ans, (int)(sst.size()));
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
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, a[N];

// void solve(){
//     cin >> n;
//     int sum = 0;
//     int fs = n + 1;
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         if(a[i] >= 0) sum += a[i];
//     }
//     int ans;
//     for(int i = 1;i <= n;i++) if(a[i] >= 0){
//         fs = i;
//         break;
//     }
//     if(fs > n){
//         cout << 0 << endl;
//         return;
//     }
//     if(fs & 1 || fs > 2){
//         cout << sum << endl;
//         return;
//     }
//     ans = max({sum - a[fs], sum + a[1], 0ll});
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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, a[N];

// void solve(){
//     cin >> n;
//     int s, e;
//     cin >> s >> e;
//     int s1 = s, ans = e;
//     bool win = true;
//     for(int i = 2;i <= n;i++){
//         cin >> s >> e;
//         if(s >= s1 && e >= ans) win = false;
//     }
//     cout << (win ? s1 : -1) << endl;
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
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 3e5 + 10;
// int n, a[N], b[N];

// void solve(){
//     cin >> n;
//     int mn1 = 1e9 + 10, mn2 = 1e9 + 10;
//     int s1 = 0, s2 = 0;
//     for(int i = 1;i <= n;i++) cin >> a[i], mn1 = min(mn1, a[i]), s1 += a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i], mn2 = min(mn2, b[i]), s2 += b[i];
//     cout << min(s1 + n * mn2, s2 + n * mn1) << endl;
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
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 3e5 + 10;
// int n;
// const int mod = 998244353;

// int inv[N], fac[N];
// int qpow(int a, int x){
//     int ret = 1;
//     while(x > 0){
//         if(x & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         x >>= 1;
//     }
//     return ret;
// }
// void get_inv(){
//     inv[0] = fac[0] = 1;
//     for(int i = 1;i < N;i++){
//         fac[i] = fac[i-1] * i % mod;
//     }
//     inv[N - 1] = qpow(fac[N - 1], mod - 2);
//     for(int i = N - 2;i >= 1;i--){
//         inv[i] = inv[i+1] * (i +1) %mod;
//     }
// }
// int A(int a, int b){
//     return fac[a] * inv[a - b] % mod;
// }

// void solve(){
//     string s;
//     cin >> s;
//     int cnt = 0, cur = 0;
//     n = s.size();
//     int sum = 0;
//     int ans = 1;
//     for(int i = 1;i < n;i++){
//         if(s[i] == s[i - 1]){
//             cnt++;
//             cur++;
//         }else if(cnt){
//             ans = ans * (cnt + 1) % mod;
//             // sum += cnt + 1;
//             cnt = 0;
//         }
//     }
//     if(cnt) ans = ans * (cnt + 1) % mod;
//     cout << cur << ' ' << fac[cur] * ans % mod << endl;
// }

// signed main(){

//     IO;

//     get_inv();
//     int t = 1;
//     cin >> t;
//     while(t--) solve();
//     // cout << A(3, 2);

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 3e5 + 10;
// int n, a[N];
// const int mod = 998244353;


// void solve(){
//     cin >> n;
//     int s1 = 0, s2 = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] == 1) s1 ++;
//         else s2++;
//     }
//     int mid = (n + 1) / 2;
//     if(s2 % 2 == 0){
//         if(s1 >= s2) cout << "0\n";
//         else{
//             int ans = mid - s1;
//             if((n - mid) & 1) ans++;
//             cout << ans << endl;
//         }
//         return;
//     }else{
//         if(s1 - 1 >= mid) cout << 1 << endl;
//         else{
//             int ans = mid - s1;
//             if((n - mid) & 1) ans++;
//             cout << ans << endl;
//         }
//         return;
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
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 3e5 + 10;
// int n, a[N];
// const int mod = 998244353;


// void solve(){
//     string L, R;
//     cin >> L >> R;
//     R = '0' + R;
//     while(L.size() < R.size()) L = '0' + L;
//     int ans = 0;
//     bool f = false;
//     n = L.size();
//     for(int i = 0;i < n;i++){
//         if(f) ans += 9;
//         else ans += abs(R[i] - L[i]);
//         if(R[i] > L[i]) f = true;
//     }
//     // cout << L << ' ' << R << endl;
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
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 3e5 + 10;
// int n, a[N];
// const int mod = 998244353;


// void solve(){
//     string s1, s2;
//     cin >> n >> s1 >> s2;
//     if(s1 == s2){
//         cout << "0\n";
//         return;
//     }
//     int ans1 = 0, ans2 = 0;
//     for(int i = 0;i < n;i++){
//         if(s1[i] != s2[i]) ans1++;
//     }
//     if(ans1 % 2 == 0) ans1 += ans1;
//     else ans1 += ans1 - 1;

//     reverse(s2.begin(), s2.end());
//     if(s1 == s2){
//         ans2 = 2;
//     }else{
//         for(int i = 0;i < n;i++){
//             if(s1[i] != s2[i]) ans2++;
//         }
//         if(ans2 % 2 == 1) ans2 += ans2;
//         else ans2 += ans2 - 1;
//     }
//     // cout << ans1 << endl << ans2 << endl;
//     cout << min(ans1, ans2) << endl;
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
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e5 + 10;
// int n, m, a[N], l[N], r[N], len[N];


// void solve(){
//     cin >> n >> m;
//     int mnr = N, mxl = 0, mnlen = N;
//     for(int i = 1;i <= n;i++){
//         cin >> l[i] >> r[i];
//         len[i] = r[i] - l[i] + 1;
//         mnr = min(mnr, r[i]);
//         mxl = max(mxl, l[i]);
//         mnlen = min(mnlen, len[i]);
//     }

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         ans = max(ans, min(len[i], r[i] - mnr));        
//         ans = max(ans, min(len[i], mxl - l[i]));        
//         ans = max(ans, min(len[i], len[i] - mnlen));        
//     }

//     cout << ans * 2 << endl;
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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 3e5 + 10;
// int n, m, s, t, c[N], u[N], v[N], st[N], top;

// struct edge{
//     int to, clo;
//     int operator<(const edge& e) const{
//         return clo < e.clo;
//     }
// };
// vector<edge>g[N];


// void print(){
//     for(int i = 1;i <= top;i++) cout << st[i] << ' ';
// }

// bool vis[N];
// bool bad[N];
// void dfs(int u){
//     if(vis[u]){
//         cout << "TOO LONG\n";
//         exit(0);
//     }
//     vis[u] = 1;
//     if(u == t){
//         print();
//         exit(0);
//     }
//     bool cyc = true;
//     bool good = false;
//     for(auto [v, c] : g[u]) if(!bad[v]){
//         if(vis[v]){
//             cout << "TOO LONG\n";
//             exit(0);
//         }
//         st[++top] = c;
//         dfs(v);
//         top--;
//     }
//     if(!good) bad[u] = 1;
// }

// void solve(){
//     cin >> n >> m >> s >> t;
//     for(int i = 1;i <= m;i++){
//         cin >> u[i] >> v[i] >> c[i];
//         g[u[i]].push_back({v[i], c[i]});
//     }
//     for(int i = 1;i <= n;i++) if(g[i].size())
//         sort(g[i].begin(), g[i].end());
//     vector<bool>vis(n + 1);
//     queue<int>q;
//     q.push(s);
//     bool reach = false;
//     while(q.size()){
//         int cur = q.front();
//         if(cur == t){
//             reach = true;
//             break;
//         }
//         q.pop();
//         if(vis[cur]) continue;
//         vis[cur] = true;
//         for(auto [to, clo] : g[cur]) if(!vis[to]) q.push(to);
//     }
//     if(!reach){
//         cout << "IMPOSSIBLE\n";
//         return;
//     }
//     for(int i = 0;i <= n;i++) vis[i] = false;

//     dfs(s);
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
// const int N = 3e5 + 10;
// int n, m, a[N], b[N], k[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];

//     // for(int i = 1;i <= n / 2;i++) k[i] = 1;
//     // for(int i = (n / 2) + 1;i <= n;i++) k[i] = 2;
//     // if(n & 1) k[(n / 2) + 1] = 0;
//     // int s1 = 0, s2 = 0;
//     // for(int i = 1;i <= n;i++){
//     //     if(k[a[i]] <= 1) s1 += i;
//     //     if(k[b[i]] == 2 || k[b[i]] == 0) s2 += i;
//     // }

//     int l = n / 2, r = l + 1;
//     r += (n & 1);

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         if(a[i] <= l) ans += i;
//     }
//     for(int i = 1;i <= n;i++){
//         if(b[i] >= r) ans -= i;
//     }
    
//     int ans2 = 0;
//     for(int i = 1;i <= n;i++){
//         if(b[i] <= l) ans2 += i;
//     }
//     for(int i = 1;i <= n;i++){
//         if(a[i] >= r) ans2 -= i;
//     }


//     if(n & 1){
//         int mid = (n / 2) + 1;
//         for(int i = 1;i <= n;i++){
//             if(a[i] == mid) ans += i, ans2 -= i;
//             if(b[i] == mid) ans -= i, ans2 += i;
//         }
//     }

//     ans = min(abs(ans2), abs(ans));
//     cout << ans;
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
// const int N = 3e5 + 10;
// int n, a, b, c, k, l[3], r[3], len[3];

// void solve(){
//     cin >> a >> b >> c >> k;
//     l[0] = pow(10, a - 1), r[0] = pow(10, a) - 1;
//     l[1] = pow(10, b - 1), r[1] = pow(10, b) - 1;
//     l[2] = pow(10, c - 1), r[2] = pow(10, c) - 1;
    

//     int cur = 0;
//     for(int i = l[0];i <= r[0];i++){
//         int lc = max(l[2], i + l[1]);
//         int lb = max(l[1], lc - i);
//         int rc = min(r[2], i + r[1]);
//         int rb = min(r[1], rc - i);

//         int lenb = rb - lb + 1;
//         if(lenb <= 0) continue;
//         // cout <<'['<<lb<<','<<rb<<"] "<<'['<<lc<<','<<rc<<"]\n";
//         cur += lenb;
//         if(cur >= k){
//             cur -= lenb;
//             cout << i << " + " << lb + (k - cur) - 1 << " = " << i + lb + (k - cur) - 1 << endl;
//             return;
//         }
//     }
//     cout << "-1\n";
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
// const int N = 3e5 + 10;
// int n;

// void solve(){
//     cin >> n;
//     int mn = -1e9 - 10;  
//     int f = 0;
//     while(n--){
//         int t;
//         cin >> t;
//         f = min(f, t);
//         mn = max(mn, t);
//     }
//     if(f < 0) cout << f << endl;
//     else cout << mn << endl;
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
// const int N = 3e5 + 10;
// int n, a[N], p[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         p[a[i]] = i;
//     }
//     int mid;
//     if(p[1] > p[n] && p[2] > p[n]){
//         cout << p[n] << ' ' << min(p[1], p[2]) << endl;
//         return;
//     }
//     if(p[1] < p[n] && p[2] < p[n]){
//         cout << p[n] << ' ' << max(p[1], p[2]) << endl;
//         return;
//     }
//     cout << "1 1\n";

// }

// signed main(){

//     IO;
//     a[0] = N;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 3e5 + 10;
// int n, a[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         cout << n - a[i] + 1 << ' ';
//     }
//     cout << endl;
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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 4e5 + 10;
// int n, a[N], b[N], ca[N], cb[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= 2 * n + 1;i++) ca[i] = cb[i] = 0;
//     a[n+1] = b[n+1] = 0; 

//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];

//     int tmp = 1;
//     for(int i = 1;i <= n;i++){
//         if(a[i] == a[i+1]) tmp++;
//         else{
//             ca[a[i]] = max(ca[a[i]], tmp);
//             tmp = 1;
//         }
//     }
//     tmp = 1;
//     for(int i = 1;i <= n;i++){
//         if(b[i] == b[i+1]) tmp++;
//         else{
//             cb[b[i]] = max(cb[b[i]], tmp);
//             tmp = 1;
//         }
//     }
//     int mx = 0;
//     for(int i = 1;i <= 2 * n;i++){
//         mx = max(mx, ca[i] + cb[i]);
//     }
//     cout << mx << endl;
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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, a[N];

// vector<array<int, 2>>g[N];

// int dp[N], ans;
// void dfs(int u, int f, int ti){
//     for(auto [v, t] : g[u]) if(v != f){
//         dp[v] = dp[u] + (ti > t);
//         ans = max(ans, dp[v]);
//         dfs(v, u, t);
//     }
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) g[i].clear();
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back({v, i});
//         g[v].push_back({u, i});
//     }

//     ans = dp[1] = 1;
//     dfs(1, 0, 0);
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
// int n, x[N], a, b;

// void solve(){
//     cin >> a >> b >> n;
//     int sum = b;
//     for(int i = 1;i <= n;i++) {
//         cin >> x[i];
//         sum += min(x[i], a - 1);
//     }
//     cout << sum << endl;
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
// int n, m, k, a[N], b[N];

// void solve(){
//     cin >> n >> m >> k;
//     int mn = 1e9, mx = 0;
//     int sum = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         sum += a[i];
//         mx = max(mx, a[i]);
//         mn = min(mn, a[i]);
//     }
//     int mn2 = 1e9, mx2 = 0;
//     for(int i = 1;i <= m;i++){
//         cin >> b[i];
//         mx2 = max(mx2, b[i]);
//         mn2 = min(mn2, b[i]);
//     }
//     if(k & 1){
//         if(mx2 > mn){
//             sum += mx2 - mn;
//         }
//     }else{
//         if(mx > mx2){   
//             if(mn < mx2){
//                 sum += mx2 - mn;
//                 sum += min(mn2, mn) - mx;
//             }else{
//                 sum += mn2 - mx;
//             }

//         }else{
//             sum -= mn;
//             sum += min(mn, mn2);
//         }
//     }
//     cout << sum << endl;
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

// int lowbit(int x){
//     return x & -x;
// }

// void solve(){
//     cin >> n >> m;
//     if(n % m == 0){
//         cout << "0\n";
//         return;
//     }
//     n = n - (n / m) * m;
//     int fm = m / __gcd(m, n);
//     if(lowbit(fm) != fm) {
//         cout << "-1\n";
//         return;
//     }
//     int cnt = 0;

//     while(n > 0){
//         cnt += n;
//         n *= 2;
//         if(n >= m) n -= m;
//     }
//     cout << cnt << endl;
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
// const int N = 5e3 + 10;
// int n, a[N], m, dp[N], c[N];
// const int inf = 0x3f3f3f3f;


// void solve(){
//     memset(c, 0, sizeof(c));
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     sort(a + 1, a + 1 + n);
//     if(a[1] != 0){
//         cout << "0\n";
//         return;
//     }
//     c[0] = 1;
//     m = 0;
//     for(int i = 2;i <= n;i++){
//         if(a[i] - a[i - 1] > 1) break;
//         c[a[i]]++;
//         m = max(m, a[i]);
//     }
//     m++;

//     dp[1] = c[0] - 1;
//     for(int i = 2;i <= m;i++){
//         dp[i] = (c[0] - 1) * i;
//         for(int j = 1;j < i;j++){
//             dp[i] = min(dp[i], dp[j] + i * (c[j] - 1) + j);
//         }
//     }

//     cout << dp[m] << endl;
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
// const int inf = 0x3f3f3f3f;


// void solve(){
//     int x, k;
//     cin >> x >> k;
//     if(x % k){
//         cout << "1\n";
//         cout << x << endl;
//     }else{
//         cout << "2\n";
//         cout << x - 1 << ' ' << 1 << endl;
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
// int n, a[N];
// const int inf = 0x3f3f3f3f;


// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     set<char>st;
//     for(auto c : s) st.insert(c);
//     if(st.size() == 1){
//         cout << n + 1 << endl;
//         return;
//     }

//     map<char, int>mp;
//     mp['>'] = mp['<'] = 1;

//     for(int i = 0;i < n - 1;i++){
//         if(s[i] == s[i + 1]){
//             int len = 2;
//             for(int j = i + 2;j < n;j++){
//                 if(s[j] == s[i]) len++;
//                 else break;
//                 i = j;
//             }
//             mp[s[i]] = max(mp[s[i]], len);
//         }
//     }
//     cout << max(mp['>'], mp['<']) + 1 << endl;
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
// const int inf = 0x3f3f3f3f;


// void solve(){
//     string s;
//     cin >> s;
//     n = s.size();
//     s = '0' + s;
//     for(int i = 1;i <= n;i++){
//         if(s[i] == '?'){
//             s[i] = s[i-1];
//         }
//         cout << s[i];
//     }
//     cout << endl;
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
// int n, ans[N], top;
// const int inf = 0x3f3f3f3f;

// int mp[300];


// void solve(){
//     top = 0;
//     int c1 = 0, c2 = 0;
//     cin >> n;
//     string s;
//     cin >> s;

//     mp['('] = mp[')'] = 0;
//     for(auto c : s) mp[c]++;
//     if(mp['('] != mp[')']){
//         cout << "-1\n";
//         return;
//     }

//     int cur = 0;
//     for(int i = 0;i < n;i++){
//         if(s[i] == '('){
//             if(cur >= 0) ans[++top] = 1, c1 = 1;
//             else ans[++top] = 2, c2 = 1;
//             cur++;
//         }else{
//             if(cur > 0) ans[++top] = 1, c1 = 1;
//             else ans[++top] = 2, c2 = 1;
//             cur--;
//         }
//     }
//     cout << c1 + c2 << endl;
//     if(c1 + c2 == 1){
//         for(int i = 1;i <= n;i++) cout << "1 ";
//     }else
//         for(int i = 1;i <= top;i++) cout << ans[i] << ' ';
//     cout << endl;
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
// int n, m, q, k, c[N], d[N];

// bool red[N];

// vector<array<int, 2>>g[N];

// void dfs1(int u, int f) {
//     for (auto [v, w] : g[u]) if(v != f){
//         d[v] = d[u] + w;
//         if (red[v]) c[v] = 0;
//         else c[v] = c[u] + w;
//         dfs1(v, u);
//     }
// }

// //树剖
// // int par[N], dep[N], top[N], son[N], siz[N];
// // void pre_dfs(int u, int fa){
// //     par[u] = fa;
// //     dep[u] = dep[fa] + 1;
// //     siz[u] = 1;
// //     for(auto [v, w] : g[u]) if(v != fa){
// //         pre_dfs(v, u);
// //         siz[u] += siz[v];
// //         if(siz[v] > siz[son[u]])
// //             son[u] = v;
// //     }
// // }
// // void dfs(int u, int tp){
// //     top[u] = tp;
// //     if(son[u]) dfs(son[u], tp);
// //     else return;

// //     for(auto [v, w] : g[u]) if(v != par[u] && v != son[u])
// //         dfs(v, v);
// // }
// // int lca(int a, int b){
// //     while(top[a] != top[b]){
// //         if(dep[top[a]] > dep[top[b]])
// //             a = par[top[a]];
// //         else
// //             b = par[top[b]];
// //     }
// //     return dep[a] < dep[b] ? a : b;
// // }

// int fa[N][20], dep[N], last[N];
// void dfs(int u, int par)
// {
//     fa[u][0] = par;
//     for (int i = 1; i <= 18; ++i)
//         fa[u][i] = fa[fa[u][i - 1]][i - 1];
//     dep[u] = dep[par] + 1;
//     if (red[u])
//         last[u] = u;
//     else
//         last[u] = last[par];
//     c[u] = d[u] - d[last[u]];
//     for (auto [v, w] : g[u])
//     {
//         if (v == par)
//             continue;
//         d[v] = d[u] + w;
//         dfs(v, u);
//     }
// }
// int lca(int u, int v)
// {
//     if (dep[u] < dep[v])
//         swap(u, v);
//     for (int i = 18; i >= 0; --i)
//         if (dep[fa[u][i]] >= dep[v])
//             u = fa[u][i];
//     if (u == v)
//         return u;
//     for (int i = 18; i >= 0; --i)
//         if (fa[u][i] != fa[v][i])
//             u = fa[u][i], v = fa[v][i];
//     return fa[u][0];
// }

// void init(){
//     for(int i = 0;i <= n;i++){
//         red[i] = false;
//         // top[i] = son[i] = 0;
//         c[i] = d[i] = 0;
//         g[i].clear();
//     }

// }

// void solve(){
//     cin >> n >> m >> q;
//     init();
//     for(int i = 1, u;i <= m;i++){
//         cin >> u;
//         red[u] = true;
//     }
//     for(int i = 1, u, v, w;i < n;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }   

//     // dfs1(1, 0);
//     // pre_dfs(1, 0);  
//     dfs(1, 1);
    
//     while(q--){
//         cin >> k;
//         vector<int>vec(k);
//         for(auto &e : vec) cin >> e;
//         sort(vec.begin(), vec.end(), [](int e1, int e2)-> int {return c[e1] > c[e2];});

//         int ans = c[vec[0]];
//         int lc = vec[0], mx = d[vec[0]];
//         for(int i = 1;i < k;i++){
//             lc = lca(lc, vec[i-1]);
//             mx = max(mx, d[vec[i - 1]]);
//             ans = min(ans, max(mx - d[lc], c[vec[i]]));
//         }
//         lc = lca(lc, vec.back());
//         mx = max(mx, d[vec.back()]);
//         ans = min(ans, mx - d[lc]);
//         cout << ans << endl;
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
// const int N = 1e5 + 10;
// int n, m, X[N], Y[N], Z[N], R, ans[N];

// vector<int>g[N];

// int dep[N], siz[N], son[N], top[N], par[N];
// void dfs1(int u, int f){
//     dep[u] = dep[f] + 1;
//     par[u] = f;
//     siz[u] = 1;
//     for(auto v : g[u]) if(v != f){
//         dfs1(v, u);
//         siz[u] += siz[v];
//         if(siz[v] > siz[son[u]]) son[u] = v;   
//     }
// }
// void dfs2(int u, int tp){
//     top[u] = tp;
//     if(son[u]) dfs2(son[u], tp);
//     else return;

//     for(auto v : g[u]) if(v != par[u] && v != son[u]) 
//         dfs2(v, v);
// }
// int lca(int u, int v){
//     while(top[u] != top[v]){
//         if(dep[top[u]] < dep[top[v]]) swap(u, v);
//         u = par[top[u]];
//     }
//     return dep[v] < dep[u] ? v : u;
// }

// struct node{
//     int mx, k;
//     int operator<(const node& e) const {
//         return mx < e.mx;
//     }
// }tr[N * 100];
// int rt[N * 100], ls[N * 100], rs[N * 100], tot;

// void up(int id){
//     tr[id] = max(tr[ls[id]], tr[rs[id]]);
// }
// void change(int &id, int l, int r, int x, int v){
//     if(!id) id = ++tot;
//     if(l == r){
//         tr[id].mx += v;
//         tr[id].k = l;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(ls[id], l, mid, x, v);
//     else change(rs[id], mid + 1, r, x, v);
//     up(id);
// }

// void merg(int &a, int b, int l, int r){
//     if(!b) return;
//     if(!a){
//         a = b;
//         return;
//     }
//     if(l == r){
//         tr[a].mx += tr[b].mx;
//         return;
//     }
//     int mid = l + r >> 1;
//     merg(ls[a], ls[b], l, mid);
//     merg(rs[a], rs[b], mid + 1, r);
//     up(a);
// }

// void dfs(int u, int f){
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         merg(rt[u], rt[v], 1, R);
//     }
//     if(tr[rt[u]].mx > 0)
//         ans[u] = tr[rt[u]].k;
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs1(1, 0);
//     dfs2(1, 1);

//     for(int i = 1;i <= m;i++){
//         cin >> X[i] >> Y[i] >> Z[i];
//         R = max(R, Z[i]);
//     }
//     for(int i = 1, lc;i <= m;i++){
//         lc = lca(X[i], Y[i]);
//         change(rt[X[i]], 1, R, Z[i], 1);
//         change(rt[Y[i]], 1, R, Z[i], 1);
//         change(rt[lc], 1, R, Z[i], -1);
//         if(par[lc]) change(rt[par[lc]], 1, R, Z[i], -1);
//     }

//     dfs(1, 0);
//     for(int i = 1;i <= n;i++) cout << ans[i] << endl;
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
// const int N = 1e6 + 10;
// int n, m;

// vector<int>g[N];

// int dep[N], mdp[N];
// void dfs(int u, int f){
//     mdp[u] = dep[u] = dep[f] + 1;
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         mdp[u] = max(mdp[u], mdp[v]);
//     }
//     sort(g[u].begin(), g[u].end(), [](int e1, int e2)->int {return mdp[e1] < mdp[e2];});
// }

// int ans;

// void dfs2(int u, int f){
//     ans++;
//     int bk = 0;
//     for(auto v : g[u]) if(v != f){
//         ans += bk;
//         dfs2(v, u);
//         bk = min(dep[u], mdp[v] - dep[u]);
//     }
// }

// void init(){
//     dep[0] = -1;
//     ans = -1;
//     for(int i = 1;i <= n;i++) {
//         g[i].clear();
//     }
// }

// void solve(){
//     cin >> n;
//     init();
//     for(int i = 2, v;i <= n;i++){
//         cin >> v;
//         g[i].push_back(v);
//         g[v].push_back(i);
//     }

//     dfs(1, 0);
//     dfs2(1, 0);

//     cout << ans << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     for(int i = 1;i <= t;i++){
//         cout << "Case #" << i << ": ";
//         solve(); 
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 3e5 + 10;
// const int mod = 998244353;
// int n, m, a[N], num[33][N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         for(int j = 0;j <= 30;j++){
//             num[j][i] = (a[i] >> j) & 1;
//         }
//     }

//     int ans = 0;
//     int pw = 1;
//     for(int i = 0;i <= 30;i++){
//         vector<int>pre(n + 10);
//         int ls[2] = {0};
//         int lc[2] = {0};
//         for(int j = 1;j <= n;j++){
//             pre[j] = pre[j - 1] ^ num[i][j];
//             ls[pre[j - 1]] += j - 1;
//             lc[pre[j - 1]]++;
            

//             int tmp = pre[j] ^ 1;
//             // int slen = (lc[tmp] * j - ls[tmp]) % mod;
//             // ans = (ans + (pw * slen % mod)) % mod;
//             ans = (ans + (pw * ((lc[tmp] * j - ls[tmp]) % mod) % mod) ) % mod;
//             // ans = (ans + ((pw * lc[tmp] * j - pw * ls[tmp] % mod) % mod) ) % mod;
//         }
//         pw <<= 1;
//         pw %= mod;
//     }

//     cout << ans << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     for(int i = 1;i <= t;i++){
//         solve(); 
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2000 + 10;
// const int inf = 0x3f3f3f3f;
// int n, m;

// struct node{
//     int l, r;
//     int operator<(const node& e) const{
//         if(l == e.l) return r < e.r;
//         return l < e.l;
//     }
//     int operator==(const node& e) const{
//         return l == e.l && r == e.r;
//     }
// }g[N];

// int mn[N << 3];
// void up(int id){
//     mn[id] = min(mn[lson], mn[rson]);
// }
// void build(int id, int l, int r){
//     if(l == r){
//         mn[id] = inf;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         mn[id] = min(mn[id], v);
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(lson, l, mid, x, v);
//     else change(rson, mid + 1, r, x, v);
//     up(id);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(ql > qr) return inf; 
//     if(ql <= l && r <= qr) return mn[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return min(query(lson, l, mid, ql, qr), query(rson, mid + 1, r, ql, qr));
// }

// void solve(){
//     cin >> n;
//     m = n * 2 + 10;
//     build(1, 1, m);
//     vector<int>idx;
//     for(int i = 1;i <= n;i++){
//         cin >> g[i].l >> g[i].r;
//         idx.push_back(g[i].l);
//         idx.push_back(g[i].r);
//     }
//     sort(all(idx));
//     idx.erase(unique(all(idx)), idx.end());
//     sort(g + 1, g + 1 + n);
//     for(int i = 1;i <= n;i++){
//         g[i].l = lower_bound(all(idx), g[i].l) - idx.begin() + 1;
//         g[i].r = lower_bound(all(idx), g[i].r) - idx.begin() + 1;
//         change(1, 1, m, g[i].l, g[i].r);
//         // cerr << g[i].l << ' ' << g[i].r << endl;
//     }

//     int pcnt = 0;
//     for(int i = 1;i < n;i++){ //枚举起点边
//         int cur = i;
//         int r;
//         int tmp = 0;
//         while(cur < n){
//             // cerr << cur << endl;
//             if(g[cur].l == g[cur + 1].l) r = g[cur + 1].r;
//             else r = max(query(1, 1, m, g[cur].l + 1, g[cur].r), g[cur].r);
//             if(r == inf){
//                 cur++;
//             }else{
//                 tmp++;
//                 while(cur < n && g[cur].l <= r) cur++;
//             }
//         }
//         pcnt = max(pcnt, tmp);
//     }

//     cout << n - pcnt * 2 << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     for(int i = 1;i <= t;i++){
//         solve(); 
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// const int N = 2000 + 10;
// const int inf = 0x3f3f3f3f;
// int n, m, l[N], r[N];


// void solve(){
//     cin >> n;
//     vector<int>l(n), r(n), idx(n);
//     for(int i = 0; i < n;i++){
//         cin >> l[i] >> r[i];
//         idx[i] = i;
//     }
//     sort(all(idx),
//         [&](int i, int j){
//             return r[i] < r[j];
//         });
    
//     int pcnt = 0;
//     int lastp = -1, lastr = -1;
//     for(auto i : idx){
//         if(l[i] <= lastp) continue;
//         if(l[i] <= lastr){
//             pcnt++;
//             lastp = r[i];
//         }else{
//             lastr = r[i];
//         }
//     }

//     cout << n - 2 * pcnt << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     for(int i = 1;i <= t;i++){
//         solve(); 
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// const int N = 2000 + 10;
// const int inf = 0x3f3f3f3f;
// int n, m;

// unordered_map<char, int>mp;

// int val(const string& s){
//     int ret = 0;
//     int mx = 0;
//     for(int i = s.size() - 1;i >= 0;i--){
//         if(mp[s[i]] < mx) ret -= mp[s[i]];
//         else ret += mp[s[i]];
//         mx = max(mx, mp[s[i]]);
//     }
//     return ret;
// }

// void solve(){
//     string s;
//     cin >> s;

//     int ans = val(s);
//     for(int to = 'A';to <= 'E';to++){
//         for(int i = s.size() - 1;i >= 0;i--){
//             if(s[i] == to){
//                 for(int j = 'A';j <= 'E';j++){
//                     s[i] = j;
//                     ans = max(ans, val(s));
//                 }
//                 s[i] = to;
//                 break;
//             }
//         }
//         for(int i = 0, len = s.size();i < len;i++){
//             if(s[i] == to){
//                 s[i] = 'E';
//                 ans = max(ans, val(s));
//                 s[i] = to;
//                 break;
//             }
//         }
//     }

//     cout << ans << endl;
// }   

// signed main(){

//     IO;
//     mp['A'] = 1;
//     mp['B'] = 10;
//     mp['C'] = 100;
//     mp['D'] = 1000;
//     mp['E'] = 10000;
//     int t = 1;
//     cin >> t;
//     for(int i = 1;i <= t;i++){
//         solve(); 
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// const int N = 2000 + 10;
// const int inf = 0x3f3f3f3f;
// int n, m, k;


// void solve(){
//     cin >> n >> k;
//     vector<int>l(n), r(n), pre(n), ocnt(n);
//     for(auto &e : l) cin >> e;
//     for(auto &e : r) cin >> e;
//     pre[0] = r[0] - l[0] + 1;
//     if(pre[0] == 1) ocnt[0] = 1;
//     for(int i = 1; i < n;i++){
//         pre[i] = r[i] - l[i] + 1 + pre[i - 1];
//         ocnt[i] = ocnt[i - 1];
//         if(r[i] == l[i]) ocnt[i]++;
//     }

//     int st = -1;
//     for(int i = 0;i < n;i++){
//         if(pre[i] >= k){
//             st = i;
//             break;
//         }
//     }

//     if(st == -1){
//         cout << "-1\n";
//         return;
//     }

//     auto val = [&](int x) {
//         int ret = r[x] + (x + 1) * 2;
//         int bk = pre[x]; //黑格数
//         int d = bk - k;  //多余黑格
//         int giup = min(ocnt[x], d); //放弃线段数
//         ret -= giup * 2;
//         bk -= giup;
//         d = bk - k; 
//         ret -= d;
//         return ret;
//     };

//     int ans = val(st);
//     while(st < n){
//         ans = min(ans, val(st++));
//     }

//     cout << ans << endl;

// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     for(int i = 1;i <= t;i++){
//         solve(); 
//     }

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 1e5 + 10;
// int n, m, a[N], f[N][20], Log[N];


// signed main(){

//     IO;

//     cin >> n >> m;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         f[i][0] = a[i];
//     }
//     for(int j = 1;j < 20 ;j++){
//         for(int i = 1;i <= n && i + (1 << j) - 1 <= n;i++){
//             f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
//         }
//     }
//     for(int i = 2;i <= n;i++){
//         Log[i] = Log[i / 2] + 1;
//     }

//     int l, r, s;
//     while(m--){
//         cin >> l >> r;
//         s = Log[r - l + 1];
//         cout << max(f[l][s], f[r - (1 << s) + 1][s]) << endl;
//     }

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// const int N = 2e5 + 10;
// int n;

// void solve(){
//     cin >> n;
//     vector<int>h(n), w(n);
//     int mw = 0, mh = 0;
//     int S = 0;
//     for(int i = 0;i < n;i++){
//         cin >> h[i] >> w[i];
//         mw = max(mw, w[i]);
//         mh = max(mh, h[i]);
//         S += h[i] * w[i];
//     }

//     vector<int>sw(n), sh(n);
//     iota(all(sw), 0);
//     iota(all(sh), 0);
//     sort(all(sw), [&](int i, int j){
//         return w[i] > w[j];
//     });
//     sort(all(sh), [&](int i, int j){
//         return h[i] > h[j];
//     });

//     set<pair<int, int>>st;
//     auto print = [&](){
//         cout << st.size() << endl;
//         for(auto [a, b] : st) cout << a << ' ' << b << endl;
//     };


//     //先找最大宽度
//     int h1, w1;
//     w1 = mw;
//     h1 = S / w1;
//     if(w1 * h1 == S){
//         st.insert({h1, w1});
//         vector<bool>vis(n);
//         int hp = 0, wp = 0;
//         int W = w1, H = h1;
//         int cnt = 0;
//         while(cnt < n){
//             bool f = false;
//             for(wp; wp < n;wp ++) if(!vis[sw[wp]]){
//                 if(w[sw[wp]] != W) break;
//                 vis[sw[wp]] = true;
//                 cnt++;
//                 H -= h[sw[wp]];
//                 f = true;
//             }
//             if(!f){
//                 st.clear();
//                 break;
//             }
//             if(!H) break;
//             f = false;
//             for(hp; hp < n; hp++) if(!vis[sh[hp]]){
//                 if(h[sh[hp]] != H) break;
//                 vis[sh[hp]] = true;
//                 cnt++;
//                 W -= w[sh[hp]];
//                 f = true;
//             }
//             if(!f){
//                 st.clear();
//                 break;
//             }
//         }
//     }

//     int h2, w2;
//     h2 = mh;
//     w2 = S / h2;
//     if(h2 * w2 == S){
//         st.insert({h2, w2});
//         if(st.size() == 1){
//             print();
//             return;
//         }        

//         vector<bool>vis(n);
//         int hp = 0, wp = 0;
//         int W = w2, H = h2;
//         int cnt = 0;
//         while(cnt < n){
//             bool f = false;
//             for(hp; hp < n;hp ++) if(!vis[sh[hp]]){
//                 if(h[sh[hp]] != H) break;
//                 vis[sh[hp]] = true;
//                 cnt++;
//                 W -= w[sh[hp]];
//                 f = true;
//             }
//             if(!f){
//                 st.erase(st.find({h2, w2}));
//                 break;
//             }
//             if(!W) break;
//             f = false;
//             for(wp; wp < n; wp++) if(!vis[sw[wp]]){
//                 if(w[sw[wp]] != W) break;
//                 vis[sw[wp]] = true;
//                 cnt++;
//                 H -= h[sw[wp]];
//                 f = true;
//             }
//             if(!f){
//                 st.erase(st.find({h2, w2}));
//                 break;
//             }
//         }
//     }
//     print();
// }

// signed main(){

//     IO;
    
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2010;
// int n, m, d[N];
// bool mp[N][N];
// vector<int>g[N];


// void init(){
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= n;j++){
//             mp[i][j] = 0;
//         }
//     }
//     for(int i = 1;i <= n;i++){
//         d[i] = 0;
//         g[i].clear();
//     }
// }

// void solve(){
//     cin >> n >> m;
//     init();
//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         mp[u][v] = mp[v][u] = 1;
//         g[u].push_back(v);
//         g[v].push_back(u);
//         d[u]++;
//         d[v]++;
//     }


//     for(int i = 1;i <= n;i++) if(d[i] >= 4){
//         vector<bool>vis(n + 1);
//         vector<int>fa(n + 1);

//         for(int j = 1;j <= n;j++) if(mp[i][j] && !vis[j]){
//             vis[j] = 1;
//             fa[j] = i;
//             queue<int>que;
//             for(auto v : g[j]) if(v != i){
//                 que.push(v);
//                 fa[v] = j;
//             }
//             while(que.size()){
//                 int u = que.front();
//                 que.pop();
//                 if(vis[u]) continue;
//                 vis[u] = 1;
//                 if(mp[u][i]){
//                     for(int i = 1;i <= n;i++) vis[i] = 0;
//                     cout << "YES\n";
//                     int cnt = 3;
//                     int cur = u;
//                     while(cur != i){
//                         cnt++;
//                         vis[cur] = 1;
//                         cur = fa[cur];
//                     }
//                     cur = u;
//                     cout << cnt << '\n';
//                     cout << u << ' ' << i << endl;
//                     while(cur != i){
//                         cout << cur << ' ' << fa[cur] << endl;
//                         cur = fa[cur];
//                     }

//                     int tmp = 0;
//                     for(int k = 1;k <= n && tmp < 2;k++) if(mp[k][i] && !vis[k]){
//                         cout << i << ' ' << k << endl;
//                         tmp++;
//                     }
//                     return;
//                 }
//                 for(auto v : g[u]) if(!vis[v]){
//                     que.push(v);
//                     fa[v] = u;
//                 }
//             }
//         }
//     }

//     cout << "NO\n";

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
// int n;
// string l, r;

// int val(const string &s){
//     char mx = 0, mn = '9';
//     for(auto c : s) {
//         mx = max(mx, c);
//         mn = min(mn, c);
//     }
//     return mx - mn;
// }

// int cmp(const string &s1, const string &s2){
//     return val(s1) < val(s2);
// }

// void solve(){
//     cin >> l >> r;
//     if(l.size() != r.size()){
//         for(int i = 1, len = l.size();i <= len;i++) cout << 9;
//         cout << endl;
//         return;
//     }
//     if(r[0] - l[0] > 1){
//         for(int i = 1, len = l.size();i <= len;i++) cout << (char)(l[0]+1);
//         cout << endl;
//         return;
//     }
//     if(l == r){
//         cout << l << endl;
//         return;
//     }

//     n = l.size();
//     string ans = min(l, r, cmp);    
//     string s(l);
//     for(int i = 0;i < n;i++){
//         for(int j = i + 1;j < n;j++) s[j] = s[i];
//         if(s >= l && s <= r) ans = min(ans, s, cmp);
//         s = l;
//     }
//     for(int i = 0;i < n;i++)if(s[i] < '9'){
//         s[i]++;
//         for(int j = i + 1;j < n;j++) s[j] = s[i];
//         if(s <= r) ans = min(ans, s, cmp);
//         s = l;
//     }
//     s = r;
//     for(int i = 0;i < n;i++){
//         for(int j = i + 1;j < n;j++) s[j] = s[i];
//         if(s >= l && s <= r) ans = min(ans, s, cmp);
//         s = r;
//     }
//     for(int i = 0;i < n;i++) if(s[i] > '0'){
//         s[i]--;
//         for(int j = i + 1;j < n;j++) s[j] = s[i];
//         if(s >= l) ans = min(ans, s, cmp);
//         s = r;
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
// const int M = N * 30;
// int n, k, a[N];
// int rt[2][N], sum[2][M], tot, ls[M], rs[M];

// void update(int id, int &cur, int pre, int l, int r, int x){
//     cur = ++tot;
//     ls[cur] = ls[pre], rs[cur] = rs[pre];
//     sum[id][cur] = sum[id][pre] + 1;
//     // cerr << l << ' ' << r << endl;
//     if(l == r){
//         // cerr << cur << ' ' << sum[id][cur] << endl;;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) update(id, ls[cur], ls[pre], l, mid, x);
//     else update(id, rs[cur], rs[pre], mid + 1, r, x);
// }
// int query(int id, int L, int R, int l, int r, int x){
//     // cerr << l << ' ' << r << endl;
//     if(l == r){
//         // cerr << R << ' ' << sum[id][R] << endl;;
//         return sum[id][R] - sum[id][L];
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) return query(id, ls[L], ls[R], l, mid, x);
//     else return query(id, rs[L], rs[R], mid + 1, r, x);
// }

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++){
//         int id = i & 1, id2 = id ^ 1;
//         // cerr << id << ' ' << id2 << endl;
//         cin >> a[i];
//         update(id, rt[id][i], rt[id][i - 1], 1, 2e5, a[i]);
//         rt[id2][i] = rt[id2][i - 1];
//     }
//     if(k == 1){
//         cout << 0 << endl;
//         return;
//     }
//     // cerr << "___\n";
//     // cerr << query(1, rt[1][0], rt[1][1], 1, 2e5, 1);
//     int hf = k / 2;
//     int sum = hf * (n - k + 1);
//     for(int i = 1;i <= n;i++){
//         int l = i + 2, r = i + k - 1;
//         while(l <= r){
//             int mid = l + r >> 1;
//             int x = (i + mid) / 2;
//             if(x - hf >= 1) r = mid - 1;
//             else l = mid + 1;
//         }
//         int L = l;
//         l = i + 2, r = i + k - 1;
//         while(l <= r){
//             int mid = l + r >> 1;
//             int x = (i + mid) / 2;
//             if(x + hf <= n) l = mid + 1;
//             else r = mid - 1;
//         }
//         int R = r;
//         int id = i & 1;
//         sum -= query(id, rt[id][L - 1], rt[id][R], 1, 2e5, a[i]);
//         // cerr << i << "sum: " << L << ' ' << R << " = " << query(id, rt[id][L - 1], rt[id][R], 1, 2e5, a[i]) << endl;
//     }
//     cout << sum << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     // for(int i = 1;i <= 3;i++){
//     //     update(1, rt[1][i], rt[1][i-1], 1, 2e5, i);
//     // }
//     // cerr << query(1, rt[1][0], rt[1][3], 1, 2e5, 1) << endl;
//     // cerr << query(1, rt[1][0], rt[1][3], 1, 2e5, 2) << endl;
//     // cerr << query(1, rt[1][0], rt[1][3], 1, 2e5, 3) << endl;

//     return 0;
// }