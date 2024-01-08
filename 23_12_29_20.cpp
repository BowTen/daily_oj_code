// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     cin >> n;
//     cout << n-1 << endl;
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
// int n, m, k;

// void solve(){
//     cin >> n >> k;
//     vector<int>a(n+5);
//     vector<int>p(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i], p[a[i]] = i;
//     for(int i = 2;i <= n;i++){
//         if(p[i] < p[i-1]){
//             cout << (n-i+1+k-1)/k << endl;
//             return;
//         }
//     }
//     cout << "0\n";

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
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, m, k;

// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     vector<int>vis(n+5);
//     vector<int>p(n+5);
//     vector<int>q(n+5);
//     int f = 1;
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         // cerr << a[i] << ' ' << vis[a[i]] << endl;
//         if(!vis[a[i]]){
//             p[i] = a[i];
//             vis[a[i]] = 1;
//         }else if(vis[a[i]] == 1){
//             q[i] = a[i];
//             vis[a[i]]++;
//         }else{
//             f = 0;
//         }
//     }

//     if(!f){
//         cout << "NO\n";
//         return;
//     }

//     vector<int>pid;
//     for(int i = 1;i <= n;i++) if(p[i]) pid.push_back(i);
//     sort(all(pid), [&](int i, int j) -> int {
//         return p[i] < p[j];
//     });
//     vector<int>qid;
//     for(int i = 1;i <= n;i++) if(q[i]) qid.push_back(i);
//     sort(all(qid), [&](int i, int j) -> int {
//         return q[i] < q[j];
//     });

//     vector<int>np, nq;
//     for(int i = 1;i <= n;i++){
//         if(!vis[i]) np.push_back(i), nq.push_back(i);
//         else if(vis[i] == 1) nq.push_back(i);
//     }

//     for(int i = 0;i < nq.size();i++){
//         q[pid[i]] = nq[i];
//     }
//     for(int i = 0;i < np.size();i++){
//         p[qid[i]] = np[i];
//     }

//     for(int i = 1;i <= n;i++){
//         if(max(p[i], q[i]) != a[i]){
//             cout << "NO\n";
//             return;
//         }
//     }

//     cout << "YES\n";
//     for(int i = 1;i <= n;i++) cout << p[i] << ' ';
//     cout << endl;
//     for(int i = 1;i <= n;i++) cout << q[i] << ' ';
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
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, m, k, fa[N];

// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// void solve(){
//     cin >> n;
//     vector<int>p(n+5);
//     for(int i = 1;i <= n;i++) fa[i] = i;
//     for(int i = 1;i <= n;i++) cin >> p[i];


//     if(is_sorted(p.begin() + 1, p.begin() + 1 + n)){
//         cout << "1\n";
//         return;
//     }

//     for(int i = 1;i <= n;i++) if(p[i] != i){
//         merg(i, p[i]);
//     }

//     int cnt = 0, ans = n, f = 0;
//     for(int i = 1;i <= n;i++){
//         if(find(i) == i) cnt++;
//         if(!f && i < n && find(i) == find(i+1)) ans--, f = 1;
//     }
//     ans -= cnt;
//     if(!f) ans++;

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
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 3e6 + 10;
// int n, mod, ans, sum[4];

// int qpow(int a, int b){
//     int ret = 1;
//     while(b){
//         if(b & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return ret;
// }

// int inv[N], fac[N];
// void get_inv(){
//     inv[0] = fac[0] = 1;
//     for(int i = 1;i < N;i++){
//         fac[i] = fac[i-1] * i % mod;
//     }
//     inv[N - 1] = qpow(fac[N - 1], mod - 2);
//     for(int i = N - 2;i >= 1;i--){
//         inv[i] = inv[i+1] * (i + 1) %mod;
//     }
// }
// int add(int a, int b){
//     return (a + b) % mod;
// }
// int _div(int a, int b){
//     a -= b;
//     while(a < 0) a += mod;
//     return a;
// }
// int mul(int a, int b){
//     return a * b % mod;
// }
// int C(int a, int b){
//     return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
// }

// void solve(){
//     cin >> n >> mod;
//     get_inv();
//     sum[0] = 1;
//     sum[1] = _div(mul(2,fac[2*n]), fac[n]);
//     ans = add(ans, _div(sum[1], sum[0]));
//     sum[2] = mul(mul(mul(2, C(2*n, n)), fac[n]), fac[2*n]);
//     for(int i = 0;i <= n;i++){
//         sum[2] = _div(sum[2], mul(C(n,i), mul(C(n,i), mul(C(2*n-i, n), mul(fac[n], mul(fac[n], fac[n]))))));
//     }
//     ans = add(ans, mul(_div(sum[2], sum[1]), 2));
//     sum[3] = fac[3*n];
//     ans = add(ans, mul(3, _div(sum[3], sum[2])));

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
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 3e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, m, vis[N];
// vector<int>g[N];
// double f[N];
// int to[N];

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++){
//         f[i] = inf;    
//     }

//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     f[n] = 0;
//     priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>que;
//     que.push({0, n});
//     while(que.size()){
//         auto u = que.top();
//         que.pop();
//         if(vis[u.second]) continue;
//         vis[u.second] = 1;
//         for(auto v : g[u.second]) if(!vis[v]){
//             int son = g[v].size();
//             if(to[v] == 0){
//                 to[v] = 1;
//                 f[v] = ((u.first/son) + 1) * son;
//                 que.push({f[v], v});
//             }else{
//                 double tmp = ((f[v] * to[v]) / son + (u.first/son)) * son / (to[v] + 1);
//                 if(tmp < f[v]){
//                     f[v] = tmp;
//                     to[v]++;
//                     que.push({f[v], v});
//                 }
//             }
//         }
//     }

//     // for(int i = 1;i <= n;i++){
//     //     cerr << i << ' ' << f[i] << endl;
//     // }

//     printf("%.10lf\n", f[1]);

// }

// signed main(){

//     IO;

//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     // priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>que;
//     // que.push({5, 0});
//     // que.push({9, 0});

//     // while(que.size()){
//     //     auto p = que.top();
//     //     que.pop();
//     //     cerr << p.first << ' ' << p.second << endl;

//     // }

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 3e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     vector<int>b(n);
//     for(auto &e : a) cin >> e;
//     for(auto &e : b) cin >> e;
//     sort(all(a));
//     sort(all(b));
//     for(int i = 0; i< n;i++){
//         if(b[i] > a[i]){
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
//     while(t--) solve();


//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 5e4 + 10;
// const int C = 500 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, c, p[N], f[C], mx[C], mn[C], up[C];

// void init(){
//     for(int i = 1;i <= c;i++){
//         f[i] = -1;
//         up[i] = 0;
//     }
// }

// void solve(){
//     cin >> n >> c;
//     init();
//     for(int i = 1;i <= n;i++) cin >> p[i];
//     // unordered_map<int,int>f;
//     // unordered_map<int,int>mx;
//     // unordered_map<int,int>mn;
//     // for(int i = 1;i <= n;i++){
//     //     mx[p[i]] = mn[p[i]] = p[i];
//     //     f[p[i]] = 0;
//     // }
//     for(int i = 1;i <= n;i++){
//         for(int j = 0, tp = c - p[i];j <= c - p[i];j++) if(f[j] != -1 && up[j] != i){
//             int ne = j + p[i];
//             if(f[ne] == -1){
//                 mx[ne] = max(mx[j], p[i]);
//                 mn[ne] = min(mn[j], p[i]);
//                 f[ne] = mx[ne] - mn[ne];
//                 up[ne] = i;
//             }else{
//                 int tmx = max({mx[j], p[i], mx[ne]});
//                 int tmn = min({mn[j], p[i], mn[ne]});
//                 int tf = tmx - tmn;
//                 if(tf < f[ne]){
//                     mx[ne] = tmx;
//                     mn[ne] = tmn;
//                     f[ne] = tf;
//                     up[ne] = i;
//                 }
//             }
//         }
//     }

//     cout << f[c] << endl;
// }

// signed main(){

//     IO;

//     f[0] = 0;
//     mx[0] = -inf;;
//     mn[0] = inf;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();


//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int C = 500 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, k, a[N], m;

// int les(int x){
//     int ret = 0, p = n;
//     for(int i = 1;i <= n;i++){
//         while(p >= i && a[i] + a[p] >= x) p--;
//         if(p < i) break;
//         ret += p - i;
//     }
//     return ret;
// }
// int gt(int x){
//     int ret = 0, p = 1;
//     for(int i = n;i >= 1;i--){
//         while(p <= i && a[i] + a[p] <= x) p++;
//         if(p > i) break;
//         ret += i - p;
//     }
//     return ret;
// }
// int rk(int x){
//     int l = les(x)+1, r = m - gt(x);
//     if(l > r){
//         if(l != k) return l;
//         return r;
//     }
//     if(k >= l && k <= r) return k;
//     return l;
// }

// void solve(){
//     cin >> n;
//     m = (n*(n-1)) / 2;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     cin >> k;
//     sort(a + 1, a + 1 + n);

//     int l = a[1] + a[2], r = a[n] + a[n-1];
//     while(l <= r){
//         int mid = l + r >> 1;
//         int rank = rk(mid);
//         if(rank == k) {
//             cout << mid << endl;
//             return;
//         }
//         if(rank >= k){
//             r = mid - 1;
//         }else{
//             l = mid + 1;
//         }
//     }

//     cout << l << endl;

//     // cerr << les(7) << ' ' << m-gt(7) << rk(7) << endl;
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
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 5e4 + 10;
// const int C = 500 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, c, p[N], mn[C], ok[C];

// void init(){
//     for(int i = 1;i <= c;i++){
//         ok[i] = 0;
//     }
// }

// void solve(){
//     cin >> n >> c;
//     init();
//     for(int i = 1;i <= n;i++) cin >> p[i];
//     sort(p+1, p+1+n);

//     int ans = inf;

//     for(int i = 1;i <= n;i++){
//         for(int j = c - p[i];j >= 0;j--) if(ok[j]){
//             int ne = j + p[i];
//             if(!ok[ne]){
//                 ok[ne] = 1;
//                 mn[ne] = min(p[i], mn[j]);
//             }
//             else mn[ne] = max(mn[ne], min(p[i], mn[j]));

//             if(ne == c){
//                 if(j == 0) ans = 0;
//                 else ans = min(ans, p[i] - mn[j]);
//             }
//         }
//     }

//     if(ok[c]) cout << ans << endl;
//     else cout << "-1\n";
// }

// signed main(){

//     IO;

//     ok[0] = 1;
//     mn[0] = inf;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();


//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, c, a[N];

// struct node{
//     int len, v[33], tag, mx;
//     node() : len(0), v({0}), tag(0) {};

//     void assign(int x){
//         len = mx = x;
//         for(int i = 0;i <= 31;i++) {
//             v[i] = ((x >> i) & 1) * x;
//         }
//     }

//     void setmin(int x){
//         for(int i = 0;i <= 31;i++) {
//             v[i] /= mx;
//             v[i] *= x;
//         }
//         mx = len = x;
//     }

//     void Xor(int x){
//         for(int i = 0;i <= 31;i++) if((x >> i) & 1){
//             v[i] = len - v[i];
//         }
//     }
//     node operator+(const node& e){
//         node ret(*this);
//         ret.tag = 0;
//         ret.mx = max(ret.mx, e.mx);
//         ret.len += e.len;
//         for(int i = 0;i < 33;i++){
//             ret.v[i] += e.v[i];
//         }
//         return ret;
//     }

//     void init(){
//         tag = mx = len = 0;
//         for(int i = 0;i < 33;i++){
//             v[i] = 0;
//         }
//     }
// }tr[N<<2];

// void up(int id){
//     tr[id] = tr[ls] + tr[rs];
// }
// void settag(int id, int x){
//     tr[id].Xor(x);
//     tr[id].tag ^= x;
// }
// void down(int id){
//     settag(ls, tr[id].tag);
//     settag(rs, tr[id].tag);
//     tr[id].tag = 0;
// }
// void build(int id, int l, int r){
//     tr[id].init();
//     if(l == r){
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// void insert(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id].assign(v);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(x <= mid) insert(ls, l, mid, x, v);
//     else insert(rs, mid + 1, r, x, v);
//     up(id);
// }
// void Xor(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr){
//         settag(id, v);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) Xor(ls, l, mid, ql, qr, v);
//     else if(ql > mid) Xor(rs, mid + 1, r, ql, qr, v);
//     else Xor(ls, l, mid, ql, qr, v), Xor(rs, mid + 1, r, ql, qr, v);
//     up(id);
// }
// void setmin(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr) {
//         if(tr[id].mx <= v) return;
//         else{
//             if(l == r){
//                 tr[id].setmin(v);
//                 return;
//             }
//         }
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) setmin(ls, l, mid, ql, qr, v);
//     else if(ql > mid) setmin(rs, mid + 1, r, ql, qr, v);
//     else setmin(ls, l, mid, ql, qr, v), setmin(rs, mid + 1, r, ql, qr, v);
//     up(id);
// }
// node query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id];
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         insert(1, 1, n, i, a[i]);
//         if(i > 1){
//             Xor(1, 1, n, 1, i-1, a[i]);
//             setmin(1, 1, n, 1, i-1, a[i]);
//         }

//         node tmp = query(1, 1, n, 1, i);
//         int sum = 0;
//         for(int i = 0;i <= 31;i++) {
//             sum = (((1 << i) * tmp.v[i] % mod) + sum) % mod;
//         }

//         ans = (ans + sum) % mod;
//     }

//     cout << ans << endl;
// }

// signed main(){

//     IO;

//     freopen("D:\\Codes\\testfile\\in3.txt", "r", stdin);
//     freopen("D:\\Codes\\testfile\\out3.txt", "w", stdout);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int C = 500 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, k;


// void solve(){
//     cin >> n >> k;
//     int p = 1;
//     for(int i = 1, u;i <= n;i++){
//         cin >> u;
//         p *= u;
//     }
//     if(2023 % p){
//         cout << "NO\n";
//         return;
//     }
//     cout << "YES\n";
//     cout << 2023 / p << ' ';
//     for(int i = 1;i < k;i++) cout << "1 ";
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
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int C = 500 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, k;


// void solve(){
//     int a, b;
//     cin >> a >> b;
//     if(a == 1){
//         cout << b * b << endl;
//         return;
//     }
//     if(b % a){
//         cout << a * b / __gcd(a, b) << endl;
//     }else{
//         cout << (b / a) * b << endl;
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
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int C = 500 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, k;


// void solve(){
//     cin >> n;
//     vector<int>a(n + 5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     cout << a[1] << ' ';
//     if(n >= 2) cout << ((a[1] + a[2]) / 2) * 2 << ' ';
//     if(n > 2){
//         int sum = a[1] + a[2], cnt = (a[1] & 1) + (a[2] & 1);
//         for(int i = 3;i <= n;i++){
//             sum += a[i];
//             cnt += (a[i] & 1);
//             cout << sum - (cnt / 3 + ((cnt % 3) % 2)) << ' ';
//         }
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
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int C = 500 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, k;


// void solve(){
//     cin >> n;
//     int pw = 1;
//     for(int i = 1;i < n;i++) pw *= 10;
//     pw = sqrt(pw);
//     map<vector<int>, vector<int>>mp;
//     for(int i = pw;i <= 4 * pw;i++){
//         vector<int>cnt(10);
//         int x = i * i;
//         while(x){
//             cnt[x % 10]++;
//             x /= 10;
//         }
//         mp[cnt].push_back(i * i);
//         // if(cnt[1] == 2 && cnt[2] == 2 && cnt[4] == 2 && cnt[8] == 1)
//         // cout << i << ' ' << i * i << endl;
//     }

//     for(auto &[cnt, vec] : mp) if(vec.size() >= n){
//         if(cnt[1] == 1 && cnt[6] == 1 && cnt[9] == 1 && cnt[0] == n - 3){
//             cout << vec.size() << endl;
//             for(auto e : vec) cout << e << ' ' << sqrt(e) << endl;
//             cout << "____________\n";
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
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int C = 500 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, k;


// void solve(){
//     cin >> n;

//     if(n == 1){
//         cout << "1\n";
//         return;
//     }

//     int ze = (n-3) / 2;
//     for(int i = 1;i <= ze;i++){
//         cout << '1';
//         for(int j = 1;j <= i;j++) cout << '0';
//         cout << '6';
//         for(int j = 1;j <= i;j++) cout << '0';
//         cout << "9";
//         for(int j = 1;j <= n - i*2 - 3;j++) cout << '0';
//         cout << endl;
//     }    
//     cout << "169";
//     for(int i = 1;i <= n-3;i++) cout << '0';
//     cout << endl;

//     cout << "196";
//     for(int i = 1;i <= n-3;i++) cout << '0';
//     cout << endl;

//     ze = (n-3) / 2;
//     for(int i = 1;i <= ze;i++){
//         cout << '9';
//         for(int j = 1;j <= i;j++) cout << '0';
//         cout << '6';
//         for(int j = 1;j <= i;j++) cout << '0';
//         cout << "1";
//         for(int j = 1;j <= n - i*2 - 3;j++) cout << '0';
//         cout << endl;
//     }    
//     cout << "961";
//     for(int i = 1;i <= n-3;i++) cout << '0';
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
// #define lson id << 1
// #define rson id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, k, q, a[N];

// int val(int x){
//     return ((x - 1)*x) / 2;
// }

// //线段树
// struct node{
//     int ans, tag, len, rc, lc, rlen, llen;

//     node() : ans(0), len(0), tag(0), rc(0), lc(0), rlen(0), llen(0) {};

//     void init(){
//         ans = tag = 0;
//     }

//     node operator+(const node& e){
//         node ret;
//         ret.ans = ans + e.ans;
//         ret.len = len + e.len;
//         ret.lc = lc;
//         ret.rc = e.rc;
//         ret.llen = llen;
//         ret.rlen = e.rlen;
//         if(rc ^ e.lc){
//             ret.ans -= val(rlen) + val(e.llen);
//             ret.ans += val(rlen + e.llen);
//             if(rlen == len) ret.llen = len + e.llen;
//             if(e.llen == e.len) ret.rlen = e.len + rlen;
//         }
//         return ret;
//     }

// }tr[N << 2];

// void settag(int id){
//     tr[id].lc ^= 1;
//     tr[id].rc ^= 1;
//     tr[id].tag ^= 1;
// }
// void up(int id){
//     tr[id] = tr[lson] + tr[rson];
// }
// void down(int id){
//     settag(lson);
//     settag(rson);
//     tr[id].tag = 0;
// }
// void build(int id, int l ,int r){
//     tr[id].init();
//     if(l == r){
//         tr[id].len = tr[id].llen = tr[id].rlen = 1;
//         tr[id].lc = tr[id].rc = a[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
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
// node query(int id, int l, int r, int ql ,int qr){
//     if(ql <= l && r <= qr) return tr[id];
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return (query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr));
// }


// void solve(){
//     cin >> n >> q;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);
//     while(q--){
//         int t, l, r;
//         cin >> t >> l >> r;
//         if(t == 1){
//             modify(1, 1, n, l, r);
//         }else{
//             cout << query(1, 1, n, l, r).ans + r - l + 1 << endl;
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
// #define lson id << 1
// #define rson id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, k, q;
// string s;


// //线段树
// struct node{
//     int tag, k[2][2];

//     node() : tag(0), k({0}) {};

//     void assign(int x){
//         k[0][0] = 1;
//         k[0][1] = 0;
//         k[1][0] = 0;
//         k[1][1] = 1;
//         k[x][x^1] = 1;
//     }

//     node operator+(const node& e){
//         node ret;
//         ret.k[0][0] = ((e.k[0][0] * k[0][0] % mod) + (e.k[0][1] * k[1][0] % mod)) % mod;
//         ret.k[0][1] = ((e.k[0][0] * k[0][1] % mod) + (e.k[0][1] * k[1][1] % mod)) % mod;
//         ret.k[1][0] = ((e.k[1][0] * k[0][0] % mod) + (e.k[1][1] * k[1][0] % mod)) % mod;
//         ret.k[1][1] = ((e.k[1][0] * k[0][1] % mod) + (e.k[1][1] * k[1][1] % mod)) % mod;

//         return ret;
//     }

// }tr[N << 2];

// void ptk(const node& ret){
//         cerr << ret.k[0][0] << "A " << ret.k[0][1] << "B\n";
//         cerr << ret.k[1][0] << "A " << ret.k[1][1] << "B\n";
// }

// void settag(int id){
//     swap(tr[id].k[0][0], tr[id].k[1][0]);
//     swap(tr[id].k[0][1], tr[id].k[1][1]);
//     swap(tr[id].k[0][0], tr[id].k[0][1]);
//     swap(tr[id].k[1][0], tr[id].k[1][1]);
//     tr[id].tag ^= 1;
// }
// void up(int id){
//     tr[id] = tr[lson] + tr[rson];
// }
// void down(int id){
//     settag(lson);
//     settag(rson);
//     tr[id].tag = 0;
// }
// void build(int id, int l ,int r){
//     tr[id].tag = 0;
//     if(l == r){
//         tr[id].assign(s[l]);
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// void modify(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr){
//         // cerr << l << ' ' << r << endl;
//         // ptk(tr[id]);
//         settag(id);
//         // cerr << l << ' ' << r << endl;
//         // ptk(tr[id]);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(lson, l, mid, ql, qr);
//     else if(ql > mid) modify(rson, mid + 1, r, ql, qr);
//     else modify(lson, l, mid, ql, qr), modify(rson, mid + 1, r, ql, qr);
//     up(id);
// }
// node query(int id, int l, int r, int ql ,int qr){
//     if(ql <= l && r <= qr) return tr[id];
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return (query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr));
// }

// int add(int a, int b){
//     return (a + b) % mod;
// }
// int mul(int a, int b){
//     return a * b % mod;
// }

// void solve(){
//     cin >> n >> q >> s;
//     s = ' ' + s;
//     for(int i = 1;i <= n;i++) s[i] -= 'A';
//     build(1, 1, n);
//     while(q--){
//         int t, l, r, a, b;
//         cin >> t >> l >> r;
//         if(t == 1){
//             modify(1, 1, n, l, r);
//         }else{
//             cin >> a >> b;
//             node ret = query(1, 1, n, l, r);
//             int A = add(mul(ret.k[0][0], a), mul(ret.k[0][1], b));
//             int B = add(mul(ret.k[1][0], a), mul(ret.k[1][1], b));
//             cout << A << ' ' << B << endl;
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
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// // #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 4e5 + 10;
// const int mod = 1e9 + 7;
// // const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, k, q, a[N];

// //线段树
// int mx[N<<2], ad[N<<2];

// void up(int id){
//     mx[id] = max(mx[ls], mx[rs]);
//     ad[id] = (ad[ls] | ad[rs]);
// }
// void build(int id, int l, int r){
//     if(l == r){
//         mx[id] = ad[id] = a[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// void modify(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr){
//         if((ad[id] & v) == ad[id]) return;
//         if(l == r) {
//             mx[id] = ad[id] = (ad[id] & v);
//             return;
//         }
//     }
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls, l, mid, ql, qr, v);
//     else if(ql > mid) modify(rs, mid + 1, r, ql, qr, v);
//     else modify(ls, l, mid, ql, qr, v), modify(rs, mid + 1, r, ql, qr, v);
//     up(id);
// }
// void change(int id, int l, int r, int x, int v){
//     if(l == r) {
//         mx[id] = ad[id] = v;
//         return ;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(ls, l, mid, x, v);
//     else change(rs, mid + 1, r, x, v);
//     up(id);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return mx[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
// }

// void solve(){
//     cin >> n >> q;
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     build(1, 1, n);

//     char s[5];
//     int l, r, x, v;
//     while(q--){
//         cin >> s;
//         if(s[0] == 'A'){
//             cin >> l >> r >> v;
//             modify(1, 1, n, l, r, v);
//         }else if(s[0] == 'U'){
//             cin >> x >> v;
//             change(1, 1, n, x, v);
//         }else{
//             cin >> l >> r;
//             cout << query(1, 1, n, l, r) << '\n';
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
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int inf = LLONG_MAX;
// int n, leaf[N];
// vector<int>g[N];

// void dfs(int u, int f){
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         leaf[u] = min(leaf[u], leaf[v]);
//     }
//     sort(all(g[u]), [&](int i, int j) -> int {
//         if(i == f) return 1;
//         if(j == f) return 0; 
//         return leaf[i] < leaf[j];
//     });
// }
// void print(int u, int f){
//     for(auto v : g[u]) if(v != f){
//         print(v, u);
//     }
//     cout << u << ' ';
// }
// void dfs2(int u, int f){
//     if(g[u].size() == 1){
//         cout << u;
//         return;
//     }
//     for(auto v : g[u]) if(v != f && v != g[u].back()){
//         print(v, u);
//     }
//     if(leaf[g[u].back()] > u){
//         cout << u << ' ';
//         dfs2(g[u].back(), u);
//     }else{
//         print(g[u].back(), u);
//         cout << u;
//         return;
//     }
// }
// void init(){
//     for(int i = 1;i <= n;i++){
//         leaf[i] = n + 1;
//         g[i].clear();
//     }
// }

// void solve(){
//     cin >> n;
//     init();
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     int mn = n + 1;
//     for(int i = 1;i <= n;i++) if(g[i].size() == 1){
//         leaf[i] = i;
//         mn = min(mn, i);
//     }

//     int cur = g[mn][0];

//     if(g[cur].size() == 1){
//         print(cur, 0);
//         cout << endl;
//         return;
//     }

//     dfs(cur, 0);
//     dfs2(cur, 0);

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
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int inf = LLONG_MAX;
// int n, a[N];


// void solve(){
//     cin >> n;
//     int x = 1;
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         x *= a[i];
//     }
//     x += n - 1;
//     cout << x * 2022 << endl;
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
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = LLONG_MAX;
// int n, a[N];

// int qpow(int a, int b){
//     int ret = 1;
//     while(b){
//         if(b & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return ret;
// }
// int mul(int a, int b){
//     return a * b % mod;
// }
// int add(int a, int b){
//     return (a + b) % mod;
// }

// void solve(){
//     cin >> n;
//     int ans = mul(( mul( mul(n,n+1), mul(2,n)+1 ) ), qpow(6, mod - 2));
//     ans = add( ans, mul(( mul( mul((n-1),n), mul(2,(n-1))+1 ) ), qpow(6, mod - 2)) );
//     ans = add( ans, mul( mul(n-1, n), qpow(2, mod - 2) ) );

//     cout << ans*2022 % mod << endl;
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
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = LLONG_MAX;
// int n, a[N];


// void solve(){
//     cin >> n;
//     vector<int>cnt(n*2+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int x = 0, ans = n * (n + 1) / 2;
//     cnt[0] = 1;
//     for(int i = 1;i <= n;i++){
//         x ^= a[i];
//         for(int j = 0;j * j <= n*2;j++) if((x ^ (j * j)) <= 2*n){
//             ans -= cnt[(x ^ (j * j))];
//             // cerr << (x ^ (j * j)) << endl;
//         }
//         cnt[x]++;
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
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = LLONG_MAX;
// int n, a[N], m;


// void solve(){
//     cin >> n >> m;
//     vector<vector<int>>mp(n+5, vector<int>(m+5));
//     vector<vector<int>>pre(n+5, vector<int>(m+5));
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             cin >> mp[i][j];
//             pre[i][j] = mp[i][j];
//         }
//     }


//     auto check = [&](int x) -> int {
//         for(int i = 1;i <= n;i++)
//             for(int j = 1;j <= m;j++)
//                 pre[i][j] = (mp[i][j]>=x) + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];

//         for(int i = 1;i+x-1 <= n;i++)
//             for(int j = 1;j+x-1 <= m;j++){
//                 int sum = pre[i+x-1][j+x-1] - pre[i-1][j+x-1] - pre[i+x-1][j-1] + pre[i-1][j-1];
//                 if(sum == x*x) return true;
//             }
//         return false;
//     };

//     int l = 1, r = min(n, m);
//     while(l <= r){
//         int mid = l + r >> 1;
//         if(check(mid)) l = mid + 1;
//         else r = mid - 1;
//     }
//     cout << r << endl;
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
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e6 + 10;
// const int mod = 1e9 + 7;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, m, fac[N], cnt[N];

// vector<int> pri;
// bool not_prime[N];
// int phi[N];
// int pre[N];

// void euler(int n) {
//   phi[1] = 1;
//   for (int i = 2; i <= n; i++) {
//     if (!not_prime[i]) {
//       pri.push_back(i);
//       phi[i] = i - 1;
//     }
//     for (int pri_j : pri) {
//       if (i * pri_j > n) break;
//       not_prime[i * pri_j] = true;
//       if (i % pri_j == 0) {
//         phi[i * pri_j] = phi[i] * pri_j;
//         break;
//       }
//       phi[i * pri_j] = phi[i] * phi[pri_j];
//     }
//   }
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 2;i <= n;i++){
//         // cnt[i] = n / i - 1;
//         // int d = n / i;
//         // for(int j = 2;j * i <= n;j++){
//         //     int s = d - j;
//         //     cnt[i] += (s / j) * (j - fac[j]);
//         //     s %= j;

//         //     // int tmp = 0;
//         //     // for(int k = 2;k <= s && k * k <= j;k++){
//         //     //     if(j % k == 0){
//         //     //         tmp++;
//         //     //         int f = j / k;
//         //     //         if(f <= s && f * f != j) tmp++;
//         //     //     }
//         //     // }
//         //     // cnt[i] += s - tmp;

//         //     int tmp = 0;
//         //     for(int k = 1;k <= s;k++){
//         //         if(__gcd(j, k) == 1) tmp++;
//         //     }
//         //     cnt[i] += tmp;
//         // }
//         cnt[i] = pre[n/i];
//         cnt[i] /= i - 1;
//         // if(!cnt[i]) break;
//     }

//     // for(int i = 2;i <= n;i++){
//     //     for(int j = i + 1;j <= n;j++){
//     //         cnt[__gcd(i, j)]++;
//     //     }
//     // }
//     // for(int i = 2;i <= n;i++) cnt[i] /= i-1;

//     int ans = 0;
//     for(int i = n;i >= 2;i--) if(cnt[i]){
//         int d = min(cnt[i], m / (i-1));
//         m -= d * (i-1);
//         ans += d * i;
//     }

//     if(!m) cout << ans << endl;
//     else cout << "-1\n";

//     for(int i = 1;i <= n;i++) cnt[i] = 0;
// }

// signed main(){

//     IO;

//     euler(N-1);
//     for(int i = 2;i < N-2;i++){
//         pre[i] = phi[i] + pre[i-1];
//     }

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 5e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 1e6;
// const int INF = 1e6;
// int n, m, a[N], b[N], f[N], d[N];

// struct node{
//     int mn, mx, smx, atag, mtag;
// }tr[N<<3];
// void up(int id){
//     tr[id].mn = min(tr[ls].mn, tr[rs].mn);
// 	if(tr[ls].mx==tr[rs].mx){
// 		tr[id].mx=tr[ls].mx;
// 		tr[id].smx=max(tr[ls].smx,tr[rs].smx);
// 	}else if(tr[ls].mx>tr[rs].mx){
// 		tr[id].mx=tr[ls].mx;
// 		tr[id].smx=max(tr[ls].smx,tr[rs].mx);
// 	}else {
// 		tr[id].mx=tr[rs].mx;
// 		tr[id].smx=max(tr[ls].mx,tr[rs].smx);
// 	}
// }
// void settag(int id, int at, int mt){
//     tr[id].atag += at;
//     tr[id].mn += at;
//     tr[id].mx += at;
//     tr[id].smx += at;
//     // tr[id].mtag += at;
//     // if(mt < tr[id].mtag){
//         // tr[id].mtag = mt;
//         tr[id].mx = min(tr[id].mx, mt);
//         tr[id].mn = min(tr[id].mn, tr[id].mx);
//     // }   
// }
// void down(int id){
//     settag(ls, tr[id].atag, tr[id].mx);
//     settag(rs, tr[id].atag, tr[id].mx);
//     tr[id].atag = 0;
//     // tr[id].mtag = inf;
// }
// void build(int id, int l, int r){
//     tr[id].atag = 0;
//     tr[id].mtag = inf;
//     if(l == r){
//         tr[id].smx = -inf;
//         if(l <= n) tr[id].mn = tr[id].mx = inf;
//         else tr[id].mn = tr[id].mx = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id].mn;
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return min(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
// }
// void modify(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr) {
//         settag(id, v, inf);
//         return;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls, l, mid, ql, qr, v);
//     else if(ql > mid) modify(rs, mid + 1, r, ql, qr, v);
//     else modify(ls, l, mid, ql, qr, v), modify(rs, mid + 1, r, ql, qr, v);
//     up(id);
// }
// void setmin(int id, int l, int r, int ql, int qr, int v){
//     if(v >= tr[id].mx) return;
//     if(ql <= l && r <= qr && v > tr[id].smx){
//         settag(id, 0, v);
//         return;
//     }
//     down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) setmin(ls, l, mid, ql, qr, v);
//     else if(ql > mid) setmin(rs, mid + 1, r, ql, qr, v);
//     else setmin(ls, l, mid, ql, qr, v), setmin(rs, mid + 1, r, ql, qr, v);
//     up(id); 
// }


// // struct node{
// // 	int mx,smx,mi;
// // 	int add1,add2;
// // }tr[4000050];
// // #define ls p<<1
// // #define rs p<<1|1
// // #define mid (l+r>>1)
// // void pushup(int p){
// // 	tr[p].mi=min(tr[ls].mi,tr[rs].mi);
// // 	if(tr[ls].mx==tr[rs].mx){
// // 		tr[p].mx=tr[ls].mx;
// // 		tr[p].smx=max(tr[ls].smx,tr[rs].smx);
// // 	}else if(tr[ls].mx>tr[rs].mx){
// // 		tr[p].mx=tr[ls].mx;
// // 		tr[p].smx=max(tr[ls].smx,tr[rs].mx);
// // 	}else {
// // 		tr[p].mx=tr[rs].mx;
// // 		tr[p].smx=max(tr[ls].mx,tr[rs].smx);
// // 	}
// // }
// // void update(int p,int k1,int k2){
// // 	if(tr[p].mi==tr[p].mx){
// // 		tr[p].mi+=k1;tr[p].mx+=k1;
// // 		k2=k1;
// // 	}else{
// // 		tr[p].mx+=k1;tr[p].mi+=k2;tr[p].smx+=k2;
// // 	}
// // 	tr[p].add1+=k1;tr[p].add2+=k2;
// // }
// // void pushdown(int p){
// // 	int mx=max(tr[ls].mx,tr[rs].mx);
// // 	if(tr[ls].mx==mx)update(ls,tr[p].add1,tr[p].add2);
// // 	else update(ls,tr[p].add2,tr[p].add2);
// // 	if(tr[rs].mx==mx)update(rs,tr[p].add1,tr[p].add2);
// // 	else update(rs,tr[p].add2,tr[p].add2);
// // 	tr[p].add1=tr[p].add2=0;
// // }
// // void build(int p,int l,int r){
// // 	tr[p].add1=tr[p].add2=0;
// // 	if(l==r){
// // 		if(l<=n)tr[p].mi=tr[p].mx=INF;
// // 		else tr[p].mi=tr[p].mx=1;
// // 		tr[p].smx=-INF;
// // 		return;
// // 	}
// // 	build(ls,l,mid);
// // 	build(rs,mid+1,r);
// // 	pushup(p);
// // }
// // void update1(int p,int l,int r,int x,int y,int w){
// // 	if(x<=l&&r<=y){
// // 		update(p,w,w);
// // 		return;
// // 	}
// // 	pushdown(p);
// // 	if(x<=mid)update1(ls,l,mid,x,y,w);
// // 	if(mid<y)update1(rs,mid+1,r,x,y,w);
// // 	pushup(p);
// // }
// // void update2(int p,int l,int r,int x,int y,int w){
// // 	if(tr[p].mx<=w)return;
// // 	if(x<=l&&r<=y&&tr[p].smx<w){
// // 		update(p,w-tr[p].mx,0);
// // 		return;
// // 	}
// // 	pushdown(p);
// // 	if(x<=mid)update2(ls,l,mid,x,y,w);
// // 	if(mid<y)update2(rs,mid+1,r,x,y,w);
// // 	pushup(p);
// // }
// // int query(int p,int l,int r,int x,int y){
// // 	if(x<=l&&r<=y)return tr[p].mi;
// // 	pushdown(p);
// // 	int ans=INF;
// // 	if(x<=mid)ans=min(ans,query(ls,l,mid,x,y));
// // 	if(mid<y)ans=min(ans,query(rs,mid+1,r,x,y));
// // 	return ans;
// // }
// // #undef ls
// // #undef rs
// // #undef mid


// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= m;i++) cin >> b[i];
//     sort(b + 1, b + 1 + m);
//     build(1, 1, m+n);
    

//     f[1] = 0;
//     int it, st = n;
//     int* dp = f;
//     for(int i = 2;i <= n;i++){
//         it = lower_bound(b + 1, b + 1 + m, a[i]) - b - 1;
//         f[i] = min(a[i] > a[i-1] ? f[i-1] : inf, it >= 1 ? query(1, 1, m+n, st+1, st+it) : inf);
//         st--;
//         modify(1, 1, n+m, st+1, st + m, 1);
//         // update1(1, 1, n+m, st+1, st + m, 1);

//         it = lower_bound(b + 1, b + 1 + m, a[i-1]) - b;
//         if(it <= m) setmin(1, 1, m+n, st + it, st + m, f[i-1]+1);
//         // if(it <= m) update2(1, 1, m+n, st + it, st + m, f[i-1]+1);
//         // cerr << i << ' ' << f[i] << endl;

//         // if(a[i-1]<a[i])dp[i]=dp[i-1];
// 		// else dp[i]=INF;
// 		// int pos=lower_bound(b+1,b+1+m,a[i])-b;
// 		// int res=query(1,1,n+m,st+1,st+pos-1);
// 		// pos=lower_bound(b+1,b+1+m,a[i-1])-b;
// 		// if(dp[i]>res)dp[i]=res;
// 		// st--;
// 		// update1(1,1,n+m,st+1,st+m,1);
// 		// update2(1,1,n+m,st+pos,st+m,dp[i-1]+1);
//     }

//     int ans = min(f[n], query(1, 1, m+n, st+1, st+m));
//     if(ans >= inf) cout << "-1\n";
//     else cout << ans << endl;
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
// #define lson id << 1
// #define rson id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int NONE = 0;
// const int NEED = 1;
// const int MUST = 2;
// int n, m, fa[N], a[N], L[N], R[N], vis[N], el[N], er[N];

// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// struct edge{
//     int u, v, w, id;
// };
// vector<edge>g[N];
// vector<edge>G[N];
// vector<edge>e;

// int tr_data[N], id[N], tot;
// int dep[N], par[N], top[N], siz[N], son[N];

// //线段树
// int tr[N << 2];
// void up(int id){
//     tr[id] = max(tr[lson], tr[rson]);
// }
// void build(int id, int l ,int r){
//     if(l == r){
//         tr[id] = tr_data[l];
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// int query(int id, int l, int r, int ql ,int qr){
//     if(ql <= l && r <= qr) return tr[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return max(query(lson, l, mid, ql, qr), query(rson, mid + 1, r, ql, qr));
// }

// //树链剖分
// void dfs(int u, int fa){
//     dep[u] = dep[fa] + 1;
//     par[u] = fa;
//     siz[u] = 1;
//     for(auto [u, v, w, id] : g[u]) if(v != fa) {
//         a[v] = w;
//         dfs(v, u);
//         siz[u] += siz[v];
//         if(siz[son[u]] < siz[v])
//             son[u] = v;
//     }
// }
// void dfs2(int u, int tp){
//     top[u] = tp;
//     L[u] = id[u] = ++ tot;
//     tr_data[tot] = a[u];
//     if(son[u]) dfs2(son[u], tp);

//     for(auto [u, v, w, id] : g[u]) if(v != par[u] && v != son[u])
//         dfs2(v, v);
//     R[u] = tot;
// }

// //操作函数
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

// unordered_map<int, stack<int>>st;

// int ans[N];
// void dfs3(int u, int f){
//     for(auto [u, v, w, i] : g[u]) if(v != f){
//         el[i] = L[v], er[i] = R[v];
//         st[w].push(i);
//         dfs3(v, u);
//         if(st[w].size() && st[w].top() == i) st[w].pop();
//     }

//     for(auto [u, v, w, i] : G[u]) if(!vis[i]){
//         int ret = line_query(u, v);
//         if(w <= ret){
//             ans[i] = NEED;
//             while(st[w].size() && (id[v] < el[st[w].top()] || id[v] > er[st[w].top()])){
//                 ans[st[w].top()] = NEED;
//                 st[w].pop();
//             }
//         }
//     }
// }

// void init(){
//     for(int i = 1;i <= n;i++){
//         fa[i] = i;
//     }
// }

// void solve(){
//     cin >> n >> m;
//     init();
//     for(int i = 1, u, v, w;i <= m;i++){
//         ans[i] = NONE;
//         cin >> u >> v >> w;
//         e.push_back({u, v, w, i});
//         G[u].push_back({u, v, w, i});
//         G[v].push_back({v, u, w, i});
//     }

//     sort(all(e), [&](const edge& e1, const edge& e2) -> int {
//         return e1.w < e2.w;
//     });

//     for(auto [u, v, w, id] : e){
//         if(find(u) != find(v)){
//             vis[id] = 1;
//             ans[id] = MUST;
//             merg(u, v);
//             g[u].push_back({u, v, w, id});
//             g[v].push_back({v, u, w, id});
//         }
//     }

//     dfs(1, 0);
//     dfs2(1, 1);
//     build(1, 1, n);
    
//     dfs3(1, 0);

//     for(int i = 1;i <= m;i++){
//         // if(n == 20 && m == 100 && i == 9) cout << vis[i] << endl; 
//         if(ans[i] == NONE) cout << "none\n";
//         else if(ans[i] == NEED) cout << "at least one\n";
//         else cout << "any\n";
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
// #define lson id << 1
// #define rson id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int NONE = 0;
// const int NEED = 1;
// const int MUST = 2;
// int n, a, b;

// void solve(){
//     int i = 1;
//     for(int a = 1;a <= 3;a++)
//     for(int b = 1;b <= 3;b++){
//     // for(int i = 1;i <= 9;i++){
//         string s = "D:\\second\\in";
//         string s2 = "D:\\second\\out";
//         s += (char)(i+'0');
//         s += ".txt";

//         // freopen(s.c_str(), "w", stdout);
//         // cout << a << ' ' << b;

//         s2 += (char)(i+'0');
//         s2 += ".txt";
//         i++;
//         // freopen(s.c_str(), "r", stdin);
//         freopen(s2.c_str(), "w", stdout);
//         // cin >> a >> b;
//         if(a == b) cout << "draw";
//         else if(a == 1){
//             if(b == 3) cout << "Alice";
//             else cout << "Bob";
//         }else if(a == 2){
//             if(b == 1) cout << "Alice";
//             else cout << "Bob";
//         }else{
//             if(b == 2) cout << "Alice";
//             else cout << "Bob";
//         }
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
// #define lson id << 1
// #define rson id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, m;

// void solve(){
//     cin >> n >> m;
//     vector<array<int, 2>>eg;
//     vector<array<int, 3>>R;
//     int sl, sr, l, r;
//     cin >> sl >> sr;
//     for(int i = 2;i <= n;i++){
//         cin >> l >> r;
//         eg.push_back({l-sr, r-sl});
//         sl = l;
//         sr = r;
//         R.push_back({eg.back()[1], eg.back()[0], i-2});
//     }
//     set<array<int, 2>>st;
//     for(int i = 1, x;i <= m;i++){
//         cin >> x;
//         st.insert({x, i});
//     }

//     vector<int>ans(n-1);
//     sort(all(R));
//     for(auto [r, l, id] : R){
//         auto P = st.lower_bound({l, 0});
//         if(P == st.end() || (*P)[0] > r){
//             cout << "No\n";
//             return;
//         }
//         ans[id] = (*P)[1];
//         st.erase(P);
//     }

//     cout << "Yes\n";
//     for(auto e : ans) cout << e << ' ';

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
// // #define lson id << 1
// // #define rson id << 1 | 1
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int M = N * 35;
// const int mod = 1e9 + 7;
// const int inf = 2e9+100;
// int n, m, a[N], ans[N];

// int rt[N], sum[M], ls[M], rs[M], tot;
// void insert(int& id1, int id2, int l, int r, int x){
//     id1 = ++tot;
//     sum[id1] = sum[id2] + 1;
//     ls[id1] = ls[id2];
//     rs[id1] = rs[id2];
//     if(l == r && l == x){
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) insert(ls[id1], ls[id2], l, mid, x);
//     else insert(rs[id1], rs[id2], mid + 1, r, x);
// }
// int query(int L, int R, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return sum[R] - sum[L];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls[L], ls[R], l, mid, ql, qr);
//     else if(ql > mid) return query(rs[L], rs[R], mid + 1, r, ql, qr);
//     else return query(ls[L], ls[R], l, mid, ql, qr) + query(rs[L], rs[R], mid + 1, r, ql, qr);
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         a[i] += mod;
//         insert(rt[i], rt[i-1], 1, inf, a[i]);
//     }

//     for(int i = 1;i < n;i++){
//         if(a[i+1] < a[i]) ans[1]++;
//     }

//     for(int i = 1;i <= n;i++){
//         for(int k = 2;k <= n-1;k++){
//             int l = k*i - (k-2), r = min(n, k*i+1);
//             if(l > n) break;
//             int tmp = query(rt[l-1], rt[r], 1, inf, 1, a[i]-1);
//             ans[k] += tmp;
//         }
//     }

//     for(int i = 1;i < n;i++) cout << ans[i] << ' ';
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
// #define endl '\n'
// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, c, a[N];

// struct node{
//     int len, v[33], tag, mx, smx, mv[33], msum, mtag;
//     // node() : len(0), v({0}), tag(0) {};
//     // node() : len(0), v({0}), tag(0), mv({0}), mx(0), smx(0), msum(0), mtag(0) {};

//     void assign(int x){
//         msum = len = mx = x;
//         for(int i = 0;i <= 31;i++) {
//             mv[i] = v[i] = ((x >> i) & 1) * x;
//         }
//     }

//     void setmin(int x){
//         // if(mx <= x) return;
//         int tmp;
//         for(int i = 0;i <= 31;i++) {
//             tmp = mv[i];
//             mv[i] /= mx;
//             mv[i] *= x;
//             v[i] -= tmp - mv[i];
//         }
//         tmp = msum;
//         msum /= mx;
//         msum *= x;
//         len -= tmp - msum;
//         mtag = mx = x;
//     }

//     void Xor(int x){
//         for(int i = 0;i <= 31;i++) if((x >> i) & 1){
//             v[i] = len - v[i];
//             mv[i] = msum - mv[i];
//         }
//     }
//     node operator+(const node& e){
//         node ret(*this);
//         ret.tag = 0;
//         ret.mtag = 0;
//         ret.mx = max(ret.mx, e.mx);

//         if(mx == e.mx){
//             ret.smx = max(smx, e.smx);
//             ret.msum += e.msum;
//             for(int i = 0;i <= 31;i++) ret.mv[i] += e.mv[i];
//         }else if(ret.mx == mx){
//             ret.smx = max(smx, e.smx);
//         }else{
//             ret.smx = max(mx, e.smx);
//             ret.msum = e.msum;
//             for(int i = 0;i <= 31;i++) ret.mv[i] = e.mv[i];
//         }

//         ret.len += e.len;
//         for(int i = 0;i < 33;i++){
//             ret.v[i] += e.v[i];
//         }
//         return ret;
//     }

//     void init(){
//         tag = mx = len = 0;
//         for(int i = 0;i < 33;i++){
//             v[i] = 0;
//         }
//     }
// }tr[N<<2];

// void downm(int id){
//     if(tr[ls].mx > tr[id].mtag && tr[ls].smx < tr[id].mtag) tr[ls].setmin(tr[id].mtag);
//     if(tr[rs].mx > tr[id].mtag && tr[rs].smx < tr[id].mtag) tr[rs].setmin(tr[id].mtag);
//     tr[id].mtag = 0;
// }
// void up(int id){
//     tr[id] = tr[ls] + tr[rs];
// }
// void settag(int id, int x){
//     tr[id].Xor(x);
//     tr[id].tag ^= x;
// }
// void down(int id){
//     settag(ls, tr[id].tag);
//     settag(rs, tr[id].tag);
//     tr[id].tag = 0;
// }
// void build(int id, int l, int r){
//     tr[id].init();
//     if(l == r){
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// void insert(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id].assign(v);
//         return;
//     }
//     if(tr[id].mtag) downm(id);
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(x <= mid) insert(ls, l, mid, x, v);
//     else insert(rs, mid + 1, r, x, v);
//     up(id);
// }
// void Xor(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr){
//         settag(id, v);
//         return;
//     }
//     if(tr[id].mtag) downm(id);
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) Xor(ls, l, mid, ql, qr, v);
//     else if(ql > mid) Xor(rs, mid + 1, r, ql, qr, v);
//     else Xor(ls, l, mid, ql, qr, v), Xor(rs, mid + 1, r, ql, qr, v);
//     up(id);
// }
// int cnt = 0;
// void setmin(int id, int l, int r, int ql, int qr, int v){
//     if(ql <= l && r <= qr) {
//         if(tr[id].mx <= v) return;
//         if(tr[id].smx < v){
//             cnt++;
//             tr[id].setmin(v);
//             return;
//         }
//     }
//     if(tr[id].mtag) downm(id);
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) setmin(ls, l, mid, ql, qr, v);
//     else if(ql > mid) setmin(rs, mid + 1, r, ql, qr, v);
//     else setmin(ls, l, mid, ql, qr, v), setmin(rs, mid + 1, r, ql, qr, v);
//     up(id);
// }
// node query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id];
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     // n = 100000;
//     // for(int i = 1;i <= n;i++) a[i] = n - i + 1;

//     build(1, 1, n);

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         insert(1, 1, n, i, a[i]);
//         if(i > 1){
//             Xor(1, 1, n, 1, i-1, a[i]);
//             setmin(1, 1, n, 1, i-1, a[i]);
//         }

//         node tmp = query(1, 1, n, 1, i);
//         int sum = 0;
//         for(int i = 0;i <= 31;i++) {
//             sum = (((1 << i) * tmp.v[i] % mod) + sum) % mod;
//         }

//         ans = (ans + sum) % mod;
//         // cerr << ans << endl;
//     }

//     cout << ans << endl;

//     // cout << cnt << endl;
// }

// signed main(){

//     IO;

//     // freopen("D:\\Codes\\testfile\\in3.txt", "r", stdin);
//     // freopen("D:\\Codes\\testfile\\out3.txt", "w", stdout);

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }

// //757613646



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     int cnt[2] = {0};
//     for(auto c : s) cnt[c - '0']++;
//     cout << abs(cnt[0] - cnt[1]) << endl;
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
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     for(auto &e : a) cin >> e;
//     int d = (n - a[0]) % n;
//     for(int i = 0;i < n;i++){
//         if(i & 1) {
//             a[i] -= d;
//             while(a[i] < 0) a[i] += n;
//         }else{
//             a[i] += d;
//             a[i] %= n;
//         }
//         if(a[i] != i) {
//             cout << "No\n";
//             return;
//         }
//     }
//     cout << "Yes\n";
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
// const int N = 2e5 + 10;
// int n, m, k;

// void solve(){
//     cin >> n >> k;
//     int ans = 0, cnt = 0;
//     for(int i = 1, e, ls;i <= k;i++){
//         cin >> m >> ls;
//         if(ls == 1){
//             int f = 1;
//             for(int j = 2;j <= m;j++){
//                 cin >> e;
//                 if(f && e - ls != 1) ans += m - j + 1, f = 0, cnt += m - j + 2;
//                 ls = e;
//             }
//             if(f) cnt++;
//         }else{
//             cnt += m;
//             ans += m - 1;
//             for(int j = 2;j <= m;j++) cin >> e;
//         }
//     }

//     ans += cnt-1;
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
// // #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int M = N * 30;
// const int inf = 1e9 + 10;
// int n, q;

// struct Tree{
//     int smn[M], mn[M], mx[M], tot, rt, ls[M], rs[M], tag[M];

//     Tree() : tot(0), rt(0) {
//         smn[0] = inf;
//         mn[0] = mx[0] = ls[0] = rs[0] = tag[0] = 0;
//     };

//     int getrt(){
//         tot++;
//         mx[tot] = mn[tot] = 0;
//         smn[tot] = inf;
//         ls[tot] = rs[tot] = 0;
//         return tot;
//     }

//     void settag(int id, int v){
//         if(v < mn[id]) return;
//         mn[id] = max(mn[id], v);
//         mx[id] = max(mx[id], v);
//         tag[id] = max(tag[id], v);
//     }
//     void down(int id){
//         if(!ls[id]) ls[id] = getrt();
//         if(!rs[id]) rs[id] = getrt();
//         settag(ls[id], tag[id]);
//         settag(rs[id], tag[id]);
//         tag[id] = 0;
//     }
//     void up(int id){
//         mn[id] = min(mn[ls[id]], mn[rs[id]]);
//         mx[id] = max(mx[ls[id]], mx[rs[id]]);
//         if(mn[ls[id]] == mn[rs[id]]){
//             smn[id] = mn[ls[id]];
//         }else if(mn[id] == mn[ls[id]]){
//             smn[id] = min(smn[ls[id]], mn[rs[id]]);
//         }else{
//             smn[id] = min(smn[rs[id]], mn[ls[id]]);
//         }
//     }

//     void setmax(int &id, int l, int r, int ql, int qr, int v){
//         if(!id) id = getrt();
//         if(ql <= l && r <= qr){
//             if(mn[id] >= v) return;
//             if(v <= smn[id]) {
//                 settag(id, v);
//                 return;    
//             }
//         }
//         if(tag[id]) down(id);
//         int mid = l + r >> 1;
//         if(qr <= mid) setmax(ls[id], l, mid, ql, qr, v);
//         else if(ql > mid) setmax(rs[id], mid + 1, r, ql, qr, v);
//         else setmax(ls[id], l, mid, ql, qr, v), setmax(rs[id], mid + 1, r, ql, qr, v);
//         up(id);
//     }
//     int getmax(int &id, int l, int r, int x){
//         if(!id){
//             id = getrt();
//             return mx[id];
//         }
//         if(l == r) return mx[id];
//         if(tag[id]) down(id);
//         int mid = l + r >> 1;
//         if(x <= mid) return getmax(ls[id], l, mid, x);
//         else return getmax(rs[id], mid + 1, r, x);
//     }
// }hor, ver;

// void solve(){
//     cin >> n >> q;

//     unordered_map<int,int>vis;
//     while(q--){
//         int x, y;
//         char op;
//         cin >> x >> y >> op;
//         swap(x, y);
//         if(vis[x]++){
//             cout << "0\n";
//             continue;
//         }

//         if(op == 'U'){
//             int r = x;
//             int l = hor.getmax(hor.rt, 1, inf, y);
//             cout << r - l << endl;
//             if(l < r) ver.setmax(ver.rt, 1, inf, l + 1, r, y);
//         }else{
//             int r = y;
//             int l = ver.getmax(ver.rt, 1, inf, x);
//             cout << r - l << endl;
//             if(l < r) hor.setmax(hor.rt, 1, inf, l + 1, r, x);
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 100 + 10;
// const int mod = 1e9 + 7;
// const int inf = 1e9 + 10;
// int n, k, a[N], f[N][N][3], s[N];

// int qpow(int a, int b){
//     int ret = 1;
//     while(b){
//         if(b & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return ret;
// }

// int inv[N], fac[N];
// void get_inv(){
//     inv[0] = fac[0] = 1;
//     for(int i = 1;i < N;i++){
//         fac[i] = fac[i-1] * i % mod;
//     }
//     inv[N - 1] = qpow(fac[N - 1], mod - 2);
//     for(int i = N - 2;i >= 1;i--){
//         inv[i] = inv[i+1] * (i+1) % mod;
//     }
// }

// int add(int a, int b){
//     return (a + b) % mod;
// }
// int mul(int a, int b){
//     return a * b % mod;
// }
// int C(int a, int b){
//     return (fac[b] * inv[b-a] % mod) * inv[b] % mod;
// }

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++) cin >> a[i];
    
//     f[1][1][2] = f[1][0][0] = 1;
//     for(int i = 2;i <= n;i++){
//         for(int j = 1;j <= min(i, k);j++){
//             f[i][j][0] = add(f[i-1][j][0], f[i-1][j][1]);
//             f[i][j][1] = add(f[i-1][j-1][1], f[i-1][j-1][2]);
//             f[i][j][2] = add(f[i-1][j-1][0], add(f[i-1][j-1][1], f[i-1][j-1][2]));
//         }
//     }

//     cerr << f[n][k][0] << ' ' << f[n][k][1] << endl;

//     f[n][k][2] = 0;
//     for(int i = 1;i <= n;i++){
//         s[i] = mul(fac[n-i], add(f[i][k][0], add(f[i][k][1], f[i][k][2])));
//     }

//     int ans = 0;
//     for(int i = k;i <= n;i++){
//         ans = add(ans, mul(mul((((i-k)&1) ? -1 : 1), C(i, k)), s[i]) );
//     }

//     cout << ans << endl;
// }   

// signed main(){

//     IO;
//     get_inv();
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
// const int N = 100 + 10;
// const int mod = 1e9 + 7;
// const int inf = 1e9 + 10;
// int n, m;


// void solve(){
//     cin >> n >> m;
//     if(((n + m) & 1) == 0) cout << "Bob\n";
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 100 + 10;
// const int mod = 1e9 + 7;
// const int inf = 1e9 + 10;
// int n, m;


// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     int a = 0, b = 0;
//     for(auto e : s) {
//         if(e == '+') a++;
//         else b++;
//     }
//     cout << abs(a - b) << endl;
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
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 100 + 10;
// const int mod = 1e9 + 7;
// const int inf = 1e9 + 10;
// int n, m;


// void solve(){
//     cin >> n;
//     vector<int>a(n + 5);
//     vector<int>vis(n + 5);
//     vector<int>b;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] == a[i-1]) i--, n--;
//     }

//     if(is_sorted(a.begin() + 1, a.begin() + 1 + n)){
//         for(int i = 1;i < n;i++){
//             if(a[i] < a[i+1]) ans++;
//         }
//         ans--;
//         cout << max(0ll, ans) << endl;
//         return;
//     }

//     for(int i = 2;i < n;i++){
//         if((a[i-1] > a[i] && a[i] < a[i+1]) || (a[i-1] < a[i] && a[i] > a[i+1])){
//             vis[i] = 1;
//             b.push_back(a[i]);
//             i++;
//         }
//     }

//     // for(auto e : b) cerr << e << ' ';

//     for(int i = 0;i + 1 < b.size();i++){
//         if(b[i] < b[i+1]) ans++;
//     }
//     int ls = inf;
//     for(int i = 1;i <= n;i++) if(!vis[i]){
//         if(a[i] > ls) ans++;
//         ls = a[i];
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
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 1e9 + 10;
// int n, m, a[N];


// void solve(){
//     // cin >> n;
//     // vector<int>a(n+5);
//     // int a1 = inf, a2 = inf, ans = 0;
//     // for(int i = 1;i <= n;i++){
//     //     cin >> a[i];
//     //     if(a[i] > a1 && a[i] > a2){
//     //         ans++;
//     //         if(a1 < a2) a1 = a[i];
//     //         else a2 = a[i]; 
//     //     }else if(a[i] <= a1 && a[i] <= a2){
//     //         if(a1 < a2) a1 = a[i];
//     //         else a2 = a[i];
//     //     }else if(a[i] <= a1){
//     //         a1 = a[i];
//     //     }else {
//     //         a2 = a[i];
//     //     }
//     // }

//     // cout << ans << endl;


//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     vector<int>vec[2];
//     vec[0].push_back(inf);
//     vec[1].push_back(inf);
 
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         // if(vec[0].size() == 1) {
//         //     vec[0].push_back(a[i]);
//         //     continue;
//         // }
//         // if(vec[1].size() == 1) {
//         //     vec[1].push_back(a[i]);
//         //     continue;
//         // }
//         if(a[i] <= vec[0].back() && a[i] <= vec[1].back()){
//             if(vec[0].back() > vec[1].back()) vec[1].push_back(a[i]);
//             else vec[0].push_back(a[i]);
//             continue;
//         }
//         if(a[i] > vec[0].back() && a[i] > vec[1].back()){
//             if(vec[0].back() > vec[1].back()) vec[1].push_back(a[i]);
//             else vec[0].push_back(a[i]);
//             continue;
//         }
//         if(vec[0].back() > vec[1].back()) vec[0].push_back(a[i]);
//         else vec[1].push_back(a[i]);
//     }
//     for(int i = 0;i <= 1;i++){
//         for(int j = 1;j + 1 < vec[i].size();j++){
//             if(vec[i][j] < vec[i][j+1]) ans++;
//             // cerr << vec[i][j] << ' ';
//         }
//         // cerr << vec[i].back() << endl;
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
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 1e9 + 10;
// int n, m, a[N];

// int lowbit(int x){
//     return x & -x;
// }

// void solve(){
//     cin >> n;
//     if(n & 1){
//         cout << "Bob\n";
//     }else{
//         if(lowbit(n) == n){
//             for(int i = 0;i <= 31;i++) if((1<<i) == n){
//                 if(i & 1) cout << "Bob\n";
//                 else cout << "Alice\n";
//                 return;
//             }
//         }else{
//             cout << "Alice\n";
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
// #define ls id << 1
// #define rs id << 1 | 1
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 1e9 + 10;
// int n, q, a[N];

// class Tree{
//     int sum[N<<2], len[N<<2], tag[N<<2];

// public:
//     void up(int id){
//         sum[id] = sum[ls] + sum[rs];
//         len[id] = len[ls] + len[rs];
//     }
//     void build(int id, int l, int r){
//         sum[id] = tag[id] = 0;
//         if(l == r) {
//             len[id] = 1;
//             return;
//         }
//         int mid = l + r >> 1;
//         build(ls, l, mid);
//         build(rs, mid + 1, r);
//         up(id);
//     }
//     void settag(int id, int v){
//         sum[id] += v * len[id];
//         tag[id] += v;
//     }
//     void down(int id){
//         settag(ls, tag[id]);
//         settag(rs, tag[id]);
//         tag[id] = 0;
//     }
//     void modify(int id, int l, int r, int ql, int qr, int v){
//         if(ql <= l && r <= qr){
//             settag(id, v);
//             return;
//         }
//         if(tag[id]) down(id);
//         int mid = l + r >>1;
//         if(qr <= mid) modify(ls, l, mid, ql, qr, v);
//         else if(ql > mid) modify(rs, mid + 1, r, ql, qr, v);
//         else modify(ls, l, mid, ql, qr, v), modify(rs, mid + 1, r, ql, qr, v);
//         up(id);
//     }
//     int query(int id, int l, int r, int ql, int qr){
//         if(ql <= l && r <= qr) return sum[id];
//         if(tag[id]) down(id);
//         int mid = l + r >> 1;
//         if(qr <= mid) return query(ls, l, mid, ql, qr);
//         else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//         else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
//     }
//     void change(int id, int l, int r, int x, int v){
//         if(l == r){
//             sum[id] = v;
//             return;
//         }
//         if(tag[id]) down(id);
//         int mid = l  + r >> 1;
//         if(x <= mid) change(ls, l, mid, x, v);
//         else change(rs, mid + 1, r, x, v);
//         up(id);
//     }
// }atr, idtr;

// void solve(){
//     cin >> n >> q;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     atr.build(1, 1, n);
//     idtr.build(1, 1, n);

//     int sum = 0;
//     while(q--){
//         int op, x, y, l, r;
//         cin >> op;
//         if(op == 1){
//             cin >> x >> y;
//             if(a[x] == y) continue;
//             atr.modify(1, 1, n, a[x], a[x], idtr.query(1, 1, n, x, x));
//             idtr.change(1, 1, n, x, 0);
//             a[x] = y;
//         }else if(op == 2){
//             cin >> l >> r;
//             sum += r - l + 1;
//             idtr.modify(1, 1, n, l, r, 1);
//         }else{
//             cin >> x;
//             int p = lower_bound(a + 1, a + 1 + n, x) - a - 1;
//             int ans = sum;
//             if(p >= 1) ans -= idtr.query(1, 1, n, 1, p);
//             if(x - 1 >= 1) ans -= atr.query(1, 1, n, 1, x-1);
//             cout << ans << endl;
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
// #define ls id << 1
// #define rs id << 1 | 1
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, q, a[N], f[N][4];
// int mp[300], vd[300];
// char c[] = "hard";

// void solve(){
//     mp['h'] = 0;
//     mp['a'] = 1;
//     mp['r'] = 2;
//     mp['d'] = 3;

//     vd['h'] = 1;
//     vd['a'] = 1;
//     vd['r'] = 2;
//     vd['d'] = 3;
//     cin >> n;
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     for(int i = 1;i <= n;i++){
//         if(!vd[s[i]]){
//             for(int j = 0;j < 4;j++) f[i][j] = f[i-1][j];
//         }else{
//             for(int j = 0;j < 4;j++){
//                 if(mp[s[i]] == j){
//                     f[i][j] = f[i-1][j] + a[i];
//                 }else if(mp[s[i]] == j-1){
//                     f[i][j] = min(f[i-1][j-1], f[i-1][j]);
//                 }else{
//                     f[i][j] = f[i-1][j];
//                 }
//             }
//         }
//     }

//     int ans = inf;
//     for(int i = 0;i < 4;i++){
//         ans = min(ans, f[n][i]);
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
// #define ls id << 1
// #define rs id << 1 | 1
// #define all(x) (x).begin(), (x).end()
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 3e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, q, a[N];


// int qpow(int a, int b){
//     int ret = 1;
//     while(b){
//         if(b & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return ret;
// }

// struct node{
//     int sum, mx, sum2;

//     node(){}
//     node(int x) : mx(x) {
//         int p = qpow(10, x) - 1;
//         // if(p < 9){
//         //     sum = sum2 = (p+mod) / 9;
//         // }else{
//         //     sum = sum2 = (p) / 9;
//         // }
//         if(p < 0) p += mod;
//         sum = sum2 = p * qpow(9, mod-2) % mod;
//     }

//     node operator+(const node& e){
//         node ret;
//         ret.sum = (sum + e.sum) % mod;
//        if(mx > e.mx){
//             ret.mx = mx;
//             ret.sum2 = (sum2 + (qpow(10, mx - e.mx) * e.sum2 % mod)) % mod;
//        }else{
//             ret.mx = e.mx;
//             ret.sum2 = (e.sum2 + (qpow(10, e.mx - mx) * sum2 % mod)) % mod;
//        }
//        return ret;
//     }
// }tr[N<<2];

// void up(int id){
//     tr[id] = tr[ls] + tr[rs];
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id] = node(a[l]);
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         tr[id] = node(v);
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(ls, l, mid, x, v);
//     else change(rs, mid + 1, r, x, v);
//     up(id);
// }
// node query(int id, int l, int r, int ql, int qr){
//     // cerr << l << ' ' << r << ' ' << ql << " " << qr << endl;
//     if(ql <= l && r <= qr) return tr[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
// }

// void solve(){
//     cin >> n >> q;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);


//     while(q--){
//         int op, x, d, l, r;
//         cin >> op;
//         if(op == 1){
//             cin >> x >> d;
//             change(1, 1, n, x, d);
//         }else if(op == 2){
//             cin >> l >> r;
//             cout << query(1, 1, n, l, r).sum << endl;
//         }else{
//             cin >> l >> r;
//             cout << query(1, 1, n, l, r).sum2 << endl;
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