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



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 1e5 + 10;
// const int INC = 0;
// const int DEC = 1;
// int n, m, a[N];
// int rt[N], tot;

// struct seg{
//     int rt, op, tag;
//     bool all;
// }idtr[N << 2];
// void idup(int id){
//     if(idtr[id << 1].rt == idtr[id << 1 | 1].rt){
//         idtr[id].all = 1;
//         idtr[id].rt = idtr[id << 1].rt;
//         idtr[id].op = idtr[id << 1].op;
//     }else{
//         idtr[id] = {0};
//     }
// }
// void build(int id, int l, int r){
//     if(l == r){
//         idtr[id].rt = rt[l];
//         idtr[id].all = true;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(id << 1, l, mid);
//     build(id << 1 | 1, mid + 1, r);
// }

// struct node{
//     int l, r;
//     int sum;
// }tr[N * 40];
// void insert(int& id, int l, int r, int x){
//     if(!id) id = ++tot;
//     tr[id].sum++;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     if(x < mid) insert(ls, l, mid, x);
//     else insert(rs, mid + 1, r, x);    
// }
// void merg(int& x, int y){
//     if(!x || !y) x |= y;
//     else{
//         tr[x].sum += tr[y].sum;
//         merg(tr[x].l, tr[y].l);
//         merg(tr[x].r, tr[y].r);
//     }
// }
// void Split(int id, int l, int r, int ql, int qr, int& sp){
//     if(ql <= l && r <= qr && idtr[id].all){
//         merg(sp, idtr[id].rt);
//         return;
//     }
//     if(idtr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) Split(id << 1, l, mid, ql, qr, sp);
//     else if(ql > mid) Split(id << 1 | 1, mid + 1, r, ql, qr, sp);
//     else Split(id << 1, l, mid, ql, qr, sp), Split(id << 1 | 1, mid + 1, r, ql, qr, sp);
// }
// void Sort(int op, int l, int r){
//     int sp = ++tot;
//     Split(1, 1, n, l, r, sp);
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         insert(rt[i], 1, n, a[i]);
//     }
//     build(1, 1, n);
//     int op, l, r;
//     while(m--){
//         cin >> op >> l >> r;
//         Sort(op, l, r);
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
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m, a[N];


// void solve(){
//     map<int, int>mp;
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         mp[a[i]]++;
//     }
//     if(mp.size() == 1) cout << "Yes\n";
//     else if(mp.size() == 2){
//         if(abs(mp.begin()->second - mp.rbegin()->second) <= 1) cout << "Yes\n";
//         else cout << "No\n";
//     }else{
//         cout << "No\n";
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m;


// void solve(){
//     cin >> n >> m;
//     string a, b;
//     cin >> a >> b;
//     bool f = true;
//     for(int i = 0;i < n - 1;i++){
//         if(a[i] == a[i + 1]){
//             f = false;
//             break;
//         }
//     }
//     if(f){
//         cout << "Yes\n";
//         return;
//     }

//     f = true;
//     for(int i = 0;i < m - 1;i++){
//         if(b[i] == b[i + 1]){
//             f = false;
//             break;
//         }
//     }
//     if(f == false || b.front() != b.back()){
//         cout << "No\n";
//         return;
//     }

//     for(int i = 0;i < n - 1;i++){
//         if(a[i] == a[i + 1]){
//             if(a[i] == b.front()){
//                 cout << "No\n";
//                 return;
//             }
//         }
//     }
//     cout << "Yes\n";
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m, st[400], top;


// void solve(){
//     top = 0;
//     cin >> n;
//     string s;
//     cin >> s;
//     if(n & 1){
//         cout << "-1\n";
//         return;
//     }

//     int cnt = 0;
//     int q = 0, p = n;
//     while(s.size()){
//         if(s[0] == s.back()){
//             if(s[0] == '1'){
//                 st[++top] = q;
//                 s = "01" + s;
//             }else{
//                 st[++top] = p;
//                 s = s + "01";
//             }
//             p += 2;
//             cnt++;
//         }
//         q++, p--;
//         s.erase(s.begin());
//         s.pop_back();
//         if(cnt > 300){
//             cout << "-1\n";
//             return;
//         }
//     }

//     cout << top << endl;
//     for(int i = 1;i <= top;i++)cout << st[i] << ' ';
//     cout << endl;

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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m, c;

// struct node{
//     int v, nd, d;
//     int operator<(const node& e){
//         return d < e.d;
//     }
// }a[N];

// void solve(){
//     cin >> n >> c;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i].v;
//         a[i].nd = i * c;
//         a[i].d = max(0ll, a[i].nd - a[i].v);
//     }
//     sort(a + 2, a + 1 + n);
//     int cur = a[1].v;
//     for(int i = 2;i <= n;i++){
//         cur += a[i].v;
//         if(cur < a[i].nd){
//             cout << "No\n";
//             return;
//         }
//     }
//     cout << "Yes\n";
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// int a, b, x, y, d, cnt;


// void solve(){
//     cin >> a >> b >> x >> y >> d >> cnt;
//     if(b <= x){
//         cout << "Y\n";
//         return;
//     }
//     if(a <= y){
//         cout << "N\n";
//         return;
//     }
//     // int win = (b + x - 1) / x;
//     // int die = (a + y - 1) / y;
//     // if(die == 2){

//     if(d > y){
//         int ma = a;
//         while(a > 0){

//             int t = a / y;
//             for(int i = t;i >= 0;i--){
//                 t = 0;
//                 if(a - i * y >= y){
//                     t = i;
//                     break;
//                 }
//             }
//             a -= t * y;
//             b -= t * x;


//             if(a <= y && cnt > 0){
//                 a = min(ma, a + d);
//                 cnt--;
//             }else{
//                 b -= x;
//                 if(b <= 0) {
//                     cout << "Y\n";
//                     return;
//                 }
//             }
//             a -= y;
//         }

//         if(a <= 0){
//             cout << "N\n";
//             return;
//         }
//     }else{
//         int win = (b + x - 1) / x;
//         int die = (a + y - 1) / y;
//         if(die >= win) cout << "Y\n";
//         else cout << "N\n";
//     }

//     // int win = (b + x - 1) / x;
//     // int die = (a + y - 1) / y;
//     // if(die >= win) cout << "Y\n";
//     // else cout << "N\n";

//     // }else{
//     //     int tmp = a - (a % y);
//     //     d = min(tmp, d);
//     //     a += cnt * d;
//     //     die = (a + y - 1) / y;
//     //     if(die >= win) cout << "Y\n";
//     //     else cout << "N\n";
//     // }
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// int a, n;


// void solve(){
//     cin >> a >> n;
//     cout << n % (a + 1) << endl;
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
// const int N = 1e6 + 10;
// int y, r;
// int day[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


// void solve(){
//     cin >> y >> r;
//     int ans = 0;
//     if(y < 10 || (y == 10 && r < 23)){ //next year
//         ans = day[10] - 23 + day[11] + day[12];
//         int cy = 1;
//         while(cy < y){
//             ans += day[cy];
//             cy++;
//         }
//         ans += r;
//     }else{ //this year
//         ans = -23;
//         int cy = 10;
//         while(cy < y){
//             ans += day[cy];
//             cy++;
//         }
//         ans += r;
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 1e6 + 10;
// int n;


// void solve(){
//     cin >> n;
//     if(n == 100){
//         cout << "Genshin Qidong!\n";
//     }else if(n < 40){
//         cout << "wyswd\n";
//     }else{
//         int ans = (int)ceil((60.0 - (0.6 * n))/0.4);
//         for(int i = ans - 2;i <= ans + 2;i++){
//             if(i * 0.4 + 0.6 * n >= 60){
//                 ans = i;
//                 break;
//             }
//         }
//         cout << ans << endl;
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
// #define ls id << 1
// #define rs id << 1 | 1
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m, d[N], a[N];

// struct node{
//     int v, tag, len;
// }tr[N << 2];
// void up(int id){
//     tr[id].v = tr[ls].v + tr[rs].v;
//     tr[id].len = tr[ls].len + tr[rs].len;
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].v = d[l];
//         tr[id].len = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// void settag(int id, int x){
//     tr[id].v += x * tr[id].len;
//     tr[id].tag += x;
// }
// void down(int id){
//     settag(ls, tr[id].tag);
//     settag(rs, tr[id].tag);
//     tr[id].tag = 0;
// }
// void modify(int id, int l, int r, int ql, int qr, int x){
//     if(ql <= l && r <= qr){
//         settag(id, x);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls, l, mid, ql, qr, x);
//     else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x);
//     else modify(ls, l, mid, ql, qr, x), modify(rs, mid + 1, r, ql, qr, x);
//     up(id);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].v;
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
// }


// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++){
//         d[i] = a[i] - a[i-1];
//     }

//     build(1, 1, n);

//     int op, l, r, K, D, p;
//     while(m--){
//         cin >> op;
//         if(op == 1){
//             cin >> l >> r >> K >> D;
//             modify(1, 1, n, l, l, K);
//             if(l + 1 <= r) modify(1, 1, n, l + 1, r, D);
//             if(r + 1 <= n) modify(1, 1, n, r + 1, r + 1, -(K + D * (r - l)));
//         }else{
//             cin >> p;
//             cout << query(1, 1, n, 1, p) << endl;
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
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, a[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 3;i < 4 && i < n;i++)
//         if(a[i] > a[i + 1]){
//             cout << "NO\n";
//             return;
//         }
//     for(int i = 5;i < 8&& i < n;i++)
//         if(a[i] > a[i + 1]){
//             cout << "NO\n";
//             return;
//         }
//     for(int i = 9;i < 16&& i < n;i++)
//         if(a[i] > a[i + 1]){
//             cout << "NO\n";
//             return;
//         }
//     for(int i = 17;i < 20&& i < n;i++)
//         if(a[i] > a[i + 1]){
//             cout << "NO\n";
//             return;
//         }
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, a[N], q, x[N], pw[33];


// void solve(){
//     cin >> n >> q;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     vector<int>vec;
//     int vis[40] = {0};
//     for(int i = 1;i <= q;i++){
//         cin >> x[i];
//         if(!vis[x[i]]) {
//             vec.push_back(x[i]);
//             vis[x[i]] = 1;
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(auto e : vec){
//             if(a[i] % pw[e] == 0) a[i] += pw[e-1];
//         }
//         cout << a[i] <<" ";
//     }
//     cout << endl;
// }   

// signed main(){

//     IO;
//     pw[0] = 1;
//     for(int i = 1;i <= 30;i++) pw[i] = pw[i-1] * 2;
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
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, a[N];
// int sum = 0;

// bool check(int x){
//     int s = sum - x;
//     int v = s;
//     for(int i = n;i >= 1 && s > 0;i--){
//         if(s < a[i]){
//             v++;
//             s = 0;
//             break;
//         }else{
//             v++;
//             s -= a[i] - 1;
//         }
//     }
//     return v <= sum - v;
// }

// void solve(){
//     cin >> n;
//     sum = 0;
//     for(int i = 1;i <= n;i++) cin >> a[i], sum += a[i];
//     sort(a + 1, a + 1 + n);
//     int l = sum / 2, r = sum;
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
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int unsigned long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// int l, r, pw[70];
// bool f = false;

// inline int lg(int a, int x){
//     int p = a;
//     for(int i = 2;1;i++){
//         p *= a;
//         if(p > x || p <= 0) return i - 1;
//     }
// }
// inline int qp(int a, int x){
//     int ret = 1;
//     while(x--){
//         if(ret > 1e18 || ret <= 0) return 1e18 + 10;
//         ret *= a;
//     }
//     return ret;
// }

// void solve(){
//     cin >> l >> r;
//     int ans = 0;
//     int p = 61;
//     for(int i = 1;i <= 61;i++){
//         if(pw[i + 1] > l){
//             p = i;
//             break;
//         }
//     }
//     while(l <= r){
//         int R;
//         if(pw[p + 1] <= r + 1) 
//             R = pw[p + 1] - 1;
//         else
//             R = r, f = 1;
//             int p2 = lg(p, l);
//             int tmp = qp(p, p2 + 1);
//             while(tmp <= R + 1 && tmp > 0){
//                 ans = (ans + (p2 * ((tmp - l) % mod) % mod)) % mod;
//                 l = tmp;
//                 p2++;
//                 tmp *= p;
//             }
//             ans = (ans + (p2 * ((R - l + 1) % mod) % mod)) % mod;
//             l = R + 1;
//             p++;
//     }
//     cout << ans << endl;
// }   

// signed main(){

//     IO;
//     pw[0] = 1;
//     for(int i = 1;i <= 62;i++){
//         pw[i] = pw[i-1] * 2;
//     }
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// using ll = long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define all(x) (x).begin(), (x).end()
// const int N = 5e5 + 10;
// const int mod = 1e9 + 7;
// int q, idx = 1;
// ll ans[N];

// struct Que{
//     int x, tp;
// };
// ll tot;
// struct node{
//     ll l, r;
//     ll sum, tag;
// }tr[N * 15];
// list<int>g[N];
// list<Que>qur[N];
// ll rt[N];

// ll getseg(){
//     tr[++tot] = {0};
//     return tot;
// }
// void insert(ll& id, int l, int r, ll x){
//     if(!id) id = getseg();
//     if(l == r) return;
//     int mid = l + r >> 1;
//     if(x <= mid) insert(ls, l, mid, x);
//     else insert(rs, mid + 1, r, x);
// }
// void settag(ll id, ll x){
//     tr[id].tag += x;
//     tr[id].sum += x;
// }
// void down(ll id){
//     settag(ls, tr[id].tag);
//     settag(rs, tr[id].tag);
//     tr[id].tag = 0;
// }
// void modify(ll id, int l, int r, int ql, int qr, ll x){
//     if(!id) return;
//     if(ql <= l && r <= qr && (l == r || (ls && rs))){
//         settag(id, x);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls, l, mid, ql, qr, x);
//     else if(ql > mid) modify(rs, mid + 1, r, ql, qr, x);
//     else modify(ls, l, mid, ql, qr, x), modify(rs, mid + 1, r, ql, qr, x);
// }
// void merg(ll& x, ll y){
//     if(!x || !y) x |= y;
//     else{
//         if(tr[x].tag) down(x);
//         if(tr[y].tag) down(y);
//         tr[x].sum += tr[y].sum;
//         merg(tr[x].l, tr[y].l);
//         merg(tr[x].r, tr[y].r);
//     }
// }
// void dfs(int u, int f){
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         merg(rt[u], rt[v]);
//     }
//     insert(rt[u], 1, idx, u);
//     for(auto [x, tp] : qur[u]) {
//         modify(rt[u], 1, idx, 1, tp, x);
//     }
// }
// void dfs2(ll id, int l, int r){
//     if(l == r){
//         ans[l] = tr[id].sum;
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     dfs2(ls, l, mid);
//     dfs2(rs, mid + 1, r);
// }

// void init(){
//     for(int i = 0;i <= idx;i++) {
//         g[i].clear();
//         qur[i].clear();
//         rt[i] = 0;
//     }
//     idx = 1;
//     tot = 0;
// }

// void solve(){
//     cin >> q;
//     int op, v, x;
//     for(int i = 1;i <= q;i++){
//         cin >> op;
//         if(op == 1){
//             cin >> v;
//             g[v].push_back(++idx);
//             // g[idx].push_back(v);
//         }else{
//             cin >> v >> x;
//             qur[v].push_back({x, idx});
//         }
//     }

//     dfs(1, 0);

//     dfs2(rt[1], 1, idx);
//     for(int i = 1;i <= idx;i++) cout << ans[i] << ' ';
//     cout << endl;

//     init();
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
// using ll = long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define lson id << 1
// #define rson id << 1 | 1 
// #define all(x) (x).begin(), (x).end()
// const int N = 5e5 + 10;
// const int mod = 1e9 + 7;
// int q, idx = 1;
// list<int>g[N];

// struct qur{
//     int op, x, v;
// };
// list<qur>qs;

// int tot, dfn[N], l[N], r[N];
// void dfs(int u, int f){
//     l[u] = dfn[u] = ++tot;
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//     }
//     r[u] = tot;
// }

// int sum[N << 2], ad[N << 2], rc[N << 2];
// void build(int id, int l, int r){
//     sum[id] = ad[id] = rc[id] = 0;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
// }
// void recover(int id){
//     sum[id] = ad[id] = 0;
//     rc[id] = 1;
// }
// void rdown(int id){
//     recover(lson);
//     recover(rson);
//     rc[id] = 0;
// }
// void settag(int id, int v){
//     ad[id] += v;
//     sum[id] += v;
// }
// void down(int id){
//     settag(lson, ad[id]);
//     settag(rson, ad[id]);
//     ad[id] = 0;
// }
// void clean(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         recover(id);
//         return;
//     }
//     if(rc[id]) rdown(id);
//     if(ad[id]) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) clean(lson, l, mid, ql, qr);
//     else if(ql > mid) clean(rson, mid + 1, r, ql, qr);
//     else clean(lson, l, mid, ql, qr), clean(rson, mid + 1, r, ql, qr);
// }
// void add(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr){
//         settag(id, v);
//         return;
//     }
//     if(ad[id]) down(id);
//     if(rc[id]) rdown(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) add(lson, l, mid, ql, qr, v);
//     else if(ql > mid) add(rson, mid + 1, r, ql, qr, v);
//     else add(lson, l, mid, ql, qr, v), add(rson, mid + 1, r, ql, qr, v);
// }
// int query(int id, int l, int r, int x){
//     if(l == r) return sum[id];
//     if(ad[id]) down(id);
//     if(rc[id]) rdown(id);
//     int mid = l + r >> 1;
//     if(x <= mid) return query(lson, l, mid, x);
//     else return query(rson, mid + 1, r, x);
// }

// void init(){
//     for(int i = 1;i <= idx;i++){
//         g[i].clear();
//     }
//     idx = 1;
//     tot = 0;
//     qs.clear();
// }

// void solve(){
//     cin >> q;
//     int op, x, v;
//     for(int i = 1;i <= q;i++){
//         cin >> op;
//         if(op == 1){
//             cin >> x;
//             g[x].push_back(++idx);
//             qs.push_back({op, idx});
//         }else{
//             cin >> x >> v;
//             qs.push_back({op, x, v});
//         }
//     }

//     dfs(1, 0);
//     build(1, 1, idx);

//     for(auto [op, x, v] : qs){
//         if(op == 1){
//             clean(1, 1, idx, l[x], r[x]);
//         }else{
//             add(1, 1, idx, l[x], r[x], v);
//         }
//     }

//     for(int i = 1;i <= idx;i++){
//         cout << query(1, 1, idx, i) << ' ';
//     }
//     cout << endl;

//     init();
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
// using ll = long long;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// #define lson id << 1
// #define rson id << 1 | 1 
// #define all(x) (x).begin(), (x).end()
// const int N = 5e5 + 10;
// const int mod = 1e9 + 7;
// int q, n, idx = 1, id[N], ans[N];
// list<int>g[N];

// struct Q{
//     int v, id;
// };
// list<Q>qur[N];

// int tr[N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x, int v){
//     while(x <= q){
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

// void dfs(int u){
//     for(auto [v, i] : qur[u]){
//         add(i, v);
//     }
//     ans[u] = getsum(q) - getsum(id[u]);
//     for(auto v : g[u]){
//         dfs(v);
//     }
//     for(auto [v, i] : qur[u]){
//         add(i, -v);
//     }
// }

// void init(){
//     for(int i = 1;i <= idx;i++){
//         g[i].clear();
//         qur[i].clear();
//     }
//     idx = 1;
// }

// void solve(){
//     cin >> q;
//     int op, x, v;
//     for(int i = 1;i <= q;i++){
//         cin >> op;
//         if(op == 1){
//             cin >> x;
//             g[x].push_back(++idx);
//             id[idx] = i;
//         }else{
//             cin >> x >> v;
//             qur[x].push_back({v, i});
//         }
//     }

//     dfs(1);

//     for(int i = 1;i <= idx;i++) cout << ans[i] << ' ';
//     cout << endl;

//     init();
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, m, a[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }

//     for(int i = 0;i <= (1 << 8);i++){
//         int tmp = 0;
//         for(int j = 1;j <= n;j++){
//             tmp ^= (a[j] ^ i);
//         }
//         if(tmp == 0){
//             cout << i << endl;
//             return;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, m, a[N];

// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     int pos[30] = {0};
//     for(int i = 0;i < n;i++) pos[s[i] - 'a'] = i;
//     for(int i = 0;i + 'a' <= s[0];i++) if(pos[i]){
//         string s1 = s.substr(0, pos[i]) + s.substr(pos[i] + 1);
//         s1 = (char)('a' + i) + s1;
//         s = s1;
//         break;
//     }
//     cout << s << endl;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// int n, m, k[N];

// void solve(){
//     cin >> n >> m;
//     vector<int>idx;
//     for(int i = 1;i <= n;i++) cin >> k[i], idx.push_back(k[i]);
//     sort(idx.begin(), idx.end());
//     idx.erase(unique(idx.begin(), idx.end()), idx.end());
//     for(int i = 1, a, b, c;i <= m;i++){
//         cin >> a >> b >> c;
//         a = 4 * a * c;
//         auto p = lower_bound(idx.begin(), idx.end(), b);
//         // cerr << *p << endl;
//         if(p != idx.end() && (b-*p) * (b-*p) < a){
//             cout << "YES\n" << (*p) << endl;
//             continue;
//         }
//         if(p != idx.begin()){
//             p--;
//             if((b-*p) * (b-*p) < a){
//                 cout << "YES\n" << (*p) << endl;
//                 continue;
//             }
//         }

//         cout << "NO\n";
//     }

//     cout << endl;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// int n, m;
// list<int>g[N];

// int dep[N], md;
// void dfs(int u, int f){
//     dep[u] = dep[f] + 1;
//     if(dep[u] > dep[md]) md = u;
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//     }
// }
// int dis[N], d = 0;
// void dfs2(int u, int f){
//     dep[u] = dep[f] + 1;
//     if(dep[u] > dep[md]) md = u;
//     d = max(d, dep[u]);

//     dis[u] = dep[u] - 1;
//     for(auto v : g[u]) if(v != f){
//         dfs2(v, u);
//     }
// }
// int pre[N];
// void dfs3(int u, int f){
//     dep[u] = dep[f] + 1;
//     dis[u] = max(dis[u], dep[u] - 1);
//     pre[dis[u]]++;
//     for(auto v : g[u]) if(v != f){
//         dfs3(v, u);
//     }
// }

// void solve(){
//     cin >> n;
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);
//     dfs2(md, 0);
//     dfs3(md, 0);

//     for(int i = 1;i <= d;i++){
//         pre[i] += pre[i-1];
//     }

//     for(int i = 1;i <= n;i++){
//         if(i >= d) cout << n << ' ';
//         else{
//             cout << 1 + pre[i-1] << ' ';
//         }
//     }

//     // cerr << d;
//     // for(int i = 1;i <= n;i++) cerr << dis[i] << ' ';
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
// using pii = pair<int,int>;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e5 + 10;
// const int HOR = 0;
// const int VER = 1;
// int n, q;

// struct node{
//     int x, y;
//     int s, xt, yt, tagx, tagy, len;
// }tr[N << 2];
// void up(int id){
//     tr[id].len = tr[ls].len + tr[rs].len;
//     tr[id].x = tr[ls].x + tr[rs].x;
//     tr[id].y = tr[ls].y + tr[rs].y;
//     if(tr[ls].s == tr[rs].s){
//         if(tr[ls].s == VER && tr[rs].x == 0) tr[id].s = VER;
//         else if(tr[ls].s == HOR && tr[rs].y == 0) tr[id].s = HOR;
//     }else if(tr[ls].len == 1 || tr[rs].len == 1){
//         if(tr[rs].x == 0) tr[id].s = VER;
//         else if(tr[rs].y == 0) tr[id].s = HOR;
//     }
// }
// void settagx(int id, int x){
//     tr[id].x += x * tr[id].len;
//     tr[id].tagx += x;
//     tr[id].xt = 1;
// }
// void settagy(int id, int x){
//     tr[id].y += tr[id].len * x;
//     tr[id].tagy += x;
//     tr[id].yt = 1;
// }
// void down(int id){
//     if(tr[id].xt){
//         settagx(ls, tr[id].tagx);
//         settagx(rs, tr[id].tagx);
//         tr[id].xt = tr[id].tagx = 0;
//     }
//     if(tr[id].yt){
//         settagy(ls, tr[id].tagy);
//         settagy(rs, tr[id].tagy);
//         tr[id].yt = tr[id].tagy = 0;
//     }
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].x = 1;
//         tr[id].len = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// int state(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].s;
//     down(id);
//     int mid = l + r >> 1;
//     if(ql <= mid) return state(ls, l, mid, ql, qr);
//     else return state(rs, mid + 1, r, ql, qr);
//     up(id);
// }
// void modifyx(int id, int l, int r, int ql, int qr, int x){
//     if(ql <= l && r <= qr){
//         settagx(id, x);
//         return;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modifyx(ls, l, mid, ql, qr, x);
//     else if(ql > mid) modifyx(rs, mid + 1, r, ql, qr, x);
//     else modifyx(ls, l, mid, ql, qr, x), modifyx(rs, mid + 1, r, ql, qr, x);
//     up(id);
// }
// pair<int, int> query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return {tr[id].x, tr[id].y};
//     pair<int,int>ret = {0, 0};
//     pair<int,int>tmp = {0, 0};
//     down(id);
//     int mid = l + r >> 1;
//     if(ql <= mid){
//         tmp = query(ls, l, mid, ql, qr);
//         ret.first += tmp.first;
//         ret.second += tmp.second;
//     }
//     else{
//         tmp = query(rs, mid + 1, r, ql, qr);
//         ret.first += tmp.first;
//         ret.second += tmp.second;
//     }
//     up(id);
//     return ret;
// }
// void modifyy(int id, int l, int r, int ql, int qr, int x){
//     if(ql <= l && r <= qr){
//         settagy(id, x);
//         return;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modifyy(ls, l, mid, ql, qr, x);
//     else if(ql > mid) modifyy(rs, mid + 1, r, ql, qr, x);
//     else modifyy(ls, l, mid, ql, qr, x), modifyy(rs, mid + 1, r, ql, qr, x);
//     up(id);
// }
// void recoverx(int l, int r, int a0, int d){
//     pii tmp = {0, 0};
//     if(l > 1) tmp = query(1, 1, n, 1, l - 1);
//     modifyx(1, 1, n, l, l, a0 - tmp.first);
//     if(l + 1 <= r) modifyx(1, 1, n, l + 1, r, d);
//     if(l + 1 <= n) modifyx(1, 1, n, l + 1, l + 1, -((a0-tmp.first)+d*(r-l)));
// }
// void recovery(int l, int r, int a0, int d){
//     pii tmp = {0, 0};
//     if(l > 1) tmp = query(1, 1, n, 1, l - 1);
//     modifyy(1, 1, n, l, l, a0 - tmp.second);
//     if(l + 1 <= r) modifyy(1, 1, n, l + 1, r, d);
//     if(l + 1 <= n) modifyy(1, 1, n, l + 1, l + 1, -((a0-tmp.second)+d*(r-l)));
// }

// void solve(){
//     cin >> n >> q;
//     build(1, 1, n);
//     int op, l, r, x, y;
//     while(q--){
//         cin >> op;
//         if(op == 1){
//             cin >> l >> r;
//             pair<int,int>tmp = query(1, 1, n, 1, l);
//             if(state(1, 1, n, l, r) == HOR){
//                 recoverx(l, r, tmp.first, 1);
//                 recovery(l, r, tmp.second, 0);
//             }else{
//                 recoverx(l, r, tmp.first, 0);
//                 recovery(l, r, tmp.second, 1);
//             }
//         }else{
//             cin >> l;
//             auto pii = query(1, 1, n, 1, l);
//             cout << pii.first << ' ' << pii.second << endl;
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
// const int N = 1e4 + 10;
// const int M = 110;
// const int INF = 10000005;
// int n, m;
// int k[M], ans[M];
// int del[N], root, judge[INF];
// list<array<int, 2>>g[N];
// int siz[N], mxs, sum, d[N];
// int que[N], dis[N], cnt; //模拟队列和栈

// void getroot(int u, int f){
//     siz[u] = 1;
//     int mx = 0;
//     for(auto [v, w] : g[u]) if(!del[v] && v != f){
//         getroot(v, u);
//         siz[u] += siz[v];
//         mx = max(mx, siz[v]);
//     }
//     mx = max(mx, sum - siz[u]);
//     if(mx < mxs){
//         mxs = mx;
//         root = u;
//     }
// }
// void getdis(int u, int f){
//     dis[++cnt] = d[u];
//     for(auto [v, w] : g[u]) if(v != f && !del[v]){
//         d[v] = d[u] + w;
//         getdis(v, u);
//     }
// }
// void calc(int u){
//     del[u] = judge[0] = 1;
//     int p = 0;

//     for(auto [v, w] : g[u]) if(!del[v]){
//         cnt = 0;
//         d[v] = w;
//         getdis(v, u);
//         for(int i = 1;i <= cnt;i++)
//             for(int j = 1;j <= m;j++)
//                 if(k[j] >= dis[i])
//                     ans[j] |= judge[k[j] - dis[i]];
//         for(int i = 1;i <= cnt;i++)
//             if(dis[i] < INF) que[++p] = dis[i], judge[que[p]] = 1;
//     }

//     for(int i = 1;i <= p;i++) judge[que[i]] = 0;
// }
// void divide(int u){
//     calc(u);

//     for(auto [v, w] : g[u]) if(!del[v]){
//         mxs = sum = siz[v];
//         getroot(v, 0);
//         divide(root);
//     }
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1, u, v, w;i < n;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({{v, w}});
//         g[v].push_back({{u, w}});
//     }

//     for(int i = 1;i <= m;i++){
//         cin >> k[i];
//     }

//     mxs = sum = n;
//     getroot(1, 0);
//     getroot(root, 0);
//     divide(root);

//     for(int i = 1;i <= m;i++){
//         cout << (ans[i] ? "AYE\n" : "NAY\n");
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
// const int N = 1e6 + 10;
// int n, L, R;
// list<int>g[N];
// int del[N];
// int sz[N], dep[N];
// int ans = 0;

// void calc(int u){
//     // cerr << u << endl;
//     vector<int>q(n + 10);
//     vector<int>pre(n + 10);
//     q[0] = 1;
//     int p1 = 0, mdp = 0;
//     dep[u] = 0;
//     auto getdis = [&](auto self, int u, int f) -> void {
//         dep[u] = dep[f] + 1;
//         pre[dep[u]]++;
//         mdp = max(mdp, dep[u]);
//         for(auto v : g[u]) if(v != f && !del[v]){
//             self(self, v, u);
//         }
//     };
//     for(auto v : g[u]) if(!del[v]){
//         mdp = 0;
//         getdis(getdis, v, u);
//         for(int i = 1;i <= R;i++) pre[i] += pre[i - 1];
//         for(int i = 0;i <= p1;i++){
//             ans += q[i] * (pre[max(0ll, R-i)] - pre[max(0ll, L-i-1)]);
//         }
//         for(int i = 1, len;i <= mdp;i++) {
//             len = pre[i]-pre[i-1];
//             if(len > n || len < 0) continue;
//             q[len]++;
//             p1 = max(p1, len);
//         }
//         for(int i = 1;i <= R;i++) pre[i] = 0;
//     }
// }

// void dfs(int u, int s){
//     int ms = s + 1, root = -1;
//     auto getroot = [&](auto self, int u, int f) -> void {
//         sz[u] = 1;
//         int mx = 0;
//         for(auto v : g[u]) if(!del[v] && v != f){
//             self(self, v, u);
//             sz[u] += sz[v];
//             mx = max(mx, sz[v]);
//         }   
//         mx = max(mx, s - sz[u]);
//         if(mx < ms) ms = mx, root = u;
//     };
//     getroot(getroot, u, 0);

//     calc(root);
//     del[root] = 1;
//     for(auto v : g[root]) if(!del[v]){
//         dfs(v, sz[v]);
//     }
// }    

// void init(){
//     ans = 0;
//     for(int i = 1;i <= n;i++) {
//         sz[i] = del[i] = 0;
//         g[i].clear();
//     }
// }   

// void solve(){
//     int l, r;
//     cin >> n >> l >> r;
//     L = n - 1 - r;
//     R = n - 1 - l;
//     // cerr << L << ' ' << R << endl;
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, n);

//     cout << ans << endl;

//     init();
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
// const int N = 1e5 + 10;
// int n, m, a[N];


// void solve(){
//     int x, y, k;
//     cin >> x >> y >> k;
//     if(y <= x){
//         cout << x << endl;
//     }else{
//         x = min(y, x + k);
//         cout << y + (y - x) << endl;
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
// const int N = 200 + 10;
// int n, m, a[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= 2 * n;i++){
//         cin >> a[i];
//     }
//     sort(a + 1, a + 1 + 2 * n);
//     int sum = 0;
//     for(int i = 2;i <= n;i++){
//         sum += a[i] - a[i-1];
//     }
//     for(int i = 2 + n;i <= 2 * n;i++){
//         sum += a[i] - a[i-1];
//     }
//     cout << sum << endl;
//     for(int i = 1;i <= n;i++){
//         cout << a[i] << ' ' << a[i + n] << endl;
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
// int n, sum[N];
// string s[N];
// map<int, map<int, int>>mp; //长度，和

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> s[i];
//         // cout << s[i] << ' ' << sum[i] << endl;
//     }
//     sort(s + 1, s + 1 + n, [](string& s1, string& s2)->int {return s1.size() > s2.size();});
//     for(int i = 1;i <= n;i++){
//         for(auto c : s[i]) sum[i] += c - '0';
//         mp[s[i].size()][sum[i]]++;
//         // cerr << s[i] << endl;
//     }
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         int tmp = sum[i];
//         // cerr << sum[i] << endl;
//         for(int j = s[i].size();j > s[i].size() / 2 && tmp > 0;j--){
//             int len = j - (s[i].size()-j);
//             // cerr << len << ' ' << tmp << endl;
//             // cerr << tmp << endl;
//             ans += mp[len][tmp];
//             tmp -= (s[i][j-1] - '0') * 2;
//         }
//         // cerr << ans << ' ';
//         mp[s[i].size()][sum[i]]--;
//         tmp = sum[i];
//         for(int j = s[i].size();j > s[i].size() / 2 && tmp > 0;j--){
//             ans += mp[j - (s[i].size()-j)][tmp];
//             tmp -= (s[i][s[i].size()-j] - '0') * 2;
//         }
//         // cerr << ans << '\n';
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
// const int N = 2e5 + 10;
// int n, a[N], an[N][33], bn[N][33];

// void solve(){
//     cin >> n;
//     for(int i = 1;i < n;i++) {
//         cin >> a[i];
//         for(int j = 30;j >= 0;j--){
//             an[i][j] = (a[i] >> j) & 1;
//         }
//     }
//     for(int j = 30;j >= 0;j--){
//         int on = 0;
//         for(int i = 1;i < n;i++){
//             bn[i+1][j] = bn[i][j] ^ an[i][j];
//             on += bn[i+1][j];
//         }
//         if(on > n - on){
//             for(int i = 1;i <= n;i++) bn[i][j] ^= 1;
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         int ans = 0;
//         for(int j = 30;j >= 0;j--){
//             ans += bn[i][j] * (1ll << j);
//         }
//         cout << ans << ' ';
//     }
//     cout << endl;
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
// const int N = 1e5 + 10;
// int n, L, R;
// list<int>g[N];
// int del[N];
// int sz[N], dep[N];
// int ans = 0;
// int k;

// void calc(int u){
//     vector<int>q1, q2;
//     q1.push_back(0);
//     auto val = [&](vector<int>& d) -> int {
//         sort(d.begin(), d.end());
//         int m = d.size();
//         int r = m - 1;
//         int ret = 0;
//         for(int i = 0;i < m;i++){
//             while(r >= 0 && d[r] + d[i] > k) r--;
//             if(i < r) ret += r - i;
//         }
//         return ret;
//     };
//     dep[u] = 0;
//     auto dfs2 = [&](auto self, int u, int f) -> void {
//         dep[u] = dep[f] + 1;
//         q1.push_back(dep[u]);
//         q2.push_back(dep[u]);
//         for(auto v : g[u]) if(v != f && !del[v]){
//             self(self, v, u);
//         }
//     };
//     for(auto v : g[u]) if(!del[v]) {
//         q2.clear();
//         dfs2(dfs2, v, u);
//         ans -= val(q2);
//     }
//     ans += val(q1);
// }

// void dfs(int u, int s){
//     int ms = s + 1, root = -1;
//     auto getroot = [&](auto self, int u, int f) -> void {
//         sz[u] = 1;
//         int mx = 0;
//         for(auto v : g[u]) if(!del[v] && v != f){
//             self(self, v, u);
//             sz[u] += sz[v];
//             mx = max(mx, sz[v]);
//         }   
//         mx = max(mx, s - sz[u]);
//         if(mx < ms) ms = mx, root = u;
//     };
//     getroot(getroot, u, 0);

//     calc(root);
//     del[root] = 1;
//     for(auto v : g[root]) if(!del[v]){
//         dfs(v, sz[v]);
//     }
// }    

// void init(){
//     ans = 0;
//     for(int i = 1;i <= n;i++) {
//         sz[i] = del[i] = 0;
//         g[i].clear();
//     }
// }   

// void solve(){
//     int l, r;
//     cin >> n >> l >> r;
//     L = n - 1 - r;
//     R = n - 1 - l;
//     // cerr << L << ' ' << R << endl;
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }


//     k = R;
//     dfs(1, n);
//     int tmp = ans;
//     ans = 0;
//     for(int i = 1;i <= n;i++) {
//         sz[i] = del[i] = 0;
//     }
//     k = L - 1;
//     dfs(1, n);
//     cout << tmp - ans << endl;

//     init();
// }

// signed main(){

//     IO;
// // freopen("awesome.in", "r", stdin);
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
// #define all(x) (x).begin(), (x).end()
// const int N = 1e5 + 10;
// const int WIN = 0;
// const int DRAW = 1;
// const int LOSE = 2;
// int n, m; 

// void solve(){
//     cin >> n;
//     vector<int>ax(n), ay(n);
//     for(auto& e : ax) cin >> e;
//     for(auto& e : ay) cin >> e;
//     cin >> m;
//     vector<int>bx(m), by(m);
//     for(auto& e : bx) cin >> e;
//     for(auto& e : by) cin >> e;

//     vector<int>pa(n), pb(m);
//     iota(all(pa), 0);
//     iota(all(pb), 0);
//     sort(all(pa), 
//         [&](int i, int j) {
//             return ax[i] < ax[j];
//     });
//     sort(all(pb), 
//         [&](int i, int j) {
//             return bx[i] < bx[j];
//     });

//     for(int i = n - 2;i >= 0;i--){
//         pa[i] = ay[pa[i]] > ay[pa[i+1]] ? pa[i] : pa[i+1];
//     }
//     for(int i = m - 2;i >= 0;i--){
//         pb[i] = by[pb[i]] > by[pb[i+1]] ? pb[i] : pb[i+1];
//     }

//     vector<int>g(n+m);
//     for(int i = 0;i < n + m;i++) g[i] = -1;

//     for(int i = 0;i < n;i++){
//         int l = 0, r = m - 1;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(bx[pb[mid]] > ax[i]) r = mid - 1;
//             else l = mid + 1;
//         }
//         if(bx[pb[l]] > ax[i]) g[i] = pb[l] + n;
//     }
//     for(int i = 0;i < m;i++){
//         int l = 0, r = n - 1;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(ax[pa[mid]] > bx[i]) r = mid - 1;
//             else l = mid + 1;
//         }
//         if(ax[pa[l]] > bx[i]) g[i+n] = pa[l];
//     }

//     vector<int>s(n+m);
//     vector<int>ans(n+m);
//     auto dfs = [&](auto self, int u) ->int {
//         if(~s[u]) return ans[u] = DRAW;
//         if(!s[u]) s[u] = -1;
//         if(s[u] == 1) return ans[u];
//         if(u < n){
//             if(~g[u]){
//                 ans[u] = self(self, g[u]);
//             }
//             s[u] = 1;
//             return ans[u];
//         }else{
//             int ret;
//             if(~g[u]){
//                 ret = self(self, g[u]);
//             }else{
//                 ret =  LOSE;
//             }
//             s[u] = 1;
//             return ret;
//         }
//     };

//     for(int i = 0;i < n;i++) if(!s[i]){
//         dfs(dfs, i);
//         s[i] = 1;
//     }
//     int c[3];
//     for(int i = 0;i < n;i++) c[ans[i]]++;
//     cout << c[0] << ' ' << c[1] << ' ' << c[2] << endl;
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
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m; 

// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     for(int x = 1;x <= n;x++) {
//         int a = 0, b = 0, ac = 0, bc = 0;
//         for(int i = 0;i < n;i++){
//             if(s[i] == s.back()) a++;
//             else b++;
//             if(a == x){
//                 ac++;
//                 a = b = 0;
//             }else if(b == x){
//                 bc++;
//                 a = b = 0;
//             }
//         }
//         if(ac > bc){
//             cout << s.back() << endl;
//             return;
//         }
//     }
//     cout << "?\n";
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
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m; 

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     vector<int>b(n, 1);
//     vector<vector<int>>pos(110);
//     for(auto& e : a) cin >> e;
//     for(int i = 0;i < n;i++) 
//         pos[a[i]].push_back(i);

//     int cnt = 0;
//     for(int i = 1;i <= 100;i++) if(pos[i].size() >= 2) cnt++;
//     if(cnt >= 2){
//         for(int i = 1;i <= 100;i++){
//             if(pos[i].size() >= 2){
//                 b[pos[i].front()] = 2;
//             }
//         }
//         for(int i = 1;i <= 100;i++){
//             if(pos[i].size() >= 2){
//                 b[pos[i].front()] = 3;
//                 break;
//             }
//         }
//         for(auto e : b) cout << e << ' ';
//         cout << endl;
//     }else{
//         cout << "-1\n";
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
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, k; 

// void solve(){
//     cin >> n >> k;
//     vector<int>a(n);
//     vector<int>vis(n);
//     for(int i = 0;i < n;i++) cin >> a[i];
//     int cnt = 0;
//     int p = n - 1;
//     while(1){
//         if(a[p] > n) break;
//         if(vis[p]){
//             cout << "Yes\n";
//             return;
//         }
//         vis[p] = 1;
//         p -= a[p];
//         if(p < 0) p += n;
//         cnt++;
//     }
//     cout << (cnt >= k ? "Yes\n" : "No\n");
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
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m; 

// void solve(){
//     cin >> n >> m;
//     vector<int>a(n), b(m);
//     int mn = 1e10;
//     for(auto& e : a) cin >> e, mn = min(mn, e);
//     for(auto& e : b) cin >> e;
//     sort(all(b));
//     int len = m;
//     bool f = true;
//     for(int i = 0;i < n;i++){
//         int p = lower_bound(b.begin(), b.begin() + len, a[i]) - b.begin();
//         for(int j = len - 1;j >= p;j--) cout << b[j] << ' ';
//         len = p;
//         cout << a[i] << ' ';
//     }
//     for(int i = len - 1;i >= 0;i--) cout << b[i] << ' ';
//     cout << endl;
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
// #define all(x) (x).begin(), (x).end()
// const int N = 1e5 + 10;
// const int WIN = 0;
// const int DRAW = 1;
// const int LOSE = 2;
// int n, m; 

// void solve(){
//     cin >> n;
//     vector<int>ax(n), ay(n);
//     for(auto& e : ax) cin >> e;
//     for(auto& e : ay) cin >> e;
//     cin >> m;
//     vector<int>bx(m), by(m);
//     for(auto& e : bx) cin >> e;
//     for(auto& e : by) cin >> e;

//     vector<int>pa(n), pb(m);
//     iota(all(pa), 0);
//     iota(all(pb), 0);
//     sort(all(pa), 
//         [&](int i, int j) {
//             return ax[i] < ax[j];
//     });
//     sort(all(pb), 
//         [&](int i, int j) {
//             return bx[i] < bx[j];
//     });

//     for(int i = n - 2;i >= 0;i--){
//         pa[i] = ay[pa[i]] > ay[pa[i+1]] ? pa[i] : pa[i+1];
//     }
//     for(int i = m - 2;i >= 0;i--){
//         pb[i] = by[pb[i]] > by[pb[i+1]] ? pb[i] : pb[i+1];
//     }

//     vector<int>g(n+m);
//     for(int i = 0;i < n + m;i++) g[i] = -1;

//     for(int i = 0;i < n;i++){
//         int l = 0, r = m - 1;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(bx[pb[mid]] > ay[i]) r = mid - 1;
//             else l = mid + 1;
//         }
//         if(l < m && bx[pb[l]] > ay[i]) g[i] = pb[l] + n;
//     }
//     for(int i = 0;i < m;i++){
//         int l = 0, r = n - 1;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(ax[pa[mid]] > by[i]) r = mid - 1;
//             else l = mid + 1;
//         }
//         if(l < n && ax[pa[l]] > by[i]) g[i+n] = pa[l];
//     }


//     vector<int>s(n+m);
//     vector<int>ans(n+m);
//     auto dfs = [&](auto self, int u) ->int {
//         if(s[u] == -1) return ans[u] = DRAW;
//         if(!s[u]) s[u] = -1;
//         if(s[u] == 1) return ans[u];
//         if(u < n){
//             if(~g[u]){
//                 ans[u] = self(self, g[u]);
//             }else{
//                 ans[u] = WIN;
//             }
//             s[u] = 1;
//             return ans[u];
//         }else{
//             if(~g[u]){
//                 ans[u] = self(self, g[u]);
//             }else{
//                 ans[u] = LOSE;
//             }
//             s[u] = 1;
//             return ans[u];
//         }
//     };

//     for(int i = 0;i < n;i++) if(!s[i]){
//         dfs(dfs, i);
//         s[i] = 1;
//     }
//     int c[3] = {0};
//     for(int i = 0;i < n;i++) c[ans[i]]++;
//     cout << c[0] << ' ' << c[1] << ' ' << c[2] << endl;
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
// #define all(x) (x).begin(), (x).end()
// const int N = 1e5 + 10;
// const int WIN = 0;
// const int DRAW = 1;
// const int LOSE = 2;
// int m; 

// void solve(){
//     cin >> m;
//     vector<int>n(m);
//     vector<int>r(m);
//     vector<int>l(m);
//     vector<int>sum(m);
//     vector<vector<int>>a(m);
//     vector<vector<int>>c(m);
//     map<int,int>cnt;
//     map<int,vector<int>>stid;
//     int L = 0, R = 0;
//     for(int i = 0;i < m;i++){
//         cin >> n[i] >> l[i] >> r[i];
//         L += l[i];
//         R += r[i];
//         a[i].resize(n[i]);
//         c[i].resize(n[i]);
//         for(auto& e : a[i]) cin >> e, stid[e].push_back(i);
//         for(int j = 0;j < n[i];j++){
//             cin >> c[i][j];
//             sum[i] += c[i][j];
//             cnt[a[i][j]] += c[i][j];
//         }
//     }

//     if(R - L + 1 > cnt.size()) {
//         cout << "0\n";
//         return;
//     }

//     int ans = 1e18;
//     for(int len = L;len <= R;len++){
//         if(!cnt[len]){
//             cout << "0\n";
//             return;
//         }
//         int tmp = cnt[len];
//         int D = R - len;
//         for(auto id : stid[len]){
//             int p = lower_bound(all(a[id]), len) - a[id].begin();
//             int d = sum[id] - r[id] + (r[id] - max(l[id], r[id] - D));
//             int dd = min(d, c[id][p]);
//             tmp -= dd;
//             dd -= sum[id] - r[id];
//             D -= dd;
//         }
//         ans = min(ans, tmp);
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
// #define all(x) (x).begin(), (x).end()
// int n;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     vector<int>b(n);
//     vector<int>d(n);
//     for(int i = 0;i < n;i++) cin >> a[i] >> b[i], d[i] = (b[i] >= a[i] ? 1 : -1);
//     vector<int>st = a;
//     sort(all(st));
//     int ans = st[n >> 1];
//     int l = 0, r = 0, mx = 0, cur = 0, ml = -1, mr = -1;
//     for(int i = 0;i < n;i++){
//         cur += d[i];
//         r = i;
//         if(cur < 0){
//             cur = 0;
//             l = r = i + 1;
//         }else if(cur > mx){
//             mx = cur;
//             ml = l;
//             mr = r;
//         }
//     }
//     // cerr << l << ' ' << r << endl;
//     for(int i = l;i <= r;i++) swap(a[i], b[i]);
//     sort(all(a));
//     ans = max(ans, a[n >> 1]);
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
// #define all(x) (x).begin(), (x).end()
// int n;

// void solve(){
//     string s;
//     cin >> s;
//     int cur = 0;
//     for(auto c : s){
//         cur += (c == '(' ? 1 : -1);
//         cur = max(cur, 0ll);
//     }
//     if(cur > 0){
//         cout << "impossible\n";
//         return;
//     }
//     cout << s << endl;
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
// #define all(x) (x).begin(), (x).end()
// int n;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     vector<int>b(n);
//     for(auto& e : a) cin >> e;
//     for(auto& e : b) cin >> e;
//     for(int i = 0;i < n;i++){
//         if(a[i] > a[n-1]) swap(a[i], b[i]);
//     }
//     int ma = a[n-1], mb = b[n-1];
//     for(int i = 0;i < n;i++){
//         ma = max(ma, a[i]);
//         mb = max(mb, b[i]);
//     }
//     if(ma == a[n-1] && mb == b[n-1]){
//         cout << "Yes\n";
//         return;
//     }
//     swap(a[n-1], b[n-1]);
//     for(int i = 0;i < n;i++){
//         if(a[i] > a[n-1]) swap(a[i], b[i]);
//     }
//     ma = a[n-1], mb = b[n-1];
//     for(int i = 0;i < n;i++){
//         ma = max(ma, a[i]);
//         mb = max(mb, b[i]);
//     }
//     if(ma == a[n-1] && mb == b[n-1]){
//         cout << "Yes\n";
//     }else{
//         cout << "No\n";
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
// #define all(x) (x).begin(), (x).end()
// int n, m;

// void solve(){
//     cin >> m;
//     vector<vector<int>>vec(m);
//     map<int, int>mp;
//     for(int i = 0;i < m;i++){
//         cin >> n;
//         vec[i].resize(n);
//         for(auto& e : vec[i]) cin >> e, mp[e]++;
//     } 
//     vector<int>ans;
//     for(int i = 0;i < m;i++){
//         bool f = false;
//         for(auto e : vec[i]){
//             mp[e]--;
//             if(mp[e] == 0) f = true;
//         }
//         if(!f){
//             cout << "-1\n";
//             return;
//         }
//         for(auto e : vec[i]){
//             if(mp[e] == 0) {
//                 ans.push_back(e);
//                 break;
//             }
//         }
//     }

//     for(auto e : ans) cout << e << ' ';
//     cout << endl;
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
// #define all(x) (x).begin(), (x).end()
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     vector<int>b(n);
//     vector<int>c(n);
//     for(int i = 0;i < n;i++) cin >> a[i] >> b[i], c[i] = a[i] * b[i];
//     int ans = 1;
//     int gc = c[0], mb = b[0];
//     for(int i = 0;i < n;i++){
//         gc = __gcd(gc, c[i]);
//         mb = mb * b[i] / __gcd(mb, b[i]);
//         if(gc % mb){
//             ans++;
//             gc = c[i];
//             mb = b[i];
//             // cerr << i << endl;
//         }
//     }
//     // for(int i = 0;i < n;i++){
//     //     cerr << c[i] << ' ' << b[i] << endl;
//     // }


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
// #define all(x) (x).begin(), (x).end()
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     vector<int>z;
//     vector<int>f;
//     int mx = -1e10, mn = 1e10;
//     for(auto& e : a){
//         cin >> e, mx = max(mx, e), mn = min(mn, e);
//         e >= 0 ? z.push_back(e) : f.push_back(-e);
//     }
//     int d = mx - mn;
//     if(z.size()) sort(all(z), greater<int>());
//     if(f.size()) sort(all(f), greater<int>());
//     int zp = 0, fp = 0;
//     if(z.back() == d) {
//         cout << "No\n";
//         return;
//     }

//     vector<int>ans;
//     mx = mn = 0;
//     while(zp < z.size() || fp < f.size()){
//         int cnt = 0;
//         int tmp = 0;
//         while(zp < z.size() && tmp + z[zp] < d && mx + z[zp] < d){
//             ans.push_back(z[zp]);
//             mx += z[zp];
//             mn = max(0ll, mn - z[zp]);
//             tmp += z[zp++];
//             cnt++;
//         }
//         tmp = 0;
//         while(fp < f.size() && tmp + f[fp] < d && mn + f[fp] < d){
//             ans.push_back(-f[fp]);
//             mn += f[fp];
//             mx = max(0ll, mx - f[fp]);
//             tmp += f[fp++];
//             cnt++;
//         }
//         if(!cnt){
//             cout << "No\n";
//             return;
//         }
//     }

//     cout << "Yes\n";
//     for(auto e : ans) cout << e << ' ';
//     cout << "\n";
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
// #define all(x) (x).begin(), (x).end()
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     vector<int>ans(n);
//     vector<int>f(n + 1);
//     vector<int>c(n + 1, 1);
//     for(auto& e : a) cin >> e;
//     int mx = 0;
//     for(int i = n - 1;i >= 0;i--){
//         if(a[i] == f[i+1]) ans[i] = 0;
//         else{
//             if(f[i+1] || a[i] <= c[i+1]) ans[i] = 1;
//             else ans[i] = 2;
//         }
//         int ne = a[i] + i + 1;
//         if(ne == n){
//             f[i] = 1;
//         }
//         else if(ne < n && f[ne]){
//             f[i] = f[ne] + 1; 
//         }
//         if(ne <= n) c[i] = max(mx + 1, c[ne] + 1);
//         else c[i] = mx + 1;
//         mx = max(mx, f[i]);
//     }

//     for(int i = 0;i < n - 1;i++) cout << ans[i] << ' ';
//     cout << endl;
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
// #define all(x) (x).begin(), (x).end()
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     int num[2] = {0};
//     bool f = false;
//     for(auto& e : a){
//         cin >> e;
//         if(e > 1) f = true;
//         if(e) num[1]++;
//         else num[0]++;
//     }

//     // cerr << num[0] << ' ' << num[1] << endl;
//     if(num[1] + 1 >= num[0]){
//         cout << "0\n";
//     }else{
//         if(f || num[1] == 0) cout << "1\n";
//         else cout << "2\n";
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
// #define all(x) (x).begin(), (x).end()
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(2*n);
//     vector<int>b(2*n);
//     for(auto& e : a) cin >> e;
//     sort(all(a));
//     int ans = 0;
//     if(n == 1){
//         ans = abs(a[0] - a[1]);
//     }else if(n == 2){
//         int ans1 = 0, ans2 = abs(a[3] - 2), ans3 = 0;
//         for(auto e : a) ans3 += abs(e);
//         for(auto e : a) ans1 += abs(e - 2);
//         for(int i = 0;i < 2*n-1;i++) ans2 += abs(a[i] + 1);
//         ans = min({ans1, ans2, ans3});
//     }else if(n & 1){
//         for(auto e : a) ans += abs(e);
//     }else{
//         int ans1 = 0, ans2 = abs(a.back() - n);
//         for(auto e : a) ans1 += abs(e);
//         for(int i = 0;i < 2*n - 1;i++) ans2 += abs(a[i] + 1);
//         ans = min(ans1, ans2);
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


// #include<stdio.h>

// int main(){

//     int n;
//     scanf("%d", &n);

//     printf("0\n");
//     for(int i = 0;i <= 25;i++){
//         if((1 << i) & n){
//             printf("%d", (1 << i));
//             if((1 << (i + 1)) <= n) printf(" ");
//         }
//     }


//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
// const int sq = 500;
// signed n, q, a[N];
// int val[N];
// vector<signed>g[N];
// unordered_map<signed, int>mp[N];

// int dep[N], par[N][20];
// void dfs1(int u, int f){
//     dep[u] = dep[f] + 1;
//     val[u] += val[f];
// 	par[u][0] = f;
// 	for (int i = 1; i < 20; ++i) {
// 		par[u][i] = par[ par[u][i - 1] ][i - 1];
// 	}
//     for(auto v : g[u]){
//         dfs1(v, u);
//     }
// }
// int lca(int u, int v) {
// 	if (dep[u] < dep[v]) swap(u, v);
// 	for (int i = 19; i >= 0; --i) {
// 		if (dep[ par[u][i] ] >= dep[v]) u = par[u][i];
// 	}
// 	if (u == v) return u;
// 	for (int i = 19; i >= 0; --i) {
// 		if (par[u][i] != par[v][i]) {
// 			u = par[u][i], v = par[v][i];
// 		}
// 	}
// 	return par[u][0];
// }
// inline long long jump(int x,int y, int fa){
// 	if (x==fa) return val[fa]; if (x>y) swap(x,y);
// 	if (dep[x]-dep[fa]<=sq) return jump(par[x][0],par[y][0],fa)+1ll*a[x]*a[y];
// 	if (mp[x].count(y)) return mp[x][y];
// 	return mp[x][y]=jump(par[x][0],par[y][0],fa)+1ll*a[x]*a[y];
// }

// void solve(){
//     scanf("%d%d", &n, &q);
//     for(int i = 1;i <= n;i++){
//         scanf("%d", &a[i]);
//         val[i] = a[i] * a[i];
//     }
//     for(signed i = 2, p;i <= n;i++){
//         scanf("%d", &p);
//         g[p].push_back(i);
//     }

//     dfs1(1, 0);

//     signed x, y;
//     while(q--){
//         scanf("%d%d", &x, &y);
//         int ca = lca(x, y);
//         printf("%lld\n", jump(x, y, ca));
//     }
// }

// signed main(){

//     // IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
// const int sq = 505;
// int n, q, a[N], dep[N], p[N], mp[N][sq], tot[N], id[N];

// int jump(int x, int y){
//     if(!x) return 0;
//     if(id[y] <= sq && mp[x][id[y]]) return mp[x][id[y]];
//     int ret = jump(p[x], p[y]) + a[x] * a[y];
//     if(id[y] <= sq) mp[x][id[y]] = ret;
//     return ret;
// }

// void solve(){
//     cin >> n >> q;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     for(int i = 2;i <= n;i++){
//         cin >> p[i];
//         dep[i] = dep[p[i]] + 1;
//         id[i] = ++tot[dep[i]];
//     }
//     int x, y;
//     while(q--){
//         cin >> x >> y;
//         cout << jump(x, y) << '\n';
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;


// void solve(){
//     int n, t, z = 0, f = 0;
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> t;
//         if(t > 0) z++;
//         else f++;
//     }
//     for(int i = 1;i <= z;i++) cout << i << ' ';
//     for(int i = 1;i <= f;i++) cout << z - i << ' ';
//     cout << '\n';
//     for(int i = 1;i <= f;i++) cout << "1 0 ";
//     for(int i = 1, p = 1;i <= z - f;i++, p++) cout << p << ' ';
//     cout << endl;

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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// int n;

// void solve(){
//     cin >> n;   
//     int cur = 0, ans = 0, sum = 0;
//     for(int i = 1, t;i <= n;i++){
//         cin >> t;
//         if(t == 1){
//             sum++;
//             cur++;
//         }else{
//             if(sum)
//             cur = 1 + (sum / 2);
//         }
//         // cerr << cur <<  ' ';
//         ans = max(ans, cur);
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 200 + 10;
// int n, m, mp[N][N], mm;

// void solve(){
//     cin >> n >> m;
//     mm = m + 8 - (m % 8);
//     // cerr << mm << endl;
//     int cur = 16;
//     for(int i = 1;i <= n;i++){
//         if(i % 4 == 1){
//             int j = 1;
//             while(j <= mm){
//                 mp[i][j++] = cur++;
//                 mp[i][j++] = cur;
//                 cur += 3;
//                 mp[i][j++] = cur++;
//                 mp[i][j++] = cur;
//                 cur += 3;
//             }
//         }else if(i % 4 == 2){
//             for(int j = 1;j <= mm;j++){
//                 mp[i][j] = mp[i-1][j] + 2;
//             }
//         }else{
//             for(int j = 1;j <= mm;j++){
//                 mp[i][j] = mp[i-2][j];
//             }
//             int j = 1;
//             while(j <= mm){
//                 int q = j, p = j + 3;
//                 swap(mp[i][q++], mp[i][p--]);
//                 swap(mp[i][q++], mp[i][p--]);
//                 j += 4;
//             }
//         }
//     }

//     set<int>st;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             if(i & 1){
//                 if(j & 1) mp[i][j] += (1ll << 62);
//                 else mp[i][j] += (1ll << 61);
//             }else{
//                 if(j & 1) mp[i][j] += (1ll << 61);
//                 else mp[i][j] += (1ll << 62);
//             }
//             st.insert(mp[i][j]);
//             // int tmp;
//             // if(i & 1){
//             //     if(j & 1) tmp = 1;
//             //     else tmp = 2;
//             // }else{
//             //     if(j & 1) tmp = 4;
//             //     else tmp = 8;
//             // }
//             // mp[i][j] = tmp;
//             // cerr << tmp << ' ';
//         }
//     }

//     cout << n*m << endl;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             cout << mp[i][j] <<" ";
//         }
//         cout << endl;
//     }
//     // for(int i = 1;i + 3 <= n;i++){
//     //     for(int j = 1;j + 3 <= m;j++){
//     //         int x1 = 0, x2= 0, x3 = 0, x4 = 0;
//     //         int ii = i, jj = j;
//     //         x1 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];
//     //         ii += 2, jj += 2;
//     //         x2 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];
//     //         ii -= 2;
//     //         x3 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];
//     //         ii += 2, jj -= 2;
//     //         x4 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];

//     //         cerr << x1 << " " << x2 << ' ' << x3 << " " << x4 << endl;
//     //     }
//     // }
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 200 + 10;
// int n, m, mp[N][N], mm;

// void solve(){
//     cin >> n >> m;
//     mm = m + 8 - (m % 8);
//     // cerr << mm << endl;
//     int cur = 16;
//     for(int i = 1;i <= n;i++){
//         if(i % 4 == 1){
//             int j = 1;
//             while(j <= mm){
//                 mp[i][j++] = cur++;
//                 mp[i][j++] = cur;
//                 cur += 3;
//                 mp[i][j++] = cur++;
//                 mp[i][j++] = cur;
//                 cur += 3;
//             }
//         }else if(i % 4 == 2){
//             for(int j = 1;j <= mm;j++){
//                 mp[i][j] = mp[i-1][j] + 2;
//             }
//         }else{
//             for(int j = 1;j <= mm;j++){
//                 mp[i][j] = mp[i-2][j];
//             }
//             int j = 1;
//             while(j <= mm){
//                 int q = j, p = j + 3;
//                 swap(mp[i][q++], mp[i][p--]);
//                 swap(mp[i][q++], mp[i][p--]);
//                 j += 4;
//             }
//         }
//     }

//     set<int>st;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             if(i & 1){
//                 if(j & 1) mp[i][j] += (1ll << 62);
//                 else mp[i][j] += (1ll << 61);
//             }else{
//                 if(j & 1) mp[i][j] += (1ll << 61);
//                 else mp[i][j] += (1ll << 62);
//             }
//             st.insert(mp[i][j]);
//             // int tmp;
//             // if(i & 1){
//             //     if(j & 1) tmp = 1;
//             //     else tmp = 2;
//             // }else{
//             //     if(j & 1) tmp = 4;
//             //     else tmp = 8;
//             // }
//             // mp[i][j] = tmp;
//             // cerr << tmp << ' ';
//         }
//     }

//     cout << n*m << endl;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             cout << mp[i][j] <<" ";
//         }
//         cout << endl;
//     }
//     // for(int i = 1;i + 3 <= n;i++){
//     //     for(int j = 1;j + 3 <= m;j++){
//     //         int x1 = 0, x2= 0, x3 = 0, x4 = 0;
//     //         int ii = i, jj = j;
//     //         x1 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];
//     //         ii += 2, jj += 2;
//     //         x2 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];
//     //         ii -= 2;
//     //         x3 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];
//     //         ii += 2, jj -= 2;
//     //         x4 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];

//     //         cerr << x1 << " " << x2 << ' ' << x3 << " " << x4 << endl;
//     //     }
//     // }
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 200 + 10;
// int n, m, mp[N][N], mm;

// void solve(){
//     cin >> n >> m;
//     cout << n * m << endl;
//     vector<int>x(n + 1), y(m + 1);
//     int cnt = 0;
//     for(int i = 0;cnt < n && i < 30;i++)
//         for(int j = i + 1;cnt < n && j < 30;j++){
//                 x[++cnt] = (1ll << i) + (1ll << j);
//             }
//     cnt = 0;
//     for(int i = 30;cnt < m && i <= 62;i++)
//         for(int j = i + 1;cnt < m && j <= 62;j++){
//                 y[++cnt] = (1ll << i) + (1ll << j);
//             }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             mp[i][j] = x[i] + y[j];
//             cout << mp[i][j] << ' ';
//         }
//         cout << endl;
//     }

//     // for(int i = 1;i + 3 <= n;i++){
//     //     for(int j = 1;j + 3 <= m;j++){
//     //         int x1 = 0, x2= 0, x3 = 0, x4 = 0;
//     //         int ii = i, jj = j;
//     //         x1 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];
//     //         ii += 2, jj += 2;
//     //         x2 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];
//     //         ii -= 2;
//     //         x3 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];
//     //         ii += 2, jj -= 2;
//     //         x4 = mp[ii][jj] ^ mp[ii][jj+1] ^ mp[ii+1][jj] ^ mp[ii+1][jj+1];

//     //         cerr << x1 << " " << x2 << ' ' << x3 << " " << x4 << endl;
//     //     }
//     // }

// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }


// #include<stdio.h>

// int main(){

//     int n;
//     scanf("%d", &n);
//     for(int i = 1;i <= n;i++) printf("***");
//     for(int i = 1;i <= n;i++) printf(" ");
//     for(int i = 1;i <= n;i++) printf("***");
//     printf("\n");
//     int a = 2, b = 3 * n + 1, c = 4 * n, d = 7 * n - 1;
//     for(int i = 2;i < 2 * n - 1;i++){
//         for(int j = 1;j <= 7 * n;j++){
//             if(j == a || j == d || (c - b > 2 && (j == b || j == c))) printf("*");
//             else printf(" ");
//         }
//         if(i < n) a++, b++, c--, d--;
//         else a--, b--, c++, d++;
//         printf("\n");
//     }
//     for(int i = 1;i <= n;i++) printf("***");
//     for(int i = 1;i <= n;i++) printf(" ");
//     for(int i = 1;i <= n;i++) printf("***");

//     return 0;
// }