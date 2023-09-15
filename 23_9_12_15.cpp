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