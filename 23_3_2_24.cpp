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