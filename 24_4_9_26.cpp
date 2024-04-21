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





// #include<bits/stdc++.h>
// using namespace std;
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'

// const int M = 5e6 + 10;
// const int N = 1e5 + 10;

// int primes[M], cnt;
// int euler[M];
// bool st[M];
// void get_eulers(){
//     euler[1] = 1;
//     for(int i = 2;i < M;i++) {
//         if(!st[i]){
//             primes[cnt++] = i;
//             euler[i] = i - 1;
//         }
//         for(int j = 0; primes[j] <= M/i;j++){
//             int t = primes[j] * i;
//             st[t] = true;
//             if(i % primes[j] == 0){
//                 euler[t] = euler[i] * primes[j];
//                 break;
//             }
//             euler[t] = euler[i] * (primes[j] - 1);
//         }
//     }
// }

// int a[N];

// #define ls id << 1
// #define rs id << 1 | 1
// struct node{
//     int cnt, num, len;
//     bool sm;

//     node operator+(const node& e) {
//         node ret;
//         int a = num, b = e.num, c = 0;
//         while(a != b){
//             if(a > b) a = euler[a], c += len;
//             else b = euler[b], c += e.len;
//         }
//         ret.len = len + e.len;
//         ret.cnt = cnt + e.cnt + c;
//         ret.num = a;
//         ret.sm = sm && e.sm && num == e.num;
//         return ret;
//     }

// }tr[N<<2];
// void up(int id){
//     tr[id] = tr[ls] + tr[rs];
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].cnt = 0;
//         tr[id].sm = 1;
//         tr[id].num = a[l];
//         tr[id].len = 1;
//         return;
//     }   
//     int mid = l + r >> 1;
//     build(ls, l, mid);
//     build(rs, mid + 1, r);
//     up(id);
// }
// void modify(int id, int l, int r, int ql, int qr){
//     if(tr[id].sm && tr[id].num == 1) return;
//     if(l == r){
//         tr[id].num = euler[tr[id].num];
//         return;
//     }
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls, l, mid, ql, qr);
//     else if(ql > mid) modify(rs, mid + 1, r, ql, qr);
//     else modify(ls, l, mid, ql, qr), modify(rs, mid + 1, r, ql, qr);
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
//     int n, m;
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     build(1, 1, n);
//     while(m--){
//         int op, l, r;
//         cin >> op >> l >> r;
//         if(op == 1){
//             modify(1, 1, n, l, r);
//         }else{
//             cout << query(1, 1, n, l, r).cnt << endl;
//         }
//     }
// }

// signed main(){
//     IO;

//     get_eulers();
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();
    
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int>a(n+5), s(n+5);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         s[i] = a[i];
//     }
//     sort(all1(s));

//     auto sum = [&](int p, int x) -> int {
//         return upper_bound(all1(s), p+x) - 1 - (upper_bound(all1(s), p-x-1) - 1);
//     };  

//     while(q--){
//         int p, k;
//         cin >> p >> k;
//         int l = 0, r = 2e9;
//         while(l <= r){
//             int mid = l + r >> 1;
//             if(sum(p, mid) >= k) r = mid - 1;
//             else l = mid + 1;
//         }
//         cout << l << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int>a(n+5);
//     vector<set<int>*>st(q+5);
//     set<int>st0;
//     for(int i = 1;i <= n;i++) {
//         st0.insert(i);
//     }
//     st[0] = &st0;

//     for(int i = 1;i <= q+1;i++){
//         st[i] = new set<int>;
//     }

//     while(q--){
//         int op, x;
//         cin >> op >> x;
//         if(op == 1){
//             st[a[x]]->erase(x);
            
//         }else{

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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int ans = 0;
//     int L = 0, last[3] = {0}, f = 0;
//     for(int i = 1;i <= n;i++){
//         if(a[i]) f = i;
//         if(a[i] == 1){
//             L = max(L, last[2]);
//             last[a[i]] = i;
//         }else if(a[i] == 2){
//             L = max(L, last[1]);
//             last[a[i]] = i;
//         }else if(a[i] == 3){
//             last[1] = last[2] = 0;
//         }
//         ans += f - L;
//         ans += L * 2;
//     }

//     for(int i = 1;i <= n;i++) if(a[i] == 0){
//         ans += i * (n-i+1);
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
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n

// void solve(){
//     int n, m, k;
//     cin >> n >> m >> k;
//     int cnt = (n+m-1) / m;
//     if(k >= n-cnt){
//         cout << "NO\n";
//     }else{
//         cout << "YES\n";
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     int ans = n, len = 0;
//     for(int i = 1;i <= n+1;i++){
//         if(a[i] == a[1]){
//             len++;
//         }else{
//             ans = min(ans, len);
//             len = 0;
//         }
//     }
//     if(ans == n) cout << -1 << endl;
//     else cout << ans << endl;
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
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n

// void solve(){
//     string a, b;
//     cin >> a >> b;
//     int x = 0, y = 0;
//     int n = a.size();
//     for(int i = 0;i < n;i++) if(a[i] != b[i]){
//         if(x == y) {
//             x = a[i];
//             y = b[i];
//             continue;
//         }
//         if(x < y){
//             if(a[i] < b[i]) swap(a[i], b[i]);
//         }else{
//             if(a[i] > b[i]) swap(a[i], b[i]);
//         }
//     }

//     cout << a << endl << b << endl;

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
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n

// const int N = 5005;
// const int mod = 998244353;
// int a[N], f[N];
// int n;

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     sort(a+1, a+1+n);

//     f[0] = 1;

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = N-1;j >= a[i];j--){
//             int tmp = f[j-a[i]];
//             ans = (ans + (max(a[i], (j+1)/2)*tmp%mod)) % mod;
//             f[j] = (f[j] + tmp) % mod;
//         }
//     }

//     // for(int i = 1;i <= 10;i++) cerr << f[i] << endl;

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
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n

// const int N = 2e5 + 10;
// int a[N], ad[N], dv[N];


// void solve(){
//     int n;
//     cin >> n;
//     int mx = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         mx = max(mx, a[i]);
//     }

//     int ls = 0;
//     for(int i = 1;i <= n;i++){
//         if(a[i] == a[i-1] && a[i] == a[i+1]) continue;
//         if(a[i] > ls && a[i] > a[i+1]){
//             ad[a[i]]++;
//             ls = a[i];
//         }
//         if(a[i] < ls && a[i] < a[i+1]){
//             dv[a[i]]++;
//             ls = a[i];
//         }
//         if(a[i] != a[i-1] && a[i] != a[i+1]) ls = a[i];
//     }

//     for(int i = 1;i <= 2*mx;i++){
//         ad[i] += ad[i-1];
//         dv[i] += dv[i-1];
//         // cerr << i << ' ' << ad[i] << ' ' << dv[i] << endl;
//     }

//     for(int i = 1;i <= mx;i++){
//         int ans = 0, c;
//         for(int j = 1, l = 0, r = i;r <= mx*2;j++, l += i, r += i){
//             c = ad[r] - ad[l];
//             // cerr << c << ' ';
//             ans += c*j;
//             c = dv[r] - dv[l];
//             // cerr << c << '\n';
//             ans -= c*j;
//         }
//         cout << ans << ' ';
//     }
//     cout << endl;
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
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n



// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int>a(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     while(q--){
//         int x;
//         cin >> x;
//         cout << min(x, a[1]-1) << ' ';
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n



// void solve(){
//     int n;
//     cin >> n;
//     vector<int>cnt(n+5);
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         int x;
//         cin >> x;
//         cnt[x]++;
//         if(cnt[x] == 2) ans++;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n


// void solve(){
//     int n;
//     cin >> n;
//     int s = 0;
//     for(int i = 1;i <= n;i++){
//         s += i*(i*2-1);
//     }
//     cout << s << ' ' << 2*n << endl;
    
//     for(int i = n;i >= 1;i--){
//         cout << 2 << ' ' << i << ' ';
//         for(int j = 1;j <= n;j++) cout << j << ' ';
//         cout << endl;
//         cout << 1 << ' ' << i << ' ';
//         for(int j = 1;j <= n;j++) cout << j << ' ';
//         cout << endl;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n);
//     for(int i = 0;i < n;i++) cin >> a[i];

//     int mx = 0, b = 0;
//     for(int i = 0;i < (1<<n);i++){
//         int tmp = 0, len = 0;
//         for(int j = 0;j < n;j++){
//             if((1<<j) & i){
//                 tmp += a[j];
//                 tmp += len * len;
//                 len = 0;
//             }else{
//                 len++;
//             }
//         }
//         tmp += len * len;
//         if(tmp > mx){
//             mx = tmp;
//             b = i;
//         }
//     }

//     vector<array<int,2>>op;
//     auto dfs = [&](auto self, int l, int r) -> void {
//         if(l == r) {
//             op.push_back({l, r});
//             op.push_back({l, r});
//             return;
//         }
//         for(int i = l;i < r;i++) {
//             self(self, i, r-1);
//         }
//         op.push_back({r, r});
//         op.push_back({l, r});
//     };

//     int L = 0;
//     for(int i = 0;i < n;i++) {
//         if((1<<i)&b){
//             if(L){
//                 dfs(dfs, L, i);
//                 L = 0;
//             }
//         }else{
//             if(!L) L = i+1;
//             if(!a[i]) op.push_back({i+1, i+1});
//         }
//     }
//     if(L) dfs(dfs, L, n);

//     // cerr << b << endl;

//     cout << mx << ' ' << op.size() << endl;
//     for(auto [x, y] : op) cout << x << ' ' << y << endl;
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
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n


// void solve(){
//     int n, a, b;
//     cin >> n >> a >> b;
//     int ans = 0;
//     if(a*2 > b){
//         ans = (n/2) * b + (n&1) * a;
//     }else{
//         ans = n * a;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n
// #define all(x) (x).begin(), (x).end()


// void solve(){
//     int n, c, d;
//     cin >> n >> c >> d;
//     vector<int>b(n*n);
//     for(int i = 0;i < n*n;i++) cin >> b[i];
//     sort(all(b));
//     vector<int>a;
//     for(int i = 1;i <= n;i++){
//         int a0 = b[0] + (i-1) * c;
//         for(int j = 1;j <= n;j++){
//             a.push_back(a0);
//             a0 += d;
//         }
//     }
//     sort(all(a));
//     // for(auto e : a) cerr << e << ' ';
//     // cerr << endl;
//     // for(auto e : b) cerr << e << ' ';
//     // cerr << endl;
//     // cerr << endl;
//     for(int i = 0;i < n*n;i++) if(a[i] != b[i]){
//         cout << "NO\n";
//         return;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n
// #define all(x) (x).begin(), (x).end()


// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<int>a(n+5), pre(n+5), suf(n+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) pre[i] = a[i] + pre[i-1];
//     for(int i = n;i >= 1;i--) suf[i] = a[i] + suf[i+1];

//     int p = k/2;
//     int q = k-p;

//     int i = 1, j = n;
//     while(i <= n && q >= a[i]) q -= a[i++];
//     a[i] -= q;
//     while(j >= 1 && p >= a[j]) p -= a[j--];

//     int ans = min(n, i-1 + n-j);
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n
// #define all(x) (x).begin(), (x).end()

// const int N = 1e6 + 10;
// int cnt[N], cur[N];

// void solve(){
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<int>a(n+5), b(m+5);
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= m;i++){
//         cin >> b[i];
//         cnt[b[i]]++;
//     }

//     int tmp = 0;
//     int ans = 0;

//     auto add = [&](int x) -> void {
//         cur[a[x]]++;
//         if(cur[a[x]] <= cnt[a[x]]) tmp++;
//     };
//     auto div = [&](int x) -> void {
//         cur[a[x]]--;
//         if(cur[a[x]] < cnt[a[x]]) tmp--;
//     };

//     for(int i = 1;i <= m;i++){
//         add(i);
//     }

//     for(int l = 1, r = m;r <= n;l++, r++){
//         ans += tmp >= k;
//         add(r+1);
//         div(l);
//     }

//     for(auto e : a) cnt[e] = cur[e] = 0;
//     for(auto e : b) cnt[e] = cur[e] = 0;

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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n
// #define all(x) (x).begin(), (x).end()


// void solve(){
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
//     s = ' ' + s;
//     for(int i = n;i > 1;i--){
//         vector<int>f(n+5);
//         int x = 0, ok = 1;
//         for(int j = 1;j <= n;j++){
//             x ^= f[j];
//             if((x ^ (s[j]-'0')) == 0){
//                 x ^= 1;
//                 if(j+i-1 <= n) f[j+i] ^= 1;
//                 else{
//                     ok = 0;
//                     break;
//                 }
//             }
//         }
//         if(ok){
//             cout << i << endl;
//             return;
//         }
//     }
//     cout << 1 << endl;
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
// #define endl '\n'
// #define all1(x) (x).begin()+1, (x).begin() + 1 + n
// #define all(x) (x).begin(), (x).end()


// void solve(){
//     int a, b, c, d;
//     cin >> a >> b >> c >> d;
//     if(a > b) swap(a, b);

//     int ans = d / 2;
//     int t1 = 0, t2 = 0;
    
//     if(a && c && b){
//         t1 += (b+1)/2;
//         t1 += (a-1)/2;
//         t1 += (c-1)/2;
//     }

//     t2 += c/2;
//     t2 += a/2;
//     t2 += b/2;

//     ans += max(t1,t2);
//     cout << ans << endl;
//     // cerr << t1 << ' ' << t2 << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// #define int long long
// using namespace std;

// int n;
// struct node{
//     int x, y;
// };
// // using iter = vector<int>::iterator;
// using Iter = vector<node>::iterator;

// bool cmpx(const node a,const node b){return a.x<b.x;}
// bool cmpy(const node a,const node b){return a.y<b.y;}
// double dis(const node a,const node b){
//     return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
// }
// void min_dis(const Iter l,const Iter r,double &d){
//     if(r-l<=1) return;
//     vector<node> Q; Iter t=l+(r-l)/2;double w=t->x;
//     min_dis(l,t,d),min_dis(t,r,d),inplace_merge(l,t,r,cmpy);
//     for(Iter x=l;x!=r;++x)
//         if(abs(w-x->x)<=d) Q.push_back(*x);
//     for(Iter x=Q.begin(),y=x;x!=Q.end();++x){
//         while(y!=Q.end()&&y->y<=x->y+d) ++y;
//         for(Iter z=x+1;z!=y;++z) d=min(d,dis(*x,*z));
//     }
// }

// void solve(){
//     cin >> n;
//     vector<node>a;
//     for(int i = 1, x, y;i <= n;i++){
//         // cin >> a[i].x >> a[i].y;
//         cin >> x >> y;
//         a.push_back({x, y});
//     }
//     // vector<int>id(n);
//     // iota(id.begin(), id.end(), 1);
//     // sort(id.begin(), id.end(), [&](int i, int j) -> int {
//     //     return a[i].x < a[j].x;
//     // });

//     // auto dis = [&](int i, int j) -> double {
//     //     int dx = a[i].x - a[j].x;
//     //     int dy = a[i].y - a[j].y;
//     //     return sqrt(pow(dx, 2) + pow(dy, 2));
//     // };
//     // auto cmpy = [&](int i, int j) -> int {
//     //     return a[i].y < a[j].y;
//     // };

//     // auto min_dis = [&](auto self, iter l, iter r, double &d) -> void {
//     //     if(r-l <= 1) return;
//     //     iter mid = l + (r-l)/2;
//     //     self(self, l, mid, d), self(self, mid, r, d);
//     //     inplace_merge(l, mid, r, cmpy);
//     //     vector<int>P;
//     //     for(iter i = l;i != r;i++) if(abs(a[*i].x - a[*mid].x) <= d) P.push_back(*i);
//     //     for(iter i = P.begin(), j = P.begin();i != P.end();i++){
//     //         while(j != P.end() && a[*j].y <= a[*i].y+d) j++;
//     //         for(iter k = i+1;k != j;k++) d = min(d, dis(*i, *k));
//     //     }
//     // };

//     // auto min_dis = [&](auto self, const Iter l,const Iter r,double &d) -> void {
//     //     if(r-l<=1) return;
//     //     vector<node> Q; Iter t=l+(r-l)/2;double w=t->x;
//     //     self(self,l,t,d),self(self,t,r,d),inplace_merge(l,t,r,cmpy);
//     //     for(Iter x=l;x!=r;++x)
//     //         if(abs(w-x->x)<=d) Q.push_back(*x);
//     //     for(Iter x=Q.begin(),y=x;x!=Q.end();++x){
//     //         while(y!=Q.end()&&y->y<=x->y+d) ++y;
//     //         for(Iter z=x+1;z!=y;++z) d=min(d,dis(*x,*z));
//     //     }
//     // };

//     sort(a.begin(), a.end(), cmpx);
//     double d = 1e18;
//     // min_dis(min_dis, id.begin(), id.end(), d);
//     min_dis(a.begin(), a.end(), d);
//     printf("%.0lf", d*d);
//     // int ans = d * d;
//     // cout << ans << endl;
// }

// signed main(){

//     solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// #define int long long
// using namespace std;

// struct node{
//     int x, y;
// };
// vector<node>a;

// double dis(const node &e1, const node &e2){
//     return sqrt(pow(e1.x-e2.x,2)+pow(e1.y-e2.y,2));
// }
// int cmpx(const node &e1, const node &e2){
//     return e1.x < e2.x;
// }
// int cmpy(const node &e1, const node &e2){
//     return e1.y < e2.y;
// }

// double min_dis(int l, int r){
//     if(r-l <= 1) return 1e20;
//     int mid = l + (r-l)/2;
//     double w = a[mid].x;
//     double d = min(min_dis(l, mid), min_dis(mid, r));
//     inplace_merge(a.begin()+l, a.begin()+mid, a.begin()+r, cmpy);
//     vector<node>P;
//     for(int i = l;i < r;i++) if(abs(a[i].x-w) <= d) P.push_back(a[i]);
//     for(int i = 0, j = 0;i < P.size();i++){
//         while(j < P.size() && P[j].y <= P[i].y+d) j++;
//         for(int k = i+1;k < j;k++) d = min(d, dis(P[k], P[i]));
//     }
//     return d;
// }

// void solve(){
//     int n;
//     cin >> n;
//     a.resize(n);
//     for(int i = 0;i < n;i++) cin >> a[i].x >> a[i].y;
//     sort(a.begin(), a.end(), cmpx);

//     double d = min_dis(0, n); 
//     printf("%.3lf", d);
// }

// signed main(){

//     solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     string s, tmp;
//     cin >> s;
//     int n;
//     cin >> n;
//     int l, r;
//     string a1,a2;
//     while(n--){
//         cin >> l >> r >> a1 >> a2;
//         tmp = s.substr(l-1, r-l+1);
//         s.erase(s.begin()+l-1, s.begin()+r);
//         int ok = 0;
//         for(int i = 0;i < s.size();i++){
//             int f = 1;
//             for(int j = 0;j < a1.size() && j+i < s.size();j++) if(s[i+j] != a1[j]) {
//                 f = 0;
//                 break;
//             }
//             if(!f) continue;
//             for(int j = 0;j < a2.size() && j+i+a1.size() < s.size();j++) if(s[i+j+a1.size()] != a2[j]){
//                 f = 0;
//                 break;
//             }
//             if(f){
//                 ok = 1;
//                 s.insert(i+a1.size(), tmp);
//                 break;
//             }
//         }
//         if(!ok) s += tmp;
//     }
//     cout << s;
// }

// int main(){

//     solve();
    
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int k;
//     cin >> k;
//     vector<vector<int>>l(k+5), mx(k+5);
//     for(int i = 1;i <= k;i++){
//         int sz = 1<<(k-i);
//         l[i].resize(sz+5);
//         mx[i].resize(sz+5);
//         for(int j = 1;j <= sz;j++){
//             cin >> l[i][j];
//             if(i>1) mx[i][j] = max({l[i][j], mx[i-1][j*2], mx[i-1][j*2-1]});
//             else mx[i][j] = l[i][j];
//         }
//     }
//     int w;
//     cin >> w;

//     if(w < l[k][1]){
//         cout << "No Solution";
//         return;
//     }
    
//     vector<vector<array<int,2>>>a(k+5);
//     a[k].resize(3);
//     a[k][1] = {l[k][1], w};
//     for(int i = k-1;i >= 1;i--){
//         int sz = 1<<(k-i);
//         a[i].resize(sz+5);
//         for(int j = 1;j <= sz;j++) a[i][j][0] = l[i][j];
//         for(int j = 1;j <= sz/2;j++) {
//             int f1 = j*2-1, f2 = j*2;
//             if(mx[i][f1] > mx[i][f2]) swap(a[i+1][j][0], a[i+1][j][1]);
//             a[i][f1][1] = a[i+1][j][0];
//             a[i][f2][1] = a[i+1][j][1];
//             if(a[i][f1][1] < a[i][f1][0] || a[i][f2][1] < a[i][f2][0]){
//                 cout << "No Solution";
//                 return;
//             }
//         }
//     }

//     int sz = (1<<(k-1));
//     for(int i = 1;i <= sz;i++) cout << a[1][i][0] << ' ' << a[1][i][1] << ' ';
// }

// int main(){

//     solve();
    
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n;
//     stack<int>a, b;
//     cin >> n;
//     int x, mx = 0, cnt = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> x;
//         if(a.empty() || a.top() < x) a.push(x);
//         else{
//             if(b.empty() || b.top() < x) b.push(x);
//             else{
//                 cnt++;
//                 mx = max(mx, (int)a.size());
//                 while(a.size()) a.pop();
//                 while(b.size() && b.top() > x) {
//                     a.push(b.top());
//                     b.pop();
//                     a.push(x);
//                 }
//             }
//         }
//     }
//     if(a.size()){
//         cnt++;
//         mx = max(mx, (int)a.size());
//         while(a.size()) a.pop();
//     }
//     if(b.size()){
//         cnt++;
//         mx = max(mx, (int)b.size());
//     }
//     cout << cnt << ' ' << mx;
// }

// int main(){

//     solve();
    
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n, c, cnt = 0;
//     cin >> n >> c;
//     priority_queue<array<int,2>>que;
//     vector<string>name(n+5);
//     vector<int>ans(n+5);
//     int x;
//     for(int i = 1;i <= n;i++){
//         cin >> name[i] >> x;
//         que.push({x, i});
//     }
//     list<int>ls;
//     while(que.size()){
//         auto [v, nm] = que.top();
//         que.pop();
//         ans[nm]++;
//         // cerr << v << ' ' << name[nm] << endl;
//         if(v >= c){
//             v -= c;
//             cnt++;
//         }else{
//             if(ls.size()){
//                 auto it = ls.begin();
//                 while(it != ls.end()){
//                     if(*it + v <= c){
//                         *it += v;
//                         if(*it == c) ls.erase(it);
//                         v = 0;
//                         break;
//                     }
//                     it++;
//                 }
//             }
//             if(v){
//                 ls.push_back(v);
//                 cnt++;
//             }
//             v = 0;
//         }
//         if(v) que.push({v, nm});
//     }
//     for(int i = 1;i <= n;i++) cout << name[i] << ' ' << ans[i] << endl;
//     cout << cnt << endl;
// }

// int main(){

//     solve();
    
//     return 0;
// }


//#include<bits/stdc++.h>
//using namespace std;


//int main(){

//	string s("exit\n");
//	if(s == "exit\n") cout << "YES\n";

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'

//const int mod = 998244353;
//const int N = 1e5 + 10;
//int qpow(int a, int b){
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}

//int inv[N], fac[N];
//void get_inv(){
//	inv[0] = fac[0] = 1;
//	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//	inv[N-1] = qpow(fac[N-1], mod-2);
//	for(int i = N-2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
//}
//int C(int a, int b){
//	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), pre(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		pre[i] = a[i] + pre[i-1];
//	}

//	auto dfs = [&](auto self, int l, int r) -> int {
//		if(l == r || r+1 == l) return 1;
//		if(l > r) return 1;
//		int ls = a[l], rs = a[r];
//		while(ls != rs && l < r){
//			if(ls < rs) ls += a[++l];
//			else rs += a[--r];
//		}
//		if(ls != rs) return 1;
		
//		if(r > l && pre[r-1] == pre[l]){
//			int len = r - l;
//			return qpow(2, len);
//		}

//		int L = 1, R = 1;
//		while(a[l+1]==0) l++, L++;
//		while(a[r-1]==0) r--, R++;
//		int len = min(L, R);

//		int f = 0;
//		for(int i = 0; i <= len;i++){
//			f = (f + (C(L, i) * C(R, i) % mod)) % mod;
//		}

//		return f * self(self, l+1, r-1) % mod;
//	};

//	int l = 1, r = n;
//	if(a[l] != a[r] && min(a[l], a[r]) == 0){
//		while(a[l] == 0) l++;
//		while(a[r] == 0) r--;
//	}
//	cout << dfs(dfs, l, r) % mod << endl;
//}

//signed main(){

//	IO;
//	get_inv();
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}







//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'


//void solve(){
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	if(a && c){
//		if(a*d == c*b) cout << 0 << endl;
//		else{
//			if((a*d) % (c*b) == 0 || (c*b) % (a*d) == 0) cout << 1 << endl;
//			else cout << 2 << endl;
//		}
//	}else if(a || c){
//		cout << 1 << endl;
//	}else{
//		cout << 0 << endl;
//	}
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	for(auto &e : a) cin >> e;
//	sort(all(a));
//	int ans = a[n-1] + a[n-2] - a[0] - a[1];
//	cout << ans << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n, m;
//	cin >> n >> m;
//	int sum = 0;
//	vector<string>mp(n+5);
//	for(int i = 1;i <= n;i++){
//		cin >> mp[i];
//		for(auto c : mp[i]) sum += (c == '1');
//		mp[i] = '0' + mp[i] + '0';
//	}
//	mp[0] = mp[n+1] = string(m+5, '0');

//	int mx = 0;
//	for(int i = 1;i < n;i++){
//		for(int j = 1;j < m;j++){
//			int tmp = 0;
//			for(int x = 0;x < 2;x++)
//				for(int y = 0;y < 2;y++) 
//					tmp += (mp[i+x][j+y] == '0');
//			mx = max(mx, tmp);
//		}
//	}

//	if(mx == 0) cout << sum - 2 << endl;
//	else if(mx == 1) cout << sum - 1 << endl;
//	else cout << sum << endl;


//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n), f(n, 1);
//	for(int i = 0;i < n;i++) cin >> a[i];
//	int ans = 1;
//	for(int i = 0;i < n;i++){
//		for(int j = max(0ll, i-401);j < i;j++) if((a[j]^i) < (a[i]^j)) f[i] = max(f[i], f[j]+1);
//		ans = max(ans, f[i]);
//	}

//	cout << ans << endl;

//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 3e5 + 10;
//int ne[N*32][2], val[N*32], tot;

//int query(int x){
//	int p = 0, ret = 0;
//	while(x){
//		int b = (x&1);
//		x >>= 1;
//		ret = max(ret, val[ne[p][b^1]]);
//		if(!ne[p][b]) break;
//		p = ne[p][b];
//	}
//	return max(ret, val[ne[p][1]]);
//}
//void insert(int x, int v){
//	int p = 0;
//	while(x){
//		int b = (x&1);
//		x >>= 1;
//		if(!ne[p][b]) ne[p][b] = ++tot;
//		p = ne[p][b];
//		val[p] = max(val[p], v);
//	}
//	if(!ne[p][0]) ne[p][0] = ++tot;
//	p = ne[p][0];
//	val[p] = max(val[p], v);
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n), f(n, 1);
//	for(int i = 0;i < n;i++) cin >> a[i];
//	int ans = 1;
//	for(int i = 0;i < n;i++){
//		f[i] = max(f[i], query(a[i]^i)+1);
//		insert(a[i]^i, f[i]);
//		ans = max(ans, f[i]);
//		cerr << f[i] << ' ';
//	}

//	cout << ans << endl;
//	for(int i = 0;i <= tot;i++) {
//		ne[i][0] = ne[i][1] = val[i] = 0;
//	}
//	tot = 0;
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	int O = 0, A = (1ll<<34)-1;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		O |= a[i];
//		A &= a[i];
//	}

//	int oc = 0, ac = 0;
//	for(int i = 1;i <= n;i++){
//		oc += (O != a[i]);
//		ac += (A != a[i]);
//	}

//	if(oc == ac){
//		cout << "sad\n";
//	}else if(oc < ac){
//		cout << "or\n";
//	}else{
//		cout << "and\n";
//	}
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), ans(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	vector<int>id(n);
//	iota(all(id), 1);
//	sort(all(id), [&](int i, int j) -> int {return a[i] < a[j];});
//	int p = 0;
//	__int128_t a1 = 1, a2 = 1, sum = 0;
//	for(int i = 1;sum <= (int)(1e18);i++){
//		sum += a2;
//		while(p < n && a[id[p]] <= sum) {
//			ans[id[p]] = i;
//			p++;
//		}
//		__int128_t tmp = a1;
//		a1 = a2;
//		a2 = tmp + a2;
//	}
//	for(int i = 1;i <= n;i++) {
//		if(ans[i] & 1) cout << 'T';
//		else cout << "K";
//	}
//}

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s = ' ' + s;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) {
//		if(s[i] == 'F') a[i] = 1;
//		else if(s[i] == 'R') a[i] = 2;
//		else a[i] = 3;
//	}

//	while(n > 1){
//		int m = n/2;
//		vector<int>b(m+5);
//		for(int i = 2;i <= n;i += 2){
//			if(a[i-1] > a[i]) swap(a[i], a[i-1]);
//			if(a[i] == a[i-1]){
//				b[i/2] = a[i];
//			}else{
//				if(a[i] <= 1) b[i/2] = a[i];
//				else if(a[i] == 2){
//					if(a[i-1] == 1) b[i/2] = 0;
//					else b[i/2] = 2;
//				}else{
//					if(a[i-1] == 2) {
//						cout << "No\n";
//						return;
//					}else b[i/2] = 3;
//				}
//			}
//		}
//		a = b;
//		n /= 2;
//	}
//	cout << "Yes\n";
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n, k, d;
//	cin >> n >> k;
//	d = n-k + 1;
//	string s;
//	cin >> s;
//	s = ' ' + s;
//	if(d >= 30) {
//		cout << "No\n";
//		return;
//	}
//	set<char>st;
//	for(int i = 1;i <= d;i++){
//		if(st.count(s[i])){
//			cout << "No\n";
//			return;
//		}
//		st.insert(s[i]);
//	}
//	for(int i = 1;i + d <= n;i++){
//		st.erase(s[i]);
//		if(st.count(s[i+d])){
//			cout << "No\n";
//			return;
//		}
//		st.insert(s[i+d]);
//	}
//	cout << "Yes\n";
//}

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n, m, q;
//	cin >> n >> m >> q;
//	vector<int>a(n+5), pos(n+5), id(n+5);
//	a[n+1] = n+1;
//	a[n+2] = n+2;
//	for(int i = 1;i <= n;i ++) cin >> a[i];
//	iota(all(pos), 0);
//	iota(all(id), 0);
//	while(m--){
//		int x, y;
//		cin >> x >> y;
//		if(x == y) continue;
//		swap(a[x], a[y]);
//		swap(id[x], id[y]);
//		swap(pos[id[x]], pos[id[y]]);
//	}

//	//for(int i = 1;i <= n;i++) cerr << a[i] << ' ';
//	//cerr << endl;
//	//for(int i = 1;i <= n;i++) cerr << id[i] << ' ';
//	//cerr << endl;
//	//for(int i = 1;i <= n;i++) cerr << pos[i] << ' ';
//	//cerr << endl;

//	set<int>st;
//	for(int i = 1;i <= n;i++) if(a[i] > a[i+1]) st.insert(i);

//	auto check = [&](int x) -> void {
//		if(a[x] > a[x+1]) st.insert(x);
//		else st.erase(x);
//	};

//	while(q--){
//		int x, y;
//		cin >> x >> y;
//		//swap(pos[x], pos[y]);
//		//swap(id[pos[x]], id[pos[y]]);
//		swap(a[pos[x]], a[pos[y]]);
//		int p1 = pos[x], p2 = pos[y];
//		check(p1);
//		check(p1-1);
//		//check(p1+1);
//		check(p2);
//		check(p2-1);
//		//check(p2+1);
//		if(st.size()) cout << 'N';
//		else cout << 'Y';
//	}
//	cout << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 1e5 + 10;
//int f[N][2], a[N], vis[N];
//list<int>g[N];

//int rt, sp;
//void getrt(int u, int fa){
//	vis[u] = 1;
//	for(auto v : g[u]) if(v != fa && !sp){
//		if(vis[v]){
//			rt = u;
//			sp = v;
//			return;
//		}
//		getrt(v, u);
//	}
//}
//void dfs0(int u, int fa){
//	f[u][0] = f[u][1] = 0;
//	if(u != sp) f[u][1] = a[u];
//	for(auto v : g[u]) if(v != fa){
//		dfs0(v, u);
//		f[u][0] += max(f[v][0], f[v][1]);
//		f[u][1] += f[v][0];
//	}
//}
//void dfs1(int u, int fa){
//	//cerr << u << endl;
//	vis[u] = 1;
//	f[u][0] = f[u][1] = 0;
//	f[u][1] = a[u];
//	for(auto v : g[u]) if(v != fa){
//		dfs1(v, u);
//		f[u][0] += max(f[v][0], f[v][1]);
//		f[u][1] += f[v][0];
//	}
//}

//int fun(int x){
//	rt = sp = 0;
//	getrt(x, 0);

//	auto it = g[rt].begin();
//	while(it != g[rt].end()){
//		if(*it == sp){
//			g[rt].erase(it);
//			break;
//		}
//		it++;
//	}
//	it = g[sp].begin();
//	while(it != g[sp].end()){
//		if(*it == rt){
//			g[sp].erase(it);
//			break;
//		}
//		it++;
//	}

//	//cerr << rt << ' ' << sp << endl;
//	dfs0(rt, 0);
//	int ret = max(f[rt][0], f[rt][1]);
//	dfs1(rt, 0);
//	ret = max(ret, f[rt][0]);
//	return ret;
//}

//void solve(){
//	int n;
//	cin >> n;
//	for(int i = 1, fa;i <= n;i++){
//		cin >> a[i] >> fa;
//		g[fa].push_back(i);
//		g[i].push_back(fa);
//	}

//	int ans = 0;
//	for(int i = 1;i <= n;i++) if(!vis[i]) {
//		ans += fun(i);
//	}

//	cout << ans << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	map<int,int>mp;
//	while(n--){
//		int x;
//		cin >> x;
//		mp[x]++;
//	}
//	int cnt = 0;
//	for(auto [k, v] : mp) cnt += v/3;
//	cout << cnt << endl;
//}	

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	if(n == 1){
//		cout << k << endl;
//		return;
//	}
//	int a1 = 0, pw = 1;
//	while(a1 + pw <= k){
//		a1 += pw;
//		pw <<= 1;
//	}
//	cout << a1 << ' ' << k-a1 << ' ';
//	n -= 2;
//	while(n--) cout << 0 << ' ';
//	cout << endl;
//}	

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int mod = 1e9 + 7;
//const int N = 3e5 + 10;

//int f[N], fac[N], inv[N];
//int qpow(int a, int b){
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}
//void get_inv(){
//	fac[0] = inv[0] = 1;
//	for(int i = 1;i < N;i++) fac[i] = fac[i-1] * i % mod;
//	inv[N-1] = qpow(fac[N-1], mod-2);
//	for(int i = N-2;i >= 1;i--) inv[i] = inv[i+1] * (i+1) % mod;
//}
//int C(int a, int b){
//	return (fac[a] * inv[a-b] % mod) * inv[b] % mod;
//}

//int bit(int x){
//	int ret = 0;
//	while(x){
//		ret ++;
//		x >>= 1;
//	}
//	return ret;
//}


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	while(k--){
//		int x, y;
//		cin >> x >> y;
//		if(x == y) n--;
//		else n -= 2;
//	}

//	int ans = 0;

//	for(int i = (n&1);i <= n;i += 2){
//		int x = n - i;
//		ans = (ans + (f[x] * C(n, i) % mod)) % mod;
//	}

//	cout << ans << endl;
//}	

//signed main(){

//	IO;

//	get_inv();
//	f[2] = 2;
//	f[0] = 1;
//	for(int i = 4;i < N;i += 2){
//		f[i] = (f[i-2] * (i-1) * 2) % mod;
//	}

//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), tp(n+5);
//	vector<array<int,35>>xo(n+5);
//	vector<vector<array<int,35>>>suf(2, vector<array<int,35>>(n+5));
//	vector<vector<array<int,35>>>pre(2, vector<array<int,35>>(n+5));
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		for(int j = 0;j <= 31;j++) {
//			xo[i][j] = (xo[i-1][j] ^ ((a[i]>>j)&1));
//			if((a[i]>>j)&1) tp[i] = j;
//			suf[xo[i][j]][j]++;
//		}
//		//cerr << tp[i] << ' ';
//	}
//	for(int j = 0;j <= 31;j++) {
//		pre[0][j]++;
//	}

//	//cerr << endl;

//	int ans = 0;
//	for(int i = 1;i <= n;i++){
//		for(int j = 0;j <= 31;j++) pre[xo[i][j]][j]++;
//		//cerr << suf[0][0] << ' ' << suf[0][1] << ' ' << suf[0][2] << endl;
//		//cerr << suf[1][0] << ' ' << suf[1][1] << ' ' << suf[1][2] << endl;
//		//cerr << pre[0][0] << ' ' << pre[0][1] << ' ' << pre[0][2] << endl;
//		//cerr << pre[1][0] << ' ' << pre[1][1] << ' ' << pre[1][2] << endl;
//		//cerr << endl;
//		ans += (pre[0][tp[i]] * suf[0][tp[i]]);
//		cerr << ans << ' ';
//		ans += (pre[1][tp[i]] * suf[1][tp[i]]);
//		cerr << ans << endl;
//		ans--;
//		for(int j = 0;j <= 31;j++) suf[xo[i][j]][j]--;
//	}
//	cout << ans << endl;
//}	

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), tp(n+5);
//	vector<array<int,35>>xo(n+5);
//	vector<vector<array<int,35>>>suf(2, vector<array<int,35>>(n+5));
//	vector<vector<array<int,35>>>pre(2, vector<array<int,35>>(n+5));
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		for(int j = 0;j <= 31;j++) {
//			xo[i][j] = (xo[i-1][j] ^ ((a[i]>>j)&1));
//			if((a[i]>>j)&1) tp[i] = j;
//		}
//	}
//	for(int j = 0;j <= 31;j++) {
//		pre[0][0][j] = 1;
//	}

//	for(int i = 1;i <= n;i++){
//		for(int j = 0;j <= 31;j++){			
//			pre[0][i][j] = pre[0][i-1][j];
//			pre[1][i][j] = pre[1][i-1][j];
//			pre[xo[i][j]][i][j]++; 
//		}
//	}
//	for(int i = n;i >= 1;i--){
//		for(int j = 0;j <= 31;j++){			
//			suf[0][i][j] = suf[0][i+1][j];
//			suf[1][i][j] = suf[1][i+1][j];
//			suf[xo[i][j]][i][j]++; 
//		}
//	}

//	int ans = 0;
//	for(int i = 1;i <= n;i++){
//		ans += (pre[0][i-1][tp[i]] * suf[0][i+1][tp[i]]);
//		ans += (pre[1][i-1][tp[i]] * suf[1][i+1][tp[i]]);
//		if(i-2 >= 0) ans += pre[xo[i][tp[i]]][i-2][tp[i]];
//		//cerr << ans << endl;
//	}
//	cout << ans << endl;
//}	

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}





//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()


//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), x(n+5);
//	for(int i = 1;i <= n;i++) {
//		cin >> a[i];
//		x[i] = (x[i-1]^a[i]);
//	}

//	int ans = 0;
//	for(int l = 1;l <= n;l++){
//		for(int r = l;r <= n;r++){
//			int b = x[l-1] ^ x[r];
//			for(int i = l;i <= r;i++){
//				if((b^a[i]) > b) {
//					ans++;
//					cerr << l << ' ' << r << ' ' << i << endl;
//				}
//			}
//		}
//	}
//	cerr << ans;
//}	

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}