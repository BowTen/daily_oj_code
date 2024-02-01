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




// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define endl '\n'
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 3000 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// const int mod = 1e9 + 7;
// int n, m; 
// // int UR[N][N], R[N][N];
// // string mp[N];
// // vector<array<int, 2>>Q[N][N];

// class BIT {
//     int tr[N];
//     int lowbit(int x){
//         return x & -x;
//     }

// public:
//     void add(int x, int v){
//         if(x <= 0) return;
//         while(x < N){
//             tr[x] += v;
//             x += lowbit(x);
//         }
//     }
//     int getsum(int x){
//         int ret = 0;
//         while(x > 0){
//             ret += tr[x];
//             x -= lowbit(x);
//         }
//         return ret;
//     }
//     int query(int l, int r){
//         return getsum(r) - getsum(l-1);
//     }
//     void init(){
//         for(int i = 0;i < N;i++) tr[i] = 0;
//     }
// }tr;

// void solve(){
//     cin >> n >> m;
//     vector<string>mp(n+5);
//     mp[0] = mp[n+1] = string(m+5, '.');
//     ll ans = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> mp[i];
//         for(auto c : mp[i]) ans += (c == 'z');
//         mp[i] = '.' + mp[i] + '.';
//     }

//     vector<vector<int>>UR(n+5, vector<int>(m+5));
//     vector<vector<int>>R(n+5, vector<int>(m+5));
    
//     for(int i = 1;i <= n;i++){
//         for(int j = m;j >= 1;j--){
//             R[i][j] = mp[i][j] == 'z' ? (1 + R[i][j+1]) : 0;
//             UR[i][j] = mp[i][j] == 'z' ? (1 + UR[i-1][j+1]) : 0;
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             UR[i][j] = min(UR[i][j], R[i][j]);
//         }
//     }

//     vector<vector<vector<array<int, 2>>>>Q(n+5, vector<vector<array<int, 2>>>(m+5));
//     auto query = [&](int i, int l, int r) -> void {
//         for(int j = r - 1, h = i+1;j >= l && j >= 1 && h <= n;j--, h++){
//             Q[h][j].push_back({h-i+1, 1});
//             Q[h][l-1].push_back({h-i+1, -1});
//         }
//     };

//     for(int i = 1;i <= n;i++){
//         int l = 0, r = 0;
//         for(int j = 1;j <= m;j++){
//             if(mp[i][j] == 'z'){
//                 if(l){
//                     r++;
//                 }else{
//                     r = l = j;
//                 }
//             }else{
//                 if(r){
//                     query(i, l, r);
//                     l = r = 0;
//                 }
//             }
//         }
//         if(r){
//             query(i, l, r);
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         tr.init();
//         for(int j = 1;j <= m;j++){
//             tr.add(UR[i][j], 1);
//             for(auto [x, op] : Q[i][j]){
//                 ans += op * (tr.getsum(N-1) - tr.getsum(x-1));
//             }
//         }
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
// using ll = long long;
// #define endl '\n'
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 3000 + 10;
// const int inf = INT_MAX;
// const int mod = 1e9 + 7;
// int n, m, s, t; 


// void solve(){
//     cin >> n;
//     vector<int>a(n+5);
//     vector<int>l(n+5);
//     vector<int>r(n+5);
//     vector<int>pl(n+5);
//     vector<int>pr(n+5);
//     a[0] = a[n+1] = inf;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     stack<int>pre, suf;
//     pre.push(0);
//     for(int i = 1;i <= n;i++){
//         while(a[i] >= a[pre.top()]) pre.pop();
//         l[i] = pre.top();
//         pre.push(i);
//     }
//     suf.push(n+1);
//     for(int i = n;i >= 1;i--){
//         while(a[i] >= a[suf.top()]) suf.pop();
//         r[i] = suf.top();
//         suf.push(i);
//     }

//     int ans = 0;
//     vector<int>ok(n+5);
//     vector<int>pok(n+5);
//     for(int i = 1;i <= n;i++){
//         pok[i] += pok[i-1];
//         if(l[i] && a[i] + n-1 < min(a[l[i]], a[r[i]])) continue;
//         if(pok[i] - pok[l[i]] > 0){
//             pok[i]++;
//             ok[i] = 1;
//             ans++;
//             continue;
//         }
//         int L = l[i], R = r[i];
//         pl[L] = pr[R] = 0;
//         while(min(a[L], a[R]) <= a[i] + (R - L - 2)){
//             if(a[R] <= a[i] + (R - L - 2)) pr[r[R]] = R, R = r[R];
//             if(a[L] <= a[i] + (R - L - 2)) pl[l[L]] = L, L = l[L];
//         }
//         if(L == 0 && R == n+1){
//             ok[i] = 1, ans++;
//             pok[i]++;
//         }else{
//             int cur = L;
//             while(pl[cur]){
//                 l[pl[cur]] = L;
//                 cur = pl[cur];
//             }
//             cur = R;
//             while(pr[cur]){
//                 r[pr[cur]] = R;
//                 cur = pr[cur];
//             }
//         }
//     }

//     cout << ans << endl;
//     for(int i = 1;i <= n;i++) if(ok[i]) cout << i << ' ';
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
// using ll = long long;
// #define endl '\n'
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 3000 + 10;
// const int inf = INT_MAX;
// const int mod = 1e9 + 7;
// const int B = 1;
// const int W = 0;
// int n, m, s, t; 


// void solve(){
//     cin >> n;
//     vector<array<int, 2>>a(n+5);
//     int sum[2] = {0};
//     int s[2] = {0};
//     int k;
//     char c;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> k >> c;
//         ans += k;
//         a[i] = {k, (c == 'B')};
//         sum[c=='B'] += k;
//     }

//     if(!sum[B] || !sum[W]){
//         cout << ans << endl;
//         return;
//     }

//     ans = 0;
//     for(int i = 1;i <= n;i++){
//         int x = (a[i][1] ^ 1), c = a[i][1];
//         if(s[x]){
//             if((s[x]*sum[c])%sum[x] == 0){
//                 int tmp = (s[x]*sum[c])/sum[x];
//                 if(s[c] < tmp && s[c] + a[i][0] > tmp){
//                     int d = tmp - s[c];
//                     s[c] += d;
//                     a[i][0] -= d;
//                     i--;
//                 }else{
//                     s[c] += a[i][0];
//                 }
//             }else{
//                 s[c] += a[i][0];
//             }
//         }else{
//             s[c] += a[i][0];
//         }
//         if(s[0] && s[1] && s[0] * sum[1] == s[1] * sum[0]){
//             s[1] = s[0] = 0;
//             ans++;
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

// int main(){

//     int n, m;
//     cin >> n >> m;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     while(m--){
//         int x, l = 1, r = n;
//         cin >> x;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(x <= a[mid]) r = mid - 1;
//             else l = mid + 1;
//         }
//         if(a[l] == x) cout << l << ' ';
//         else cout << -1 << ' ';
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int n, m;
//     cin >> n >> m;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     while(m--){
//         int x, l = 1, r = n;
//         cin >> x;
//         while(l < r){
//             int mid = l + r >> 1;
//             if(a[mid] >= x) r = mid - 1;
//             else l = mid + 1;
//         }
//         if(a[l] == x) cout << l << ' ';
//         else cout << -1 << ' ';
//     }

//     return 0;
// }


// #include<bits/stdc++.h>
// #define int long long
// using namespace std;

// signed main(){

//     int L, n, m;
//     cin >> L >> n >> m;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     auto check = [&](int x) -> bool {
//         int cnt = 0, ls = 0;
//         for(int i = 1;i <= n;i++){
//             if(a[i] - ls < x){
//                 cnt++;
//             }else{
//                 ls = a[i];
//             }
//         }
//         if(L - a[n] < x && ls == a[n]){
//             cnt++;
//         }
//         return cnt <= m;
//     };
 
//     int l = 1, r = L;
//     while(l <= r){
//         int mid = l + r >> 1;
//         if(check(mid)) l = mid + 1;
//         else r = mid - 1;
//     }

//     cout << r << endl;

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define int long long

// int n;

// void solve(){
//     cin >> n;
//     vector<double>x(n+5), t(n+5);
//     for(int i = 1;i <= n;i++) cin >> x[i];
//     for(int i = 1;i <= n;i++) cin >> t[i];

//     double ans;
//     auto check = [&](double mid) -> bool {
//         double l = 0, r = 1e8;
//         for(int i = 1;i <= n;i++){
//             if(t[i] > mid) return false;
//             r = min(r, x[i] + (mid - t[i]));
//             l = max(l, x[i] - (mid - t[i]));
//         }
//         if(r >= l){
//             ans = r;
//             return true;
//         }
//         return false;
//     };

//     double l = 0, r = 3e8;
//     int cnt = 1000;
//     while(cnt--){
//         double mid = (l + r) / 2;
//         if(check(mid)) r = mid;
//         else l = mid;
//     }
//     printf("%.6lf\n", ans);
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define int long long
// int n, c;

// void solve(){
//     cin >> n >> c;
//     vector<int>x(n+5);
//     for(int i = 1;i <= n;i++) cin >> x[i];
//     sort(x.begin() + 1, x.begin() + 1 + n);

//     auto check = [&](int mid) -> bool {
//         int ls = -1e9, cnt = 0;
//         for(int i = 1;i <= n;i++){
//             if(x[i] - ls >= mid) {
//                 ls = x[i];
//                 cnt++;
//             }
//         }
//         return cnt >= c;
//     };

//     int l = 1, r = 1e9;
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
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define int long long
// int n;
// double l, r;

// void solve(){
//     cin >> n >> l >> r;
//     vector<double>a(n+1);
//     for(int i = 0;i < n+1;i++) cin >> a[i]; 

//     auto val = [&](double x) -> double {
//         double ret = 0;
//         for(int i = 0;i < n+1;i++){
//             ret += pow(x, n-i) * a[i];
//         }
//         return ret;
//     };

//     double eps = 1e-6;
//     while(r - l > eps){
//         double mid = (l + r) / 2;
//         if(val(mid-eps) < val(mid+eps)) l = mid;
//         else r = mid;
//     }

//     printf("%.5lf", l);
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define int long long
// int n;

// void solve(){
//     int l = 1, r = 1e9;
//     while(l <= r){
//         int mid = l + r >> 1;
//         cout << mid << endl;
//         int x;
//         cin >> x;
//         if(x == 0) return;
//         else if(x == 1) r = mid;
//         else l = mid + 1;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define int long long
// int n;
// double l, r;

// void solve(){
//     vector<int>a({1, 2, 2, 3, 4, 4, 4, 5, 6});

//     // lower_bound 查找容器中第一个大于等于指定元素的元素，返回其迭代器
//     cout << "第一个大于等于 2 的数为：" << *lower_bound(a.begin(), a.end(), 2) << endl;
//     cout << "第一个 2 的下标为：" << (lower_bound(a.begin(), a.end(), 2) - a.begin()) << endl;
//     cout << "第一个 4 的下标为：" << (lower_bound(a.begin(), a.end(), 4) - a.begin()) << endl;    
    
//     // upper_bound 查找容器中第一个大于指定元素的元素，返回其迭代器
//     cout << "第一个大于 2 的数为：" << *upper_bound(a.begin(), a.end(), 2) << endl;
//     cout << "最后一个 2 的下标为：" << (upper_bound(a.begin(), a.end(), 2) - a.begin() - 1) << endl;
//     cout << "最后一个 4 的下标为：" << (upper_bound(a.begin(), a.end(), 4) - a.begin() - 1) << endl;    
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<iostream>
// #include<cstring>
// #include<cstdio> 
// using namespace std;
// int n,m;
// int diff[1000011],need[1000011],rest[1000011],r[1000011],l[1000011],d[1000011];
// bool isok(int x)
// {
//     memset(diff,0,sizeof(diff));
//     for(int i=1;i<=x;i++)
//     {
//         diff[l[i]]+=d[i];
//         diff[r[i]+1]-=d[i]; 
//     }
//     for(int i=1;i<=n;i++)
//     {
//         need[i]=need[i-1]+diff[i];
//         if(need[i]>rest[i])return 0;
//     }
//     return 1;
// } 
// int main()
// {
    
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)scanf("%d",&rest[i]);
//     for(int i=1;i<=m;i++)scanf("%d%d%d",&d[i],&l[i],&r[i]);
//     int begin=1,end=m; 
//     if(isok(m)){cout<<"0";return 0;}
//     while(begin<end)
//     {
//         int mid=(begin+end)/2;
//         if(isok(mid))begin=mid+1;
//         else end=mid;
//     }
//     cout<<"-1"<<endl<<begin;
// }


// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     int n,m;
//     cin >> n >> m;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     while(m--){
//         int x;
//         cin >> x;

//         int l = 1, r = n;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(a[mid] >= x) r = mid - 1;
//             else l = mid + 1;
//         }
//         if(a[l] == x) cout << l << endl;
//         else cout << "-1\n";
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n, c;
//     cin >> n >> c;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     sort(a.begin() + 1, a.begin() + 1 + n);

//     auto check = [&](int x) -> bool {
//         int ls = -1e9, cnt = 0;
//         for(int i = 1;i <= n;i++){
//             if(a[i] - ls >= x) {
//                 ls = a[i];
//                 cnt++;
//             }
//         }
//         return cnt >= c;
//     };

//     int l = 1, r = 1e9;
//     while(l <= r){
//         int mid = l + r >> 1;
//         if(check(mid)) l = mid + 1;
//         else r = mid - 1;
//     }

//     cout << r << endl;

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int>a({1, 2, 2, 3, 4, 4, 4, 5, 6});

//     // lower_bound 查找容器中第一个大于等于指定元素的元素，返回其迭代器
//     cout << "第一个大于等于 2 的数为：" << *lower_bound(a.begin(), a.end(), 2) << endl;
//     cout << "第一个 2 的下标为：" << (lower_bound(a.begin(), a.end(), 2) - a.begin()) << endl;
//     cout << "第一个 4 的下标为：" << (lower_bound(a.begin(), a.end(), 4) - a.begin()) << endl;    
    
//     // upper_bound 查找容器中第一个大于指定元素的元素，返回其迭代器
//     cout << "第一个大于 2 的数为：" << *upper_bound(a.begin(), a.end(), 2) << endl;
//     cout << "最后一个 2 的下标为：" << (upper_bound(a.begin(), a.end(), 2) - a.begin() - 1) << endl;
//     cout << "最后一个 4 的下标为：" << (upper_bound(a.begin(), a.end(), 4) - a.begin() - 1) << endl;    

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int mod = 1e9 + 7;
// const int N = 1010;

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
// void get_inv(){
//     fac[0] = inv[0] = 1;
//     for(int i = 1;i < N;i++){
//         fac[i] = fac[i-1] * i % mod;
//     }
//     inv[N-1] = qpow(fac[N-1], mod-2);
//     for(int i = N-2;i >= 1;i--){
//         inv[i] = inv[i+1] * (i+1) % mod;
//     }
// }

// int C(int a, int b){
//     // cerr << a << ' ' << b << endl;
//     return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
// }
// int A(int a, int b){
//     return fac[a] * inv[a-b] % mod;
// }

// void solve(){
//     int n, x, p;
//     cin >> n >> x >> p;
//     int cnt[2] = {0};

//     int l = 0, r = n;
//     while(l < r){
//         int mid = l + r >> 1;
//         if(mid <= p){
//             l = mid + 1;
//             if(mid < p) cnt[0]++;
//         }
//         else r = mid, cnt[1]++;
//     }

//     int ans = (A(x-1, cnt[0]) * A(n-x, cnt[1]) % mod) * fac[n-1-cnt[0]-cnt[1]] % mod;
//     if(l-1 == p) cout << ans << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int mod = 1e9 + 7;
// const int N = 1010;


// void solve(){
//     int n, k1, k2;
//     cin >> n >> k1 >> k2;
//     if(k1 > k2) swap(k1, k2);
//     int k = k1 + k2;
//     vector<int>a(n+5), b(n+5);
//     priority_queue<int>q;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) {
//         cin >> b[i];
//         q.push(abs(a[i] - b[i]));
//     }
//     while(k > 0){
//         if(q.top() <= 0) break;
//         int x = q.top();
//         q.pop();
//         x--;
//         k--;
//         q.push(x);
//     }
//     if(k){
//         if(k <= k1 * 2){
//             k1 = k/2;
//             k2 = k-k1;
//         }else{
//             k2 -= (k1+k2-k);
//         }
//         int t = max(k1,k2) - min(k1,k2);
//         k = t;
//         while(k > 0){
//             int x = q.top();
//             q.pop();
//             x--;
//             k--;
//             q.push(x);
//         }
//     }
//     int ans = 0;
//     while(q.size()){
//         int x = q.top();
//         q.pop();
//         ans += x * x;
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
// const int mod = 1e9 + 7;
// const int N = 1010;


// void solve(){
//     int n;
//     cin >> n;
//     vector<double>x(n+5), t(n+5);
//     for(int i = 1;i <= n;i++) cin >> x[i];
//     double mn = 1e9, mx = -1e9;
//     for(int i = 1;i <= n;i++){
//         cin >> t[i];
//         mn = min(mn, x[i] - t[i]);
//         mx = max(mx, x[i] + t[i]);
//     }
//     printf("%.6lf\n", (mx + mn) / 2);
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
// const int mod = 1e9 + 7;
// const int N = 1010;


// void solve(){
//     int n, k1, k2, sum = 0;
//     cin >> n >> k1 >> k2;
//     if(k1 > k2) swap(k1, k2);
//     int k = k1 + k2;
//     vector<int>a(n+5), b(n+5);
//     priority_queue<int>q;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++){
//         cin >> b[i];
//         q.push(abs(a[i] - b[i]));        
//     }
//     while(k){
//         if(q.top() == 0) break;
//         int x = q.top();
//         q.pop();
//         x--, k--;
//         q.push(x);
//     }
//     if(k){
//         k2 -= (k1+k2-k);
//         if(k1 > k2){
//             int d = (k1 - k2) / 2;
//             k1 -= d;
//             k2 += d;
//         }
//         k = max(k1, k2) - min(k1, k2);
//         while(k){
//             int x = q.top();
//             q.pop();
//             x--, k--;
//             q.push(x);
//         }
//     }
//     int ans = 0;
//     while(q.size()){
//         ans += q.top()*q.top();
//         q.pop();
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
// typedef long long ll;
// using namespace std;

// bool check(ll x,ll n,ll P,ll lesson,ll task)
// {
//     if(x==0)
//     return false;

//     ll p = 0;
//     for(ll i=8;i<=n;i+=7)
//     {
//         if(i==8||((i-1)%7)==0&&((i-1)/7)==1)
//             {
//                 p+=2*task+lesson;
//                 x--;
//             }
//         else if(((i-1)%7)==0&&((i-1)/7)!=1)
//         {
//                 p+=task+lesson;
//                 x--;
//         }
//         if(x<0)
//         return false;
//         if(p>=P)
//         return true;
//     }
//     for(int i=1;i<=n;i++)
//     {
//       if(((i-1)%7)==0)
//         continue;
//       if(x==0)
//       return false;
//       p+=lesson;
//       x--;
//       if(p>=P)
//       return true;
//     }
//     if(p>=P&&x>=0)
//     return true;
//     else
//     return false;
// }

// // bool check(ll x,ll n,ll P,ll lesson,ll task)
// // {
// //     ll t = min(x*2, (n+6) / 7);
// //     ll s = x*lesson + t*task;
// //     return s >= P;
// // }
// int main()
// {
//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         ll n,P,lesson,task;
//         cin>>n>>P>>lesson>>task;
//         ll l = 0, r = n;
//         while(l<=r)
//         {
//             ll mid= l + r >> 1;
//             if(check(mid,n,P,lesson,task)) r = mid - 1;
//             else l = mid + 1;
//         }
//         cout<< n-l << endl;
//     }
// }


// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int n;
//     double l, r;
//     cin >> n >> l >> r;
//     vector<double>a(n+1);
//     for(auto &e : a) cin >> e;

//     auto f = [&](double x) -> double {
//         double ret = 0;
//         for(int i = 0;i < n+1;i++){
//             ret += a[i] * pow(x, n-i);
//         }
//         return ret;
//     };

//     double eps = 1e-6;
//     int cnt = 1000;
//     while(cnt--){
//         double mid = (l+r)/2;
//         if(f(mid-eps) < f(mid+eps)) l = mid;
//         else r = mid;
//     }

//     printf("%.6lf", l);

//     return 0;
// }


// #include<bits/stdc++.h> 
// #define int long long
// #define mod 200907
// #define longg 100020
// #define TT if(n==-1&&k==-1)break
// #define peace ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
// #define pp <<" "<<
// using namespace std;

// vector<int>a(longg);
// int L,n,m,l,r,k,sum=0;


// signed main()
// {
// 	int t,d,p,l,T;
// 	cin >> T;
// 	while(T--){
// 		cin >> d >> p >> l >> t;
// 		int tn = ((d-1)/7)+1;
// 		int hday = 2*t + l;
// 		int mday =   t + l;
// 		int lday =       l;
// 		// cout << tn pp hday pp mday pp lday<<endl;
// 		//all high_day
// 		if(p <= (tn/2)*hday){
// 			cout << d-(p+hday-1)/hday;
// 		}
		
		
// 		else if(tn%2==1){
// 			if(p <= ((tn/2)*hday) + mday){
// 				cout << d-tn/2-1;
// 			}
// 			else{
// 				cout << d-tn/2-1- (p-(tn/2)*hday - mday + l-1)/l;
// 			}	
// 		}
		
		
// 		else{
// 			cout << d-tn/2-(p-(tn/2)*hday + l-1)/l;
// 		}
// 		cout << endl;
// 	}
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'


// void solve(){
// 	int n, m;
// 	cin >> n >> m;
// 	int ans = (m / 2) * n;
// 	cout << ans << endl;
// }

// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n;

// void solve(){
// 	cin >> n;
// 	vector<int>a(n), b(n), id(n);
// 	for(auto &e : a) cin >> e;
// 	for(auto &e : b) cin >> e;
// 	iota(id.begin(), id.end(), 0);

// 	sort(all(id), [&](int i, int j) -> int {return a[i] < a[j];});
// 	for(int i = 1;i <= n;i++) cout << i << ' ';
// 	cout << endl;
// 	for(int i = 0;i < n;i++) cout << b[id[i]] << ' ';
// 	cout << endl;
	
// } 


// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n;

// void solve(){
// 	int a, b, r;
// 	cin >> a >> b >> r;

// 	int mx = 0;
// 	for(int i = 62;i >= 0;i--) {
// 		if(max(a,b) & (1ll<<i)){
// 			if(min(a,b) & (1ll<<i)){
// 				a -= (1ll << i);
// 				b -= (1ll << i);
// 			}else{
// 				mx = i;
// 				break;
// 			}
// 		}
// 	}

// 	if(a < b) swap(a, b);
// 	for(int i = mx-1;i >= 0;i--) if((1ll<<i) <= r){
// 		if((a&(1ll<<i)) && (!(b&(1ll<<i)))) {
// 			a -= (1ll<<i);
// 			b += (1ll<<i);
// 			r -= (1ll<<i);
// 		}
// 	}
// 	cout << a-b << endl;
// } 


// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n;

// void solve(){
// 	cin >> n;
// 	vector<int>a(n+5);
// 	for(int i = 1;i <= n;i++) cin >> a[i];

// 	auto check = [&](int x) -> bool {
// 		vector<int>f(n+5);
// 		map<int,int>mp;
//         mp[0] = 0;
//         int s = 0, l = 0;
// 		for(int i = 1;i <= n;i++){
//             s += a[i-1];
//             while(s > x){
//                 s -= a[++l];
//             }
//             while(mp.begin()->second < l) mp.erase(mp.begin());
//             f[i] = mp.begin()->first + a[i];
//             mp[f[i]] = i;
//         }
//         s = 0;
//         for(int i = n;i >= 1;i--){
//             if(f[i] <= x) return true;
//             if(a[i] + s > x){
//                 return f[i] <= x;
//             }
//             s += a[i];
//         }
//         return true;
// 	};


// 	int l = 1, r = 1e15;
// 	while(l <= r){
// 		int mid = l + r >> 1;
// 		if(check(mid)) r = mid - 1;
// 		else l = mid + 1;
// 	}
// 	cout << l << endl;
// } 


// signed main(){

// 	IO;
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// // #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n;

// void solve(){
// 	cin >> n;
// 	vector<int>a(n+5);

//     auto dfs = [&](auto self, int L, int R, vector<int>&id) -> void {
//         if(id.size() == 0) return;
//         int p = rand() % id.size();
//         char ret;
//         do{
//             cout << "? " << id[p] << endl;
//             cin >> ret;
//         }while(ret != '=');

//         vector<int>l, r;
//         for(auto e : id) if(e != id[p]){
//             cout << "? " << e << endl;
//             cin >> ret;
//             if(ret == '>'){
//                 r.push_back(e);
//             }else if(ret == '<'){
//                 l.push_back(e);
//             }
//             cout << "? " << id[p] << endl;
//             cin >> ret;
//         }

//         a[id[p]] = L + l.size();

//         self(self, L, a[id[p]]-1, l);
//         self(self, a[id[p]]+1, R, r);
//     };

//     vector<int>b(n);
//     iota(all(b), 1);
//     dfs(dfs, 1, n, b);

//     cout << "! ";
//     for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//     cout << endl;
// } 


// signed main(){

// 	IO;
//     srand(time(0));
// 	int t = 1;
// 	cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<map>
// #include<set>
// #include<fstream>
// #include<queue>
// #include<deque>
// #include<stack>
// #include<vector>
// #include<string>
// #include<iostream>
// #include<algorithm>
// #include<iterator>
// #include<cstring>
// #include<cstdio>
// #include<cmath>
// #include<cstdio>
// #include<bitset>
// using namespace std;
// int a[100001],sum[100001],yihuo[100001];
// int main()
// {
// 	int t,n,q,l,r,f;
// 	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
// 	cin >> t;
// 	while(t--){
// 		cin >> n >> q;
// 		for(int i=1;i<=n;i++){
// 			cin >> a[i];
// 		}
// 		sum[1]=a[1];
// 		yihuo[1]=a[1];
// 		for(int i=2;i<=n;i++){
// 			sum[i]=sum[i-1]+a[i];
// 			yihuo[i]=yihuo[i-1]^a[i];
// 		}
// 		while(q--){
// 			cin >> l >> r;
// 			int zyl=l,zyr=r;
// 			f=sum[r]-sum[l-1]-(yihuo[r]^yihuo[l-1]);
// 			int z=0;
// 			while(z<=33&&l<=r){
// 				if(a[l]!=0){
// 					if(f!=sum[r]-sum[l-1]-(yihuo[r]^yihuo[l-1])){
// 						break;
// 					}
// 				}
// 				int ll=l,rr=r;
// 				while(ll<=rr){
// 					int mid=(ll+rr)/2;
// 					if(f!=sum[mid]-sum[l-1]-(yihuo[mid]^yihuo[l-1])){
// 						ll=mid+1;
// 					}else{
// 						rr=mid-1;
// 					}
// 				}
// 				if(zyr-zyl>ll-l){
// 					zyr=ll;
// 					zyl=l;
// 				}
// 				l++;
// 			}
// 			cout << zyl << ' ' << zyr << '\n';
// 		}
// 	}
// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;

// void solve(){
//     int n, k1, k2;
//     cin >> n >> k1 >> k2;
//     if(k1 < k2) swap(k1, k2);
//     vector<int>a(n+5), b(n+5);
//     priority_queue<int>q;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) {
//         cin >> b[i];
//         q.push(abs(a[i] - b[i]));
//     }

//     while(k1+k2){
//         if(q.top() == 0) break;
//         int x = q.top();
//         q.pop();
//         x--;
//         k1--;
//         if(k1 < k2) swap(k1, k2);
//         q.push(x);
//     }
    
//     k1 -= k2;
//     k1 %= 2;
//     while(k1){
//         int x = q.top();
//         q.pop();
//         x--;
//         k1--;
//         q.push(x);
//     }

//     int ans = 0;
//     while(q.size()){
//         int x = q.top();
//         q.pop();
//         ans += x * x;
//     }

//     cout << ans << endl;
// } 


// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;

// void solve(){
//     int x, d;
//     cin >> x >> d;

//     vector<int>ans;
//     int p = 1;
//     for(int i = 33;i >= 0;i--) if((1ll<<i) & x){
//         int j = i;
//         ans.push_back(p);
//         p += d;
//         while(j--){
//             ans.push_back(p);
//         }
//         p += d;
//     }

//     cout << ans.size() << endl;
//     for(auto e : ans) cout << e << ' ';
//     cout << endl;
// } 


// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int op[300][2];

// void solve(){
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
    
//     unordered_map<int, unordered_map<int, pair<int,int>>>ne;

//     int X = 0, Y = 0;
//     for(auto c : s) X += op[c][0], Y += op[c][1];

//     // cerr << X << ' ' << Y << endl;

//     auto dfs = [&](auto self, int i, int x, int y, char dir) -> void {
//         // cerr << x << ' ' << y << endl;
//         if(i == n) {
//             int nx = x+op[dir][0];
//             int ny = y+op[dir][1];
//             ne[x][y] = {nx, ny};
//             return;
//         }
//         int nx = x+op[s[i]][0];
//         int ny = y+op[s[i]][1];
//         self(self, i+1, nx, ny, s[i]);
//         if(!i) return;
//         nx = x+op[dir][0];
//         ny = y+op[dir][1];
//         if(ne.count(nx) && ne[nx].count(ny)){
//             ne[x][y] = ne[nx][ny];
//         }else{
//             ne[x][y] = {nx, ny};
//         }
//     };

//     dfs(dfs, 0, 0, 0, 0);

//     // for(auto &xm : ne){
//     //     for(auto &yp : xm.second){
//     //         cerr << xm.first << ' ' << yp.first << ' ' << " ne = " << yp.second.first << ' ' << yp.second.second << endl;
//     //     }
//     // }

//     int q;
//     cin >> q;
//     while(q--){
//         int x, y, ax, ay;
//         cin >> x >> y;
//         x = -x, y = -y;

//         if(ne.count(x) && ne[x].count(y)){
//             auto p = ne[x][y];
//             x = p.first, y = p.second;
//             ax = X - x;
//             ay = Y - y;            
//         }
//         ax = X - x;
//         ay = Y - y;            

//         cout << ax << ' ' << ay << endl;
//     }
// } 


// signed main(){

// 	IO;

//     op['U'][0] = 0;
//     op['U'][1] = 1;
//     op['D'][0] = 0;
//     op['D'][1] = -1;
//     op['L'][0] = -1;
//     op['L'][1] = 0;
//     op['R'][0] = 1;
//     op['R'][1] = 0;

// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;

// void solve(){
//     int n;
//     cin >> n;
//     vector<array<int, 3>>a(n);
//     int tmp = 1;
//     for(auto &[x, y, id] : a) cin >> x >> y, id = tmp++;

//     sort(all(a));

//     vector<int>ans;
//     for(int i = 0;i < n;i++) ans.push_back(a[i][2]);
//     for(int i = n-2;i >= 0;i--) ans.push_back(a[i][2]);
//     cout << ans.size() << endl;
//     for(auto e : ans) cout << e << ' ';
// } 


// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;

// void solve(){
//     int n, sum = 0, pos;
//     cin >> n;
//     vector<int>a(n+100), pre(n+100);
//     for(int i = 0;i < n;i++){
//         cin >> a[i], pre[i] += (i-1>=0 ? pre[i-1] : 0) + a[i], sum += a[i];
//         if(a[i]) pos = i;
//     }
//     for(int i = n;i <= n+80;i++) pre[i] += pre[i-1];

//     if(sum == 1){
//         cout << max(1ll, pos) << endl;
//         return;
//     }

//     auto check = [&](int x) -> bool {
//         int a0 = pre[n+60] - pre[x-1] + a[0], s = 1;
//         for(int i = x-1;i >= 1;i--){
//             if(a[i] >= s){
//                 a0 += a[i] - s;
//             }else{
//                 s += s - a[i];
//             }
//             if(s >= 1e16) return false;
//         }
//         return a0 >= s;
//     };

//     int l = 1, r = n + 50;
//     while(l <= r){
//         int mid = l + r >> 1;
//         if(check(mid)) l = mid + 1;
//         else r = mid - 1;
//     }

//     if(check(r+50)) cerr << "DEBUG\n";

//     cout << r << endl;

// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 3e5 + 10;
// int fa[N], siz[N], n, m, ans = 0;
// vector<array<int, 2>>G[N];

// int find(int x){
//     return fa[x] == x ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     siz[b] += siz[a];
//     fa[a] = b;
// }

// int dep[N], mn[N][20], par[N][20];
// void dfs(int u, int f){
//     dep[u] = dep[f] + 1;
//     par[u][0] = f;
//     for(int i = 1;i < 20;i++){
//         par[u][i] = par[par[u][i-1]][i-1];
//         mn[u][i] = min(mn[u][i-1], mn[par[u][i-1]][i-1]);
//     }
//     for(auto [v, w] : G[u]) if(v != f){
//         mn[v][0] = w;
//         dfs(v, u);
//     }
// }
// int getmn(int u, int v){
//     if(dep[u] < dep[v]) swap(u, v);
//     int ret = mn[u][0];
//     for(int i = 19;i >= 0;i--){
//         if(dep[par[u][i]] >= dep[v]){
//             ret = min(ret, mn[u][i]);
//             u = par[u][i];
//         }
//     }
//     if(u == v) return ret;
//     for(int i = 19;i >= 0;i--){
//         if(par[u][i] != par[v][i]){
//             ret = min({ret, mn[u][i], mn[v][i]});
//             u = par[u][i];
//             v = par[v][i];
//         }
//     }
//     ret = min({ret, mn[u][0], mn[v][0]});
//     return ret;
// }

// bool check(vector<array<int, 3>> g){
//     vector<int>vis(m);
//     for(int i = 0;i < m;i++) {
//         auto [w, u, v] = g[i];
//         if(find(u) != find(v)){
//             ans += siz[fa[u]] * siz[fa[v]] * w;
//             merg(u, v);
//             vis[i] = 1;
//             G[u].push_back({v, w});
//             G[v].push_back({u, w});
//         }
//     }

//     for(int i = 1;i <= n;i++) if(find(i) == i){
//         mn[i][0] = 1e9;
//         dfs(i, 0);
//     }

//     for(int i = 0;i < g.size();i++) if(!vis[i]){
//         // cerr << g[i][1] << ' ' << g[i][2] << ' ' << g[i][0] << ' ' << getmn(g[i][1], g[i][2]) << endl;
//         if(getmn(g[i][1], g[i][2]) != g[i][0]) return false;
//     }
//     return true;
// }

// void init(){
//     for(int i = 0;i < 20;i++){
//         mn[0][i] = 1e9;
//     }
//     for(int i = 1;i <= n;i++){
//         fa[i] = i;
//         siz[i] = 1;
//     }
// }

// void solve(){
//     cin >> n >> m;
//     init();
//     vector<array<int, 3>>g(m);
//     for(int i = 0;i < m;i++){
//         cin >> g[i][1] >> g[i][2] >> g[i][0];
//     }

//     sort(all(g), greater<array<int, 3>>());

//     if(!check(g)) {
//         cout << "-1\n";
//         return ;
//     }

//     int s = 0;
//     // for(int i = 1;i <= n;i++) if(find(i) == i){
//     //     ans += siz[i] * s;
//     //     s += siz[i];
//     // }
//     for(int i = 1;i <= n;i++) if(find(i) == i){
//         s += siz[i] * (n-siz[i]);
//     }
//     ans += s/2;

//     cout << ans << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 3e5 + 10;
// int fa[N], siz[N], n, m;
// vector<array<int, 2>>G[N];

// int find(int x){
//     return fa[x] == x ? x : fa[x] = find(fa[x]);
// }
// void merg(int a, int b){
//     a = find(a);
//     b = find(b);
//     siz[b] += siz[a];
//     fa[a] = b;
// }

// int dep[N], mn[N][20], par[N][20];
// void dfs(int u, int f){
//     dep[u] = dep[f] + 1;
//     par[u][0] = f;
//     for(int i = 1;i < 20;i++){
//         par[u][i] = par[par[u][i-1]][i-1];
//         mn[u][i] = min(mn[u][i-1], mn[par[u][i-1]][i-1]);
//     }
//     for(auto [v, w] : G[u]) if(v != f){
//         mn[v][0] = w;
//         dfs(v, u);
//     }
// }
// int getmn(int u, int v){
//     int ret = 1e9;
//     if(dep[u] < dep[v]) swap(u, v);
//     for(int i = 19;i >= 0;i--){
//         if(dep[par[u][i]] >= dep[v]){
//             ret = min(ret, mn[u][i]);
//             u = par[u][i];
//         }
//     }
//     if(u == v) return ret;
//     for(int i = 19;i >= 0;i--){
//         if(par[u][i] != par[v][i]){
//             ret = min({ret, mn[u][i], mn[v][i]});
//             u = par[u][i];
//             v = par[v][i];
//         }
//     }
//     ret = min({ret, mn[u][0], mn[v][0]});
//     return ret;
// }

// bool check(vector<array<int, 3>> g){
//     vector<int>vis(m);
//     for(int i = 0;i < m;i++) {
//         auto [w, u, v] = g[i];
//         if(find(u) != find(v)){
//             // cerr << i << endl;
//             // cerr << u << ' ' << v << ' ' << w << endl;
//             merg(u, v);
//             vis[i] = 1;
//             G[u].push_back({v, w});
//             G[v].push_back({u, w});
//         }
//     }

//     for(int i = 1;i <= n;i++) if(!dep[i]){
//         // cerr << i << endl;
//         mn[i][0] = 1e9;
//         dfs(i, 0);
//     }

//     for(int i = 0;i < g.size();i++) if(!vis[i]){
//         // cerr << g[i][1] << ' ' << g[i][2] << ' ' << g[i][0] << ' ' << getmn(g[i][1], g[i][2]) << endl;
//         if(getmn(g[i][1], g[i][2]) != g[i][0]) return false;
//     }
//     return true;
// }

// void init(){
//     for(int i = 0;i < 20;i++){
//         mn[0][i] = 1e9;
//     }
//     for(int i = 1;i <= n;i++){
//         fa[i] = i;
//     }
// }

// void solve(){
//     cin >> n >> m;
//     init();
//     vector<array<int, 3>>g(m);
//     for(int i = 0;i < m;i++){
//         cin >> g[i][1] >> g[i][2] >> g[i][0];
//     }

//     sort(all(g), greater<array<int, 3>>());

//     if(!check(g)) {
//         cout << "-1\n";
//         return ;
//     }

//     for(int i = 1;i <= n;i++){
//         fa[i] = i;
//         siz[i] = 1;
//     }

//     int ans = 0;
//     for(auto [w, u, v] : g) if(find(v) != find(u)){
//         ans += siz[fa[u]] * siz[fa[v]] * w;
//         merg(u, v);
//     }

//     int s = 0;
//     for(int i = 1;i <= n;i++) if(find(i) == i){
//         s += siz[i] * (n-siz[i]);
//     }
//     ans += s/2;

//     cout << ans << endl;
// } 

// signed main(){

// 	IO;
// 	int t = 1;
// 	// cin >> t;
// 	while(t--) solve();

// 	return 0;
// }