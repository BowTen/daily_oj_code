// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 105;
// int n, m;

// int pre[N], suf[N], vis[N];
// vector<int>g[N];

// void init(){
//     for(int i = 0;i <= n;i++) {
//         g[i].clear();
//         pre[i] = suf[i] = vis[i] = 0;
//     }
// }

// bool bfs(int x){
//     vis[x] = x;
//     queue<int>que;
//     que.push(x);
//     while(que.size()){
//         int u = que.front();
//         que.pop();
//         for(auto v : g[u]){
//             if(v == x) return false;
//             if(vis[v] == x) continue;
//             que.push(v);
//             vis[v] = x;
//             suf[x]++;
//             pre[v]++;
//         }
//     }
//     return true;
// }

// void solve(){
//     cin >> n >> m;
//     init();

//     bool f = false;
//     for(int i = 1;i <= m;i++){
//         int u, v;

//         cin >> u >> v;
//         g[u].push_back(v);
//         if(u == v) f = true;
//     }

//     if(f){
//         while(n--) cout << 0;
//         cout << '\n';
//         return;
//     }

//     for(int i = 1;i <= n;i++){
//         if(!bfs(i)){
//             while(n--) cout << 0;
//             cout << '\n';
//             return;
//         }
//     }

//     int n2 = n / 2;
//     for(int i = 1;i <= n;i++){
//         if(suf[i] <= n2 && pre[i] <= n2) cout << 1;
//         else cout << 0;
//     }
//     cout << '\n';
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 105;
// int n, m;

// int pre[N], suf[N], vis[N];
// vector<int>g[N];

// void init(){
//     for(int i = 0;i <= n;i++) {
//         g[i].clear();
//         pre[i] = suf[i] = vis[i] = 0;
//     }
// }

// bool bfs(int x){
//     vis[x] = x;
//     queue<int>que;
//     que.push(x);
//     while(que.size()){
//         int u = que.front();
//         que.pop();
//         for(auto v : g[u]){
//             if(v == x) return false;
//             if(vis[v] == x) continue;
//             que.push(v);
//             vis[v] = x;
//             suf[x]++;
//             pre[v]++;
//         }
//     }
//     return true;
// }

// void solve(){
//     cin >> n >> m;
//     init();

//     bool f = false;
//     for(int i = 1;i <= m;i++){
//         int u, v;

//         cin >> u >> v;
//         g[u].push_back(v);
//         if(u == v) f = true;
//     }

//     if(f){
//         while(n--) cout << 0;
//         cout << '\n';
//         return;
//     }

//     for(int i = 1;i <= n;i++){
//         if(!bfs(i)){
//             while(n--) cout << 0;
//             cout << '\n';
//             return;
//         }
//     }

//     int n2 = n / 2;
//     for(int i = 1;i <= n;i++){
//         if(suf[i] <= n2 && pre[i] <= n2) cout << 1;
//         else cout << 0;
//     }
//     cout << '\n';
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e6 + 10;
// int n, m, a[N];

// int tr[N];
// int lowbit(int x){
//     return x & -x;
// }

// void add(int x, int v){
//     while(x <= n){
//         tr[x] += v;
//         x += lowbit(x);
//     }
// }

// int getsum(int x){
//     int ret = 0;
//     while(x > 0){
//         ret += tr[x];
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     for(int i = 0;i <= n + 2;i++) tr[i] = 0;
//     vector<int>pos(n + 10, 0);
//     vector<array<int, 2>>q;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++){
//         q.push_back({pos[a[i]] + 1, i - 1});
//         pos[a[i]] = i;
//     }
//     sort(q.begin(), q.end(), [](array<int,2> e1, array<int,2> e2)->int {
//         return e1[1] < e2[1];
//     });

//     int it = 1;
//     vector<int>ans(n + 10);
//     vector<int>last(n + 10);
//     for(auto [l, r] : q){
//         while(it <= r){
//             if(last[a[it]]) add(last[a[it]], -1);
//             last[a[it]] = it;
//             add(it, 1);
//             it++;
//         }
//         int mx;
//         if(l == 1) mx = n;
//         else mx = getsum(r) - getsum(l - 1);
//         ans[1]++;
//         ans[mx + 1]--;
//     }

//     for(int i = 1;i <= n;i++){
//         ans[i] += ans[i-1];
//         cout << ans[i] << "\n "[i<n];
//     }
// }

// signed main(){

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }