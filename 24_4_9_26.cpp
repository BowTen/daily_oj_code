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




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 3e5 + 10;
//int tr[N*30][2], mx[N*30][2], tot;
//int query(int x, int id){	
//	int p = 0, ret = 0;
//	for(int i = 30;i >= 0;i--){
//		bool b = (x>>i)&1, bi = (id>>i)&1;
//		ret = max(ret, mx[tr[p][!b]][bi]);
//		if(!tr[p][b]) break;
//		p = tr[p][b];
//	}
//	return ret;
//}
//void insert(int x, int a, int v){
//	int p = 0;
//	for(int i = 30;i >= 0;i--){
//		bool b = (x>>i)&1, ba = (a>>i)&1;
//		if(!tr[p][b]) tr[p][b] = ++tot;
//		p = tr[p][b];
//		mx[p][ba] = max(mx[p][ba], v);
//	}
//}

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	int ans = 0;
//	for(int i = 0;i < n;i++){
//		cin >> a[i];
//		int f = query(a[i]^i, i) + 1;
//		insert(a[i]^i, a[i], f);
//		ans = max(ans, f);
//	}
//	cout << ans << endl;

//	for(int i = 0;i <= tot;i++){
//		tr[i][0] = tr[i][1] = mx[i][0] = mx[i][1] = 0;
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

//int exgcd(int a, int b, int &x, int &y){
//	//cerr << a << ' ' << b << endl;
//	if(b == 0){
//		x = 1, y = 0;
//		return a;
//	}
//	int x1, y1, d;
//	d = exgcd(b, a%b, x1, y1);
//	x = x1, y = x1-a/b*y1;
//	//cerr << x1 << ' ' << y1 << endl;
//	return d;
//}	

//void solve(){
//	int x, y, n, m, l, d;
//	cin >> x >> y >> n >> m >> l;
//	if(n == m){
//		cout << "Impossible\n";
//		return;
//	}
//	int k1, k2;
//	int g = exgcd(n-m, l, k1, k2);
//	cerr << k1 << ' ' << k2 << ' ' << g << endl;
//	if((y-x)%g){
//		cout << "Impossible\n";
//		return;
//	}
//	k1 *= (y-x)/g;
//	k2 *= (y-x)/g;
//	if((k1*n+x)%l == (k1*m+y)%l) cout << k1 << endl;
//	else cout << k2 << endl;
//	// dn + x = dm + y  d(n-m) = y-x(mod l)
//	// d(n-m) = (y-x) + l*k   d(n-m) - kl = y-x

//}	

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();
//	//cerr << gcd(4, 0);

//	return 0;
//}




//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()

//const int N = 2e5 + 1;
//int n, m, q, fa[N];
//vector<array<int,2>>g[N];

//int find(int x){
//	return x == fa[x] ? x : fa[x] = find(fa[x]);
//}
//void merg(int a, int b){
//	a = find(a);
//	b = find(b);
//	fa[a] = b;
//}

//int dep[N], par[N][20], mx[N][20];
//void dfs(int u, int fa, int val){
//	dep[u] = dep[fa] + 1;
//	par[u][0] = fa;
//	mx[u][0] = val;
//	for(int i = 1;i < 20;i++){
//		par[u][i] = par[par[u][i-1]][i-1];
//		mx[u][i] = max(mx[u][i-1], mx[par[u][i-1]][i-1]);
//	}
//	for(auto [v, w] : g[u]) if(v != fa){
//		dfs(v, u, w);
//	}
//}
//int getmx(int u, int v){
//	int ret = 0;
//	if(dep[u] < dep[v]) swap(u, v);
//	for(int i = 19;i >= 0;i--){
//		if(dep[par[u][i]] >= dep[v]){
//			ret = max(ret, mx[u][i]);
//			u = par[u][i];
//		}
//	}
//	if(u == v) return ret;
//	for(int i = 19;i >= 0;i--){
//		if(par[u][i] != par[v][i]){
//			ret = max({ret, mx[u][i], mx[v][i]});
//			u = par[u][i];
//			v = par[v][i];
//		}
//	}
//	return max({ret, mx[u][0], mx[v][0]});
//}

//#define ls id << 1
//#define rs id << 1 | 1
//int a[N], tr[N<<2];
//void up(int id){
//	tr[id] = max(tr[ls], tr[rs]);
//}
//void build(int id, int l, int r){
//	if(l == r){
//		tr[id] = a[l];
//		return;
//	}
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//	up(id);
//}
//int query(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return tr[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls, l, mid, ql, qr);
//	else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//	else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
//}


//void init(){
//	for(int i = 1;i <= n;i++){
//		fa[i] = i;
//		g[i].clear();
//	}
//}

//void solve(){
//	cin >> n >> m >> q;
//	init();
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		if(find(u) != find(v)){
//			g[v].push_back({u, i});
//			g[u].push_back({v, i});
//			merg(u, v);
//		}
//	}
//	dfs(1, 0, 0);
//	for(int i = 1;i < n;i++){
//		a[i] = getmx(i, i+1);
//	}
//	build(1, 1, n-1);
//	while(q--){
//		int l, r;
//		cin >> l >> r;
//		if(l == r){
//			cout << 0 << ' ';
//			continue;
//		}
//		cout << query(1, 1, n-1, l, r-1) << ' ';
//	}
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

//const int N = 2e5 + 30;
//int b[N], a[N];

//#define ls id << 1
//#define rs id << 1 | 1
//int R[2][N<<2], tag[N<<2], tr[N<<2];
//void up(int id){
//	R[0][id] = max(R[0][ls], R[0][rs]);
//	R[1][id] = max(R[1][ls], R[1][rs]);
//	if(~tr[ls] >= 0 && ~tr[rs] && tr[ls] == tr[rs]) tr[id] = tr[ls];
//	else tr[id] = -1;
//}
//void build(int id, int l, int r){
//	if(l == r){
//		tr[id] = b[l];
//		R[b[l]][id] = l;
//		return;
//	}
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//	up(id);
//}
//void settag(int id){
//	tr[id] ^= 1;
//	tag[id] ^= 1;
//	swap(R[0][id], R[1][id]);
//}
//void down(int id){
//	settag(ls);
//	settag(rs);
//	tag[id] = 0;
//}
//void modify(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) {
//		settag(id);
//		return;
//	}
//	if(tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(qr <= mid) modify(ls, l, mid, ql, qr);
//	else if(ql > mid) modify(rs, mid + 1, r, ql, qr);
//	else modify(ls, l, mid, ql, qr), modify(rs, mid + 1, r, ql, qr);
//	up(id);
//}
//int find(int id, int l, int r, int p, int f){
//	if(l == r) return l;
//	if(tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(R[f][ls] > p) return find(ls, l, mid, p, f);
//	else return find(rs, mid + 1, r, p, f);
//}
//int query(int id, int l, int r, int x){
//	if(l == r) return tr[id];
//	if(tag[id]) down(id);
//	int mid = l + r >> 1;
//	if(x <= mid) return query(ls, l, mid, x);
//	else return query(rs, mid + 1, r, x);
//}

//void solve(){
//	int n, q;
//	cin >> n >> q;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		b[a[i]]++;
//	}
//	for(int i = 1;i < N;i++){
//		b[i] += b[i-1]/2;
//		b[i-1] %= 2;
//	}

//	int m = N-5;
//	build(1, 1, m);


//	while(q--){
//		int l, x, p;
//		cin >> l >> x;
//		p = a[l];
//		int b = query(1, 1, m, p);
//		if(b == 1) modify(1, 1, m, p, p);
//		else {
//			int r = find(1, 1, m, p, 1);
//			modify(1, 1, m, p, r-1);
//			modify(1, 1, m, r, r);
//		}

//		p = a[l] = x;
//		b = query(1, 1, m, p);
//		if(b == 0) modify(1, 1, m, p, p);
//		else {
//			int r = find(1, 1, m, p, 0);
//			modify(1, 1, m, p, r-1);
//			modify(1, 1, m, r, r);
//		}

//		cout << R[1][1] << endl;
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
//	vector<int>a(n+5), cnt(n+5), f(n+5);
//	vector<vector<int>>del(n+5, vector<int>(n+5));
//	for(int i = 1;i <= n;i++) {
//		cin >> a[i];
//	} 
//	for(int len = 2;len <= n;len += 2){
//		int ok = 1;
//		for(int i = 1;i <= len;i++){
//			if(++cnt[a[i]] > len/2) ok = 0;
//		}
//		for(int i = 1, j = len;j <= n;i++, j++){
//			del[i][j] = ok;
//			cnt[a[i]]--;
//			cnt[a[j+1]]++;
//			if(cnt[a[i]] == len/2) ok = 1;
//			if(cnt[a[j+1]] > len/2) ok = 0;
//		}
//		for(int i = 0;i <= n;i++) cnt[i] = 0;
//	}
//	int ans = 0;
//	f[1] = 1;
//	if(1 == n || del[2][n]) ans = f[1];
//	for(int i = 2;i <= n;i++){
//		if(del[1][i-1]) f[i] = 1;
//		for(int j = 1;j+1 <= i-1;j++){
//			if(a[j] == a[i] && del[j+1][i-1] && f[j]) f[i] = max(f[i], f[j]+1);
//		}
//		if(a[i-1] == a[i] && f[i-1]) f[i] = max(f[i], f[i-1]+1);
//		if(i == n || del[i+1][n]) ans = max(ans, f[i]);
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

//const int N = 2e5 + 10;
//const int mod = 998244353;
//int fac[N], inv[N];
//int qpow(int a, int b){
//	int ret = 1;
//	while(b){
//		if(b & 1) ret = a * ret % mod;
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
//int A(int a, int b){
//	return fac[a] * inv[a-b] % mod;
//}

//void solve(){
//	int n, s;
//	cin >> n >> s;
//	vector<int>a(n+5), b(n+5), vis(n+5), low(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++){
//		cin >> b[i];
//		if(b[i] > 0) vis[b[i]] = 1;
//	}
//	vector<int>num;
//	for(int i = 1;i <= n;i++) if(!vis[i]) num.push_back(i);
//	vector<int>cnt(num.size());
//	for(int i = 1;i <= n;i++){
//		if(b[i] == -1){
//			low[i] = max(0ll, a[i] - s);
//			auto it = lower_bound(all(num), low[i]);
//			if(it == num.end()){
//				cout << 0 << endl;
//				return;
//			}
//			cnt[it-num.begin()]++;
//		}else{
//			if(b[i]+s < a[i]){
//				cout << 0 << endl;
//				return;
//			}
//		}
//	}
//	int sum = 0;
//	int ans = 1;
//	for(int i = cnt.size()-1;i >= 0;i--) if(cnt[i]){
//		ans = ans * A(cnt.size()-i-sum, cnt[i]) % mod;
//		sum += cnt[i];
//	}
//	cout << ans << endl;
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
//#define all(x) (x).begin(), (x).end()

//const int N = 1e6 + 10;
//int a[N], n;
//int cmp(int i, int j){
//	if(a[i] == a[j]) return n+1;
//	if(a[i] > a[j]) return i;
//	else return j;
//}
//struct node{
//	int mx, win;
//	node operator+(const node& e) {
//		node ret;
//		ret.mx = max(mx, e.mx);
//		if(a[win] >= e.mx) ret.win = cmp(win, e.win);
//		else ret.win = e.win;
//		return ret;
//	}
//}tr[N<<2];

//#define ls id << 1 
//#define rs id << 1 | 1
//void up(int id){
//	tr[id] = tr[ls] + tr[rs];
//}
//void build(int id, int l, int r){
//	if(l == r){
//		tr[id] = {a[l], l};
//		return;
//	}
//	int mid = l + r >> 1;
//	build(ls, l, mid);
//	build(rs, mid + 1, r);
//	up(id);
//}
//node query(int id, int l, int r, int ql, int qr){
//	if(ql <= l && r <= qr) return tr[id];
//	int mid = l + r >> 1;
//	if(qr <= mid) return query(ls, l, mid, ql, qr);
//	else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//	else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
//}

//void solve(){
//	int q;
//	cin >> n >> q;
//	a[n+1] = -1e9;
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	build(1, 1, n);
//	while(q--){
//		int l, r, x;
//		cin >> l >> r >> x;
//		node tmp = {x, r};
//		int sum = r-l+1;
//		if(sum & 1) tmp.win = r;
//		else tmp.win = n+1;

//		int ar = a[r];
//		a[r] = x;
//		if(l > 1) tmp = query(1, 1, n, 1, l-1) + tmp;
//		if(r < n) tmp = tmp + query(1, 1, n, r+1, n);
//		cout << tmp.win << endl;
//		a[r] = ar;
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
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	vector<int>f(n+5);
	
//	int ans = 0;
//	auto dfs = [&](auto self, int u, int fa) -> void {
//		f[u] = 1;
//		int mx = 0, son = 0;
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//			mx = max(mx, f[v]);
//			son++;
//		}
//		if(son) f[u] += mx + son-1;
//		if(son){
//			array<int,2>mx = {0, 0};
//			for(auto v : g[u]) if(v != fa){
//				mx[1] = max(mx[1], f[v]);
//				if(mx[1] > mx[0]) swap(mx[0], mx[1]);
//			}
//			if(u == 1) ans = max(ans, mx[0]+mx[1]+son-1);
//			else ans = max(ans, mx[0]+mx[1]+son);
//		}
//		ans = max(ans, f[u]);
//	};

//	dfs(dfs, 1, 0);
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

//int ans = 0;
//struct node{
//	int h, w;
//	node(int h = 0, int w = 0) : h(h), w(w) {};
//	int operator<(const node& e) const {
//		if(w == e.w) return h < e.h;
//		return w < e.w;
//	}
//};
//struct water{
//	int mx, cur;
//	multiset<node>st;
//	water(int c, int c0) : mx(c), cur(c0) {
//		st.insert(node(c0, 0));
//	}

//	int use(int x){
//		if(cur < x) return 0;
//		cur -= x;
//		while(x){
//			auto nd = *st.begin();
//			st.erase(st.begin());
//			int d = min(x, nd.h);
//			nd.h -= d;
//			x -= d;
//			ans += d * nd.w;
//			//cerr << d << ' ' << nd.w << endl;
//			if(nd.h) st.insert(nd);
//		}
//		return 1;
//	}

//	void add(int h, int w){
//		cur += h;
//		st.insert(node(h, w));
//	}

//	void upd(){
//		while(cur > mx){
//			auto nd = *st.rbegin();
//			st.erase(prev(st.end()));
//			int d = min(cur-mx, nd.h);
//			cur -= d;
//			nd.h -= d;
//			if(nd.h) st.insert(nd);
//		}
//	}

//	void log(){
//		cerr << cur << endl;
//		for(auto [h, w] : st) cerr << h << ' ' << w << endl;
//	}
//};


//void solve(){
//	ans = 0;
//	int n, m, c, c0;
//	cin >> n >> m >> c >> c0;
//	water wt(c, c0);

//	vector<array<int,3>>f(n);
//	for(int i = 0;i < n;i++){
//		for(int j = 0;j < 3;j++) cin >> f[i][j];
//		swap(f[i][1], f[i][2]);
//	}
//	sort(f.begin(), f.end());
//	f.push_back({m, 0, 0});

//	int ls = 0;
//	for(int i = 0;i <= n;i++){
//		auto [t, w, s] = f[i];
//		int d = t-ls;
//		if(!wt.use(d)) { 
//			cout << -1 << endl;
//			return;
//		}
//		wt.add(s, w);
//		wt.upd();
//		ls = t;
// 		//cerr << t << ' ' << s << ' ' << w << ' ' << ans << endl;
//		//wt.log();
//		//cerr << endl;
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
//	if(n == 1){
//		cout << 0 << endl;
//		return;
//	}
//	vector<vector<int>>g(n+5);
//	for(int i = 1, u, v;i < n;i++){
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	int leaf = 0, cnt = 0;
//	for(int i = 1;i <= n;i++){
//		if(g[i].size() == 1) leaf++;
//		else if(g[i].size() > 2) cnt++;
//	}
//	if(cnt == 0){
//		cout << 1 << endl;
//		return;
//	}

//	vector<int>s(n+5);

//	auto dfs = [&](auto self, int u, int fa) -> void {
//		if(g[u].size() > 2) {
//			s[u]++;
//			return;
//		}
//		for(auto v : g[u]) if(v != fa){
//			self(self, v, u);
//		}
//	};

//	for(int i = 1;i <= n;i++) if(g[i].size() == 1){
//		dfs(dfs, i, 0);
//	}

//	int ans = leaf;
//	for(int i = 1;i <= n;i++) if(s[i]){
//		ans--;
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

//const int inf = 0x3f3f3f3f;

//void solve(){
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>g(n+5);
//	vector<int>d(n+5);
//	for(int i = 1, u, v;i <= m;i++){
//		cin >> u >> v;
//		d[u]++;
//		g[v].push_back(u);
//	}
//	vector<int>dis(n+5, inf);
//	dis[n] = 0;

//	priority_queue<array<int,2>, vector<array<int,2>>,greater<array<int,2>>>que;
//	que.push({dis[n], n});
//	while(que.size()){
//		auto [ds, u] = que.top();
//		que.pop();
//		if(ds > dis[u]) continue;
//		for(auto v : g[u]) {
//			if(ds + d[v] < dis[v]){
//				dis[v] = ds + d[v];
//				que.push({dis[v], v});
//			}
//			d[v]--;
//		}
//	}

//	cout << dis[1] << endl;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 0x3f3f3f3f;

//void solve(){
//	int n;
//	cin >> n;
//	vector<array<int,3>>seg(n+5);
//	for(int i = 1, c, l, r;i <= n;i++){
//		cin >> c >> l >> r;
//		seg[i] = {l, r, c};
//	}
//	seg[0] = {-1, -1, 0};
//	sort(all1(seg));
//	int R[2] = {0, 0};
//	set<pair<int,int>>st[2];
//	vector<int>fa(n+5);
//	iota(all(fa), 0);
	
//	auto find = [&](auto self, int x) -> int {
//		return x == fa[x] ? x : fa[x] = self(self, fa[x]);
//	};
//	auto merg = [&](int a, int b) -> void {
//		a = find(find, a);
//		b = find(find, b);
//		fa[a] = b;
//	};

//	for(int i = 1;i <= n;i++){
//		auto [l, r, c] = seg[i];
//		//cerr << l << ' ' << r << ' ' << c << ' ' << ans << endl;
//		int f = 0;
//		int c1 = c^1;
//		if(seg[R[c1]][1] >= l){
//			merg(R[c1], i);
//			f = 1;
//		}
//		while(st[c1].size() && st[c1].begin()->first < l) st[c1].erase(st[c1].begin());
//		if(st[c1].size()){
//			f = 1;
//			for(auto [v, id] : st[c1]) {
//				merg(i, id);
//			}
//			if(st[c1].rbegin()->first > seg[R[c1]][1])
//			R[c1] = st[c1].rbegin()->second;
//			st[c1].clear();
//		}
//		if(f){
//			if(r > seg[R[c]][1]) R[c] = i;
//		}else{
//			st[c].insert({r, i});
//		}
//	}

//	int ans = 0;
//	for(int i = 1;i <= n;i++) ans += (i == find(find, i));
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int inf = 0x3f3f3f3f;
//const int N = 410;
//int mod;

//int add(int a, int b){
//	return (a + b) % mod;
//}
//int dv(int a, int b){
//	return (a - b + mod) % mod;
//}

//void solve(){
//	int n, k;
//	cin >> n >> k >> mod;
//	vector<vector<int>>f(n+5, vector<int>(k+5)), pre(n+5, vector<int>(k+5)), xpre(n+5, vector<int>(n+5));
//	for(int i = 0;i <= k;i++) f[2][i] = 1;
//	for(int i = 0;i <= k;i++){
//		for(int x = 0;x <= i;x++){
//			for(int y = 0;y <= i;y++) if(x+y >= i){
//				//cerr << x << ' ' << i << ' ' << y << endl;
//				f[3][y]++;
//				f[3][y] %= mod;
//			}
//		}
//	}

//	for(int i = 2;i <= 3;i++){
//		pre[i][0] = f[i][0];
//		xpre[i][0] = f[i][0];
//		for(int j = 1;j <= k;j++){
//			pre[i][j] = add(f[i][j], pre[i][j-1]);
//			xpre[i][j] = add(((j+1)*f[i][j]%mod), xpre[i][j-1]);
//		}
//	}

//	for(int i = 4;i <= n;i++){
//		f[i][0] = pre[i-1][k];
//		pre[i][0] = f[i][0];
//		xpre[i][0] = f[i][1];
//		for(int j = 1;j <= k;j++){
//			f[i][j] = add(f[i][j], dv(pre[i-1][k], pre[i-1][j-1]));
//			f[i][j] = add(f[i][j], xpre[i-2][j-1]);
//			pre[i][j] = add(f[i][j], pre[i][j-1]);
//			xpre[i][j] = add(((j+1)*f[i][j]%mod), xpre[i][j-1]);
//		}
//	}

//	for(int i = 2;i <= n;i++){
//		for(int j = 0;j <= k;j++){
//			cerr << f[i][j] << ' ';
//		}
//		cerr << endl;
//	}

//	//cerr << pre[3][0] << ' ' << pre[3][1] << endl;
//	//cerr << pre[2][0] << ' ' << pre[2][1] << endl;
 
//	int ans = 0;
//	for(int i = 0;i <= k;i++) ans = add(ans, f[n][i]);
//	cout << ans << endl;
//}		

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}


//#include <bits/stdc++.h>

//using i64 = long long;

//template<class T>
//constexpr T power(T a, i64 b) {
//    T res {1};
//    for (; b; b /= 2, a *= a) {
//        if (b % 2) {
//            res *= a;
//        }
//    }
//    return res;
//}

//constexpr i64 mul(i64 a, i64 b, i64 p) {
//    i64 res = a * b - i64(1.L * a * b / p) * p;
//    res %= p;
//    if (res < 0) {
//        res += p;
//    }
//    return res;
//}

//template<i64 P>
//struct MInt {
//    i64 x;
//    constexpr MInt() : x {0} {}
//    constexpr MInt(i64 x) : x {norm(x % getMod())} {}
	
//    static i64 Mod;
//    constexpr static i64 getMod() {
//        if (P > 0) {
//            return P;
//        } else {
//            return Mod;
//        }
//    }
//    constexpr static void setMod(i64 Mod_) {
//        Mod = Mod_;
//    }
//    constexpr i64 norm(i64 x) const {
//        if (x < 0) {
//            x += getMod();
//        }
//        if (x >= getMod()) {
//            x -= getMod();
//        }
//        return x;
//    }
//    constexpr i64 val() const {
//        return x;
//    }
//    constexpr MInt operator-() const {
//        MInt res;
//        res.x = norm(getMod() - x);
//        return res;
//    }
//    constexpr MInt inv() const {
//        return power(*this, getMod() - 2);
//    }
//    constexpr MInt &operator*=(MInt rhs) & {
//        if (getMod() < (1ULL << 31)) {
//            x = x * rhs.x % int(getMod());
//        } else {
//            x = mul(x, rhs.x, getMod());
//        }
//        return *this;
//    }
//    constexpr MInt &operator+=(MInt rhs) & {
//        x = norm(x + rhs.x);
//        return *this;
//    }
//    constexpr MInt &operator-=(MInt rhs) & {
//        x = norm(x - rhs.x);
//        return *this;
//    }
//    constexpr MInt &operator/=(MInt rhs) & {
//        return *this *= rhs.inv();
//    }
//    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
//        MInt res = lhs;
//        res *= rhs;
//        return res;
//    }
//    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
//        MInt res = lhs;
//        res += rhs;
//        return res;
//    }
//    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
//        MInt res = lhs;
//        res -= rhs;
//        return res;
//    }
//    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
//        MInt res = lhs;
//        res /= rhs;
//        return res;
//    }
//    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
//        i64 v;
//        is >> v;
//        a = MInt(v);
//        return is;
//    }
//    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
//        return os << a.val();
//    }
//    friend constexpr bool operator==(MInt lhs, MInt rhs) {
//        return lhs.val() == rhs.val();
//    }
//    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
//        return lhs.val() != rhs.val();
//    }
//};

//template<>
//i64 MInt<0>::Mod = 998244353;

//constexpr int P = 1000000007;
//using Z = MInt<0>;

//void solve() {
//    int n, k, p;
//    std::cin >> n >> k >> p;
	
//    Z::setMod(p);
	
	//std::vector dp(k + 1, std::vector<Z>(k + 1));
	//dp[0][0] = 1;
	//for (int i = 1; i <= n; i++) {
	//    std::vector g(k + 1, std::vector<Z>(k + 1));
	//    for (int b = 0; b <= k; b++) {
	//        for (int a = 0; a <= k; a++) {
	//            int c = std::max(0, b - a);
	//            g[b][c] += dp[a][b];
	//        }
	//        for (int j = 1; j <= k; j++) {
	//            g[b][j] += g[b][j - 1];
	//        }
	//    }
	//    std::swap(dp, g);
	//}
	//Z ans = 0;
	//for (int a = 0; a <= k; a++) {
	//    for (int b = 0; b <= a; b++) {
	//		std::cerr << a << ' ' << b << ' ' << dp[a][b] << std::endl;
	//        ans += dp[a][b];
	//    }
	//}
	//std::cout << ans << "\n";
//}

//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
	
//    int t;
//    std::cin >> t;
	
//    while (t--) {
//        solve();
//    }
	
//    return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//int mod;

//void solve(){
//	int n, m;
//	cin >> n >> m >> mod;
//	vector<vector<int>>f(m+5, vector<int>(m+5));
//	f[0][0] = 1;
//	for(int i = 1;i <= n;i++){
//		vector<vector<int>>g(m+5, vector<int>(m+5));
//		for(int a = 0;a <= m;a++){
//			for(int b = 0;b <= m;b++){
//				(g[b][max(0ll, b-a)] += f[a][b]) %= mod;
//			}
//		}
//		for(int a = 0;a <= m;a++)
//			for(int b = 1;b <= m;b++){
//				(g[a][b] += g[a][b-1]) %= mod;
//			}
//		swap(f, g);
//	}
//	int ans = 0;
//	for(int i = 0;i <= m;i++){
//		for(int j = 0;j <= i;j++){
//			(ans += f[i][j]) %= mod;
//		}
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int mod = 999999893;
//int qpow(int a, int b){
//    int ret = 1;
//    while(b){
//        if(b & 1) ret = ret * a % mod;
//        a = a * a % mod;
//        b >>= 1;
//    }
//    return ret;
//}


//void solve(){
//    int n, x, y, z, w;
//    cin >> n;
//    if(n == 1){
//        cout << 0 << endl;
//        return;
//    }else if(n == 2){
//        cout << 1 << endl;
//        return;
//    }
//    y = w = -1;
//    x = -1;
//    z = 0;
//    int q = n-1;
//    if(q&1){
//        (y += qpow(2, (q+1)/2)) %= mod;
//        (x += qpow(2, (q-1)/2)) %= mod;
//        (w += qpow(2, (q+1)/2)) %= mod;
//        (z += qpow(2, (q-1)/2)) %= mod;
//    }else{
//        (x += qpow(2, q/2)) %= mod;
//        (y += qpow(2, q/2)) %= mod;
//        (z += qpow(2, q/2)) %= mod;
//        (w += qpow(2, q/2)) %= mod;
//    }

//    int a1 = ((y*z%mod)-(x*w%mod)+mod)%mod;
//    int a2 = ((2*qpow(z,2)%mod)-qpow(w,2)+mod)%mod;
//    cout << a1*qpow(a2, mod-2)%mod << endl;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//    string s;
//    string ss = "odoo.com";
//    cin >> s;
//    int p = 0;
//    for(int i = 0;i < s.size();i++){
//        if(s[i] == '@'){
//            p = i;
//            break;
//        }
//        if(s[i] < 'a' || s[i] > 'z'){
//            cout << "no\n";
//            return;
//        }
//    }
//    if(p < 2 || p > 4){
//        cout << "no\n";
//        return;
//    }
//    if(p+1 + ss.size() != s.size()){
//        cout << "no\n";
//        return;
//    }
//    for(int i = 0;i < ss.size();i++) if(ss[i] != s[p+1+i]){
//        cout << "no\n";
//        return;
//    }
//    cout << "yes\n";
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//    string s;
//    string ss = "ODOO";
//    cin >> s;
//    int ans = s.size();
//    int d = s.size()-4;
//    for(int i = 0; i + 3 < s.size();i++){
//        int tmp = 0;
//        for(int j = 0;j < 4;j++){
//            tmp += (s[i+j] != ss[j]);
//        }
//        ans = min(ans, tmp+d);
//    }    
//    cout << ans << endl;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//struct node{
//    string name;
//    int w, pos;
//    node() = default;
//    node(string name, int w, int pos) : name(name), w(w), pos(pos) {};
//};


//void solve(){
//    int n, m, q;
//    cin >> n >> m >> q;
//    vector<node>a(n+5);
//    for(int i = 1;i <= n;i++){
//        cin >> a[i].name >> a[i].w >> a[i].pos;
//    }
//    sort(all1(a), [&](const node& e1, const node& e2) -> int {
//        return e1.pos < e2.pos;
//    });

//    vector<int>pos(m+5), die(m+5);
//    for(int i = 1, x;i <= m;i++){
//        cin >> x;
//        cin >> pos[x];
//    }

//    string t;
//    map<string, vector<array<int,3>>>g;
//    for(int i = 1, id, w;i <= q;i++){
//        cin >> id >> t >> w;
//        g[t].push_back({pos[id], id, w});
//    }

//    for(auto &[name, vec] : g){
//        sort(all(vec));
//    }

//    int cnt = 0;
//    for(int i = n;i >= 1;i--) if(a[i].w > 0){
//        for(auto [pos, id, w] : g[a[i].name]) if(pos >= a[i].pos && !die[id]){
//            a[i].w -= w;
//            if(a[i].w <= 0) break;
//            die[id] = 1;
//        }
//        cnt += (a[i].w > 0);
//    }
//    cout << cnt << endl;
//    for(int i = n;i >= 1;i--) if(a[i].w > 0){
//        cout << a[i].name << ' ';
//    }
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n




//void solve(){
//    int n, t;
//    cin >> n >> t;
//    vector<int>a(n+5);
//    int ok = 1;
//    for(int i = 1;i <= n;i++){
//        cin >> a[i];
//        if(a[i] > t) ok = 0;
//    }
//    if(!ok){
//        cout << -1 << endl;
//        return;
//    }

//    auto check = [&](int x) -> int {
//        priority_queue<int, vector<int>, greater<int>>que;
//        for(int i = 1;i <= x;i++){
//            que.push(a[i]);
//        }
//        for(int i = x+1;i <= n;i++){
//            int tmp = que.top();
//            que.pop();
//            tmp += a[i];
//            if(tmp > t) return 0;
//            que.push(tmp);
//        }
//        return 1;
//    };

//    int l = 1, r = n;
//    while(l <= r){
//        int mid = l + r >> 1;
//        if(check(mid)) r = mid - 1;
//        else l = mid + 1;
//    }
//    cout << l << endl;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//    int n;
//    cin >> n;
//    vector<int>a(n), f(n+5);
//    for(int i = 0;i < n;i++) cin >> a[i];
//    sort(all(a));
//    a.erase(unique(all(a)), a.end());
//    n = a.size();
//    if(n == 1){
//        cout << "Alice\n";
//        return;
//    }

//    for(int i = n-1;i >= 1;i--) a[i] -= a[i-1];
//    f[n-1] = 1;
//    for(int i = n-2;i >= 0;i--){
//        if(a[i] > 1) f[i] = 1;
//        else f[i] = (f[i+1] ^ 1);
//    }
//    if(f[0]) cout << "Alice\n";
//    else cout << "Bob\n";
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//int bit(int x){
//    for(int i = 30;i >= 0;i--) if((x>>i)&1) return (1<<i);
//}

//void solve(){
//    int n, k;
//    cin >> n >> k;
//    int p = bit(k);
//    vector<int>a;
//    for(int i = 0;i < 20;i++) if((1<<i) != p) a.push_back(1<<i);
//    a.push_back(k^p);
//    a.push_back(k+1);
//    a.push_back(k+1+p);
//    cout << a.size() << endl;
//    for(auto e : a) cout << e << ' ';
//    cout << endl;
//}		

//signed main(){

//	IO;
//	int t = 1;
//	cin >> t;
//	while(t--) solve();

//	return 0;
//}

//#include <bits/stdc++.h>

//using i64 = long long;

//void solve() {
//    int n;
//    std::cin >> n;
	
//    std::string s;
//    std::cin >> s;
	
//    int l = 0, r = 0;
//    int x = s[0] - '0';
//    int i = 0;
//    for (auto c : s) {
//        if (c - '0' == (x + i % 2 + 2) % 2) {
//            i++;
//            r = std::max(r, i);
//        } else {
//            i--;
//            l = std::min(l, i);
//        }
//    }
//    std::cout << r - l << "\n";
//}

//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
	
//    int t;
//    std::cin >> t;
	
//    while (t--) {
//        solve();
//    }
	
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//#define endl '\n'
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//void solve(){
//	int n;
//	string s;
//	cin >> n >> s;
//	int len = 1;
//	char ls = s[0];
//	int f = 1, l = 0, r = 0, L = 1, R = 1;
//	for(int i = 1;i < n;i++){
//		if(s[i] == ls){
//			if(f){
//				l = r+len;
//				R = max(R, l);
//				l++;
//			}else{
//				r = l-len;
//				L = min(L, r);
//				r--;
//			}
//			f ^= 1;
//			len = 1;
//		}else{
//			len++;
//		}
//		ls = s[i];
//	}
//	if(f){
//		l = r+len;
//		R = max(R, l);
//		l++;
//	}else{
//		r = l-len;
//		L = min(L, r);
//		r--;
//	}
//	cout << R-L+1 << endl;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++){
//		if(a[a[i]] == i) {
//			cout << 2 << endl;
//			return;
//		}
//	}
//	cout << 3 << endl;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//void solve(){
//	string s;
//	cin >> s;
//	int n = s.size();
//	s += '1';
//	int st = n;
//	for(int i = 0; i < n;i++) if(s[i] == '1'){
//		st = i;
//		break;
//	}
//	if(st == n) {
//		cout << 0 << endl;
//		return;
//	}

//	char ls = s[st];
//	int len = 0;
//	int d = 0, ans = 0;
//	for(int i = st;i <= n;i++){
//		if(s[i] == ls){
//			if(s[i] == '1'){
//				len++;
//			}else{
//				d++;
//			}
//		}else{
//			if(s[i] == '0'){
//				d = 1;
//			}else{
//				ans += d * (len+1);
//				len++;
//			}
//		}
//		ls = s[i];
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5);
//	vector<vector<int>>f(n+5, vector<int>(11));
//	int ans = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		ans += a[i];
//	}

//	for(int i = 1;i <= n;i++){
//		for(int j = 0;j <= k;j++) f[i][j] = f[i-1][j];
//		int tmp = 0, mn = a[i];
//		for(int j = 0, p = i;j <= k && p >= 1;j++, p--){
//			if(a[p] >= mn) tmp += a[p] - mn;
//			else{
//				tmp += (i-p) * (mn-a[p]);
//				mn = a[p];
//			}
//			for(int x = 0;x <= k && x+j <= k;x++){
//				f[i][j+x] = max(f[i][j+x], f[p-1][x] + tmp);
//				//if(i == 3 && j+x == 3){
//				//	cerr << j << ' ' << x << ' ' << f[i][j+x] << endl;
//				//}
//			}
//		}
//		//for(int j = 0;j <= k;j++) cerr << f[i][j] << ' ';
//		//cerr << endl;
//	}

//	int mx = 0;
//	for(int j = 0;j <= k;j++) mx = max(mx, f[n][j]);
//	cout << ans - mx << endl;
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5), b(n+5), id(n+5), suf(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++) cin >> b[i];
//	iota(all(id), 0);
//	sort(all1(id), [&](int i, int j) -> int {
//		if(b[i] == b[j]) return (b[i]-a[i]) < (b[j]-a[j]);
//		return b[i] > b[j];
//	});
//	vector<int>ta(n+5), tb(n+5);
//	for(int i = 1;i <= n;i++){
//		ta[i] = a[id[i]];
//		tb[i] = b[id[i]];
//	}
//	a = ta;
//	b = tb;

//	for(int i = n;i >= 1;i--){
//		suf[i] = suf[i+1] + max(0ll, b[i]-a[i]);
//	}
//	if(k == 0){
//		cout << suf[1] << endl;
//		return;
//	}

//	priority_queue<int>que;

//	int sum = 0;
//	for(int i = 1;i <= k;i++){
//		sum += a[i];
//		que.push(a[i]);
//	}
//	int ans = 0;
//	for(int i = k;i <= n;i++){
//		ans = max(ans, suf[i+1] - sum);
//		sum += a[i+1];
//		que.push(a[i+1]);
//		sum -= que.top();
//		que.pop();
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int N = 5010;
//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int p1, t1, p2, t2, h, s;
//	cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
//	if(t1 < t2){
//		swap(p1, p2);
//		swap(t1, t2);
//	}
//	vector<int>f(N, inf);
//	f[0] = 0;

//	int ans = inf;

//	for(int i = 0;i <= h;i++){
//		for(int j = 1;1;j++){
//			int t = j*t2;
//			if(t >= t1) break;
//			int w = i + j*(p2-s);
//			int tmp = f[i] + t;
//			if(w > h){
//				ans = min(ans, tmp);
//				break;
//			}
//			f[w] = min(f[w], tmp);
//		}
//		for(int j = 1;1;j++){
//			int t = j*t1;
//			int c = t/t2;
//			int w = i + j*(p1-s) + c*(p2-s) + s;
//			int tmp = f[i] + t;
//			if(w > h){
//				ans = min(ans, tmp);
//				break;
//			}
//			f[w] = min(f[w], tmp);

//			(t += t2) -= (t % t2);
//			c = t/t2;
//			w = i + j*(p1-s) + c*(p2-s) + s;
//			tmp = f[i] + t;
//			if(w > h){
//				ans = min(ans, tmp);
//				break;
//			}
//			f[w] = min(f[w], tmp);
//		}
//	}
//	ans = min(ans, f[h]);
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int N = 5010;
//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n;
//	cin >> n;
//	vector<int>a(n+5), b(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
//	for(int i = 1;i <= n;i++) cin >> b[i];

//	for(int i = 0;i <= n;i++){
//		int f = 1;
//		for(int j = 1;j+i <= n;j++){
//			if(a[j] > b[j+i]){
//				f = 0;
//				break;
//			}
//		}
//		if(f){
//			cout << i << endl;
//			return;
//		}
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int N = 5010;
//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>a(n+5);
//	for(int i = 1;i <= n;i++) cin >> a[i];
	
//	auto check = [&](int x) -> int {
//		int sum = 0;
//		for(int i = 1;i <= n;i++){
//			sum += max(0ll, x - a[i]);
//		}
//		return sum <= k;
//	};

//	int l = 1, r = 2e12;
//	while(l <= r){
//		int mid = l + r >> 1;
//		if(check(mid)) l = mid + 1;
//		else r = mid - 1;
//	}

//	int ans = r*n - n+1;
//	for(int i = 1;i <= n;i++) {
//		if(a[i] < r){
//			k -= (r-a[i]);
//			a[i] = r;
//		}
//	}
//	for(int i = 1;i <= n;i++) {
//		if(a[i] > r) ans++;
//		else{
//			if(k){
//				ans++;
//				k--;
//			}
//		}
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int N = 5010;
//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n, m, ans = 0;
//	cin >> n >> m;
//	for(int b = 1;b <= m;b++){
//		int b2 = b*b;
//		for(int i = b2;i-b <= n;i += b2){
//			if(i-b > 0) ans++;
//		}
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int N = 5010;
//const int inf = 0x3f3f3f3f3f3f3f3f;

//void solve(){
//	int n;
//	string s;
//	cin >> n >> s;
//	int k = 0;
//	for(auto c : s) k += (c == 'U');
//	if(k & 1) cout << "YES\n";
//	else cout << "NO\n";
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n


//void solve(){
//	int n, m, ans = 0, cnt = 0;
//	cin >> n >> m;
//	if(n > m) swap(n, m);
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			if(gcd(i, j) != 1) continue;
//			int t = min(n/i, m/j);
//			if(i+j > t) break;
//			ans += t / (i+j);
//		}
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
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int N = 2e5 + 10;
//const int mod = 1e9+7;

//int lowbit(int x){
//	return x & -x;
//}
//int fac[N], inv[N];
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
//int dv(int a, int b){
//	return (a - b + mod) % mod;
//}


//void solve(){
//	int n, k;
//	cin >> n >> k;
//	vector<int>b(n+5);
//	for(int i = 1;i <= n;i++) cin >> b[i];
//	for(int i = 1;i <= n;i++){
//		int x = i + lowbit(i);
//		int d = 1;
//		while(x <= n){
//			b[x] = dv(b[x], b[i] * C(d+k-1, d) % mod);
//			x += lowbit(x);
//			d++;
//		}
//		cout << b[i] << ' ';
//	}
//	cout << endl;
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
//#define all(x) (x).begin(), (x).end()
//#define all1(x) (x).begin()+1, (x).begin()+1+n

//const int N = 55;
//const int M = N*N;
//const int inf = 0x3f3f3f3f3f3f3f3f;
//int n, m, s, t;

//struct edge{
//	int v, c, w, ne;
//}e[M<<1];
//int h[N<<1], tot = 1;
//void add(int u, int v, int c, int w){
//	e[++tot] = {v, c, w, h[u]};
//	h[u] = tot;
//	e[++tot] = {u, 0, -w, h[v]};
//	h[v] = tot;
//}

//int mf[N<<1], pre[N<<1], dis[N<<1], vis[N<<1];
//bool bfs(){  //spfa找最小费用增广路
//    for(int i = 1;i <= t;i++){
//        mf[i] = 0, dis[i] = inf;
//    }
//    mf[s] = inf, dis[s] = 0, vis[s] = 1;
//    queue<int>q;
//    q.push(s);
//    while(q.size()){
//        int u = q.front();
//        q.pop();
//        vis[u] = 0;
//        for(int i = h[u];i;i = e[i].ne){
//            auto [v, c, w, ne] = e[i];
//            if(dis[v] > dis[u] + w && c){
//                dis[v] = dis[u] + w;
//                mf[v] = min(mf[u], c);
//                pre[v] = i;
//                if(!vis[v]){
//                    q.push(v);
//                    vis[v] = 1;
//                }
//            }
//        }
//    }
//    return mf[t] > 0;
//}

//pair<int,int> EK(){
//    int cost = 0, flow = 0;
//    while(bfs()){
//        for(int v = t;v != s;){
//            int i = pre[v];
//            e[i].c -= mf[t];
//            e[i^1].c += mf[t];
//            v = e[i^1].v;
//        }
//        flow += mf[t];
//        cost += mf[t] * dis[t];
//    }
//    return {flow, cost};
//}

//int mp[N][N];
//int a[N], b[N];

//void solve(){
//    cin >> n >> m; //1-n, n+1 - n+m, s=n+m+1, t=n+m+2
//	s = n+m+1, t = n+m+2;

//	int sw = 0;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			cin >> mp[i][j];
//			sw += mp[i][j];
//		}
//	}

//	int sum = 0;
//	for(int i = 1;i <= n;i++){
//		cin >> a[i];
//		sum += a[i];
//	}
//	for(int i = 1;i <= m;i++) cin >> b[i];

//	for(int i = 1;i <= n;i++) add(s, i, a[i], 0);
//	for(int i = 1;i <= m;i++) add(n+i, t, b[i], 0);
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			int w = (mp[i][j] ? -1 : 1);
//			add(i, n+j, 1, w);
//		}
//	}

//    auto ans = EK();

//	//cerr << ans.first << ' ' << ans.second << endl;
//	cout << (ans.first == sum ? sw+ans.second : -1) << endl;
//}

//signed main(){

//	IO;
//	int t = 1;
//	//cin >> t;
//	while(t--) solve();

//	return 0;
//}