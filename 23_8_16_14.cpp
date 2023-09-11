// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 105;
// int n, m;

// int pre[N], suf[N], vis[N];
// vector<int>g[N];

// void init(){
//     for(int i = 0;i <= n;i++) {
//         g[i].clear();
//         pre[i] = suf[i] = vis[i] = 0;
//     }
// }

// bool bfs(int x){
//     vis[x] = x;
//     queue<int>que;
//     que.push(x);
//     while(que.size()){
//         int u = que.front();
//         que.pop();
//         for(auto v : g[u]){
//             if(v == x) return false;
//             if(vis[v] == x) continue;
//             que.push(v);
//             vis[v] = x;
//             suf[x]++;
//             pre[v]++;
//         }
//     }
//     return true;
// }

// void solve(){
//     cin >> n >> m;
//     init();

//     bool f = false;
//     for(int i = 1;i <= m;i++){
//         int u, v;

//         cin >> u >> v;
//         g[u].push_back(v);
//         if(u == v) f = true;
//     }

//     if(f){
//         while(n--) cout << 0;
//         cout << '\n';
//         return;
//     }

//     for(int i = 1;i <= n;i++){
//         if(!bfs(i)){
//             while(n--) cout << 0;
//             cout << '\n';
//             return;
//         }
//     }

//     int n2 = n / 2;
//     for(int i = 1;i <= n;i++){
//         if(suf[i] <= n2 && pre[i] <= n2) cout << 1;
//         else cout << 0;
//     }
//     cout << '\n';
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
// const int N = 105;
// int n, m;

// int pre[N], suf[N], vis[N];
// vector<int>g[N];

// void init(){
//     for(int i = 0;i <= n;i++) {
//         g[i].clear();
//         pre[i] = suf[i] = vis[i] = 0;
//     }
// }

// bool bfs(int x){
//     vis[x] = x;
//     queue<int>que;
//     que.push(x);
//     while(que.size()){
//         int u = que.front();
//         que.pop();
//         for(auto v : g[u]){
//             if(v == x) return false;
//             if(vis[v] == x) continue;
//             que.push(v);
//             vis[v] = x;
//             suf[x]++;
//             pre[v]++;
//         }
//     }
//     return true;
// }

// void solve(){
//     cin >> n >> m;
//     init();

//     bool f = false;
//     for(int i = 1;i <= m;i++){
//         int u, v;

//         cin >> u >> v;
//         g[u].push_back(v);
//         if(u == v) f = true;
//     }

//     if(f){
//         while(n--) cout << 0;
//         cout << '\n';
//         return;
//     }

//     for(int i = 1;i <= n;i++){
//         if(!bfs(i)){
//             while(n--) cout << 0;
//             cout << '\n';
//             return;
//         }
//     }

//     int n2 = n / 2;
//     for(int i = 1;i <= n;i++){
//         if(suf[i] <= n2 && pre[i] <= n2) cout << 1;
//         else cout << 0;
//     }
//     cout << '\n';
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
// const int N = 1e6 + 10;
// int n, m, a[N];

// int tr[N];
// int lowbit(int x){
//     return x & -x;
// }

// void add(int x, int v){
//     while(x <= n){
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

// void solve(){
//     cin >> n;
//     for(int i = 0;i <= n + 2;i++) tr[i] = 0;
//     vector<int>pos(n + 10, 0);
//     vector<array<int, 2>>q;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++){
//         q.push_back({pos[a[i]] + 1, i - 1});
//         pos[a[i]] = i;
//     }
//     sort(q.begin(), q.end(), [](array<int,2> e1, array<int,2> e2)->int {
//         return e1[1] < e2[1];
//     });

//     int it = 1;
//     vector<int>ans(n + 10);
//     vector<int>last(n + 10);
//     for(auto [l, r] : q){
//         while(it <= r){
//             if(last[a[it]]) add(last[a[it]], -1);
//             last[a[it]] = it;
//             add(it, 1);
//             it++;
//         }
//         int mx;
//         if(l == 1) mx = n;
//         else mx = getsum(r) - getsum(l - 1);
//         ans[1]++;
//         ans[mx + 1]--;
//     }

//     for(int i = 1;i <= n;i++){
//         ans[i] += ans[i-1];
//         cout << ans[i] << "\n "[i<n];
//     }
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
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 3e5 + 10;
// int n;

// vector<int>g[N];

// struct node{
//     int tag;
//     int mn, sum;
// }tr[N << 2];

// void up(int id){
//     if(tr[lson].mn == tr[rson].mn) tr[id].sum = tr[lson].sum + tr[rson].sum;
//     else if(tr[lson].mn < tr[rson].mn) tr[id].sum = tr[lson].sum;
//     else tr[id].sum = tr[rson].sum;
//     tr[id].mn = min(tr[lson].mn, tr[rson].mn);
// }

// void build(int id, int l, int r){
//     tr[id].tag = 0;
//     if(l == r){
//         tr[id].mn = N;
//         tr[id].sum = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// void settag(int id, int x){
//     tr[id].tag += x;
//     tr[id].mn += x;
// }

// void down(int id){
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag = 0;
// }

// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id].mn = v;
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(x <= mid) change(lson, l, mid, x, v);
//     else change(rson, mid + 1, r, x, v);
//     up(id);
// }

// void modify(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr) {
//         settag(id, v);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, v);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, v);
//     else modify(lson, l, mid, ql, qr, v), modify(rson, mid + 1, r, ql, qr, v);
//     up(id);
// }

// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return (tr[id].mn == 1 ? tr[id].sum : 0);
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) g[i].clear();
//     for(int i = 1;i < n;i++){
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     build(1, 1, n);

//     int ans = 0;
//     for(int r = 1;r <= n;r++){
//         change(1, 1, n, r, 1);
//         if(r > 1) modify(1, 1, n, 1, r - 1, 1);
//         for(auto v : g[r]) if(v < r){
//             modify(1, 1, n, 1, v, -1);
//         }
//         ans += query(1, 1, n, 1, r);
//     }

//     cout << ans << '\n';
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 5e5 + 10;
// const int M = 2000 + 10;
// int n, m;
// vector<int>g[N];
// vector<int>vg[N];
// vector<int>ke;

// bool isq[N];
// int tot = 0, dfn[N], dep[N], par[N][20];
// void dfs(int u, int f){
//     dfn[u] = ++tot;
//     if(isq[u]) ke.push_back(u);
//     dep[u] = dep[f] + 1;
//     par[u][0] = f;
//     for(int i = 1;i < 20;i++) par[u][i] = par[par[u][i-1]][i-1];
//     for(auto v : g[u]) if(v != f)
//         dfs(v, u);
// }

// int lca(int u, int v){
//     if(dep[u] < dep[v]) swap(u, v);
//     for(int i = 19;i >= 0;i--) if(dep[par[u][i]] >= dep[v])
//         u = par[u][i];
//     if(u == v) return u;
//     for(int i = 19;i >= 0;i--) if(par[u][i] != par[v][i]){
//         u = par[u][i];
//         v = par[v][i];
//     }
//     return par[u][0];
// }

// bool cmp(int a, int b){
//     return dfn[a] < dfn[b];
// }

// void vtree(){
//     sort(ke.begin(), ke.end(), cmp);
//     for(int i = 0, len = ke.size();i < len - 1;i++) ke.push_back(lca(ke[i], ke[i + 1]));
//     ke.erase(unique(ke.begin(), ke.end()), ke.end());
//     sort(ke.begin(), ke.end(), cmp);
//     for(int i = 1, len = ke.size(); i < len;i++){
//         int ca = lca(ke[i], ke[i - 1]);
//         vg[ca].push_back(ke[i]);
//         vg[ke[i]].push_back(ca);
//     }
// }

// int fa[N], val[N], esiz[N], w[N];
// void dfs2(int u, int f){
//     fa[u] = f;
//     esiz[u] = dep[u] - dep[f] - 1;
//     for(auto v : vg[u]) if(v != f) dfs2(v, u);
// }

// struct node{
//     int op, u, v, k;
// }q[M];

// void init(){
//     tot = 0;
//     ke.clear();
//     for(int i = 1;i <= n;i++) {
//         w[i] = val[i] = 0;
//         fa[i] = 0;
//         g[i].clear();
//         vg[i].clear();
//         isq[i] = false;
//         for(int j = 0;j < 20;j++) par[i][j] = 0;
//     }
// }

// const int ADD = 1, XOR = 2, DIV = 3, SUM = 4, XSUM = 5;
// void change(int u, int v, int k, int op){
//     if(dep[u] < dep[v]) swap(u, v);
//     while(dep[u] > dep[v]){
//         if(op == ADD){
//             w[u] += k;
//             val[u] += k;
//         }else if(op == DIV){
//             if(w[u] >= k)
//             w[u] -= k;
//             if(val[u] >= k)
//             val[u] -= k;
//         }else{
//             w[u] ^= k;
//             val[u] ^= k;
//         }
//         u = fa[u];
//     }
//     while(u != v){
//         if(op == ADD){
//             w[u] += k;
//             val[u] += k;
//         }else if(op == DIV){
//             if(w[u] >= k)
//             w[u] -= k;
//             if(val[u] >= k)
//             val[u] -= k;
//         }else{
//             w[u] ^= k;
//             val[u] ^= k;
//         }
//         u = fa[u];
//         v = fa[v];
//     }
//         if(op == ADD){
//             w[u] += k;
//         }else if(op == DIV){
//             if(w[u] >= k)
//             w[u] -= k;
//         }else{
//             w[u] ^= k;
//         }
// }

// int query(int u, int v, int op){
//     int ans = 0;
//     if(dep[u] < dep[v]) swap(u, v);
//     while(dep[u] > dep[v]){
//         if(op == SUM){
//             ans += val[u] * esiz[u] + w[u];
//         }else{
//             ans ^= w[u];
//             if(esiz[u] & 1) ans ^= val[u];
//         }
//         u = fa[u];
//     }
//     while(u != v){
//         if(op == SUM){
//             ans += val[u] * esiz[u] + w[u];
//             ans += val[v] * esiz[v] + w[v];
//         }else{
//             ans ^= w[u];
//             ans ^= w[v];
//             if(esiz[u] & 1) ans ^= val[u];
//             if(esiz[v] & 1) ans ^= val[u];
//         }

//         u = fa[u];
//         v = fa[v];
//     }
//     if(op == SUM){
//         ans += w[u];
//     }else{
//         ans ^= w[u];
//     }
//     return ans;
// }

// void solve(){
//     cin >> n >> m;
//     init();
//     for(int i = 1;i < n;i++){
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     for(int i = 1;i <= m;i++){
//         cin >> q[i].op >> q[i].u >> q[i].v;
//         q[i].k = 0;
//         if(q[i].op == 1 || q[i].op == 2 || q[i].op == 3 || q[i].op == 7) cin >> q[i].k;
//         isq[q[i].u] = isq[q[i].v] = true;
//     }

//     dfs(1, 0);
//     vtree();
//     dfs2(1, 0);

//     for(int i = 1;i <= m;i++){
//         auto [op, u, v, k] = q[i];
//         if(op == 1){    //路劲加
//             change(u, v, k, op);
//         }else if(op == 2){      //路径异或
//             change(u, v, k, op);
//         }else if(op == 3){      //路劲减
//             change(u, v, k, op);
//         }else if(op == 4){      //路径求和
//             cout << query(u, v, op) << '\n';
//         }else if(op == 5){      //路径异或和
//             cout << query(u, v, op) << '\n';
//         }else if(op == 6){      //路径极差
//             if(dep[u] < dep[v]) swap(u, v);
//             int mn = w[u], mx = w[u];
//             while(dep[u] < dep[v]){
//                 mn = min({mn, w[u], val[u]});
//                 mx = max({mx, w[u], val[u]});
//                 u = fa[u];
//             }
//             while(u != v){
//                 mn = min({mn, w[u], val[u]});
//                 mx = max({mx, w[u], val[u]});
//                 mn = min({mn, w[v], val[v]});
//                 mx = max({mx, w[v], val[v]});
//                 u = fa[u];
//                 v = fa[v];
//             }
//             cout << mx - mn << '\n';
//         }else{      //最小与k差
//             if(dep[u] < dep[v]) swap(u, v);
//             int mn = abs(w[u] - k);
//             while(dep[u] < dep[v]){
//                 mn = min({mn, abs(w[u] - k), abs(val[u] - k)});
//                 u = fa[u];
//             }
//             while(u != v){
//                 mn = min({mn, abs(w[u] - k), abs(val[u] - k)});
//                 mn = min({mn, abs(w[v] - k), abs(val[v] - k)});
//                 u = fa[u];
//                 v = fa[v];
//             }
//             cout << mn << '\n';

//         }
//     }
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, m, a[N], a1, ak, k;

// void solve(){
//     cin >> m >> k >> a1 >> ak;
//     int ans = 0;
//     if(ak * k > m){
//         m %= k;
//         m = max(0ll, m - a1);
//         cout << m << '\n';
//         return;
//     }
//     m -= ak * k;
//     if(m <= a1){
//         cout << "0\n";
//         return;
//     }
//     m -= a1;

//     int ck = m / k;
//     ans += ck;
//     m -= ck * k;

//     if(m && a1 + m >= k) ans++;
//     else ans += m;

//     cout << ans << '\n';

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
// const int N = 3e5 + 10;
// int n, m, a[N];

// int d[N], w[N];
// int lowbit(int x){
//     return x & -x;
// }

// void addd(int x, int v){
//     while(x <= n){
//         d[x] += v;
//         x += lowbit(x);
//     }
// }
// void addw(int x, int v){
//     while(x <= n){
//         w[x] += v;
//         x += lowbit(x);
//     }
// }
// int getd(int x){
//     int ret = 0;
//     while(x > 0){
//         ret += d[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }
// int getw(int x){
//     int ret = 0;
//     while(x > 0){
//         ret += w[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void init(){
//     for(int i = 1;i <= n;i++) d[i] = w[i] = 0;
// }

// void solve(){
//     cin >> n;
//     init();
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int p = n + 1;
//     addd(a[1], 1);
//     for(int i = 2;i <= n;i++){
//         if(a[i] > a[i-1]){
//             p = i;
//             break;
//         }
//         addd(a[i], 1);
//     }

//     int ans = 0;
//     for(int i = p;i <= n;i++){
//         if(getw(a[i])) addd(a[i], 1);
//         else if(getd(a[i])) addw(a[i], 1), ans++;
//         else addd(a[i], 1);
//     }

//     cout << ans << '\n';
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e5 + 10;
// int n, m, a[N], pw[20];

// struct node{
//     int bits[20], tag = 0, sum, len = 0;

//     node operator+(const node &e) const {
//         node ret = *this;
//         ret.tag = 0;
//         ret.sum += e.sum;
//         ret.len += e.len;
//         for(int i = 0;i < 20;i++) ret.bits[i] += e.bits[i];
//         return ret;
//     }

//     void operator^=(int x) {
//         for(int i = 0;i < 20;i++) if((x >> i) & 1) {
//             sum -= pw[i] * bits[i];
//             bits[i] = len - bits[i];
//             sum += pw[i] * bits[i];
//         }
//     }

//     node(int x = 0) : sum(x) {
//         for(int i = 0;i < 20;i++) bits[i] = (x >> i) & 1;
//     }
// }tr[N << 2];

// void up(int id){
//     tr[id] = tr[lson] + tr[rson];
// }

// void build(int id, int l, int r){
//     if(l == r){
//         tr[id] = node(a[l]);
//         tr[id].len = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// void settag(int id, int x){
//     // cout << id << ' ' << x << '\n';
//     tr[id].tag ^= x;
//     tr[id] ^= x;
// }

// void down(int id){
//     // cout << id << '\n';
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag = 0;
// }

// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].sum;
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
// }

// void modify(int id, int l, int r, int ql, int qr, int x){
//     if(ql <= l && r <= qr){
//         // cout << id << ' ' << x << '\n';
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

// signed main(){

//     pw[0] = 1;
//     for(int i = 1;i < 20;i++) pw[i] = pw[i-1] * 2;

//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);
//     cin >> m;
//     while(m--){
//         int op, l, r, k;
//         cin >> op >> l >> r;
//         if(op == 1){
//             cout << query(1, 1, n, l, r) << '\n';
//         }else{
//             cin >> k;
//             modify(1, 1, n, l, r, k);
//             // cout << "___\n";
//         }
//     }

//     // cout << tr[2].sum;

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// #define IO ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, q;

// struct node{
//     int l, r, mx, pre, suf, len;
//     node() : l(0), r(0), mx(1), pre(1), suf(1), len(1) {}
// }tr[N << 2];

// void up(int id){
//     tr[id].len = tr[lson].len + tr[rson].len;
//     tr[id].l = tr[lson].l;
//     tr[id].r = tr[rson].r;
//     tr[id].pre = tr[lson].pre;
//     tr[id].suf = tr[rson].suf;
//     tr[id].mx = max(tr[lson].mx, tr[rson].mx);
//     if(tr[lson].r != tr[rson].l){
//         tr[id].mx = max(tr[id].mx, tr[lson].suf + tr[rson].pre);
//         if(tr[lson].len == tr[lson].pre) tr[id].pre += tr[rson].pre;
//         if(tr[rson].len == tr[rson].suf) tr[id].suf += tr[lson].suf;
//     }
// }

// void change(int id, int l, int r, int x){
//     if(l == r){
//         int x = 1 ^ tr[id].l;
//         tr[id].l = tr[id].r = x;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(lson, l, mid, x);
//     else change(rson, mid + 1, r, x);
//     up(id);
// }

// signed main(){

//     IO;
//     cin >> n >> q;
//     while(q--){
//         int x;
//         cin >> x;
//         change(1, 1, n, x);
//         cout << tr[1].mx << '\n';
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// #define IO ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, q;

// int mx[N<<2], L[N<<2], R[N<<2], len[N<<2], pre[N<<2], suf[N<<2];

// void up(int id){
//     len[id] = len[lson] + len[rson];
//     L[id] = L[lson];
//     R[id] = R[rson];
//     pre[id] = pre[lson];
//     suf[id] = suf[rson];
//     mx[id] = max(mx[lson], mx[rson]);
//     if(R[lson] != L[rson]){
//         mx[id] = max(mx[id], suf[lson] + pre[rson]);
//         if(len[lson] == pre[lson]) pre[id] += pre[rson];
//         if(len[rson] == suf[rson]) suf[id] += suf[lson];
//     }
// }

// void build(int id, int l, int r){
//     if(l == r){
//         pre[id] = suf[id] = len[id] = mx[id] = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, 1, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// void change(int id, int l, int r, int x){
//     if(l == r){
//         int xx = L[id] ^ 1;
//         L[id] = R[id] = xx;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(lson, l, mid, x);
//     else change(rson, mid + 1, r, x);
//     up(id);
// }

// signed main(){

//     IO;
//     cin >> n >> q;
//     build(1, 1, n);
//     while(q--){
//         int x;
//         cin >> x;
//         change(1, 1, n, x);
//         cout << mx[1] << '\n';
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, m;
// string s;
// int num[300], cnt;
// int pre[N];
// vector<int>pos[300];

// signed main(){

//     IO;
//     cin >> m >> n;
//     cin >> s;
//     s = ' ' + s;
//     for(int i = 1;i <= n;i++){
//         pre[i] += pre[i-1];
//         num[s[i]]++;
//         if(num[s[i]] == 1) cnt++;
//         if(cnt == m){
//             pre[i]++;
//             cnt = 0;
//             for(int i = 'a';i < 'a' + m;i++) num[i] = 0;
//         }
//         pos[s[i]].push_back(i);
//     }

//     int q;
//     cin >> q;
//     while(q--){
//         int l, r;
//         cin >> l >> r;
//         if(m == 1){
//             cout << r - l + 2 << '\n';
//             continue;
//         }
//         int bg = 0;
//         bool all = true;
//         for(int i = 'a';i < 'a' + m;i++){
//             int mx = lower_bound(pos[i].begin(), pos[i].end(), l) - pos[i].begin();
//             if(mx == pos[i].size() || pos[i][mx] > r){
//                 all = false;
//                 break;
//             }
//             bg = max(bg, pos[i][mx]);
//         }
//         if(!all){
//             cout << "1\n";
//             continue;
//         }
//         // cout << bg << ' ';
//         int ans = pre[r] - pre[l - 1] + 1;
//         if(pre[bg] - pre[bg - 1] == 1 && pre[bg] - pre[l - 1] == 2) ans --;
//         cout << ans << '\n';
//     }

//     // cout << s.size();
//     // cout << ;
//     // for(int i = 45;i <= 80;i++) cout << s[i];
//     // for(int i = 48;i <= 78;i++) if(pre[i] != pre[i - 1]) cout << i << ' ';

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef pair<int, int> pii;
// typedef unsigned long long ull;
// const ll inf = 1e18;
// const int N = 2e5 + 10;
// const int M = 1e6 + 10;
// const double eps = 1e-8;
// const int mod = 998244353;

// #define fi first
// #define se second
// #define re register
// #define lowbit (-x&x)
// #define endl '\n'
// int n, m;
// char s[N];
// int nxt[N][26];
// int f[N][20];
// int pos[26];
// void solve() {
//     cin >> m >> n;
//     cin >> (s + 1);
//     for (int i = 0; i < 26; i++) nxt[n][i] = n + 1;
//     for (int i = n; i >= 1; i--) {
//         if (!pos[s[i]-'a']) nxt[i][s[i]-'a'] = n + 1;
//         else nxt[i][s[i]-'a'] = pos[s[i]-'a'];
//         pos[s[i]-'a'] = i;
//         for (int j = 0; j < m; j++) {
//             if (pos[j]) nxt[i-1][j] = pos[j];
//             else nxt[i-1][j] = n + 1;
//         }
//     }
//     for (int i = 0; i <= n; i++) {
//         int ma = 0;
//         for (int j = 0; j < m; j++) ma = max(ma, nxt[i][j]);
//         f[i][0] = ma;
//         for (int j = 0; j < 20; j++) f[n+1][j] = f[n][j] = n + 1;
//     }
//     for (int j = 1; j < 20; j++) {
//         for (int i = 0; i <= n; i++) {
//             f[i][j] = f[f[i][j-1]][j-1];
// //            if (!i) cout << f[i][j] << ' ' << f[i][j-1] << ' ' << j-1 << endl;
//         }
//     }
//     int q; cin >> q;
//     while (q--) {
//         int l, r; cin >> l >> r;
//         int ans = 0;
//         int now = l - 1;
//         for (int i = 19; ~i; i--) {
//             if (f[now][i] <= r) {
//                 ans += (1 << i);
//                 now = f[now][i];
//             }
//         }
//         printf("%d\n", ans+1);
//     }
// }
// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
// #ifdef ACM_LOCAL
//     freopen("input", "r", stdin);
//     freopen("output", "w", stdout);
// #endif

// #ifdef ACM_LOCAL
//     auto start = clock();
// #endif
//     int t = 1;
// //    cin >> t;
//     while (t--)
//         solve();
// #ifdef ACM_LOCAL
//     auto end = clock();
//     cerr << "Run Time: " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
// #endif
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// int n;

// struct Point{
//     double x, y;
//     int operator<(const Point& e) const {
//         return x == e.x ? y < e.y : x < e.x;
//     }
// }p[N];

// Point s[N];
// int top;

// double cross(Point p1, Point p2, Point p3){
//     p2.x -= p1.x, p2.y -= p1.y;
//     p3.x -= p1.x, p3.y -= p1.y;
//     return p2.x * p3.y - p2.y * p3.x;
// }

// double dis(Point a, Point b){
//     double dx = a.x - b.x;
//     double dy = a.y - b.y;
//     return sqrt(dx * dx + dy * dy);
// }

// double Andrew(){
//     sort(p + 1, p + 1 + n);
//     for(int i = 1;i <= n;i++){
//         while(top > 1 && cross(s[top-1], s[top], p[i]) <= 0) top--;
//         s[++top] = p[i];
//     }
//     int t = top;
//     for(int i = n - 1;i >= 1;i--){
//         while(top > t && cross(s[top-1], s[top], p[i]) <= 0) top--;
//         s[++top] = p[i];
//     }
//     double res = 0;
//     for(int i = 1;i < top;i++) res += dis(s[i], s[i+1]);
//     return res;
// }

// signed main(){

//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> p[i].x >> p[i].y;
//     }
//     cout << fixed << setprecision(2) << Andrew();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5 + 10;
// int n, a[N], m;

// void solve(){
//     cin >> n >> m;
//     char mp[22][22];
//     for(int i = 1;i <= n;i++)
//         cin >> mp[i];
//     string tp = " vika";
//     int p = 1;
//     for(int j = 0;j < m;j++){
//         for(int i = 1;i <= n;i++){
//             if(mp[i][j] == tp[p]){
//                 p++;
//                 break;
//             }
//         }
//         if(p == 5){
//             cout << "YES\n";
//             return;
//         }
//     }
//     cout << "NO\n";

// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// const int N = 1e6 + 10;
// int n, a[N], m, b[N];

// void solve(){
//     cin >> n;
//     int mn = INT_MAX;
//     for(int i = 1;i <= n;i++) cin >> b[i], mn = min(mn, b[i]);
//     mn = max(1, mn - 1);
//     m = n;
//     a[1] = b[1];
//     for(int i = 2, j = 2;i <= n;i++, j++){
//         if(b[i] < a[j-1]){
//             a[j++] = mn;
//             m++;
//         }
//         a[j] = b[i];
//     }
//     cout << m << '\n';
//     for(int i = 1;i <= m;i++) cout << a[i] << ' ';
//     cout << '\n';
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e6 + 10;
// int n, a[N], m, b[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     a[n+1] = 0;
//     if(a[1] != n){
//         cout << "NO\n";
//         return;
//     }
//     int h = 1;
//     for(int i = 1, j = a[1];i <= n;i++, h++){
//         while(a[i] == a[i+1]){
//             h++;
//             i++;
//         }
//         while(j > a[i + 1]){
//             b[j] = h;
//             j--;
//         }
//     }
//     b[1] = n;
//     for(int i = 1;i <= n;i++){
//         if(a[i] != b[i]){
//             cout <<"NO\n";
//             return;
//         }
//         // cout << b[i] << ' ';

//     }

//     cout << "YES\n";
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e6 + 10;
// int n, a[N], m, b[N];

// void solve(){
//     cin >> n;
//     int l = 2, r = 2e9;
//     while(l <= r){
//         int mid = l + r >> 1;
//         if((mid * (mid - 1)) / 2 > n) r = mid - 1;
//         else l = mid + 1;
//     }
//     // cout << (l * (l - 1)) / 2 << '\n';
//     for(int i = max(2ll, l - 1);i <= l + 2;i++){
//         if((i * (i - 1)) / 2 > n){
//             l = i - 1;
//             break;
//         }
//     }
//     int ans = l + (n - (l * (l - 1)) / 2);
//     cout << ans << '\n';
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e6 + 10;
// int n, a[N], m, b[N], d;

// void solve(){
//     cin >> n >> m >> d;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     priority_queue<int, vector<int>, greater<int>>q;
//     int sum = 0, ans = 0;
//     for(int i = 1;i <= n;i++){
//         if(a[i] > 0) q.push(a[i]), sum += a[i];
//         if(q.size() > m) sum -= q.top(), q.pop();
//         ans = max(ans, sum - d * i);
//     }
//     cout << ans << '\n';
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 110;
// int n, a[N], w, f;

// void solve(){
//     cin >> w >> f >> n;
//     int sum = 0;
//     for(int i = 1;i <= n;i++) cin >> a[i], sum += a[i];
//     vector<int>dp(sum + 1, 0);
//     dp[0] = 1;
//     for(int i = 1;i <= n;i++){
//         for(int j = sum;j >= a[i];j--){
//             dp[j] |= dp[j - a[i]];
//         }
//     }
//     int ans = sum;
//     for(int i = 0;i <= sum;i++) if(dp[i]){
//         ans = min(ans, max((i + w - 1) / w, (sum - i + f - 1) / f));
//     }
//     cout << ans << '\n';
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1010;
// int n, a[N], w, f;

// void solve(){
//     int x, y;
//     cin >> x >> y >> n;
//     int d = 1;
//     a[n] = y;
//     for(int i = n - 1;i >= 2;i--, d++){
//         a[i] = a[i+1] - d;
//     }
//     if(a[2] - x <= a[3] - a[2]) cout << "-1\n";
//     else{
//         cout << x << ' ';
//         for(int i = 2;i <= n - 1;i++) cout << a[i] << ' ';
//         cout << y << '\n';
//     }
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// int n, k;
// char s[N];

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++) cin >> s[i];
//     if(k % 2 == 0){
//         sort(s + 1, s + 1 + n);
//     }else{
//         vector<char>ss[2];
//         for(int i = 1;i <= n;i++){
//             ss[(i&1)].push_back(s[i]);
//         }
//         sort(ss[1].begin(), ss[1].end());
//         sort(ss[0].begin(), ss[0].end());
//         int it[2] = {0};
//         for(int i = 1;i <= n;i++){
//             s[i] = ss[(i&1)][it[(i&1)]++];
//         }
//     }
//         for(int i = 1;i <= n;i++) cout << s[i];
//         cout << '\n';
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// int n, x;

// void solve(){
//     cin >> x;
//     int ad = 1, cur = 1;
//     vector<int>ans;
//     ans.push_back(1);
//     while(cur + ad <= x){
//         cur += ad;
//         ans.push_back(cur);
//         ad *= 2;
//     }
//     while(cur < x){
//         while(cur + ad > x) ad /= 2;
//         cur += ad;
//         ans.push_back(cur);
//     }
//     cout << ans.size() << '\n';
//     for(int i = ans.size() - 1;i >= 0;i--) cout << ans[i] << ' ';
//     cout << '\n';
// }

// signed main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, m, a, q;

// void solve(){
//     cin >> n >> a >> q;
//     string s;
//     cin >> s;
//     if(a >= n){
//         cout << "YES\n";
//         return;
//     }
//     int ad = 0, sum = 0;
//     int mx = 0;
//     for(auto c : s){
//         if(c == '+') ad++, sum++;
//         else ad--;
//         mx = max(mx, ad);
//     }
//     if(a + mx >= n) cout << "YES\n";
//     else if(a + sum >= n) cout << "MAYBE\n";
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
// const int N = 2e5 + 10;
// int n, p[N], pos[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> p[i], pos[p[i]] = i;
//     int ans = 0;
//     for(int i = 1;i < n;i++){
//         if(pos[i+1] < pos[i]) ans++;
//     }
//     cout << ans << '\n';
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
// const int N = 2e5 + 10;
// int n, a[N], k;

// void solve(){
//     cin >> n >> k;
//     vector<int>vis(n + 2, 0);
//     for(int i = 1;i <= n;i++) cin >> a[i], vis[a[i]] = 1;
//     for(int i = 0;i <= n;i++) if(!vis[i]){
//         a[0] = i;
//         break;
//     }
//     int st = 1, ed = n;
//     k %= (n + 1);
//     st = (1 + n + 1 - k) % (n + 1);
//     for(int i = 1;i <= n;i++){
//         cout << a[st] << ' ';
//         st++;
//         st %= (n + 1);
//     }
//     cout << '\n';
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
// const int N = 510;
// int n, m, a[N], k;
// string mp[N];

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) cin >> mp[i], mp[i] = ' ' + mp[i];
//     for(int j = 1;j <= m;j++){
//         int last = 0;
//         for(int i = 1;i <= n;i++){
//             if(mp[i][j] == 'L'){
//                 if(last){
//                     mp[last][j] = 'B';
//                     mp[last][j+1] = 'W';
//                     mp[i][j] = 'W';
//                     mp[i][j+1] = 'B';
//                     last = 0;
//                 }else{
//                     last = i;
//                 }
//             }
//         }
//         if(last){
//             cout << "-1\n";
//             return;
//         }
//     }
//     for(int i = 1;i <= n;i++){
//         int last = 0;
//         for(int j = 1;j <= m;j++){
//             if(mp[i][j] == 'U'){
//                 if(last){
//                     mp[i][last] = 'B';
//                     mp[i+1][last] = 'W';
//                     mp[i][j] = 'W';
//                     mp[i+1][j] = 'B';
//                     last = 0;
//                 }else{
//                     last = j;
//                 }
//             }
//         }
//         if(last){
//             cout << "-1\n";
//             return;
//         }
//     }
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             cout << mp[i][j];
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 3010;
// int n;
// string mp[N];

// struct node{
//     int l, r;
//     node() : l(0), r(0) {}
// };

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> mp[i], mp[i] = ' ' + mp[i];
//     vector<node>tag[2] = {vector<node>(n+1), vector<node>(n+1)};
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         int d = 0, cur = i & 1, ne = cur ^ 1;
//         for(int j = 1;j <= n;j++){
//             if(tag[cur][j].l){
//                 d++;
//             }
//             if((d & 1) != (mp[i][j] - '0')){
//                 tag[ne][max(1, j-1)].l ^= 1;
//                 tag[ne][min(n, j+1)].r ^= 1;
//                 ans++;
//             }
//             if(tag[cur][j].r){
//                 d--;
//             }
//             if(tag[cur][j].l) tag[ne][max(1, j-1)].l ^= 1;
//             if(tag[cur][j].r) tag[ne][min(n, j+1)].r ^= 1;
//             tag[cur][j].l = 0;
//             tag[cur][j].r = 0;
//         }
//     }
//     cout << ans << '\n';
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
// const int N = 2e5 + 10;
// int n, a[N];

// void solve(){
//     string s;
//     cin >> s;
//     for(auto c : s){
//         if(c == '3'){
//             cout << "31\n";
//             return;
//         }
//         if(c == '1'){
//             cout << "13\n";
//             return;
//         }
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
// const int N = 2e5 + 10;
// int n, a[N];

// void solve(){
//     string a, b;
//     cin >> a >> b;
//     n = a.size();
//     if(a[0] != b[0] || a[n-1] != b[n-1]){
//         cout << "NO\n";
//         return;
//     }
//     if(a[0] == a[n-1]){
//         cout << "YES\n";
//         return;
//     }
//     n = a.size();
//     for(int i = 0;i < n - 1;i++){
//         if(a[i] == a[0] && a[i+1] == a[n-1] && a[i] == b[i] && a[i+1] == b[i+1]){
//             cout << "YES\n";
//             return;
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
// const int N = 2e5 + 10;
// int n;

// void solve(){
//     string s;
//     cin >> s;
//     vector<int>st(s.size() + 1, 0);
//     st[0] = st[1] = '1';
//     int len = 0;
//     int mn = 2;
//     int zer = 0;
//     for(auto c : s){
//         if(c == '+'){
//             len++;
//         }else if(c == '-'){
//             mn = max(2ll, min(mn, len));
//             if(len > 1){
//                 st[len] = 0;
//             }
//             len--;
//             if(len < zer) zer = 0;
//         }else{
//             if(st[len] == 0){
//                 if(c == '0'){
//                     st[len] = c;
//                     if(!zer) zer = len;
//                 }else{
//                     if(zer){
//                         cout << "NO\n";
//                         return;
//                     }
//                     while(mn <= len){
//                         st[mn++] = c;
//                     }
//                 }
//             }else{
//                 if(st[len] != c || (zer && c == '1')){
//                     cout << "NO\n";
//                     return;
//                 }
//             }
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
// const int N = 2e5 + 10;
// int n, a[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     int ans = LONG_LONG_MAX;
//     vector<int>pre(n + 2);
//     vector<int>suf(n + 2);
//     for(int i = n - 1;i >= 1;i--){
//         suf[i] = suf[i+1];
//         if(a[i] >= a[i+1]) suf[i]++;
//     }
//     for(int i = 2;i <= n;i++){
//         pre[i] = pre[i-1];
//         if(a[i] >= a[i-1]) pre[i]++;
//     }
//     for(int i = 1;i <= n;i++){
//         ans = min(ans, pre[i] + suf[i+1] + 1);
//     }
//     ans = min({ans, pre[n] + 1, suf[1]});
//     cout << ans << '\n';
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
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, m;

// int trl[N], trr[N];

// int lowbit(int x){
//     return x & -x;
// }

// void add(int l, int r){
//     while(l <= n){
//         trl[l]++;
//         l += lowbit(l);
//     }
//     while(r <= n){
//         trr[r]++;
//         r += lowbit(r);
//     }
// }

// int query(int l, int r){
//     int ret = 0;
//     while(r > 0){
//         ret += trl[r];
//         r -= lowbit(r);
//     }
//     l--;
//     while(l > 0){
//         ret -= trr[l];
//         l -= lowbit(l);
//     }
//     return ret;
// }

// signed main(){

//     cin >> n >> m;
//     while(m--){
//         int op, l, r;
//         cin >> op >> l >> r;
//         if(op == 1){
//             add(l, r);
//         }else{
//             cout << query(l, r) << '\n';
//         }
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, q, a[N], s[N];

// struct node{
//     int mx, tag;
// }tr[N << 2];

// void up(int id){
//     tr[id].mx = max(tr[lson].mx, tr[rson].mx);
// }

// inline void settag(int id, int x){
//     tr[id].mx += x;
//     tr[id].tag += x;
// }

// void down(int id){
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag = 0;
// }

// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].mx = a[l] - s[l-1];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id].mx += v;
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(x <= mid) change(lson, l, mid, x, v);
//     else change(rson, mid + 1, r, x, v);
//     up(id);
// }

// void modify(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr){
//         settag(id, v);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, v);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, v);
//     else modify(lson, l, mid, ql, qr, v) , modify(rson, mid + 1, r, ql, qr, v);
//     up(id);
// }

// int res;
// void query(int id, int l, int r){
//     if(res != -1) return;
//     if(l == r){
//         if(tr[id].mx == 0) res = l;
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(tr[lson].mx >= 0) query(lson, l, mid);
//     if(tr[rson].mx >= 0) query(rson, mid + 1, r);
// }

// signed main(){

//     scanf("%lld %lld", &n, &q);
//     for(int i = 1;i <= n;i++) cin >> a[i], s[i] = s[i-1] + a[i];
//     build(1, 1, n);
//     while(q--){
//         int x, v, d;
//         scanf("%lld %lld", &x, &v);
//         d = v - a[x];
//         a[x] += d;
//         change(1, 1, n, x, d);
//         if(x + 1 <= n)
//             modify(1, 1, n, x + 1, n, -d);
//         res = -1;
//         query(1, 1, n);
//         printf("%lld\n", res);
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 3e5 + 10;
// int n, q, a[N];

// //主席树
// int rt[N * 50], ls[N * 50], rs[N * 50], sum[N * 50], tot;

// void newLine(int &cur, int pre, int l, int r, int x){
//     cur = ++tot;
//     ls[cur] = ls[pre], rs[cur] = rs[pre], sum[cur] = sum[pre] + 1;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     if(x <= mid) newLine(ls[cur], ls[pre], l, mid, x);
//     else newLine(rs[cur], rs[pre], mid + 1, r, x);
// }

// int query(int R, int L, int l, int r, int k){
//     if(l == r) return l;
//     int mid = l + r >> 1;
//     if(sum[ls[R]] - sum[ls[L]] > k){
//         int ret = query(ls[R], ls[L], l, mid, k);
//         if(ret != -1) return ret;
//     }
//     if(sum[rs[R]] - sum[rs[L]] > k) return query(rs[R], rs[L], mid + 1, r, k);
//     return -1;
// }

// signed main(){

//     IO;
//     cin >> n >> q;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         newLine(rt[i], rt[i - 1], 1, n, a[i]);
//     }
//     while(q--){
//         int l, r, k;
//         cin >> l >> r >> k;
//         k = (r - l + 1) / k;
//         cout << query(rt[r], rt[l - 1], 1, n, k) << '\n';
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 3e5 + 10;
// int n, k, q, a[N], m;

// int ori[N << 2];
// void build(int id, int l, int r){
//     if(l == r){
//         ori[id] = a[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     ori[id] = min(ori[lson], ori[rson]);
// }

// int qry(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return ori[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return qry(lson, l, mid, ql, qr);
//     else if(ql > mid) return qry(rson, mid + 1, r, ql, qr);
//     else return min(qry(lson, l, mid, ql, qr), qry(rson, mid + 1, r, ql, qr));
// }

// int rt, ls[N * 50], rs[N * 50], tag[N * 50], mn[N * 50], tot;

// void settag(int id, int x){
//     tag[id] = mn[id] = x;
// }

// void down(int id){
//     if(!ls[id]) ls[id] = ++tot;
//     if(!rs[id]) rs[id] = ++tot;
//     settag(ls[id], tag[id]);
//     settag(rs[id], tag[id]);
//     tag[id] = 0;
// }

// int newSeg(int l, int r){
//     ++tot;
//     if(r - l + 1 >= n) mn[tot] = ori[1];
//     else{
//         int ql = l % n, qr = r % n;
//         if(!ql) ql = n;
//         if(!qr) qr = n;
//         if(ql <= qr) mn[tot] = qry(1, 1, n, ql, qr);
//         else mn[tot] = min(qry(1, 1, n, 1, qr), qry(1, 1, n, ql, n));
//     }
//     return tot;
// }

// void up(int id, int l, int r){
//     int mid = l + r >> 1;
//     if(!ls[id]) ls[id] = newSeg(l, mid);
//     if(!rs[id]) rs[id] = newSeg(mid + 1, r);
//     mn[id] = min(mn[ls[id]], mn[rs[id]]);
// }

// void modify(int &id, int l, int r, int ql, int qr, int x){
//     if(!id) id = ++tot;
//     if(ql <= l && r <= qr){
//         settag(id, x);
//         return;
//     }
//     if(tag[id]) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls[id], l, mid, ql, qr, x);
//     else if(ql > mid) modify(rs[id], mid + 1, r, ql, qr, x);
//     else modify(ls[id], l, mid, ql, qr, x), modify(rs[id], mid + 1, r, ql, qr, x);
//     up(id, l, r);
// }

// int query(int &id, int l, int r, int ql, int qr){
//     if(!id) id = newSeg(l, r);
//     if(ql <= l && r <= qr) return mn[id];
//     if(tag[id]) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls[id], l, mid, ql, qr);
//     else if(ql > mid) return query(rs[id], mid + 1, r, ql, qr);
//     else return min(query(ls[id], l, mid, ql, qr), query(rs[id], mid + 1, r, ql, qr));
// }

// signed main(){

//     IO;
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);
//     m = n * k;
//     cin >> q;
//     while(q--){
//         int op, l, r, x;
//         cin >> op >> l >> r;
//         if(op == 1){
//             cin >> x;
//             modify(rt, 1, m, l, r, x);
//         }else{
//             cout << query(rt, 1, m, l, r) << '\n';
//         }
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 5e5 + 10;
// int n, a[N], q, last[N], ls[N];

// struct node{
//     int mn, x;
//     int operator<(const node &e) const{
//         if(x == e.x) return mn > e.mn;
//         return mn <= e.mn;
//     }
// }tr[N << 2];

// void up(int id){
//     tr[id] = min(tr[lson], tr[rson]);
// }

// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].mn = INT_MAX;
//         tr[id].x = a[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// node query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return min(query(lson, l, mid, ql, qr), query(rson, mid + 1, r, ql, qr));
// }

// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id].mn = v;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(lson, l, mid, x, v);
//     else change(rson, mid + 1, r, x, v);
//     up(id);
// }

// signed main(){

//     IO;

//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);
//     cin >> q;
//     vector<array<int, 3>>que(q);
//     for(int i = 0;i < q;i++){
//         cin >> que[i][0] >> que[i][1];
//         que[i][2] = i + 1;
//     }
//     sort(que.begin(), que.end(), [](array<int, 3>e1, array<int, 3>e2)->int {return e1[1] < e2[1];});
//     vector<int>ans(q + 1);

//     int it = 1;
//     for(auto [l, r, id] : que){
//         while(it <= r){
//             change(1, 1, n, it, last[a[it]]);
//             if(last[a[it]]) change(1, 1, n, last[a[it]], last[a[it]]);
//             last[a[it]] = it;
//             it++;
//         }
//         node res = query(1, 1, n, l, r);
//         if(res.mn >= l) res.x = 0;
//         ans[id] = res.x;
//     }

//     for(int i = 1;i <= q;i++) cout << ans[i] << '\n';

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define lson id << 1
// #define rson id << 1 | 1
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 5e5 + 10;
// int n, a[N], q, last[N];

// struct node{
//     int mn, x, ti;
//     int operator<(const node &e) const {
//         if(mn == e.mn) return ti > e.ti;
//         return mn < e.mn;
//     }
// }tr[N << 2];

// void up(int id){
//     tr[id] = min(tr[lson], tr[rson]);
// }

// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].mn = INT_MAX;
//         tr[id].x = l;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// int it = 1;

// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id].mn = v;
//         tr[id].ti = it;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(lson, l, mid, x, v);
//     else change(rson, mid + 1, r, x, v);
//     up(id);
// }

// signed main(){

//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);
//     cin >> q;
//     vector<array<int, 3>>qe(q);
//     for(int i = 0;i < q;i++){
//         cin >> qe[i][0] >> qe[i][1];
//         qe[i][2] = i + 1;
//     }
//     sort(qe.begin(), qe.end(), [](array<int,3>e1, array<int,3>e2)->int {return e1[1] < e2[1];});

//     vector<int>ans(q + 1);
//     for(auto [l, r, id] : qe){
//         while(it <= r){
//             change(1, 1, n, a[it], last[a[it]]);
//             last[a[it]] = it;
//             it++;
//         }
//         if(tr[1].mn < l) ans[id] = tr[1].x;
//         else ans[id] = 0;
//     }

//     for(int i = 1;i <= q;i++) cout << ans[i] << '\n';

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, m, a[N];

// void solve(){
//     cin >> n;
//     if(n == 3) cout << "Bob\n";
//     else cout << "Alice\n";

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
// const int N = 2e5 + 10;
// int n, m, a[N];

// void solve(){
//     cin >> n;
//     bool f = false;
//     int last = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(f){
//             if(a[i] >= last && a[i] <= a[1]){
//                 cout << 1;
//                 last = a[i];
//             }else cout << 0;
//         }else{
//             if(a[i] >= last){
//                 cout << 1;
//                 last = a[i];
//             }else if(a[i] <= a[1]){
//                 cout << 1;
//                 last = a[i];
//                 f = true;
//             }else cout << 0;
//         }
//     }
//     cout << '\n';
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
// const int N = 2e5 + 10;
// int n, m, a[N];

// int pow(int a, int b){
//     int ret = 1;
//     while(b--) ret *= a;
//     return ret;
// }

// void solve(){

//     int z[6] = {0}, f[6] = {0}, last[6] = {0};
//     string s;
//     cin >> s;
//     n = s.size();
//     s = ' ' + s;

//     int d = 0;
//     for(int i = 1;i <= n;i++) if(s[i] < 'E'){
//         d = 10000 - pow(10, s[i] - 'A');
//         for(int j = i + 1;j <= n;j++){
//             if(s[i] < s[j]){
//                 d += pow(10, s[i] - 'A') * 2;
//                 break;
//             }
//         }
//         break;
//     }
//     if(d == 0){
//         cout << n * 10000 << '\n';
//         return;
//     }
//     for(int i = 1;i <= n;i++){
//         int c = s[i] - 'A';
//         z[c] += pow(10, c);
//         last[c] = 0;
//         for(int j = 0;j < c;j++){
//             last[c] += z[j];
//             f[j] += z[j];
//             z[j] = 0;
//         }
//     }
//     int ans = 0;
//     for(int i = 0;i < 5;i++){
//         ans += z[i] - f[i];
//         d = max(d, last[i]);
//     }
//     ans += d;
//     cout << d << '\n';
//     cout << ans << '\n';
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
// const int N = 2e5 + 10;
// int n, m;
// int mp[10][10];
// char op1 = 0, op2 = 0;
// char op[5] = " +-*";
// char num[3] = "BC";
// string ans = "A=     "; //偶数位因子,奇数符号

// bool f = false;

// bool check(){
//     for(int i = 1;i <= 7;i++){
//         int A, B = mp[4][i], C = mp[4][i+1];
//         A = (ans[2] == 'B' ? B : C);
//         for(int j = 3;j <= 6 && ans[j] != ' ';j += 2){
//             if(ans[j] == '+'){
//                 A += (ans[j+1] == 'B' ? B : C);
//             }else if(ans[j] == '-'){
//                 A -= (ans[j+1] == 'B' ? B : C);
//             }else{
//                 A *= (ans[j+1] == 'B' ? B : C);
//             }
//         }
//         if(A != mp[3][i]) return false;
//     }
//     return true;
// }

// void dfs(int p){
//     if(f) return;
//     if(p & 1){ //枚举符号
//         for(int i = 1;i <= 3;i++){
//             ans[p] = op[i];
//             dfs(p + 1);
//             if(f) return;
//         }
//     }else{ //枚举因子
//         for(int i = 0;i <= 1;i++){
//             ans[p] = num[i];
//             if(check()){
//                 f = true;
//                 return;
//             }
//             if(p + 1 <= 6) dfs(p + 1);
//             if(f) return;
//         }
//     }
//     ans[p] = ' ';
// }

// void solve(){
//     for(int i = 1;i <= 7;i++) cin >> mp[3][i];
//     for(int i = 1;i <= 8;i++) cin >> mp[4][i];

//     dfs(2);

//     n = 6;
//     for(int i = 2;i >= 1;i--, n--){
//         for(int j = 1;j <= n;j++){
//             int B = mp[i+1][j], C = mp[i+1][j+1];
//             mp[i][j] = (ans[2] == 'B' ? B : C);
//             for(int x = 3;x <= 6 && ans[x] != ' ';x += 2){
//                 if(ans[x] == '+'){
//                     mp[i][j] += (ans[x+1] == 'B' ? B : C);
//                 }else if(ans[x] == '-'){
//                     mp[i][j] -= (ans[x+1] == 'B' ? B : C);
//                 }else{
//                     mp[i][j] *= (ans[x+1] == 'B' ? B : C);
//                 }
//             }
//         }
//     }

//     n = 5;
//     for(int i = 1;i <= 4;i++, n++){
//         for(int j = 1;j <= n;j++){
//             cout << mp[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     cout << ans;

// }

// signed main(){

//     IO;

//     int t = 1;
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
//     for(int i = 1;i <= m;i++){
//         int a, b;
//         cin >> a >> b;
//     }
//     if(m < n) cout << "YES\n";
//     else cout << "NO\n";
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
// const int N = 2e5 + 10;
// int n, m, a[N], b[N];

// void solve(){
//     cin >> n;
//     int ans = 0;
//     int mx = 0;
//     for(int i = 1;i <= n;i++) cin >> a[i], ans += a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i], ans += b[i], mx = max(mx, b[i]);
//     ans -= mx;
//     cout << ans << '\n';

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
// const int N = 2e5 + 10;
// int n, m, a[N];
// int num[N];

// void init(){
//     for(int i = 0;i <= n;i++) num[i] = 0;
// }

// bool check(int x){
//     int cur = num[1] - x;
//     for(int i = 2;i <= x;i++){
//         cur += num[i];
//         if(cur < 1) return false;
//         cur--;
//     }
//     return true;
// }

// void solve(){
//     cin >> n;
//     init();
//     for(int i = 1;i <= n;i ++ ){
//         cin >> a[i];
//         num[a[i]]++;
//     }
//     int l = 0, r = min(num[1], (n + 1) / 2);
//     while(l <= r){
//         int mid = l + r >> 1;
//         if(check(mid)) l = mid + 1;
//         else r = mid - 1;
//     }
//     cout << l - 1 << '\n';
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
// const int N = 2e5 + 10;
// int n, m, a[N];

// void solve(){
//     cin >> n;
//     m = (n + 1) * (n + 1) / 4;
//     cout << n - 1 << '\n';
//     for(int i = 1;i < n;i++){
//         cout << i << ' ' << i + 1 << ' ' << m-- << '\n';
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
// const int N = 2e5 + 10;
// int n, m, a[N], ti[N], mx[N], mn[N];
// vector<int>g[N];
// int ans[N];

// void dfs(int u, int fa){
//     for(auto v : g[u]) if(v != fa){
//         dfs(v, u);
//         mx[u] = max(mx[u], mx[v]);
//         mn[u] = min(mn[u], mn[v]);
//     }
//     ans[mn[u]]++;
//     ans[mx[u]]--;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i < n;i++){
//         int fa;
//         cin >> fa;
//         g[fa].push_back(i+1);
//         g[i+1].push_back(fa);
//     }
//     for(int i = 1;i <= n;i++){
//         int t;
//         cin >> t;
//         ti[t] = mx[t] = mn[t] = i;
//     }
//     dfs(1, 0);
//     for(int i = 1;i <= n;i++) {
//         ans[i] += ans[i-1];
//         cout << ans[i] << ' ';
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
// const int N = 1e5 + 10;
// int n;

// int rt, ls[N * 50], rs[N * 50], mn[N * 50], mn2[N * 50], tot;
// int tag[N * 50]; //是否存在
// const int ADD = 1, REMOVE = 2, REVERSE = 3;

// int getseg(int l, int r){
//     tot++;
//     mn[tot] = l;
//     mn2[tot] = r;
//     tag[tot] = 0;
//     return tot;
// }

// void settag(int id, int op, int l, int r){
//     if(op == REVERSE){
//         swap(mn2[id], mn[id]);
//         if(mn[id] == r) mn[id] = 1e18 + 1;
//     }else if(op == REMOVE){
//         mn2[id] = r;
//         mn[id] = l;
//     }else{
//         mn2[id] = l;
//         mn[id] = 1e18 + 1;
//     }
//     tag[id] = op;
// }

// void down(int id, int l, int r){
//     int mid = l + r >> 1;
//     if(!ls[id]) ls[id] = getseg(l, mid);
//     if(!rs[id]) rs[id] = getseg(mid + 1, r);
//     settag(ls[id], tag[id], l, mid);
//     settag(rs[id], tag[id], mid + 1, r);
//     tag[id] = 0;
// }

// void up(int id, int l, int r){
//     int mid = l + r >> 1;
//     if(!ls[id]) ls[id] = getseg(l, mid);
//     if(!rs[id]) rs[id] = getseg(mid + 1, r);
//     mn[id] = min(mn[ls[id]], mn[rs[id]]);
//     mn2[id] = min(mn2[ls[id]], mn2[rs[id]]);
// }

// void modify(int &id, int l, int r, int ql, int qr, int op){
//     if(!id) id = getseg(l, r);
//     if(ql <= l && r <= qr){
//         settag(id, op, l, r);
//         return;
//     }
//     if(tag[id]) down(id, l, r);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls[id], l, mid, ql, qr, op);
//     else if(ql > mid) modify(rs[id], mid + 1, r, ql, qr, op);
//     else modify(ls[id], l, mid, ql, qr, op), modify(rs[id], mid + 1, r, ql, qr, op);
//     up(id, l, r);
// }

// signed main(){

//     cin >> n;
//     while(n--){
//         int op, l, r;
//         cin >> op >> l >> r;
//         modify(rt, 1, 1e18, l, r, op);
//         cout << mn[rt] << '\n';
//     }

//     return 0;
// }
//

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e6 + 10;
// int n, m, a[N], q;

// struct node{
//     int mn, sum, len, tag;
//     node() : tag(0) {}
// }tr[N << 2];

// void up(int id){
//     tr[id].sum = tr[lson].sum + tr[rson].sum;
//     tr[id].len = tr[lson].len + tr[rson].len;
//     tr[id].mn = min(tr[lson].mn, tr[rson].mn);
// }

// void settag(int id, int l, int r, int x){
//     if(tr[id].len == 0) return;
//     if(l == r){
//         tr[id].mn = tr[id].sum = max(0ll, tr[id].sum - x);
//         if(tr[id].sum == 0){
//             tr[id].mn = LLONG_MAX;
//             tr[id].len = 0;
//         }
//     }else{
//         tr[id].sum -= tr[id].len * x;
//         tr[id].mn -= x;
//         tr[id].tag += x;
//     }
// }

// void down(int id, int l, int r){
//     int mid = l + r >> 1;
//     settag(lson, l, mid, tr[id].tag);
//     settag(rson, mid + 1, r, tr[id].tag);
//     tr[id].tag = 0;
// }

// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].len = 1;
//         tr[id].mn = tr[id].sum = a[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// int query(int id, int l, int r, int ql, int qr){
//     // if(l > r || l < 1 || r < 1 || l > n || r > n) return 0;
//     if(ql <= l && r <= qr) return tr[id].sum;
//     if(tr[id].tag) down(id, l, r);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
// }

// void modify(int id, int l, int r, int ql, int qr, int x){
//     // if(l > r || l < 1 || r < 1 || l > n || r > n) return;
//     if(ql <= l && r <= qr){
//         if(l == r || x < tr[id].mn){
//             settag(id, l, r, x);
//             return;
//         }
//     }
//     if(tr[id].tag) down(id, l, r);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, x);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, x);
//     else modify(lson, l, mid, ql, qr, x), modify(rson, mid + 1, r, ql, qr, x);
//     up(id);
// }

// void solve(){
//     cin >> n >> q;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);
//     while(q--){
//         int op, l, r;
//         cin >> op >> l >> r;
//         // if(l > r) swap(l, r);
//         if(op == 1){
//             int ret = 0;
//             if(l > r) ret = query(1, 1, n, l, n) + query(1, 1, n, 1, r);
//             else ret = query(1, 1, n, l, r);
//             cout << ret << '\n';
//         }else{
//             int x;
//             cin >> x;
//             if(l > r){
//                 modify(1, 1, n, l, n, x);
//                 modify(1, 1, n, 1, r, x);
//             }else modify(1, 1, n, l, r, x);
//         }
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
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e6 + 10;
// int n, m, a[N], q;

// struct node{
//     int mn, se, sum, len, tag, mtag, cnt;
//     node() : tag(0), mtag(0) {}
// }tr[N << 2];

// void up(int id){
//     tr[id].sum = tr[lson].sum + tr[rson].sum;
//     tr[id].len = tr[lson].len + tr[rson].len;
//     if(tr[lson].mn == tr[rson].mn){
//         tr[id].cnt = tr[lson].cnt + tr[rson].cnt;
//         tr[id].mn = tr[lson].mn;
//         tr[id].se = min(tr[lson].se, tr[rson].se);
//     }else if(tr[lson].mn < tr[rson].mn){
//         tr[id].cnt = tr[lson].cnt;
//         tr[id].mn = tr[lson].mn;
//         tr[id].se = min(tr[lson].se, tr[rson].mn);
//     }else{
//         tr[id].cnt = tr[rson].cnt;
//         tr[id].mn = tr[rson].mn;
//         tr[id].se = min(tr[rson].se, tr[lson].mn);
//     }
// }

// void settag(int id, int x){
//     tr[id].sum -= tr[id].len * x;
//     tr[id].mn -= x;
//     tr[id].se -= x;
//     tr[id].tag += x;
// }

// void down(int id){
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag = 0;
// }

// void setmax(int id){
//     tr[id].sum += (0 - tr[id].mn) * tr[id].cnt;
//     tr[id].mn = 0;
//     tr[id].se = max(tr[id].se, 0ll);
//     tr[id].mtag = 1;
//     if(tr[id].sum == 0) tr[id].cnt = tr[id].len;
// }

// void mdown(int id){
//     setmax(lson);
//     setmax(rson);
//     tr[id].mtag = 0;
// }

// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].len = tr[id].cnt = 1;
//         tr[id].se = tr[id].mn = tr[id].sum = a[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].sum;
//     if(tr[id].tag) down(id);
//     if(tr[id].mtag) mdown(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
// }

// void modify(int id, int l, int r, int ql, int qr, int x){
//     if(tr[id].sum == 0) return;
//     if(ql <= l && r <= qr){
//         settag(id, x);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     if(tr[id].mtag) mdown(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, x);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, x);
//     else modify(lson, l, mid, ql, qr, x), modify(rson, mid + 1, r, ql, qr, x);
//     up(id);
// }

// void getmax(int id, int l, int r, int ql, int qr){
//     if(tr[id].mn >= 0) return;
//     if(ql <= l && r <= qr){
//         if(tr[id].se > 0 || l == r || tr[id].cnt == tr[id].len){
//             setmax(id);
//             return;
//         }
//     }
//     if(tr[id].tag) down(id);
//     if(tr[id].mtag) mdown(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) getmax(lson, l, mid, ql, qr);
//     else if(ql > mid) getmax(rson, mid + 1, r, ql, qr);
//     else getmax(lson, l, mid, ql, qr), getmax(rson, mid + 1, r, ql, qr);
//     up(id);
// }

// void solve(){
//     cin >> n >> q;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);
//     while(q--){
//         int op, l, r;
//         cin >> op >> l >> r;
//         if(op == 1){
//             int ret = 0;
//             if(l > r) ret = query(1, 1, n, l, n) + query(1, 1, n, 1, r);
//             else ret = query(1, 1, n, l, r);
//             cout << ret << '\n';
//         }else{
//             int x;
//             cin >> x;
//             if(l > r){
//                 modify(1, 1, n, l, n, x);
//                 getmax(1, 1, n, l, n);
//                 modify(1, 1, n, 1, r, x);
//                 getmax(1, 1, n, 1, r);
//             }else modify(1, 1, n, l, r, x), getmax(1, 1, n, l, r);
//         }
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
// const int N = 1e6 + 10;
// int n, m, a[N], q;

// void solve(){
//     double a, b, c;
//     cin >> a >> b >> c;
//     double d = fabs(a - b) / 2.0;
//     cout << (int)ceil(d / c) << '\n';

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
// const int N = 110;
// int n, m, d[N], s[N], len[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++ ) cin >> d[i] >> s[i];
//     int mn = INT_MAX;
//     for(int i = 1;i <= n;i++ ){
//         len[i] = d[i] + (s[i] - 1) / 2;
//         mn = min(mn, len[i]);
//     }
//     cout << mn << '\n';

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
// const int N = 110;
// int n, m, d[N], s[N], len[N];

// void solve(){
//     int l, r;
//     cin >> l >> r;
//     for(int i = l;i <= r;i++){
//         for(int j = 2, len = sqrt(i);j <= len;j++){
//             if(i % j == 0){
//                 cout << j << ' ' << i - j << '\n';
//                 return;
//             }
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
// const int N = 110;
// int n, m, d[N], s[N], len[N];

// void solve(){
//     int x, y;
//     cin >> n >> x >> y;
//     int z = (x * y) / __gcd(x, y);
//     int ad = n / x;
//     int dv = n / y;
//     int sm = n / z;
//     ad -= sm;
//     dv -= sm;
//     int ans = 0;
//     ans -= (dv * (1 + dv)) / 2;
//     ans += (ad * (2 * n - ad + 1)) / 2;
//     cout << ans << '\n';
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
// const int N = 1e5 + 10;
// int n, m, a[N], q, pre[2][N], ans[2];

// void init(){
//     ans[0] = ans[1] = 0;
//     for(int i = 0;i <= n;i++) pre[0][i] = pre[1][i] = 0;
// }

// void solve(){

//     cin >> n;
//     init();
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     for(int i = 1;i <= n;i++){
//         pre[0][i] ^= pre[0][i-1];
//         pre[1][i] ^= pre[1][i-1];
//         pre[s[i] - '0'][i] ^= a[i];
//     }
//     ans[0] = pre[0][n];
//     ans[1] = pre[1][n];

//     cin >> q;
//     while(q--){
//         int op, l, r;
//         cin >> op >> l;
//         if(op == 1){
//             cin >> r;
//             ans[0] ^= pre[0][r] ^ pre[0][l-1] ^ pre[1][r] ^ pre[1][l-1];
//             ans[1] ^= pre[0][r] ^ pre[0][l-1] ^ pre[1][r] ^ pre[1][l-1];
//         }else{
//             cout << ans[l] << ' ';
//         }
//     }
//     cout << '\n';
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
// const int N = 1e5 + 10;
// int n, m, a[N], c[N], vis[N], d[N];

// void init(){
//     for(int i = 0;i <= n;i++){
//         d[i] = vis[i] = 0;
//     }
// }

// void solve(){

//     cin >> n;
//     init();
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         d[a[i]]++;
//     }
//     for(int i = 1;i <= n;i++) cin >> c[i];

//     for(int i = 1;i <= n;i++) if(d[i] == 0 && !vis[i]){
//         int cur = i;
//         while(d[cur] == 0){
//             cout << cur << ' ';
//             vis[cur] = 1;
//             d[a[cur]]--;
//             cur = a[cur];
//         }
//     }
//     for(int i = 1;i <= n;i++) if(!vis[i]){
//         int mn = i, cur = a[i];
//         while(cur != i){
//             if(c[cur] < c[mn]) mn = cur;
//             cur = a[cur];
//         }
//         cur = a[mn];
//         while(1){
//             cout << cur << ' ';
//             vis[cur] = 1;
//             if(cur == mn) break;
//             cur = a[cur];
//         }
//     }

//     cout << '\n';
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
// const int N = 2e5 + 10;
// int n, a[N], pre[N], pro[N] = {1};

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//     }

//     int l = 1, r = n;
//     while(l < n && a[l] == 1) l++;
//     while(r > 1 && a[r] == 1) r--;
//     int prod = 1;
//     for(int i = l;i <= r;i++){
//         prod *= a[i];
//         if(prod > 1e9){
//             cout << l << ' ' << r << '\n';
//             return;
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         pre[i] = pre[i-1] + a[i];
//         pro[i] = pro[i-1] * a[i];
//     }

//     vector<int>num;
//     for(int i = l;i <= r;i++)
//         if(a[i] > 1) num.push_back(i);

//     int L = 1, R = 1, ans = 0;
//     for(int i = 0;i < num.size();i++){
//         for(int j = i;j < num.size();j++){
//             int d = (pro[num[j]] / pro[num[i]-1]) - (pre[num[j]] - pre[num[i]-1]);
//             if(d > ans){
//                 ans = d;
//                 L = num[i];
//                 R = num[j];
//             }
//         }
//     }

//     cout << L << ' ' << R << '\n';
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
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 1e5 + 10;
// int B;
// int n, q, st[N], d[N], cnt[N], vis[N];
// char ch[N];
// int fa[322][N];

// int find(int id, int x){
//     return fa[id][x] == x ? x : fa[id][x] = find(id, fa[id][x]);
// }

// void merg(int id, int a, int b){
//     a = find(id, a);
//     b = find(id, b);
//     if(a == b) return;
//     if(a > b) swap(a, b);
//     fa[id][a] = b;
// }

// void solve()
// {
//     for (int i = 1; i <= 320; i++)
//         for (int j = 1; j < N; j++)
//             fa[i][j] = j;
//     string s;
//     cin >> s;
//     n = s.size();
//     s = ' ' + s;
//     B = sqrt(n) + 1;
//     cin >> q;
//     for (int i = q; i >= 1; i--)
//     {
//         cin >> st[i] >> d[i] >> cnt[i] >> ch[i];
//     }
//     for (int i = 1; i <= q; i++)
//     {
//         if (d[i] >= B)
//         {
//             for (int j = st[i], len = min(n, st[i] + cnt[i] * d[i]); j <= len; j += d[i])
//                 if (!vis[j])
//                 {
//                     vis[j] = 1;
//                     s[j] = ch[i];
//                 }
//         }
//         else
//         {
//             if(!vis[st[i]]){
//                 vis[st[i]] = 1;
//                 s[st[i]] = ch[i];
//             }
//             for (int j = st[i] + d[i], len = min(n, st[i] + cnt[i] * d[i]); j <= len; j += d[i]){
//                 merg(d[i], j - d[i], j);
//                 if (!vis[j])
//                 {
//                     vis[j] = 1;
//                     s[j] = ch[i];
//                 }else{
//                     j = find(d[i], j);
//                 }
//             }
//         }
//     }
//     for(int i = 1;i < s.size();i++) cout << s[i];
// }

// signed main()
// {
//     IO;

//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }




// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e5 + 10;
// int n, m, w[N];
// vector<int>g[N];

// int par[N], dep[N], son[N], top[N], id[N], siz[N], tot, tr_data[N];

// void pre_dfs(int u, int fa){
//     dep[u] = dep[fa] + 1;
//     par[u] = fa;
//     siz[u] = 1;
//     for(auto v : g[u]) if(v != fa){
//         pre_dfs(v, u);
//         siz[u] += siz[v];
//         if(siz[son[u]] < siz[v]) son[u] = v;
//     }
// }

// int mxtr[N];

// void dfs(int u, int tp){
//     top[u] = tp;
//     id[u] = ++tot;
//     mxtr[u] = max(mxtr[u], tot);
//     tr_data[tot] = w[u];
//     if(son[u]) {
//         dfs(son[u], tp);
//         mxtr[u] = max(mxtr[u], mxtr[son[u]]);
//     }
//     else return;

//     for(auto v : g[u]) if(v != par[u] && v != son[u]){
//         dfs(v, v);
//         mxtr[u] = max(mxtr[u], mxtr[v]);
//     }
// }

// struct node{
//     int sum, tag, len;
// }tr[N << 2];

// void up(int id){
//     tr[id].sum = tr[lson].sum + tr[rson].sum;
//     tr[id].len = tr[lson].len + tr[rson].len;
// }

// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].sum = tr_data[l];
//         tr[id].len = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// void settag(int id, int x){
//     tr[id].sum += x * tr[id].len;
//     tr[id].tag += x;
// }

// void down(int id){
//     settag(lson, tr[id].tag);
//     settag(rson, tr[id].tag);
//     tr[id].tag = 0;
// }

// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].sum;
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
// }

// void modify(int id, int l, int r, int ql, int qr, int x){
//     if(ql <= l && r <= qr){
//         settag(id, x);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, x);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, x);
//     else modify(lson, l, mid, ql, qr, x) , modify(rson, mid + 1, r, ql, qr, x);
//     up(id);
// }

// int line_query(int x){
//     int ret = 0;
//     while(x){
//         // cout << id[top[x]] << ' ' << id[x] << '\n';
//         ret += query(1, 1, n, id[top[x]], id[x]);
//         x = par[top[x]];
//     }
//     return ret;
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) cin >> w[i];
//     for(int i = 1;i < n;i++){
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }

//     pre_dfs(1, 0);
//     dfs(1, 1);
//     build(1, 1, n);

//     while(m--){
//         int op, x, a;
//         cin >> op >> x;
//         if(op == 1){
//             cin >> a;
//             // cout << id[x] << '\n';
//             modify(1, 1, n, id[x], id[x], a);
//             // cout << op << ' ' << x << ' ' << a << '\n';
//         }else if(op == 2){
//             cin >> a;
//             // cout << id[x] << ' ' << mxtr[x] << '\n';
//             modify(1, 1, n, id[x], mxtr[x], a);
//             // cout << op << ' ' << x << ' ' << a << '\n';
//         }else{
//             cout << line_query(x) << '\n';
//             // cout << op << ' ' << x << '\n';
//         }
//     }
//     // for(int i = 1;i <= n;i++){
//     //     cout << id[i] << ' ';
//     // }
//     // cout << '\n';
//     // for(int i = 1;i <= n;i++){
//     //     cout << mxtr[i] << ' ';
//     // }
// }

// signed main()
// {
//     IO;

//     int t = 1;
//     // cin >> t;
//     while (t--)
//         solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long 
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e5 + 10;
// int n, w[N];
// vector<array<int, 3>>g[N];

// int par[N], dep[N], siz[N], son[N], id[N], tr_data[N], tot, top[N], seg[N];

// void pre_dfs(int u, int fa){
//     dep[u] = dep[fa] + 1;
//     siz[u] = 1;
//     par[u] = fa;
//     for(auto [v, s, id] : g[u]) if(v != fa){
//         w[v] = s;
//         seg[id] = v;
//         pre_dfs(v, u);
//         siz[u] += siz[v];
//         if(siz[son[u]] < siz[v]) son[u] = v;
//     }
// }

// void dfs(int u, int tp){
//     top[u] = tp;
//     id[u] = ++tot;
//     tr_data[tot] = w[u];
//     if(son[u]) dfs(son[u], tp);
//     else return;

//     for(auto [v, s, id] : g[u]) if(v != par[u] && v != son[u])
//         dfs(v, v);
// }   

// int mx[N << 2];

// void up(int id){
//     mx[id] = max(mx[lson], mx[rson]);
// }

// void build(int id, int l, int r){
//     if(l == r){
//         mx[id] = tr_data[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         mx[id] = v;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(lson, l, mid, x, v);
//     else change(rson, mid + 1, r, x, v);
//     up(id);
// }

// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return mx[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return max(query(lson, l, mid, ql, qr), query(rson, mid + 1, r, ql, qr));
// }

// int line_query(int u, int v){
//     int ret = 0;
//     while(top[u] != top[v]){
//         if(dep[top[u]] < dep[top[v]]) swap(u, v);
//         ret = max(ret, query(1, 1, n, id[top[u]], id[u]));
//         u = par[top[u]];
//     }
//     if(u == v) return ret;
//     if(dep[u] < dep[v]) swap(u, v);
//     ret = max(ret, query(1, 1, n, id[v] + 1, id[u]));
//     return ret;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i < n;i++){
//         int a, b, w;
//         cin >> a >> b >> w;
//         g[a].push_back({b, w, i});
//         g[b].push_back({a, w, i});
//     }

//     pre_dfs(1, 0);
//     dfs(1, 1);
//     build(1, 1, n);

//     string s;
//     while(cin >> s, s != "DONE"){
//         int a, b;
//         cin >> a >> b;
//         if(s == "CHANGE"){
//             change(1, 1, n, id[seg[a]], b);
//         }else{
//             cout << line_query(a, b) << '\n';
//         }
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
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 5e5 + 10;
// int n, m;
// vector<int>g[N];

// int dep[N], siz[N], par[N], top[N], son[N], id[N], tot, mxson[N];

// void pre_dfs(int u, int fa){
//     dep[u] = dep[fa] + 1;
//     par[u] = fa;
//     siz[u] = 1;
//     for(auto v : g[u]) if(v != fa){
//         pre_dfs(v, u);
//         siz[u] += siz[v];
//         if(siz[son[u]] < siz[v]) son[u] = v;
//     }
// }

// void dfs(int u, int tp){
//     top[u] = tp;
//     mxson[u] = id[u] = ++tot;
//     if(son[u]) dfs(son[u], tp), mxson[u] = max(mxson[u], mxson[son[u]]);
//     else return;

//     for(auto v : g[u]) if(v != par[u] && v != son[u])
//         dfs(v, v), mxson[u] = max(mxson[u], mxson[v]);
// }

// int same[N << 2], tr[N << 2], tag[N << 2];

// void up(int id){
//     same[id] = same[lson] && same[rson] && (tr[lson] == tr[rson]);
//     tr[id] = tr[lson];
// }

// void build(int id, int l, int r){
//     if(l == r){
//         same[id] = true;
//         tr[id] = 0;
//         return;
//     }   
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// void settag(int id, int v){
//     same[id] = true;
//     tr[id] = v;
//     tag[id] = v + 1;
//     // cout << id << ' ' << v << ' ' << tag[id] << '\n';
// }

// void down(int id){
//     settag(lson, tag[id] - 1);
//     settag(rson, tag[id] - 1);
//     tag[id] = 0;
// }

// void modify(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr){
//         // cout << l << ' ' << r << ' ' << id << '\n';
//         settag(id, v);
//         return;
//     }
//     if(tag[id]) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr, v);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr, v);
//     else modify(lson, l, mid, ql, qr, v), modify(rson, mid + 1, r, ql, qr, v);
//     up(id);
// }

// int query(int id, int l, int r, int x){
//     if(same[id]) return tr[id];
//     if(tag[id]) down(id);
//     int mid = l + r >> 1;
//     if(x <= mid) return query(lson, l, mid, x);
//     else return query(rson, mid + 1, r, x);
// }

// void line_modify(int u, int v){
//     while(u){
//         modify(1, 1, n, id[top[u]], id[u], v);
//         u = par[top[u]];
//     }
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i < n;i++){
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }

//     pre_dfs(1, 0);
//     dfs(1, 1);
//     build(1, 1, n);
    
//     // for(int i = 1;i <= n;i++) cout << query(1, 1, n, id[i]) << ' ';
//     // cout << '\n';
//     // modify(1, 1, n, 1, 5, 1);
//     // // cout << tag[1] << '\n';
//     // modify(1, 1, n, 1, 3, 1);
//     // for(int i = 1;i <= n;i++) cout << query(1, 1, n, id[i]) << ' ';
//     // cout << '\n';



//     cin >> m;
//     while(m--){
//         int op, u;
//         cin >> op >> u;
//         if(op == 1){
//             modify(1, 1, n, id[u], mxson[u], 1);
//         }else if(op == 2){
//             line_modify(u, 0);
//         }else{
//             cout << query(1, 1, n, id[u]) << '\n';
//         }
//     }
//     // for(int i = 1;i <= n;i++) cout << id[i] << ' ';
//     // cout << '\n';
//     // for(int i = 1;i <= n;i++) cout << mxson[i] << ' ';
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
// #define lson id << 1
// #define rson id << 1 | 1
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m;
// vector<array<int, 3>>g[N];

// int dep[N], siz[N], par[N], son[N], top[N], tr_data[N], id[N], tot, seg[N], w[N];

// void dfs1(int u, int fa){
//     dep[u] = dep[fa] + 1;
//     siz[u] = 1;
//     par[u] = fa;
//     for(auto [v, s, id] : g[u]) if(v != fa){
//         dfs1(v, u);
//         w[v] = s;
//         seg[id] = v;
//         siz[u] += siz[v];
//         if(siz[son[u]] < siz[v]) son[u] = v;
//     }
// }

// void dfs2(int u, int tp){
//     top[u] = tp;
//     id[u] = ++tot;
//     tr_data[tot] = w[u];
//     if(son[u]) dfs2(son[u], tp);
//     else return;

//     for(auto [v, s, id] : g[u]) if(v != par[u] && v != son[u]) 
//         dfs2(v, v);
// }

// struct node{
//     int sum, mn, mx, tag, pos, neg;
// }tr[N << 2];

// void up(int id){
//     tr[id].sum = tr[lson].sum + tr[rson].sum;
//     tr[id].pos = tr[lson].pos + tr[rson].pos;
//     tr[id].neg = tr[lson].neg + tr[rson].neg;
//     tr[id].mn = min(tr[lson].mn, tr[rson].mn);
//     tr[id].mx = max(tr[lson].mx, tr[rson].mx);
// }

// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].sum = tr[id].mn = tr[id].mx = tr_data[l];
//         if(tr_data[l] > 0) tr[id].pos = tr_data[l];
//         if(tr_data[l] < 0) tr[id].neg = tr_data[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }

// void settag(int id){
//     swap(tr[id].neg, tr[id].pos);
//     swap(tr[id].mn, tr[id].mx);
//     tr[id].neg *= -1;
//     tr[id].pos *= -1;
//     tr[id].mx *= -1;
//     tr[id].mn *= -1;
//     tr[id].sum = tr[id].pos + tr[id].neg;
//     tr[id].tag ^= 1;
// }

// void down(int id){
//     settag(lson);
//     settag(rson);
//     tr[id].tag = 0;
// }

// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id].mn = tr[id].mx = tr[id].sum = v;
//         tr[id].pos = tr[id].neg = 0;
//         if(v > 0) tr[id].pos = v;
//         if(v < 0) tr[id].neg = v;
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(x <= mid) change(lson, l, mid, x, v);
//     else change(rson, mid + 1, r, x, v);
//     up(id);
// }

// void modify(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         settag(id);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr);
//     else modify(lson, l, mid, ql, qr), modify(rson, mid + 1, r, ql, qr);
//     up(id);
// }

// void line_reverse(int u, int v){
//     while(top[u] != top[v]){
//         if(dep[top[u]] < dep[top[v]]) swap(u, v);
//         modify(1, 1, n, id[top[u]], id[u]);
//         u = par[top[u]];
//     }
//     if(u != v){
//         if(dep[u] < dep[v]) swap(u, v);
//         modify(1, 1, n, id[v] + 1, id[u]);
//     }
// }

// int query_sum(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].sum;
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query_sum(lson, l, mid, ql, qr);
//     else if(ql > mid) return query_sum(rson, mid + 1, r, ql, qr);
//     else return query_sum(lson, l, mid, ql, qr) + query_sum(rson, mid + 1, r, ql, qr);
// }

// int getsum(int u, int v){
//     int ret = 0;
//     while(top[u] != top[v]){
//         if(dep[top[u]] < dep[top[v]]) swap(u, v);
//         ret += query_sum(1, 1, n, id[top[u]], id[u]);
//         u = par[top[u]];
//     }
//     if(u == v) return ret;
//     if(dep[u] < dep[v]) swap(u, v);
//     ret += query_sum(1, 1, n, id[v] + 1, id[u]);
//     return ret;
// }

// int query_max(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].mx;
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query_max(lson, l, mid, ql, qr);
//     else if(ql > mid) return query_max(rson, mid + 1, r, ql, qr);
//     else return max(query_max(lson, l, mid, ql, qr), query_max(rson, mid + 1, r, ql, qr));
// }

// int getmax(int u, int v){
//     int ret = -INT_MAX;
//     while(top[u] != top[v]){
//         if(dep[top[u]] < dep[top[v]]) swap(u, v);
//         ret = max(ret, query_max(1, 1, n, id[top[u]], id[u]));
//         u = par[top[u]];
//     }
//     if(u == v) return ret;
//     if(dep[u] < dep[v]) swap(u, v);
//     ret = max(ret, query_max(1, 1, n, id[v] + 1, id[u]));
//     return ret;
// }

// int query_min(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].mn;
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query_min(lson, l, mid, ql, qr);
//     else if(ql > mid) return query_min(rson, mid + 1, r, ql, qr);
//     else return min(query_min(lson, l, mid, ql, qr), query_min(rson, mid + 1, r, ql, qr));
// }

// int getmin(int u, int v){
//     int ret = INT_MAX;
//     while(top[u] != top[v]){
//         if(dep[top[u]] < dep[top[v]]) swap(u, v);
//         ret = min(ret, query_min(1, 1, n, id[top[u]], id[u]));
//         u = par[top[u]];
//     }
//     if(u == v) return ret;
//     if(dep[u] < dep[v]) swap(u, v);
//     ret = min(ret, query_min(1, 1, n, id[v] + 1, id[u]));
//     return ret;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i < n;i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         u++;
//         v++;
//         g[u].push_back({v, w, i});
//         g[v].push_back({u, w, i});
//     }

//     dfs1(1, 0);
//     dfs2(1, 1);
//     build(1, 1, n);

//     cin >> m;
//     while(m--){
//         int a, b;
//         string s;
//         cin >> s >> a >> b;
//         a++;
//         b++;
//         if(s == "C"){
//             a--;
//             b--;
//             change(1, 1, n, id[seg[a]], b);
//         }else if(s == "N"){ 
//             line_reverse(a, b);
//         }else if(s == "SUM"){
//             cout << getsum(a, b) << '\n';
//         }else if(s == "MAX"){
//             cout << getmax(a, b) << '\n';
//         }else{
//             cout << getmin(a, b) << '\n';
//         }   
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
// const int N = 2e5 + 10;
// int n, m, a[N];


// void solve(){
//     cin >> n;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] == i) ans++;
//     }
//     cout << (ans + 1)/2 << '\n';
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
//     cin >> n;
//     if(n == 2) cout << "2\n";
//     else if(n < 2e5 && isprime[n]) cout << "1\n";
//     else{
//         if(n <= 1e4){
//             int len = 0, ans = 0;
//             for(int i = 1;i <= n;i++){
//                 if(n % i == 0) len++;
//                 else{
//                     if(n > 3){
//                         cout << len << '\n';
//                         return;
//                     }else{
//                         ans = len;
//                         len = 0;
//                     }
//                 }
//             }
//             cout << max(ans, len) << '\n';
//         }else{
//             int len = 0, ans = 0;
//             for(int i = 1;i <= 1e4;i++){
//                 if(n % i == 0) len++;
//                 else{
//                     if(n > 3){
//                         ans = max(ans, len);
//                         break;
//                     }else{
//                         ans = len;
//                         len = 0;
//                     }
//                 }
//             }
//             len = 1;
//             for(int i = 1;i <= cnt;i++){
//                 if(n % prime[i] == 0){
//                     len = 1;
//                     for(int j = prime[i] + 1, sq = sqrt(n);j <= sq;j++){
//                         if(n % j == 0){
//                             len++;
//                         }else{
//                             cout << max(len, ans) << endl;
//                             return;
//                         }
//                     }
//                 }
//             }
//             cout << max(ans, len) << endl;
//         }
//     }
// }

// signed main(){

//     IO;

//     euler();
//     // cout << cnt << endl;
//     // for(int i = 1;i <= 10;i++) cout << prime[i] << ' ';


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


// void solve(){
//     cin >> n;
//     int z = 0, f = 0, mx = 1, mn = 1, zs = 0, fs = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] > a[mx]) mx = i;
//         if(a[i] < a[mn]) mn = i;
//         if(a[i] > 0) z = i, zs++;
//         if(a[i] < 0) f = i, fs++;
//     }
//     if(z == 0 && f == 0){
//         cout << "0\n";
//         return;
//     }

//     if(f == 0){
//         cout << n - 1 << '\n';
//         for(int i = 2;i <= n;i++) cout << i << ' ' << i - 1 << '\n';
//     }else if(z == 0){
//         cout << n - 1 << '\n';
//         for(int i = n - 1;i >= 1;i--) cout << i << ' ' << i + 1 << '\n';
//     }else{
//         int cntz = fs + n - 1, cntf = zs + n - 1;
//         int ztm = a[mx], ftm = a[mn];
//         while(ztm < -a[mn]){
//             ztm *= 2;
//             cntz++;
//         }
//         while(-ftm < a[mx]){
//             ftm *= 2;
//             cntf++;
//         }
//         // cout << cntz << ' ' << cntf << endl;
//         // cout << ztm << ' ' << ftm << endl;

//         if(cntz < cntf){
//             cout << cntz << endl;
//             while(a[mx] < -a[mn]){
//                 a[mx] *= 2;
//                 cout << mx << ' ' << mx << endl;
//             }
//             for(int i = 1;i <= n;i++) if(a[i] < 0){
//                 cout << i << ' ' << mx << endl;
//             }
//             for(int i = 2;i <= n;i++) cout << i << ' ' << i - 1 << '\n';
//         }else{
//             cout << cntf << endl;
//             while(-a[mn] < a[mx]){
//                 a[mn] *= 2;
//                 cout << mn << ' ' << mn << endl;
//             }
//             for(int i = 1;i <= n;i++) if(a[i] > 0){
//                 cout << i << ' ' << mn << endl;
//             }
//             for(int i = n - 1;i >= 1;i--) cout << i << ' ' << i + 1 << '\n';
//         }
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
// int n, m, a[N], pre[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i], pre[i] = a[i] + pre[i-1];
//     bitset<N>st;
//     st[1] = 1;
//     int ans = a[1];
//     for(int i = 1;i <= n;i++){
//         st |= (st << a[i]);
//         if(st[i]){
//             ans = max(ans, pre[i] - i + 1);
//             st[i] = 0;
//         }
//     }
//     for(int i = n + 1;i <= 2 * n;i++){
//         if(st[i]){
//             ans = max(ans, pre[n] - i + 1);
//             break;
//         }
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



// #include<stdio.h>

// #include<math.h>

// int happy(int year, int month, int day){
//     if(month < 1 || month > 12) return -1;
//     auto leap = [](int y)->bool {
//         return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
//     };
//     if(day < 1) return -2;
//     if(month == 4 || month == 6 || month == 9 || month == 11){
//         if(day > 30) return -2;
//     }else if(month == 2){
//         if(leap(year)){
//             if(day > 29) return -2;
//         }else{
//             if(day > 28) return -2;
//         }
//     }else{
//         if(day > 31) return -2;
//     }
//     return 1;
// }

// int main() {

//         char ch;

//         int year, month, day;

// while (scanf("%d%c%d%c%d", &year, &ch, &month, &ch, &day) != EOF) {

// printf("%d ", happy(year, month, day));

// }

// return 0;

// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n);
//     for(auto& e : a) cin >> e;
//     vector<int>ans;
//     for(int i = 0;i < n;i++){
//         bool ri = false, le = false;
//         for(int j = i + 1;j < n;j++){
//             if(a[j] < a[i]){
//                 ri = true;
//                 break;
//             }
//         }
//         if(!ri)
//             for(int j = i - 1;j >= 0;j--){
//                 if(a[j] > a[i]){
//                     le = true;
//                     break;
//                 }
//             }
//         if(!ri && !le) ans.push_back(a[i]);
//     }
//     cout << ans.size() << '\n';
//     for(int i = 0;i < ans.size();i++){
//         cout << ans[i];
//         if(i + 1 < ans.size()) cout << ' ';
//     }
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     for(int i = 1;i <= t;i++){
//         solve();
//         if(i < t) cout << '\n';
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>g(n);
//     vector<int>c(n);
//     for(auto& e : g) cin >> e;
//     for(auto& e : c) cin >> e;

//     for(int i = 0;i < n;i++){
//         bool ans = true;
//         for(int j = i, cnt = 0, sum = 0; cnt <= n;j = (j + 1) % n, cnt++){  
//             sum += g[j] - c[j];
//             if(sum < 0){
//                 ans = false;
//                 break;
//             }
//         }
//         if(ans){
//             cout << i << '\n';
//             return;
//         }
//     }
//     cout << "-1\n";
// }

// signed main(){

//     int t = 1;
//     // cin >> t;
//     for(int i = 1;i <= t;i++){
//         solve();
//     }

//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lson id << 1
#define rson id << 1 | 1
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 5e4 + 10;
const int mod = 1e9 + 7;
int n, m, q, a[N], vis[N], ans[N];


struct node{
    int val[4]; //S, A2, A, len

    node() {
        for(int i = 0; i < 3;i++) val[i] = 0;
        val[3] = 1;
    }
    node(int x) {
        val[0] = x * x;
        val[1] = val[0];
        val[2] = x;
        val[3] = 1;
    }
    node(int s, int a2, int a, int le) {
        val[0] = s;
        val[1] = a2;
        val[2] = a;
        val[3] = le;
    }

    node operator+(const node& e) const{
        node ret(*this);
        for(int i = 0;i < 4;i++) ret.val[i] += e.val[i];
        return ret;
    }
};

struct Mat{
    int mp[4][4];
    Mat() {
        memset(mp, 0, sizeof(mp));
    }
    Mat(int x) : Mat() {
        mp[0][0] = mp[0][1] = mp[1][1] = mp[2][2] = mp[3][3] = 1;
        mp[0][2] = mp[1][2] = 2 * x;
        mp[0][3] = mp[1][3] = x * x;
        mp[2][3] = x;
    }
    
    void init(){
        for(int i = 0; i < 4;i++)
            for(int j = 0;j < 4;j++) 
                mp[i][j] = i == j;
    }

    node operator*(const node& e) const {
        node ret(0, 0, 0, e.val[3]);
        for(int i = 0; i < 4;i++){
            for(int j = 0;j < 4;j++){
                ret.val[i] = (ret.val[i] + mp[i][j] * e.val[j]) % mod;
            }
        }
        return ret;
    }

    Mat operator*(const Mat& e) const{
        Mat ret;
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 4;j++){
                for(int k = 0;k < 4;k++){
                    ret.mp[i][j] = (ret.mp[i][j] + mp[i][k] * e.mp[k][j]) % mod;
                }
            }
        }
        return ret;
    }
};

Mat tag[N << 2];
node tr[N << 2];

bool tag_act[N << 2] = {0};

void up(int id){
    tr[id] = tr[lson] + tr[rson];
}

void build(int id, int l, int r){
    tag[id].init();
    if(l == r){
        tr[id] = node(a[l]);
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(id);
}

void settag(int id, const Mat& mt){
    tr[id] = mt * tr[id];
    tag[id] = mt * tag[id];
    tag_act[id] = true;
}

void down(int id){
    settag(lson, tag[id]);
    settag(rson, tag[id]);
    tag[id].init();
    tag_act[id] = false;
}

void modify(int id, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        // cerr << 9;
        settag(id, Mat(v));
        return;
    }
    if(tag_act[id]) down(id);
    int mid = l + r >> 1;
    if(qr <= mid) modify(lson, l, mid, ql, qr, v);
    else if(ql > mid) modify(rson, mid + 1, r, ql, qr, v);
    else modify(lson, l, mid, ql, qr, v), modify(rson, mid + 1, r, ql, qr, v);
    up(id);
}

int query(int id, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return tr[id].val[2] % mod;
    if(tag_act[id]) down(id);
    int mid = l + r >> 1;
    if(qr <= mid) return query(lson, l, mid, ql, qr) % mod;
    else if(ql > mid) return query(rson, mid + 1, r, ql, qr) % mod;
    else return (query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr)) % mod;
}

struct quer{
    int ti, l, r, id;
    bool operator<(const quer& e) const {
        return ti < e.ti;
    }
};

signed main(){

    IO;

    cin >> n >> m >> q;
    vector<array<int, 3>>modi(m + 1);
    vector<quer>qr;
    for(int i = 1;i <= n;i++) cin >> a[i];

    build(1, 1, n);

    for(int i = 1;i <= m;i++){
        cin >> modi[i][0] >> modi[i][1] >> modi[i][2];
    }
    for(int i = 1;i <= q;i++){
        int l, r, x, y;
        cin >> l >> r >> x  >> y;
        if(x == 0) vis[i] = 1;
        else qr.push_back({x - 1, l, r, i});
        qr.push_back({y, l, r, i});
    }
    sort(qr.begin(), qr.end());

    // cout << query(1, 1, n, 1, n) << '\n';
    // modify(1, 1, n, 1, 2, 1);
    // modify(1, 1, n, 3, n, 0);
    // cout << query(1, 1, n, 1, n) << '\n';
    // modify(1, 1, n, 1, n, 0);
    // cout << query(1, 1, n, 1, n) << '\n';

    for(int i = 1;i <= m;i++){
        auto [l, r, x] = modi[i];
        modify(1, 1, n, l, r, x);
        if(l > 1) modify(1, 1, n, 1, l - 1, 0);
        if(r < n) modify(1, 1, n, r + 1, n, 0);
        cout << i << ' ' << query(1, 1, n, 2, 2) << '\n';
    }

    // int it = 0;
    // for(int i = 0;i <= m;i++){
    //     auto [l, r, x] = modi[i];
    //     // cerr << 9;
    //     if(l){
    //         modify(1, 1, n, l, r, x);
    //         // if(l > 1) modify(1, 1, n, 1, l - 1, 0);
    //         // if(r < n) modify(1, 1, n, r + 1, n, 0);
    //     }
    //     // cout << l << ' ' << r << ' ' << x << '\n';
    //     while(it < qr.size() && qr[it].ti == i){
    //         auto [ti, l, r, id] = qr[it++];
    //         cout << ti << ' ' << l << ' ' << r << ' ' << id << '\n';
    //         int val = query(1, 1, n, l, r);
    //         if(vis[id]) ans[id] += val;
    //         else{
    //             vis[id] = 1;
    //             ans[id] -= val;
    //         }
    //     }
    // }

    // for(int i = 1;i <= q;i++)
    //     cout << ans[i] % mod << '\n';

    return 0;
}