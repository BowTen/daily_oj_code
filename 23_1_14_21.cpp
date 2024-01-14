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



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
int n, m, q;
int num[5] = {0, 2, 4, 6, 8};

void solve(){

}

signed main(){

    IO;
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}