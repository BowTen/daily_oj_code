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
//     cout << (n + 1) / 2 << endl;
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
// int n, a[N], s, t;

// void solve(){
//     string s;
//     cin >> n;
//     cin >> s;
//     s = ' ' + s;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         vector<int>cnt(10);
//         int mx = 0, sum = 0;
//         for(int j = i;j >= max(1ll, i - 100);j--){
//             cnt[s[j]-'0']++;
//             if(cnt[s[j]-'0'] == 1) sum++;
//             mx = max(mx, cnt[s[j] - '0']);
//             if(mx <= sum) ans++;
//         }        
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
// const int N = 6e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, a[N], s, t;

// void solve(){
//     string s;
//     cin >> n;
//     cin >> s;
//     s = ' ' + s;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         vector<int>cnt(10);
//         int mx = 0, sum = 0;
//         for(int j = i;j >= max(1ll, i - 100);j--){
//             cnt[s[j]-'0']++;
//             if(cnt[s[j]-'0'] == 1) sum++;
//             mx = max(mx, cnt[s[j] - '0']);
//             if(mx <= sum) ans++;
//         }        
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
// const int N = 6e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, a[N], s, t;

// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i], a[i] += a[i-1];
//     map<int,int>mp;
//     int ans = 0, mx = 0;
//     for(int i = n;i >= 1;i--){
//         mp[a[i]]++;
//         mx = max(mx, mp[a[i]]);
//         if(a[i] == a[i-1]){
//             ans += mx;
//             mx = 0;
//             mp.clear();
//         }
//     }
//     ans += mp[0];

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
// const int N = 3e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, fa[N], siz[N], d[N];

// int find(int x){
//     if(x == fa[x]) return x;
//     int rt = find(fa[x]);
//     d[x] += d[fa[x]];
//     return fa[x] = rt;
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     d[a] = siz[b];
//     siz[b] += siz[a];
//     fa[a] = b;
// }

// void solve(){
//     for(int i = 1;i < N;i++){
//         fa[i] = i;
//         siz[i] = 1;
//     }
//     cin >> n;
//     while(n--){
//         char op;
//         int x, y;
//         cin >> op >> x >> y;
//         if(op == 'M'){
//             merg(x, y);
//         }else{
//             if(find(x) == find(y)){
//                 cout << abs(d[x] - d[y]) - 1 << endl;
//             }else{
//                 cout << "-1\n";
//             }
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
// const int N = 2e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m, fa[N];

// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     fa[a] = b;
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= 2 * n;i++) fa[i] = i;
//     vector<array<int, 3>>g;
//     while(m--){
//         int x, y, w;
//         cin >> x >> y >> w;
//         g.push_back({w, x, y});
//     }
//     sort(g.begin(), g.end());
//     for(int i = g.size() - 1;i >= 0;i--){
//         auto [w, x, y] = g[i];
//         if(find(x) == find(y)){
//             cout << w << endl;
//             return;
//         }else{
//             merg(x, y + n);
//             merg(x + n, y);
//         }
//     }
//     cout << 0 << endl;
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
// const int N = 2e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n;

// int lowbit(int x){
//     if(!x) return 0;
//     return x & -x;
// }

// void solve(){
//     int a, b, d;
//     cin >> a >> b >> d;
//     a |= b;
//     if(lowbit(a) < lowbit(d)){
//         cout << "-1\n";
//         return;
//     }

//     int p;
//     for(int i = 0;i <= 33;i++){
//         if((d >> i) & 1) {
//             p = i;
//             break;
//         }
//     }

//     int ans = 0;
//     for(int i = 0;i < 60;i++) if( ((a >> i) & 1) && (((ans >> i) & 1) == 0) ){
//         ans += (d << (i-p));
//     }

//     ans |= a;
//     if(ans % d){
//         cout << "-1\n";
//     }else{
//         cout << ans << endl;
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
// const int N = 2e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m;


// void solve(){
//     cin >> n;
//     string a, b, c;
//     cin >> a >> b >> c;
//     for(int i = 0;i < n;i++){
//         if(c[i] != a[i] && c[i] != b[i]){
//             cout << "YES\n";
//             return;
//         }
//     }
//     cout << "NO\n";
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
// const int N = 2e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// int n, m;


// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     vector<int>cnt(n+5);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         cnt[a[i]]++;
//     }

//     int s = 0, ans = 0;
//     for(int i = 0;i <= n;i++) if(cnt[i] >= 2){
//         s += (cnt[i] * (cnt[i]-1)) / 2;
//     }
//     for(int i = 0;i <= n;i++) if(cnt[i]){
//         if(cnt[i] >= 2){
//             s -= (cnt[i] * (cnt[i]-1)) / 2;
//         }
//         ans += s * cnt[i];
//         if(cnt[i] >= 3){
//             ans += (cnt[i] * (cnt[i]-1) * (cnt[i]-2)) / 6;
//         }
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
// const int N = 2e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// const int R = 1;
// const int L = 0;
// int n, m;


// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     vector<int>dir(n+5);
//     vector<array<int, 2>>pre(n+5); //cnt, dis
//     vector<array<int, 2>>suf(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     dir[1] = R;
//     dir[n] = L;
//     for(int i = 2;i < n;i++){
//         if(a[i] - a[i-1] > a[i+1] - a[i]) dir[i] = R;
//         else dir[i] = L;
//     }

//     // for(int i = 1;i <= n;i++){
//     //     if(dir[i] == R) cerr << "R\n";
//     //     else cerr << "L\n";
//     // }

//     for(int i = 2;i <= n;i++){
//         pre[i][0] += pre[i-1][0];
//         pre[i][1] += pre[i-1][1];
//         if(dir[i-1] == L){
//             pre[i][0] += 1;
//             pre[i][1] += a[i] - a[i-1];
//         }
//         // cerr << i << ' ' << pre[i][0] << ' ' << pre[i][1] << endl;
//     }
//     for(int i = n-1;i >= 1;i--){
//         suf[i][0] += suf[i+1][0];
//         suf[i][1] += suf[i+1][1];
//         if(dir[i+1] == R){
//             suf[i][0] += 1;
//             suf[i][1] += a[i+1] - a[i];
//         }
//         // cerr << i << ' ' << suf[i][0] << ' ' << suf[i][1] << endl;
//     }

//     cin >> m;
//     while(m--){
//         int x, y;
//         cin >> x >> y;
//         int ans;
//         if(y > x) ans = y-x - (pre[y][0]-pre[x][0]) + (pre[y][1]-pre[x][1]);
//         else ans = x-y - (suf[y][0]-suf[x][0]) + (suf[y][1]-suf[x][1]);
//         // int ans = min(y-x - (pre[y][0]-pre[x][0]) + (pre[y][1]-pre[x][1]), y-x - (suf[x][0]-pre[y][0]) + (suf[x][1]-suf[y][1]));
//         cout << ans << endl;
//         // cerr << y-x - (pre[y][0]-pre[x][0]) + (pre[y][1]-pre[x][1]) << ' '
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
// const int N = 2e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// const int R = 1;
// const int L = 0;
// int n, m;


// void solve(){
//     int x;
//     cin >> x;
//     vector<int>ans;
//     int p;
//     for(int i = 62;i >= 0;i--){
//         if((x >> i) & 1){
//             p = i;
//             break;
//         }
//     }

//     for(int i = 1;i <= p;i++) ans.push_back(i);
//     for(int i = p-1;i >= 0;i--) if((x >> i) & 1){
//         ans.push_back(i+1);
//     }

//     cout << ans.size() << endl;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e6 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 998244353;
// const int R = 1;
// const int L = 0;
// int n, m;


// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     vector<int>d(n+5);
//     d[0] = d[n+1] = 1e12;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> d[i];


//     vector<list<int>::iterator>it(n+5);
//     list<int>ls;
//     for(int i = 0;i <= n+1;i++) {
//         ls.push_back(i);
//         it[i] = prev(ls.end());
//     }

//     vector<int>die(n+5);
//     vector<int>ans(n+5);
//     vector<int>check;
//     for(int i = 1;i <= n;i++){
//         check.push_back(i);
//     }
//     for(int i = 1;i <= n;i++){
//         vector<int>cur;
//         for(auto id : check) if(id >= 1 && id <= n && (!die[id])){
//             if(d[id] < a[*prev(it[id])] + a[*next(it[id])]){
//                 die[id] = 1;
//                 cur.push_back(id);
//                 ans[i]++;
//             }
//         }
//         if(cur.empty()) break;
//         check.clear();
//         for(auto id : cur){
//             if(!die[*prev(it[id])]){
//                 check.push_back(*prev(it[id]));
//             }
//             if(!die[*next(it[id])]){
//                 check.push_back(*next(it[id]));
//             }
//         }
//         for(auto id : cur){
//             ls.erase(it[id]);
//         }
//     }

//     for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
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
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, m, Log[N], mx[N][20];

// void solve(){
//     cin >> n >> m;
//     vector<int>a(n+5);
//     vector<int>L(n+5);
//     vector<int>R(n+5);
//     a[0] = a[n+1] = inf;
//     for(int i = 1;i <= n;i++) cin >> a[i], mx[i][0] = i;

//     stack<int>st;
//     st.push(0);
//     for(int i = 1;i <= n;i++){
//         while(a[st.top()] < a[i]) st.pop();
//         L[i] = st.top()+1;
//         st.push(i);
//     }
//     while(st.size()) st.pop();
//     st.push(n+1);
//     for(int i = n;i >= 1;i--){
//         while(a[st.top()] <= a[i]) st.pop();
//         R[i] = st.top() - 1;
//         st.push(i);
//     }

//     auto cmp = [&](int i, int j) -> int {
//         if(a[i] == a[j]) return i > j;
//         return a[i] < a[j];
//     };

//     auto query = [&](int l, int r) -> int {
//         int s = Log[r - l + 1];
//         return max(mx[l][s], mx[r-(1<<s)+1][s], cmp);
//     };

//     for(int j = 1;j < 20;j++){
//         for(int i = 1;i + (1<<j) - 1 <= n;i++){
//             mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1], cmp);
//         }
//     }

//     // cerr << max(1, 2, cmp);

//     // for(int i = 1;i <= n;i++){
//     //     cerr << i << ' ' << L[i] << ' ' << R[i] << "   " << query(L[i], R[i]) << endl;
//     // }

//     vector<vector<int>>f(n+5, vector<int>(m+5));

//     auto dfs = [&](auto self, int i) -> void {
//         if(L[i] == R[i]){
//             for(int j = 1;j <= m;j++){
//                 f[i][j] = j;
//             }
//             return;
//         }

//         if(i == L[i]){
//             int r = query(i+1, R[i]);
//             self(self, r);
//             for(int j = 1;j <= m;j++){
//                 f[i][j] = (f[i][j-1] + f[r][j]) % mod;
//             }
//         }else if(i == R[i]){
//             int l = query(L[i], i-1);
//             self(self, l);
//             for(int j = 1;j <= m;j++){
//                 f[i][j] = (f[i][j-1] + f[l][j-1]) % mod;
//             }
//         }else{
//             int r = query(i+1, R[i]);
//             int l = query(L[i], i-1);
//             self(self, l);
//             self(self, r);
//             for(int j = 1;j <= m;j++){
//                 f[i][j] = (f[i][j-1] + (f[l][j-1] * f[r][j] % mod)) % mod;
//             }
//         }
//     };

//     dfs(dfs, query(1, n));

//     cout << f[query(1, n)][m] << endl;

// }   

// signed main(){

//     IO;

//     for(int i = 2;i < N;i++){
//         Log[i] = Log[i/2] + 1;
//     }

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
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, m, Log[N], mx[N][20];

// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int ans = 0;
//     for(int j = 0;j <= 10;j++){
//         int s = 0;
//         for(int i = 1;i <= n;i++){
//             s += (a[i] >> j) & 1;
//         }
//         if(s && s != n) ans += (1 << j);
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
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k;

// void solve(){
//     cin >> n >> k;
//     vector<int>h(n+5);
//     vector<int>p(n+5);
//     map<int,int>mp;
//     for(int i = 1;i <= n;i++) cin >> h[i];
//     for(int i = 1;i <= n;i++){
//         cin >> p[i];
//         mp[p[i]] = max(mp[p[i]], h[i]);
//     }

//     int sum = 0, f = 0;
//     for(auto [p, h] : mp){
//         if(sum >= h) continue;
//         if(f){
//             k -= p;
//             f = 0;
//         }
//         if(k <= 0) {
//             cout << "NO\n";
//             return;
//         }
//         while(1){
//             sum += k;   
//             if(sum >= h){
//                 f = 1;
//                 break;
//             }
//             k -= p;
//             if(k <= 0) {
//                 cout << "NO\n";
//                 return;
//             }
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k;

// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     int mx = 0;
//     for(int i = 1;i <= n;i++) cin >> a[i], mx = max(mx, a[i]);
//     if(n > 3){
//         cout << mx * n << endl;
//     }else if(n == 3){
//         if(mx == a[1] || mx == a[3]){
//             cout << mx * n << endl;
//         }else{
//             sort(a.begin() + 1, a.begin() + 1 + n);
//             swap(a[2], a[3]);
//             int ans = a[1] + a[2] + a[3];
//             ans = max(ans, a[3] * 3);
//             a[1] = a[2] = a[2] - a[1];
//             ans = max(ans, a[1] * 3);
//             ans = max(ans, a[1] + a[2] + a[3]);
//             a[3] = a[2] = abs(a[2] - a[3]);
//             ans = max(ans, a[1] + a[2] + a[3]);
//             cout << ans << endl;
//         }
//     }else{
//         cout << max(a[1] + a[2], 2*abs(a[1]-a[2])) << endl;
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
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k;

// void solve(){
//     cin >> n;
//     int a = 0, b = 0;
//     while(n--){
//         int x, y;
//         cin >> x >> y;
//         a += x;
//         b += y;
//     }
//     if(a > b){
//         cout << "Takahashi\n";
//     }else if(a == b){
//         cout << "Draw\n";
//     }else {
//         cout << "Aoki\n";
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
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k;

// void solve(){
//     string s, s2;
//     cin >> s;
//     // n = s.size();
//     // s = s + 'e';
//     // for(int i = 0;i < n;i++){
//     //     if(s[i] != s[i+1]) s2.push_back(s[i]);
//     // }
//     // if(s2.size() > 3){
//     //     cout << "No\n";
//     // }else{
//     //     if(is_sorted(s2.begin(), s2,end())) cout << "Yes\n";
//     //     else 
//     // }
//     cout << (is_sorted(s.begin(), s.end()) ? "Yes\n" : "No\n");
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
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k;

// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     vector<int>ne(n+5);
//     int h;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] == -1) h = i;
//         else ne[a[i]] = i;
//     }
    
//     for(int i = 1;i <= n;i++, h = ne[h]){
//         cout << h << ' ';
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
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m;

// void solve(){
//     cin >> n >> m >> k;
//     vector<string>mp(n+5);
//     vector<vector<int>>pre(n+5, vector<int>(m+5));
//     vector<vector<int>>lm(n+5, vector<int>(m+5));
//     for(int i = 1;i <= n;i++){
//         cin >> mp[i];
//         mp[i] = 'x' + mp[i] + 'x';
//         for(int j = 1;j <= m;j++){
//             pre[i][j] += pre[i][j-1];
//             if(mp[i][j] == 'o') pre[i][j]++;
//         }
//         for(int j = m+1;j >= 1;j--){
//             if(mp[i][j] == 'x') lm[i][j] = j;
//             else lm[i][j] = lm[i][j+1];
//         }
//     }

//     int ans = max(n, m) + 1;
    

//     for(int i = 1;i <= n;i++){
//         for(int j = 1, r = k;r <= m;++j, r = j+k-1){
//             if(lm[i][j] <= r){
//                 j = lm[i][j];
//                 continue;
//             }
//             ans = min(ans, k - (pre[i][r] - pre[i][j-1]));
//         }
//     }

//     vector<string>mp2(m+5);
//     vector<vector<int>>pre2(m+5, vector<int>(n+5));
//     vector<vector<int>>lm2(m+5, vector<int>(n+5));
//     for(int i = 1;i <= m;i++){
//         for(int j = 1;j <= n;j++){
//             mp2[i].push_back(mp[j][i]);
//         }
//         mp2[i] = 'x' + mp2[i] + 'x';
//         // cerr << mp2[i] << endl;
//         for(int j = 1;j <= n;j++){
//             pre2[i][j] += pre2[i][j-1];
//             if(mp2[i][j] == 'o') pre2[i][j]++;
//         }
//         for(int j = n+1;j >= 1;j--){
//             if(mp2[i][j] == 'x') lm2[i][j] = j;
//             else lm2[i][j] = lm2[i][j+1];
//             // cerr << i << ' ' << j << ' ' << lm2[i][j] << endl;
//         }
//     }
//     swap(n, m);
//     for(int i = 1;i <= n;i++){
//         for(int j = 1, r = k;r <= m;++j, r = j+k-1){
//             if(lm2[i][j] <= r){
//                 j = lm2[i][j];
//                 continue;
//             }
//             ans = min(ans, k - (pre2[i][r] - pre2[i][j-1]));
//         }
//     }

//     cout << (ans == max(n,m)+1 ? -1 : ans) << endl;
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
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m;

// void solve(){
//     cin >> n;
//     map<int,vector<int>>mp;
//     for(int i = 0;i < n;i++){
//         for(int j = 0;(1 << j) <= i;j++) if((i >> j) & 1){
//             mp[n-j].push_back(i+1);
//         }   
//     }
//     cout << mp.size() << endl;
//     for(auto [k,v] : mp){
//         cout << v.size() << ' ';
//         for(auto e : v) cout << e << ' ';
//         cout << endl;
//     }
//     string s;
//     cin >> s;
//     reverse(s.begin(), s.end());
//     int ans = 0;
//     for(int i = 0;i < s.size();i++){
//         ans += (1<<i) * (s[i] - '0');
//     }
//     cout << ans + 1 << endl;
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
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m;

// void solve(){
//     cin >> n;
//     int sum = 0;
//     while(n--){
//         int a;
//         cin >> a;
//         sum += a;
//     }
//     sum = abs(sum);
//     cout << sum << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m;

// void solve(){
//     cin >> n;
//     cout << (n + 1) / 2 << endl;
//     int q = 1, p = 3 * n;
//     while(q < p){
//         cout << q << ' ' << p << endl;
//         q += 3;
//         p -= 3;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m;

// void solve(){
//     cin >> n;
//     int a1, mn = inf;
//     cin >> a1;
//     for(int i = 1;i < n;i++) {
//         int t;
//         cin >> t;
//         mn = min(mn, t);
//     }
//     if(a1-1 >= mn) cout << "Alice\n";
//     else cout << "Bob\n";
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m;

// void solve(){
//     cin >> n >> m;
//     vector<int>a(n+5);
//     vector<int>pre(n+5);
//     vector<int>xp(n+5);
//     map<int,vector<int>>mp[2];
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         pre[i] = pre[i-1] + a[i];
//         xp[i] = a[i] ^ xp[i-1];
//         mp[i&1][xp[i]].push_back(i);
//     }
//     while(m--){
//         int l, r;
//         cin >> l >> r;
//         if(pre[r] - pre[l-1] == 0){
//             cout << "0\n";
//             continue;
//         }
//         if(xp[r] ^ xp[l-1]){
//             cout << "-1\n";
//         }else{
//             if(((r - l + 1) & 1) || a[l] == 0 || a[r] == 0){
//                 // cerr << l << ' ' << r << ' ' << a[l] << ' ' << a[r] << endl;
//                 cout << "1\n";
//             }else{
//                 int x = xp[l-1];
//                 auto p = upper_bound(all(mp[l&1][x]), l);
//                 if(p == mp[l&1][x].end() || *p > r){
//                     cout << "-1\n";
//                 } else {
//                     cout << "2\n";
//                 }
//             }
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
// #define endl '\n'
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m;

// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     int gc = a[1];
//     for(int i = 1;i <= n;i++) gc = gcd(gc, a[i]);
//     if(gc == 1){
//         cout << "0\n";
//         return;
//     }
//     int ans;
//     for(int i = n;i >= 1;i--){
//         int g = (i == 1 ? 1 : a[1]);
//         for(int j = 1;j <= n;j++){
//             g = gcd(i == j ? gcd(i, a[i]) : a[j], g);
//         }
//         if(g == 1){
//             ans = n - i + 1;
//             break;
//         }
//     }
//     if(n >= 2) ans = min(ans, 3ll);
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
// #define endl '\n'
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m;

// void solve(){
//     cin >> n;
//     string s;
//     char c, ls = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> c;
//         if(c == ls) continue;
//         s.push_back(c);
//         ls = c;
//     }   
//     int p = n, ans = 0; 
//     for(int i = 0;i < s.size();i++){
//         if(s[i] == '1'){
//             p = i + 1;
//             break;
//         }
//     }
//     ans = s.size() - p;
//     cout << max(0ll, ans) << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m;

// void solve(){
//     cin >> n >> k;
//     vector<int>a(n+5);
//     int x = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         x ^= a[i];
//     }
//     int s = x;
//     int l, r;
//     cin >> l >> r;
//     int L = l, R = r;
//     while(l < r && ((x ^ a[l]) == x - a[l])){
//         x -= a[l];
//         l++;
//     }
//     while(l < r && ((x ^ a[r]) == x - a[r])){
//         x -= a[r];
//         r--;
//     }
//     swap(l, L);
//     swap(r, R);
//     x = s;
//     while(l < r && ((x ^ a[r]) == x - a[r])){
//         x -= a[r];
//         r--;
//     }
//     while(l < r && ((x ^ a[l]) == x - a[l])){
//         x -= a[l];
//         l++;
//     }

//     if(r-l+1 < R-L+1) cout << l << ' ' << r << endl;
//     else cout << L << ' ' << R << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m;

// void solve(){
//     cin >> n;
//     set<int>st;
//     map<int,int>pos;
//     st.insert(0);
//     while(n--){
//         char op;
//         int x;
//         cin >> op >> x;
//         if(op == '+'){
//             st.insert(x);
//         }else{
//             while(st.count(pos[x])){
//                 pos[x] += x;
//             }
//             cout << pos[x] << endl;
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
// #define endl '\n'
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m, q;

// void solve(){
//     cin >> n >> q;
//     vector<int>a(n+5);
//     vector<int>pre(n+5);
//     vector<int>xp(n+5);
//     vector<int>p;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i]) p.push_back(i);
//         pre[i] = pre[i-1] + a[i];
//         xp[i] = xp[i-1] ^ a[i];
//     }

//     auto val = [&](int L, int R) -> int {
//         return (pre[R] - pre[L-1]) - (xp[R] ^ xp[L-1]);
//     };

//     // for(auto e : p) cerr  << e << ' ';
//     // cerr << endl;
    
//     while(q--){
//         int L, R;
//         cin >> L >> R;
//         // cerr << L << " " << R << endl;
//         int sum = (pre[R] - pre[L-1]) - (xp[R] ^ xp[L-1]);
//         int st = lower_bound(all(p), L) - p.begin();
//         int al = L, ar = R, alen = R - L + 1;
//         for(int i = st;i < p.size() && p[i] <= R;i++){
//             int l = p[i], r = R;
//             if(val(p[i], r) != sum) continue;
//             while(l <= r){
//                 int mid = l + r >> 1;
//                 if(val(p[i], mid) >= sum) r = mid - 1;
//                 else l = mid + 1;
//             }
//             if(l - p[i] + 1 < alen){
//                 alen = l - p[i] + 1;
//                 al = p[i];
//                 ar = l;
//             }
//         }
//         cout << al << ' ' << ar << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m, q;

// void solve(){
//     cin >> n >> q;
//     vector<int>a(n+5);
//     vector<int>pre(n+5);
//     vector<int>xp(n+5);
//     vector<int>p;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i]) p.push_back(i);
//         pre[i] = pre[i-1] + a[i];
//         xp[i] = xp[i-1] ^ a[i];
//     }

//     auto val = [&](int L, int R) -> int {
//         return (pre[R] - pre[L-1]) - (xp[R] ^ xp[L-1]);
//     };

//     while(q--){
//         int L, R;
//         cin >> L >> R;
//         // cerr << L << " " << R << endl;
//         int sum = val(L, R);
//         int al = L, ar = R, alen = R - L + 1;
//         int st = lower_bound(all(p), L) - p.begin();
//         for(int i = st;i < p.size() && p[i] <= R;i++){
//             int sl = p[i];
//             if(val(sl, R) != sum) break;
//             int l = sl, r = R;
//             while(l <= r){
//                 int mid = l + r >> 1;
//                 if(val(sl, mid) >= sum) r = mid - 1;
//                 else l = mid + 1;
//             }
//             if(l - sl + 1 < alen){
//                 alen = l - sl + 1;
//                 al = sl;
//                 ar = l;
//             }
//         }
//         if(sum == 0) cout << L << ' ' << L << endl;
//         else cout << al << ' ' << ar << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, k, m, q;

// void solve(){
//     set<int>st;
//     st.insert(0);
//     map<int, int>p;
//     map<int, set<int>>er, fac;
//     cin >> q;
//     while(q--) {
//         char op;
//         int x;
//         cin >> op >> x;
//         if(op == '+'){
//             st.insert(x);
//         }else if(op == '-'){
//             st.erase(x);
//             for(auto f : fac[x]){
//                 er[f].insert(x);
//             }
//         }else{
//             if(er[x].size()){
//                 int u = *er[x].begin();
//                 while(st.count(u)){
//                     er[x].erase(u);
//                     if(er[x].empty()){
//                         u = 0;
//                         break;
//                     }
//                     u = *er[x].begin();
//                 }
//                 if(u){
//                     cout << u << endl;
//                     continue;
//                 }
//             }
//             while(st.count(p[x])){
//                 fac[p[x]].insert(x);
//                 p[x] += x;
//             }
//             cout << p[x] << endl;
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
// #define endl '\n'
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 110;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;

// int C[N][N];

// void init() {
//     for (int i = 1; i < N; i++) {
//         C[i][0] = C[i][i] = 1;
//         for (int j = 1; j < i; j++)
//             C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
//     }
//     C[0][0] = 1;
// }

// void solve(){
//     int n, i, j, x, y;
//     cin >> n >> i >> j >> x >> y;
//     if(x > y){
//         i = n - i + 1;
//         j = n - j + 1;
//         swap(i, j);
//         swap(x, y);
//     }


//     int ans = 0;

//     if(y == n){
//         ans = (C[x-1][i-1] * C[y-x-1][j-i-1]) % mod;
//         if(j == n) ans = 0;
//         cout << ans << endl;
//         return;
//     }

//     for(int p = i + 1;p < j;p++){
//         ans = (ans + ((C[x-1][i-1] * C[y-x-1][p-i-1 - (n-y-1-(j-p-1))] % mod) * C[n-y-1][j-p-1] % mod)) % mod;
//     }
//     for(int p = j + 1;p < n;p++){
//         ans = (ans + ((C[x-1][i-1] * C[y-x-1][j-i-1] % mod) * C[n-y-1][p-j-1] % mod)) % mod;
//     }

//     cout << ans << endl;
// }       

// signed main(){

//     IO;
//     init();
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 1e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, m, k; 

// void solve(){
//     cin >> n >> m >> k;
//     vector<string>mp(n+5);
//     vector<vector<int>>RD(n + 5, vector<int>(m+5));
//     vector<vector<int>>LD(n + 5, vector<int>(m+5));
//     vector<vector<int>>RU(n + 5, vector<int>(m+5));
//     vector<vector<int>>LU(n + 5, vector<int>(m+5));
//     vector<vector<int>>D(n + 5, vector<int>(m+5));
//     vector<vector<int>>R(n + 5, vector<int>(m+5));
//     vector<vector<int>>U(n + 5, vector<int>(m+5));
//     vector<vector<int>>L(n + 5, vector<int>(m+5));
//     mp[n+1] = mp[0] = string(m + 5, '.');
//     for(int i = 1;i <= n;i++){
//         cin >> mp[i];
//         mp[i] = '.' + mp[i] + '.';
//     }
    
//     for(int i = n;i >= 1;i--){
//         for(int j = m;j >= 1;j--){
//             RD[i][j] += (mp[i][j] == '#') + RD[i+1][j+1] - ((i+k+1<=n && j+k+1<=m) ? (mp[i+k+1][j+k+1]=='#') : 0ll);
//             R[i][j] += (mp[i][j] == '#') + R[i][j+1] - (j+k+1<=m ? (mp[i][j+k+1]=='#') : 0ll);
//             D[i][j] += (mp[i][j] == '#') + D[i+1][j] - (i+k+1<=n ? (mp[i+k+1][j]=='#') : 0ll);
//         }
//         for(int j = 1;j <= m;j++){
//             LD[i][j] += (mp[i][j] == '#') + LD[i+1][j-1] - ((i+k+1<=n && j-k-1>=1) ? (mp[i+k+1][j-k-1]=='#') : 0ll);
//         }
//     }
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             LU[i][j] += (mp[i][j] == '#') + LU[i-1][j-1] - ((i-k-1>=1 && j-k-1>=1) ? (mp[i-k-1][j-k-1]=='#') : 0ll);
//             L[i][j] += (mp[i][j] == '#') + L[i][j-1] - (j-k-1>=1 ? (mp[i][j-k-1]=='#') : 0ll);
//             U[i][j] += (mp[i][j] == '#') + U[i-1][j] - (i-k-1>=1 ? (mp[i-k-1][j]=='#') : 0ll);
//         }
//         for(int j = m;j >= 1;j--){
//             RU[i][j] += (mp[i][j] == '#') + RU[i-1][j+1] - ((i-k-1>=1 && j+k+1<=m) ? (mp[i-k-1][j+k+1]=='#') : 0ll);
//         }
//     }

//     vector<vector<int>>p1(n + 5, vector<int>(m+5));
//     vector<vector<int>>p2(n + 5, vector<int>(m+5));
//     vector<vector<int>>p3(n + 5, vector<int>(m+5));
//     vector<vector<int>>p4(n + 5, vector<int>(m+5));

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) if(mp[i][j] == '#'){
//             if(abs(i-n) + abs(j-1) <= k) p1[n][1]++;
//             if(abs(i-n) + abs(j-m) <= k) p2[n][m]++;
//             if(abs(i-1) + abs(j-m) <= k) p3[1][m]++;
//             if(abs(i-1) + abs(j-1) <= k) p4[1][1]++;
//         }
//     }

//     ans = max({ans, p1[n][1], p2[n][m], p3[1][m], p4[1][1]});
    
//     for(int i = n;i >= 1;i--){
//         ans = max(ans, p1[i][1]);
//         int J = 2;
//         if(i-k < 1){
//             J += 1-(i-k);
//         }
//         for(int j = 2;j <= m && J <= m;j++, J++){
//             p1[i][j] = p1[i][j-1] - U[i][j-1] + (j+k<=m ? LU[i][j+k] : RD[max(1ll, i-k)][J]);
//             ans = max(ans, p1[i][j]);
//         }
//         ans = max(ans, p2[i][m]);
//         J = m-1;
//         if(i-k < 1){
//             J -= 1-(i-k);
//         }
//         for(int j = m-1;j >= 1 && J >= 1;j--, J--){
//             p2[i][j] = p2[i][j+1] - U[i][j+1] + (j-k>=1 ? RU[i][j-k] : LD[max(1ll, i-k)][J]);
//             ans = max(ans, p2[i][j]);
//         }
//         p1[i-1][1] = p1[i][1] - R[i][1] + ((1+k<=m) ? LU[i-1][1+k] : RD[max(1ll, i-k-1)][min(m+1, 1+((i-k-1) < 1 ? 1-(i-k-1) : 0ll))]);
//         p2[i-1][m] = p2[i][m] - L[i][m] + ((m-k>=1) ? RU[i-1][m-k] : LD[max(1ll, i-k-1)][max(0ll, m-((i-k-1) < 1 ? 1-(i-k-1) : 0ll))]);
//     }
//     for(int i = 1;i <= n;i++){
//         ans = max(ans, p4[i][1]);
//         int J = 2;
//         if(i+k > n){
//             J += i+k-n;
//         }
//         for(int j = 2;j <= m && J <= m;j++, J++){
//             p4[i][j] = p4[i][j-1] - D[i][j-1] + (j+k<=m ? LD[i][j+k] : RU[min(n, i+k)][J]);
//             ans = max(ans, p4[i][j]);
//         }
//         ans = max(ans, p3[i][m]);
//         J = m-1;
//         if(i+k > n){
//             J -= i+k-n;
//         }
//         for(int j = m-1;j >= 1 && J >= 1;j--, J--){
//             p3[i][j] = p3[i][j+1] - D[i][j+1] + (j-k>=1 ? RD[i][j-k] : LU[min(n, i+k)][J]);
//             ans = max(ans, p3[i][j]);
//         }
//         p4[i+1][1] = p4[i][1] - R[i][1] + ((1+k<=m) ? LD[i+1][1+k] : RU[min(n, i+k+1)][min(m+1, 1+((i+k+1) > n ? (i+k+1)-n : 0ll))]);
//         p3[i+1][m] = p3[i][m] - L[i][m] + ((m-k>=1) ? RD[i+1][m-k] : LU[min(n, i+k+1)][max(1ll, m-((i+k+1) > n ? (i+k+1)-n : 0ll))]);
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
// #define endl '\n'
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 1e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, m, k; 

// void solve(){
//     cin >> n >> m >> k;
//     vector<string>mp(n + 5);

//     for(int i = 1;i <= n;i++){
//         cin >> mp[i];
//         mp[i] = ' ' + mp[i];
//     }

//     auto calc = [&]() -> int {
//         vector<vector<int>>D(n+5, vector<int>(m+5));
//         vector<vector<int>>R(n+5, vector<int>(m+5));
//         vector<vector<int>>LD(n+5, vector<int>(m+5));

//         for(int i = n;i >= 1;i--){
//             for(int j = m;j >= 1;j--){
//                 R[i][j] = (mp[i][j] == '#') + R[i][j+1] - (j+k+1 <= m ? (mp[i][j+k+1] == '#') : 0ll);
//                 D[i][j] = (mp[i][j] == '#') + D[i+1][j] - (i+k+1 <= n ? (mp[i+k+1][j] == '#') : 0ll);
//             }
//             for(int j = 1;j <= m;j++){
//                 LD[i][j] = (mp[i][j] == '#') + LD[i+1][j-1];
//             }
//         }

//         vector<int>p(n+5);
        
//         for(int i = 1;i <= n;i++){
//             for(int j = 1;j <= m;j++) if(mp[i][j] == '#'){
//                 if(i-1 + j-1 <= k) p[1]++;
//             }
//         }

//         int res = p[1];

//         for(int i = 1;i <= n;i++){
//             res = max(res, p[i]);
//             p[i+1] = p[i] - R[i][1] + (1+k<=m ? LD[i+1][1+k] : LD[min(n+1,i+1+(1+k)-m)][m]);
//             for(int j = 2;j <= m;j++){
//                 p[i] = p[i] - D[i][j-1] + (j+k<=m ? LD[i][j+k] : LD[min(n+1,i+(j+k)-m)][m]) - (i+k+1<=n ? LD[i+k+1][j-1] : 0ll);
//                 res = max(res, p[i]);
//             }
//         }

//         return res;
//     };

//     auto print = [&]() -> void {
//         for(int i = 1;i <= n;i++){
//             for(int j = 1;j <= m;j++){
//                 cerr << mp[i][j];
//             }
//             cerr << endl;
//         }
//         cerr << "\n____________________\n";
//     };

//     int ans = calc();

//     for(int i = 1;i <= n;i++){
//         reverse(mp[i].begin()+1, mp[i].end());
//     }
//     ans = max(ans, calc());
//     reverse(mp.begin() + 1, mp.begin() + 1 + n);
//     ans = max(ans, calc());
//     for(int i = 1;i <= n;i++){
//         reverse(mp[i].begin()+1, mp[i].end());
//     }
//     ans = max(ans, calc());

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
// #define endl '\n'
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 1e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, m, k; 

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++){
//         for(int j = 'a';j < 'a' + k;j++) cout << (char)j;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 1e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, m, x; 

// void solve(){
//     cin >> x >> n;
//     int ans = 1;
//     for(int i = 1;i*i <= x;i++){
//         if(x % i == 0){
//             if(i*n <= x) ans = max(ans, i);
//             if((x % (x/i)) == 0){
//                 if(n*(x/i) <= x) ans = max(ans, x/i);
//             }
//         }
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
// #define endl '\n'
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 1e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, m, k; 

// void solve(){
//     cin >> n >> k >> m;
//     string s, ans;
//     cin >> s;

//     int cnt = 0;
//     map<char, int>st;
//     for(auto c : s){
//         st[c]++;
//         if(st.size() == k){
//             cnt++;
//             ans.push_back(c);
//             st.clear();
//         }
//     }    
//     if(cnt >= n){
//         cout << "YES\n";
//     }else{
//         cout << "NO\n";
//         for(int i = 'a';i < 'a' + k;i++){
//             if(st[(char)i] == 0){
//                 ans.push_back((char)i);
//                 break;
//             }
//         }
//         while(ans.size() < n) ans.push_back('a');
//         cout << ans << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, m, k, nn1, nnv; 

// int qpow(int a, int b){
//     int ret = 1;
//     while(b){
//         if(b & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return ret;
// }

// int add(int a, int b){
//     return (a+b) % mod;
// }
// int mul(int a, int b){
//     return a*b % mod;
// }
// int chu(int a, int b){
//     return mul(a, qpow(b, mod-2));
// }

// void solve(){
//     cin >> n >> m >> k;
//     nn1 = chu(mul(n, n-1), 2);
//     nnv = qpow(nn1, mod-2);
//     int sum = 0;
//     for(int i = 1, a, b, v;i <= m;i++){
//         cin >> a >> b >> v;
//         sum = add(sum, v);
//     }

//     int av = chu(sum, m);

//     vector<int>f(k+5);

//     int p = mul(1, nnv);
//     int s = p;
//     int ss = s;

//     for(int i = 2;i <= k;i++){
//         // f[i] = add(f[i-1], add(mul( mul(m,nnv) , av ), mul(m, s)) );
//         // f[i] = add(f[i-1], mul( mul(m,nnv) , add(av, mul(m, s) ) ) );
//         f[i] = add(f[i-1], mul(m, mul(s, nnv)));
//         p = mul(p, chu(nn1-1, nn1) );
//         ss = add(ss, p);
//         s = add(s, ss);
//     }

//     // for(int i = 1;i <= k;i++){
//     //     cerr << f[i] << endl;
//     // }

//     f[k] = add(f[k], mul(mul(k, sum), nnv));

//     cout << f[k]%mod << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, m, k, nn1, nnv; 


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
//     inv[N-1] = qpow(fac[N-1], mod-2);
//     for(int i = N-2;i >= 1;i--){
//         inv[i] = inv[i+1] * (i+1) % mod;
//     }
// }

// int add(int a, int b){
//     return (a+b) % mod;
// }
// int mul(int a, int b){
//     return a*b % mod;
// }
// int chu(int a, int b){
//     return mul(a, qpow(b, mod-2));
// }
// int C(int a, int b){
//     return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
// }


// void solve(){
//     cin >> n >> m >> k;
//     nn1 = C(n, 2);
//     nnv = qpow(nn1, mod-2);
//     int sum = 0;
//     for(int i = 1, a, b, v;i <= m;i++){
//         cin >> a >> b >> v;
//         sum = add(sum, v);
//     }

//     int ans = mul(mul(k, sum), nnv);
//     for(int i = 2;i <= k;i++){
//         int tmp = mul(C(k, i), mul(qpow(mul(1,nnv), i), qpow(mul(nn1-1,nnv), k-i)));
//         tmp = mul(tmp, chu(mul(i,i-1),2));
//         ans = add(ans, mul(m, tmp));
//     }

//     cout << ans << endl;
// }       

// signed main(){

//     IO;
//     get_inv();
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }