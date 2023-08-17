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