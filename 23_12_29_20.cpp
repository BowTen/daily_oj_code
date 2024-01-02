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