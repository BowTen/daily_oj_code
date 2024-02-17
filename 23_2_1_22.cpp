// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 3e5 + 10;
// int n, m, q;

// class Tree{
// public:
//     vector<int>mn, tag, a;

//     void up(int id){
//         mn[id] = min(mn[ls], mn[rs]);
//     }
//     void settag(int id, int x){
//         tag[id] += x;
//         mn[id] += x;
//     }
//     void down(int id){
//         settag(ls, tag[id]);
//         settag(rs, tag[id]);
//         tag[id] = 0;
//     }
//     void build(int id, int l, int r){
//         if(l == r){
//             mn[id] = a[l];
//             return;
//         }
//         int mid = l + r >> 1;
//         build(ls, l, mid);
//         build(rs, mid + 1, r);
//         up(id);
//     }

//     Tree(vector<int>v, int sz) : a(v), mn(sz*4+10), tag(sz*4+10) {
//         build(1, 1, sz);
//     }

//     int getmn(int id, int l, int r, int ql, int qr){
//         if(ql <= l && r <= qr) return mn[id];
//         if(tag[id]) down(id);
//         int mid = l + r >> 1;
//         if(qr <= mid) return getmn(ls, l, mid, ql, qr);
//         else if(ql > mid) return getmn(rs, mid + 1, r, ql, qr);
//         else return min(getmn(ls, l, mid, ql, qr), getmn(rs, mid + 1, r, ql, qr));
//     }

//     void modify(int id, int l, int r, int ql, int qr, int x){
//         if(ql <= l && r <= qr) {
//             settag(id, x);
//             return;
//         }
//         if(tag[id]) down(id);
//         int mid = l + r >> 1;
//         if(qr <= mid) modify(ls, l, mid, ql, qr, x);
//         else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x);
//         else modify(ls, l, mid, ql, qr, x), modify(rs, mid + 1, r, ql, qr, x);
//         up(id);
//     }
// };


// void solve(){
//     cin >> n >> m;
//     vector<int>a(n+5), b(m+5), v(n+5), pre(n+5), c(N);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= m;i++) cin >> b[i], c[1]++, c[b[i]+1]--;
    
//     vector<int>oa(a);
//     sort(all1(a), greater<int>());
//     for(int i = 1;i <= n;i++){
//         pre[i] += pre[i-1] + a[i];
//         c[i] += c[i-1];
//     }

//     for(int i = 1;i <= n;i++){
//         c[i] += c[i-1];
//         v[i] = c[i] - pre[i];
//     }

//     Tree tr(v, n);

//     sort(all1(a));

//     cin >> q;
//     while(q--){
//         int op, x;
//         cin >> op >> x;
//         if(op == 1){
//             int id = upper_bound(all1(a), oa[x]) - a.begin() - 1;
//             a[id]++;
//             id = n-id+1;
//             oa[x]++;
//             tr.modify(1, 1, n, id, n, -1);
//         }else if(op == 2){
//             int id = lower_bound(all1(a), oa[x]) - a.begin();
//             a[id]--;
//             id = n-id+1;
//             oa[x]--;
//             tr.modify(1, 1, n, id, n, 1);
//         }else if(op == 3){
//             b[x]++;
//             if(b[x] <= n) tr.modify(1, 1, n, b[x], n, 1);
//         }else{
//             if(b[x] <= n) tr.modify(1, 1, n, b[x], n, -1);
//             b[x]--;
//         }
//         if(tr.mn[1] >= 0) cout << "1\n";
//         else cout << "0\n";
//     }
// } 

// signed main(){

// 	IO;
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 3e5 + 10;

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5), d(n+5), mx(n+5), c(n+5);
//     vector<vector<int>>g(n+5);
//     for(int i = 2, p;i <= n;i++){
//         cin >> p;
//         g[p].push_back(i);
//     }
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     auto dfs = [&](auto self, int u) -> void {
//         if(g[u].size() == 0){
//             c[u] = 1;
//             mx[u] = a[u];
//             return;
//         }

//         for(auto v : g[u]) {
//             self(self, v);
//             mx[u] = max(mx[u], mx[v]);
//             c[u] += c[v];
//             d[u] += d[v];
//         }
//         for(auto v : g[u]) {
//             d[u] += (mx[u] - mx[v]) * c[v];
//         }

//         if(d[u] >= a[u]){
//             d[u] -= a[u];
//         }else{
//             a[u] -= d[u];
//             mx[u] += a[u] / c[u];
//             if(a[u] % c[u]){
//                 mx[u]++;
//                 d[u] = c[u] - (a[u] % c[u]);
//             }else{
//                 d[u] = 0;
//             }
//         }
//     };

//     dfs(dfs, 1);

//     cout << mx[1] << endl;
// } 

// signed main(){

// 	IO;
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int N = 1e5 + 10;
// const int M = N * 50;

// class Tree{
// public:
//     int mx[M], rt[N], tot, ls[M], rs[M];

//     void up(int id){
//         mx[id] = max(mx[ls[id]], mx[rs[id]]);
//     }
//     void change(int &id, int l, int r, int x, int v){
//         if(!id) id = ++tot;
//         if(l == r){
//             mx[id] = max(v, mx[id]);
//             return;
//         }
//         int mid = l + r >> 1;
//         if(x <= mid) change(ls[id], l, mid, x, v);
//         else change(rs[id], mid + 1, r, x, v);
//         up(id);
//     }
//     int query(int &id, int l, int r, int ql, int qr){
//         if(!id) return 0;
//         if(ql <= l && r <= qr) return mx[id];
//         int mid = l + r >> 1;
//         if(qr <= mid) return query(ls[id], l, mid, ql, qr);
//         else if(ql > mid) return query(rs[id], mid + 1, r, ql, qr);
//         else return max(query(ls[id], l, mid, ql, qr), query(rs[id], mid + 1, r, ql, qr));
//     }
// }tr;


// void solve(){
//     int n, m, ans = 0;
//     cin >> n >> m;
//     for(int i = 1, u, v, w;i <= m;i++){
//         cin >> u >> v >> w;
//         w++;
//         int mx = (w == 1 ? 0 : tr.query(tr.rt[u], 1, 1e5+1, 1, w-1)) + 1;
//         tr.change(tr.rt[v], 1, 1e5+1, w, mx);
//         ans = max(ans, tr.mx[tr.rt[v]]);
//     }
//     cout << ans << endl;
// } 

// signed main(){

// 	IO;
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int N = 5e4 + 10;
// const int M = N * 50;
// int n, m, q, C;
// int f[N], c[N];
// vector<int>g[N];

// class Tree{
// public:
//     int s[M], s2[M], len[M], rt[N], tot, tag[M], ls[M], rs[M];

//     void up(int id){
//         s[id] = s[ls[id]] + s[rs[id]];
//         s2[id] = s2[ls[id]] + s2[rs[id]];
//         len[id] = len[ls[id]] + len[rs[id]];
//     }
//     void settag(int id, int x){
//         s2[id] += len[id] * x*x + 2*s[id]*x;
//         s[id] += len[id] * x;
//         tag[id] += x;
//     }
//     void down(int id){
//         settag(ls[id], tag[id]);
//         settag(rs[id], tag[id]);
//         tag[id] = 0;
//     }
//     void modify(int &id, int l, int r, int ql, int qr, int v){
//         if(!id){
//             id = ++tot;
//             len[id] = r-l + 1;
//         }
//         if(ql <= l && r <= qr){
//             settag(id, v);
//             return;
//         }
//         int mid = l + r >> 1;
//         if(!ls[id]) ls[id] = ++tot, len[ls[id]] = mid - l + 1;
//         if(!rs[id]) rs[id] = ++tot, len[rs[id]] = r - (mid+1) + 1;
//         if(tag[id]) down(id);
//         if(qr <= mid) modify(ls[id], l, mid, ql, qr, v);
//         else if(ql > mid) modify(rs[id], mid + 1, r, ql, qr, v);
//         else modify(ls[id], l, mid, ql, qr, v), modify(rs[id], mid + 1, r, ql, qr, v);
//         up(id);
//     }
// }tr;

// int dep[N], dfn[N], son[N], siz[N], tot, top[N], par[N];
// void line_modify(int u, int v, int c, int x){
//     // cerr << u << ' ' << v << endl;
//     while(top[u] != top[v]){
//     // cerr << u << ' ' << v << endl;
//         if(dep[top[u]] < dep[top[v]]) swap(u, v);
//         tr.modify(tr.rt[c], 1, n, dfn[top[u]], dfn[u], x);
//         u = par[top[u]];
//     }
//     if(dep[u] < dep[v]) swap(u, v);
//     tr.modify(tr.rt[c], 1, n, dfn[v], dfn[u], x);
//     // cerr << u << ' ' << v << endl;
// }

// void dfs1(int u, int fa){
//     par[u] = fa;
//     dep[u] = dep[fa] + 1;
//     siz[u] = 1;
//     for(auto v : g[u]){
//         dfs1(v, u);
//         siz[u] += siz[v];
//         if(siz[v] > siz[son[u]]) son[u] = v;
//     }
// }
// void dfs2(int u, int tp){
//     top[u] = tp;
//     dfn[u] = ++tot;
//     line_modify(u, 1, c[u], 1);
//     if(son[u]) dfs2(son[u], tp);
//     else return;

//     for(auto v : g[u]) if(v != son[u]){
//         dfs2(v, v);
//     }
// }

// void solve(){
//     cin >> n >> m >> q >> C;
//     for(int i = 1;i <= n;i++) cin >> c[i];
//     for(int i = 2, p;i <= n;i++){
//         cin >> p;
//         g[p].push_back(i);
//     }
//     for(int i = 1;i <= m;i++){
//         cin >> f[i];
//     }

//     dfs1(1, 0);
//     dfs2(1, 1);

//     while(q--){
//         int op, x, y;
//         cin >> op;
//         if(op == 1){
//             cin >> x >> y;
//             line_modify(x, 1, c[x], -1);
//             c[x] = y;
//             line_modify(x, 1, c[x], 1);
//         }else{
//             cin >> x;
//             int s2 = tr.s2[tr.rt[x]], s = tr.s[tr.rt[x]];
//             // cerr << s2 << ' ' << s << endl;
//             double ans = (1.0*f[x]*f[x]) * s2 - (2.0*C*f[x]*s) + (1.0*n*C*C);
//             ans /= n;
//             printf("%.12lf\n", ans);
//         }
//     }
// } 

// signed main(){

// 	IO;
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int ROB = 0;
// const int ANT = 1;
// const int N = 5e4 + 10;
// const int M = N * 50;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5), b(n+5), vis(2*n+5);
//     vector<array<int, 3>>evt;
//     for(int i = 1;i <= n;i++) cin >> a[i], evt.push_back({a[i], ROB, i});
//     for(int i = 1;i <= n;i++) cin >> b[i], evt.push_back({b[i], ANT, i});
//     evt.push_back({(int)3e9, ROB, 0});

//     sort(all(evt));
    
//     int len = 0;
//     vector<int>ans;

//     int neb = 0;
//     stack<int>rob, wit;
//     for(int i = 0;i < 2*n;i++) if(!vis[i]){
//         auto [x, k, id] = evt[i];
//         while(neb <= i || evt[neb][1] != ROB) neb++;
//         if(k == ROB){
//             rob.push(x);
//         }else{
//             if(rob.empty()){
//                 ans.push_back(id);
//                 len += evt[neb][0] - x;
//                 vis[neb] = 1;
//                 neb++;
//             }else{
//                 if(evt[neb][0] - x < x - rob.top()){
//                     wit.push(id);
//                 }else{
//                     ans.push_back(id);
//                 }
//                 len += x - rob.top();
//                 rob.pop();
//             }
//         }
//     }

//     while(wit.size()){
//         ans.push_back(wit.top());
//         wit.pop();
//     }

//     cout << len << endl;
//     for(auto e : ans) cout << e << ' ';
//     cout << endl;


// } 

// signed main(){

// 	IO;
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int ROB = 0;
// const int ANT = 1;
// const int N = 5e4 + 10;
// const int M = N * 50;


// void solve(){
//     cout << "-1000000000 0\n";
//     cout << "-1 1000000000\n";
//     cout << "0 -1000000000\n";
//     cout << "1000000000 1\n";

// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int unsigned long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
// int k1, k2, fa[N];

// int find(int x){
//     return fa[x] == x ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// int rd(){
//     int k3 = k1, k4 = k2;
//     k1 = k4;
//     k3 ^= k3 << 23;
//     k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
//     return k2 + k4;
// }

// void solve(){
//     int n, m;
//     cin >> n >> m >> k1 >> k2;
//     vector<array<int, 3>>g;
//     for(int i = 1;i <= n;i++) fa[i] = i;
//     for(int i = 1, u, v, w;i <= m;i++){
//         u = rd() % n + 1;
//         v = rd() % n + 1;   
//         w = rd();
//         g.push_back({w, u, v});
//     }

//     sort(all(g));    

//     int sum = 0, cnt = 0;
//     for(auto [w, u, v] : g) if(find(u) != find(v)){
//         sum = (sum + w) % mod;
//         merg(u, v);
//     }

//     for(int i = 1;i <= n;i++) {
//         cnt += (find(i) == i);
//     }
//     if(cnt != 1) {
//         cout << "0\n";
//         return;
//     }

//     cout << sum << endl;

// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;


// void solve(){
//     int n, sum = 0;
//     cin >> n;
//     vector<int>a(n+5), b(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i], sum += abs(a[i] - b[i]);
//     a[n+1] = 3e9;

//     vector<int>ans;
//     stack<int>as, bs;
//     int ap = 0, bp = 0;
//     while(ap < n || bp < n){
//         if(ap < n && a[ap+1] < b[bp+1]){
//             ap++;
//             as.push(ap);
//         }else{
//             bp++;
//             if(as.size() == bs.size()){
//                 ans.push_back(bp);
//                 ap++;
//             }else{
//                 bs.push(bp);
//             }
//             while(as.size() && as.size() == bs.size() && b[bs.top()] - a[as.top()] <= a[ap+1] - b[bs.top()]){
//                 ans.push_back(bs.top());
//                 bs.pop();
//                 as.pop();
//             }
//         }
//     }

//     while(bs.size()) {
//         ans.push_back(bs.top());
//         bs.pop();
//     }

//     cout << sum << endl;
//     for(auto e : ans) cout << e << ' ';
//     cout << endl;

// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int N = 3e5 + 10;
// const int mod = 1e9 + 7;
// int c[N], lcn[N], par[N][20], n, m, k, ans;
// vector<int>g[N];

// int qpow(int a, int b){
//     int ret = 1;
//     while(b){
//         if(b & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return ret;
// }

// int fac[N], inv[N];
// void get_inv(){
//     fac[0] = inv[0] = 1;
//     for(int i = 1;i < N;i++){
//         fac[i] = fac[i-1] * i % mod;
//     }
//     inv[N-1] = qpow(fac[N-1], mod-2);
//     for(int i = N - 2;i >= 1;i--){
//         inv[i] = inv[i+1] * (i+1) % mod;
//     }
// }
// int C(int a, int b){
//     if(b > a) return 0;
//     return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
// }

// int dep[N];
// void dfs(int u, int f){
//     dep[u] = dep[f] + 1;
//     par[u][0] = f;
//     for(int i = 1;i < 20;i++) par[u][i] = par[par[u][i-1]][i-1];
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//     }
// }
// int lca(int u, int v){
//     if(dep[u] < dep[v]) swap(u, v);
//     for(int i = 19;i >= 0;i--){
//         if(dep[par[u][i]] >= dep[v]) u = par[u][i];
//     }
//     if(u == v) return u;
//     for(int i = 19;i >= 0;i--){
//         if(par[u][i] != par[v][i]) {
//             u = par[u][i];
//             v = par[v][i];
//         }
//     }
//     return par[u][0];
// }

// int add(int a, int b){
//     return (a + b) % mod;
// }
// int dv(int a, int b){
//     return (a - b + mod) % mod;
// }
// int mul(int a, int b){
//     return a * b % mod;
// }

// void dfs2(int u, int f){
//     for(auto v : g[u]) if(v != f){
//         dfs2(v, u);
//         c[u] += c[v];
//     }
//     ans = add(ans, dv(C(c[u], k), C(c[u] - lcn[u], k)));
// }

// void solve(){
//     ans = 0;
//     cin >> n >> m >> k;
//     for(int i = 1;i <= n;i++){
//         c[i] = lcn[i] = 0;
//         g[i].clear();
//     }
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);

//     for(int i = 1, u, v, ca;i <= m;i++){
//         cin >> u >> v;
//         c[u]++, c[v]++;
//         ca = lca(u, v);
//         lcn[ca]++;
//         c[ca]--;
//         c[par[ca][0]]--;
//     }

//     dfs2(1, 0);

//     // for(int i = 1;i <= n;i++){
//     //     cerr << "lcn " << i << " = " << lcn[i] << endl;
//     //     cerr << " c  " << i << " = " << c[i] << endl;
//     // }

//     cout << ans << endl;
// } 

// signed main(){

// 	IO;
//     get_inv();
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int N = 3e5 + 10;
// const int mod = 1e9 + 7;


// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<int>>g(n+5);
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     double ans = 0;
//     auto dfs = [&](auto self, int u, int f, int fd) -> void {
//         ans += 1.0 / fd;    
//         for(auto v : g[u]) if(v != f){
//             self(self, v, u, fd + 1);
//         }
//     };

//     dfs(dfs, 1, 0, 1);
//     printf("%.12lf\n", ans);

// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int N = 4e5 + 10;
// const int mod = 1e9 + 7;
// int n, m;
// vector<array<int, 2>>g[N];
// array<int, 2>ans[N];

// int dfn[N], low[N], scc[N], idx, tot, st[N], top;
// int siz[N];
// vector<array<int, 4>>sccg[N]; //to, id, u, v;
// void dfs(int u, int id){
//     dfn[u] = low[u] = ++tot;
//     st[++top] = u;
//     for(auto [v, id2] : g[u]) {
//         if(!dfn[v]) dfs(v, id2);
//         if(id2 != id) low[u] = min(low[u], low[v]);
//     }
//     if(dfn[u] == low[u]){
//         idx++;
//         while(st[top] != u){
//             scc[st[top--]] = idx;
//             siz[idx]++;
//         }
//         scc[st[top--]] = idx;
//         siz[idx]++;
//     }
// }

// int vis[N];
// void dfs2(int u, int id){
//     vis[u] = 1;
//     for(auto [v, id2] : g[u]) if(id != id2){
//         if(scc[u] == scc[v]){
//             if(ans[id2][0] == 0) ans[id2] = {u, v};
//             if(!vis[v]) dfs2(v, id2);
//         }else{
//             sccg[scc[u]].push_back({scc[v], id2, u, v});
//         }
//     }
// }

// void dfs3(int u, int f){
//     for(auto [v, id, a, b] : sccg[u]) if(v != f){
//         ans[id] = {b, a};
//         dfs3(v, u);
//     }
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         g[u].push_back({v, i});
//         g[v].push_back({u, i});
//     }

//     dfs(1, 0);

//     for(int i = 1;i <= n;i++) if(!vis[i]){
//         dfs2(i, 0);
//     }

//     int mx = 1;
//     for(int i = 1;i <= idx;i++){
//         if(siz[i] > siz[mx]) mx = i;
//     }

//     dfs3(mx, 0);

//     cout << siz[mx] << endl;
//     for(int i = 1;i <= m;i++){
//         cout << ans[i][0] << ' ' << ans[i][1] << endl;
//     }
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int RED = 0;
// const int BULE = 1;
// const int N = 1e6 + 2e5 + 20;

// struct node{
//     int x, y, w, ty;
// };

// class BIT{
// public:
//     int tr[N];
//     int lowbit(int x){
//         return x & -x;
//     }
//     void init(){
//         for(int i = 0;i < N;i++) tr[i] = -1;
//     }

//     void add(int x, int v){
//         while(x < N){
//             tr[x] = max(tr[x], v);
//             x += lowbit(x);
//         }
//     }
//     int get_mx(int x){
//         int ret = -1;
//         while(x > 0){
//             ret = max(ret, tr[x]);
//             x -= lowbit(x);
//         }
//         return ret;
//     }
// }tr;


// void solve(){
//     int n, q, m;
//     cin >> n;
//     vector<node>a(2*n + 5);
//     vector<int>idx;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i].x >> a[i].y >> a[i].w;
//         a[i].ty = RED;
//         idx.push_back(a[i].x);
//     }
//     for(int i = n+1;i <= 2*n;i++){
//         cin >> a[i].x >> a[i].y >> a[i].w;
//         a[i].ty = BULE;
//         idx.push_back(a[i].x);
//     }
//     sort(a.begin() + 1, a.begin() + 1 + 2*n, [&](const node& e1, const node& e2) -> int {
//         return e1.y < e2.y;
//     });

//     cin >> q;
//     vector<array<int, 3>>qur(q+5);
//     vector<int>ans(q+5, -1);
//     for(int i = 1;i <= q;i++){
//         cin >> qur[i][0] >> qur[i][1];
//         idx.push_back(qur[i][0]), idx.push_back(qur[i][1]);
//         qur[i][2] = i;
//     }

//     sort(all(idx));
//     idx.erase(unique(all(idx)), idx.end());
//     m = idx.size() + 1;
//     for(int i = 1;i <= 2*n;i++){
//         a[i].x = lower_bound(all(idx), a[i].x) - idx.begin() + 1;
//         // cerr << a[i].x << ' ' << a[i].y << ' ' << a[i].w << " " << (a[i].ty==RED?"RED":"BULE") << endl;
//     }
//     for(int i = 1;i <= q;i++){
//         qur[i][0] = lower_bound(all(idx), qur[i][0]) - idx.begin() + 1;
//         qur[i][1] = lower_bound(all(idx), qur[i][1]) - idx.begin() + 1;
//         // cerr << qur[i][0] << ' ' << qur[i][1] << endl;
//     }
    
//     vector<array<int, 4>>evt; // rx, bx, w, ty/id  y轴下往上扫
//     for(int i = 1;i <= q;i++) evt.push_back({qur[i][0], qur[i][1], 0, qur[i][2]});

//     auto dfs = [&](auto self, int l, int r) -> void {
//         if(l == r) return;
//         int mxr = 0, mxb = 0, mid = l + r >> 1;
//         for(int i = l;i <= mid;i++) if(a[i].ty == RED) if(!mxr || a[i].w > a[mxr].w) mxr = i;
//         for(int i = mid + 1;i <= r;i++) if(a[i].ty == BULE) if(!mxb || a[i].w > a[mxb].w) mxb = i;
//         if(mxr && mxb){
//             for(int i = l;i <= mid;i++) if(a[i].ty == RED) evt.push_back({a[i].x, a[mxb].x, a[i].w + a[mxb].w, 0});
//             for(int i = mid + 1;i <= r;i++) if(a[i].ty == BULE) evt.push_back({a[mxr].x, a[i].x, a[i].w + a[mxr].w, 0});
//         }
//         self(self, l, mid), self(self, mid + 1, r);
//     };

//     dfs(dfs, 1, n*2);

//     sort(all(evt), [&](const array<int, 4> &a1, const array<int, 4> &a2) -> int {
//         if(a1[1] == a2[1]) return a1[3] > a2[3];
//         return a1[1] < a2[1];
//     });
//     tr.init();
//     for(auto [rx, bx, w, id] : evt){ //维护后缀max
//         if(id){
//             ans[id] = max(ans[id], tr.get_mx(m-rx));
//         }else{
//             tr.add(m-rx+1, w);
//         }
//     }

//     sort(all(evt), [&](const array<int, 4> &a1, const array<int, 4> &a2) -> int {
//         if(a1[1] == a2[1]) return a1[3] > a2[3];
//         return a1[1] > a2[1];
//     });
//     tr.init();
//     for(auto [rx, bx, w, id] : evt){ //维护前缀max
//         if(id){
//             ans[id] = max(ans[id], tr.get_mx(rx-1));
//         }else{
//             tr.add(rx, w);
//         }
//     }

//     for(int i = 1;i <= q;i++) cout << ans[i] << endl;

// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int RED = 0;
// const int BULE = 1;
// const int N = 1e6 + 2e5 + 20;


// void solve(){
// 	int n;
// 	cin >> n;
// 	string s;
// 	cin >> s;
// 	int q = 0;
// 	for(auto c : s){
// 		if(c == 'Q') q++;
// 		else{
// 			q--;
// 			q = max(0ll, q);
// 		}
// 	}
// 	if(q) cout << "No\n";
// 	else cout << "Yes\n";
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int RED = 0;
// const int BULE = 1;
// const int N = 1e6 + 2e5 + 20;


// void solve(){
// 	int n;
// 	cin >> n;
// 	int m = n / 2;
// 	for(int i = m + 1, j = 1;i <= n;i++, j++){
// 		cout << i << ' ';
// 		if(j <= m) cout << j << ' ';
// 	}
// 	cout << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int RED = 0;
// const int BULE = 1;
// const int N = 1e6 + 2e5 + 20;


// void solve(){
// 	int n;
// 	cin >> n;
// 	vector<int>a(n+5);
// 	for(int i = 1;i <= n;i++){
// 		cin >> a[i];
// 	}
// 	if(n&1) {
// 		cout << "-1\n";
// 		return;
// 	}
// 	vector<array<int,2>>ans;
// 	for(int i = 1;i < n;i+=2){
// 		if(a[i] == a[i+1]){
// 			ans.push_back({i, i+1});
// 		}else{
// 			ans.push_back({i, i});
// 			ans.push_back({i+1, i+1});
// 		}
// 	}	
// 	cout << ans.size() << endl;
// 	for(auto [l, r] : ans) cout << l << ' ' << r << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int RED = 0;
// const int BULE = 1;
// const int N = 1e6 + 2e5 + 20;


// void solve(){
// 	int n, fs = 0, ls = 0;
// 	cin >> n;
// 	vector<int>b(n+5);
// 	for(int i = 1;i <= n;i++){
// 		cin >> b[i];
// 		if(!fs && b[i]) fs = i;
// 		if(b[i]) ls = i;
// 	}
// 	vector<array<int, 2>>a, ans;
// 	for(int i = 1;i <= n;i++){
// 		if(b[i]) a.push_back({b[i], i});
// 	}

// 	if(a.size() & 1) {
// 		cout << "-1\n";
// 		return;
// 	}

// 	if(!fs){
// 		cout << "1\n" << 1 << ' ' << n << endl;
// 		return;
// 	}

// 	if(fs > 1) ans.push_back({1, fs-1});

// 	for(int i = 0;i < a.size();i+=2){
// 		if(i-1 >= 0 && a[i][1]-1 >= a[i-1][1]+1) ans.push_back({a[i-1][1]+1, a[i][1]-1});
// 		if(a[i][0] == a[i+1][0]){
// 			if(a[i][1] + 1 == a[i+1][1]){
// 				ans.push_back({a[i][1], a[i+1][1]});
// 			}else{
// 				ans.push_back({a[i][1], a[i][1]});
// 				if(a[i][1]+1 <= a[i+1][1]-2) ans.push_back({a[i][1]+1, a[i+1][1]-2});
// 				ans.push_back({a[i+1][1]-1, a[i+1][1]});
// 			}
// 		}else{
// 			ans.push_back({a[i][1], a[i][1]});
// 			if(a[i][1]+1 <= a[i+1][1]-1) ans.push_back({a[i][1]+1, a[i+1][1]-1});
// 			ans.push_back({a[i+1][1], a[i+1][1]});
// 		}
// 	}
	
// 	if(ls < n) ans.push_back({ls+1, n});

// 	cout << ans.size() << endl;
// 	for(auto [l, r] : ans) cout << l << ' ' << r << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int RED = 0;
// const int BULE = 1;
// const int N = 1e6 + 2e5 + 20;


// void solve(){
// 	int n, x;
// 	cin >> n >> x;
// 	vector<int>a(n+5), cnt(x+5);
// 	for(int i = 1;i <= n;i++){
// 		cin >> a[i];
// 		cnt[a[i]]++;
// 	}

// 	for(int i = 1;i < x;i++){
// 		if(cnt[i] % (i+1)){
// 			cout << "No\n";
// 			return;
// 		}
// 		cnt[i+1] += cnt[i] / (i+1);
// 	}

// 	cout << "Yes\n";
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int mod = 998244353;

// int qpow(int a, int b){
// 	int ret = 1;
// 	while(b){
// 		if(b & 1) ret = ret * a % mod;
// 		a = a * a % mod;
// 		b >>= 1;
// 	}
// 	return ret;
// }

// int fac[N], inv[N];
// void get_inv(){
// 	fac[0] = inv[0] = 1;
// 	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
// 	inv[N-1] = qpow(fac[N-1], mod-2);
// 	for(int i = N - 2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
// }

// int C(int a, int b){
// 	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
// }

// void solve(){
// 	int n, on = 0, ze = 0;
// 	cin >> n;
// 	vector<int>a(n+5), f(n+5);
// 	for(int i = 1;i <= n;i++) cin >> a[i], on += a[i];
// 	for(int i = n - on + 1;i <= n;i++) ze += (a[i] == 0);
	
// 	f[0] = 0;
// 	for(int i = 1;i <= ze;i++){
// 		f[i] = (f[i-1] + (C(n, 2) * qpow(i*i%mod, mod-2) % mod)) % mod;
// 	}

// 	cout << f[ze] << endl;
// } 

// signed main(){

// 	IO;
// 	get_inv();
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// const int R = 0;
// const int L = 1;
// const int D = 2;
// const int U = 3;
// int to[300];
// int op[4][2] = {0, 1, 0, -1, 1, 0, -1, 0}; //R L D U

// void solve(){
// 	int n, m, p, q;
// 	cin >> n >> m >> p >> q;
// 	vector<string>mp(n+5);
// 	mp[0] = mp[n+1] = string(m+5, '#');
// 	for(int i = 1;i <= n;i++){
// 		cin >> mp[i];
// 		mp[i] = '#' + mp[i] + '#';
// 	}

// 	vector< vector<vector<array<int, 3> >> > g(n+5, vector<vector< array<int, 3> >>(m+5));
// 	vector<vector<int>>dis(n+5, vector<int>(m+5, inf));

// 	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>que;

// 	for(int i = 1;i <= n;i++){
// 		for(int j = 1;j <= m;j++) if(mp[i][j] != '#'){
// 			if(mp[i][j] == '.'){
// 				dis[i][j] = 0;
// 				que.push({0, i, j});
// 			}
// 			int nx, ny;
// 			for(int k = 0;k < 4;k++){
// 				nx = i + op[k][0];
// 				ny = j + op[k][1];
// 				if(mp[nx][ny] >= 'A' && mp[nx][ny] <= 'Z'){
// 					int id = to[mp[nx][ny]];
// 					nx += op[id][0];
// 					ny += op[id][1];
// 					if(nx == i || ny == j){
// 						g[i][j].push_back({nx, ny, q});
// 					}else{
// 						g[i][j].push_back({nx, ny, p});
// 					}
// 				}
// 			}
// 		}
// 	}

// 	// for(int i = 1;i <= n;i++){
// 	// 	for(int j = 1;j <= m;j++) if(g[i][j].size()){
// 	// 		cerr << i << ' ' << j << " : \n";
// 	// 		for(auto [x, y, w] : g[i][j]) cerr << x << ' ' << y << ' ' << w << endl;
// 	// 	}
// 	// }

// 	while(que.size()){
// 		auto [c, x, y] = que.top();
// 		que.pop();
// 		if(c > dis[x][y]) continue;
// 		for(auto [nx, ny, w] : g[x][y]) if(dis[nx][ny] > c + w){
// 			dis[nx][ny] = c + w;
// 			que.push({dis[nx][ny], nx, ny});
// 		}
// 	}

// 	int ans = inf;
// 	for(int i = 1;i <= n;i++){
// 		for(int j = 1;j <= m;j++){
// 			if(i < n) ans = min(ans, dis[i][j] + dis[i+1][j]);
// 			if(j < m) ans = min(ans, dis[i][j] + dis[i][j+1]);
// 		}
// 	}

// 	if(ans < inf) cout << ans << endl;
// 	else cout << "-1\n";
// } 

// signed main(){

// 	IO;
// 	to['U'] = D;
// 	to['D'] = U;
// 	to['L'] = R;
// 	to['R'] = L;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
// 	int x[3], y[3];
// 	for(int i = 0;i < 3;i++) cin >> x[i] >> y[i];
// 	if((x[0] == x[1] || x[0] == x[2] || x[1] == x[2]) && (y[1] == y[2] || y[0] == y[1] || y[0] == y[2])) cout << "NO\n";
// 	else cout << "YES\n";
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
// 	int n, a1;
// 	cin >> n;
// 	vector<int>a(n+5);
// 	for(int i = 1;i <= n;i++) cin >> a[i];
// 	a1 = a[1];
// 	sort(all1(a));
// 	int i = 1;
// 	for(i;i <= n;i++){
// 		if(a[i] == a1) break;
// 	}
// 	for(++i;i <= n;i++) if(a[i] > a1){
// 		a1 += (a[i] - a1 + 1) / 2;
// 	}

// 	cout << a1 << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
// 	int n, tot;
// 	cin >> n;
// 	vector<int>a(n+5);
// 	vector<array<int, 2>>seg;
// 	queue<array<int, 2>>que;
// 	for(int i = 1;i <= n;i++){
// 		for(int j = i, op;j <= n;j++){
// 			cin >> op;
// 			if(op == 1) seg.push_back({i, j});
// 			else if(op) que.push({i, j});
// 		}
// 	}

// 	sort(all(seg));
// 	vector<array<int, 2>>on;
// 	array<int, 2>cur({0, 0});
// 	for(auto [l, r] : seg){
// 		if(cur[0] == 0) cur = {l, r};
// 		if(cur[1] >= l) cur[1] = r;
// 		else {
// 			on.push_back(cur);
// 			cur = array<int, 2>({0, 0});
// 		}
// 	}
// 	if(cur[0]) on.push_back(cur);

// 	int sum = n;
// 	for(auto [l, r] : on){
// 		cerr << l << " " << r << endl;
// 		sum -= (r - l);
// 		++tot;
// 		for(int i = l;i <= r;i++){
// 			a[i] = tot;
// 		}
// 	}


// 	while(que.size()){
// 		vector<int>p(n+5);
// 		for(int i = 1, len = que.size();i <= len;i++){
// 			auto [l, r] = que.front();
// 			que.pop();
// 			p[l]++, p[r+1]--;
// 			que.push({l, r});
// 		}
// 		int mx = 0;
// 		for(int i = 1;i <= n;i++){
// 			p[i] += p[i-1];
// 			if(p[i] > p[mx] && !a[i]) mx = i;
// 		}
// 		if(mx){
// 			a[mx] = 1;
// 			sum--;
// 		}else{
// 			cout << "0\n";
// 			return;
// 		}
// 		for(int i = 1, len = que.size();i <= len;i++){
// 			auto [l, r] = que.front();
// 			que.pop();
// 			if(mx < l || mx > r) que.push({l, r});
// 		}
// 	}

// 	int ans = 1;
// 	for(int i = 1;i <= sum;i++) ans = ans * 2 % mod;
// 	cout << ans << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
// 	int n;
// 	cin >> n;
// 	vector<vector<int>>a(n+5, vector<int>(n+5));
// 	vector<vector<int>>f(n+5, vector<int>(n+5));
// 	for(int i = 1;i <= n;i++){
// 		for(int j = i;j <= n;j++){
// 			cin >> a[i][j];
// 		}
// 	}

// 	for(int i = 1;i <= n;i++) {
// 		if(a[i][i] == 2){
// 			cout << "0\n";
// 			return;
// 		}
// 	}

// 	f[1][1] = 2;
// 	for(int i = 2;i <= n;i++){
// 		for(int j = 1;j <= i;j++){
// 			int cnt[3] = {0};
// 			for(int k = 1;k < j;k++) cnt[1] += a[k][i] == 1;
// 			for(int k = j;k <= i;k++) cnt[2] += a[k][i] == 2;
// 			if(!cnt[1] && !cnt[2]) {
// 				if(i == j){
// 					for(int k = 1;k <= i-1;k++) f[i][j] = (f[i][j] + f[i-1][k]) % mod;
// 				}else{
// 					f[i][j] = (f[i][j] + f[i-1][j]) % mod;
// 				}
// 			}
// 		}
// 	}

// 	int ans = 0;
// 	for(int j = 1;j <= n;j++){
// 		int cnt[3] = {0};
// 		for(int k = 1;k < j;k++) cnt[1] += a[k][n] == 1;
// 		for(int k = j;k <= n;k++) cnt[2] += a[k][n] == 2;
// 		if(!cnt[1] && !cnt[2]) ans = (ans + f[n][j]) % mod;
// 	}

// 	cout << ans << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5), b(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];

//     int as = 0, bs = 0;
//     for(int i = 1;i <= n;i++){
//         as += a[i];
//         bs += b[i];
//     }

//     if(as == bs){
//         for(int i = 1;i <= n;i++){
//             if(a[i] != b[i]){
//                 cout << "1\n";
//                 return;
//             }
//         }
//         cout << "0\n";
//     }else if(as > bs){
//         int f = 0;
//         for(int i = 1;i <= n;i++){
//             if(!a[i] && b[i]){
//                 f = 1;
//                 break;
//             }
//         }
//         cout << f + (as - bs) << endl;
//     }else{
//         int f = 0;
//         for(int i = 1;i <= n;i++){
//             if(a[i] && !b[i]){
//                 f = 1;
//                 break;
//             }
//         }
//         cout << f + abs(as - bs) << endl;
//     }
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5), b(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 2;i <= n;i++){
//         b[i] = a[i-1] * a[i] / gcd(a[i], a[i-1]);
//     }
//     b[1] = a[1];
//     b[n+1] = a[n];
//     for(int i = 1;i <= n;i++){
//         if(a[i] != gcd(b[i], b[i+1])){
//             cout << "NO\n";
//             return;
//         }
//     }
//     cout << "YES\n";
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5), d(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i], d[i] = a[i] - i;
//     d[n+1] = -1e9;
//     int p = 1, ans = 0;
//     for(int i = 1;i <= n;i++){
//         if(d[i] < (1-i)) {
//             p = i+1;
//             continue;
//         }
//         while(d[p+1] >= (1-i)) p++;
//         ans += p-i+1;
//     }
//     cout << ans << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int a[N], d[N], s[N], R[N];

// int bit[N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x, int v){
//     while(x < N){
//         bit[x] += v;
//         x += lowbit(x);
//     }
// }
// int getsum(int x){
//     int ret = 0;
//     while(x > 0){
//         ret += bit[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// struct node{
//     int mx, sum;
// }tr[N<<2];

// void up(int id){
//     tr[id].mx = max(tr[ls].mx, tr[rs].mx);
//     tr[id].sum = tr[ls].sum + tr[rs].sum;
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id] = {R[l], s[l]};
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// int getmx(int id, int l, int r, int x){
//     if(l == r) return l;
//     int mid = l + r >> 1;
//     if(tr[ls].mx >= x) return getmx(ls, l, mid, x);
//     else return getmx(rs, mid + 1, r, x);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].sum;
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
// }

// void solve(){
//     int n;
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i], d[i] = a[i] - i;
//     d[n+1] = -1e9;
//     int p = 1, ans = 0, pp = 1;
//     for(int i = 1;i <= n;i++){
//         while(p < i || d[p+1] >= (1-i)) p++;
//         if(pp <= p) pp = p + 1;
//         while(d[pp+1] >= (1-i)) pp++;
//         s[i] = p-i+1;
//         R[i] = p;
//         add(i, pp-i+1);
//         ans += s[i];
//     }

//     build(1, 1, n);

//     // for(int i = 1;i <= n;i++) cerr << R[i] << ' ';
//     // cerr << endl;

//     int q;
//     cin >> q;
//     while(q--){
//         int p, x;
//         cin >> p >> x;
//         // cerr << p << ' ' << x << endl;
//         int ret = ans;
//         if(x < a[p]){
//             int f = getmx(1, 1, n, p);
//             if(f < (p-x+1)){
//                 ret -= query(1, 1, n, f, p-x);
//                 int cnt = (p-x)-f+1;
//                 ret += (cnt*(2*x+cnt-1))/2;
//             }
//         }else if(x > a[p]){
//             int l = lower_bound(R+1, R+1+n, p-1) - R;
//             int r = upper_bound(R+1, R+1+n, p-1) - R - 1;
//             // cerr << l << ' ' << r << endl;
//             l = max(l, p-x+1);
//             if(l <= r){
//                 ret -= query(1, 1, n, l, r);
//                 ret += getsum(r) - getsum(l-1);
//             }
//         }
//         cout << ret << endl;
//     }

// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// void solve(){
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
//     s = ' ' + s;

//     int cnt = 0;
//     for(int i = 1;i <= n*2;i++) cnt += s[i] == '1';

//     if(cnt & 1){
//         cout << "-1\n";
//         return;
//     }

//     vector<int>mv;
//     int ls = 0;
//     for(int i = 1;i <= n*2;i+=2){
//         if(s[i] == s[i+1]) continue;
//         if(s[i] != ls+'0'){
//             mv.push_back(i);
//             ls = s[i] - '0';
//         }else{
//             mv.push_back(i+1);
//             ls = s[i+1] - '0';
//         }
//     }

//     cout << mv.size() << ' ';
//     for(auto e : mv) cout << e << ' ';
//     cout << endl;
//     for(int i = 1;i <= 2*n;i+=2) cout << i << ' ';
//     cout << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// void solve(){
//     int a, b;
//     cin >> a >> b;
//     if(a % 2 == 0 && b % 2 == 0) cout << "Yes\n";
//     else if(a % 2 == 0){
//         if(a/2 != b) cout << "Yes\n";
//         else cout << "No\n";
//     }else if(b % 2 == 0){
//         if(b/2 != a) cout << "Yes\n";
//         else cout << "No\n";
//     }else{
//         cout << "No\n";
//     }
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// void solve(){
//     int n, mn = inf;
//     cin >> n;
//     vector<int>a(n);
//     for(int i = 0;i < n;i++) cin >> a[i], mn = min(mn, a[i]);
//     sort(all(a));
//     a.erase(unique(all(a)), a.end());
//     for(auto &e : a) e -= mn;

//     int ans = 0;

//     int l = 0, r = 0;
//     while(l < a.size()){
//         while(r+1 < a.size() && a[r+1] < n+a[l]) r++;
//         ans = max(ans, r - l + 1);
//         l++;
//     }
//     cout << ans << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// void solve(){
//     int n, x, d, ans = 0;
//     cin >> n >> x;

//     if(x == 1){
//         n--;
//         for(int i = 1;i * i <= n;i++) if(n % i == 0){
//             if(i % 2 == 0) ans++;
//             if(n/i != i && (n/i) % 2 == 0) ans++;
//         }
//         cout << ans << endl;
//         return;
//     }

//     d = x - 2;
//     n += d;

//     for(int i = 1;i * i <= n;i++) if(n % i == 0){
//         if(i % 2 == 0 && (i+2)/2 >= x){
//             ans++;
//             // cerr << (i+2)/2 << endl;
//         }
//         if(n/i != i) {
//             if(n/i % 2 == 0 && (n/i+2)/2 >= x) {
//                 ans++;
//                 // cerr << (n/i+2)/2 << endl;
//             }
//         }
//     }

//     int m = n;
//     n -= d, n -= x;
//     for(int i = 1;i * i <= n;i++) if(n % i == 0) {
//         if(i % 2 == 0 && (i+2)/2 >= x && m % i != 0){
//             ans++;
//             // cerr << (i+2)/2 << endl;
//         }
//         if(n/i != i) {
//             if(n/i % 2 == 0 && (n/i+2)/2 >= x && m % (n/i) != 0) {
//                 ans++;
//                 // cerr << (n/i+2)/2 << endl;
//             }
//         }
//     }

//     cout << ans << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// void solve(){
//     int n, b, x, sum = 0;
//     cin >> n >> b >> x;
//     vector<int>c(n+5);
//     for(int i = 1;i <= n;i++){
//         cin >> c[i];
//         sum += (c[i] * (c[i]-1)) / 2;
//     }


//     auto val = [&](int k) -> int {
//         int ret = (1-k)*x + sum*b;
//         for(int i = 1;i <= n;i++){
//             int a1 = c[i] / k;
//             int a2 = a1 + ((c[i] % k) ? 1 : 0);
//             int c2 = c[i] % k;
//             ret -= ((a2*(a2-1))/2) * c2 * b;
//             ret -= ((a1*(a1-1))/2) * (k-c2) * b;
//         }
//         return ret;
//     };

//     int l = 1, r = N;
//     while(r - l > 2){
//         // cerr << l << " " << r << endl;
//         int mid = l + r >> 1;
//         if(val(mid) < val(mid+1)) l = mid;
//         else r = mid + 1;
//     }

//     // cerr << l << ' ' << r << endl;
//     // for(int i = 1;i <= 20;i++){
//     //     cerr << val(i) << endl;
//     // }

//     int ans = 0;
//     for(int i = l;i <= r;i ++) ans = max(ans, val(i));

//     cout << ans << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int dp[N], vis[N], pre[N];

// void solve(){
//     int n, x, y, s, m, ox;
//     cin >> n >> x >> y >> s;
//     ox = x;
//     m = x % y;
//     s -= n * m;

//     if(s % y || s < 0){
//         cout << "NO\n";
//         return;
//     }

//     s /= y;
//     x /= y;

//     int len = inf, p;
//     for(int i = x, j = 1;x <= s;i++, j++){
//         if(len > j + 1 + dp[s-x]){
//             len = j + 1 + dp[s-x];
//             p = j;
//         }
//         x += i+1;
//     }


//     if(len > n){
//         cout << "NO\n";
//     }else{
//         cout << "YES\n";

//         vector<int>ans;

//         for(int i = 1;i <= p;i++){
//             s -= ox/y;
//             ans.push_back(ox);
//             ox += y;
//         }

//         for(int i = 1;i * (i+1) / 2 <= s;i++){
//             int v = i * (i+1) / 2;
//             while(v <= s && dp[s-v] + 1 + i == dp[s]){
//                 ans.push_back(m);
//                 for(int j = 1;j <= i;j++) ans.push_back(m + j * y);
//                 s -= v;
//             }
//         }
//         while(ans.size() < n) ans.push_back(m);

//         for(auto e : ans) cout << e << ' ';

//         cout << endl;
//     }
// }

// signed main(){

// 	IO;

//     int s = 0;
//     for(int i = 1;s + i < N;i++){
//         s += i;
//         dp[s] = i;
//         vis[s] = 1;
//     }

//     vector<int>num;
//     for(int i = 1;i < N;i++){
//         if(vis[i]){
//             num.push_back(i);
//         }else{
//             dp[i] = dp[num.back()] + dp[i-num.back()] + 1;
//             for(auto e : num) dp[i] = min(dp[i], dp[e] + dp[i-e] + 1);
//         }
//     }

//     dp[0] = -1;

// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// void solve(){
//     int n;
//     cin >> n;
//     n -= 4;
//     int l1 = 1, l2 = (n+2)/3, l3 = n - l2;
//     int ans = min(l2 - l1, l3 - l2);
//     l2 = n/3, l3 = n - l2;
//     ans = max({ans, min(l2 - l1, l3 - l2)});
//     cout << ans << endl;
// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);

//     int mx = 0, mn = inf;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         mx = max(mx, a[i]);
//         mn = min(mn, a[i]);
//     }

//     int tg = mn * 2;

//     int ans = 0;

//     for(int i = 1;i <= n;i++){
//         ans += (a[i] + tg-2) / (tg-1) - 1;
//     }

//     cout << ans << endl;
// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// int fa[300], vis[300];
// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// void solve(){
//     for(int i = 'a';i <= 'z';i++) fa[i] = i, vis[i] = 0;
//     int n;
//     string s, ans;
//     cin >> n >> s;
//     s = ' ' + s;
//     unordered_map<char, char>mp;

//     for(int i = 1;i <= n;i++){
//         if(!mp.count(s[i])){
//             for(int j = 'a';j <= 'z';j++) if(!vis[j]){
//                 if(find(s[i]) != find(j) || mp.size() == 25){
//                     mp[s[i]] = (char)j;
//                     merg(s[i], j);
//                     vis[j] = 1;
//                     break;
//                 }
//             }
//         }
//         ans.push_back(mp[s[i]]);
//     }

//     cout << ans << endl;
// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 1e3 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// int MP[3][3] = {
//     0, 2, 1,
//     2, 1, 0,
//     1, 0, 2
// };

// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<string>s(n+5);
//     unordered_map<string, int>mp;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1, t;j <= k;j++){
//             cin >> t;
//             s[i].push_back(t+'0');
//         }
//         mp[s[i]] = 0;
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = i+1;j <= n;j++){
//             string t;
//             for(int r = 0;r < k;r++){
//                 t.push_back('0'+MP[s[i][r]-'0'][s[j][r]-'0']);
//             }
//             if(mp.count(t)) mp[t]++;
//         }
//     }

//     int ans = 0;

//     for(auto &[S, cnt] : mp) if(cnt >= 2){
//         ans += (cnt-1) * cnt / 2;
//     }

//     cout << ans << endl;
// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 1e3 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }

//     int ans = inf;
//     for(int i = 1;i <= n;i++){
//         for(int j = i + 1;j <= n;j++){
//             for(int k = j + 1;k <= n;k++){
//                 vector<int>tmp({a[i], a[j], a[k]});
//                 sort(all(tmp));
//                 ans = min(ans, tmp[1] - tmp[0] + (tmp[2] - tmp[1]));
//             }
//         }
//     }

//     cout << ans << endl;
// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 1e3 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= i;j++){
//             if(j == 1 || j == i) cout << 1 << ' ';
//             else cout << 0 << ' ';
//         }
//         cout << endl;
//     }
// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 1e3 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>vis(n+5);
//     string s;
//     cin >> s;

//     int ans = 0;
//     s = ' ' + s;
//     for(int i = 1;i <= n;i++) if(s[i] == '0'){
//         for(int j = i;j <= n && s[j] == '0';j += i) if(!vis[j]){
//             ans += i;
//             vis[j] = 1;
//         }
//     }

//     cout << ans << endl;
// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 1e3 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int q = k, p = k, cur = a[k], lq = k, lp = k, lqc = a[k], lpc = a[k], lsq = k, lsp = k;
//     while(1){
//         while(lq - 1 >= 1 && lqc + a[lq-1] >= 0){
//             lq--;
//             lqc += a[lq];
//             if(lqc > cur){
//                 lpc += lqc - cur;
//                 cur = lqc;
//                 q = lq;
//                 break;
//             }
//         }
//         while(lp + 1 <= n && lpc + a[lp+1] >= 0){
//             lp++;
//             lpc += a[lp];
//             if(lpc > cur){
//                 lqc += lpc - cur;
//                 cur = lpc;
//                 p = lpc;
//                 break;
//             }
//         }
//         if(lp == n || lq == 1){
//             cout << "YES\n";
//             return;
//         }
//         if(lp == lsp && lq == lsq){
//             cout << "NO\n";
//             return;
//         }
//         lsq = lq, lsp = lp;
//     }
// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// using uint = unsigned long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 1e3 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
    
//     for(int i = 1, d = 0;i <= n;i++, d++){
//         for(int j = 1;j <= n;j++){
//             int res = (a[i] + (-i+j) * d) % n;
//             res += n;
//             cout << res % n << ' ';
//         }
//         cout << endl;
//     }
// }

// signed main(){

// 	IO;
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 500 + 10;
// const int M = 5e4 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// struct edge{
//     int to, ne;
// }e[M<<1];

// int head[N], tot;
// void add(int u, int v){
//     e[++tot] = {v, head[u]};
//     head[u] = tot;
// }

// int vis[N], match[N];

// int dfs(int u){
//     for(int i = head[u];i;i = e[i].ne) if(!vis[e[i].to]){
//         int v = e[i].to;
//         vis[v] = 1;
//         if(!match[v] || dfs(match[v])){
//             match[v] = u;
//             return 1;
//         }
//     }
//     return 0;
// }

// void solve(){
//     int n, m, k;
//     cin >> n >> m >> k;
//     for(int i = 1, u, v;i <= k;i++){
//         cin >> u >> v;
//         add(u, v);
//     }

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         memset(vis, 0, sizeof(vis));
//         ans += dfs(i);
//     }

//     cout << ans << endl;
// }

// signed main(){

// 	IO;
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 500 + 10;
// const int M = 5e4 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<int>a(n+5), b(k+5);

//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         b[i%k] = max(b[i%k], a[i]);
//     }

//     int ans = 0;
//     for(int i = 0;i < k;i++) ans += b[i];
//     cout << ans << endl;
// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }






// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 500 + 10;
// const int M = 5e4 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, x, y;
//     cin >> n >> x >> y;
//     if((x && y) || (!x && !y)){
//         cout << "-1\n";
//         return;
//     }

//     x = max(x, y);

//     if((n-1) % x){
//         cout << "-1\n";
//         return;
//     }

//     int cur = 2;
//     for(int i = 1, j = 1;i <= n-1;i++, j++){
//         cout << cur << ' ';
//         if(j == x){
//             cur += x;
//             j = 0;
//         }
//     }
//     cout << endl;
// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 500 + 10;
// const int M = 5e4 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5), b(n+5);
//     for(int i = 1;i <= n;i ++) cin >> a[i], b[i] = a[i] & 1;

//     vector<array<int, 2>>ans;
//     int f = 0;
//     for(int i = n;i >= 1;i--){
//         if(f){
//             if(b[i] == b[1]) ans.push_back({i, f});
//         }else{
//             if(b[i] == b[1]) f = i;
//         }
//     }
//     for(int i = 2;i <= n;i++){
//         if(b[i] != b[1]) ans.push_back({1, i});
//     }

//     cout << ans.size() << endl;
//     for(auto [l, r] : ans) cout << l << ' ' << r << endl;

// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 500 + 10;
// const int M = 5e4 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, x, y;
//     cin >> n >> x >> y;
//     string a, b;
//     cin >> a >> b;

//     int cnt = 0;
//     for(int i = 0;i < n;i++) cnt += (a[i] != b[i]);

//     if(cnt & 1) {
//         cout << "-1\n";
//         return;
//     }

//     if(cnt > 2){
//         cout << cnt/2 * y << endl;
//     }else if(cnt == 2){
//         for(int i = 0;i < n;i++){
//             if(a[i] != b[i]){
//                 if(a[i+1] != b[i+1]){
//                     cout << min(x, 2*y) << endl;
//                 }else{
//                     cout << y << endl;
//                 }
//                 break;
//             }
//         }
//     }else{
//         cout << "0\n";
//     }

// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 500 + 10;
// const int M = 5e4 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, x, y;
//     cin >> n >> x >> y;
//     string a, b;
//     cin >> a >> b;

//     int cnt = 0;
//     for(int i = 0;i < n;i++) cnt += (a[i] != b[i]);

//     if(cnt & 1) {
//         cout << "-1\n";
//         return;
//     }

//     if(y <= x){
//         if(cnt > 2){
//             cout << cnt/2 * y << endl;
//         }else if(cnt == 2){
//             for(int i = 0;i < n;i++){
//                 if(a[i] != b[i]){
//                     if(a[i+1] != b[i+1]){
//                         cout << min(x, 2*y) << endl;
//                     }else{
//                         cout << y << endl;
//                     }
//                     break;
//                 }
//             }
//         }else{
//             cout << "0\n";
//         }
//     }else{

//         vector<int>d;
//         d.push_back(0);
//         for(int i = 0;i < n;i++) if(a[i] != b[i]){
//             d.push_back(i+1);
//         }
//         vector<vector<int>>dp(cnt + 5, vector<int>(cnt+5));

//         for(int len = 2;len <= cnt;len += 2){
//             for(int l = 1, r = l + len-1;r <= cnt;l++, r++){
//                 if(len == 2) dp[l][r] = min(y, (d[r]-d[l])*x);
//                 else dp[l][r] = min({dp[l+2][r] + min(y, (d[l+1]-d[l])*x), dp[l][r-2] + min(y, (d[r]-d[r-1])*x), dp[l+1][r-1] + y});
//             }
//         }
    
//         cout << dp[1][cnt] << endl;
//     }   

// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 1000 + 10;
// const int M = 1e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, E, s, t;

// int tot = 1, h[N];  //正边 ^ 1 == 反边， 所以编号从2开始
// struct edge{
//     int v, c, ne;
// }e[M<<1];  //需要建反边，边数开两倍空间
// void add(int u, int v, int c){
//     e[++tot] = {v, c, h[u]};
//     h[u] = tot;
// }

// int dep[N], cur[N];

// bool bfs(){  //先对点分层，减小dfs深度
//     for(int i = 1;i <= n+m+2;i++) dep[i] = 0;
//     dep[s] = 1;
//     queue<int>q;
//     q.push(s);
//     while(q.size()){
//         int u = q.front();
//         q.pop();
//         for(int i = h[u];i;i = e[i].ne){
//             int v = e[i].v;
//             if(dep[v] == 0 && e[i].c){
//                 dep[v] = dep[u] + 1;
//                 q.push(v);
//                 if(v == t) return true;
//             }
//         }
//     }
//     return false;
// } 

// int dfs(int u, int mf){  //多路增广
//     if(u == t) return mf;
//     int sum = 0;
//     for(int i = cur[u];i;i = e[i].ne){
//         cur[u] = i;  //当前弧优化
//         int v = e[i].v;
//         if(dep[v] == dep[u] + 1 && e[i].c){
//             int f = dfs(v, min(mf, e[i].c));
//             e[i].c -= f;   //更新残留网
//             e[i^1].c += f;
//             sum += f;
//             mf -= f;
//             if(mf == 0) break;
//         }
//     }
//     if(sum == 0) dep[u] = 0;  //残枝优化
//     return sum;
// }

// int Dinic(){  //累加可行流
//     int flow = 0;
//     while(bfs()){
//         for(int i = 1;i <= n+m+2;i++) cur[i] = h[i];
//         flow += dfs(s, inf);
//     }
//     return flow;
// }

// void solve(){
//     cin >> n >> m >> E;
//     s = n + m + 1, t = s + 1;
//     for(int i = 1, u, v;i <= E;i++){
//         cin >> u >> v;
//         v += n;
//         add(u, v, 1);
//         add(v, u, 0);  //建正边后立刻建上反边
//     }
//     for(int i = 1;i <= n;i++){
//         add(s, i, 1);
//         add(i, s, 0);
//     }
//     for(int i = 1 + n;i <= n + m;i++){
//         add(i, t, 1);
//         add(t, i, 0);
//     }

//     cout << Dinic() << endl;
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	// cin >> T;
// 	while(T--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 1000 + 10;
// const int M = 1e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, E, s, t;

// int tot = 1, h[N];  //正边 ^ 1 == 反边， 所以编号从2开始
// struct edge{
//     int v, c, ne;
// }e[M<<1];  //需要建反边，边数开两倍空间
// void add(int u, int v, int c){
//     e[++tot] = {v, c, h[u]};
//     h[u] = tot;
// }

// int mf[N], pre[N];
// bool bfs(){  //增广
//     for(int i = 1;i <= n+m+2;i++) mf[i] = 0;
//     mf[s] = inf;
//     queue<int>q;
//     q.push(s);
//     while(q.size()){
//         int u = q.front();
//         q.pop();
//         for(int i = h[u];i;i = e[i].ne){
//             int v = e[i].v;
//             if(mf[v] == 0 && e[i].c){
//                 mf[v] = min(e[i].c, mf[u]);
//                 pre[v] = i;
//                 q.push(v);
//                 if(v == t) return true;
//             }
//         }
//     }
//     return false;
// }   

// int EK(){  //累加可行流
//     int flow = 0;
//     while(bfs()){
//         int v = t;
//         while(v != s){  //更新残留网
//             int i = pre[v];
//             e[i].c -= mf[t];
//             e[i^1].c += mf[t];
//             v = e[i^1].v;
//         }
//         flow += mf[t];
//     }
//     return flow;
// }


// void solve(){
//     cin >> n >> m >> E;
//     s = n + m + 1, t = s + 1;
//     for(int i = 1, u, v;i <= E;i++){
//         cin >> u >> v;
//         v += n;
//         add(u, v, 1);
//         add(v, u, 0);  //建正边后立刻建上反边
//     }
//     for(int i = 1;i <= n;i++){
//         add(s, i, 1);
//         add(i, s, 0);
//     }
//     for(int i = 1 + n;i <= n + m;i++){
//         add(i, t, 1);
//         add(t, i, 0);
//     }

//     cout << EK() << endl;
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	// cin >> T;
// 	while(T--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 500 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// int n,m;
// int e[N][N];

// int lx[N],ly[N],slack[N];
// int px[N],py[N],pre[N];
// bool vx[N],vy[N];

// queue<int> q;
// void aug(int v)
// {
// 	int t;
// 	while(v)
// 	{
// 		t=px[pre[v]];
// 		px[pre[v]]=v;
// 		py[v]=pre[v];
// 		v=t;
// 	}
// }
// void bfs(int s)
// {
// 	memset(vx,0,sizeof(vx));
// 	memset(vy,0,sizeof(vy));
// 	fill(slack+1,slack+n+1,inf);
	
// 	while(!q.empty())q.pop();
// 	q.push(s);
	
// 	while(1)
// 	{
// 		while(!q.empty())
// 		{
// 			int u=q.front();q.pop();
// 			vx[u]=1;
// 			for(int i=1;i<=n;++i)if(!vy[i])
// 			{
// 				if(lx[u]+ly[i]-e[u][i]<slack[i])
// 				{
// 					slack[i]=lx[u]+ly[i]-e[u][i];
// 					pre[i]=u;
// 					if(slack[i]==0)
// 					{
// 						vy[i]=1;
// 						if(!py[i]){aug(i);return;}
// 						else q.push(py[i]);
// 					}
// 				}
// 			}
// 		}
// 		int d=inf;
// 		for(int i=1;i<=n;++i)if(!vy[i])d=min(d,slack[i]);
// 		for(int i=1;i<=n;++i)
// 		{
// 			if(vx[i])lx[i]-=d;
// 			if(vy[i])ly[i]+=d;else slack[i]-=d;
// 		}
// 		for(int i=1;i<=n;++i)if(!vy[i])
// 		{
// 			if(slack[i]==0)
// 			{
// 				vy[i]=1;
// 				if(!py[i]){aug(i);return;}
// 				else q.push(py[i]);
// 			}
// 		}
// 	}
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= n;j++){
//             e[i][j] = -inf;
//         }
//     }

//     for(int i = 1, u, v, w;i <= m;i++){
//         cin >> u >> v >> w;
//         e[u][v] = w;
//     }

//     for(int i = 1;i <= n;i++){
//         lx[i] = -inf;   
//         for(int j = 1;j <= n;j++){
//             lx[i] = max(lx[i], e[i][j]);
//         }
//     }

//     for(int i = 1;i <= n;i++) bfs(i);


//     int ans = 0;
//     for(int i = 1;i <= n;i++) ans += e[py[i]][i];

//     cout << ans << endl;
//     for(int i = 1;i <= n;i++) cout << py[i] << ' ';
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	// cin >> T;
// 	while(T--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;



// void solve(){
// 	int n, mx = 0, mn = inf;
// 	cin >> n;
// 	for(int i = 1, t;i <= n;i++){
// 		cin >> t;
// 		mx = max(mx, t);
// 		mn = min(mn, t);
// 	}
// 	cout << mx-mn << endl;
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;



// void solve(){
// 	int n, k;
// 	cin >> n >> k;
// 	int d = n - 2 + n;
// 	if(d * 2 >= k){
// 		cout << (k+1) / 2 << endl;
// 	}else{
// 		k -= d * 2;
// 		cout << d + k << endl;
// 	}
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;



// void solve(){
// 	int k, x, a;
// 	cin >> k >> x >> a;
// 	k--;

// 	int cur = a - 1;
// 	for(int i = 1;i <= x;i++){
// 		int d = (a + 1) - cur;
// 		int b = (d + k - 1) / k;
// 		cur -= b;
// 		if(cur < 0){
// 			cout << "NO\n";
// 			return;
// 		}
// 	}
// 	cout << "YES\n";
	
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// int add(int a, int b){
// 	return (a + b) % mod;
// }
// int mut(int a, int b){
// 	return a * b % mod;
// }

// void solve(){
// 	int n;
// 	cin >> n;
// 	vector<vector<int>>g(n+5);
// 	vector<int>dp[3];
// 	dp[1].resize(n+5);
// 	dp[2].resize(n+5);
// 	for(int i = 1, u, v;i < n;i++){
// 		cin >> u >> v;
// 		g[u].push_back(v);
// 		g[v].push_back(u);
// 	}

// 	auto dfs = [&](auto self, int u, int f) -> void {
// 		dp[1][u] = 1;
// 		for(auto v : g[u]) if(v != f){
// 			self(self, v, u);
// 			dp[1][u] = mut(dp[1][u], dp[1][v] + 1);
// 			dp[2][u] = add(dp[2][u], add(dp[2][v], dp[1][v]));
// 		}
// 	};

// 	dfs(dfs, 1, 0);

// 	int ans = add(1ll, add(dp[1][1], dp[2][1]));
// 	cout << ans << endl;
	
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
// 	int n;
// 	cin >> n;
//     cout << n + (n/2) * 2 + (n/3) * 2 << endl;
	
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
// 	int n, k, r, c;
//     cin >> n >> k >> r >> c;

//     vector<vector<int>>mp(n+5, vector<int>(n+5));

//     while(r <= n) r += k;
//     int d = r - n;
//     r -= d;
//     c += d;
//     while(c > n) c -= k;
//     while(c + k <= n) c += k;


//     while(r >= 1 && c >= 1){
//         int x = r, y = c;
//         while(x >= 1 && y <= n){
//             mp[x][y] = 1;
//             x--, y++;
//         }
//         c -= k;
//         if(c < 1){
//             int d = 1 - c;
//             c += d;
//             r -= d;
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= n;j++){
//             cout << (mp[i][j] ? 'X' : '.');
//         }
//         cout << endl;
//     }
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
// 	int n;
//     cin >> n;
//     vector<int>a(n+5), b(n+5);
//     for(int i = 0;i < n;i ++)cin >> a[i];
//     for(int i = 0;i < n;i ++)cin >> b[i];

//     for(int i = 0;i < n;i++){
//         if(b[i] < a[i]){
//             cout << "NO\n";
//             return;
//         }
//     }

//     for(int i = 0;i < n;i++){
//         if(a[i] != b[i] && !(b[(i+1)%n]+1 == b[i] || b[(i+1)%n] >= b[i])){
//             cout << "NO\n";
//             return;
//         }
//     }

//     cout << "YES\n";
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){

// }

// signed main(){

// 	IO;
// 	// int T = 1;
// 	// cin >> T;
// 	// while(T--) solve();

//     int n;
//     cin >> n;
//     map<int,int>mp;

//     for(int i = 0;i < (1ll << n);i+=2){
//         int cnt = 0;
//         for(int j = 0;j < n;j++){
//             cnt += ((i >> j) & 1) == 0;
//         }
//         mp[cnt]++;
//     }

//     for(auto [k, v] : mp){
//         cout << k << ' ' << v << endl;
//     }

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;

// int qpow(int a, int b){
//     int ret = 1;
//     while(b){
//         if(b & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return ret;
// }

// int fac[N], inv[N];
// void init(){
//     fac[0] = inv[0] = 1;
//     for(int i = 1;i < N;i++){
//         fac[i] = fac[i-1] * i % mod;
//     }
//     inv[N-1] = qpow(fac[N-1], mod-2);
//     for(int i = N-2;i >= 1;i--){
//         inv[i] = inv[i+1] * (i+1) % mod;
//     }
// }

// int mul(int a, int b){
//     return a * b % mod;
// }

// int C(int a, int b){
//     return mul(mul(fac[a], inv[a-b]), inv[b]);
// }

// void solve(){
//     int n, k;
//     cin >> n >> k;

//     if(k >= n){
//         cout << qpow(2, n) << endl;
//         return;
//     }

//     int ans = 1;

//     for(int i = 1;i <= k;i++){
//         ans = (ans + C(n, i)) % mod;
//     }

//     cout << ans << endl;
// }

// signed main(){

// 	IO;

//     init();

// 	int T = 1;
// 	// cin >> T;
// 	while(T--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;

// struct node{
//     int d, k;
//     signed operator<(const node& e) const {
//         if(d == e.d) return k < e.k;
//         return d > e.d;
//     }
// };

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>d[2];
//     d[0].resize(n+5);
//     d[1].resize(n+5);

//     for(int i = 1;i <= n;i++)  cin >> d[0][i];
//     for(int i = 1;i <= n;i++)  cin >> d[1][i];

//     sort(all1(d[0]));
//     sort(all1(d[1]));

//     int sm = 1;
//     for(int i = 1;i <= n;i++){
//         if(d[0][i] != d[1][i]){
//             sm = 0;
//             break;
//         }
//     }

//     vector<int>L;
//     for(int i = 1;i <= n;i++){
//         L.push_back(d[0][1] + d[1][i]);
//         L.push_back(abs(d[0][1] - d[1][i]));
//     }

//     multiset<node>st;
//     for(int i = 1;i <= n;i++) st.insert({d[0][i], 0}), st.insert({d[1][i], 1});

//     // L.clear();
//     // L.push_back(36);

//     for(auto len : L){
//         if(len == 0 && sm == 0) continue;
//         // cerr << len << endl;
//         multiset<node>s(st);
//         vector<int>ans;
//         int f = 1;
//         while(s.size() && s.begin()->d > len){
//             auto [d, k] = *s.begin();
//             if(k == 0){
//                 ans.push_back(d);
//                 if(s.find({d-len, 1}) != s.end()){
//                     s.erase(s.find({d-len, 1}));
//                 }else{
//                     f = 0;
//                     break;    
//                 }
//             }else{
//                 ans.push_back(len-d);
//                 if(s.find({d-len, 0}) != s.end()){
//                     s.erase(s.find({d-len, 0}));
//                 }else{
//                     f = 0;
//                     break;
//                 }
//             }
//             s.erase(s.begin());
//         }
//         if(f){
//             while(s.size()){
//                 auto [d, k] = *s.begin();
//                 // cerr << d << ' ' << k << endl;
//                 if(k == 0){
//                     ans.push_back(d);
//                     if(s.find({len-d, 1}) != s.end()){
//                         s.erase(s.find({len-d, 1}));
//                     }else{
//                         f = 0;
//                         break;
//                     }
//                 }else{
//                     ans.push_back(len-d);
//                     if(s.find({len-d, 0}) != s.end()){
//                         s.erase(s.find({len-d, 0}));
//                     }else{
//                         f = 0;
//                         break;
//                     }
//                 }
//                 s.erase(s.begin());
//             }
//         }
//         if(f){
//             cout << "YES\n";
//             int mn = 0;
//             sort(all(ans));
//             for(auto e : ans) mn = min(mn, e);
//             for(auto e : ans) cout << e-mn << ' ';
//             cout << endl << -mn << ' ' << len-mn << endl;
//             // cerr << mn << endl;
//             return;
//         }
//     }
//     cout << "NO\n";
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }

// 0 0 1 1 2 2 3 4 4 4
// 0 1 1 2 3 3 3 3 4 5

// 0 0 1 1 2 2 3 4 4 4
// 0 1 1 2 3 3 3 3 4 5




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;



// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n*2);
//     for(int i = 0;i < 2*n;i++) cin >> a[i];
//     sort(all(a));

//     int ans = 0;
//     for(int i = 0;i < n*2;i += 2) ans += a[i];
//     cout << ans << endl;
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;



// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n);
//     iota(all(a), 1);

//     int c = n;
//     if(n & 1){
//         for(int i = 0;i < n;i += 2, c -= 2){
//             a[i] = c;
//         }

//     }else{
//         for(int i = 1;i < n;i += 2, c -= 2){
//             a[i] = c;
//         }
//     }
//     for(auto e : a) cout << e << ' ';
//     cout << endl;

// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;



// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n + 5);
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         a[i] += i;
//     }

//     map<int,int>mp;
//     auto find = [&](auto self, int x) -> int {
//         if(mp.count(x) == 0) {
//             mp[x] = x - 1;
//             return x;
//         }
//         int ret = self(self, mp[x]);
//         mp[x] = ret - 1;
//         return ret;
//     };

//     vector<int>ans;

//     for(int i = n;i >= 1;i--){
//         int x = find(find, a[i]);
//         if(x > 1) ans.push_back(x);
//     }

//     sort(all(ans), greater<int>());

//     for(int i = 0;i < n;i ++) cout << ans[i] << ' ';
//     cout << endl;
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;



// void solve(){
//     int n, ans = 0;
//     cin >> n;
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     for(int l = 1;l <= n;l ++){
//         for(int r = l;r <= n;r++){
//             int ls = -2;
//             for(int i = l;i <= r;i++) if(s[i] == '1'){
//                 if(i - ls > 1){
//                     ls = i+1;
//                     ans++;
//                 }
//             }
//         }
//     }

//     cout << ans << endl;
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;



// void solve(){
//     int n, ans = 0;
//     cin >> n;
//     string s;
//     cin >> s;
//     s = ' ' + s;
   
//     vector<int>dp(n+5);

//     for(int i = 1;i <= n;i ++){
//         if(s[i] == '1'){
//             int ls = max(0ll, i-3);
//             dp[i] = min(3ll, i) + dp[ls] + ls;
//         }else{
//             dp[i] = dp[i-1];
//         }
//         ans += dp[i];
//     }

//     cout << ans << endl;
// }

// signed main(){

// 	IO;
// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }