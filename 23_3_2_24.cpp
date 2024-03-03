// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// // #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n

// const int N = 2e6 + 10;

// int bitcount(int x){
//     int ret = 0;
//     while(x){
//         ret += (x & 1);
//         x >>= 1;
//     }
//     return ret;
// }

// void play(int x){
//     for(int i = 62;i >= 0;i--) if((x >> i) & 1){
//         cout << (1ll << i) << ' ' << (x - (1ll << i)) << endl;
//         return;
//     }
// }

// void solve(){
//     int n;
//     cin >> n;

//     if(bitcount(n) % 2 == 0){
//         cout << "first" << endl;    
//         play(n);
//     }else{
//         cout << "second" << endl;
//     }

//     int a, b;
//     while(cin >> a >> b, a || b){
//         if(bitcount(a) % 2 == 0) n = a;
//         else n = b;
//         play(n);
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int inf = 0x3f3f3f3f3f3f3f3f;

// int op[2][2] = {1, 1, 2, 0};

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>>mp(n+5, vector<int>(m+5)), vis(n+5, vector<int>(m+5));
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < m;j++){
//             cin >> mp[i][j];
//         }
//     }

//     int ans = inf;

//     queue<array<int, 3>>que;
//     que.push({0, 0, 0});
//     vis[0][0] = 1;

//     while(que.size()){
//         auto [x, y, d] = que.front();
//         que.pop();
//         if(y == m-2){
//             int rx = x - d;
//             while(rx < 0) rx += n;
//             ans = min(ans, d + min(n - rx, rx + 2));
//             break;
//         }
//         for(int i = 0;i < 2;i++){
//             int nx = (x + op[i][0] + n) % n, ny = (y + op[i][1] + m) % m;
//             if(i == 1){
//                 if(mp[(x+1)%n][y]) continue;
//             }
//             if(!vis[nx][ny] && mp[nx][ny] == 0){
//                 que.push({nx, ny, d + 1});
//                 vis[nx][ny] = 1;
//             }
//         }
//     }

//     if(ans == inf) cout << -1 << endl;
//     else cout << ans << endl;
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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int inf = 0x3f3f3f3f3f3f3f3f;

// int op[2][2] = {1, 1, 2, 0};

// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<int>>g(n+5);
//     for(int i = 2, v;i <= n;i++){
//         cin >> v;
//         g[v].push_back(i);
//     }

//     string c;
//     cin >> c;
//     c = ' ' + c;

//     vector<array<int, 2>>f(n+5); // s  p

//     auto dfs = [&](auto self, int u) -> void {
//         for(auto v : g[u]) {
//             self(self, v);
//             f[u][0] += min(f[v][0], f[v][1] + 1);
//             f[u][1] += min(f[v][0] + 1, f[v][1]);
//         }
//         if(c[u] == 'S') f[u][1] = inf;
//         else if(c[u] == 'P') f[u][0] = inf;
//     };

//     dfs(dfs, 1);

//     cout << min(f[1][0], f[1][1]) << endl;

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
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define all1(x) (x).begin() + 1, (x).begin() + 1 + n
// const int inf = 0x3f3f3f3f3f3f3f3f;

// int op[4][2] = {
//     1, 1,
//     1, -1,
//     -1, 1,
//     -1, -1
// };
// vector<vector<int>>mp(8, vector<int>(8));

// int check(int f){
//     for(int i = 2;i < 7;i++){
//         for(int j = 2;j < 7;j++) if(((i + j) % 2) == f && mp[i][j]) {
//             int fg = 1;
//             for(int k = 0;k < 4;k++){
//                 int x = i + op[k][0];
//                 int y = j + op[k][1];
//                 if(!mp[x][y]){
//                     fg = 0;
//                     break;
//                 } 
//             }
//             if(fg) return 0;
//         }
//     }
//     return 1;
// }

// void solve(){
//     string s[8];
//     for(int i = 1;i <= 7;i++){
//         cin >> s[i];
//         s[i] = ' ' + s[i];
//     }
//     for(int i = 1;i <= 7;i++){
//         for(int j = 1;j <= 7;j++){
//             mp[i][j] = (s[i][j] == 'B');
//         }
//     }

//     int ans = 0;
//     vector<array<int, 2>>id;

//     auto dfs = [&](auto self, int sum, int cur, int p, int fg) -> int {
//         int res = 0;
//         for(int i = p;i < id.size();i++){
//             mp[id[i][0]][id[i][1]] = 0;
//             if(sum == cur){
//                 res |= check(fg);
//             }else{
//                 res |= self(self, sum, cur+1, i+1, fg);
//             }
//             mp[id[i][0]][id[i][1]] = 1;
//         }
//         return res;
//     };


//     if(!check(0)){
//         for(int i = 2;i < 7;i++){
//             for(int j = 2;j < 7;j++) if((i + j) % 2 == 0 && mp[i][j]){
//                 id.push_back({i, j});
//             }
//         }
//         for(int x = 1;x <= 4;x++){
//             if(dfs(dfs, x, 1, 0, 0)) {
//                 ans += x;
//                 break;
//             }
//         }
//     }

//     if(!check(1)){
//         id.clear();
//         for(int i = 2;i < 7;i++){
//             for(int j = 2;j < 7;j++) if((i + j) % 2 == 1 && mp[i][j]){
//                 id.push_back({i, j});
//             }
//         }
//         for(int x = 1;x <= 4;x++){
//             if(dfs(dfs, x, 1, 0, 1)) {
//                 ans += x;
//                 break;
//             }
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