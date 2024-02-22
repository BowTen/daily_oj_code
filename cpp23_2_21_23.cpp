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




#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin(), (x).end()
#define ls id << 1
#define rs id << 1 | 1
const int N = 1e6 + 10;
const int mod = 998244353;



void solve(){

}


signed main(){

    IO;
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}