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