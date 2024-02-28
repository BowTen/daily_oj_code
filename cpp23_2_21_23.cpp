// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// // #define ls id << 1
// // #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int M = N * 50;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;

// int qpow(int a, int b){
// 	int ret = 1;
// 	while(b){
// 		if(b & 1) ret = ret * a % mod;
// 		a = a * a % mod;
// 		b >>= 1;
// 	}
// 	return ret;
// }

// int fac[N], inv[N];
// void init(){
// 	fac[0] = inv[0] = 1;
// 	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
// 	inv[N-1] = qpow(fac[N-1], mod - 2);
// 	for(int i = N - 2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
// }

// int C(int a, int b){
// 	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
// }


// void solve(){
//     int n;
//     cin >> n;
//     for(int k = 1;k <= (n-1) / 2;k++){
// 		int ans = 1;
// 		for(int x = n-2*k;x >= 1;x -= 2*k){
// 			ans = (ans + ((C(n, x) - C(x + 2*k-1, 2*k-1) + mod) % mod)) % mod;
// 		}
// 		cout << ans << ' ';
//     }
// 	cout << endl;
// }


// signed main(){

// 	IO;

// 	init();

// 	int T = 1;
// 	cin >> T;
// 	while(T--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n), b(n);

//     for(auto &e : a) cin >> e;
//     for(auto &e : b) cin >> e;

//     sort(all(a));
//     sort(all(b));

//     int ans = 0;
//     for(int i = 0;i < n;i++) {
//         if(a[i] <= b[i]) ans += b[i] - a[i];
//         else {
//             cout << "-1\n";
//             return;
//         }
//     }

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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()

// void solve(){
//     int n;
//     cin >> n;
//     int sq = sqrt(n);
//     int ans = sq * 4;
//     int d = n - (sq*sq);
//     if(d > sq) ans += 4;
//     else if(d > 0) ans += 2;

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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()

// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<int>s(n+5);
//     for(int i = 1;i <= n;i ++) cin >> s[i];
//     int ans = s[n];
//     while((k-1)*2 >= n-1) n--, k--;

//     int i = 1, j = n;
//     while(i < j){
//         ans = max(ans, s[i] + s[j]);
//         i++, j--;
//     }

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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// int pre[N];

// void solve(){
//     int n, m, ans = 0;
//     cin >> m >> n;

//     while(m){
//         int num = m % 10;
//         if(n >= 10 - num){
//             ans = (ans + 1) % mod;
//             ans = (ans + pre[n - (10-num)]) % mod;
//         }
//         m /= 10;
//         ans = (ans + 1) % mod;
//     }

//     cout << ans << endl;
// }

// signed main(){

//     IO;

//     pre[9] = pre[10] = 1;
//     for(int i = 11;i < N;i++) pre[i] = (pre[i-9] + pre[i-10]) % mod;
//     for(int i = 9;i < N;i++) pre[i] = (pre[i] + pre[i-1]) % mod;

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;


// void solve(){
//     int n, m, cnt = 0;
//     cin >> n >> m;
//     vector<vector<int>>g(n+5);
//     vector<int>dep(n+5);
//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     auto dfs = [&](auto self, int u, int fa) -> void {
//         dep[u] = dep[fa] + 1;
//         for(auto v : g[u]) if(v != fa){
//             if(dep[v] && dep[v] < dep[u]){
//                 cnt++;
//             }
//             else if(dep[v] == 0) self(self, v, u);
//         }
//     };


//     dfs(dfs, 1, 0);

//     for(int i = 1;i <= n;i++) if(!dep[i]){
//         cout << "NO";
//         return;
//     }

//     if(cnt == 1) cout << "FHTAGN!";
//     else cout << "NO";
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     sort(a.begin() + 1, a.begin() + 1 + n);
//     if(a[1] == a[n]) cout << "NO\n";
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>l(n+5), r(n+5, n+1); //last two  first one
//     vector<vector<int>>mp(n+5, vector<int>(n+5));

//     for(int i = 1;i <= n;i++){
//         for(int j = i;j <= n;j++){
//             cin >> mp[i][j];
//             if(mp[i][j] == 1){
//                 r[j] = min(r[j], i);
//             }else if(mp[i][j] == 2){
//                 l[j] = i;
//             }
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         // cerr << l[i] << ' ' << r[i] << endl;
//         if(l[i] >= r[i] || mp[i][i] != 1){
//             cout << "0\n";
//             return;
//         }
//     }

//     vector<vector<int>>f(n+5, vector<int>(n+5));
//     vector<int>sum(n+5);
//     sum[1] = f[1][0] = 2;
//     for(int i = 2;i <= n;i++){
//         for(int j = l[i];j < r[i];j++){
//             if(j == i-1) f[i][j] = sum[i-1];
//             else f[i][j] = f[i-1][j];
//             sum[i] = (sum[i] + f[i][j]) % mod;
//             // cerr << i << ' ' << j << ' ' << f[i][j] << endl;
//         }
//     }

//     cout << sum[n] << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 998244353;

// int fa[N], ne[N];

// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// void solve(){
//     int n, q;
//     cin >> n >> q;

//     for(int i = 1;i <= n;i++) ne[i] = i+1, fa[i] = i;

//     while(q--){
//         int op, x, y;
//         cin >> op >> x >> y;
//         if(x > y) swap(x, y);
//         if(op == 1){
//             merg(x, y);
//         }else if(op == 2){
//             for(int i = x;i <= y;){
//                 merg(x, i);
//                 int nt = ne[i];
//                 ne[i] = ne[y];
//                 i = nt;
//             }

//         }else{
//             if(find(x) == find(y)) cout << "YES\n";
//             else cout << "NO\n";
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>p(n+5), l(n+5), r(n+5), ll(n+5), rr(n+5), pos(n+5);
//     for(int i = 1;i <= n;i++) cin >> p[i], pos[p[i]] = i;
    
//     set<int>st;
//     st.insert(0);
//     st.insert(-1);
//     st.insert(n+1);
//     st.insert(n+2);
//     for(int i = n;i >= 1;i--){
//         r[i] = *st.upper_bound(pos[i]);
//         rr[i] = *st.upper_bound(r[i]);
//         l[i] = *prev(st.lower_bound(pos[i]));
//         ll[i] = *prev(st.lower_bound(l[i]));
//         st.insert(pos[i]);
//         rr[i] = min(n+1, rr[i]);
//         ll[i] = max(0ll, ll[i]);
//     }

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         ans += i * (l[i] - ll[i]) * (r[i] - pos[i]);
//         ans += i * (rr[i] - r[i]) * (pos[i] - l[i]);
//         // cerr << i << ' ' << ll[i] << ' ' << l[i] << ' ' << r[i] << ' ' << rr[i] << ' ' << ans << endl;
//     }

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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 998244353;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     map<int,int>mp;
//     for(int i = 1;i <= n;i++) cin >> a[i], mp[a[i]]++;
//     for(auto [k, v] : mp) if(v == 1){
//         cout << "YES\n";
//         return;
//     }
//     cout << "NO\n";
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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 998244353;

// int p[14], a[14][14];

// void solve(){
//     int n;
//     cin >> n;
//     for(int i = 1;i <= n;i++) 
//         for(int j = 1;j <= n;j++) cin >> a[i][j];

//     for(int i = 1;i <= n;i++) p[i] = i;

//     int ans = mod;
//     do{
//         int tmp = a[p[1]][p[n]];
//         for(int i = 1;i < n;i++){
//             tmp += a[p[i]][p[i+1]];
//         }
//         ans = min(ans, tmp);
//     }while(next_permutation(p+2, p+1+n));

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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;

// int tr[N];
// int lowbit(int x){
//     return x & -x;
// }
// int getsum(int x){
//     int ret = 0;
//     while(x){
//         ret += tr[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }
// void add(int x){
//     while(x < N){
//         tr[x] ++;
//         x += lowbit(x);
//     }
// }


// void solve(){
//     int n, k;
//     cin >> n >> k;

//     k = min(k, n-k);
//     int x = 1, ans = 1;
//     for(int i = 1;i <= n;i++){
//         ans++;
//         add(x);
//         ans -= getsum(x);
//         x += k;

//         if(x > n){
//             ans += getsum(n);
//             x -= n;
//         }
//         add(x);
//         ans += getsum(x-1);
        
//         cout << ans << ' ';
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;



// void solve(){
//     int n;
//     cin >> n;
//     int ans = 0;
//     while(n--){
//         int t;
//         cin >> t;
//         ans += t;
//     }
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;



// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int m;
//     cin >> m;
//     vector<int>b(m+5);
//     for(int i = 1;i <= m;i++) cin >> b[i];
//     sort(b.begin() + 1, b.begin() + 1 + m);
//     for(int i = 1;i <= m;i++) b[i] += b[i-1];

//     for(int i = 1;i <= n;i++){
//         int cnt = upper_bound(b.begin() + 1, b.begin() + 1 + m, a[i]) - b.begin() - 1;
//         cout << cnt << ' ';
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;



// void solve(){
//     string s;
//     cin >> s;
//     int n = s.size();
//     int x;
//     cin >> x;
//     if(x > n){
//         cout << "-1\n";
//         return;
//     }

//     int sm = n - x;
//     string ans;
//     for(int i = 0;i < sm;i++) ans.push_back(s[i]);
//     for(int i = sm;i < n;i++) ans.push_back(((s[i]-'0')^1)+'0');

//     if(s[sm] == '0'){
//         int p;
//         for(int i = sm-1;i >= 0;i--) if(ans[i] == '1'){
//             ans[i] = '0';
//             p = i;
//             break;
//         }
//         x--;
//         int cur = p;
//         while(cur + 1 < n){
//             if(s[cur+1] == '0'){
//                 cur++;
//                 ans[cur] = '1';
//                 x--;
//             }else{
//                 if(x == n-1 - cur) {
//                     cur++;
//                     ans[cur] = '0';
//                     x--;
//                 }else{
//                     cur++;
//                     ans[cur] = '1';
//                 }
//             }
//         }
//     }

//     int f = 0;
//     for(int i = 0;i < ans.size();i++){
//         if(f) cout << ans[i];
//         else if(ans[i] == '1'){
//             cout << ans[i];
//             f = 1;
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;



// void solve(){
//     string s;
//     cin >> s;
//     int x, n = s.size();
//     cin >> x;

//     if(s[0] == '0'){
//         if(x == 0){
//             cout << 0;
//         }else{
//             cout << "-1";
//         }
//         return;
//     }

//     if(x > n){
//         cout << "-1\n";
//         return;
//     }

//     string ans(s);
//     int p = n-x;
//     while(s[p] == '0') p--;
//     ans[p] = '0';
//     x--;

//     for(int i = p+1;i < n;i++) if(s[i] == '0'){
//         ans[i] = '1';
//         x--;
//     }
//     for(int i = n-1;i > p && x > 0;i--) if(s[i] == '1'){
//         ans[i] = '0';
//         x--;
//     }

//     int f = 0;
//     for(auto c : ans){
//         if(f) cout << c;
//         else if(c == '1'){
//             f = 1;
//             cout << c;
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;



// void solve(){
//     int n, d, m;
//     cin >> n >> d;
//     m = n - 1;

//     if(n == 1){
//         if(d == 0) cout << "YES\n";
//         else cout << "NO\n";
//     }

//     if(d > m*(m+1)/2 || d < m){
//         cout << "NO\n";
//         return;
//     }

//     cout << "YES\n";

//     int s = m*(m+1)/2;
//     int p = n;
//     while(s - (p-1) + 1 >= d){
//         s = s - (p-1) + 1;
//         p--;
//     }

//     for(int i = p + 1;i <= n;i++) {
//         cout << 1 << ' ' << i << endl;
//     }
//     for(int i = 2;i < p;i++){
//         cout << i-1 << ' ' << i << endl;
//     }
//     s -= p-1;
//     cout << d - s << ' ' << p << endl;
//     cout << 1 << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;

// struct node{
//     int v, l, r, cnt;
//     int operator<(const node& e) const {
//         if(v == e.v) return l > e.l;
//         return v > e.v;
//     }
// };

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     priority_queue<node>que;
//     int l = 1;
//     for(int i = 2;i <= n;i++){
//         if(a[i] != a[i-1]){
//             que.push({a[i-1], l, i-1, i-l});
//             l = i;
//         }
//     }
//     que.push({a[n], l, n, n-l+1});

//     while(1){
//         auto [v, l, r, cnt] = que.top();
//         que.pop();
//         while(que.size() && que.top().v == v && que.top().l - 1 == r){
//             r = que.top().r;
//             cnt += que.top().cnt;
//             que.pop();
//         }
//         cnt /= 2;
//         v++;
//         que.push({v, l, r, cnt});
//         if(cnt == 0) break;
//     }

//     if(que.size() == 1) cout << "Yes\n";
//     else cout << "No\n";
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin(), (x).end()
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;



// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<int>a(n+5), L(n+5, 1), R(n+5, n+1);
    
//     while(m--){
//         int x, y;
//         cin >> x >> y;

//         int l = 1, r = n;
//         while(l < r){
//             int mid = l + r >> 1;
//             if(y <= mid) {
//                 L[mid] = max(L[mid], x);
//                 r = mid;
//             }else {
//                 R[mid] = min(R[mid], x);
//                 l = mid + 1;
//             }
//         }
//     }

//     for(int i = 1;i <= n;i++) {
//         if(R[i] <= L[i]){
//             cout << "-1\n";
//             return;
//         }
//     }

//     set<array<int, 2>>st;
//     vector<int>idx(n);
//     iota(all(idx), 1);
//     sort(all(idx), [&](int i, int j) -> int {
//         if(L[i] == L[j]) return R[i] < R[j];
//         return L[i] < L[j];
//     });

//     int p = 0;
//     for(int i = 1;i <= n;i++){
//         while(p < n && i >= L[idx[p]]){
//             st.insert({R[idx[p]], idx[p]});
//             p++;
//         }
//         auto it = st.upper_bound({i, n+1});
//         if(it == st.end()){
//             cout << "-1\n";
//             return;
//         }
//         a[(*it)[1]] = i;
//         st.erase(it);
//     }

//     for(int i = 1;i <= n;i++) cout << a[i] << ' ';
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;



// void solve(){
//     int n, m;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     cin >> m;
//     vector<int>b(m+5);
//     int cnt = 0;
//     for(int i = 1;i <= m;i++) cin >> b[i], cnt += b[i] & 1;

//     sort(all1(a));
//     for(int i = n;i >= 1 && cnt > 0;i--){
//         if(a[i] % 2 == 0){
//             a[i] = 0;
//             cnt--;
//         }
//     }

//     int ans = 0;
//     for(int i = 1;i <= n;i++) if(a[i] % 2 == 0){
//         ans += a[i];
//     }

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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;



// void solve(){
//     int n;
//     cin >> n;
//     cout << 3 << endl;
//     cout << 1 << ' ' << n*(n+1)/2 - 1 << ' ' << 0 << endl;
//     for(int i = 2;i <= n;i++) cout << i << ' ' << 0 << ' ' << i << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;



// void solve(){
//     int l1, r1, l2, r2;
//     cin >> l1 >> r1 >> l2 >> r2;
//     int ans = 0;
//     for(int i = l1;i <= r1;i++){
//         if(i >= l2 && i <= r2) ans++;
//     }
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
// using namespace std;
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 1e6 + 10;
// const int mod = 998244353;

// int add(int a, int b){
//     return (a + b) % mod;
// }
// int dv(int a, int b){
//     return (a - b + mod) % mod;
// }

// void solve(){
//     int n, m, K;
//     cin >> n >> m >> K;
//     vector<int>a(n+5);
//     vector<vector<vector<int>>>f(n+2, vector<vector<int>>(n+2, vector<int>(K+2)));
//     vector<vector<vector<int>>>pre(n+2, vector<vector<int>>(n+2, vector<int>(K+2)));
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     pre[0][0][0] = f[0][0][0] = 1;
//     for(int k = 1;k < K;k++) pre[0][0][k] += pre[0][0][k-1];
//     for(int i = 1;i <= n;i++){
//         for(int j = 0;j <= n;j++){
//             if(j > 0) f[i][j][0] = add(pre[i-1][j-1][0], dv(pre[i-1][j-1][K-1], pre[i-1][j-1][K-a[i]-1]));
//             pre[i][j][0] = f[i][j][0];
//             // cerr << i << ' ' << j << ' ' << "0 = " << f[i][j][0] << endl;
//             for(int k = 1;k < K;k++){
//                 if(k >= a[i]) f[i][j][k] = add(f[i][j][k], dv(pre[i-1][j][k], (k-a[i] == 0 ? 0 : pre[i-1][j][k-a[i]-1])));
//                 else f[i][j][k] = add(f[i][j][k], add(pre[i-1][j][k], dv(pre[i-1][j][K-1], pre[i-1][j][K-(a[i]-k)-1])));
//                 pre[i][j][k] = add(pre[i][j][k], add(f[i][j][k], pre[i][j][k-1]));

//                 // cerr << i << ' ' << j << ' ' << k << " = " << f[i][j][k] << endl;
//             }
//         }
//     }


//     int ans = 0;
//     for(int i = 0;i < K;i++) ans = add(ans, f[n][m][i]);

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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 5e5 + 10;
// const int mod = 998244353;

// struct sec{
//     int l, r, id;
// };

// int mn[N<<2];

// void up(int id){
//     mn[id] = min(mn[ls], mn[rs]);
// }
// void build(int id, int l, int r){
//     if(l == r){
//         mn[id] = N;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// void change(int id, int l, int r, int x, int v){
//     if(l == r){
//         mn[id] = min(mn[id], v);
//         return;
//     }
//     int mid = l + r >> 1;
//     if(x <= mid) change(ls, l, mid, x, v);
//     else change(rs, mid + 1, r, x, v);
//     up(id);
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return mn[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return min(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
// }

// void solve(){
//     int n, q, L;
//     cin >> n >> q >> L;
//     vector<sec>a(n+5), qur(q+5);
//     build(1, 1, L);

//     for(int i = 1;i <= n;i++){
//         cin >> a[i].l >> a[i].r;
//         a[i].id = i;
//     }

//     for(int i = 1;i <= q;i++){
//         cin >> qur[i].l >> qur[i].r;
//         qur[i].id = i;
//     }

//     sort(a.begin() + 1, a.begin() + 1 + n, [&](const sec &e1, const sec &e2) -> int {
//         return e1.l < e2.l;
//     });
//     sort(qur.begin() + 1, qur.begin() + 1 + q, [&](const sec &e1, const sec &e2) -> int {
//         return e1.l < e2.l;
//     });

//     vector<int>ans(q+5);
//     int p = 1;
//     for(int i = 1;i <= q;i++){
//         while(p <= n && qur[i].l >= a[p].l){
//             change(1, 1, L, a[p].r, a[p].id);
//             p++;
//         }
//         int ret = query(1, 1, L, qur[i].r, L);
//         ans[qur[i].id] = (ret == N ? 0 : ret);
//     }

//     for(int i = 1;i <= q;i++) cout << ans[i] << endl;

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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// const int N = 5e5 + 10;
// const int mod = 998244353;



// void solve(){
//     int n, x;
//     string s;
//     cin >> n >> x >> s;
//     s = ' ' + s;
//     vector<int>pre(n+5), suf(n+5);
//     int lsum = 0, rsum = 0, a = 0, q = 0;
//     for(int i = 1;i <= n;i++) a += (s[i] == 'a'), q += (s[i] == 'q');
//     for(int i = 1;i <= n;i++) pre[i] += pre[i-1] + (s[i] == 'q'), lsum += (s[i] == 'a') * pre[i];
//     for(int i = n;i >= 1;i--) suf[i] += suf[i+1] + (s[i] == 'q'), rsum += (s[i] == 'a') * suf[i];
//     int ans = 0, mx = 0;
//     for(int i = 1;i <= n;i++) ans += pre[i] * suf[i] * (s[i] == 'a');

//     for(int i = 0;i <= x;i++){
//         int s = i, tmp = ans;
//         if(lsum > rsum) swap(lsum, rsum);
//         int d = rsum - lsum;
//         int cnt = min(s, (d + a-1) / a);
//         tmp += cnt * rsum;                                    
//         lsum += cnt * a;
//         s -= cnt;

//         d = (s + 1) / 2;

//         tmp += d * (lsum + lsum + (d-1) * a) / 2;
//         d = s - d;
//         tmp += d * (rsum + a + rsum + d*a) / 2;
//         tmp += (x-i) * ((i+q)/2) * ((i+1+q)/2);   
//         mx = max(mx, tmp);

//         lsum -= cnt * a;
//     }

//     cout << mx << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 5e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, k;
//     cin >> n;
//     vector<vector<int>>g(n+5), par(n+5, vector<int>(20)), eid(n+5);
//     vector<int>mask(1), dep(n+5), pre(n+5);
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     for(int i = 1;i <= n;i++) eid[i].resize(g[i].size());

//     auto dfs = [&](auto self, int u, int f) -> void {
//         dep[u] = dep[f] + 1;
//         par[u][0] = f;
//         for(int i = 1;i < 20;i++) par[u][i] = par[par[u][i-1]][i-1];
//         for(int i = 0;i < g[u].size();i++) if(g[u][i] != f){
//             pre[g[u][i]] = i;
//             self(self, g[u][i], u);
//         }
//     };  

//     auto col = [&](int u, int v, int id) -> void {
//         if(dep[u] < dep[v]) swap(u, v);
//         for(int i = 19;i >= 0;i--) if(dep[par[u][i]] >= dep[v] && par[u][i] != v) u = par[u][i];
//         if(par[u][0] == v){
//             if(!eid[v][pre[u]]){
//                 eid[v][pre[u]] = mask.size();
//                 mask.push_back(0);
//             }
//             mask[eid[v][pre[u]]] |= id;
//             return;
//         }
//         for(int i = 19;i >= 0;i--) if(par[u][i] != par[v][i]){
//             u = par[u][i];
//             v = par[v][i];
//         }
//         int f = par[u][0];
//         if(!eid[f][pre[u]]){
//             eid[f][pre[u]] = mask.size();
//             mask.push_back(0);
//         }
//         if(!eid[f][pre[v]]){
//             eid[f][pre[v]] = mask.size();
//             mask.push_back(0);
//         }
//         mask[eid[f][pre[u]]] |= id;
//         mask[eid[f][pre[v]]] |= id;
//     };

//     dfs(dfs, 1, 0);


//     cin >> k;
//     for(int i = 1, u, v;i <= k;i++){
//         cin >> u >> v;
//         col(u, v, (1<<(i-1)));
//     }

//     vector<int>dp(1<<k, inf);
//     dp[0] = 0;

//     for(int i = 0;i < (1 << k);i++){
//         for(int j = 1;j < mask.size();j++){
//             dp[mask[j] | i] = min(dp[mask[j] | i], dp[i] + 1);
//         }
//     }

//     // cerr << mask[1] << ' ' << mask[2] << endl;

//     cout << dp[(1<<k) - 1] << endl;
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 26e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, ans = 0;
//     cin >> n;
//     int d = 0, f = 0;
//     for(int i = 1, t;i <= n;i++){
//         cin >> t;
//         if(f){
//             if(t){
//                 ans += d;
//                 d = 0;
//             }else{
//                 d++;
//             }
//         }else if(t){
//             f = 1;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 26e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<array<int, 2>>e(n+5); //x  a
//     vector<int>pre(n+5);

//     for(int i = 1; i <= n;i++) cin >> e[i][1];
//     for(int i = 1; i <= n;i++) {
//         cin >> e[i][0];
//         e[i][0] = abs(e[i][0]);
//     }
//     sort(all1(e));
//     for(int i = 1;i <= n;i++){
//         auto [x, a] = e[i];
//         pre[i] = pre[i-1] + (x - e[i-1][0]) * k - a;
//         if(pre[i] < 0){
//             cout << "NO\n";
//             return;
//         }
//     }
//     cout << "YES\n";

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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 26e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int>a(n+5), on(n+5), pre(n+5);
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//         on[i] += on[i-1];
//         pre[i] += pre[i-1];
//         if(a[i] == 1) on[i]++;
//         else pre[i] += a[i];
//     }

//     while(q--){
//         int l, r;
//         cin >> l >> r;
//         if(pre[r] - pre[l-1] - (r-l+1 - (on[r]-on[l-1])) >= on[r] - on[l-1] && l != r) cout << "YES\n";
//         else cout << "NO\n";
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 3e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// int a[N];
// struct node{
//     int mn, mx, f;
//     node(int a = 0, int b = 0, int c = 0) : mn(a), mx(b), f(c) {};
//     node operator+(const node& e) {
//         node ret;
//         ret.mn = min(mn, e.mn);
//         ret.mx = max(mx, e.mx);
//         if(ret.mn != ret.mx) ret.f = 1;
//         return ret;
//     }
// }tr[N<<2];
// void up(int id){
//     tr[id] = tr[ls] + tr[rs];
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id] = node(a[l], a[l], 0);
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }

// node query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
// }

// void solve(){
//     int n;
//     cin >> n;
//     a[0] = a[n+1] = 0;
//     vector<int>pre(n+5), ans(n+5, inf);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         pre[i] += a[i] + pre[i-1];
//     }

//     build(1, 1, n);

//     for(int i = 1;i <= n;i++) {
//         if(a[i-1] > a[i] || a[i+1] > a[i]){
//             ans[i] = 1;
//             continue;
//         }

//         if(i > 1){
//             int l = 1, r = i-1;
//             while(l <= r){
//                 int mid = l + r >> 1;
//                 if(pre[i-1] - pre[mid-1] > a[i] && query(1, 1, n, mid, i-1).f) l = mid + 1;
//                 else r = mid - 1;
//             }
//             //r
//             if(r >= 1 && r < i){
//                 ans[i] = min(ans[i], i-r);
//             }
//         }
//         if(i < n){
//             int l = i + 1, r = n;
//             while(l <= r){
//                 int mid = l + r >> 1;
//                 if(pre[mid] - pre[i] > a[i] && query(1, 1, n, i+1, mid).f) r = mid - 1;
//                 else l = mid + 1;
//             }
//             //l
//             if(l <= n && l > i){
//                 ans[i] = min(ans[i], l-i);
//             }
//         }
//     }


//     for(int i = 1;i <= n;i++){
//         if(ans[i] != inf) cout << ans[i] << ' ';
//         else cout << "-1 ";
//     }
//     cout << endl;

//     for(int i = 1;i <= n;i++) a[i] = 0;
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 5e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, k;
//     cin >> n;
//     vector<vector<int>>g(n+5), eid(n+5), bit(n+5);
//     vector<int>mask(1), dep(n+5), pre(n+5), fa(n+5);
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     for(int i = 1;i <= n;i++){
//         eid[i].resize(g[i].size());
//         bit[i].resize(g[i].size());
//     }

//     auto dfs = [&](auto self, int u, int f) -> void {
//         dep[u] = dep[f] + 1;
//         fa[u] = f;
//         for(int i = 0;i < g[u].size();i++) if(g[u][i] != f){
//             pre[g[u][i]] = i;
//             self(self, g[u][i], u);
//         }
//     };  

//     auto col = [&](int u, int v, int id) -> void {
//         if(dep[u] < dep[v]) swap(u, v);
//         while(dep[u] > dep[v]){
//             if(!eid[fa[u]][pre[u]]) bit[fa[u]][pre[u]] |= id;
//             else mask[eid[fa[u]][pre[u]]] |= id;
//             if(fa[u] == v){
//                 if(!eid[v][pre[u]]){
//                     eid[v][pre[u]] = mask.size();
//                     mask.push_back(bit[fa[u]][pre[u]]);
//                 }
//             }
//             u = fa[u];
//         }
//         if(u == v) return;
//         while(fa[u] != fa[v]){
//             if(!eid[fa[u]][pre[u]]) bit[fa[u]][pre[u]] |= id;
//             else mask[eid[fa[u]][pre[u]]] |= id;
//             u = fa[u];
//             if(!eid[fa[v]][pre[v]]) bit[fa[v]][pre[v]] |= id;
//             else mask[eid[fa[v]][pre[v]]] |= id;
//             v = fa[v];
//         }
//         int f = fa[u];
//         if(!eid[f][pre[u]]){
//             eid[f][pre[u]] = mask.size();
//             mask.push_back(bit[fa[u]][pre[u]]);
//         }
//         if(!eid[f][pre[v]]){
//             eid[f][pre[v]] = mask.size();
//             mask.push_back(bit[fa[v]][pre[v]]);
//         }
//         mask[eid[f][pre[u]]] |= id;
//         mask[eid[f][pre[v]]] |= id;
//     };

//     dfs(dfs, 1, 0);

//     cin >> k;
//     for(int i = 1, u, v;i <= k;i++){
//         cin >> u >> v;
//         col(u, v, (1<<(i-1)));
//     }

//     vector<int>dp(1<<k, inf);
//     dp[0] = 0;

//     for(int i = 0;i < (1 << k);i++){
//         for(int j = 1;j < mask.size();j++){
//             dp[mask[j] | i] = min(dp[mask[j] | i], dp[i] + 1);
//         }
//     }

//     cout << dp[(1<<k) - 1] << endl;
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 3e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int Log[N];

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5), ans(n+5, inf), pre(n+5);
//     vector<vector<int>>mx(n+5, vector<int>(20)), mn(n+5, vector<int>(20, inf));
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         mx[i][0] = mn[i][0] = a[i];
//         pre[i] += pre[i-1] + a[i];
//     }

//     for(int j = 1;j < 20 ;j++){
//         for(int i = 1;i <= n && i + (1 << j) - 1 <= n;i++){
//             mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
//             mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
//         }
//     }

//     auto sm = [&](int l, int r) -> int {
//         int s = Log[r-l+1];
//         return max(mx[l][s], mx[r-(1<<s)+1][s]) == min(mn[l][s], mn[r-(1<<s)+1][s]);
//     };


//     for(int i = 1;i <= n;i++){
//         if(a[i-1] > a[i] || a[i+1] > a[i]){
//             ans[i] = 1;
//             continue;
//         }
//         if(i > 1){
//             int l = 1, r = i-1;
//             while(l <= r){
//                 int mid = l + r >> 1;
//                 if(pre[i-1] - pre[mid-1] > a[i] && (!sm(mid, i-1))) l = mid + 1;
//                 else r = mid - 1;
//             }
//             if(r >= 1 && pre[i-1] - pre[r-1] > a[i] && (!sm(r, i-1))) ans[i] = min(ans[i], i - r);
//         }
//         if(i < n){
//             int l = i + 1, r = n;
//             while(l <= r){
//                 int mid = l + r >> 1;
//                 if(pre[mid] - pre[i] > a[i] && (!sm(i+1, mid))) r = mid - 1;
//                 else l = mid + 1;
//             }
//             if(l <= n && pre[l] - pre[i] > a[i] && (!sm(i+1, l))) ans[i] = min(ans[i], l - i);
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         cout << (ans[i] == inf ? -1 : ans[i]) << ' ';
//     }
//     cout << endl;

//     for(int i = 1;i <= n;i++){
//         mx[i] = vector<int>(20);
//         mn[i] = vector<int>(20, inf);
//     }
// }


// signed main(){

//     IO;

//     for(int i = 2;i < N;i++) Log[i] = Log[i/2] + 1;

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 3e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// vector<char>mp[300];

// void solve(){
//     string s;
//     cin >> s;
//     int n = s.size();
//     s = ' ' + s;

//     auto dfs = [&](auto self, int p) -> int {
//         if(p > n) return 1;
//         if(p == n){
//             if(mp[s[p]].size() && mp[s[p]][0] == 0) return 1;
//             else return 0;
//         }

//         if(mp[s[p]].empty()) return 0;
//         int ret = 0;
//         for(auto ne : mp[s[p]]){
//             if(ne == s[p+1]) ret += self(self, p+2);
//             else if(ne == 0) ret += self(self, p+1);
//         }
//         return ret;
//     };

//     if(dfs(dfs, 1)) cout << "YES\n";
//     else cout << "NO\n";
// }


// signed main(){

//     IO;

// // "H","HE","LI","BE","B","C","N","O","F","NE",
// // "NA","MG","AL","SI","P","S","CL","AR","K","CA"

//     mp['H'].push_back(0);
//     mp['H'].push_back('E');
//     mp['L'].push_back('I');
//     mp['B'].push_back('E');
//     mp['B'].push_back(0);
//     mp['C'].push_back(0);
//     mp['N'].push_back(0);
//     mp['O'].push_back(0);
//     mp['F'].push_back(0);
//     mp['N'].push_back('E');
//     mp['N'].push_back('A');
//     mp['M'].push_back('G');
//     mp['A'].push_back('L');
//     mp['S'].push_back('I');
//     mp['P'].push_back(0);
//     mp['S'].push_back(0);
//     mp['C'].push_back('L');
//     mp['A'].push_back('R');
//     mp['K'].push_back(0);
//     mp['C'].push_back('A');

//     for(int i = 'A';i <= 'Z';i++) if(mp[i].size()) sort(all(mp[i]));

//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 3e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n;
//     cin >> n;
//     if(n & 1) cout << "potassium\n";
//     else cout << "qxforever\n";
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 3e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n;
//     cin >> n;
//     if(n < 4 || n == 6) cout << "-1\n";
//     else if(n == 4) cout << "2 0 2 0\n";
//     else if(n == 5) cout << "2 1 2 0 0\n";
//     else {
//         cout << n - 4 << " 2 1 ";
//         for(int i = 4;i <= n;i++){
//             if(i == n-3) cout << 1 << ' ';
//             else cout << "0 ";
//         }
//         cout << endl;
//     }
// }


// signed main(){

//     IO;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     // int n = 6;


//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 3e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, m;
//     cin >> n;
//     m = n * 2;
//     vector<int>a(m + 5);
//     for(int i = 1;i <= m;i++){
//         cin >> a[i];
//     }

//     int ans = 0;
//     for(int i = 1;i+5 <= m;i += 2){
//         if(a[i] > a[i+1] && a[i+2] > a[i+3] && a[i+4] > a[i+5] && a[i] < a[i+2] && a[i+1] < a[i+4] && a[i+3] < a[i+5]){
//             ans += 2;
//             swap(a[i+1], a[i+2]);
//             swap(a[i+3], a[i+4]);
//             i += 4;
//         }
//     }
//     for(int i = 1;i+3 <= m;i += 2){
//         if(a[i] > a[i+1] && a[i+2] > a[i+3] && a[i] < a[i+2] && a[i+1] < a[i+3]){
//             ans++;
//             swap(a[i+1], a[i+2]);
//             i += 2;
//         }
//     }
//     for(int i = 1;i+1 <= m;i += 2){
//         if(a[i] > a[i+1]){
//             ans++;
//             swap(a[i], a[i+1]);
//         }
//     }
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 3e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     string s, t;
//     cin >> s >> t;
//     int n = s.size(), m = t.size();
//     vector<int>ne(n+5);
//     s = ' ' + s;
//     t = ' ' + t;

//     for(int i = 2, j = 0;i <= n;i++){
//         while(j && s[i] != s[j+1]) j = ne[j];
//         if(s[i] == s[j+1]) j++;
//         ne[i] = j;
//     }
//     for(int i = 1, j = 0;i <= m;i++){
//         while(j && s[j+1] != t[i]) j = ne[j];
//         if(s[j+1] == t[i]) j++;
//         if(j == n) j = ne[j];
//         else if(j == 0){
//             cout << "No\n";
//             return;
//         }
//     }

//     cout << "Yes\n";
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 5e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


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
// void init(){
//     fac[0] = inv[0] = 1;
//     for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//     inv[N-1] = qpow(fac[N-1], mod-2);
//     for(int i = N-2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
// }

// void solve(){
//     int n, c, ans = 1;
//     cin >> n >> c;
//     vector<int>L(n+5), R(n+5), V(n+5);
//     for(int i = 1;i <= n;i++){
//         cin >> L[i] >> R[i] >> V[i];
//     }

//     auto C = [&](int a, int b) -> int {
//         int ret = 1;
//         for(int i = a-b+1;i <= a;i++) ret = ret * i % mod;
//         return ret * inv[b] % mod;
//     };

//     vector<int>a;

//     auto dfs = [&](auto self, int u) -> void {
//         if(L[u] != -1) self(self, L[u]);
//         a.push_back(V[u]);
//         if(R[u] != -1) self(self, R[u]);
//     };

//     a.push_back(1);
//     dfs(dfs, 1);
//     a.push_back(c);

//     int l = 0;
//     for(int i = 1;i < a.size();i++){
//         if(a[i] != -1){
//             int len = i - l - 1;
//             int vlen = a[i] - a[l] + 1 + (len - 1);
//             if(len) ans = ans * C(vlen, len) % mod;
//             l = i;
//         }
//     }

//     cout << ans << endl;
// }


// signed main(){

//     IO;
//     init();
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 5e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// void solve(){
//     int n, ans = 0;
//     cin >> n;
//     vector<int>c(n+5), cnt(n+5);
//     vector<vector<int>>g(n+5);
//     for(int i = 1;i <= n;i++) cin >> c[i];
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     auto dfs = [&](auto self, int u, int f) -> void {
//         ans += cnt[c[u]];
//         int tmp = cnt[c[u]];
//         for(auto v : g[u]) if(v != f){
//             cnt[c[u]] = 1;
//             self(self, v, u);
//         }
//         cnt[c[u]] = tmp + 1;
//     };

//     dfs(dfs, 1, 0);

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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 5e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// void solve(){
//     string s;
//     cin >> s;
//     map<char, int>mp;
//     for(auto c : s) mp[c]++;
//     for(int i = 0;i < s.size();i++){
//         if(mp[s[i]] == 1) {
//             cout << i+1 << endl;
//             return;
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 5e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>p(n+5), pos(n+5);
//     for(int i = 1;i <= n;i++){
//         cin >> p[i];
//         pos[p[i]] = i;
//     }
//     int q;
//     cin >> q;
//     while(q--){
//         int a, b;
//         cin >> a >> b;
//         if(pos[a] < pos[b]) cout << a << endl;
//         else cout << b << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 5e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// void solve(){
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
//     int q;
//     cin >> q;

//     vector<char>mp(300);
//     for(int i = 'a';i <= 'z';i++) mp[i] = i;
//     vector<array<char, 2>>qur(q+5);
//     for(int i = 1;i <= q;i++) cin >> qur[i][0] >> qur[i][1];
//     for(int i = q;i >= 1;i--) mp[qur[i][0]] = mp[qur[i][1]];

//     for(auto c : s) cout << mp[c];
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 5e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int divd(int x){
//     int res=1;
//     for(int i=2;i*i<=x;i++){
//         if(x%i==0){
//             int cnt=0;
//             while(x%i==0)x/=i,cnt++;
//             if(cnt&1){
//                 res*=i;
//             }
//         }
//     }
//     if(x>1)res*=x;
//     return res;
// }
// void solve(){
//     int n,ans=0,cnt=0;
//     cin >> n;
//     vector<int>a(n+5);
//     map<int,int>mp;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i]==0){
//             cnt++;
//             continue;
//         }
//         int d=divd(a[i]);
//         ans+=mp[d];
//         mp[d]++;
//         // cerr<<ans<<'\n';
//     }
//     ans+=cnt*(cnt-1)/2+cnt*(n-cnt);
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 5e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// void solve(){
//     int n;
//     cin >> n;
//     int m = n * 2;
//     vector<int>a(m+5);
//     for(int i = 1;i <= m;i++) cin >> a[i];

//     int ans = 0;
//     for(int i = 1;i <= m;i+=2){
//         if(a[i] > a[i+1]){
//             if(a[i] < a[i+2]) swap(a[i+1], a[i+2]);
//             else swap(a[i], a[i+1]);
//             ans++;
//         }
//     }
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 5e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// struct harbour{
//     int x, v;
//     int operator<(const harbour& e) const {
//         if(x != e.x) return x < e.x;
//         return v < e.v;
//     }
// };

// class Tree{
// public:

//     struct Tag{
//         int ac, a1, d;
//         Tag() : ac(0), a1(0), d(0) {};
//         Tag(int ac, int st, int a1, int d) : ac(ac), a1(a1), d(d) {};
//     };

//     int mxn;
//     vector<int>sum, len, L, R, atag;
//     vector<Tag>tag;

//     Tree(int n) : mxn(n), sum(n*4+5), len(n*4+5), L(n*4+5), R(n*4+5), tag(n*4+5), atag(n*4+5) {
//         build(1, 1, mxn);
//     }

//     void up(int id){
//         sum[id] = sum[ls] + sum[rs];
//         len[id] = len[ls] + len[rs];
//     }

//     void build(int id, int l, int r){
//         L[id] = l, R[id] = r;
//         if(l == r) {
//             len[id] = 1;
//             return;
//         }
//         int mid = l + r >> 1;
//         build(ls, l, mid);
//         build(rs, mid + 1, r);
//         up(id);
//     }

//     void settag(int id, int a1, int d) {
//         tag[id].ac = 1;
//         atag[id] = 0;
//         sum[id] = len[id] * (a1 + a1 + (len[id] - 1) * d) / 2;
//         tag[id].a1 = a1;
//         tag[id].d = d;
//     }

//     void down(int id){
//         settag(ls, tag[id].a1, tag[id].d);
//         settag(rs, tag[id].a1 + ((len[id]+1)/2)*tag[id].d, tag[id].d);
//         tag[id] = Tag();
//     }

//     void setatag(int id, int v) {
//         sum[id] += len[id] * v;
//         if(tag[id].ac) tag[id].a1 += v;
//         else atag[id] += v;
//     }

//     void downa(int id){
//         setatag(ls, atag[id]);
//         setatag(rs, atag[id]);
//         atag[id] = 0;
//     }

//     void modify(int id, int l, int r, int ql, int qr, int a1, int d) {
//         if(ql <= l && r <= qr){
//             settag(id, a1 + (l-ql) * d, d);
//             return;
//         }
//         if(tag[id].ac) down(id);
//         if(atag[id]) downa(id);
//         int mid = l + r >> 1;
//         if(qr <= mid) modify(ls, l, mid, ql, qr, a1, d);
//         else if(ql > mid) modify(rs, mid + 1, r, ql, qr, a1, d);
//         else modify(ls, l, mid, ql, qr, a1, d), modify(rs, mid + 1, r, ql, qr, a1, d);
//         up(id);
//     }

//     void add(int id, int l, int r, int ql, int qr, int v){
//         if(ql <= l && r <= qr) {
//             setatag(id, v);
//             return;
//         }
//         if(tag[id].ac) down(id);
//         if(atag[id]) downa(id);
//         int mid = l + r >> 1;
//         if(qr <= mid) add(ls, l, mid, ql, qr, v);
//         else if(ql > mid) add(rs, mid + 1, r, ql, qr, v);
//         else add(ls, l, mid, ql, qr, v), add(rs, mid + 1, r, ql, qr, v);
//         up(id);
//     }

//     void change(int id, int l, int r, int x, int v){
//         if(l == r){
//             sum[id] = v;
//             return;
//         }
//         if(tag[id].ac) down(id);
//         if(atag[id]) downa(id);
//         int mid = l + r >> 1;
//         if(x <= mid) change(ls, l, mid, x, v);
//         else change(rs, mid + 1, r, x, v);
//         up(id);
//     }

//     int query(int id, int l, int r, int ql, int qr){
//         if(ql <= l && r <= qr) return sum[id];
//         if(tag[id].ac) down(id);
//         if(atag[id]) downa(id);
//         int mid = l + r >> 1;
//         if(qr <= mid) return query(ls, l, mid, ql, qr);
//         else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//         else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
//     }
// };

// void solve(){
//     int n, m, q;
//     cin >> n >> m >> q;
//     Tree tr(n);
//     set<harbour>hb;
//     vector<harbour>a(m+5);

//     for(int i = 1;i <= m;i++) cin >> a[i].x;
//     for(int i = 1;i <= m;i++){
//         cin >> a[i].v;
//         hb.insert(a[i]);
//     }

//     sort(a.begin() + 1, a.begin() + 1 + m);
//     for(int i = 1;i + 1 <= m;i++){
//         int l = a[i].x+1, r = a[i+1].x-1;
//         if(l <= r){
//             tr.modify(1, 1, n, l, r, (a[i+1].x - (a[i].x+1)) * a[i].v, -a[i].v);
//         }
//     }

//     while(q--){
//         int op, x, y;
//         cin >> op >> x >> y;
//         if(op == 1){
//             tr.change(1, 1, n, x, 0);
            
//             hb.insert({x, y});
//             auto it = hb.find({x, y});
//             int d = next(it)->x - x;
//             int a1 = prev(it)->v;
//             int l = prev(it)->x+1, r = x-1;
//             if(l <= r) tr.add(1, 1, n, l, r, -a1*d);

//             l = x+1, r = next(it)->x-1;
//             if(l <= r) tr.modify(1, 1, n, l, r, y*(r-l+1), -y);
//         }else{
//             cout << tr.query(1, 1, n, x, y) << endl;
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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 5e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<int>>mp(n, vector<int>(n)), f(1<<n, vector<int>(n, inf));
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < n;j++){
//             cin >> mp[i][j];
//         }
//     }

//     f[1][0] = 0;
//     for(int i = 1;i < (1<<n);i++){
//         for(int k = 0;k < n;k++) if(i-(1<<k) == (i^(1<<k))){
//             for(int j = 0;j < n;j++) if(i+(1<<j) == (i^(1<<j))){
//                 int ne = i + (1<<j);
//                 if(ne == (1<<n)-1){
//                     f[ne][j] = min(f[ne][j], f[i][k] + mp[j][k] + mp[0][j]);
//                 }else{
//                     f[ne][j] = min(f[ne][j], f[i][k] + mp[j][k]);
//                 }
//             }
//         }
//     }

//     int ans = inf;
//     for(int i = 0;i < n;i++) ans = min(ans, f[(1<<n) - 1][i]);

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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 301;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// bool isprime[N];
// int prime[N];
// int cnt;
// int pid[N];

// void euler() {
//     memset(isprime, true, sizeof(isprime));
//     isprime[1] = false;
//     for(int i = 2;i < N;i++){
//         if(isprime[i]) prime[++cnt] = i;
//         for(int j = 1;j <= cnt && prime[j] * i < N;j++){
//             isprime[prime[j] * i] = false;
//             if(i % prime[j] == 0) break;
//         }
//     }
//     for(int i = 1;i <= cnt;i++) pid[prime[i]] = i;
// }

// void solve(){
//     int n, ans = 0;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     map<int,int>mp;

//     int cur = 0;
//     for(int i = 1;i <= n;i++){
//         mp[cur]++;
//         for(int j = 1;j <= cnt;j++){
//             int tmp = 0;
//             while(a[i] % prime[j] == 0){
//                 tmp++;
//                 a[i] /= prime[j];
//             }
//             if(tmp & 1) cur ^= (1ll << (j-1));
//         }
//         ans += mp[cur];
//     }

//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     euler();
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 1010;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// int a[N], mx[N];

// void solve(){
//     int n, l, r;
//     cin >> n >> l >> r;
//     int tp = r - l;
//     if(mx[n] <= tp){
//         for(int i = 1;i <= n;i++) cout << a[i]+l << ' ';
//         cout << endl;
//     }else{
//         cout << -1 << endl;
//     }
// }

// signed main(){

//     IO;

//     a[0] = -1;
//     for(int i = 1;i < N;i++){
//         if(i & 1) a[i] = a[i-1] + 3;
//         else a[i] = a[i-1] - 2;
//         mx[i] = max(mx[i-1], a[i]);
//     }

//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 1010;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<int>ver(n+5), h;
//     for(int i = 1;i <= n;i++) cin >> ver[i];
//     for(int i = 1, l, r, y;i <= m;i++){
//         cin >> l >> r >> y;
//         if(l > 1) continue;
//         h.push_back(r);
//     }

//     sort(all1(ver));
//     ver[n+1] = 1e9;
//     sort(all(h));

//     int ans = h.size();
//     for(int i = 1, j = 0;i <= n+1;i++){
//         int tmp = i-1;
//         while(j < h.size() && ver[i] > h[j]){
//             j++;
//         }
//         tmp += h.size() - j;
//         ans = min(ans, tmp);
//     }

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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 1010;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, m, s, t;
//     cin >> n >> m;
//     s = m+1, t = m+2;
//     vector<int>x(m+5), y(m+5), idx(m);
//     vector<vector<array<int, 2>>>g(m+5);
//     cin >> x[s] >> y[s] >> x[t] >> y[t];

//     g[s].push_back({t, abs(x[s]-x[t]) + abs(y[s]-y[t])});

//     for(int i = 1;i <= m;i++){
//         cin >> x[i] >> y[i];
//         g[i].push_back({t, abs(x[i]-x[t]) + abs(y[i]-y[t])});
//         g[s].push_back({i, min(abs(x[i]-x[s]), abs(y[i]-y[s]))});
//     }

//     iota(all(idx), 1);
    
//     sort(all(idx), [&](int i, int j) -> int {
//         return x[i] < x[j];
//     });
//     for(int i = 0;i + 1 < idx.size();i++){
//         int u = idx[i], v = idx[i+1];
//         g[u].push_back({v, x[v] - x[u]});
//         g[v].push_back({u, x[v] - x[u]});
//     }

//     sort(all(idx), [&](int i, int j) -> int {
//         return y[i] < y[j];
//     });
//     for(int i = 0;i + 1 < idx.size();i++){
//         int u = idx[i], v = idx[i+1];
//         g[u].push_back({v, y[v] - y[u]});
//         g[v].push_back({u, y[v] - y[u]});
//     }
    
//     vector<int>dis(m+5, inf), vis(m+5);
//     dis[s] = 0;
//     priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int, 2>>>que;
//     que.push({dis[s], s});

//     while(que.size()){
//         auto [d, u] = que.top();
//         que.pop();
//         if(vis[u]) continue;
//         vis[u] = 1;
//         for(auto [v, w] : g[u]) if(!vis[v] && d + w < dis[v]){
//             dis[v] = d + w;
//             que.push({dis[v], v});
//         }
//     }

//     cout << dis[t] << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 1010;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// map<int,int>fa, val;
// int find(int x){
//     if(fa.count(x) == 0) {
//         fa[x] = x;
//         return x;
//     }
//     if(fa[x] == x) return x;
//     int f = find(fa[x]);
//     val[x] ^= val[fa[x]];
//     fa[x] = f;
//     return fa[x];
// }
// void merg(int a, int b, int x){
//     int y = val[a] ^ val[b] ^ x;
//     a = find(a);
//     b = find(b);
//     val[a] ^= y;
//     fa[a] = b;
// }

// void solve(){
//     int q, last = 0;
//     cin >> q;
//     while(q--){
//         int t, l, r, x;
//         cin >> t;
//         if(t == 1){
//             cin >> l >> r >> x;
//             l ^= last;
//             r ^= last;
//             x ^= last;
//             if(l > r) swap(l, r);
//             l--;
//             if(find(l) == find(r)) continue;
//             // cerr << t << ' ' << l << ' ' << r << ' ' << x << endl;
//             merg(l, r, x);
//         }else{
//             cin >> l >> r;
//             l ^= last;
//             r ^= last;
//             if(l > r) swap(l, r);
//             l--;
//             // cerr << t << ' ' << l << ' ' << r << endl;
//             if(find(l) != find(r)){
//                 cout << "-1\n";
//                 last = 1;
//             }else{
//                 last = val[l] ^ val[r];
//                 cout << last << endl;
//             }
//         }
//     }

//     // cerr << val[4] << endl;
//     // cerr << val[5] << endl;
//     // cerr << find(4);
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 12;
// const int M = 1e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// int n, m, q;
// int fa[M*N], mp[N][M], pid[N][M], c[N*M];

// int find (int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// struct node{
//     int l[N], r[N], sum;
//     node operator+(const node& e) {
//         node ret;
//         ret.sum = sum + e.sum;
//         for(int i = 1;i <= n;i++){
//             fa[l[i]] = l[i];
//             fa[r[i]] = r[i];
//             fa[e.l[i]] = e.l[i];
//             fa[e.r[i]] = e.r[i];
//         }
//         for(int i = 1;i <= n;i++) if(c[r[i]] == c[e.l[i]]){
//             int af = find(r[i]), bf = find(e.l[i]);
//             if(af != bf){
//                 fa[af] = bf;
//                 ret.sum--;  
//             }
//         }
//         for(int i = 1;i <= n;i++){
//             ret.l[i] = find(l[i]);
//             ret.r[i] = find(e.r[i]);
//         }
//         return ret;
//     }
// }tr[M<<2];


// void up(int id){
//     tr[id] = tr[ls] + tr[rs];
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].sum = n;
//         for(int i = 1;i <= n;i++){
//             tr[id].l[i] = tr[id].r[i] = pid[i][l];
//             if(mp[i][l] == mp[i-1][l]){
//                 tr[id].sum--;
//                 merg(tr[id].l[i], tr[id].l[i-1]);
//             }
//         }
//         for(int i = 1;i <= n;i++){
//             tr[id].l[i] = tr[id].r[i] = find(tr[id].l[i]);
//         }
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// node query(int id, int l, int r, int ql, int qr){
//     // cerr << l << ' ' << r << endl;
//     if(ql <= l && r <= qr) return tr[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
// }

// void solve(){
//     cin >> n >> m >> q;
//     int tot = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             cin >> mp[i][j];
//             pid[i][j] = ++tot;
//             fa[tot] = tot;
//             c[tot] = mp[i][j];
//         }
//     }

//     build(1, 1, m);

//     // cerr << "DEBUG\n";

//     while(q--){
//         int l, r;
//         cin >> l >> r;
//         cout << query(1, 1, m, l, r).sum << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 12;
// const int M = 1e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i ++) cin >> a[i];
//     sort(a.begin() + 1, a.begin() + 1 + n);
//     a.erase(unique(all1(a)), a.end());
//     for(int i = 1;i + 2 < a.size();i++){
//         if(a[i] + 1 == a[i+1] && a[i]+2 == a[i+2]){
//             cout << "YES\n";
//             return;
//         }
//     }

//     cout << "NO\n";
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 12;
// const int M = 1e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<array<char, 2>>a(q+5);
//     string s;
//     for(int i = 1;i <= q;i++){
//         cin >> s;
//         a[i][1] = s[0];
//         cin >> a[i][0];
//     }

//     int ans = 0;
    
//     auto dfs = [&](auto self, char h, int len) -> int {
//         if(len == n) return 1;
//         int ret = 0;
//         for(int i = 1;i <= q;i++) if(a[i][0] == h){
//             ret += self(self, a[i][1], len+1);
//         }
//         return ret;
//     };

//     cout << dfs(dfs, 'a', 1) << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 12;
// const int M = 1e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5), bd;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i < n;i++){
//         if((a[i] >= a[i+1] && (i&1)) || (a[i] <= a[i+1] && (i%2==0))){
//             bd.push_back(i);
//             bd.push_back(i+1);
//         }
//     }
//     if(bd.size() > 8){
//         cout << "0\n";
//         return;
//     }

//     vector<array<int, 2>>ans;
//     for(auto p : bd){
//         for(int i = 1;i <= n;i++){
//             swap(a[p], a[i]);
//             int f = 1;
//             for(int j = i-1;j <= i+1;j++) if(j >= 1 && j < n)
//                 if((a[j] >= a[j+1] && (j&1)) || (a[j] <= a[j+1] && (j%2==0))) f = 0;
//             for(auto j : bd) if(j + 1 <= n){
//                 if((a[j] >= a[j+1] && (j&1)) || (a[j] <= a[j+1] && (j%2==0))) f = 0;
//                 j--;
//                 if(j >= 1)
//                     if((a[j] >= a[j+1] && (j&1)) || (a[j] <= a[j+1] && (j%2==0))) f = 0;
//             }
//             if(f){
//                 ans.push_back({min(p,i), max(p,i)});
//             }
//             swap(a[p], a[i]);
//         }
//     }

//     if(ans.size()){
//         sort(all(ans));
//         ans.erase(unique(all(ans)), ans.end());
//     }

//     cout << ans.size() << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 100;
// const int M = 1e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// const int D = 1e9;

// int s, t, n, m, x;
// int tot = 1, h[N];  //正边 ^ 1 == 反边， 所以编号从2开始
// struct edge{
//     int v, c, ne;
// }e[M<<1];  //需要建反边，边数开两倍空间
// void add(int u, int v, int c){
//     e[++tot] = {v, c, h[u]};
//     h[u] = tot;
// }

// int dep[N], cur[N];

// bool bfs(){  //先对点分层，减小dfs深度
//     for(int i = 1;i <= n;i++) dep[i] = 0;
//     dep[s] = 1;
//     queue<int>q;
//     q.push(s);
//     while(q.size()){
//         int u = q.front();
//         q.pop();
//         for(int i = h[u];i;i = e[i].ne){
//             int v = e[i].v;
//             if(dep[v] == 0 && e[i].c){
//                 dep[v] = dep[u] + 1;
//                 q.push(v);
//                 if(v == t) return true;
//             }
//         }
//     }
//     return false;
// } 

// int dfs(int u, int mf){  //多路增广
//     if(u == t) return mf;
//     int sum = 0;
//     for(int i = cur[u];i;i = e[i].ne){
//         cur[u] = i;  //当前弧优化
//         int v = e[i].v;
//         if(dep[v] == dep[u] + 1 && e[i].c){
//             int f = dfs(v, min(mf, e[i].c));
//             e[i].c -= f;   //更新残留网
//             e[i^1].c += f;
//             sum += f;
//             mf -= f;
//             if(mf == 0) break;
//         }
//     }
//     if(sum == 0) dep[u] = 0;  //残枝优化
//     return sum;
// }

// int Dinic(){  //累加可行流
//     int flow = 0;
//     while(bfs()){
//         for(int i = 1;i <= n;i++) cur[i] = h[i];
//         flow += dfs(s, inf);
//     }
//     return flow;
// }


// void solve(){
//     cin >> n >> m >> x;
//     s = 1, t = n;
//     vector<array<int,3>>E(m);
//     for(int i = 0;i < m;i++){
//         cin >> E[i][0] >> E[i][1] >> E[i][2];
//     }

//     auto check = [&](double sum) -> int {
//         double av = sum / x;
//         for(int i = 1;i <= n;i++){
//             h[i] = 0;
//             cur[i] = 0;
//         }
//         tot = 1;
//         for(auto [u, v, w] : E){
//             add(u, v, floor(w/av));
//             add(v, u, 0);
//         }

//         return Dinic() >= x;
//     };

//     double l = 0, r = 1e9;
//     int cnt = 300;
//     while(cnt--){
//         double mid = (l+r)/2.0;
//         if(check(mid)) l = mid;
//         else r = mid;
//     }

//     printf("%.10lf\n", l);

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

// int main(){

//     int n, t;
//     cin >> n >> t;
//     vector<int>a(n);
//     for(auto &e : a) cin >> e;

//     int l = 0, r = n-1;
//     while(l <= r){
//         int mid = l + r >> 1;
//         if(a[mid] >= t) r = mid - 1;
//         else l = mid + 1;
//     }
//     if(l < n && a[l] == t) cout << l << endl;
//     else cout << -1 << endl;

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 100;
// const int M = 1e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;



// void solve(){
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<map<int,int>>mp(n+5);
//     vector<int>fa(n+5), siz(n+5, 1);
//     iota(all(fa), 0);

//     auto find = [&](auto self, int x) -> int {
//         return fa[x] == x ? x : fa[x] = self(self, fa[x]);
//     };
//     auto merg = [&](int a, int b) -> void {
//         a = find(find, a);
//         b = find(find, b);
//         fa[a] = b;
//         siz[b] += siz[a];
//     };

//     int de = n-1;

//     for(int i = 1, u, v;i <= m;i++){
//         cin >> u >> v;
//         mp[u][v] = mp[v][u] = 1;
//         if(u > v) swap(u, v);
//         if(u == 1) siz[v] = 0, de--;
//     }

//     if(de < k){
//         cout << "impossible\n";
//         return;
//     }

//     set<int>st;
//     for(int i = 2;i <= n;i++) st.insert(i);

//     queue<int>que;
//     for(int i = 2;i <= n;i++) if(st.count(i)){
//         que.push(i);
//         st.erase(i);
//         while(que.size()){
//             int u = que.front();
//             que.pop();
//             auto it = st.begin();
//             while(it != st.end()) {
//                 if(!mp[u][*it]){
//                     que.push(*it);
//                     merg(u, *it);
//                     it = st.erase(it);
//                 }else{
//                     it = next(it);
//                 }
//             }
//         }
//     }

//     int cnt = 0;
//     for(int i = 2;i <= n;i++){
//         cnt += i == find(find, i);
//         if(siz[fa[i]] == 0){
//             cout << "impossible\n";
//             return;
//         }   
//     }

//     if(cnt > k) cout << "impossible\n";
//     else cout << "possible\n";
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 100;
// const int M = 1e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;



// void solve(){
//     int n, m, q;
//     cin >> n >> m >> q;
//     vector<int>ans(4, 1);

//     cout << 8 << endl;
//     if(!q) return;

//     string s, c;

//     int x, y;
//     cin >> x >> y >> s;
//     cout << 4 << endl;
//     q--;
//     while(q--){
//         int a, b;
//         cin >> a >> b >> c;
//         int cnt = 0;
//         for(int i = 0;i < 4;i++)if(ans[i]){
//             if(i == 0){
//                 if(s[0] == c[0]){
//                     if(abs(b-y) & 1){
//                         int dx = (a-x) % 4;
//                         if(dx == 2 || dx == 3 || dx == -1 || dx == -2) ans[i] = 1;
//                         else ans[i] = 0;
//                     }else{
//                         int dx = (a-x) % 4;
//                         if(dx == 0 || dx == 1 || dx == -3) ans[i] = 1;
//                         else ans[i] = 0;
//                     }
//                 }else{
//                     if(abs(b-y) & 1){
//                         int dx = (a-x) % 4;
//                         if(dx == 2 || dx == 3 || dx == -1 || dx == -2) ans[i] = 0;
//                         else ans[i] = 1;
//                     }else{
//                         int dx = (a-x) % 4;
//                         if(dx == 0 || dx == 1 || dx == -3) ans[i] = 0;
//                         else ans[i] = 1;
//                     }
//                 }
//             }else if(i == 1){
//                 if(s[0] == c[0]){
//                     if(abs(a-x) & 1){
//                         int dx = (b-y) % 4;
//                         if(dx == 2 || dx == 3 || dx == -1 || dx == -2) ans[i] = 1;
//                         else ans[i] = 0;
//                     }else{
//                         int dx = (b-y) % 4;
//                         if(dx == 0 || dx == 1 || dx == -3) ans[i] = 1;
//                         else ans[i] = 0;
//                     }
//                 }else{
//                     if(abs(a-x) & 1){
//                         int dx = (b-y) % 4;
//                         if(dx == 2 || dx == 3 || dx == -1 || dx == -2) ans[i] = 0;
//                         else ans[i] = 1;
//                     }else{
//                         int dx = (b-y) % 4;
//                         if(dx == 0 || dx == 1 || dx == -3) ans[i] = 0;
//                         else ans[i] = 1;
//                     }
//                 }
//             }else if(i == 2){
//                 if(s[0] == c[0]){
//                     if(abs(b-y) & 1){
//                         int dx = -((a-x) % 4);
//                         if(dx == 2 || dx == 3 || dx == -1 || dx == -2) ans[i] = 1;
//                         else ans[i] = 0;
//                     }else{
//                         int dx = -((a-x) % 4);
//                         if(dx == 0 || dx == 1 || dx == -3) ans[i] = 1;
//                         else ans[i] = 0;
//                     }
//                 }else{
//                     if(abs(b-y) & 1){
//                         int dx = -((a-x) % 4);
//                         if(dx == 2 || dx == 3 || dx == -1 || dx == -2) ans[i] = 0;
//                         else ans[i] = 1;
//                     }else{
//                         int dx = -((a-x) % 4);
//                         if(dx == 0 || dx == 1 || dx == -3) ans[i] = 0;
//                         else ans[i] = 1;
//                     }
//                 }
//             }else{
//                 if(s[0] == c[0]){
//                     if(abs(a-x) & 1){
//                         int dx = -((b-y) % 4);
//                         if(dx == 2 || dx == 3 || dx == -1 || dx == -2) ans[i] = 1;
//                         else ans[i] = 0;
//                     }else{
//                         int dx = -((b-y) % 4);
//                         if(dx == 0 || dx == 1 || dx == -3) ans[i] = 1;
//                         else ans[i] = 0;
//                     }
//                 }else{
//                     if(abs(a-x) & 1){
//                         int dx = -((b-y) % 4);
//                         if(dx == 2 || dx == 3 || dx == -1 || dx == -2) ans[i] = 0;
//                         else ans[i] = 1;
//                     }else{
//                         int dx = -((b-y) % 4);
//                         if(dx == 0 || dx == 1 || dx == -3) ans[i] = 0;
//                         else ans[i] = 1;
//                     }
//                 }
//             }
//             cnt += ans[i];
//         }
//         cout << cnt << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 2e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// vector<vector<array<int, 2>>>g;
// int ans, del[N], siz[N];

// int root, sum, mxs;
// void getroot(int u, int f){
//     siz[u] = 1;
//     int mx = 0;
//     for(auto [v, w] : g[u]) if(v != f && !del[v]){
//         getroot(v, u);
//         siz[u] += siz[v];
//         mx = max(mx, siz[v]);
//     }
//     mx = max(mx, sum - siz[u]);
//     if(mx <= mxs) mxs = mx, root = u;
// }

// void calc(int u){
//     vector<int>cnt(4);
//     vector<int>tmp(4);
//     auto getdis = [&](auto self, int u, int fa, int f, int pre) -> void {
//         tmp[f]++;
//         ans++;
//         if(f == 0){
//             ans++;
//             ans += cnt[0]*2 + cnt[3] + cnt[2];
//         }else if(f == 1){
//             ans += cnt[0];
//         }else if(f == 2){
//             ans += cnt[3];
//         }else{
//             ans++;
//             ans += cnt[0] + cnt[3]*2 + cnt[1];
//         }
//         for(auto [v, w] : g[u]) if(v != fa && !del[v]){
//             int ne;
//             if(w == pre) ne = f;
//             else{
//                 if(f == 0) ne = 1;
//                 else if(f == 3) ne = 2;
//                 else continue;
//             }
//             self(self, v, u, ne, w);
//         }
//     };

//     for(auto [v, w] : g[u]) if(!del[v]){
//         tmp = vector<int>(4);
//         getdis(getdis, v, u, (w == 1 ? 3 : 0), w);
//         for(int i = 0;i < 4;i++) cnt[i] += tmp[i];
//     }
// }   

// void divid(int u){
//     calc(u);
//     del[u] = 1;

//     for(auto [v, w] : g[u]) if(!del[v]){
//         mxs = sum = siz[v];
//         getroot(v, 0);
//         divid(root);
//     }
// }

// void solve(){
//     int n;
//     cin >> n;
//     g.resize(n+5);
//     for(int i = 1, u, v, w;i < n;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     sum = mxs = n;
//     getroot(1, 0);
//     divid(root);

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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 2e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;



// void solve(){
//     int n, k, sum = 0, od = 0;
//     cin >> n >> k;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] & 1) od = 1;
//         sum += a[i];
//     }

//     if(k == 1 && od){
//         cout << -1 << endl;
//         return;
//     }

//     if(sum == 0){
//         cout << 0 << endl;
//         return;
//     }

//     for(int i = 0;1;i++){
//         if((1<<i) > k){
//             k = i-1;
//             break;
//         }
//     }

//     vector<int>cnt(k+1);
//     for(int i = 1;i <= n;i++){
//         for(int j = 0;j <= k;j++){
//             cnt[j] += ((a[i] >> j) & 1);
//         }
//     }

//     for(int i = 0;i <= k;i++) if(cnt[i] == 0){
//         cout << 1 << endl;
//         return;
//     }

//     cout << 2 << endl;
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 2e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;



// void solve(){
//     int n, x, y, cnt = 0;
//     cin >> n >> x >> y;
//     if((x ^ y) != (x - y)){
//         cout << "NO\n";
//         return;
//     }

//     x -= y;
//     while(x){
//         cnt += (x & 1);
//         x >>= 1;
//     }

//     if((1ll<<cnt) >= n) cout << "YES\n";
//     else cout << "NO\n";
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
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 2e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;



// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     int cur = 0;
//     for(int i = 1;i <= n;i++){
//         if(a[i] == cur){
//             cur++;
//         }else if(a[i] > cur){
//             a[i] = cur;
//         }
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 2e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;



// void solve(){
//     int n;
//     cin >> n;
//     string a, b;
//     cin >> a >> b;
//     a = ' ' + a;
//     b = ' ' + b;

//     if(a == b){
//         cout << "0\n\n";
//         return;
//     }

//     vector<int>ans;
//     int p = n+1;
//     for(int i = 1;i <= n;i++){
//         if(a[i] != b[i]){
//             cout << -1 << endl;
//             return;
//         }
//         if(a[i] == '1'){
//             p = i;
//             break;
//         }
//     }

//     for(int i = p+1;i <= n;i++) if(a[i] == '1'){
//         ans.push_back(i);
//     }
//     for(int i = n;i >= p+1;i--) if(b[i] == '1'){
//         ans.push_back(i);
//     }

//     cout << ans.size() << endl;
//     for(auto e : ans) cout << e << ' ';
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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 1e6 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// int Log[N];
// vector<int>fac[N];

// class ST{
// public:
//     vector<array<int,20>>data;
//     function<int(int,int)> cmp;

//     ST(int n, const vector<int>& a, function<int(int,int)> f) : data(a.size()), cmp(f) {
//         for(int i = 1;i <= n;i++) data[i][0] = a[i];
//         for(int j = 1;j < 20;j++){
//             for(int i = 1;i <= n && i+(1<<j)-1 <= n;i++){
//                 data[i][j] = cmp(data[i][j-1], data[i+(1<<(j-1))][j-1]);
//             }
//         }
//     }   

//     int query(int l, int r){
//         int s = Log[r-l+1];
//         return cmp(data[l][s], data[r-(1<<s)+1][s]);
//     }
// };

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int>a(n+5), b(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];
//     for(int i = 1;i <= n;i++){
//         a[i] -= b[i];
//     }

//     ST gst(n, a, [&](int a, int b) -> int {return gcd(a, b);});
//     ST mst(n, b, [&](int a, int b) -> int {return max(a, b);});
//     ST ist(n, a, [&](int a, int b) -> int {return min(a, b);});

//     while(q--){
//         int l, r;
//         cin >> l >> r;
//         int gc = gst.query(l, r);
//         int mx = mst.query(l, r);
//         int mn = ist.query(l, r);
//         if(mn < 0 || gc <= mx){
//             cout << -1 << endl;
//             continue;
//         }

//         int ans = *upper_bound(all(fac[gc]), mx);
//         cout << ans << endl;
//     };
// }


// signed main(){

//     IO;
//     for(int i = 1;i < N;i++){
//         for(int j = i;j < N;j += i){
//             fac[j].push_back(i);
//         }
//     }
//     for(int i = 2;i < N;i++) Log[i] = Log[i/2] + 1;
//     int T = 1;
//     cin >> T;
//     while(T--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 2e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;

// vector<vector<array<int, 2>>>g;
// int ans, del[N], siz[N];

// int root, sum, mxs;
// void getroot(int u, int f){
//     siz[u] = 1;
//     int mx = 0;
//     for(auto [v, w] : g[u]) if(v != f && !del[v]){
//         getroot(v, u);
//         siz[u] += siz[v];
//         mx = max(mx, siz[v]);
//     }
//     mx = max(mx, sum - siz[u]);
//     if(mx <= mxs) mxs = mx, root = u;
// }

// void calc(int u){
//     vector<int>cnt(4);
//     vector<int>tmp(4);
//     auto getdis = [&](auto self, int u, int fa, int f, int pre) -> void {
//         tmp[f]++;
//         ans++;
//         if(f == 0){
//             ans++;
//             ans += cnt[0]*2 + cnt[3] + cnt[1];
//         }else if(f == 1){
//             ans += cnt[0];
//         }else if(f == 2){
//             ans += cnt[3];
//         }else{
//             ans++;
//             ans += cnt[0] + cnt[3]*2 + cnt[2];
//         }
//         for(auto [v, w] : g[u]) if(v != fa && !del[v]){
//             int ne;
//             if(w == pre) ne = f;
//             else{
//                 if(f == 0) ne = 1;
//                 else if(f == 3) ne = 2;
//                 else continue;
//             }
//             self(self, v, u, ne, w);
//         }
//     };

//     for(auto [v, w] : g[u]) if(!del[v]){
//         tmp = vector<int>(4);
//         getdis(getdis, v, u, (w == 1 ? 3 : 0), w);
//         for(int i = 0;i < 4;i++) cnt[i] += tmp[i];
//     }
// }   

// void divid(int u){
//     calc(u);
//     del[u] = 1;

//     for(auto [v, w] : g[u]) if(!del[v]){
//         mxs = sum = siz[v];
//         getroot(v, 0);
//         divid(root);
//     }
// }

// void solve(){
//     int n;
//     cin >> n;
//     g.resize(n+5);
//     for(int i = 1, u, v, w;i < n;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     sum = mxs = n;
//     getroot(1, 0);
//     divid(root);

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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 2e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<array<int, 2>>>g(n+5);
//     vector<array<int, 4>>f(n+5);
//     for(int i = 1, u, v, w;i < n;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     int ans = 0;
//     auto dfs = [&](auto self, int u, int fa) -> void {
//         for(auto [v, w] : g[u]) if(v != fa){
//             self(self, v, u);
//             if(w == 1){
//                 ans += (f[v][0] + f[v][2]) * f[u][3] + (f[v][3] + 1) * (f[u][0] + f[u][2] + f[u][3]*2);
//                 f[u][2] += f[v][0] + f[v][2];
//                 f[u][3] += f[v][3] + 1;
//             }else{
//                 ans += (f[v][3] + f[v][1]) * f[u][0] + (f[v][0] + 1) * (f[u][1] + f[u][3] + f[u][0]*2);
//                 f[u][1] += f[v][3] + f[v][1];
//                 f[u][0] += f[v][0] + 1;
//             }
//         }
//         ans += f[u][1] + f[u][2] + f[u][0] * 2 + f[u][3] * 2;
//     };

//     dfs(dfs, 1, 0);

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
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// #define ls id << 1
// #define rs id << 1 | 1
// #define endl '\n'
// const int N = 2e5 + 10;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f3f3f3f3f;


// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<array<int, 2>>>g(n+5);
//     vector<int>scc(n+5), siz(n+5), par(n+5);
//     int tot = 0;
//     for(int i = 1, u, v, w;i < n;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     auto dfs = [&](auto self, int u, int fa, int sc, int f) -> void {
//         siz[sc]++;
//         int ne = 0;
//         for(auto [v, w] : g[u]) if(v != fa){
//             if(w == f){
//                 self(self, v, u, sc, w);
//             }else{
//                 if(!ne){
//                     ne = ++tot;
//                     par[ne] = sc;
//                     siz[ne] = 1;
//                 }
//                 self(self, v, u, ne, w);
//             }
//         }
//     };

//     dfs(dfs, 1, 0, ++tot, g[1][0][1]);

//     int ans = 0;
//     ans += siz[1] * (siz[1]-1);
//     for(int i = 2;i <= tot;i++){
//         ans += siz[i] * (siz[i] - 1);
//         ans += (siz[i]-1) * (siz[par[i]]-1);
//     }

//     cout << ans << endl;
// }


// signed main(){

//     IO;
//     int T = 1;
//     // cin >> T;
//     while(T--) solve();

//     return 0;
// }

