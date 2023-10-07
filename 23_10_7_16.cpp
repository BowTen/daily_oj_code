// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// const int N = 2e5 + 10;
// int n, M;
// vector<int>a[N];
// vector<int>st[N];

// int tr[N];
// int lowbit(int x){
//     return x & -x;
// }
// void add(int x, int v){
//     while(x < M){
//         tr[x] = max(tr[x], v);
//         x += lowbit(x);
//     }
// }
// int getmax(int x){
//     int ret = 0;    
//     while(x > 0){
//         ret = max(ret, tr[x]);
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void init(){
//     M = 0;
//     for(int i = 1;i <= n;i++) {
//         a[i].clear();
//         st[i].clear();
//         tr[i] = 0;
//     }
// }

// void solve(){
//     cin >> n;
//     init();
//     vector<int>idx;
//     idx.reserve(n + 1);
//     for(int i = 1, k;i <= n;i++){
//         cin >> k;
//         a[i].resize(k + 1);
//         st[i].reserve(k + 1);
//         for(int j = 1;j <= k;j++){
//             cin >> a[i][j];
//         }
//         for(int j = 1;j <= k;j++){
//             if(st[i].empty() || a[i][j] > st[i].back()){
//                 st[i].push_back(a[i][j]);
//                 idx.push_back(a[i][j]);
//             }
//         }
//     }
//     sort(st + 1, st + 1 + n, [](const vector<int>& v1, const vector<int>& v2){
//         return v1.back() < v2.back();
//     });
//     sort(all(idx));
//     idx.erase(unique(all(idx)), idx.end());
//     for(int i = 1;i <= n;i++){
//         for(auto &e : st[i]){
//             e = lower_bound(all(idx), e) - idx.begin() + 1;
//             M = max(M, e);
//         }
//     }
//     for(int i = 0; i <= M;i++) tr[i] = 0;

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1, len = st[i].size();j <= len;j++){
//             ans = max(ans, j + getmax(st[i][len - j] - 1));
//         }
//         add(st[i].back(), ans);
//         // cerr << st[i].back() << ' ' << ans << endl;
//     }
//     cout << ans << endl;
//     // cerr << getmax(7) << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();
//     // add(1, 1);
//     // cerr << getmax(7);

//     return 0;
// }