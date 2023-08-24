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



#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, a[N];

void solve(){
    
}

signed main(){

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}