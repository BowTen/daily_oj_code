// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// // #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n

// const int N = 2e6 + 10;

// int bitcount(int x){
//     int ret = 0;
//     while(x){
//         ret += (x & 1);
//         x >>= 1;
//     }
//     return ret;
// }

// void play(int x){
//     for(int i = 62;i >= 0;i--) if((x >> i) & 1){
//         cout << (1ll << i) << ' ' << (x - (1ll << i)) << endl;
//         return;
//     }
// }

// void solve(){
//     int n;
//     cin >> n;

//     if(bitcount(n) % 2 == 0){
//         cout << "first" << endl;    
//         play(n);
//     }else{
//         cout << "second" << endl;
//     }

//     int a, b;
//     while(cin >> a >> b, a || b){
//         if(bitcount(a) % 2 == 0) n = a;
//         else n = b;
//         play(n);
//     }

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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int inf = 0x3f3f3f3f3f3f3f3f;

// int op[2][2] = {1, 1, 2, 0};

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>>mp(n+5, vector<int>(m+5)), vis(n+5, vector<int>(m+5));
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < m;j++){
//             cin >> mp[i][j];
//         }
//     }

//     int ans = inf;

//     queue<array<int, 3>>que;
//     que.push({0, 0, 0});
//     vis[0][0] = 1;

//     while(que.size()){
//         auto [x, y, d] = que.front();
//         que.pop();
//         if(y == m-2){
//             int rx = x - d;
//             while(rx < 0) rx += n;
//             ans = min(ans, d + min(n - rx, rx + 2));
//             break;
//         }
//         for(int i = 0;i < 2;i++){
//             int nx = (x + op[i][0] + n) % n, ny = (y + op[i][1] + m) % m;
//             if(i == 1){
//                 if(mp[(x+1)%n][y]) continue;
//             }
//             if(!vis[nx][ny] && mp[nx][ny] == 0){
//                 que.push({nx, ny, d + 1});
//                 vis[nx][ny] = 1;
//             }
//         }
//     }

//     if(ans == inf) cout << -1 << endl;
//     else cout << ans << endl;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int inf = 0x3f3f3f3f3f3f3f3f;

// int op[2][2] = {1, 1, 2, 0};

// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<int>>g(n+5);
//     for(int i = 2, v;i <= n;i++){
//         cin >> v;
//         g[v].push_back(i);
//     }

//     string c;
//     cin >> c;
//     c = ' ' + c;

//     vector<array<int, 2>>f(n+5); // s  p

//     auto dfs = [&](auto self, int u) -> void {
//         for(auto v : g[u]) {
//             self(self, v);
//             f[u][0] += min(f[v][0], f[v][1] + 1);
//             f[u][1] += min(f[v][0] + 1, f[v][1]);
//         }
//         if(c[u] == 'S') f[u][1] = inf;
//         else if(c[u] == 'P') f[u][0] = inf;
//     };

//     dfs(dfs, 1);

//     cout << min(f[1][0], f[1][1]) << endl;

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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int inf = 0x3f3f3f3f3f3f3f3f;

// int op[4][2] = {
//     1, 1,
//     1, -1,
//     -1, 1,
//     -1, -1
// };
// vector<vector<int>>mp(8, vector<int>(8));

// int check(int f){
//     for(int i = 2;i < 7;i++){
//         for(int j = 2;j < 7;j++) if(((i + j) % 2) == f && mp[i][j]) {
//             int fg = 1;
//             for(int k = 0;k < 4;k++){
//                 int x = i + op[k][0];
//                 int y = j + op[k][1];
//                 if(!mp[x][y]){
//                     fg = 0;
//                     break;
//                 } 
//             }
//             if(fg) return 0;
//         }
//     }
//     return 1;
// }

// void solve(){
//     string s[8];
//     for(int i = 1;i <= 7;i++){
//         cin >> s[i];
//         s[i] = ' ' + s[i];
//     }
//     for(int i = 1;i <= 7;i++){
//         for(int j = 1;j <= 7;j++){
//             mp[i][j] = (s[i][j] == 'B');
//         }
//     }

//     int ans = 0;
//     vector<array<int, 2>>id;

//     auto dfs = [&](auto self, int sum, int cur, int p, int fg) -> int {
//         int res = 0;
//         for(int i = p;i < id.size();i++){
//             mp[id[i][0]][id[i][1]] = 0;
//             if(sum == cur){
//                 res |= check(fg);
//             }else{
//                 res |= self(self, sum, cur+1, i+1, fg);
//             }
//             mp[id[i][0]][id[i][1]] = 1;
//         }
//         return res;
//     };


//     if(!check(0)){
//         for(int i = 2;i < 7;i++){
//             for(int j = 2;j < 7;j++) if((i + j) % 2 == 0 && mp[i][j]){
//                 id.push_back({i, j});
//             }
//         }
//         for(int x = 1;x <= 4;x++){
//             if(dfs(dfs, x, 1, 0, 0)) {
//                 ans += x;
//                 break;
//             }
//         }
//     }

//     if(!check(1)){
//         id.clear();
//         for(int i = 2;i < 7;i++){
//             for(int j = 2;j < 7;j++) if((i + j) % 2 == 1 && mp[i][j]){
//                 id.push_back({i, j});
//             }
//         }
//         for(int x = 1;x <= 4;x++){
//             if(dfs(dfs, x, 1, 0, 1)) {
//                 ans += x;
//                 break;
//             }
//         }
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;

// class Tree{
// public:

//     struct node{
//         int sum, l, r;
//         node operator+(const node& e) {
//             node ret;
//             ret.sum = sum + e.sum;
//             ret.l = l;
//             ret.r = e.r;
//             if(r > e.l){
//                 ret.sum += e.l;
//                 ret.r += r - e.l;
//             }else{
//                 ret.sum += r;
//                 ret.l += e.l - r;
//             }
//             return ret;
//         }
//     };

//     vector<node>tr;
//     const vector<int>&a, &b;

//     Tree(int n, const vector<int>& a, const vector<int>& b) : tr((n<<2)+5), a(a), b(b) {
//         build(1, 1, n);
//     }

//     void up(int id){
//         tr[id] = tr[ls] + tr[rs];
//     }

//     void build(int id, int l, int r){
//         if(l == r){
//             tr[id].sum = min(a[l], b[l]);;
//             tr[id].r = max(0ll, a[l] - b[l]);
//             tr[id].l = max(0ll, b[l] - a[l]);
//             return;
//         }
//         int mid = l + r >> 1;
//         build(ls, l, mid);
//         build(rs, mid + 1, r);
//         up(id);
//     }

//     void change(int id, int l, int r, int p){
//         if(l == r){
//             tr[id].sum = min(a[l], b[l]);;
//             tr[id].r = max(0ll, a[l] - b[l]);
//             tr[id].l = max(0ll, b[l] - a[l]);
//             return;
//         }
//         int mid = l + r >> 1;
//         if(p <= mid) change(ls, l, mid, p);
//         else change(rs, mid + 1, r, p);
//         up(id);
//     }
// };

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int>a(n+5), b(n+5), c(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];
//     for(int i = 1;i < n;i++) cin >> c[i];


//     Tree tr(n, a, b);

//     while(q--){
//         int p, x, y, z;
//         cin >> p >> x >> y >> z;
//         a[p] = x;
//         b[p] = y;
//         tr.change(1, 1, n, p);
//         cout << tr.tr[1].sum << endl;
//     }

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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;

// class Tree{
// public:
//     vector<int>mx, tag;

//     Tree(int n) : mx(n*4+10), tag(n*4+10) {};

//     void settag(int id, int x){
//         tag[id] += x;
//         mx[id] += x;
//     }

//     void down(int id) {
//         settag(ls, tag[id]);
//         settag(rs, tag[id]);
//         tag[id] = 0;
//     }

//     void up(int id){
//         mx[id] = max(mx[ls], mx[rs]);
//     }

//     void modify(int id, int l, int r, int ql, int qr, int v) {
//         if(ql <= l && r <= qr){
//             settag(id, v);
//             return;
//         }
//         if(tag[id]) down(id);
//         int mid = l + r >> 1;
//         if(qr <= mid) modify(ls, l, mid, ql, qr, v);
//         else if(ql > mid) modify(rs, mid + 1, r, ql, qr, v);
//         else modify(ls, l, mid, ql, qr, v), modify(rs, mid + 1, r, ql, qr, v);
//         up(id);
//     }

//     int query(int id, int l, int r, int ql, int qr){
//         if(ql <= l && r <= qr) return mx[id];
//         if(tag[id]) down(id);
//         int mid = l + r >> 1;
//         if(qr <= mid) return query(ls, l, mid, ql, qr);
//         else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//         else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//     }
// };

// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<int>>g(n+5), son(n+5);
//     vector<int>a(n+5);
//     vector<stack<int>>st(n+5);

//     for(int i = 2, u;i <= n;i++){
//         cin >> u;
//         g[u].push_back(i);
//     }
//     for(int i = 1;i <= n;i++) cin >> a[i];


//     auto dfs = [&](auto self, int u) -> void {
//         if(st[a[u]].size()) son[st[a[u]].top()].push_back(u);
//         st[a[u]].push(u);
//         for(auto v : g[u]) {
//             self(self, v);
//         }
//         st[a[u]].pop();
//     };

//     dfs(dfs, 1);

//     Tree tr(n);

//     vector<int>dfn(n+5), R(n+5);
//     int tot = 0, ans = 0;

//     auto dfs2 = [&](auto self, int u) -> void {
//         dfn[u] = ++tot;
//         for(auto v : g[u]){
//             self(self, v);
//         }
//         R[u] = tot;
//         tr.modify(1, 1, n, dfn[u], R[u], 1);
//         for(auto v : son[u]){
//             // cerr << u < ' ' << v << endl;
//             tr.modify(1, 1, n, dfn[v], R[v], -1);
//         }
//         array<int, 2>mx = {1, 1};
//         for(auto v : g[u]){
//             mx[1] = max(mx[1], tr.query(1, 1, n, dfn[v], R[v]));
//             if(mx[1] > mx[0]) swap(mx[1], mx[0]);
//         }

//         ans = max({ans, mx[0] * mx[1], tr.query(1, 1, n, dfn[u], R[u])});
//     };

//     dfs2(dfs2, 1);

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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n*2+10);
//     vector<array<int, 2>>s(n+5);
//     vector<int>fa(n+5), siz(n+5, 1);
//     iota(all(fa), 0);
//     auto find = [&](auto self, int x) -> int {
//         return x == fa[x] ? x : fa[x] = self(self, fa[x]);
//     };
//     auto merg = [&](int a, int b) -> void {
//         a = find(find, a);
//         b = find(find, b);
//         fa[a] = b;
//         siz[b] += siz[a];
//     };

//     for(int i = 1;i <= 2*n;i++){
//         cin >> a[i];
//         if(s[a[i]][0]) s[a[i]][1] = i;
//         else s[a[i]][0] = i;
//     }

//     vector<int>idx(n);
//     iota(all(idx), 1);
//     sort(all(idx), [&](int i, int j) -> int {
//         return s[i][0] < s[j][0];
//     });

//     int R = idx[0];
//     for(int i = 1;i < idx.size();i++){
//         auto [l, r] = s[idx[i]];
//         if(l < s[R][1]) merg(idx[i], R);
//         if(r > s[R][1]) R = idx[i]; 
//     }

//     vector<vector<int>>son(n+5);
//     int tot = 0;
//     for(int j = 0;j < n;j++){
//         int i = idx[j];
//         int f = find(find, i);
//         tot += (f == i);
//         son[f].push_back(i);
//     }

//     cout << tot << ' ';

//     iota(all(fa), 0);
//     siz = vector<int>(n+5, 1);

//     int ans = 1;
//     for(int i = 1;i <= n;i++) if(son[i].size()){
//         // cerr << son[i].size() << endl;
//         // sort(all(son[i]), [&](int i, int j) -> int {return s[i][0] < s[i][0];});
//         stack<int>st;
//         st.push(son[i][0]);
//         for(int j = 1;j < son[i].size();j++){
//             auto [l, r] = s[son[i][j]];
//             while(st.size() && r > s[st.top()][1]){
//                 if(l < s[st.top()][1]) merg(son[i][j], st.top());
//                 st.pop();
//             }
//             st.push(son[i][j]);
//         }
//         ans = (ans * (siz[find(find, son[i][0])] * 2) % mod) % mod;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// class TMap{
// public:
//     vector<int>it;
//     vector<vector<array<int, 2>>>&g;
//     int itp;
//     int &tot;

//     TMap(int n, int &tot, int itp, vector<vector<array<int,2>>>&g) : it(n*4+10), tot(tot), itp(itp), g(g) {
//         build(1, 1, n);
//     }

//     void up(int id){
//         if(itp){
//             g[it[ls]].push_back({it[id], 0});
//             g[it[rs]].push_back({it[id], 0});
//         }else{
//             g[it[id]].push_back({it[ls], 0});
//             g[it[id]].push_back({it[rs], 0});
//         }
//     }

//     void build(int id, int l, int r){
//         if(l == r){
//             it[id] = l;
//             return;
//         }
//         it[id] = ++tot; 
//         int mid = l + r >> 1;
//         build(ls, l, mid);
//         build(rs, mid + 1, r);
//         up(id);
//     }

//     void add(int id, int l, int r, int ql, int qr, int u, int w){
//         if(ql <= l && r <= qr){
//             if(itp) g[it[id]].push_back({u, w});
//             else g[u].push_back({it[id], w});
//             return ;
//         }
//         int mid = l + r >> 1;
//         if(qr <= mid) add(ls, l, mid, ql, qr, u, w);
//         else if(ql > mid) add(rs, mid + 1, r, ql, qr, u, w);
//         else add(ls, l, mid, ql, qr, u, w), add(rs, mid + 1, r, ql, qr, u, w);
//     }
// };

// void solve(){
//     int n, q, s;
//     cin >> n >> q >> s;

//     vector<vector<array<int, 2>>>g(n*8+10);
//     int tot = n;
//     TMap itp(n, tot, 1, g);
//     TMap pti(n, tot, 0, g);

//     while(q--){
//         int op;
//         cin >> op;
//         if(op == 1){
//             int u, v, w;
//             cin >> u >> v >> w;
//             g[u].push_back({v, w});
//         }else{
//             int u, l, r, w;
//             cin >> u >> l >> r >> w;
//             if(op == 2) pti.add(1, 1, n, l, r, u, w);
//             else itp.add(1, 1, n, l, r, u, w);
//         }
//     }

//     vector<int>dis(tot+5, inf);
//     priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>que;
//     dis[s] = 0;
//     que.push({dis[s], s});
//     while(que.size()){
//         auto [d, u] = que.top();
//         que.pop();
//         if(d > dis[u]) continue;
//         for(auto [v, w] : g[u]) if(d + w < dis[v]){
//             dis[v] = d + w;
//             que.push({dis[v], v});
//         }
//     }

//     for(int i = 1;i <= n;i++) cout << (dis[i] == inf ? -1 : dis[i]) << ' ';
//     cout << endl;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// class TMap{
// public:
//     vector<int>it;
//     vector<vector<int>>&g;
//     int &tot;
//     int itp;

//     TMap(int n, int &tot, int itp, vector<vector<int>>&g) : it(n*4+5), tot(tot), itp(itp), g(g) {
//         build(1, 1, n);
//     }

//     void up(int id){
//         if(itp){
//             g[it[ls]].push_back(it[id]);
//             g[it[rs]].push_back(it[id]);
//         }else{
//             g[it[id]].push_back(it[ls]);
//             g[it[id]].push_back(it[rs]);
//         }
//     }

//     void build(int id, int l, int r){
//         if(l == r){
//             it[id] = l;
//             return;
//         }
//         it[id] = ++tot;
//         int mid = l + r >> 1;
//         build(ls, l, mid);
//         build(rs, mid + 1, r);
//         up(id);
//     }

//     void add(int id, int l, int r, int ql, int qr, int u) {
//         if(ql <= l && r <= qr){
//             if(itp){
//                 g[it[id]].push_back(u);
//             }else{
//                 g[u].push_back(it[id]);
//             }
//             return;
//         }
//         int mid = l + r >> 1;
//         if(qr <= mid) add(ls, l, mid, ql, qr, u);
//         else if(ql > mid) add(rs, mid + 1, r, ql, qr, u);
//         else add(ls, l, mid, ql, qr, u), add(rs, mid + 1, r, ql, qr, u);
//     }
// };

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n*2+10);
//     vector<array<int, 2>>s(n+5);
//     vector<int>fa(n+5);
//     iota(all(fa), 0);
//     auto find = [&](auto self, int x) -> int {
//         return x == fa[x] ? x : fa[x] = self(self, fa[x]);
//     };
//     auto merg = [&](int a, int b) -> void {
//         a = find(find, a);
//         b = find(find, b);
//         fa[a] = b;
//     };

//     for(int i = 1;i <= 2*n;i++){
//         cin >> a[i];
//         if(s[a[i]][0]) s[a[i]][1] = i;
//         else s[a[i]][0] = i;
//     }

//     vector<int>idx(n);
//     iota(all(idx), 1);
//     sort(all(idx), [&](int i, int j) -> int {
//         return s[i][0] < s[j][0];
//     });

//     int R = idx[0];
//     for(int i = 1;i < idx.size();i++){
//         auto [l, r] = s[idx[i]];
//         if(l < s[R][1]) merg(idx[i], R);
//         if(r > s[R][1]) R = idx[i]; 
//     }

//     vector<vector<int>>son(n+5);
//     int tot = 0;
//     for(int j = 0;j < n;j++){
//         int i = idx[j];
//         int f = find(find, i);
//         tot += (f == i);
//         son[f].push_back(i);
//     }

//     cout << tot << ' ';

//     int len = n*2;

//     vector<vector<int>>g(len*4 + 5);

//     int _tot = len;
//     TMap pti(len, _tot, 0, g);
//     for(int i = 1;i <= n;i++){
//         pti.add(1, 1, len, s[i][0]+1, s[i][1], s[i][0]);
//         pti.add(1, 1, len, s[i][0], s[i][1]-1, s[i][1]);
//     }

//     vector<int>dfn(_tot+5), low(_tot+5), scc(_tot+5), st(_tot+5), siz(_tot+5);
//     int top = 0, cnt = 0;
//     tot = 0;
//     auto tarjan = [&](auto self, int u, int f) -> void {
//         dfn[u] = low[u] = ++tot;
//         st[++top] = u;
//         for(auto v : g[u]) {
//             if(!dfn[v]){
//                 self(self, v, u);
//                 low[u] = min(low[u], low[v]);
//             }else if(!scc[v]){
//                 low[u] = min(low[u], low[v]);
//             }
//         }
//         if(low[u] == dfn[u]){
//             scc[u] = ++cnt;
//             if(u <= len) siz[cnt]++;
//             while(st[top] != u){
//                 if(st[top] <= len) siz[cnt]++;
//                 scc[st[top--]] = cnt;
//             }
//             top--;
//         }   
//     };

//     int ans = 1;
//     for(int i = 1;i <= n;i++) if(son[i].size()){
//         tarjan(tarjan, s[son[i][0]][0], 0);
//         int tmp = siz[scc[ s[son[i][0]][0] ]];
//         ans = (ans * tmp) % mod;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, m;
//     cin >> n >> m;
//     if(n == 1 && m == 1){
//         cout << 0 << endl;
//         return;
//     }
//     int ans = n + m - 2 + min(n, m);
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, k, b, s;
//     cin >> n >> k >> b >> s;
//     int sum = k * b;
//     if(sum > s){
//         cout << -1 << endl;
//         return;
//     }

//     int d = s - sum;
//     if(n * (k-1) + 1 <= d){
//         cout << -1 << endl;
//         return;
//     }

//     vector<int>a(n+5);
//     a[n] = sum;
//     for(int i = 1;i <= n;i++){
//         int tmp = min(k-1, d);
//         a[i] += tmp;
//         d -= tmp;
//         cout << a[i] << ' ';
//     }
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int ans = 0, cur = 0;
//     for(int i = 1;i <= n;i++){
//         if(a[i] != a[i-1]) cur += i-1;
//         cur++;
//         ans += cur;
//     }

//     while(q--){
//         int i, x;
//         cin >> i >> x;
//         if(a[i] != x){
//             if(a[i] != a[i-1] && x == a[i-1]){
//                 ans -= (n-i+1) * (i-1);
//             }
//             if(a[i] == a[i-1] && x != a[i-1]){
//                 ans += (n-i+1) * (i-1);
//             }
//             if(a[i] != a[i+1] && x == a[i+1]){
//                 ans -= (n-i) * i;
//             }
//             if(a[i] == a[i+1] && x != a[i+1]){
//                 ans += (n-i) * i;
//             }
//         }
//         a[i] = x;
//         cout << ans << endl;
//     }
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
// #define int unsigned long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int>a(n+5), vis(n+5);
//     vector<vector<array<int,2>>>g(n+5);
//     for(int i = 1, u, v, w;i <= q;i++){
//         cin >> u >> v >> w;
//         if(u > v) swap(u, v);
//         if(u == v){
//             a[u] = w;
//             vis[u] = 1;
//         }else{
//             g[u].push_back({v, w});
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(auto [v, w] : g[i]) {
//             if(vis[v]){ 
//                 a[i] |= (w & (~a[v]));
//             }
//         }
//         for(auto [v, w] : g[i]) {
//             if(!vis[v]){ 
//                 a[v] |= (w & (~a[i]));
//             }
//         }
//     }

//     for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//     cout << endl;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int>a(n+5, (1<<30)-1);
//     vector<vector<array<int, 2>>>g(n+5);
//     for(int i = 1, u, v, w;i <= q;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//         a[u] &= w;
//         a[v] &= w;
//     }
//     for(int i = 1;i <= n;i++){
//         a[i] = 0;
//         for(auto [v, w] : g[i]){
//             if(v == i) {
//                 a[i] = w;
//                 break;
//             }
//             a[i] |= w - a[v];
//         }
//         cout << a[i] << ' ';
//     }
//     cout << endl;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
//     string rs(s.rbegin(), s.rend());
//     if(rs < s){
//         cout << rs << s << endl;
//     }else{
//         cout << s << endl;
//     }
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5), cnt(n+5);
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         cnt[a[i]]++;
//     }
//     if(cnt[0] == 0 || cnt[0] == n){
//         cout << 2 << endl;
//         cout << 1 << ' ' << 1 << endl;
//         cout << 2 << ' ' << n << endl;
//         return;
//     }
//     if(cnt[0] == 1){
//         cout << -1 << endl;
//         return;
//     }

//     int m;
//     for(int i = 1;i <= n+1;i++) if(!cnt[i]){
//         m = i;
//         break;
//     }

//     cnt = vector<int>(n+5);
//     int cur = 0;
//     int p;
//     for(int i = 1;i <= n;i++){
//         cnt[a[i]]++;
//         while(cnt[cur]) cur++;
//         if(cur == m){
//             p = i;
//             break;
//         }
//     }

//     cnt = vector<int>(n+5);
//     for(int i = p + 1;i <= n;i++){
//         cnt[a[i]]++;
//     }
//     for(int i = 0;i < m;i++) if(!cnt[i]){
//         cout << "-1\n";
//         return;
//     }
//     cout << 2 << endl;
//     cout << 1 << ' ' << p << endl;
//     cout << p + 1 << " " << n << endl;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<array<int, 2>>a(n+5); //b a
//     for(int i = 1;i <= n;i++) cin >> a[i][1] >> a[i][0];
//     // for(int i = 1;i <= n;i++)
//     //     cerr << a[i][1] << ' ' << a[i][0] << endl;

//     sort(all1(a));

//     int ans = 0;

//     for(int i = 1;i <= n;i++){
//         priority_queue<int>q;
//         int sum = 0;
//         for(int j = i;j >= 1;j--){
//             int d = a[j][1];
//             // while(q.size() && sum + (a[i][0] - a[j][0]) > m) {
//             //     sum -= q.top();
//             //     q.pop();
//             // }
//             if(sum + d + (a[i][0] - a[j][0]) <= m){
//                 q.push(a[j][1]);
//                 sum += d;
//                 ans = max(ans, (int)q.size());
//             }else if(q.size() && d <= q.top()){
//                 sum -= q.top();
//                 q.pop();
//                 q.push(a[j][1]);
//                 sum += d;
//                 ans = max(ans, (int)q.size());
//             }
//         }
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, c;
//     cin >> n >> c;
//     vector<int>a(n+5);
//     vector<int>num[2];
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         num[a[i]&1].push_back(a[i]);
//     }

//     int ans = ((c+1)*(c+2)) / 2;

//     for(int i = 1;i <= n;i++){
//         ans -= c - a[i] + 1;
//     }

//     for(int i = 1;i <= n;i++){
//         ans -= (a[i] + 2) / 2;

//         ans += lower_bound(all(num[a[i]&1]), a[i]) - num[a[i]&1].begin() + 1;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;


// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<array<int, 2>>a(n+5); //b a
//     for(int i = 1;i <= n;i++) cin >> a[i][1] >> a[i][0];

//     sort(all1(a));

//     int ans = 0;

//     for(int i = 1;i <= n;i++){
//         priority_queue<int>q;
//         int sum = 0, B = a[i][0];
//         for(int j = i;j >= 1;j--){
//             int d = B - a[j][0] + a[j][1];
//             if(sum + d <= m){
//                 q.push(a[j][1]);
//                 sum += d;
//                 B = a[j][0];
//                 ans = max(ans, (int)q.size());
//             }else if(q.size() && d <= q.top()){
//                 sum -= q.top();
//                 q.pop();
//                 q.push(a[j][1]);
//                 sum += d;
//                 B = a[j][0];
//                 ans = max(ans, (int)q.size());
//             }
//         }
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

// int main(){

//     int a, b;
//     scanf("%d:%d", &a, &b);
//     if(a < 12 || (a == 12 && b == 0)){
//         cout << "Only ";
//         if(a < 10) cout << 0;
//         cout << a << ":";
//         if(b < 10) cout << 0;
//         cout << b;
//         cout << ".  Too early to Dang.\n";
//     }else{
//         a -= 12;
//         if(b) a++;
//         while(a--) cout << "Dang";
//         cout << endl;
//     }
    
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int a, b;
//     cin >> a >> b;
//     int oa = a;
//     int ob = b;
//     int m;
//     cin >> m;
//     int f = 0;
//     while(m--){
//         int x, y, u, v;
//         cin >> x >> y >> u >> v;
//         if(f) continue;
//         cerr << m << endl;

//         int ac = (y == (x + u));
//         int bc = (v == (x + u));

//         if(ac != bc){
//             if(ac){
//                 a--;
//                 if(a == 0) f = 1;
//             }else{
//                 b--;
//                 if(b == 0) f = 2;
//             }
//         }
//     }

//     cout << a << ' ' << b << endl;

//     cout << (f == 1 ? 'A' : 'B') << endl;
//     cout << (f == 1 ? ob-b : oa-a);
    
    
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int n;
//     cin >> n;
    
//     map<int,int>mp;
//     while(n--){
//         int k;
//         cin >> k;
//         if(k == 1){
//             cin >> k;
//             continue;
//         }
    
//         while(k--){
//             int t;
//             cin >> t;
//             mp[t] = 1;
//         }    
//     }

//     vector<int>ans;
//     cin >> n;
//     map<int,int>vis;
//     while(n--){
//         int t;
//         cin >> t;
//         if(vis[t]) continue;
//         if(!mp[t]) ans.push_back(t);
//         vis[t] = 1;
//     }

//     if(ans.size()){
//         for(int i = 0;i < ans.size();i++){
//             cout << ans[i];
//             if(i != ans.size()-1) cout << ' ';
//         }
//     }else{
//         cout << "No one is handsome";
//     }
    
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     string t = "GPLT";
    
//     string s;
//     cin >> s;
//     map<int,int>mp;
//     for(auto &e : s){
//         if(e >= 'a' && e <= 'z'){
//             e -= 'a';
//             e += 'A';
//         }
//         mp[e]++;
//     }


//     int i = 0;
//     do{
//         if(mp[t[i]]){
//             cout << t[i];
//             mp[t[i]]--;
//         }
//         i = (i+1)%4;
//     }while(mp['G'] + mp['P'] + mp['L'] + mp['T']);
        
    
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;

// struct node{
//     int id, cnt;
//     double s;
// };

// int main(){

//     int n;
//     cin >> n;
//     vector<node>a(n+5);
//     for(int i = 1;i <= n;i++) a[i].id = i;

//     for(int i = 1;i <= n;i++){
//         int k;
//         cin >> k;

//         while(k--){
//             int id;
//             double p;
//             cin >> id >> p;
//             p /= 100;
//             a[id].cnt++;
//             a[id].s += p;
//             a[i].s -= p;
//         }
//     }

//     vector<int>idx(n);
//     iota(idx.begin(), idx.end(), 1);
//     sort(idx.begin(), idx.end(), [&](int i, int j) -> int {
//         if(fabs(a[i].s - a[j].s) > 0.0001) return a[i].s > a[j].s;
//         if(a[i].cnt != a[j].cnt) return a[i].cnt > a[j].cnt;
//         return a[i].id < a[j].id;
//     });

//     for(auto i : idx) {
//         printf("%d %.2lf\n", a[i].id, a[i].s);
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;

// const int N = 200;

// int fa[N];
// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// int bad[N][N];

// int main(){

//     int n, m, k;
//     cin >> n >> m >> k;
//     for(int i = 1;i <= n;i++) fa[i] = i;
//     while(m--){
//         int u, v, w;
//         cin >> u >> v >> w;
//         if(w == 1){
//             merg(u, v);
//         }else{
//             bad[u][v] = bad[v][u] = 1;
//         }
//     }

//     while(k--){
//         int u, v;
//         cin >> u >> v;
//         if(find(u) == find(v) && !bad[u][v]) cout << "No problem\n";
//         else if(find(u) == find(v) && bad[u][v]) cout << "OK but...\n";
//         else if(find(u) != find(v) && !bad[u][v]) cout << "OK\n";
//         else cout << "No way\n";
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// const int N = 50;
// int n;
// int mid[N], pre[N];
// int L[N], R[N];

// int pp;

// int solve(int l, int r){
//     if(l > r) return 0;
//     int rt = pre[++pp];
//     int rpos = l;
//     for(int i = l;i <= r;i++) if(mid[i] == rt){
//         rpos = i;
//         break;
//     }

//     R[rt] = solve(l, rpos - 1);
//     L[rt] = solve(rpos + 1, r);

//     return rt;
// }


// vector<int>vec[N];
// int dep[N];

// void dfs(int u, int f){
//     if(!u) return;
//     dep[u] = dep[f] + 1;
//     vec[dep[u]].push_back(u);
//     dfs(L[u], u);
//     dfs(R[u], u);
// }

// int main(){

//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> mid[i];
//     for(int i = 1;i <= n;i++) cin >> pre[i];

//     int rt = solve(1, n);

//     dfs(rt, 0);

//     int f = 0;
//     for(int i = 1;i <= n;i++){
//         for(auto e : vec[i]){
//             if(f) cout << ' ';
//             f = 1;
//             cout << e;

//         }
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// const int N = 4096;
// int hp[N], n, m;
// int siz = 0;

// void push(int x){
//     hp[++siz] = x;

//     int cur = siz;
//     int fa = cur >> 1;
//     while(fa > 0 && hp[cur] < hp[fa]){
//         swap(hp[fa], hp[cur]);
//         cur = fa;
//         fa = cur >> 1;
//     }
// }

// int main(){

//     cin >> n >> m;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         push(a[i]);
//     }

//     map<int,int>pos;
//     for(int i = 1;i <= siz;i++) pos[hp[i]] = i;

//     while(m--){
//         int x = 0, y = 0;
//         cin >> x;

//         string s;
//         getline(cin, s);

//         if(s.back() == 't'){ //root

//             if(pos[x] == 1) cout << "T\n";
//             else cout << "F\n";

//         }else if(s[1] == 'a'){ //bro
        
//             for(int i = 5;s[i] != ' ';i++){
//                 y = y * 10 + s[i] - '0';
//             }
//             if(pos[x]/2 == pos[y]/2) cout << "T\n";
//             else cout << "F\n";

//         }else if(s[4] == 't'){ //fa

//             int pw = 1;
//             for(int i = s.size()-1;s[i] != ' ';i--, pw *= 10){
//                 y += pw * (s[i] - '0');
//             }
//             if(pos[x] == pos[y]/2) cout << "T\n";
//             else cout << "F\n";

//         }else{ //son

//             int pw = 1;
//             for(int i = s.size()-1;s[i] != ' ';i--, pw *= 10){
//                 y += pw * (s[i] - '0');
//             }
//             if(pos[x] == pos[y]*2 || pos[x] == pos[y]*2+1) cout << "T\n";
//             else cout << "F\n";

//         }
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;

// const int inf = 0x3f3f3f3f;

// int main(){

//     int n, m;
//     cin >> n >> m;
//     vector<vector<array<int, 3>>>g(n+5);
//     for(int i = 1, u, v, one, len, t;i <=m;i++){
//         cin >> u >> v >> one >> len >> t;
//         u++, v++;
//         g[u].push_back({v, len, t});
//         if(!one) g[v].push_back({u, len, t});
//     }

//     int s, t;
//     cin >> s >> t;
//     s++, t++;

//     vector<int>pre(n+5);
//     vector<array<int, 2>>dis(n+5, {inf, inf}); // ti, d
//     dis[s] = {0, 0};
//     priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>que;
//     que.push({0, 0, s});

//     while(que.size()){
//         auto [tm, d, u] = que.top();
//         que.pop();
//         // cerr << u << endl;
//         if(u == t) break;
//         if(tm > dis[u][0] || (tm == dis[u][0] && d > dis[u][1])) continue;
//         for(auto [v, w, ti] : g[u]){
//             array<int,2>tmp({tm+ti, d+w});
//             if(tmp < dis[v]){
//                 dis[v] = tmp;
//                 que.push({tmp[0], tmp[1], v});
//                 pre[v] = u;
//             }
//         }
//     }

//     int tim = dis[t][0];
//     vector<int>ans1;
//     int cur = t;
//     while(cur != s){
//         ans1.push_back(cur);
//         cur = pre[cur];
//     }
//     ans1.push_back(cur);

    
//     dis = vector<array<int,2>>(n+5, {inf, inf}); // d, cnt
//     dis[s] = {0, 0};
//     while(que.size()) que.pop();
//     que.push({0, 0, s});

//     while(que.size()){
//         auto [d, cnt, u] = que.top();
//         que.pop();
//         if(u == t) break;
//         if(d > dis[u][0] || (d == dis[u][0] && cnt > dis[u][1])) continue;
//         for(auto [v, w, ti] : g[u]){
//             array<int,2>tmp({d+w, cnt+1});
//             if(tmp < dis[v]){
//                 dis[v] = tmp;
//                 que.push({tmp[0], tmp[1], v});
//                 pre[v] = u;
//             }
//         }
//     }

//     int dist = dis[t][0];
//     vector<int>ans2;
//     cur = t;
//     while(cur != s){
//         ans2.push_back(cur);
//         cur = pre[cur];
//     }
//     ans2.push_back(cur);

//     if(ans1 == ans2){
//         cout << "Time = " << tim << "; Distance = " << dist << ": ";
//         for(int i = ans1.size()-1;i >= 0;i--){
//             cout << ans1[i]-1;
//             if(i) cout << " => ";
//         }
//     }else{
//         cout << "Time = " << tim << ": ";
//         for(int i = ans1.size()-1;i >= 0;i--){
//             cout << ans1[i]-1;
//             if(i) cout << " => ";
//         }
//         cout << endl;

//         cout << "Distance = " << dist << ": ";
//         for(int i = ans2.size()-1;i >= 0;i--){
//             cout << ans2[i]-1;
//             if(i) cout << " => ";
//         }


//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define  endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// using namespace std;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, m, p;
//     cin >> n >> m >> p;
//     vector<int>d(n+5), h(m+5), t(m+5), pt(m+5);
//     for(int i = 2;i <= n;i++){
//         cin >> d[i];
//         d[i] += d[i-1];
//     }

//     for(int i = 1;i <= m;i++) cin >> h[i] >> t[i];
//     for(int i = 1;i <= m;i++) t[i] = t[i] - d[h[i]];
//     sort(t.begin() + 1, t.begin() + 1 + m);
//     for(int i = 1;i <= m;i++) pt[i] = t[i] + pt[i-1];

//     vector<vector<int>>f(p+5, vector<int>(m+5));
//     vector<int>que(m+5);
//     int hd = 1, bk = 0;

//     auto K = [&](int i, int x1, int x2) -> double {
//         double y1 = f[i][x1] + pt[x1];
//         double y2 = f[i][x2] + pt[x2];
//         return (y2 - y1) / (x2 - x1);
//     };

//     for(int j = 1;j <= m;j++){
//         f[1][j] = j*t[j] - pt[j];
//     }

//     for(int i = 2;i <= p;i++){
//         hd = 1, bk = 0;
//         que[++bk] = 1;
//         for(int j = 2;j <= m;j++){
//             while(bk > hd && K(i-1, que[hd], que[hd+1]) <= t[j]) hd++;
//             int delt = f[i-1][que[hd]] + pt[que[hd]] - t[j]*que[hd];
//             f[i][j] = delt - pt[j] + j*t[j];
//             while(bk > hd && K(i-1, que[bk], j) <= K(i-1, que[bk-1], que[bk])) bk--;
//             que[++bk] = j;
//         }
//     }

//     int ans = inf;
//     for(int i =  1;i <= p;i++) ans = min(ans, f[i][m]);

//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define  endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// using namespace std;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<vector<array<int, 2>>>g(n+5);
//     for(int i = 1, u, v, w;i <= m;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     vector<int>ans(n+5, inf);
//     vector<vector<int>>f(2, vector<int>(n+5, inf));
//     vector<int>que(n+5);
//     int hd = 1, bk = 0;

//     auto K = [&](int i, int k1, int k2) -> double {
//         double x1 = k1, x2 = k2;
//         double y1 = f[i&1][k1] + k1*k1, y2 = f[i&1][k2] + k2*k2;
//         return (y2 - y1) / (x2 - x1);
//     };

//     f[0][1] = 0;
//     priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>pq;
//     pq.push({0, 1});
//     while(pq.size()){
//         auto [d, u] = pq.top();
//         pq.pop();
//         for(auto [v, w] : g[u]) if(w + d < f[0][v]){
//             f[0][v] = d + w;
//             pq.push({f[0][v], v});
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         f[1][i] = f[0][i];
//         ans[i] = min(ans[i], f[0][i]);
//         while(bk > hd && K(0, que[bk], i) <= K(0, que[bk-1], que[bk])) bk--;
//         que[++bk] = i;
//     }

//     for(int i = 1;i <= k;i++){
//         for(int j = 1;j <= n;j++){
//             while(bk > hd && K((i&1)^1, que[hd], que[hd+1]) <= 2*j) hd++;
//             int delt = f[(i&1)^1][que[hd]] + que[hd]*que[hd] - 2*j*que[hd];
//             int tmp = delt + j*j;
//             if(tmp < f[i&1][j]){
//                 f[i&1][j] = tmp;
//                 pq.push({tmp, j});
//             }
//         }
//         while(pq.size()){
//             auto [d, u] = pq.top();
//             pq.pop();
//             for(auto [v, w] : g[u]) if(d + w < f[i&1][v]){
//                 f[i&1][v] = d + w;
//                 pq.push({d+w, v});
//             }
//         }
//         hd = 1, bk = 0;
//         for(int j = 1;j <= n;j++){
//             f[(i&1)^1][j] = f[i&1][j];
//             ans[j] = min(ans[j], f[i&1][j]);
//             while(bk > hd && K(i&1, que[bk], j) <= K(i&1, que[bk-1], que[bk])) bk--;
//             que[++bk] = j;
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         cout << ans[i] << ' ';
//     }
// }

// signed main(){

//     IO;
//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define  endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// using namespace std;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, s;
//     cin >> n >> s;
//     vector<int>t(n+5), c(n+5);
//     for(int i = 1;i <= n;i++) cin >> t[i] >> c[i];
//     for(int i = 1;i <= n;i++){
//         t[i] += t[i-1];
//         c[i] += c[i-1];
//     }

//     vector<int>f(n+5), que(n+5);
//     int hd = 1, bk = 0;
//     auto dx = [&](int i, int j) -> int {return c[j] - c[i];};
//     auto dy = [&](int i, int j) -> int {return f[j] - f[i];};

//     auto find = [&](int k) -> int {
//         int l = hd, r = bk;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(mid == bk || dy(que[mid], que[mid+1]) > k * dx(que[mid], que[mid+1])) r = mid - 1;
//             else l = mid + 1;
//         }
//         return que[l];
//     };

//     for(int i = 1;i <= n;i++){
//         while(bk > hd && dx(que[bk-1], que[bk]) * dy(que[bk], i-1) <= dx(que[bk], i-1) * dy(que[bk-1], que[bk])) bk--;
//         que[++bk] = i-1;
//         int j = find(t[i] + s);
//         int delt = f[j] - s*c[j] - t[i]*c[j];
//         f[i] = delt + s*c[n] + t[i]*c[i];
//     }

//     cout << f[n] << endl;
// }

// signed main(){

//     IO;
//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define  endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// using namespace std;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     vector<vector<int>>f(n+5, vector<int>(n+5, inf));
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     a[n+1] = inf;

//     f[0][1] = f[0][0] = 0;
//     for(int i = 0;i <= n;i++){
//         f[i][1] = f[i][0] = 0;
//         for(int j = 2;j <= n+1;j++){
//             if(i){
//                 for(int k = 0;k < j;k++) if(a[k] < a[j]){
//                     f[i][j] = min(f[i][j], f[i-1][k] + (j-k-1));
//                 }
//             }
//             if(a[j] > a[j-1]) f[i][j] = min(f[i][j], f[i][j-1]);
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         cout << f[i][n+1] << ' ';
//     }
//     // for(int i = 1;i <= n;i++) cerr << f[1][i] << ' ';
//     // cerr << endl;

//     // for(int i = 0;i <= n;i++){
//     //     for(int j = 0;j <= n+1;j++){
//     //         if(f[i][j] == inf) cerr << "inf ";
//     //         else cerr << f[i][j] << ' ';
//     //     }
//     //     cerr << endl;
//     // }
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
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define  endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// using namespace std;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, q;
//     cin >> n >> q;
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     set<int>L, R;
//     for(int i = 1;i < n;i++){
//         if(s[i] == '(' && s[i+1] == '(') L.insert(i);
//     }
//     for(int i = 1;i < n;i++){
//         if(s[i] == ')' && s[i+1] == ')') R.insert(i);
//     }

//     while(q--){
//         int x;
//         cin >> x;

//         if(n & 1){
//             cout << "NO\n";
//             continue;
//         }

//         if(x > 1 && s[x-1] == s[x]){
//             if(s[x] == '('){
//                 L.erase(x-1);
//             }else{
//                 R.erase(x-1);
//             }
//         }
//         if(x < n && s[x] == s[x+1]){
//             if(s[x] == '('){
//                 L.erase(x);
//             }else{
//                 R.erase(x);
//             }
//         }

//         if(s[x] == '(') s[x] = ')';
//         else s[x] = '(';

//         if(x > 1 && s[x-1] == s[x]){
//             if(s[x] == '('){
//                 L.insert(x-1);
//             }else{
//                 R.insert(x-1);
//             }
//         }
//         if(x < n && s[x] == s[x+1]){
//             if(s[x] == '('){
//                 L.insert(x);
//             }else{
//                 R.insert(x);
//             }
//         }

//         if(s[1] == ')' || s[n] == '('){
//             cout << "NO\n";
//         }else{
//             if(L.empty() && R.empty()){
//                 cout << "YES\n";
//             }else{
//                 if(L.empty() != R.empty()){
//                     cout << "NO\n";
//                 }else{
//                     int l = *L.begin();
//                     int r = *R.begin();
//                     if(l < r && (*L.rbegin()) < (*R.rbegin())) cout << "YES\n";
//                     else cout << "NO\n";
//                 }
//             }
//         }
//     }
// }

// signed main(){

//     IO;
//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define  endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// using namespace std;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int k;
//     cin >> k;
//     string s;
//     cin >> s;
//     stack<int>st;
//     vector<int>ans;
//     for(int i = 0;i < s.size();i++){
//         if(s[i] == '(') st.push(i);
//         else {
//             ans.push_back((i-st.top()) / 2);
//             st.pop();
//         }
//     }
//     sort(all(ans));
//     int sum = 0;
//     for(int i = 0;i + k < ans.size();i++) sum += ans[i];
//     cout << sum << endl;
// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define  endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// using namespace std;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int N = 5010;
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
// void get_inv(){
//     fac[0] = inv[0] = 1;
//     for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//     inv[N-1] = qpow(fac[N-1], mod - 2);
//     for(int i = N - 2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
// }
// int C(int a, int b){
//     if(b > a) return 0;
//     return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
// }


// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<int>c(n+5), f(n+5), s(n+5);
//     for(int i = 1;i <= n;i++) cin >> c[i];

//     int len = 0;

//     for(int i = 1;i <= n;i++){
//         int cnt = 0;
//         for(int j = i;j >= 0;j--){
//             if(cnt == k){
//                 f[i] = max(f[i], f[j] + k);
//             }else{
//                 cnt += c[j] == c[i];
//             }
//         }
//         len = max(len, f[i]);
//         // cerr << f[i] << ' ';
//     }
//     // cerr << endl;

//     if(len == 0) {
//         cout << 1 << endl;
//         return;
//     }

//     // cerr << len << endl;

//     vector<vector<int>>last(n+5, vector<int>(n+5));
//     int ans = 0;

//     s[0] = 1;
//     for(int i = 1;i <= n;i++){
//         int cnt = 0;
//         for(int j = i;j >= 0;j--){
//             if(f[j] == f[i] - k && cnt >= k){
//                 // s[i] = (s[i] + ((s[j] * C(cnt, k) - last[f[i]][c[i]] + mod)%mod)) % mod;
//                 s[i] = (s[i] + (s[j] * C(cnt-1, k-1) % mod)) % mod;
//                 // cerr << j << ' ' << i << endl;
//             }
//             cnt += c[j] == c[i];
//         }
//         if(f[i] == len){
//             ans = (ans + s[i]) % mod;
//             // last[c[i]] = s[i];
//         }
//         // last[f[i]][c[i]] = (last[f[i]][c[i]] + s[i]) % mod;
//         // cerr << s[i] << " ";
//     }
//     // cerr << endl;

//     cout << ans << endl;
// }

// signed main(){

//     IO;

//     get_inv();

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define  endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// using namespace std;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int N = 5010;
// const int mod = 1e9 + 7;



// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>>g(n+5);
//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     int k = sqrt(n);
//     if(k * k != n){
//         cout << "NO\n";
//         return;
//     }

//     map<int, int>dmp;
//     for(int i = 1;i <= n;i++) dmp[g[i].size()]++;

//     if(dmp[4] != k || dmp[2] != n - k){
//         cout << "NO\n";
//         return;
//     }

//     vector<int>fa(n+5), siz(n+5, 1);
//     iota(all(fa), 0);

//     auto find = [&](auto self, int x) -> int {
//         return x == fa[x] ? x : fa[x] = self(self, fa[x]);
//     };
//     auto merg = [&](int a, int b) -> void {
//         a = find(find, a);
//         b = find(find, b);
//         if(a == b) return;
//         fa[a] = b;
//         siz[b] += siz[a];
//     };

//     for(int i = 1;i <= n;i++) if(g[i].size() == 2){
//         for(auto v : g[i]) merg(i, v);
//     }

//     int cnt = 0;
//     set<int>st;
//     for(int i = 1;i <= n;i++) if(g[i].size() == 4 && siz[find(find, i)] == k){
//         cnt++;
//         st.insert(fa[i]);
//     }

//     if(cnt != k || cnt != st.size()){
//         cout << "NO\n";
//         return;
//     }

//     iota(all(fa), 0);
//     for(int i = 1;i <= n;i++) if(g[i].size() == 4){
//         for(auto v : g[i]) if(g[v].size() == 4){
//             merg(i, v);
//         }
//     }

//     cnt = 0;
//     for(int i = 1;i <= n;i++) cnt += (find(find, i) == i);
    
//     if(cnt != n-k+1) cout << "NO\n";
//     else cout << "YES\n";
// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define  endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// using namespace std;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int N = 5010;
// const int mod = 1e9 + 7;


// struct node{
//     int cnt, c;
//     int operator<(const node &e) const {
//         if(cnt != e.cnt) return cnt < e.cnt;
//         return c > e.c;
//     }
//     int operator>(const node &e) const {
//         if(cnt != e.cnt) return cnt > e.cnt;
//         return c < e.c;
//     }
// };

// void solve(){
//     int n, m, p;
//     cin >> n >> m >> p;
//     vector<int>w(n+5);
//     vector<vector<array<int, 2>>>g(n+5);
//     for(int i = 1;i <= n;i++) cin >> w[i];
//     for(int i = 1, u, v, s;i <= m;i++){
//         cin >> u >> v >> s;
//         g[u].push_back({v, s});
//     }

//     vector<vector<node>>dis(n+5, vector<node>(n+5, {inf, 0}));
//     dis[1][1] = {0, p};

//     priority_queue<pair<node, array<int, 2>>, vector<pair<node, array<int, 2>>>, greater<pair<node, array<int, 2>>>>que;
//     que.push({{0, p}, {1, 1}});
//     while(que.size()){
//         auto [cnt, c] = que.top().first;
//         auto [i, j] = que.top().second;
//         que.pop();
//         for(auto [v, s] : g[i]){
//             int d = max(0ll, (s-c+w[j]-1) / w[j]);
//             int mx = j;
//             if(w[v] > w[j]) mx = v;
//             node ne = {cnt+d, c+d*w[j]-s};
//             if(ne < dis[v][mx]){
//                 dis[v][mx] = ne;
//                 que.push({ne, {v, mx}});
//             }
//         }
//     }

//     int ans = inf;
//     for(int i = 1;i <= n;i++){
//         ans = min(ans, dis[n][i].cnt);
//     }
//     if(ans == inf) cout << -1 << endl;
//     else cout << ans << endl;
// }

// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define  endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// using namespace std;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int N = 5010;
// const int mod = 1e9 + 7;

// class Tree{
// public:
//     vector<int>tr;

//     Tree(int n) : tr(n*4+5) {}

//     void up(int id){
//         tr[id] = max(tr[ls], tr[rs]);
//     }

//     void change(int id, int l, int r, int x, int v) {
//         if(l == r){
//             tr[id] = max(tr[id], v);
//             return;
//         }
//         int mid = l + r >> 1;
//         if(x <= mid) change(ls, l, mid, x, v);
//         else change(rs, mid + 1, r, x, v);
//         up(id);
//     }

//     int query(int id, int l, int r, int ql, int qr){
//         if(ql <= l && r <= qr) return tr[id];
//         int mid = l + r >> 1;
//         if(qr <= mid) return query(ls, l, mid, ql, qr);
//         else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//         else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//     }
// };

// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<int>a(n+5), h(k+5), c(k+5), last(k+5), f(n+5);
//     vector<vector<array<int, 2>>>L(n+5);
//     Tree mxt(n);

//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= k;i++) cin >> c[i];
//     for(int i = 1;i <= k;i++) cin >> h[i];

//     int ans = 0, mxf = 0;

//     for(int i = 1;i <= n;i++){
//         if(last[a[i]]){
//             if(i-last[a[i]] > 1) L[i-1].push_back({last[a[i]]+1, c[a[i]] - h[a[i]]});
//             else ans -= c[a[i]] - h[a[i]];
//         }
//         last[a[i]] = i;
//     }


//     for(int i = 1;i <= n;i++){
//         f[i] = f[i-1];
//         for(auto [l, w] : L[i]) if(l-1 >= 1){
//             f[i] = max(f[i], w + mxt.query(1, 1, n, 1, l-1));
//         }
//         mxt.change(1, 1, n, i, f[i]);

//         ans += c[a[i]];
//         mxf = max(mxf, f[i]);
//     }

//     ans -= mxf;
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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define  endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// using namespace std;
// const int inf = 0x3f3f3f3f;
// // const int inf = 0x3f3f3f3f3f3f3f3f;
// const int N = 5010;
// const int mod = 1e9 + 7;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>c(n+5), dis(n+5, inf);
//     vector<vector<int>>g(n+5);
//     for(int i = 1;i <= n;i++) cin >> c[i];
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     vector<array<int,3>>que(n+5);
//     int hd = 1, bk = 0;
//     int ans = inf;

//     auto bfs = [&](int x) -> void {
//         hd = 1, bk = 0;
//         que[++bk] = {x, 0, 0};
//         while(bk >= hd){
//             auto [u, d, pre] = que[bk--];
//             if(d >= ans) continue;
//             for(auto v : g[u]) if(v != pre && d + 1 < dis[v]){
//                 dis[v] = d + 1;
//                 que[++bk] = {v, dis[v], u};
//             }
//         }
//     };

//     bfs(c[1]);

//     for(int i = 2;i <= n;i++){
//         ans = min(ans, dis[c[i]]);
//         cout << ans << ' ';
//         bfs(c[i]);
//     }

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
// const int mod = 1e9 + 7;
// const int N = 1010;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// int op[8][2] = {
//     1, 1,
//     1, 0,
//     1, -1,
//     0, 1,
//     0, -1,
//     -1, 1,
//     -1, 0,
//     -1, -1
// };
// int op2[4][2] = {
//     1, 0,
//     0, 1,
//     -1, 0,
//     0, -1
// };

// int n, m;
// string mp[N];
// int id[N][N];

// int fa[N*N], bad[N*N], siz[N*N];

// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     if(a == b) return;
//     fa[a] = b;
//     siz[b] += siz[a];
//     if(bad[a] || bad[b]) {
//         bad[b] = 1;
//         siz[b] = n*m+5;
//     }
// }

// void solve(){
//     cin >> n >> m;
//     int tot = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> mp[i];
//         mp[i] = ' ' + mp[i] + ' ';
//         for(int j = 1;j <= m;j++){
//             id[i][j] = ++tot;
//             fa[tot] = tot;
//             siz[tot] = 1;
//         }
//     }
//     mp[0] = mp[n+1] = string(m+5, '.');

//     for(int i = 1;i <= n;i++){
//         if(mp[i][1] == '.') bad[id[i][1]] = 1;
//         if(mp[i][m] == '.') bad[id[i][m]] = 1;
//     }
//     for(int j = 1;j <= m;j++) {
//         if(mp[1][j] == '.') bad[id[1][j]] = 1;
//         if(mp[n][j] == '.') bad[id[n][j]] = 1;
//     }

//     array<int, 2>fans({0, 0});

//     for(int i = 2;i < n;i++){
//         for(int j = 2;j < m;j++){
//             int f = 0;
//             for(int ii = i-1;ii <= i+1;ii++){
//                 for(int jj = j-1;jj <= j+1;jj++) if(!(ii == i && jj == j)){
//                     if(mp[ii][jj] == '.') {
//                         f = 1;
//                         break;
//                     }
//                 }
//             }
//             if(f == 0){
//                 for(int ii = 1;ii <= n;ii++) mp[ii] = mp[0];
//                 for(int ii = i-1;ii <= i+1;ii++){
//                     for(int jj = j-1;jj <= j+1;jj++) if(!(ii == i && jj == j)){
//                         mp[ii][jj] = '#';
//                     }
//                 }
//                 for(int ii = 1;ii <= n;ii++){
//                     for(int jj = 1;jj <= m;jj++) {
//                         cout << mp[ii][jj];
//                     }
//                     cout << endl;
//                 }
//                 return;
//             }
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) if(mp[i][j] == '.'){
//             for(int k = 0;k < 8;k++){
//                 int x = i + op[k][0], y = j + op[k][1];
//                 if(x < 1 || x > n || y < 1 || y > m || mp[x][y] == '#') continue;

//                 merg(id[i][j], id[x][y]);
//             }
//         }
//     }

//     int mn = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) if(mp[i][j] == '.'){
//             if(mn == 0 || siz[find(id[i][j])] < siz[mn]) mn = find(id[i][j]);
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) if(mp[i][j] == '.' && find(id[i][j]) == mn){
//             for(int k = 0;k < 8;k++){
//                 int x = i + op[k][0], y = j + op[k][1];
//                 if(x < 1 || x > n || y < 1 || y > m || mp[x][y] == '.') continue;
//                 mp[x][y] = '*';
//             }
//         }
//     }


//     vector<vector<int>>d(n+5, vector<int>(m+5));
//     queue<array<int,2>>que;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) if(mp[i][j] == '*'){
//             for(int k = 0;k < 4;k++){
//                 int x = i + op2[k][0], y = j + op2[k][1];
//                 if(x < 1 || x > n || y < 1 || y > m) continue;
//                 if(mp[x][y] == '*') d[i][j]++;
//             }
//             if(d[i][j] <= 1)
//                 que.push({i,j});
//         }            
//     }

//     while(que.size()){
//         auto [i, j] = que.front();
//         que.pop();
//         mp[i][j] = '.';
//         d[i][j]--;
//             for(int k = 0;k < 4;k++){
//                 int x = i + op2[k][0], y = j + op2[k][1];
//                 if(x < 1 || x > n || y < 1 || y > m || mp[x][y] != '*') continue;
//                 d[x][y]--;
//                 if(d[x][y] <= 1) que.push({x, y});
//             }
//     }

//     // cerr << mn << endl;

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) {
//             // cerr << find(id[i][j]) << ' ';
//             if(mp[i][j] == '*') cout << '#';
//             else cout << '.';
//         }            
//         // cerr << endl;
//         cout << endl;
//     }
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()

// int op8[8][2] = {
//     0, 1, 
//     0, -1,
//     1, 0,
//     1, 1, 
//     1, -1,
//     -1, 0,
//     -1, 1,
//     -1, -1
// };

// const int D = 0;
// const int R = 1;
// const int U = 2;
// const int L = 3;
// int op4[4][2] = {
//     1, 0, 
//     0, 1,
//     -1, 0,
//     0, -1
// };
// char cdir[4] = {'D', 'R', 'U', 'L'};

// void solve(){
//     int n, m;
//     cin >> n >> m;
    
//     vector<string>mp(n+5);
//     vector<vector<int>>id(n+5, vector<int>(m+5));
//     vector<int>fa(n*m+5);
//     iota(all(fa), 0);
//     int tot = 0;

//     auto find = [&](auto self, int x) -> int {
//         return fa[x] == x ? x : fa[x] = self(self, fa[x]);
//     };
//     auto merg = [&](int a, int b) -> void {
//         a = find(find, a);
//         b = find(find, b);
//         if(a == b) return;
//         fa[a] = b;
//     };

//     for(int i = 1;i <= n;i++) {
//         cin >> mp[i];
//         mp[i] = '.' + mp[i] + '.';
//         for(int j = 1;j <= m;j++){
//             id[i][j] = ++tot;
//         }
//     }
//     mp[0] = mp[n+1] = string(m+5, '.');


//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             int f = 1;
//             for(int k = 0;k < 8;k++){
//                 int x = i + op8[k][0], y = j + op8[k][1];
//                 if(mp[x][y] != '#'){
//                     f = 0;
//                     break;
//                 }
//             }
//             if(f){
//                 for(int k = 0;k < 8;k++){
//                     int x = i + op8[k][0], y = j + op8[k][1];
//                     mp[x][y] = 'a';
//                 }
//                 for(int I = 1;I <= n;I++){
//                     for(int J = 1;J <= m;J++){
//                         if(mp[I][J] == 'a') cout << '#';
//                         else cout << '.';
//                     }
//                     cout << endl;
//                 }
//                 return;
//             }
//         }
//     }

//     vector<vector<int>>d(n+5, vector<int>(m+5));
//     queue<array<int, 2>>que;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) if(mp[i][j] == '#'){
//             for(int k = 0;k < 4;k++){
//                 int x = i + op4[k][0], y = j + op4[k][1];
//                 d[i][j] += (mp[x][y] == '#');
//             }
//             if(d[i][j] <= 1) que.push({i, j});
//         }
//     }

//     while(que.size()){
//         auto [i, j] = que.front();
//         que.pop();
//         d[i][j] = 0;
//         mp[i][j] = ' ';
//         for(int k = 0;k < 4;k++){
//             int x = i + op4[k][0], y = j + op4[k][1];
//             if(mp[x][y] == '#') {
//                 d[x][y]--;
//                 if(d[x][y] == 1) que.push({x, y});
//             }
//         }
//     }


//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) if(mp[i][j] == '.'){
//             for(int k = 0;k < 8;k++){
//                 int x = i + op8[k][0], y = j + op8[k][1];
//                 if(mp[x][y] != '.') continue;
//                 merg(id[i][j], id[x][y]);
//             }
//         }
//     }

//     int ze = find(find, 0);
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) if(mp[i][j] == '.' && find(find, id[i][j]) == ze){
//             mp[i][j] = ' ';
//         }
//     }
//     for(int i = 1;i <= n;i++) {
//         mp[i][0] = mp[i][m+1] = ' ';
//     }
//     mp[0] = mp[n+1] = string(m+5, ' ');
//     // for(int i = 1;i <= n;i++){
//     //     for(int j = 1;j <= m;j++) {
//     //         cerr << find(find, id[i][j]) << ' ';
//     //     }
//     //     cerr << endl;
//     // }

//     vector<set<array<int,2>>>cyc(n*m+10);
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++)if(mp[i][j] == '.'){
//             int pid = find(find, id[i][j]);
//             for(int k = 0;k < 8;k++){
//                 int x = i + op8[k][0], y = j + op8[k][1];
//                 if(mp[x][y] == '#'){
//                     cyc[pid].insert({x, y});
//                 }
//             }
//         }
//     }
    
//     vector<vector<int>>vis(n+5, vector<int>(m+5)), good(n+5, vector<int>(m+5)), dfn(n+5, vector<int>(m+5));
//     auto dfs = [&](auto self, int i, int j, int dir, int pre) -> int {
//         dfn[i][j] = ++tot;
//         // cerr << i << ' ' << j << ' ' << cdir[dir] << ' ' << cdir[pre] << endl;
//         for(int k = (dir+1)%4;k != (dir+2)%4;k = (k+3)%4) if(k != pre){
//             int x = i + op4[k][0], y = j + op4[k][1];
//             if(mp[x][y] != '#' || !vis[x][y]) continue;
//             if(dfn[x][y]){
//                 // cerr << x << " " << y << ' ' << dfn[x][y] << endl;
//                 good[i][j] = dfn[x][y];
//                 return dfn[x][y];
//             }else{
//                 int ret = self(self, x, y, k, (dir+2)%4);
//                 if(ret){
//                     good[i][j] = ret;
//                     if(ret == dfn[i][j]) return 0;
//                     else return ret;
//                 }
//             }
//         }
//         mp[i][j] = ' ';
//         return 0;
//     };

//     int mn;

//     for(int i = 1;i <= n*m;i++) if(cyc[i].size()){
//         // cerr << i << endl;
//         mn = i;
//         tot = 0;
//         for(auto [x, y] : cyc[i]){
//             vis[x][y] = 1;
//             // cerr << x <<  ' ' << y << endl;
//         }
//         for(auto [x, y] : cyc[i]) {
//             if(mp[x][y+1] == '.'){
//                 // cerr << x << ' ' << y << endl;
//                 dfs(dfs, x, y, D, U);
//                 break;
//             }
//         }
//         auto it = cyc[i].begin();
//         while(it != cyc[i].end()){
//             auto [x, y] = *it;
//             vis[x][y] = dfn[x][y] = 0;
//             if(!good[x][y]){
//                 it = cyc[i].erase(it);
//             }else{
//                 good[x][y] = 0;
//                 it = next(it);
//             }
//         }
//     }

//     for(int i = 1;i <= n*m;i++) if(cyc[i].size() && cyc[i].size() < cyc[mn].size()) mn = i;

//     for(auto [x, y] : cyc[mn]) mp[x][y] = 'a';

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             if(mp[i][j] == 'a') cout << '#';
//             else cout << '.';
//         }
//         cout << endl;
//     }

//     // cerr << "END\n";
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// // #define int long long
// // const int inf = 0x3f3f3f3f3f3f3f3f;

// int op8[8][2] = {
//     0, 1, 
//     0, -1,
//     1, 0,
//     1, 1, 
//     1, -1,
//     -1, 0,
//     -1, 1,
//     -1, -1
// };
// int op[4][2] = {
//     0, 1,
//     0, -1,
//     1, 0,
//     -1, 0
// };

// void solve(){
//     int n, m;
//     cin >> n >> m;
    
//     vector<string>mp(n+5);

//     for(int i = 1;i <= n;i++) {
//         cin >> mp[i];
//         mp[i] = ' ' + mp[i] + ' ';
//     }
//     mp[0] = mp[n+1] = string(m+5, ' ');

//     queue<array<int, 2>>que;

//     for(int i = 1;i <= n;i++){
//         if(mp[i][1] == '.') que.push({i, 1}), mp[i][1] = ' ';
//         if(mp[i][m] == '.') que.push({i, m}), mp[i][m] = ' ';
//     }
//     for(int j = 1;j <= m;j++){
//         if(mp[1][j] == '.') que.push({1, j}), mp[1][j] = ' ';
//         if(mp[n][j] == '.') que.push({n, j}), mp[n][j] = ' ';
//     }
 
//     while(que.size()){
//         auto [i, j] = que.front();
//         que.pop();
//         for(int k = 0;k < 8;k++){
//             int x = i + op8[k][0], y = j + op8[k][1];
//             if(mp[x][y] == '.') que.push({x, y}), mp[x][y] = ' ';
//         }
//     }


//     int X = 0, Y = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) if(mp[i][j] == '.'){
//             X = i;
//             Y = j;
//             break;
//         }
//         if(X) break;
//     }
//     X--;

//     for(int i = X;i >= 1;i--) mp[i][Y] = ' ';

//     vector<vector<int>>vis(n+5, vector<int>(m+5));
//     vector<vector< array<int,2> >>pre(n+5, vector<array<int,2>>(m+5));
//     que.push({X, Y+1});
//     vis[X][Y+1] = 1;
//     pre[X][Y+1] = {X, Y};
//     while(que.size()){
//         auto [i, j] = que.front();
//         que.pop();
//         for(int k = 0;k < 4;k++){
//             int x = i+op[k][0], y = j+op[k][1];
//             if(mp[x][y] == '#' && !vis[x][y]){
//                 vis[x][y] = 1;
//                 pre[x][y] = {i, j};
//                 que.push({x, y});
//             }
//         }
//     }

//     int x = X, y = Y-1;
//     while(1){
//         mp[x][y] = 'a';
//         auto [i, j] = pre[x][y];
//         x = i, y = j;
//         if(x == X && y == Y) break;
//     }
//     mp[x][y] = 'a';

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             if(mp[i][j] == 'a') cout << '#';
//             else cout << '.';
//         }
//         cout << endl;
//     }

// }

// signed main(){
//     IO;

//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }


// #include<bits/stdc++.h>
// #define all(x) (x).begin(), (x).end()
// using namespace std;

// void solve(){
//     int n, k, x;
//     cin >> n >> k >> x;

//     vector<vector<int>>seg, zer;
//     vector<int>vis(n+5);
//     for(int i = 1;i <= n;i++) {
//         int v = x ^ i;
//         if(v > n){
//             zer.push_back(vector<int>(0));
//             while(i%4) i--;
//             if(i+3 > n){
//                 cout << "NO\n";
//                 return;
//             }
//             for(int j = i;j <= i+3;j++){
//                 vis[j] = 1;
//                 if(j) zer.back().push_back(j);
//             }
//             i += 3;
//         }
//     }

//     for(int i = 1;i <= n;i++) if(!vis[i]){
//         int v = x ^ i;
//         if(v && vis[v]){
//             cout << "NO\n";
//             return;
//         }
//         vis[i] = vis[v] = 1;
//         seg.push_back({});
//         seg.back().push_back(i);
//         if(v) seg.back().push_back(v);
//     }

//     if((seg.size()%2) != (k%2) || k > seg.size()){
//         cout << "NO\n";
//     }else{
//         cout << "YES\n";
//         for(int i = k;i < seg.size();i++) seg[0].insert(seg[0].end(), all(seg[i]));
//         for(auto &vec : zer) seg[0].insert(seg[0].end(), all(vec));
//         for(int i = 0;i < k;i++){
//             cout << seg[i].size() << ' ';
//             for(auto e : seg[i]) cout << e << ' ';
//             cout << endl;
//         }
//     }
// }

// signed main(){

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// #define all(x) (x).begin(), (x).end()
// #define int long long
// using namespace std;

// int lowbit(int x){
//     return x & -x;
// }
// int bit(int x){
//     for(int i = 0;(1<<i) <= x;i++) if((x>>i)&1) {
//         return i;
//     }
//     return 0;
// }

// void solve(){
//     int n, sum = 0;
//     cin >> n;
//     vector<int>a(n+5), ad(35), dv(35), adf(35), dvf(35);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         sum += a[i];
//     }
//     if(sum % n){
//         cout << "No\n";
//         return;
//     }

//     int av = sum / n;

//     for(int i = 1;i <= n;i++) if(a[i] != av){
//         int d = abs(a[i] - av);
//         if(lowbit(d) == d){ 
//             if(a[i] < av){
//                 ad[bit(d)]++;
//                 adf[bit(d)]++;
//             }else{
//                 dv[bit(d)]++;
//                 dvf[bit(d)]++;
//             }
//         }else{
//             int tmp = d + lowbit(d);
//             if(lowbit(tmp) == tmp){
//                 if(a[i] < av){
//                     ad[bit(tmp)]++;
//                     dv[bit(lowbit(d))]++;
//                 }else{
//                     dv[bit(tmp)]++;
//                     ad[bit(lowbit(d))]++;
//                 }
//             }else{
//                 cout << "No\n";
//                 return;
//             }
//         }
//     }

//     // for(int i = 0;i <= 5;i++){
//     //     cerr << ad[i] << ' ' << adf[i] << ' ' << dv[i] << ' ' << dvf[i] << endl;
//     // }

//     for(int i = 0;i <= 30;i++){
//         if(ad[i] < dv[i]){
//             int d = dv[i] - ad[i];
//             if(d % 2){
//                 cout << "No\n";
//                 return;
//             }
//             d /= 2;
//             if(dvf[i] < d){
//                 cout << "No\n";
//                 return;
//             }
//             dv[i+1] += d;
//         }else if(ad[i] > dv[i]){
//             int d = ad[i] - dv[i];
//             if(d % 2){
//                 cout << "No\n";
//                 return;
//             }
//             d /= 2;
//             if(adf[i] < d){
//                 cout << "No\n";
//                 return;
//             }
//             ad[i+1] += d;
//         }
//     }

//     cout << "Yes\n";
// }

// signed main(){

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;

// int inv[N];
// int qpow(int a, int b){
//     int ret = 1;
//     while(b){
//         if(b & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return ret;
// }
// void get_inv(){
//     inv[0] = 1;
//     for(int i = N-1;i >= 1;i--) inv[i] = qpow(i, mod-2);
// }

// void solve(){
//     int n, k = 0;
//     string a, b;
//     cin >> n >> a >> b;

//     for(int i = 0;i < n;i++) k += (a[i] == b[i]);

//     vector<int>f(n+5);
//     f[0] = 1;

//     for(int i = 1;i < n;i++){
//         f[i] = ((n + (i*f[i-1]%mod))%mod) * inv[n-i] % mod;
//     }

//     int ans = 0;
//     for(int i = k;i < n;i++) ans = (ans + f[i]) % mod;
//     cout << ans << endl;
// }


// signed main(){

//     IO;
//     get_inv();
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;



// void solve(){
//     int n, ans = 1;
//     string s;
//     cin >> n >> s;
//     s = ' ' + s;
//     vector<vector<int>>g(n+5);

//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     vector<vector<int>>f(n+5, vector<int>(n+5));

//     vector<queue<array<int,4>>>que(n+5); //u, low, pre, len
//     for(int i = 1;i <= n;i++){
//         f[i][i] = 1;
//         for(auto v : g[i]) que[i].push({v, v, i, 2});
//     }
//     // cerr << "DEBUG\n";

//     for(int len = 2;len <= n;len++){
//         // cerr << len << endl;
//         for(int i = 1;i <= n;i++){
//             while(que[i].size() && que[i].front()[3] <= len){
//                 auto [u, low, pre, L] = que[i].front();
//                 que[i].pop();
//                 f[i][u] = max(f[i][pre], f[low][u]);
//                 if(s[u] == s[i]){
//                     if(L > 2) f[i][u] = max(f[i][u], f[low][pre] + 2);
//                     else f[i][u] = max(f[i][u], 2ll);
//                 }
//                 f[u][i] = f[i][u];
//                 for(auto v : g[u]) if(v != pre){
//                     que[i].push({v, low, u, L + 1});
//                 }
//                 ans = max(ans, f[i][u]);
//                 // cerr << i << ' ' << u << ' ' << ans << endl;
//             }
//         }
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// // #define endl '\n'
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;



// int solve(){
//     int n, cur;
//     cin >> n;
//     array<int, 2>ans({1, 2});

//     cout << "? " << ans[0] << ' ' << ans[1] << endl;
//     cin >> cur;
//     if(cur * 2 >= n){
//         cout << "! " << ans[0] << ' ' << ans[1] << endl;
//         cin >> n;
//         return n;
//     }

//     for(int i = 3;i <= n;i++){
//         int t[2];
//         cout << "? " << ans[0] << ' ' << i << endl;
//         cin >> t[0];
//         if(t[0] == -1) return -1;
//         cout << "? " << ans[1] << ' ' << i << endl;
//         cin >> t[1];
//         if(t[1] == -1) return -1;
//         int mx = 0;
//         if(t[1] > t[0]) mx = 1;
//         if(t[mx] > cur){
//             cur = t[mx];
//             ans[mx ^ 1] = i;
//         }

//         if(cur * 2 >= n){
//             cout << "! " << ans[0] << ' ' << ans[1] << endl;
//             cin >> n;
//             return n;
//         }
//     }
//     return 1;
// }


// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--){
//         if(solve() == -1) return 0;
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;



// void solve(){
//     int n;
//     cin >> n;
//     if(n & 1){
//         cout << "NO\n";
//     }else{
//         cout << "YES\n";
//         n /= 2;
//         for(int i = 1;i <= n;i++) cout << "AAB";
//         cout << endl;
//     }
// }


// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--){
//         solve();
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;

// pair<int,int> f(int x){
//     int R = x % 10;
//     while(x >= 10) x /= 10;
//     int L = x;
//     return {L, R};
// }

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++){
//         if(a[i] < a[i-1]){
//             cout << "NO\n";
//             return;
//         }else if(a[i] >= 10){
//             auto p = f(a[i]);
//             if(p.first >= a[i-1] && p.first <= p.second) a[i] = p.second;
//         }
//     }
//     cout << "YES\n";
// }


// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--){
//         solve();
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     string s[2];
//     cin >> s[0] >> s[1];
//     s[0] = ' ' + s[0];
//     s[1] = ' ' + s[1];

//     vector<int>vis[2];
//     vis[0] = vis[1] = vector<int>(n+5);

//     queue<array<int, 2>>que;
//     que.push({1, n});
//     vis[1][n] = 1;
//     while(que.size()){
//         auto [x, y] = que.front();
//         que.pop();
//         if(x == 0 && y == 1){
//             cout << "YES\n";
//             return;
//         }
//         if(y-1 < 1 || s[x][y-1] != '>') continue;
        
//         int nx = x, ny = y-2;
//         if(ny >= 1 && !vis[nx][ny]) {
//             vis[nx][ny] = 1;
//             que.push({nx, ny});
//         }
//         nx = x^1, ny = y-1;
//         if(ny >= 1 && !vis[nx][ny]) {
//             vis[nx][ny] = 1;
//             que.push({nx, ny});
//         }
//     }

//     cout << "NO\n";
// }


// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--){
//         solve();
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;


// void solve(){
//     int n;
//     string a;
//     cin >> a;
//     n = a.size();
//     a = ' ' + a;

//     int ans = 0;
//     for(int k = 2;k <= n;k++){
//         string b = " ";
//         for(int i = k;i <= n;i++) b.push_back(a[i]);
//         int m = b.size()-1;
//         vector<int>ne(m + 5);
        
//         for(int i = 2, j = 0;i <= m;i++){
//             while(j && b[i] != b[j+1] && b[i] != '?' && b[j+1] != '?') j = ne[j];
//             if(b[i] == b[j+1] || b[i] == '?' || b[j+1] == '?') j++;
//             ne[i] = j;
//         }
//         for(int i = max(1ll, k-m), j = 0; i <= k-1; i++){
//             while(j && a[i] != b[j+1] && a[i] != '?' && b[j+1] != '?') j = ne[j];
//             if(a[i] == b[j + 1] || a[i] == '?' || b[j + 1] == '?') j++;
//             if(i == k-1) ans = max(ans, j*2);
//         }
//     }

//     cout << ans << endl;
// }


// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--){
//         solve();
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;


// void solve(){
//     int n;
//     string a;
//     cin >> a;
//     n = a.size();
//     a = ' ' + a;

//     int ans = 0;
//     for(int len = 2;len <= n;len += 2){
//         vector<int>pre(n+5);
//         int x = len / 2;
//         for(int i = 1;i + x <= n;i++){
//             pre[i] = pre[i-1];
//             if(a[i] == a[i+x] || a[i] == '?' || a[i+x] == '?') pre[i]++;
//         }
//         for(int i = 1;i + x <= n;i++){
//             if(pre[i+x-1] - pre[i-1] == x) ans = len;
//         }
//     }

//     cout << ans << endl;
// }


// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--){
//         solve();
//     }

//     return 0;
// }


// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;


// void solve(){
//     int n, k, cnt = 0;
//     cin >> n >> k;
//     vector<int>a(n+5), b(n+5);
//     for(int i = 1;i <= n;i++){
//         int r = min(i + k-1, n);
//         int len = r - i + 1;
//         int d1 = len / 2;
//         for(int j = 1;j <= d1;j++) a[i+d1-j] = j + i - 1;
//         int d2 = len - d1;
//         for(int j = 1;j <= d2;j++) a[r-j+1] = j + i - 1 + d1;
//         ++cnt;
//         for(int j = i;j <= r;j++) b[j] = cnt;
//         i = r;
//     }

//     for(int i = 1;i <= n;i++) cout << a[i] << " \n"[i==n];
//     cout << cnt << endl;
//     for(int i = 1;i <= n;i++) cout << b[i] << " \n"[i==n];
// }


// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--){
//         solve();
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;


// void solve(){
//     int n, k;
//     cin >> n >> k;
//     if(k && k >= n-1) cout << 1 << endl;
//     else cout << n << endl;
// }


// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--){
//         solve();
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;


// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<int>a(n*2+5), p1(n+5), p2(n+5);
//     for(int i = 1;i <= n*2;i++){
//         cin >> a[i];
//         if(p1[a[i]]) p2[a[i]] = i;
//         else p1[a[i]] = i;
//     }

//     vector<int>a1, a2;
//     for(int i = 1;i <= n;i++) {
//         if(p2[i] <= n){
//             if(a1.size() + 2 <= k*2){
//                 a1.push_back(i);
//                 a1.push_back(i);
//             }
//         }else if(p1[i] > n){
//             if(a2.size() + 2 <= k*2){
//                 a2.push_back(i);
//                 a2.push_back(i);
//             }
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         if(p1[i] <= n && p2[i] > n && a1.size() < k*2){
//             a1.push_back(i);
//             a2.push_back(i);
//         }
//     }

//     for(auto e : a1) cout << e << ' ';
//     cout << endl;
//     for(auto e : a2) cout << e << ' ';
//     cout << endl;
// }


// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--){
//         solve();
//     }

//     return 0;
// }





// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// using namespace std;
// const int N = 1e6 + 10;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5), cnt(n+5);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         cnt[a[i]]++;
//     }

//     int f = 0;
//     for(int i = 0;i <= n;i++){
//         if(cnt[i] == 0){
//             cout << i << endl;
//             return;
//         }
//         if(cnt[i] == 1){
//             f++;
//             if(f == 2){
//                 cout << i << endl;
//                 return;
//             }
//         }
//     }
// }


// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--){
//         solve();
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int unsigned long long
// #define endl '\n'
// using namespace std;
// const int N = 2e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// const int P = 233;
// int pw[N];

// int Log[N];

// class ST{
// public:
//     vector<vector<int>>f;
//     function<int(int,int)>cmp;

//     ST(int n, string s, function<int(int,int)>cmp) : f(n+5, vector<int>(20)), cmp(cmp) {
//         for(int i = 1;i <= n;i++) f[i][0] = s[i];
//         for(int j = 1;j < 20 ;j++){
//             for(int i = 1;i <= n && i + (1 << j) - 1 <= n;i++){
//                 f[i][j] = cmp(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
//             }
//         }
//     }

//     int query(int l, int r){
//         int s = Log[r - l + 1];
//         // cerr << l << ' ' << r << ' ' << s << endl;
//         return cmp(f[l][s], f[r - (1 << s) + 1][s]);
//     }
// };

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     string s, ss[2];
//     cin >> s;
//     s = ' ' + s + ' ';
//     ss[0] = ss[1] = s;

//     vector<int>H(n+5), rH(n+5);
//     for(int i = 1;i <= n;i++){
//         H[i] = (H[i-1] * P + s[i]) % mod;
//     }
//     reverse(s.begin(), s.end());
//     for(int i = 1;i <= n;i++){
//         rH[i] = (rH[i-1] * P + s[i]) % mod;
//     }
//     reverse(s.begin(), s.end());

//     auto gethash = [&](vector<int>&H, int l, int r) -> int {
//         if(l > r) return 0;
//         return (H[r] - (H[l-1] * pw[r-l+1] % mod) + mod) % mod;
//     };

//     for(int i = 1;i <= n;i++){
//         ss[i&1][i+1] = ss[i&1][i];
//     }

//     ST mxt[2] = {ST(n, ss[0], [&](int i, int j)->int {return max(i, j);}), ST(n, ss[1], [&](int i, int j)->int {return max(i, j);})};
//     ST mnt[2] = {ST(n, ss[0], [&](int i, int j)->int {return min(i, j);}), ST(n, ss[1], [&](int i, int j)->int {return min(i, j);})};

//     while(q--){
//         int l, r;
//         cin >> l >> r;
//         int len = r - l + 1;
//         int ans = (len-1) * (2+len) / 2;

//         ans -= len;
//         if(len > 1){
//             int hf = len / 2;
//             int l1 = l, r1 = l1 + hf - 1;
//             int r2 = r, l2 = r - hf + 1;
//             if(gethash(H, l1, r1) != gethash(rH, n-r2+1, n-l2+1)) ans += len;
//         }

//         int mx[2], mn[2];
//         mx[0] = mxt[0].query(l + (l&1), r - (r&1));
//         mn[0] = mnt[0].query(l + (l&1), r - (r&1));
//         mx[1] = mxt[1].query(l + ((l&1) == 0), r - ((r&1) == 0));
//         mn[1] = mnt[1].query(l + ((l&1) == 0), r - ((r&1) == 0));

//         if(mx[0] == mn[0] && mx[1] == mn[1]){
//             int cnt = (len+1)/2 - 1;
//             if(len & 1) cnt --;
//             if(cnt > 0)
//             ans -= cnt * (3 + 3+(cnt-1)*2) / 2;

//             if(mx[0] == mx[1]){
//                 ans = 0;
//             }
//         }

//         cout << ans << endl;
//     }


// }


// signed main(){

//     IO;

//     pw[0] = 1;
//     for(int i = 1;i < N;i++) pw[i] = pw[i-1] * P % mod;

//     for(int i = 2;i < N;i++) Log[i] = Log[i/2] + 1;

//     int T = 1;
//     cin >> T;
//     while(T--){
//         solve();
//     }

//     return 0;
// }





// #include<bits/stdc++.h>
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define int unsigned long long
// #define endl '\n'
// using namespace std;
// const int N = 2e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// const int P = 233;
// int pw[N];

// int Log[N];

// class ST{
// public:
//     vector<vector<int>>f;
//     function<int(int,int)>cmp;

//     ST(int n, string s, function<int(int,int)>cmp) : f(n+5, vector<int>(20)), cmp(cmp) {
//         for(int i = 1;i <= n;i++) f[i][0] = s[i];
//         for(int j = 1;j < 20 ;j++){
//             for(int i = 1;i <= n && i + (1 << j) - 1 <= n;i++){
//                 f[i][j] = cmp(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
//             }
//         }
//     }

//     int query(int l, int r){
//         int s = Log[r - l + 1];
//         // cerr << l << ' ' << r << ' ' << s << endl;
//         return cmp(f[l][s], f[r - (1 << s) + 1][s]);
//     }
// };

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     string s, ss[2];
//     cin >> s;
//     s = ' ' + s + ' ';
//     ss[0] = ss[1] = s;

//     vector<int>H(n+5), rH(n+5);
//     for(int i = 1;i <= n;i++){
//         H[i] = (H[i-1] * P + s[i]) % mod;
//     }
//     reverse(s.begin(), s.end());
//     for(int i = 1;i <= n;i++){
//         rH[i] = (rH[i-1] * P + s[i]) % mod;
//     }
//     reverse(s.begin(), s.end());

//     auto gethash = [&](vector<int>&H, int l, int r) -> int {
//         if(l > r) return 0;
//         return (H[r] - (H[l-1] * pw[r-l+1] % mod) + mod) % mod;
//     };

//     for(int i = 1;i <= n;i++){
//         ss[i&1][i+1] = ss[i&1][i];
//     }

//     ST mxt[2] = {ST(n, ss[0], [&](int i, int j)->int {return max(i, j);}), ST(n, ss[1], [&](int i, int j)->int {return max(i, j);})};
//     ST mnt[2] = {ST(n, ss[0], [&](int i, int j)->int {return min(i, j);}), ST(n, ss[1], [&](int i, int j)->int {return min(i, j);})};

//     while(q--){
//         int l, r;
//         cin >> l >> r;
//         int len = r - l + 1;
//         int ans = (len-1) * (2+len) / 2;

//         ans -= len;
//         if(len > 1){
//             int hf = len / 2;
//             int l1 = l, r1 = l1 + hf - 1;
//             int r2 = r, l2 = r - hf + 1;
//             if(gethash(H, l1, r1) != gethash(rH, n-r2+1, n-l2+1)) ans += len;
//         }

//         int mx[2], mn[2];
//         mx[0] = mxt[0].query(l + (l&1), r - (r&1));
//         mn[0] = mnt[0].query(l + (l&1), r - (r&1));
//         mx[1] = mxt[1].query(l + ((l&1) == 0), r - ((r&1) == 0));
//         mn[1] = mnt[1].query(l + ((l&1) == 0), r - ((r&1) == 0));

//         if(mx[0] == mn[0] && mx[1] == mn[1]){
//             int cnt = (len+1)/2 - 1;
//             if(len & 1) cnt --;
//             if(cnt > 0)
//             ans -= cnt * (3 + 3+(cnt-1)*2) / 2;

//             if(mx[0] == mx[1]){
//                 ans = 0;
//             }
//         }

//         cout << ans << endl;
//     }


// }


// signed main(){

//     IO;

//     pw[0] = 1;
//     for(int i = 1;i < N;i++) pw[i] = pw[i-1] * P % mod;

//     for(int i = 2;i < N;i++) Log[i] = Log[i/2] + 1;

//     int T = 1;
//     cin >> T;
//     while(T--){
//         solve();
//     }

//     return 0;
// }


