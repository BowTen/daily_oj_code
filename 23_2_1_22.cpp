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