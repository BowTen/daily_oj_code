// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2500 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, k, f[N][N];



// void solve(){
//     cin >> n >> k;
//     for(int i = 0;i < k;i++) f[0][i] = 1;

//     for(int i = 1;i <= n;i++){
//         for(int j = 0;j < k;j++){
//             for(int x = 0;x + j < k;x++){
//                 int ls = i - (x+1) * (j+1);
//                 if(ls < 0) break;
//                 f[i][j] = (f[i][j] + f[ls][x]) % mod;
//             }
//         }
//     } 

//     int ans = 0;
//     for(int i = 0;i < k;i++){
//         ans = (ans + f[n][i]) % mod;
//     }
//     cout << ans << endl;

//     for(int i = 0;i <= n;i++){
//         for(int j = 0;j <= k;j++){
//             f[i][j] = 0;
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
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2500 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, q;
// int dx[8] = {1, -1 ,0, 0, 1, -1, 1, -1};
// int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};


// void solve(){
//     cin >> n >> m >> q;
//     vector<string>mp(n+5);
//     mp[n+1] = mp[0] = string(m + 5, '#');
//     for(int i = 1;i <= n;i++){
//         cin >> mp[i];
//         mp[i] = '#' + mp[i] + '#';
//     }

//     queue<array<int, 3>>que;
//     pair<int,int>land;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             if(mp[i][j] == '#'){
//                 land = {i, j};
//             }else if(mp[i][j] == 'v'){
//                 que.push({i, j, 0});
//             }
//         }
//     }

//     vector<vector<int>>dis(n+5, vector<int>(m+5));
//     while(que.size()){
//         auto [x, y, d] = que.front();
//         // cerr << x << ' ' << y << ' ' << d << endl;
//         que.pop();
//         for(int i = 0;i < 4;i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] != 'v' && !dis[nx][ny]){
//                 dis[nx][ny] = d + 1;
//                 que.push({nx, ny, d + 1});
//             }
//         }
//     }

//     // cerr << "DEB\n";

//     int qx, qy;
//     auto check = [&](int w) -> bool {
//         if(dis[qx][qy] < w) return false;
//         vector<vector<int>>vis(n+5, vector<int>(m+5));

//         queue<pair<int,int>>que;
//         que.push({qx, qy});
//         vis[qx][qy] = 1;
//         while(que.size()){
//             auto [x, y] = que.front();
//             que.pop();
//             for(int i = 0;i < 4;i++){
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];
//                 if(mp[nx][ny] != '#' && dis[nx][ny] >= w && !vis[nx][ny]){
//                     que.push({nx, ny});
//                     vis[nx][ny] = 1;
//                 }
//             }
//         }

//         que.push(land);
//         while(que.size()){
//             auto [x, y] = que.front();
//             que.pop();

//             if(x == 1 || x == n || y == 1 || y == m){
//                 return false;
//             }

//             for(int i = 0;i < 8;i++){
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];
//                 if(!vis[nx][ny]){
//                     que.push({nx, ny});
//                     vis[nx][ny] = 1;
//                 }
//             }
//         }

//         return true;
//     };

//     while(q--){
//         cin >> qx >> qy;

//         int l = 0, r = n + m;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(check(mid)) l = mid + 1;
//             else r = mid - 1;
//         }
//         cout << r << endl;
//     }

//     // for(int i = 1;i <= n;i++){
//     //     for(int j = 1;j <= m;j++){
//     //         fprintf(stderr, "%4lld", dis[i][j]);
//     //     }
//     //     cerr << endl;
//     // }

//     // qx = 8, qy = 8;
//     // if(check(10)) cerr << "OK\n";
    
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
// const int N = 1e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, q;


// void solve(){
//     cin >> n;
//     cout << "L";
//     for(int i = 1;i <= n;i++) cout << "o";
//     cout << "ng";
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
// const int N = 1e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, q;


// void solve(){
//     cin >> n;
//     int ans = 0;
//     while(n % 2 == 0){
//         ans++;
//         n >>= 1;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, q;
// int num[5] = {0, 2, 4, 6, 8};

// void solve(){
//     cin >> n;
//     if(n == 1){
//         cout << "0\n";
//         return;
//     }
//     n--;
//     stack<int>st;
//     while(n){
//         st.push(n % 5);
//         n /= 5;
//     }
//     while(st.size()){
//         cout << num[st.top()];
//         st.pop();
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
// const int N = 1e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, q;
// int num[5] = {0, 2, 4, 6, 8};

// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     vector<int>pre(n+5);
//     vector<int>suf(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++){
//         pre[i] = min(0ll, a[i] - i);
//         pre[i] = min(pre[i], pre[i-1]);
//     }
//     for(int i = n;i >= 1;i--){
//         suf[i] = min(0ll, a[i] - (n-i+1));
//         suf[i] = min(suf[i], suf[i+1]);
//     }
//     int ans = 1;
//     for(int i = 1;i <= n;i++){
//         pre[i] = i + pre[i];
//         suf[i] = (n-i+1) + suf[i];
//         ans = max(ans, min(pre[i], suf[i]));
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, q;
// int f[15][15];


// void init(){
//     for(int i = 0;i <= 9;i++) f[1][i] = 1;
//     for(int i = 2;i <= 12;i++){
//         for(int j = 0;j <= 9;j++){
//             for(int k = 0;k <= 9;k++){
//                 if(abs(j - k) >= 2) f[i][j] += f[i-1][k];
//             }
//         }
//     }
// }
// int dp(int x){
//     if(!x) return 0;
//     int a[15], cnt = 0, res = 0, last = -5;
//     while(x) a[++cnt] = x % 10, x /= 10;

//     for(int i = cnt;i >= 1;i--){
//         for(int j = (i==cnt);j < a[i];j++){
//             if(abs(j - last) >= 2) res += f[i][j];
//         }
//         if(abs(last - a[i]) < 2) break;
//         last = a[i];
//         if(i == 1) res++;
//     }

//     for(int i = cnt-1;i >= 1;i--){
//         for(int j = 1;j <= 9;j++){
//             res += f[i][j];
//         }
//     }

//     return res;
// }

// void solve(){
//     int a, b;
//     cin >> a >> b;

//     init();

//     // cerr << "DEBUG\n";

//     cout << dp(b) - dp(a-1);

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
// const int N = 1e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, q, k;
// int f[22][22];


// void solve(){
//     cin >> k;
//     for(int i = 0;i <= 9;i++) f[1][i] = 1;
//     for(int i = 1;i <= 18;i++){
//         for(int j = 0;j <= 9;j++){
//             for(int k = 0;k <= 9;k++){
//                 if(abs(j - k) <= 2) f[i][j] += f[i-1][k];
//             }
//         }
//     }


//     int ans = 0;
//     for(int i = 1;i <= 9;i++) ans += f[k][i];
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, q, k;


// void solve(){
//     string s;
//     cin >> s;
//     int p = 0;
//     for(int i = 1;i < s.size() - 1;i++){
//         if(s[i] == 'a'){
//             p = i;
//             break;
//         }
//     }

//     if(p){
//         for(int i = 0;i < s.size();i++){
//             if(i == p) cout << ' ';
//             cout << s[i];
//             if(i == p) cout << ' ';
//         }
//     }else{
//         cout << s[0] << " ";
//         for(int i = 1;i < s.size() - 1;i++){
//             cout << s[i];
//         }
//         cout << ' ' << s.back();
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
// const int N = 1e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, q, k;


// void solve(){
//     cin >> n;
//     map<int, int>mp;
//     vector<vector<int>>vec(n+5);
//     for(int i = 1, e;i <= n;i++){
//         cin >> k;
//         while(k--){
//             cin >> e;
//             vec[i].push_back(e);
//             mp[e]++;
//         }
//     }

//     for(int i = 1;i <= n;i++) {
//         int f = 1;
//         for(auto e : vec[i]){
//             if(mp[e] == 1){
//                 f = 0;
//                 break;
//             }
//         }
//         if(f){
//             cout << "Yes\n";
//             return;
//         }
//     }
//     cout << "No\n";
// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }0





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, q, k;


// void solve(){
//     cin >> n >> k;
//     m = n;
//     if(n == k){
//         cout << n << endl;
//         return;
//     }

//     for(int i = 0;(1ll << i) <= max(n, k);i++){
//         if(((n>>i)&1) < ((k>>i)&1)){
//             cout << "-1\n";
//             return;
//         }
//     }

//     int f = 0, p;
//     for(int i = 0;(1ll << i) <= max(n, k);i++) if(((n >> i) & 1)){
//         if(f){
//             if(((n>>i)&1) != ((k>>i)&1)){
//                 cout << "-1\n";
//                 return;
//             }
//         }else{
//             if(((n>>i)&1) == ((k>>i)&1)){
//                 f = 1;
//             }else{
//                 n ^= (1ll << i);
//                 p = i + 1;
//             }
//         }
//     }

//     n += (1ll << p);

//     if((m & n) != k){
//         cout << "-1\n";
//         return;
//     }
//     cout << n << endl;
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
// const int N = 6e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, a[N], s, t, vis[N], pre[N];

// bool isprime[N];
// int prime[N];
// int cnt;

// void euler(){
//     memset(isprime, true, sizeof(isprime));
//     isprime[1] = false;
//     for(int i = 2;i < N;i++){
//         if(isprime[i]) prime[++cnt] = i;
//         for(int j = 1; j <= cnt && prime[j] * i < N;j++){
//             isprime[prime[j]*i] = false;
//             if(i % prime[j] == 0) break;
//         }
//     }
// }

// int mul[N];

// vector<int>g[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     cin >> s >> t;

//     for(int i = 1;i <= n;i++) {
//         int x = a[i];
//         for(int j = 2;x > 1;j++){
//             if(isprime[x]){
//                 g[i].push_back(x+n);
//                 g[x+n].push_back(i);
//                 break;
//             }
//             if(x % j == 0){
//                 g[i].push_back(j+n);
//                 g[j+n].push_back(i);
//                 while(x % j == 0){
//                     x /= j;
//                 }
//             }
//         }
//     }

//     queue<int>que;
//     que.push(s);
//     vis[s] = 1;
//     while(que.size()){
//         int u = que.front();
//         que.pop();
//         if(u == t) break;
//         for(auto v : g[u]) if(!vis[v]){
//             que.push(v);
//             pre[v] = u;
//             vis[v] = 1;
//         }
//     }

//     if(!vis[t]){
//         cout << "-1\n";
//         return;
//     }
//     vector<int>ans;
//     int u = t;
//     while(u != s){
//         if(u <= n) ans.push_back(u);
//         u = pre[u];
//     }
//     ans.push_back(s);
//     cout << ans.size() << endl;
//     for(int i = ans.size() - 1;i >= 0;i--) cout << ans[i] << ' ';

// }   

// signed main(){

//     IO;
//     euler();

//     // cerr << cnt << endl;

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
// const int N = 6e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, a[N], s, t;

// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     int m = 0;
//     for(int i = 1;i <= n;i++) cin >> a[i], m = max(m, a[i]);
//     cin >> s >> t;

//     vector<vector<int>>g(n + m + 10);
//     for(int i = 1;i <= n;i++){
//         int x = a[i];
//         for(int j = 2;j * j <= x;j++){
//             if(x % j == 0){
//                 g[i].push_back(n+j);
//                 g[n+j].push_back(i);
//                 while(x % j == 0) x /= j;
//             }
//         }
//         if(x > 1) {
//             g[i].push_back(n+x);
//             g[n+x].push_back(i);
//         }
//     }

//     vector<int>pre(n + m + 10);
//     queue<int>que;
//     que.push(s);
//     pre[s] = s;
//     while(!que.empty()){
//         int u = que.front();
//         que.pop();
//         for(auto v : g[u]) if(!pre[v]){
//             pre[v] = u;
//             que.push(v);
//         }
//     }

//     if(!pre[t]){
//         cout << "-1\n";
//         return;
//     }

//     vector<int>ans;
//     int u = t;
//     while(u != s){
//         if(u <= n) ans.push_back(u);
//         u = pre[u];
//     }
//     ans.push_back(s);

//     cout << ans.size() << endl;
//     for(int i = ans.size() - 1;i >= 0;i--){
//         cout << ans[i] << ' ';
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
// const int N = 6e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, a[N], s, t;

// void solve(){
//     cin >> n;
//     int mx = 0, mn = 0, ls = 0, cur;
//     while(n--) {
//         cin >> cur;
//         cur += ls;
//         mx = max(mx, cur);
//         mn = min(mn, cur);
//         ls = cur;
//     }

//     cout << mx - mn << endl;

// }   

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }