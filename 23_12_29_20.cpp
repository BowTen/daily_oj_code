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