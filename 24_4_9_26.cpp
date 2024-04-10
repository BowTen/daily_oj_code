// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'

// const int UP = 0;
// const int RI = 1;
// const int DO = 2;
// const int LE = 3;
// int op[4][2] = //U R D L
// {
//     -1, 0,
//     0, 1,
//     1, 0,
//     0, -1
// };

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<string> mp(n+5);
//     vector<int>fp[4];
//     fp[UP] = fp[DO] = vector<int>(n+5);
//     fp[LE] = fp[RI] = vector<int>(m+5);
//     for(int i = 1;i <= n;i++){
//         cin >> mp[i];
//         mp[i] = 'x' + mp[i] + 'x';
//     }
//     mp[0] = mp[n+1] = string(m+3, 'x');

//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) if(mp[i][j] == '#') {
//             fp[LE][i] = j;
//             break;
//         }
//         for(int j = m;j >= 1;j--) if(mp[i][j] == '#') {
//             fp[RI][i] = j;
//             break;
//         }
//         // cerr << fp[LE][i] << ' ' << fp[RI][i] << endl;
//     }
//     // cerr << endl;
//     for(int j = 1;j <= m;j++){
//         for(int i = 1;i <= n;i++) if(mp[i][j] == '#'){
//             fp[UP][j] = i;
//             break;
//         }
//         for(int i = n;i >= 1;i--) if(mp[i][j] == '#'){
//             fp[DO][j] = i;
//             break;
//         }
//         // cerr << fp[UP][j] << ' ' << fp[DO][j] << endl;
//     }
//     // cerr << endl;

//     queue<array<int,2>>que;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++) if(mp[i][j] == '#'){
//             que.push({i, j});
//         }
//     }

//     int sum = 0;
//     while(que.size()){
//         auto [x, y] = que.front();
//         que.pop();
//         // cerr << x << ' ' << y << endl;
//         sum++;
//         for(int i = 0;i < 4;i++){
//             int nx = x + op[i][0];
//             int ny = y + op[i][1];
//             if(mp[nx][ny] == '#' || mp[nx][ny] == 'x') continue;
//             if(op[i][0]){
//                 if(op[i][0] * (fp[i][y]-x) <= 0) continue;
//             }else{
//                 if(op[i][1] * (fp[i][x]-y) <= 0) continue;
//                 // cerr << x << ' ' << y << ' ' << nx << ' ' << ny << ' ' << i << ' ' << fp[i][x] << endl;
//             }
//             mp[nx][ny] = '#';
//             que.push({nx, ny});
//         }
//     }


//     vector<vector<int>>vis(n+5, vector<int>(m+5));
//     for(int i = 1;que.empty();i++) {
//         for(int j = 1;que.empty() && j <= m;j++) if(mp[i][j] == '#'){
//             que.push({i, j});
//             vis[i][j] = 1;
//             // cerr << i << ' ' << j << endl;
//             break;
//         }
//     }
 
//     while(que.size()){
//         auto [x, y] = que.front();
//         que.pop();
//         sum--;
//         for(int i = 0;i < 4;i++){
//             int nx = x + op[i][0];
//             int ny = y + op[i][1];
//             if(!vis[nx][ny] && mp[nx][ny] == '#'){
//                 vis[nx][ny] = 1;
//                 que.push({nx, ny});
//             }
//         }
//     }

//     auto pt = [&]() {
//         for(int i = 1;i <= n;i++){
//             for(int j = 1;j <= m;j++){
//                 cout << mp[i][j];
//             }
//             cout << endl;
//         }
//         cout << endl;
//     };

//     // pt();

//     if(sum == 0){
//         pt();
//         // cerr << "END\n";
//         return;
//     }

//     vector<array<int,2>>pos;
//     int mxy[2] = {0, 0};
//     int mny[2] = {m, m};
//     int mxx[2] = {0, 0};
//     int mnx[2] = {n, n};
//     for(int i = 1;pos.size()==0;i++) {
//         for(int j = 1;pos.size()==0 && j <= m;j++)if(mp[i][j] == '#'){
//             pos.push_back({i, j});
//         }
//     }
//     for(int i = n;pos.size()==1;i--) {
//         for(int j = 1;pos.size()==1 && j <= m;j++)if(mp[i][j] == '#'){
//             pos.push_back({i, j});
//         }
//     }

//     vis = vector<vector<int>>(n+5, vector<int>(m+5));

//     for(int i = 0;i < 2;i++){
//         que.push(pos[i]);
//         vis[pos[i][0]][pos[i][1]] = 1;
//         while(que.size()){
//             auto [x, y] = que.front();
//             // cerr << x << ' ' << y << endl;
//             mxy[i] = max(mxy[i], y);
//             mny[i] = min(mny[i], y);
//             mxx[i] = max(mxx[i], x);
//             mnx[i] = min(mnx[i], x);
//             que.pop();
//             for(int k = 0;k < 4;k++){
//                 int nx = x + op[k][0];
//                 int ny = y + op[k][1];
//                 if(!vis[nx][ny] && mp[nx][ny] == '#'){
//                     vis[nx][ny] = 1;
//                     que.push({nx, ny});
//                 }
//             }
//         }
//         // cerr << 
//         // cerr << endl;
//     }

//     if(pos[0][1] < pos[1][1]){
//         pos.push_back({mxx[0], mxy[0]});
//         pos.push_back({mnx[1], mny[1]});
//         for(int i = pos[2][0]+1;i <= pos[3][0];i++) mp[i][pos[2][1]] = '#';
//         for(int j = pos[2][1]+1;j <= pos[3][j];j++) mp[pos[3][0]][j] = '#';
//         for(int i = pos[2][0];i >= mnx[0];i--){
//             int cnt = (i==pos[2][0]);
//             for(int j = pos[2][1];mp[i][j] == '.';j--){
//                 cnt++;
//                 mp[i][j] = '#';
//             }
//             if(!cnt) break;
//         }
//         for(int i = pos[3][0];i <= mxx[1];i++){
//             int cnt = (i==pos[3][0]);
//             for(int j = pos[3][1];mp[i][j] == '.';j++){
//                 // cerr << i << ' ' << j << endl;
//                 cnt++;
//                 mp[i][j] = '#';
//             }
//             if(!cnt) break;
//         }
//         // cerr << endl;
//     }else{
//         pos.push_back({mxx[0], mny[0]});
//         pos.push_back({mnx[1], mxy[1]});
//         for(int i = pos[2][0]+1;i <= pos[3][0];i++) mp[i][pos[2][1]] = '#';
//         for(int j = pos[3][1]+1;j <= pos[2][1];j++) mp[pos[3][0]][j] = '#';
//         for(int i = pos[2][0];i >= mnx[0];i--){
//             int cnt = (i==pos[2][0]);
//             for(int j = pos[2][1];mp[i][j] == '.';j++){
//                 cnt++;
//                 mp[i][j] = '#';
//             }
//             if(!cnt) break;
//         }
//         for(int i = pos[3][0];i <= mxx[1];i++){
//             int cnt = (i==pos[3][0]);
//             for(int j = pos[3][1];mp[i][j] == '.';j--){
//                 cnt++;
//                 mp[i][j] = '#';
//             }
//             if(!cnt) break;
//         }
//     }

//     // cerr << pos[0][0] << ' ' << pos[0][1] << endl;
//     // cerr << pos[1][0] << ' ' << pos[1][1] << endl;
//     // cerr << pos[2][0] << ' ' << pos[2][1] << endl;
//     // cerr << pos[3][0] << ' ' << pos[3][1] << endl;
//     // cerr << "DEBUG\n";
//     pt();

// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--){
//         solve();
//         // cerr << t+1 << endl;
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define ls id << 1
// #define rs id << 1 | 1

// const int N = 2e5 + 10;
// int mn[N<<2], mx[N<<2];
// void up(int id){
//     mn[id] = min(mn[ls], mn[rs]);
//     mx[id] = max(mx[ls], mx[rs]);
// }
// void build(int id, int l, int r){
//     if(l == r){
//         mn[id] = N;
//         mx[id] = 0;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// void modify(int id, int l, int r, int p, int x, int y){
//     if(l == r){
//         mn[id] = min(mn[id], x);
//         mx[id] = max(mx[id], y);
//         return;
//     }
//     int mid = l + r >> 1;
//     if(p <= mid) modify(ls, l, mid, p, x, y);
//     else modify(rs, mid + 1, r, p, x, y);
//     up(id);
// }
// pair<int,int> cmp(pair<int,int>a, pair<int,int>b){
//     a.first = min(a.first, b.first);
//     a.second = max(a.second, b.second);
//     return a;
// }
// pair<int,int> query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return {mn[id], mx[id]};
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return cmp(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
// }

// void solve(){
//     int n;
//     cin >> n;
//     build(1, 1, n);
//     vector<int>a(n+5), b(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];

//     for(int i = 1;i <= n;i++) if(a[i] > b[i]){
//         modify(1, 1, n, a[i], b[i], 0);
//         modify(1, 1, n, b[i], N, a[i]);
//     }

//     vector<int>ans;

//     for(int i = 1;i <= n;i++){
//         int f = 1;
//         for(int l = 1, r = i;l <= n;l += i, r += i){
//             r = min(r, n);
//             auto [L, R] = query(1, 1, n, l, r);
//             if(L < l || R > r) {
//                 f = 0;
//                 break;
//             }
//         }
//         if(f) ans.push_back(i);
//     }

//     cout << ans.size() << endl;
//     for(auto e : ans) cout << e << ' ';
//     cout << endl;

// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--){
//         solve();
//     }

//     return 0;
// }