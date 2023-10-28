// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m, a[N], b[N];


// bool check(int x){
//     for(int i = 1, j = x + 1;j <= n;j++, i++){
//         if(a[i] >= b[j]) return false;
//     }
//     return true;
// }

// void solve(){
//     cin >> n >> m;
//     a[1] = 1;
//     for(int i = 2;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];

//     sort(a + 1, a + 1 + n);
//     sort(b + 1, b + 1 + n);

//     // for(int i = 1;i <= n;i++) cerr << a[i] << ' ';
//     // cerr << endl;
//     // for(int i = 1;i <= n;i++) cerr << b[i] << ' ';

//     int l = 0, r = n;
//     while(l <= r){
//         int mid = l + r >> 1;
//         if(check(mid)) r = mid - 1;
//         else l = mid + 1;
//     }
//     cout << l << endl;
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
// int a, b;

// void solve(){
//     cin >> a >> b;
//     cout << 2 << endl;
//     if(a + 2 > 1e9) cout << a - 1 << ' ' << a - 2 << endl;
//     else cout << a + 1 << ' ' << a + 2 << endl;
//     cout << a << ' ' << b << endl;
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
// int n, mp[2][N];

// void solve(){
//     cin >> n;   
//     int cur = 2*n - 1;
//     for(int i = 1;i < n;i++){
//         mp[!(i & 1)][i] = cur--;
//     }
//     for(int i = 1;i <= n;i++){
//         mp[i & 1][i] = cur--;
//     }
//     mp[1][n] = n*2;
//     for(int i = 1;i <= n;i++){
//         cout << mp[0][i] << ' ';
//     }
//     cout << endl;
//     for(int i = 1;i <= n;i++){
//         cout << mp[1][i] << ' ';
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
// const int N = 2e5 + 10;
// int n, a[N], d[2][N];

// void solve(){
//     cin >> n;   
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     if(n == 2){
//         if(a[1] > a[2]) cout << "NO\n";
//         else cout << "YES\n";
//         return;
//     }
//     for(int i = n - 1;i > 1;i--){
//         if(a[i] > a[i + 1]){
//             d[0][i]++;
//             d[0][i-1]++;
//         }
//     }
//     for(int i = 2;i < n;i++){
//         if(a[i] < a[i - 1]){
//             d[1][i]++;
//             d[1][i+1]++;
//             break;
//         }
//     }
//     for(int i = 1;i <= n;i++){
//         if(d[0][i] && d[0][i] == d[1][i]){
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
//     while(t--)solve();


//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;
// int n, m, ans[N], op[N];
// list<int>g[N];

// struct qur{
//     int dp, id;
// };
// list<qur>q[N];

// int tr[N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x){
//     while(x <= n){
//         tr[x] += 1;
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

// int dep[N];
// void dfs(int u, int f){
//     dep[u] = dep[f] + 1;
//     for(auto [dp, id] : q[u]){
//         ans[id] -= (getsum(n) - getsum(dp - 1));
//     }
//     add(dep[u]);
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//     }
//     for(auto [dp, id] : q[u]){
//         ans[id] += (getsum(n) - getsum(dp - 1));
//     }
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     int d = n + 1;
//     for(int i = 1;i <= m;i++){
//         int x;
//         cin >> op[i] >> x;
//         if(op[i] == 1){
//             d = x;
//         }else{
//             q[x].push_back({d, i});
//         }   
//     }

//     dfs(1, 0);

//     for(int i = 1;i <= m;i++) if(op[i] == 2){
//         cout << ans[i] << '\n';
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// const int N = 2e5 + 10;
// int n, m, ans[N], op[N];
// list<int>g[N];

// struct qur{
//     int dp, id;
// };
// list<qur>q[N];
// struct node{
//     int l, r, sum;
// }tr[N * 40];
// int rt[N], tot;

// void merg(int& x, int y){
//     if(!x || !y) x |= y;
//     else{
//         tr[x].sum += tr[y].sum;
//         merg(tr[x].l, tr[y].l);
//         merg(tr[x].r, tr[y].r);
//     }
// }
// void add(int &id, int l, int r, int x){
//     if(!id) id = ++tot;
//     tr[id].sum++;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     if(x <= mid) add(ls, l, mid, x);
//     else add(rs, mid + 1, r, x);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(!id) return 0;
//     if(ql <= l && r <= qr) return tr[id].sum;
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
// }

// int dep[N];
// void dfs(int u, int f){
//     dep[u] = dep[f] + 1;
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         merg(rt[u], rt[v]);
//     }
//     add(rt[u], 1, n, dep[u]);
//     for(auto [dp, id] : q[u]){
//         ans[id] = query(rt[u], 1, n, dp, n);
//     }
// }



// void solve(){
//     cin >> n >> m;
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     int d = n + 1;
//     for(int i = 1;i <= m;i++){
//         int x;
//         cin >> op[i] >> x;
//         if(op[i] == 1){
//             d = x;
//         }else{
//             q[x].push_back({d, i});
//         }   
//     }

//     dfs(1, 0);

//     for(int i = 1;i <= m;i++) if(op[i] == 2){
//         cout << ans[i] << '\n';
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
// #define dp f[i] 
// const int N = 90;
// int n, m, mp[N][N], f[N][N][N], pw[N];


// void solve(){
//     cin >> n >> m;
//     pw[1] = 2;
//     for(int i = 2;i <= m;i++) pw[i] = 2 * pw[i - 1];
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             cin >> mp[i][j];
//         }

//         for(int j = 1;j <= m;j++){
//             for(int k = m;k >= j;k--){
//                 int id = (j - 1) + (m - k);
//                 if(!id) continue;
//                 if(j == 1) dp[j][k] = dp[j][k+1] + mp[i][k+1] * pw[id];
//                 else if(k == m) dp[j][k] = dp[j-1][k] + mp[i][j-1] * pw[id];
//                 else dp[j][k] = max(dp[j-1][k] + mp[i][j-1] * pw[id], dp[j][k+1] + mp[i][k+1] * pw[id]);
//             }
//         }

//         int mx = 0;
//         for(int j = 1;j <= m;j++){
//             mx = max(mx, dp[j][j] + mp[i][j] * pw[m]);
//         }
//         ans += mx;
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// const int N = 3e5 + 10;
// int n, m, q, fa[N], p[N], pid[N];

// struct node{
//     int l, r;
//     int sum;
// }tr[N * 50];
// int rt[N], tot;
// void merge(int& x, int y){
//     if(!x || !y) x |= y;
//     else{
//         tr[x].sum += tr[y].sum;
//         merge(tr[x].l, tr[y].l);
//         merge(tr[x].r, tr[y].r);
//     }
// }
// void insert(int& id, int l, int r, int x){
//     if(!id) id = ++tot;
//     tr[id].sum++;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     if(x <= mid) insert(ls, l, mid, x);
//     else insert(rs, mid + 1, r, x);
// }
// int _rak(int id, int l, int r, int k){
//     if(l == r) return pid[l];
//     int mid = l + r >> 1;
//     if(tr[ls].sum >= k) return _rak(ls, l, mid, k);
//     else return _rak(rs, mid + 1, r, k - tr[ls].sum);
// }
// int rak(int id, int k){
//     if(tr[id].sum < k) return -1;
//     return _rak(id, 1, n, k);
// }

// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     if(a == b) return;
//     merge(rt[a], rt[b]);
//     fa[b] = a;
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++){
//         fa[i] = i;
//         cin >> p[i];
//         pid[p[i]] = i;
//         insert(rt[i], 1, n, p[i]);
//     }
//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         merg(u, v);
//     }
//     cin >> q;
//     char op;
//     int u, v;
//     while(q--){
//         cin >> op >> u >> v;
//         if(op == 'B'){
//             merg(u, v);
//         }else{
//             cout << rak(rt[find(u)], v) << endl;
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// const int N = 1e5 + 10;
// int n, m, c[N], ans[N];
// list<int>g[N];

// struct node{
//     int l, r;
//     int sum, mx;
// }tr[N * 40];
// int rt[N], tot;

// void up(int id){
//     tr[id].mx = max(tr[ls].mx, tr[rs].mx);
//     tr[id].sum = (tr[id].mx == tr[ls].mx) * tr[ls].sum + (tr[id].mx == tr[rs].mx) * tr[rs].sum;
// }
// void insert(int& id, int l, int r, int x){
//     if(!id) id = ++tot;
//     if(l == r){
//         tr[id].sum = x;
//         tr[id].mx++;
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) insert(ls, l, mid, x);
//     else insert(rs, mid + 1, r, x);
//     up(id);
// }
// void merg(int& x, int y, int l, int r){
//     if(!x || !y) {
//         x |= y;
//         return;    
//     }
//     if(l == r){
//         tr[x].mx += tr[y].mx;
//         return;
//     }
//     int mid = l + r >> 1;
//     merg(tr[x].l, tr[y].l, l, mid);
//     merg(tr[x].r, tr[y].r, mid + 1, r);
//     up(x);
// }

// void dfs(int u, int f){
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         merg(rt[u], rt[v], 1, n);
//     }
//     insert(rt[u], 1, n, c[u]);
//     ans[u] = tr[rt[u]].sum;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> c[i];
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);

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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// const int N = 8e5 + 10;
// int n, m, p[N], ans, lson[N], rson[N], idx, root;
// list<int>num[N];

// struct node{
//     int l, r;
//     int sum;
// }tr[N * 20];
// int tot, rt[N];
// void insert(int& id, int l, int r, int x){
//     if(!id) id = ++tot;
//     tr[id].sum++;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     if(x <= mid) insert(ls, l, mid, x);
//     else insert(rs, mid + 1, r, x);
// }
// int rak(int id, int l, int r, int x){
//     if(l == r || !id) return 0;
//     int mid = l + r >> 1;
//     if(x <= mid) return rak(ls, l, mid, x);
//     else return tr[ls].sum + rak(rs, mid + 1, r, x);
// }
// void merg(int& x, int y){
//     if(!x || !y) x |= y;
//     else{
//         tr[x].sum += tr[y].sum;
//         merg(tr[x].l, tr[y].l);
//         merg(tr[x].r, tr[y].r);
//     }
// }

// void dfs(int& u){
//     if(!u) u = ++idx;
//     cin >> p[u];
//     if(p[u]) insert(rt[u], 1, n, p[u]), num[u].push_back(p[u]);
//     else{
//         dfs(lson[u]);
//         dfs(rson[u]);
//         if(num[lson[u]].size() > num[rson[u]].size()) swap(lson[u], rson[u]);
//         int le = lson[u], ri = rson[u];
//         int s1 = 0, s2 = 0;
//         for(auto x : num[le]){
//             int k = rak(rt[ri], 1, n, x);
//             s1 += k;
//             s2 += num[ri].size() - k;
//         }
//         ans += min(s1, s2);

//         num[u].splice(num[u].end(), num[le]);
//         num[u].splice(num[u].end(), num[ri]);

//         merg(rt[u], rt[lson[u]]);
//         merg(rt[u], rt[rson[u]]);
//     }
// }

// void solve(){
//     cin >> n;

//     dfs(root);

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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// const int N = 5000 + 10;
// int n, a[N], f[N], last[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         last[i] = 1e9;
//     }
//     last[0] = -1;
//     int ans = 1;
//     for(int i = 1;i <= n;i++){
//         int l = 0, r = i - 1;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(last[mid] < a[i]) l = mid + 1;
//             else r = mid - 1;
//         }
//         f[i] = r + 1;
//         last[f[i]] = min(last[f[i]], a[i]);
//         ans = max(ans, f[i]);
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 12000 + 10;
// int n, p[N];
// list<int>g[N];


// struct node{
//     int l, r;
//     int lismn, ldsmx;
// }tr[N * 40];
// int rt[N], tot;

// int getseg(){
//     tr[++tot].lismn = 1e17;
//     return tot;
// }
// void up(int id){
//     tr[id].lismn = min(tr[ls].lismn, tr[rs].lismn);
//     tr[id].ldsmx = max(tr[ls].ldsmx, tr[rs].ldsmx);
// }
// void clismn(int& id, int l, int r, int x, int im){
//     if(!id) id = getseg();
//     if(l == r){
//         tr[id].lismn = min(tr[id].lismn, im);
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) clismn(ls, l, mid, x, im);
//     else clismn(rs, mid + 1, r, x, im);
//     up(id);
// }
// void cldsmx(int& id, int l, int r, int x, int dm){
//     if(!id) id = getseg();
//     if(l == r){
//         tr[id].ldsmx = max(tr[id].ldsmx, dm);
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) cldsmx(ls, l, mid, x, dm);
//     else cldsmx(rs, mid + 1, r, x, dm);
//     up(id);
// }
// int getlism(int id, int l, int r, int x){
//     if(!id) return 0;
//     if(l == r) return x > tr[id].lismn ? l : 0;
//     int mid = l + r >> 1;
//     if(x > tr[rs].lismn) return getlism(rs, mid + 1, r, x);
//     else return getlism(ls, l, mid, x);
// }
// int getldsm(int id, int l, int r, int x){
//     if(!id) return 0;
//     if(l == r) return x < tr[id].ldsmx ? l : 0;
//     int mid = l + r >> 1;
//     if(x < tr[rs].ldsmx) return getldsm(rs, mid + 1, r, x);
//     else return getldsm(ls, l, mid, x);
// } 
// void merg(int& x, int y){
//     if(!x || !y) x |= y;
//     else{
//         tr[x].lismn = min(tr[x].lismn, tr[y].lismn);
//         tr[x].ldsmx = max(tr[x].ldsmx, tr[y].ldsmx);
//         merg(tr[x].l, tr[y].l);
//         merg(tr[x].r, tr[y].r);
//     }
// }

// int ans = 1;
// bool ok = false;
// void dfs(int u, int f){
//     cerr << u << endl;
//     int mlis = 0, mlds = 0, len = 1;
//     // cerr << "_____\n";
//     if(u == 13) ok = true;
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         int vlism = getlism(rt[v], 1, n, p[u]);
//         int vldsm = getldsm(rt[v], 1, n, p[u]);

//         len = max(len, vlism + mlds + 1);
//         len = max(len, vldsm + mlis + 1);

//         mlis = max(vlism, mlis);
//         mlds = max(vldsm, mlds);

//         merg(rt[u], rt[v]);
//     }
//     // cerr << "_____\n";
//     ans = max(ans, len);
//     if(ok){
//         cerr << u << " : ";
//         cerr << mlis << ' ' << mlds << endl;
//     }
//     if(u == 13) ok = false;
//     clismn(rt[u], 1, n, mlis + 1, p[u]);
//     cldsmx(rt[u], 1, n, mlds + 1, p[u]);
// }

// void solve(){
//     cin >> n;
//     tr[0].lismn = 1e17;
//     vector<int>rk;
//     for(int i = 1;i <= n;i++){
//         cin >> p[i];
//         rk.push_back(p[i]);
//     }
//     sort(rk.begin(), rk.end());
//     rk.erase(unique(rk.begin(), rk.end()), rk.end());
//     for(int i = 1;i <= n;i++){
//         p[i] = lower_bound(all(rk), p[i]) - rk.begin() + 1;
//         clismn(rt[i], 1, n, 1, p[i]);
//         cldsmx(rt[i], 1, n, 1, p[i]);
//         // cerr << p[i] << endl;
//     }
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);

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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 12000 + 10;
// const int LIS = 0;
// const int LDS = 1;
// int n, p[N], m;
// list<int>g[N];
// int ans = 1;

// struct node{
//     int l, r;
//     int lis, lds;
// }tr[N * 40];
// int rt[N], tot;

// void up(int id){
//     tr[id].lis = max(tr[ls].lis, tr[rs].lis);
//     tr[id].lds = max(tr[ls].lds, tr[rs].lds);
// }
// void insert(int& id, int l, int r, int x, int im, int dm){
//     if(!id) id = ++tot;
//     if(l == r){
//         tr[id].lis = max(tr[id].lis, im);
//         tr[id].lds = max(tr[id].lds, dm);
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) insert(ls, l, mid, x, im, dm);
//     else insert(rs, mid + 1, r, x, im, dm);
//     up(id);
// }
// int query(int id, int l, int r, int ql, int qr, int f){
//     if(!id || ql > qr) return 0;
//     if(ql <= l && r <= qr) return f == LIS ? tr[id].lis : tr[id].lds;
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr, f);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr, f);
//     else return max(query(ls, l, mid, ql, qr, f), query(rs, mid + 1, r, ql, qr, f));
// }
// void merg(int& x, int y){
//     if(!x || !y) x |= y;
//     else{
//         tr[x].lis = max(tr[x].lis, tr[y].lis);
//         tr[x].lds = max(tr[x].lds, tr[y].lds);
//         ans = max({ans, tr[tr[x].l].lis + tr[tr[y].r].lds, tr[tr[x].r].lds + tr[tr[y].l].lis});
//         merg(tr[x].l, tr[y].l);
//         merg(tr[x].r, tr[y].r);
//     }
// }

// bool ok = false;
// void dfs(int u, int f){
//     int mlis = 0, mlds = 0, len = 1;
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);

//         int vlis = query(rt[v], 1, m, 1, p[u] - 1, LIS);
//         int vlds = query(rt[v], 1, m, p[u] + 1, m, LDS);

//         len = max(len, vlis + mlds + 1);
//         len = max(len, vlds + mlis + 1);

//         mlis = max(mlis, vlis);
//         mlds = max(mlds, vlds);

//         merg(rt[u], rt[v]);
//     }
//     ans = max(ans, len);
//     insert(rt[u], 1, m, p[u], mlis + 1, mlds + 1);
// }

// void solve(){
//     cin >> n;
//     vector<int>rk;
//     for(int i = 1;i <= n;i++){
//         cin >> p[i];
//         rk.push_back(p[i]);
//     }
//     sort(rk.begin(), rk.end());
//     rk.erase(unique(rk.begin(), rk.end()), rk.end());
//     m = rk.size();
//     for(int i = 1;i <= n;i++){
//         p[i] = lower_bound(all(rk), p[i]) - rk.begin() + 1;
//         insert(rt[i], 1, m, p[i], 1, 1);
//     }
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);

//     cout << ans << endl;
// }   

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }