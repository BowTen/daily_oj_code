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




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// const int N = 2e5 + 10;
// int n;

// void solve(){
//     string s;
//     cin >> s;
//     n = s.size() / 2;
//     set<char>st;
//     for(int i = 0;i < n;i++) st.insert(s[i]);
//     if(st.size() >= 2){
//         cout << "YES\n";
//     }else{
//         cout << "NO\n";
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
// #define all(a) a.begin(), a.end()
// const int N = 2e5 + 10;
// int n, k, a[N], pre[N];

// void solve(){
//     cin >> n >> k;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     sort(a + 1, a + 1 + n);
//     for(int i = 1;i <= n;i++)
//         pre[i] = pre[i - 1] + a[i];
//     for(int i = 0;i <= k;i++){
//         ans = max(ans, pre[n - (k - i)] - pre[2 * i]);
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
// #define all(a) a.begin(), a.end()
// const int N = 3e5 + 10;
// int n;

// void solve(){
//     cin >> n;
//     vector<int>a;
//     for(int i = 1, t;i <= n;i++){
//         cin >> t;
//         if(a.empty() || t != a.back()) a.push_back(t);
//     }
//     if(a.size() == 1) {
//         cout << "1\n";
//         return;
//     }
//     int ans = 2;
//     for(int i = 1;i < a.size() - 1;i++){
//         if(a[i] < a[i - 1] && a[i] < a[i + 1]) ans++;
//         if(a[i] > a[i - 1] && a[i] > a[i + 1]) ans++;
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
// #define all(a) a.begin(), a.end()
// const int N = 1000 + 10;
// int n, q, k;

// void solve(){
//     cin >> n >> q;
//     vector<int>a(n + 1);
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//     }
//     sort(all(a));
//     while(q--){
//         cin >> k;
//         if(n == 1){
//             if(k & 1){
//                 cout << 1 + a[1] + k / 2 << ' ';
//             }else{
//                 cout << a[1] - k / 2 << ' ';
//             }
//             continue;
//         }
//         vector<int>b(a);
//         if(k <= n){
//             for(int i = 1;i <= k;i++){
//                 b[i] += k - i + 1;
//             }
//             int mn = b[1];
//             for(int i = 1;i <= n;i++){
//                 mn = min(mn, b[i]);
//             }
//             cout << mn << ' ';
//         }else{  
//             if((k - n) & 1){
//                 for(int i = 1;i < n;i++){
//                     b[i] += k - i + 1;
//                 }
//                 k -= (n - 1);
//                 k /= 2;
//             }else{
//                 for(int i = 1;i <= n;i++){
//                     b[i] += k - i + 1;
//                 }
//                 k -= n;
//                 k /= 2;
//             }
//             int mn = b[1];
//             for(int i = 1;i <= n;i++) mn = min(mn, b[i]);
//             for(int i = 1;i <= n;i++){
//                 k -= min(b[i] - mn, k);
//             }
//             if(k > 0){
//                 if(k % n) mn--;
//                 mn -= k / n;
//             }
//             cout << mn << ' ';
//         }
//     }
// }

// signed main(){

//     IO;
//     int t = 1;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// const int N = 2e5 + 10;
// int n, q, k;

// void solve(){
//     string s;
//     cin >> s;
//     map<char, int>mp;
//     for(auto c : s) mp[c]++;

//     if(mp.size() == 1){
//         cout << "-1\n";
//         return;
//     }
//     if(mp.size() > 2){
//         cout << "4\n";
//         return;
//     }
//     if(mp.begin()->second == 3 || mp.begin()->second == 1){
//         cout << "6\n";
//         return;
//     }
//     cout << "4\n";

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
// #define all(a) a.begin(), a.end()
// const int N = 2e5 + 10;
// int n, q, k;


// void solve(){
//     cin >> n;
//     int qr = sqrt(n);
//     if(qr * qr < n) qr++;
//     cout << qr - 1 << endl;
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
// #define all(a) a.begin(), a.end()
// const int N = 2e5 + 10;
// int n, q, k, a[40];

// int val(int x){
//     return (x * (x + 1)) / 2;
// }

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++){
//         a[i] = -1000;
//     }
//     int l = 1, r = n;
//     while(l <= r){
//         int mid = l + r >> 1;
//         if(val(mid) < k) l = mid + 1;
//         else r = mid - 1;
//     }
//     for(int i = max(1ll, l - 3);i <= l + 3;i++){
//         if(val(i) > k){
//             l = i - 1;
//             break;
//         }
//     }
//     for(int i = 1;i <= l;i++) a[i] = 2;
//     k -= val(l);
//     a[l + 1] = (l - k) * -2 - 1;
//     for(int i = 1;i <= n;i++) cout << a[i] << ' ';
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
// #define all(a) a.begin(), a.end()
// const int N = 3e5 + 10;
// int n, q, k, pre1[N], suf0[N];

// void solve(){
//     string s;
//     cin >> s;
//     n = s.size();
//     s = ' ' + s;
//     pre1[0] = 0;
//     suf0[n + 1] = 0;
//     for(int i = 1;i <= n;i++){
//         pre1[i] = pre1[i - 1];
//         if(s[i] == '1') pre1[i]++;
//     }   
//     for(int i = n;i >= 0;i--){
//         suf0[i] = suf0[i + 1];
//         if(s[i] == '0') suf0[i]++;
//     }
//     int ans = 1e18;
//     for(int i = 0;i <= n;i++){
//         int tmp = (pre1[i] + suf0[i + 1]) * (1e12 + 1);
//         if(i && i != n && s[i] == '1' && s[i + 1] == '0') tmp -= 2e12 + 2, tmp += 1e12;
//         ans = min(ans, tmp);
//     }

//     // for(int i = 1;i <= n;i++) cerr << pre1[i] << ' ';
//     // cerr << endl;
//     // for(int i = 1;i <= n;i++) cerr << suf0[i] << ' ';
//     // cerr << endl;

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
// #define all(a) a.begin(), a.end()
// const int N = 3e5 + 10;
// int n, k;

// string tp;

// void solve(){
//     cin >> k;
//     string s;
//     cin >> s;
//     for(int i = 0;i + k <= n;i++){
//         if(equal(tp.begin() + i, tp.begin() + i + k, s.begin())){
//             cout << "YES\n";
//             return;
//         }
//     }
//     cout << "NO\n";
// }

// signed main(){

//     IO;
    
//     for(int i = 3;i <= 30;i++){
//         if(i % 3 == 0) tp.push_back('F');
//         if(i % 5 == 0) tp.push_back('B');
//     }
//     tp += tp;
//     n = tp.size();
//     // cerr << tp << endl;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     // string tmp = "B";
//     // if(equal(tp.begin() + 1, tp.begin() + 1 + 1, tmp.begin())) cout << "YYYY\n";

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// const int N = 3e5 + 10;
// int n, k;

// void solve(){
//     string a, b;
//     cin >> a >> b;
//     if(a.front() == b.front()){
//         cout << "YES\n";
//         cout << a.front() << "*\n";
//             return;
//     }
//     if(a.back() == b.back()){
//         cout << "YES\n";
//         cout << '*' << a.back() << endl;
//             return;
//     }

//     for(int i = 0; i < a.size() - 1;i++){
//         for(int j = 0;j < b.size() - 1;j++) if(a[i] == b[j] && a[i+1] == b[j+1]){
//             cout << "YES\n";
//             cout << '*' << a[i] << a[i + 1] << "*\n";
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// const int N = 3e5 + 10;
// int n, k, l, r;

// void solve(){
//     cin >> l >> r;
//     int cnt = 0, tmp = r;
//     while(tmp >= l){
//         tmp >>= 1;
//         cnt++;
//     }
//     cout << cnt << ' ';

//     int ans = 0;
//     tmp = r;
//     for(int i = 1;i < cnt;i++) tmp >>= 1;
//     ans = max(0ll, tmp - l + 1);

//     tmp = r;
//     for(int i = 1;i < cnt - 1;i++) tmp >>= 1;
//     tmp /= 3;
//     ans += (cnt - 1) * max(0ll, tmp - l + 1);
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
// #define all(a) a.begin(), a.end()
// const int N = 1e6 + 10;
// const int mod = 19930726;
// int n, k, p[N], pw[N];

// int qpow(int a, int x){
//     int ret = 1;
//     while(x){
//         if(x & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         x >>= 1;
//     }
//     return ret;
// }

// void solve(){
//     cin >> n >> k;
//     pw[0] = 1;
//     for(int i = 1;i <= n;i++){
//         pw[i] = pw[i - 1] * i % mod;
//     }
//     string s;
//     cin >> s;
//     s = '!' + s + '@';
//     int R = 0, mid = 0;
//     int ans = 1;
//     for(int i = 1;i <= n;i++){
//         p[i] = R > i ? min(p[2 * mid - i], R - i) : 0;
//         while(s[i + p[i] + 1] == s[i - p[i] - 1]) p[i]++;
//         if(i + p[i] > R){
//             R = i + p[i];
//             mid = i;
//         }
//     }
//     sort(p + 1, p + 1 + n, greater<int>());
//     int len = 0, num = p[1];
//     for(int i = 1;i <= n;i++){
//         if(p[i + 1] != p[1] || i == n){
//             len = i;
//             break;
//         }
//     }
//     while(k && num > 0){
//         // cerr << k << ' ' << len << ' ' << num << endl;
//         ans = ans * qpow(num * 2 + 1, min(len, k)) % mod;
//         k -= min(len, k);
//         num --;
//         while(len < n && p[len + 1] == num) len++;
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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// const int N = 1e7 + 10;
// int n, k, p[N];

// void solve(){
//     string str, s;
//     cin >> str;
//     n = str.size();
//     s.reserve(2 * n + 4);
//     s.push_back('^');
//     for(int i = 0;i < n;i++){
//         s.push_back('*');
//         s.push_back(str[i]);
//     }
//     s.push_back('*');
//     s.push_back('@');
//     n = s.size() - 2;
//     int R = 0, mid = 0;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         p[i] = R > i ? min(R - i, p[2 * mid - i]) : 0;
//         while(s[i + p[i] + 1] == s[i - p[i] - 1]) p[i]++;
//         if(i + p[i] > R){
//             R = i + p[i];
//             mid = i;
//         }
//         ans = max(p[i], ans);
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
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, k, a[N], x, dp[N][22];

// void solve(){
//     cin >> n >> k >> x;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         a[i] -= x;
//     }
//     x *= 2;

//     dp[1][0] = a[1];
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         dp[i][0] = a[i] + max(0ll, dp[i - 1][0]);
//         if(n - i >= k) ans = max(ans, dp[i][0]);
//         for(int j = 1;j <= k && j <= i;j++){
//             dp[i][j] = a[i] + x + max(0ll, dp[i-1][j-1]);
//             if(i-1 >= j) dp[i][j] = max(dp[i][j], a[i] + max(dp[i-1][j], 0ll));
//             if(n - i >= k - j) ans = max(ans, dp[i][j]);
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n;

// void solve(){
//     cin >> n;
//     int sum = 0;
//     for(int i = 1, t;i < n;i++){
//         cin >> t;
//         sum += t;
//     }
//     cout << -sum << endl;
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
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, p;

// void solve(){
//     cin >> n >> p;
//     vector<array<int, 2>>vec(n + 1);
//     for(int i = 1;i <= n;i++) cin >> vec[i][1];
//     for(int i = 1;i <= n;i++) cin >> vec[i][0];
//     vec[0] = {p, N};
//     sort(vec.begin(), vec.end(), [](const array<int,2>&a1, const array<int,2>& a2)->int{
//         if(a1[0] == a2[0]) return a1[1] > a2[1];
//         return a1[0] < a2[0];
//     });
//     if(vec[0][0] == p){
//         cout << p * n << endl;
//         return;
//     }
//     int ans = p;
//     n--;
//     int pos = 0;
//     int cnt = 0;
//     while(n){
//         if(vec[pos][0] == p){
//             ans += p * n;
//             break;
//         }
//         int d = min(n, vec[pos][1]);
//         n -= d;
//         ans += d * vec[pos][0];
//         pos++;
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
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, m, k;

// void solve(){
//     cin >> n >> m >> k;
//     if(k == 1){
//         cout << "1\n";
//         return;
//     }
//     else if(k == 2){
//         int ans = min(n, m);
//         ans += max(0ll, m - n) / n; 
//         cout << ans << endl;
//         return;
//     }else if(k == 3){
//         int d = max(0ll, m - n);
//         int ans = d % n;
//         d /= n;
//         ans += d * (n - 1);
//         cout << ans << endl;
//         return;
//     }   
//     cout << 0 << endl;
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
// using ll=long long;
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 1e5 + 10;
// const int mod = 998244353;
// int n, m;

// ll pw[N];
// array<int, 2>a[N];
// bool vis[N];
// int cnt[N];

// void solve(){
//     pw[0] = 1;
//     for(int i = 1;i < N;i++){
//         pw[i] = (pw[i - 1] << 1) % mod; 
//     }
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i][0], a[i][1] = i;
//     sort(a + 1, a + 1 + n, greater<array<int, 2>>());
//     for(int i = 1;i <= n;i++){
//         int sq = sqrt(a[i][1]);
//         for(int j = 1;j <= sq;j++) {
//             if(a[i][1] % j == 0){
//                 if(!vis[j]) cnt[a[i][0]]++;
//                 vis[j] = 1;
//                 if(a[i][1] % (a[i][1] / j) == 0){
//                     if(!vis[a[i][1] / j]) cnt[a[i][0]]++;
//                     vis[a[i][1] / j] = 1;
//                 }
//             }
//         }
//     }

//     int q = 1;
//     for(int p = 1;p <= n;p++){
//         if(a[p][0] != a[p-1][0]) a[q++][0] = a[p][0];
//     }
//     q--;

//     int p = n - 1;
//     ll ans = 0;
//     set<int>ss;
//     for(int i = 1;i <= q;i++){
//         int d = cnt[a[i][0]];
//         while(d--){
//             ans = (ans + (pw[p] * a[i][0] % mod)) % mod;
//             --p;
//         }
//     }   
//     cout << ans << endl;
// }   

// signed main(){

//     IO;
    
//     int t = 1;
//     while(t--) solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long;
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 998244353;
// int n, m;

// unordered_map<bitset<26>, int>mp[2][26];

// void solve(){
//     cin >> n;
//     string s;
//     for(int i = 1;i <= n;i++){
//         cin >> s;
//         bitset<26>st;
//         bitset<26>bst;
//         int id = s.size() & 1;
//         for(auto e : s){
//             st[e - 'a'] = 1;
//             bst[e - 'a'] = ~bst[e - 'a'];
//         }
//         for(int i = 0;i < 26;i++) if(!st[i]) {
//             mp[id][i][bst]++;
//         }
//     }

//     int ans = 0;
//     bitset<26>ac((1<<27)-1);
//     for(int i = 0;i < 26;i++){
//         for(const auto& [s, sum] : mp[1][i]){
//             bitset<26>nd(ac);
//             nd[i] = 0;
//             nd ^= s;
//             ans += mp[0][i][nd] * sum;
//         }
//     }
//     cout << ans << endl;
// }   

// signed main(){

//     IO;
    
//     int t = 1;
//     while(t--) solve();

//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 998244353;
// int n, m;


// void solve(){
//     cin >> n;
//     if(n <= 6){
//         cout << "NO\n";
//         return;
//     }
//     if(n == 9){
//         cout << "NO\n";
//         return;
//     }
//     if(n == 8){
//         cout << "YES\n";
//         cout << "1 2 5\n";
//         return;
//     }
//     if(n == 7){
//         cout << "YES\n";
//         cout << "1 2 4\n";
//         return;
//     }

//     cout << "YES\n";
//     if(n % 3){
//         cout << "1 2 " << n - 3 << endl;
//     }else{
//         cout << "1 4 " << n - 5 << endl;
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
// using ll=long long;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 998244353;
// int n, m, x[4], y[4];
// double d[4][4];

// double dis(int a, int b){
//     return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
// }

// bool check(double x){
//     if(d[1][0] <= x && d[1][3] <= x) return true;
//     if(d[2][0] <= x && d[2][3] <= x) return true;
//     if(d[1][2] > 2*x) return false;

//     if(d[1][0] <= x && d[2][3] <= x) return true;
//     if(d[2][0] <= x && d[1][3] <= x) return true;
//     return false;
// }

// void solve(){
//     for(int i = 0;i < 3;i++){
//         cin >> x[i] >> y[i];
//     }
//     for(int i = 0;i < 4;i++){
//         for(int j = 0;j < 4;j++){
//             d[i][j] = dis(i, j);
//         }
//     }
//     double l = 0, r = 1e6;
//     int cnt = 200;
//     while(cnt--){
//         double mid = (l + r) / 2.0;
//         if(check(mid)) r = mid;
//         else l = mid;
//     }
//     cout << fixed << setprecision(10);
//     cout << l << endl;
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
// using ll=long long;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 998244353;
// int n, pos;


// void solve(){
//     string s;
//     cin >> s >> pos;
//     n = s.size();
//     s = (char)0 + s;
//     s.push_back(0);

//     vector<int>ans(n + 1);
//     ans[0] = 1;
//     int tot = 0;
//     list<int>ls(n + 2);
//     iota(ls.begin(), ls.end(), 0);
//     auto q = ls.begin(), p = next(ls.begin());
//     while(p != ls.end()){
//         while(s[*q] > s[*p]){
//             ans[*q] = ++tot;
//             ls.erase(q);
//             q = prev(p);
//         }
//         p++;
//         q = prev(p);
//     }

//     int l = 0, sum = n;
//     while(pos > sum){
//         pos -= sum;
//         sum--;
//         l++;
//     }
//     string ss = " ";
//     for(int i = 1;i <= n;i++){
//         if(ans[i] > l) ss.push_back(s[i]);
//     }
//     cout << ss[pos];
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
// using ll=long long;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(a) a.begin(), a.end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int mod = 998244353;
// int n, w[N], tot;

// vector<int>g[N];

// int siz[N], dep[N], son[N], top[N], par[N], id, idx[N], tr_data[N];
// void dfs1(int u, int f){
//     dep[u] = dep[f] + 1;
//     siz[u] = 1;
//     par[u] = f;
//     for(auto v : g[u]) if(v != f){
//         dfs1(v, u);
//         siz[u] += siz[v];
//         if(siz[son[u]] < siz[v]) son[u] = v;
//     }
// }
// void dfs2(int u, int tp){
//     top[u] = tp;
//     idx[u] = ++id;
//     tr_data[id] = w[u];
//     if(son[u]) dfs2(son[u], tp);
//     else return;

//     for(auto v : g[u]) if(v != son[u] && v != par[u]){
//         dfs2(v, v);
//     }
// }
// int lca(int u, int v){
//     while(top[u] != top[v]){
//         if(dep[top[u]] < dep[top[v]]) swap(u, v);
//         u = par[top[u]];
//     }
//     return (dep[v] < dep[u] ? v : u);
// }

// struct node{
//     int pre, suf, mx, sum;
//     int nep, nes, mn;

//     node() : pre(0), suf(0), mx(0), sum(0), nep(0), nes(0), mn(0) {};

//     void reverse(){
//         swap(pre, suf);
//         swap(nep, nes);
//     }
//     void assgin(int x){
//         nep = nes = mn = pre = suf = mx = sum = x;
//     }
// }tr[N << 2];
// node merg(const node& e1, const node& e2){
//     if(e1.mn == 0) return e2;
//     if(e2.mn == 0) return e1;
//     node ret;
//     ret.sum  = e1.sum + e2.sum;
//     ret.mx = max({e1.mx, e2.mx, e1.suf + e2.pre});
//     ret.pre = max(e1.pre, e1.sum + e2.pre);
//     ret.suf = max(e2.suf, e2.sum + e1.suf);

//     ret.mn = min({e1.mn, e2.mn, e1.nes + e2.nep});
//     ret.nep = min(e1.nep, e1.sum + e2.nep);
//     ret.nes = min(e2.nes, e2.sum + e1.nes);
//     return ret;
// }
// node operator+(const node& e1, const node& e2){
//     if(e1.mn == 0) return e2;
//     if(e2.mn == 0) return e1;
//     node ret;
//     ret.sum  = e1.sum + e2.sum;
//     ret.mx = max({e1.mx, e2.mx, e1.suf + e2.pre});
//     ret.pre = max(e1.pre, e1.sum + e2.pre);
//     ret.suf = max(e2.suf, e2.sum + e1.suf);

//     ret.mn = min({e1.mn, e2.mn, e1.nes + e2.nep});
//     ret.nep = min(e1.nep, e1.sum + e2.nep);
//     ret.nes = min(e2.nes, e2.sum + e1.nes);
//     return ret;
// }
// void up(int id){
//     tr[id] = merg(tr[lson], tr[rson]);
// }
// void build(int id, int l, int r){
//     if(l == r){
//         tr[id].assgin(tr_data[l]);
//         return;
//     }
//     int mid = l + r >> 1;
//     build(lson, l, mid);
//     build(rson, mid + 1, r);
//     up(id);
// }
// node query(int id, int l, int r, int ql, int qr){
//     if(ql <= l && r <= qr) return tr[id];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(lson, l, mid, ql, qr);
//     else if(ql > mid) return query(rson, mid + 1, r, ql, qr);
//     else return merg(query(lson, l, mid, ql, qr), query(rson, mid + 1, r, ql, qr));
// }

// node line_query(int u, int v){
//     node L, R;  
//     while(top[u] != top[v]){
//         if(dep[top[u]] > dep[top[v]]){
//             node tmp = query(1, 1, tot, idx[top[u]], idx[u]);
//             tmp.reverse();
//             L = merg(L, tmp);
//             u = par[top[u]];
//         }else{
//             R = merg(query(1, 1, tot, idx[top[v]], idx[v]), R);
//             v = par[top[v]];            
//         }
//     }
//     if(dep[u] > dep[v]){
//         node tmp = query(1, 1, tot, idx[v], idx[u]);
//         tmp.reverse();
//         L = merg(L, tmp);
//     }else{
//         R = merg(query(1, 1, tot, idx[u], idx[v]), R);
//     }
//     L = merg(L, R);
//     return L;
// }
// // node rev(node e){
// //     swap(e.pre, e.suf);
// //     swap(e.nep, e.nes);
// //     return e;
// // }

// // node line_query(int u, int v)
// // {
// //     node L, R;
// //     while (top[u] != top[v])
// //     {
// //         if (dep[top[u]] > dep[top[v]])
// //         {
// //             L = L + rev(query(1, 1, tot, idx[top[u]], idx[u]));
// //             u = par[top[u]];
// //         }
// //         else
// //         {
// //             R = query(1, 1, tot, idx[top[v]], idx[v]) + R;
// //             v = par[top[v]];
// //         }
// //     }
// //     if (dep[u] < dep[v])
// //         R = query(1, 1, tot, idx[u], idx[v]) + R;
// //     else
// //         L = L + rev(query(1, 1, tot, idx[v], idx[u]));
// //     return (L + R);
// // }

// void init(){
//     for(int i = 1;i <= tot;i++){
//         son[i] = 0;
//         g[i].clear();
//     }
//     id = tot = 0;
// }

// void solve(){
//     cin >> n;
//     string s;
//     vector<array<int, 3>>que;
//     que.reserve(n + 1);
//     w[++tot] = 1;
//     for(int i = 1, a, b, x;i <= n;i++){
//         cin >> s;
//         if(s[0] == '+'){
//             cin >> a >> x;
//             w[++tot] = x;
//             g[a].push_back(tot);
//             g[tot].push_back(a);
//         }else{
//             cin >> a >> b >> x;
//             que.push_back({a, b, x});
//         }
//     }

//     dfs1(1, 0);
//     dfs2(1, 1);
//     build(1, 1, tot);

//     for(auto [u, v, x] : que){
//         if(x > 0){
//             int mx = line_query(u, v).mx;
//             cout << (mx >= x ? "YES\n" : "NO\n");
//         }else if(x < 0){
//             int mn = line_query(u, v).mn;
//             cout << (mn <= x ? "YES\n" : "NO\n");
//         }else{
//             cout << "YES\n";
//         }
//     }
//     init();
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
// #define end '\n'
// const int N = 1e5 + 10;
// int n, m, a[N];
// int siz[N], sum[N], fa[N], son[N];
// struct node{
//     int id;
//     node(int x = 0) : id(x) {};
//     signed operator<(const node& e) const {
//         if(siz[id] == siz[e.id]) return id < e.id;
//         return siz[id] > siz[e.id];
//     }
//     signed operator==(const node& e) const {
//         return id == e.id;
//     }
//     signed operator>(const node& e) const {
//         if(siz[id] == siz[e.id]) return id > e.id;
//         return siz[id] < siz[e.id];
//     }
// };
// set<node>g[N];
// vector<int>vec[N];

// void dfs(int u, int f){
//     siz[u] = 1;
//     sum[u] = a[u];
//     fa[u] = f;
//     for(auto v : vec[u]) if(v != f){
//         dfs(v, u);
//         g[u].insert(v);
//         sum[u] += sum[v];
//         siz[u] += siz[v];
//     }
//     if(g[u].size()) son[u] = g[u].begin()->id;
// }


// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         vec[u].push_back(v);
//         vec[v].push_back(u);
//     }

//     dfs(1, 0);

//     int t, x;
//     while(m--){
//         cin >> t >> x;
//         if(t == 1){
//             cout << sum[x] << endl;
//         }else{
//             if(g[x].size() == 0) continue;
//             int v = son[x];
//             int f = fa[x];
//             g[f].erase(x);
//             g[x].erase(v);
//             fa[v] = f;
//             fa[x] = v;            
//             swap(sum[v], sum[x]);
//             swap(siz[v], siz[x]);
//             sum[x] = sum[v] - sum[x];
//             siz[x] = siz[v] - siz[x];
//             g[v].insert(x);
//             g[f].insert(v);
//             son[f] = g[f].begin()->id;
//             son[v] = g[v].begin()->id;
//             if(g[x].size()) son[x] = g[x].begin()->id;
//             else son[x] = 0;
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
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 110;
// int n, c[2];

// int dp[N][10000];

// void solve(){
//     string s;
//     cin >> s;
//     for(auto e : s) c[e - '0']++;
//     n = s.size();
//     // s = ' ' + s;
//     int need = ((n*(n-1))/2 - (c[0]*(c[0]-1))/2 + (c[1]*(c[1]-1))/2) / 2;
//     memset(dp, 0x3f, sizeof(dp));
//     dp[0][0] = 0;
//     for(int i = 0;i < n;i++){
//         for(int j = c[1];j >= 1;j--){
//             for(int k = i;k <= need;k++){
//                 dp[j][k] = min(dp[j-1][k-i] + (s[i] != '1'), dp[j][k]);
//             }
//         }
//     }
//     cout << dp[c[1]][need] << endl;
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
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     string a, b;
//     cin >> n >> m;
//     cin >> a >> b;
//     a = a + a + a;
//     int tmp = n;
//     for(;n <= m * 3;){
//         a = a + a;
//         n *= 2;
//     }
//     for(int i = 0;i < n;i++){
//         if(a[i] == b[0]){
//             bool f = true;
//             for(int j = 0;j < m;j++){
//                 if(a[i + j] != b[j]){
//                     f = false;
//                     break;
//                 }
//             }
//             if(f){
//                 int ans = i + m;
//                 int cnt = 0;
//                 while(tmp < ans){
//                     cnt++;
//                     tmp *= 2;
//                 }
//                 cout << cnt << endl;
//                 return;
//             }
//         }
//     }
//     cout << "-1\n";
//     // cerr << n << ' ' << m << endl << a << endl << b;
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
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     vector<int>a(3);
//     for(int i = 0;i < 3;i++) cin >> a[i];
//     sort(a.begin(), a.end());
//     int cnt = 0;
//     for(int i = 1;i < 3;i++){
//         if(a[i] == a[0]) continue;
//         if(a[i] % a[0]){
//             cout << "NO\n";
//             return;
//         }
//         cnt += a[i] / a[0] - 1;
//     }
//     if(cnt <= 3) cout << "YES\n";
//     else cout << "NO\n";
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
// const int N = 1e3 + 10;
// int n, m;
// string mp[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> mp[i];
//         mp[i] = ' ' + mp[i];
//     }

//     int ans = 0;
//     for(int i = 1;i <= n / 2;i++){
//         int len = n - (i - 1) * 2;
//         string mn = mp[i];
//         int b = i + len - 1;
//         for(int j = i;j <= b;j++) mn[j] = max(mn[j], mp[j][b]);
//         for(int j = b, q = i;j >= i;j--, q++) mn[q] = max(mn[q], mp[b][j]);
//         for(int j = b, q = i;j >= i;j--, q++) mn[q] = max(mn[q], mp[j][i]);


//         for(int j = i + 1;j <= b;j++) ans += mn[j] - mp[i][j];
//         for(int j = i + 1;j <= b;j++) ans += mn[j] - mp[j][b];
//         for(int j = b - 1, q = i + 1;j >= i;j--, q++) ans += mn[q] - mp[b][j];
//         for(int j = b - 1, q = i + 1;j >= i;j--, q++) ans += mn[q] - mp[j][i];

//         // cerr << mn << endl;
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
// // #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 1e6 + 10;
// const int M = 1e4 + 10;
// int n, m, a[M];

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

// void solve(){
//     cin >> n;
//     unordered_map<int,int>mp;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         for(int j = 1;j <= cnt && a[i] > 1;j++){
//             if(isprime[a[i]]){
//                 mp[a[i]]++;
//                 break;
//             }
//             while(a[i] % prime[j] == 0){
//                 mp[prime[j]]++;
//                 a[i] /= prime[j];
//             }
//         }
//     }
//     for(auto [v, cnt] : mp){
//         if(cnt % n){
//             cout << "NO\n";
//             return;
//         }
//         // cout << v << ' ' << cnt << endl;
//     }
//     cout << "YES\n";
// }

// signed main(){

//     IO;
//     euler();
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
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f;
// int n, m, a[N], dp[N], mn[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];

//     int last = n + 1, lastv = 0;
//     mn[n+1] = 0;
//     dp[n+1] = 0;
//     for(int i = n;i >= 1;i--){
//         if(i + a[i] > n){
//             dp[i] = min(n + 1 - i, mn[i+1] + 2);
//         }else{
//             int p = i + a[i];
//             dp[i] = mn[p];
//         }
//         mn[i] = min(mn[i+1] + 1, dp[i + 1]);
//         dp[i] = min(dp[i], mn[i] + 1);
//     }
//     cout << dp[1] << endl;
//     // for(int i = 1;i <= n;i++){
//     //     cerr << dp[i] << ' ';
//     // }
//     // cerr << endl;
//     // for(int i = 1;i <= n;i++){
//     //     cerr << mn[i] << ' ';
//     // }
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
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f;
// int n, k;
// bool f[N];

// vector<int>g[N];

// int dep[N], mx[N], len = 0;
// void dfs(int u, int fa){
//     dep[u] = dep[fa] + 1;
//     if(f[u]) mx[u] = 0;
//     for(auto v : g[u]) if(v != fa){
//         dfs(v, u);
//         len = max(len, mx[u] + 1 + mx[v]);
//         mx[u] = max(mx[u], mx[v] + 1);
//     }
// }

// void init(){
//     for(int i = 1;i <= n;i++){
//         f[i] = false;
//         g[i].clear();
//         mx[i] = -inf;
//     }
//     len = 0;
// }

// void solve(){
//     cin >> n >> k;
//     init();
//     for(int i = 1, t;i <= k;i++){
//         cin >> t;
//         f[t] = true;
//     }
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);
//     cout << (len + 1) / 2 << endl;
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
// using ll=long long;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e5 + 10;
// int n, p[N];

// mt19937_64 rnd(time(0));
// ll mx_fac;
// vector<int> fac;

// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// ll qpow(ll a, ll b, ll p)
// { // 快速幂
//     ll res = 1;
//     while (b)
//     {
//         if (b & 1)
//             res = (__int128)res * a % p;
//         a = (__int128)a * a % p;
//         b >>= 1;
//     }
//     return res;
// }

// bool Miller_Rabin(ll p)
// { // 判断素数
//     if (p < 2)
//         return 0;
//     if (p == 2)
//         return 1;
//     if (p == 3)
//         return 1;
//     ll d = p - 1, r = 0;
//     while (!(d & 1))
//         ++r, d >>= 1; // 将d处理为奇数
//     for (ll k = 0; k < 10; ++k)
//     {
//         ll a = rnd() % (p - 2) + 2;
//         ll x = qpow(a, d, p);
//         if (x == 1 || x == p - 1)
//             continue;
//         for (int i = 0; i < r - 1; ++i)
//         {
//             x = (__int128)x * x % p;
//             if (x == p - 1)
//                 break;
//         }
//         if (x != p - 1)
//             return 0;
//     }
//     return 1;
// }

// ll Pollard_Rho(ll x)
// {
//     ll s = 0, t = 0;
//     ll c = (ll)rnd() % (x - 1) + 1;
//     int step = 0, goal = 1;
//     ll val = 1;
//     for (goal = 1;; goal *= 2, s = t, val = 1)
//     { // 倍增优化
//         for (step = 1; step <= goal; ++step)
//         {
//             t = ((__int128)t * t + c) % x;
//             val = (__int128)val * abs(t - s) % x;
//             if ((step % 127) == 0)
//             {
//                 ll d = gcd(val, x);
//                 if (d > 1)
//                     return d;
//             }
//         }
//         ll d = gcd(val, x);
//         if (d > 1)
//             return d;
//     }
// }

// void divide_fac(ll x)
// {
//     if (x < 2)
//         return;
//     if (Miller_Rabin(x))
//     {                            // 如果x为质数
//         mx_fac = max(mx_fac, x); // 更新答案
//         fac.push_back(x);
//         return;
//     }
//     ll p = x;
//     while (p >= x)
//         p = Pollard_Rho(x);
//     // 不用求质因子幂次时使用
//     while ((x % p) == 0)
//          x /= p;
//     divide_fac(x), divide_fac(p); // 继续向下分解x和p
// }

// int exgcd(int a, int b, int& x, int& y){
//     if(b == 0) {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     int d = exgcd(b, a % b, y, x);
//     y -= a / b * x;
//     return d;
// }

// void solve(){
//     cin >> n;
//     int lcm = 1;
//     for(int i = 1;i <= n;i++){
//         cin >> p[i];
//         int l1 = lcm / __gcd(lcm, p[i]);
//         lcm = l1 * p[i];
//     }
//     lcm *= 2;
//     divide_fac(lcm);
//     int lc = lcm;
//     for(auto &e : fac){
//         int t = 1;
//         while(lc % e == 0){
//             lc /= e;
//             t *= e;
//         }
//         e = t;
//     }
//     int tmp = 1;
//     for(auto &e : fac){
//         tmp *= e;
//         // cerr << e << endl;
//     }
//     // cerr << lcm << endl;
//     // cerr << tmp << endl;

//     int ans = lcm;
//     for(int i = 0, tp = (1ll << fac.size()) - 1;i <= tp;i++){
//         int a = 1, b = 1;
//         for(int j = 0, len = fac.size();j < len;j++){
//             if((1 << j) & i) a *= fac[j];
//             else b *= fac[j];
//         }
//         int x, y;
//         exgcd(a, b, x, y);
//         if(a*x == 0 || b*y == 0) continue;
//         // cerr << a*x << ' ' << b*y << endl;
//         int d = min(a * x, b * y);
//         if(d < 0) d = -d;
//         ans = min(ans, d);
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
// const int N = 2e5 + 10;
// int n, q;
// vector<int>g[N];

// int sum[N];
// void dfs(int u, int f){
//     bool leaf = true;
//     for(auto v : g[u]) if(v != f){
//         dfs(v, u);
//         leaf = false;
//         sum[u] += sum[v];
//     }
//     if(leaf) sum[u] = 1;
// }

// void init(){
//     for(int i = 1;i <= n;i++){
//         g[i].clear();
//         sum[i] = 0;
//     }
// }

// void solve(){
//     cin >> n;
//     init();
//     for(int i = 1, u, v;i < n;i++){
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);
//     cin >> q;
//     while(q--){
//         int u, v;
//         cin >> u >> v;
//         cout << sum[u] * sum[v] << endl;
//     }
// }

// signed main(){
    
//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits./stdc++.h>
// using namespace std;
// // using ll = long long;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const ll M = N * 25;
// const ll TP = 1e9 + 2;
// int n, d[N];

// vector<array<int, 2>>g[N];

// int sum[N];
// ll rt[N], ls[M], rs[M], id;
// void update(ll &cur, ll pre, ll l, ll r, ll x){
//     cur = ++id;
//     ls[cur] = ls[pre];
//     rs[cur] = rs[pre];
//     sum[cur] = sum[pre] + 1;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     if(x <= mid) update(ls[cur], ls[pre], l, mid, x);
//     else update(rs[cur], rs[pre], mid + 1, r, x);
// }
// int query(ll L, ll R, ll l, ll r, ll ql, ll qr){
//     if(ql <= l && r <= qr) return sum[R] - sum[L];
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls[L], ls[R], l, mid, ql, qr);
//     else if(ql > mid) return query(rs[L], rs[R], mid + 1, r, ql, qr);
//     else return query(ls[L], ls[R], l, mid, ql, qr) + query(rs[L], rs[R], mid + 1, r, ql, qr);
// }

// vector<int>idx;

// ll dep[N];
// int st[N], ed[N], tot, totp[N];
// void dfs(int u, int f){
//     st[u] = ++tot;
//     totp[tot] = u;
//     idx.push_back(dep[u]);
//     // update(rt[tot], rt[tot-1], 1, TP, dep[u]);
//     for(auto [v, w] : g[u]) if(v != f){
//         dep[v] = dep[u] + w;
//         dfs(v, u);
//     }
//     ed[u] = tot;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) {
//         cin >> d[i];
//     }

//     for(int i = 1, u, v, w;i < n;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }
//     dfs(1, 0);
//     for(int i = 1;i <= n;i++){
//         d[i] += dep[i];
//         idx.push_back(d[i]);
//     }
//     sort(idx.begin(), idx.end());
//     idx.erase(unique(idx.begin(), idx.end()), idx.end());
//     for(int i = 1;i <= n;i++){
//         dep[i] = lower_bound(idx.begin(), idx.end(), dep[i]) - idx.begin() + 1;
//         d[i] = lower_bound(idx.begin(), idx.end(), d[i]) - idx.begin() + 1;
//     }
//     for(int i = 1;i <= tot;i++){
//         update(rt[i], rt[i-1], 1, TP, dep[totp[i]]);
//     }

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         ans = max(ans, query(rt[st[i] - 1], rt[ed[i]], 1, TP, dep[i], d[i]));
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



// #include<bits./stdc++.h>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int M = N * 2;
// const int TP = 1e12 + 2;
// int n, d[N], ans;
// vector<array<int, 2>>g[N];

// int tr[N << 1];
// int lwobit(int x){
//     return x & -x;
// }
// void add(int x){
//     while(x < M){
//         tr[x] ++;
//         x += lwobit(x);
//     }   
// }
// int getsum(int x){
//     int ret = 0;
//     while(x > 0){
//         ret += tr[x];
//         x -= lwobit(x);
//     }
//     return ret;
// }

// int dep[N];
// void dfs(int u, int f){
//     for(auto [v, w] : g[u]) if(v != f){
//         dep[v] = dep[u] + w;
//         dfs(v, u);
//     }
// }
// void dfs2(int u, int f){
//     int s1 = getsum(d[u]);
//     add(dep[u]);
//     for(auto [v, w] : g[u]) if(v != f){
//         dfs2(v, u);
//     }
//     int s2 = getsum(d[u]);
//     ans = max(ans, s2 - s1);
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) {
//         cin >> d[i];
//     }

//     for(int i = 1, u, v, w;i < n;i++){
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//     }

//     vector<int>idx;
//     dfs(1, 0);
//     for(int i = 1;i <= n;i++){
//         d[i] += dep[i];
//         idx.push_back(d[i]);
//         idx.push_back(idx[i]);
//     }
//     sort(all(idx));
//     idx.erase(unique(all(idx)), idx.end());
//     M = idx.size() + 10;
//     for(int i = 1;i <= n;i++){
//         dep[i] = lower_bound(all(idx), dep[i]) - idx.begin() + 1;
//         d[i] = lower_bound(all(idx), d[i]) - idx.begin() + 1;
//     }
//     dfs2(1, 0);
//     cout << ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits./stdc++.h>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e3 + 10;
// const int M = N * 30;
// const int TP = 1e9 + 2;
// int n, c;

// struct node{
//     int x, y;
//     int operator<(const node& e) const{
//         if(y == e.y) return x < e.x;
//         return y < e.y;
//     }
// }p[N];

// struct tnode{
//     int mx, tag;
// }tr[M];
// int tot, rt, ls[M], rs[M];
// int getnode(){
//     ++tot;
//     tr[tot].mx = tr[tot].tag = 0;
//     ls[tot] = rs[tot] = 0;
//     return tot;
// }   
// void up(int id){
//     tr[id].mx = max(tr[ls[id]].mx, tr[rs[id]].mx);
// }
// void settag(int id, int v){
//     tr[id].mx += v;
//     tr[id].tag += v;
// }
// void down(int id){
//     if(!ls[id]) ls[id] = getnode();
//     if(!rs[id]) rs[id] = getnode();
//     settag(ls[id], tr[id].tag);
//     settag(rs[id], tr[id].tag);
//     tr[id].tag = 0;
// }
// void modify(int &id, int l, int r, int ql, int qr, int v){
//     if(!id) id = getnode();
//     if(ql <= l && r <= qr){
//         settag(id, v);
//         return;
//     }
//     if(tr[id].tag) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls[id], l, mid, ql, qr, v);
//     else if(ql > mid) modify(rs[id], mid + 1, r, ql, qr, v);
//     else modify(ls[id], l, mid, ql, qr, v), modify(rs[id], mid + 1, r, ql, qr, v);
//     up(id);
// }
// void initree(){
//     tot = 0;
//     rt = 0;
// }

// bool check(int len){
//     initree();
//     int l, r;
//     l = r = len / 2;
//     if(len % 2 == 0) l--;
//     int tp = 1, bt = 1;
//     while(tp <= n){
//         while(p[tp].y - p[bt].y >= len){
//             modify(rt, 1, TP, max(1ll, p[bt].x - l), min(TP, p[bt].x + r), -1);
//             bt++;
//         }
//         modify(rt, 1, TP, max(1ll, p[tp].x - l), min(TP, p[tp].x + r), 1);
//         tp++;
//         if(tr[1].mx >= c) return true;
//     }
//     return false;
// }

// void solve(){
//     cin >> n >> c;
//     for(int i = 1;i <= n;i++){
//         cin >> p[i].x >> p[i].y;
//     }
//     sort(p + 1, p + 1 + n);

//     int l = 1, r = 1e9;
//     while(l <= r){
//         int mid = l + r >> 1;
//         if(check(mid)) r = mid - 1;
//         else l = mid + 1;
//     }
//     cout << l << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits./stdc++.h>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 510;
// const int M = N * 30;
// const int TP = 1e9 + 2;
// const int mod = 998244353;
// int n, dp[N][N];

// void solve(){
//     cin >> n;
//     dp[0][0] = 1;
//     for(int i = 1;i <= n;i++){
//         for(int j = 0;j <= i;j++){
//             for(int k = 1;k <= i;k++){
//                 dp[i][j] = (dp[i][j] + dp[i - k][j ^ k]) % mod;
//             }
//         }
//     }
//     cout << dp[n][0] << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits./stdc++.h>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, x[N];

// void solve(){
//     cin >> n;
//     map<int, vector<int>>mp;
//     for(int i = 1;i <= n;i++){
//         cin >> x[i];
//         mp[x[i]].push_back(i);
//     }
//     int ans = x[1], L = 1, R = 1, len = 1;
//     for(auto [num, vec] : mp){
//         // cerr << num << endl;
//         int cur = 0, l = vec.front(), r = vec.front(), last = r - 1;
//         for(int i = 0, ln = vec.size();i < ln;i++){
//             // cerr << vec[i] << ' ';
//             r = vec[i]; 
//             cur++;
//             cur -= r - last - 1;
//             if(cur <= 0){
//                 cur = 1;
//                 l = r = vec[i];
//             }
//             if(cur > len){
//                 len = cur;
//                 L = l;
//                 R = r;
//                 ans = num;
//             }
//             last = r;
//         }
//         // cerr << endl;
//     }
//     // cerr << endl;
//     // cerr << len << endl;
//     cout << ans << ' ' << L << ' ' << R << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<bits./stdc++.h>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, a[N], k;

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     int ans = 0, last = n + 1;
//     for(int i = n;i >= 1;i--){
//         if(i + k < last) ans++;
//         if(a[i-1] >= a[i] * 2) last = i;
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




// #include<bits./stdc++.h>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, a[N], k;

// void solve(){
//     cin >> n;
//     int sum = 0;
//     for(int i = 1;i <= n;i++){
//         // cin >> a[i];
//         a[i] = i;
//         sum += a[i];
//     }
//     while(sum % n) a[1]++, sum ++;
//     for(int i = 1;i <= n;i++) cout << a[i] << ' ';
//     cout << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits./stdc++.h>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, a[N], k;

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     int ans = -1;
//     for(int i = 1;i <= n;i++){
//         if(a[i] == i) continue;
//         int d = abs(i - a[i]);
//         if(ans == -1){
//             ans = d;
//         }else{
//             ans = __gcd(ans, d);
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





// #include<bits./stdc++.h>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// int n, a[N], b[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];
//     sort(a + 1, a + 1 + n);
//     sort(b + 1, b + 1 + n);
//     for(int i = 1;i <= n;i++){
//         if(a[i] <= b[i]){
//             cout << "0\n";
//             return;
//         }
//     }
//     b[n + 1] = mod;
//     int ans = 1;
//     int p = 1, cur = 0;
//     for(int i = 1;i <= n + 1;i++){
//         while(p <= n && a[p] <= b[i]){
//             // cerr << a[p] << ' ' << i << endl;
//             ans = ans * (i - 1 - cur) % mod;
//             cur++;
//             p++;
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




// #include<bits./stdc++.h>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 30;
// const int mod = 1e9 + 7;
// int n, mp[N][N], m, x, y;
// int op[9][2] = {
//     {0, 0},
//     {2, 1},
//     {2, -1},
//     {-2, 1},
//     {-2, -1},
//     {1, 2},
//     {1, -2},
//     {-1, 2},
//     {-1, -2},
// };

// void solve(){
//     cin >> n >> m >> x >> y;
//     for(int i = 0; i <= 8;i++){
//         int nx = x + op[i][0];
//         int ny = y + op[i][1];
//         if(nx >= 0 && ny >= 0) mp[nx][ny] = -1;
//     }
//     mp[0][0] = 1;
//     for(int i = 0;i <= n;i++){
//         for(int j = 0;j <= m;j++) if(mp[i][j] != -1){
//             if(i > 0) mp[i][j] += max(0ll, mp[i-1][j]); 
//             if(j > 0) mp[i][j] += max(0ll, mp[i][j-1]); 
//         }
//     }
//     cout << mp[n][m];
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<bits./stdc++.h>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 15;
// const int mod = 1e9 + 7;
// int n, mp[N][N], dp[N][N][N][N], m;

// void solve(){
//     cin >> n;
//     m = n * 2 - 2;
//     int x, y, v;
//     while(cin >> x >> y >> v, x){
//         mp[x][y] = v;
//     }
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= n;j++){
//             for(int x = 1;x <= n;x++){
//                 for(int y = 1;y <= n;y++){
//                     dp[i][j][x][y] = max({
//                         dp[i-1][j][x-1][y],
//                         dp[i-1][j][x][y-1],
//                         dp[i][j-1][x-1][y],
//                         dp[i][j-1][x][y-1],
//                         })
//                         + mp[i][j] + mp[x][y];
//                     if(i == x && j == y) dp[i][j][x][y] -= mp[i][j];
//                 }
//             }
//         }
//     }

//     cout << dp[n][n][n][n] << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<iostream>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 210;
// const int mod = 1e9 + 7;
// int n, mp[N][N], dp[N];

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         for(int j = i + 1;j <= n;j++){
//             cin >> mp[i][j];
//             mp[j][i] = mp[i][j];
//         }
//     }

//     for(int i = 2;i <= n;i++){
//         dp[i] = mp[1][i];
//         for(int j = 2;j < i;j++){
//             dp[i] = min(dp[i], dp[j] + mp[j][i]);
//         }
//     }

//     cout << dp[n] << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<iostream>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 40;
// const int mod = 1e9 + 7;
// int n, m, v[N], w[N], dp[N][40000];

// void solve(){
//     cin >> m >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> v[i] >> w[i];
//     }

//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = 0;j <= m;j++){
//             dp[i][j] = dp[i-1][j];
//             if(j + v[i] <= m) dp[i][j] = max(dp[i][j], dp[i-1][j + v[i]] + v[i] * w[i]);
//             ans = max(ans, dp[i][j]);
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




// #include<iostream>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1010;
// const int mod = 1e9 + 7;
// int n, x, los[N], win[N], dp[N], cost[N];

// void solve(){
//     cin >> n >> x;
//     for(int i = 1;i <= n;i++){
//         cin >> los[i] >> win[i] >> cost[i];
//     }
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = x;j >= 0;j--){
//             if(j >= cost[i]) dp[j] = max(dp[j] + los[i], dp[j-cost[i]] + win[i]);
//             else dp[j] += los[i];
//             ans = max(ans, dp[j]);
//         }
//     }
//     cout << ans * 5 << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<iostream>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 40;
// const int mod = 1e9 + 7;
// int n, v, a[N], dp[N][20010];

// void solve(){
//     cin >> v >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = v;j >= 0;j--){
//             if(j >= a[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j - a[i]] + a[i]);
//             else dp[i][j] = dp[i-1][j];
//             ans = max(ans, dp[i][j]);
//         }
//     }
//     cout << v - ans << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }




// #include<iostream>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 110;
// const int mod = 1e9 + 7;
// int t, n, c[N], v[N], f[1010];

// void solve(){
//     cin >> t >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> c[i] >> v[i];
//     }
//     for(int i = 1;i <= n;i++){
//         for(int j = t;j >= c[i];j--){
//             f[j] = max(f[j], f[j - c[i]] + v[i]);
//         }
//     }
//     cout << f[t];
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();

//     return 0;
// }



// #include<iostream>
// #include<vector>
// #include<map>
// #include<unordered_map>
// using namespace std;
// #define int long long
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1010;
// const int mod = 1e9 + 7;
// int m, n;

// struct node{
//     int w, v;
// };
// unordered_map<int, vector<node>>vec;

// int f[N];

// void solve(){
//     cin >> m >> n;
//     for(int i = 1, w, v, x;i <= n;i++){
//         cin >> w >> v >> x;
//         vec[x].push_back({w, v});
//     }

//     for(auto &[id, g] : vec){
//         for(int j = m;j >= 0;j--){
//             for(auto [w, v] : g){
//                 if(j >= w) f[j] = max(f[j], f[j - w] + v);
//             }
//         }
//     }
//     cout << f[m];
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
// #define all(a) a.begin(), a.end()
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1010;
// int n;

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

// int f[N];
// int dfs(int x){
//     // cerr << x << endl;
//     if(f[x]) return x;
//     int ret = isprime[x];
//     for(int i = 1;i <= cnt && prime[i] <= x / 2;i++){
//         // if(x == 7) cerr << prime[i] << endl;

//         if(isprime[x - prime[i]])
//             ret ++;
//         else
//             ret += dfs(x - prime[i]);
//     }
//     if(ret == 0) ret = -1;
//     return f[x] = ret;
// }

// void solve(){
//     euler();
//     cin >> n;
//     f[0] = 1;
//     // cerr << dfs(4);
//     cout << dfs(n) << endl;
//     // for(int i = 1;i <= 7;i++) cerr << i << ' ' << f[i] << endl;
//     // cerr << prime[0] << endl;
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
// const int N = 1e3 + 10;
// int n;

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

// int f[N];

// void solve(){
//     euler();
//     cin >> n;
//     f[0] = 1;
//     for(int i = 1;prime[i] <= n;i++){
//         for(int j = prime[i];j <= n;j++){
//             f[j] += f[j - prime[i]];
//         }
//     }
//     cout << f[n] << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--)solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, a[N];

// void solve(){
//     string s;
//     cin >> s;
//     set<char>st;
//     for(auto c : s) st.insert(c);
//     if(st.size() == 1){
//         cout << "-1\n";
//         return;
//     }
//     cout << s.size() - 1 << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, m;

// void solve(){
//     cin >> n >> m;
//     int t;
//     int mm[2] = {(int)(-1e9), (int)(-1e9)};
//     int nn[2] = {(int)(1e9), (int)(1e9)};
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             cin >> t;
//             nn[1] = min(nn[1], t);
//             mm[1] = max(mm[1], t);
//             if(mm[0] < mm[1]) swap(mm[1], mm[0]);
//             if(nn[0] > nn[1]) swap(nn[1], nn[0]);
//         }
//     }
//     int d[2];
//     d[0] = m * n - n;
//     d[1] = n - 1;
//     if(d[0] < d[1]) swap(d[0], d[1]);
//     int ans1 = (mm[0] - nn[0]) * d[0] + max((mm[1] - nn[0]) * d[1], (mm[0] - nn[1]) * d[1]);
//     d[0] = m * n - m;
//     d[1] = m - 1;
//     if(d[0] < d[1]) swap(d[0], d[1]);
//     int ans2 = (mm[0] - nn[0]) * d[0] + max((mm[1] - nn[0]) * d[1], (mm[0] - nn[1]) * d[1]);
//     // int ans2 = (mm[0] - nn[0]) * d[0] + (mm[0] - nn[1]) * d[1];
//     cout << max(ans2, ans1) << endl;
//     // cerr << mm[0] << ' ' << mm[1] << ' ' << nn[0] << ' ' << nn[1] << endl;
//     // cerr << d[0] << ' ' << d[1];
// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, x[N], m;

// void solve(){
//     cin >> n >> m;
//     vector<int>p;
//     int l = 0, r = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> x[i];
//         if(x[i] > 0) p.push_back(x[i]);
//         else if(x[i] == -2) l++;
//         else r++;
//     }
//     sort(p.begin(), p.end());
//     p.erase(unique(p.begin(), p.end()), p.end());

//     int ans = 0;

//         for(int i = 0, len = p.size();i < len;i++){
//             int d = max(0ll, min(p[i] - 1 - i, r)) + max(0ll, min(m - p[i] - (len - (i + 1)), l));
//             ans = max(ans, d);
//         }
//         ans += p.size();

//         int ans1 = min(m, (int)(p.size() + l));
//         int ans2 = min(m, (int)(p.size() + r));
//         ans = max({ans, ans1, ans2});

//     ans = min(ans, m);
//     cout << ans << endl;

// }

// signed main(){

//     IO;
//     int t = 1;
//     cin >> t;
//     while(t--)solve();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// int n, a[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     // cout << n << ' ';
//     for(int i = 0;i <= n;i++){
//         int s = 0;
//         for(int j = 1;j <= n;j++){
//             if(a[j] > i) s++;
//         }
//         if(s == i){
//             cout << i << endl;
//             return;
//         }
//     }
//     cout << "-1\n";
//     // cout << endl;
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
// int n, a[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     int q = n / 2, p = n / 2 + 1;
//     if(n & 1) q++;
//     int ans = 0;
//     while(q >= 1){
//         if(a[q] != a[p]){
//             int d = abs(a[p] - a[q]);
//             if(ans == 0) ans = d;
//             else ans = __gcd(ans, d);
//         }
//         q--, p++;
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
// int n, m;


// void solve(){
//     cin >> n >> m;
//     if(n == 1 || m == 1){
//         cout << "YES\n";
//         return;
//     }
//     if(n <= m || n % m == 0){
//         cout << "NO\n";
//         return;
//     }
//     int sq = sqrt(n);
//     for(int i = 2;i <= sq;i++){
//         if(n % i == 0){
//             if(i <= m) cout << "NO\n";
//             else cout << "YES\n";
//             return;
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
// int n, m, a[N], mx[N][20], mx2[N][20], Log[N];


// void solve(){
//     cin >> n;
//     vector<array<int, 2>>vec;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         mx[i][0] = a[i] + i;
//         mx2[i][0] = a[i] - i;
//     }

//     for(int j = 1;j < 20 ;j++){
//         for(int i = 1;i <= n && i + (1 << j) - 1 <= n;i++){
//             mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
//             mx2[i][j] = max(mx2[i][j - 1], mx2[i + (1 << (j - 1))][j - 1]);
//         }
//     }
//     for(int i = 2;i <= n;i++){  //预处理对数
//         Log[i] = Log[i / 2] + 1;
//     }
//     int ans = 0;
//     for(int i = 2;i < n;i++){
//         int l = 1, r = i - 1;
//         int s = Log[r - l + 1];
//         int pre = max(mx[l][s], mx[r - (1 << s) + 1][s]);
//         l = i + 1, r = n;
//         s = Log[r - l + 1];
//         int suf = max(mx2[l][s], mx2[r - (1 << s) + 1][s]);
//         ans = max(ans, a[i] + pre + suf);
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
// int n, m, a[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     if(a[n] == 1) {
//         cout << "NO\n";
//         return;
//     }
//     cout << "YES\n";

//     vector<int>vec[2];
//     int id = 0;
//     int cur = 1;
//     for(int i = n - 1;i >= 1;i--){
//         if(a[i] != a[i + 1]){
//             vec[id].push_back(cur);
//             cur = 0;
//             id ^= 1;
//         }
//         cur++;
//     }
//     vec[id].push_back(cur);

//     int len = min(vec[0].size(), vec[1].size());
//     for(int i = 0;i < len;i++){
//         for(int j = 1;j < vec[0][i];j++) cout << 0 << ' ';
//         for(int j = 1;j <= vec[1][i];j++) cout << 0 << ' ';
//         cout << vec[1][i] << ' ';
//     }
//     if(vec[0].size() > len) while(vec[0][len] --) cout << 0 << ' ';
//     cout << endl;
//     // cerr << vec[0].size() << ' ' << vec[1].size() << endl;
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
// int n, m, a[N];


// void solve(){
//     cin >> n >> m;
//     for(int i = 0;i <= n;i++){
//         int d = n - i;
//         if(i * (i - 1) / 2 + d * (d - 1) / 2 == m){
//             cout << "YES\n";
//             for(int j = 1;j <= i;j++) cout << -1 << ' ';
//             for(int j = i + 1;j <= n;j++) cout << 1 << ' ';
//             cout << endl;
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
// const int N = 2e5 + 10;
// int n, m, a[N], k;


// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     int cnt = 0;
//     for(int i = 1;i <= n;i++){
//         if((int)(abs(a[i] - i)) % k) cnt++;
//     }   
//     if(cnt == 0){
//         cout << "0\n";
//         return;
//     }
//     else if(cnt == 2){
//         cout << "1\n";
//         return;
//     }
//     cout << "-1\n";
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
// int n, m, a[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     map<int,int>mp;
//     for(int i = 1;i <= n;i++){
//         int sq = sqrt(a[i]);
//         for(int j = 2;j <= sq;j++){
//             while(a[i] % j == 0){
//                 mp[j]++;
//                 a[i] /= j;
//             }
//         }
//         if(a[i] && a[i] != 1) mp[a[i]]++;
//     }
//     int ans = 0, cnt = 0;
//     for(auto& [num, v] : mp){
//         // cerr << num << ' ' << v << endl;
//         if(v >= 2) {
//             ans += v / 2;
//             if(v & 1) cnt++;            
//         }else{
//             cnt += v;
//         }
//     }
//     cout << ans + cnt / 3 << endl;

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
// int n, m, x[N], c[N], k;

// void solve(){
//     cin >> n >> k;
//     for(int i = 1;i <= k;i++) cin >> x[i];
//     for(int i = 1;i <= k;i++) {
//         cin >> c[i];
//     }
//     for(int i = 1;i <= k;i++)
//         if(c[i] - c[i-1] > x[i] - x[i - 1]){
//             cout << "NO\n";
//             return;
//         }
//     string ans = "abc";
//     char cur = 'd';
//     int last = 3;
//     char p = 'a';
//     for(int i = 1;i <= k;i++){
//         if(x[i] <= 3) continue;
//         int dc = c[i] - last;
//         for(int j = 1;j <= dc;j++) ans.push_back(cur);
//         while(ans.size() < x[i]){
//             ans.push_back(p++);
//             if(p == 'd') p = 'a';
//         }
//         cur++;
//         last = c[i];
//     }
//     cout << "YES\n";
//     cout << ans << endl;
// }

// signed main(){

//     // IO;

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
// int n, m;

// void solve(){
//     string s;
//     cin >> s;
//     int cur = '1';
//     int ans = 0;
//     for(auto c : s){
//         if(c == '0') c = '9' + 1;
//         ans += abs(c - cur);
//         cur = c;
//         ans++;
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
// int n, m;

// void solve(){
//     string s;
//     int num[300] = {0};
//     cin >> n >> m >> s;
//     for(auto c : s) num[c]++;
//     int j = 0, o = 0;
//     for(int i = 'a';i <= 'z';i++) if(num[i]){
//         if(num[i] & 1) j++;
//         else o++;
//     }
//     n -= m;
//     if(n & 1){  
//         if(j - 1 > m){
//             cout << "NO\n";
//         }else{
//             m -= (j - 1);
//             if(m & 1) cout << "NO\n";
//             else cout << "YES\n";
//         } 
//     }else{
//         if(j > m){
//             cout << "NO\n";
//         }else{
//             m -= j;
//             if(m & 1) cout << "NO\n";
//             else cout << "YES\n";
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
// const int N = 2e5 + 10;
// int n, k, a[N];

// void solve(){
//     cin >> n >> k;
//     int ans = 10;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] % k == 0){
//             ans = 0;
//             continue;
//         }
//         if(a[i] > k) ans = min(ans, k - (a[i] % k));
//         else ans = min(ans, k - a[i]);
//         // cerr << ans << endl;
//     }
//     if(k == 4 && n >= 2){
//         int d = 0;
//         for(int i = 1;i <= n;i++) if(a[i] % 2 == 0) d++;
//         if(d < 2) d = 2 - d;
//         else d = 0;
//         ans = min(d, ans);
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
// #define all(x) (x).begin(), (x).end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, k, L[N], R[N], m;


// void solve(){
//     cin >> n;
//     multiset<int>l;
//     multiset<int>r;
//     // map<pair<int,int>, int>mp;
//     char op;
//     for(int i = 1;i <= n;i++){
//         cin >> op >> L[i] >> R[i];
//         if(op == '+'){
//             // mp[{L[i], R[i]}]++;
//             l.insert(L[i]);
//             r.insert(R[i]);
//         }else{
//             // mp[{L[i], R[i]}]--;
//             // if(mp[{L[i], R[i]}] == 0){
//                 l.erase(l.find(L[i]));
//                 r.erase(r.find(R[i]));
//             // }
//         }

//         // cerr << op << ' ' << L[i] << ' ' << R[i] << endl;

//         if(l.size() >= 2){
//             if(*r.begin() < *prev(l.end())) cout << "YES\n";
//             else cout << "NO\n";
//         }else{
//             cout << "NO\n";
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
// #define all(x) (x).begin(), (x).end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, a[N], cnt[N], b[N];


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         b[i] = a[i];
//         cnt[i] = 0;
//     }
//     int ans = 0;
//     for(int i = 2;i <= n;i++)if(a[i] < a[i - 1]){
//         if(cnt[i - 1]){
//             int q = b[i - 1], p = b[i];
//             // cnt[i] = cnt[i-1] + 1;
//             if(q > p){
//                 while(p < q){
//                     p *= 2;
//                     cnt[i]++;
//                 }
//                 cnt[i] += cnt[i - 1];
//             }else{
//                 while(q < p){
//                     q *= 2;
//                     cnt[i]--;
//                 }
//                 cnt[i] += cnt[i - 1];
//                 if(q > p) cnt[i] ++;
//             }
//             // cerr << cnt[i] << ' ' << a[i] << endl;
//             for(int j = 1;j <= cnt[i] && a[i] <= 1e9;j++){
//                 a[i] *= 2;
//             }
//             // cerr << cnt[i] << ' ' << a[i] << "\n____\n";
//             // cerr << "KKONILJL\n";
//         }else{
//             while(a[i] < a[i-1]) {
//                 a[i] *= 2;
//                 cnt[i]++;
//             }
//         }
//         ans += cnt[i];
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
// #define all(x) (x).begin(), (x).end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// const int inf = 0x3f3f3f3f3f3f3f3f;
// int n, m, a[N], b[N];


// void solve(){
//     cin >> n >> m;
//     a[1] = 1;
//     for(int i = 2;i <= n;i++) cin >> a[i];
//     for(int i = 1;i <= n;i++) cin >> b[i];
//     sort(a + 1, a + 1 + n);
//     sort(b + 1, b + 1 + n);
//     int p = n;
//     while(p >= 1 && a[p] >= b[p]) p--;
//     for(int i = )
// }

// signed main(){

//     IO;

//     int t = 1;
//     cin >> t;
//     while(t--) solve();

//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// #define IOIOIO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
// #define int long long
// #define endl '\n'
// const int N = 1e5 + 10, M = 4e5 + 10;

// int n, m, A_A[N], BB[N], c[N];

// int p = 1;
// int qpow(int a,int k,int p){
//     int ret = 1;
//     while(k){
//         if(k & 1)
//             ret = ret * a % p;
//         a = a * a % p;
//         k >>= 1;
//     }
//     return ret;
// }

// void solve()
// {
// cin >> n >> m;
// A_A[1] = 1;
// for (int i=2;i<=n;++i) 
//  cin >> A_A[i];
// for (int i=1;i<=n;++i)
// cin >> BB[i];
// sort(A_A + 1, A_A + n + 1);
// sort(BB + 1, BB + n + 1);
// int now = 1;
// for (int i=1;i<=n;++i) {
//  int pos = lower_bound(A_A + 1, A_A + n + 1, BB[i]) - A_A - 1;
//  if (pos >= now) {
//  now++;
//  }
// }
// now--;
// cout << n - now << endl; 
// }
// signed main(void)
// {
// IOIOIO;
// int T = 1;
// cin >> T;
// while (T--)
// solve();
// return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, m, a, b;

// int val(int x){
//     int ret = 0;
//     while(x){
//         ret += x % 10;
//         x /= 10;
//     }
//     return ret;
// }

// void solve(){

//     string s;
//     cin >> a >> b;
//     while(val(a) % b) a++;
//     cout << a << endl;
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
// #define all(x) (x).begin(), (x).end()
// #define lson id << 1
// #define rson id << 1 | 1
// const int N = 2e5 + 10;
// int n, m, a, b;


// void solve(){
//     cin >> n;
//     string s;
//     cin >> s;
//     int p[2] = {n - 1, n - 1};
//     int cnt = 1;
//     int ans = 0;
//     while(p[1] >= 0 && p[0] >= 0){
//         if(s[p[1]] == '1'){
//             while(p[0] >= 0 && s[p[0]] == '1') p[0]--;
//             if(p[0] < 0) break;
//             swap(s[p[0]], s[p[1]]);
//             ans += p[1] - p[0]; 
//         }
//         cout << ans << ' ';
//         p[0]--;
//         p[1]--;
//     }
//     while(p[1] >= 0) {
//         cout << "-1 ";
//         p[1]--;    
//     }
//     cout << endl;
//     // cerr << n << endl << s << endl;
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
// // #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// int n, m, L[N], R[N];

// int rt, ls[N * 30], rs[N * 30], tag[N * 30], mn[N * 30], mx[N * 30], tot;
// void settag(int id, int x){
//     tag[id] += x;
//     mx[id] += x;
//     mn[id] += x;
// }
// int newSeg(){
//     ++tot;
//     ls[tot] = rs[tot] = mx[tot] = mn[tot] = tag[tot] = 0;
//     return tot;
// }
// void down(int id){
//     if(!ls[id]) ls[id] = newSeg();
//     if(!rs[id]) rs[id] = newSeg();
//     settag(ls[id], tag[id]);
//     settag(rs[id], tag[id]);
//     tag[id] = 0;
// }
// void up(int id){
//     if(!ls[id]) ls[id] = newSeg();
//     if(!rs[id]) rs[id] = newSeg();
//     mn[id] = min(mn[ls[id]], mn[rs[id]]);
//     mx[id] = max(mx[ls[id]], mx[rs[id]]);
// }
// void modify(int &id, int l, int r, int ql, int qr, int x){
//     if(!id) id = newSeg();
//     if(ql <= l && r <= qr){
//         settag(id, x);
//         return;
//     }
//     if(tag[id]) down(id);
//     int mid = l + r >> 1;
//     if(qr <= mid) modify(ls[id], l, mid, ql, qr, x);
//     else if(ql > mid) modify(rs[id], mid + 1, r, ql, qr, x);
//     else modify(ls[id], l, mid, ql, qr, x), modify(rs[id], mid + 1, r, ql, qr, x);
//     up(id);
// }

// void solve(){
//     cin >> n >> m;
//     tot = rt = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> L[i] >> R[i];
//     }
//     vector<array<int, 3>>evt;
//     evt.reserve(n * 2 + 2);
//     for(int i = 1;i <= n;i++){
//         modify(rt, 1, m, L[i], R[i], 1);
//         evt.push_back({L[i], 0, i});
//         evt.push_back({R[i], 1, i});
//     }
//     sort(all(evt));
//     // cerr << mx[1] << endl;

//     int ans = 0;
//     for(auto [p, k, id] : evt){
//         ans = max(ans, mx[1] - mn[1]);
//         if(k == 0){
//             modify(rt, 1, m, L[id], R[id], -1);
//         }else{
//             modify(rt, 1, m, L[id], R[id], 1);
//         }
//     }
//     ans = max(ans, mx[1] - mn[1]);
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
// // #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 2e5 + 10;
// const int M = N * 27;
// int n, tr[N][27], tot, fail[M], siz[M], id[N];
// string T[N], s;
// vector<int>g[M];

// int add(const string& s){
//     int i = 0, p = 0, len = s.size();   
//     while(i < len){
//         if(!tr[p][s[i] - 'a']) tr[p][s[i] - 'a'] = ++tot;
//         p = tr[p][s[i] - 'a'];
//         i++;
//     }   
//     return p;
// }
// void build(){
//     queue<int>q;
//     for(int i = 0;i < 26;i++)
//         if(tr[0][i]) q.push(tr[0][i]);
//     while(q.size()){
//         int u = q.front();
//         q.pop();
//         for(int i = 0;i < 26;i++){
//             int v = tr[u][i];
//             if(v) fail[v] = tr[fail[u]][i], q.push(v);
//             else tr[u][i] = tr[fail[u]][i];
//         }
//     }
// }
// void query(const string& s){
//     int len = s.size(), p = 0;
//     for(int k = 0;k < len;k++){
//         p = tr[p][s[k] - 'a'];
//         siz[p]++;
//     }
// }   
// void dfs(int u){
//     for(auto v : g[u]){
//         dfs(v);
//         siz[u] += siz[v];
//     }
// }


// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> T[i];
//         id[i] = add(T[i]);
//     }
//     build();
//     cin >> s;
//     query(s);
    
//     for(int i = 1;i <= tot;i++){
//         g[fail[i]].push_back(i);
//     }
//     dfs(0);

//     for(int i = 1;i <= n;i++){
//         cout << siz[id[i]] << endl; 
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
// const int M = 1e6;
// const int mod = 1e9 + 7;
// int n, tr[N][27], tot, fail[N], m;
// string T[M], S[N];
// list<int>g[N];

// int cnt[N], sumr2[N], sumr[N], L[N];

// void add(const string& s){
//     int p = 0;
//     for(int i = 0, len = s.size();i < len;i++){
//         if(!tr[p][s[i] - 'a']) tr[p][s[i] - 'a'] = ++tot;
//         p = tr[p][s[i] - 'a'];
//     }
//     L[p] = s.size();
// }
// void build(){
//     queue<int>q;
//     for(int i = 0;i < 26;i++)
//         if(tr[0][i]) q.push(tr[0][i]);
//     while(q.size()){
//         int u = q.front();
//         q.pop();
//         for(int j = 0;j < 26;j++){
//             int v = tr[u][j];
//             if(v) fail[v] = tr[fail[u]][j], q.push(v);
//             else tr[u][j] = tr[fail[u]][j];
//         }
//     }
// }
// inline int _add(int a, int b){
//     return (a + b) % mod;
// }
// inline int _sub(int a, int b){
//     return (((a - b) % mod) + mod) % mod;
// }
// inline int _pro(int a, int b){
//     return (a * b) % mod;
// }
// int query(const string& s){
//     int p = 0, mx = 0, len = s.size();
//     int ans = 0;
//     for(int i = 0, r = 1;i < len;i++, r++){
//         p = tr[p][s[i] - 'a'];
//         cnt[p]++;
//         sumr2[p] = (sumr2[p] + r * r) % mod;
//         sumr[p] = (sumr[p] + r) % mod;
//         mx = max(mx, p);
//     }
//     auto dfs = [&](auto self, int u) -> void {
//         if(u > mx) return;
//         for(auto v : g[u]){
//             self(self, v);
//             cnt[u] = (cnt[u] + cnt[v]) % mod;
//             sumr2[u] = (sumr2[u] + sumr2[v]) % mod;
//             sumr[u] = (sumr[u] + sumr[v]) % mod;
//         }
//         if(L[u]) ans = _add(ans,_add(_sub((len*sumr[u]%mod),sumr2[u]),_add((L[u]*sumr[u]%mod),(cnt[u]*(_sub(_sub(len+1,L[u]),(L[u]*len%mod)))%mod))));
//         // if(L[u]) ans = _add(ans,_add(_add(_sub(_pro(len,sumr[u]),sumr2[u]),_pro(L[u],sumr[u])),_pro(cnt[u],(_sub(_sub(len+1,L[u]),_pro(L[u],len))))));
//         cnt[u] = 0;
//         sumr2[u] = 0;
//         sumr[u] = 0;
//     };
//     dfs(dfs, 0);
//     return ans;
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++){
//         cin >> S[i];
//         add(S[i]);
//     }
//     build();
//     for(int i = 1;i <= tot;i++){
//         g[fail[i]].push_back(i);
//     }
//     for(int i = 1;i <= m;i++){
//         cin >> T[i];
//         cout << query(T[i]) << endl;
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
// int n, m;
// string s[N];

// int tr[N][27], cnt[N], tot, fail[N];
// void add(const string& s){
//     int p = 0, len = s.size();
//     for(int i = 0;i < len;i++){
//         if(!tr[p][s[i] - 'a']) tr[p][s[i] - 'a'] = ++tot;
//         p = tr[p][s[i] - 'a'];
//     }
//     cnt[p]++;
// }
// void build(){
//     queue<int>q;
//     for(int i = 0;i < 26;i++){
//         if(tr[0][i]) q.push(tr[0][i]);
//     }
//     while(q.size()){
//         int u = q.front();
//         q.pop();
//         for(int i = 0; i < 26;i++){
//             int v = tr[u][i];
//             if(v) fail[v] = tr[fail[u]][i], q.push(v);
//             else tr[u][i] = tr[fail[u]][i];
//         }
//     }
// }
// int query(const string& s){
//     int ret = 0, len = s.size(), p = 0;
//     for(int i = 0;i < len;i++){
//         p = tr[p][s[i] - 'a'];
//         for(int j = p;j && ~cnt[j];j = fail[j]){
//             ret += cnt[j];
//             cnt[j] = -1;
//         }
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++){
//         cin >> s[i];
//         add(s[i]);
//     }
//     build();
//     string T;
//     cin >> T;
//     cout << query(T) << endl;
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(t--){
//         solve();
//     }


//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// const int N = 1e6 + 10;
// int n, m;
// string s[N], T;

// list<int>g[N];

// int tr[N][27], fail[N], tot, ed[N], cnt[N];
// int add(const string& s){
//     int len = s.size(), p = 0;
//     for(int i = 0;i < len;i++){
//         if(!tr[p][s[i] - 'a']) tr[p][s[i] - 'a'] = ++tot;
//         p = tr[p][s[i] - 'a'];
//     }
//     return p;
// }
// void build(){
//     queue<int>q;
//     for(int i = 0;i < 26;i++){
//         if(tr[0][i]) q.push(tr[0][i]);
//     }
//     while(q.size()){
//         int u = q.front();
//         q.pop();
//         for(int i = 0;i < 26;i++){
//             int v = tr[u][i];
//             if(v) fail[v] = tr[fail[u]][i], q.push(v);
//             else tr[u][i] = tr[fail[u]][i];
//         }
//     }
// }
// void query(const string& s){
//     int len = s.size(), p = 0;
//     for(int i = 0;i < len;i++){
//         p = tr[p][s[i] - 'a'];
//         cnt[p]++;
//     }
//     for(int i = 1;i <= tot;i++){
//         g[fail[i]].push_back(i);
//     }
//     auto dfs = [&](auto self, int u) -> void {
//         for(auto v : g[u]){
//             self(self, v);
//             cnt[u] += cnt[v];
//         }
//     };
//     dfs(dfs, 0);
// }

// void init(){
//     for(int i = 0;i <= tot;i++){
//         g[i].clear();
//         fail[i] = cnt[i] = 0;
//         for(int j = 0;j < 26;j++){
//             tr[i][j] = 0;
//         }
//     }
//     tot = 0;
// }

// void solve(){
//     init();
//     for(int i = 1;i <= n;i++){
//         cin >> s[i];
//         ed[i] = add(s[i]);
//     }
//     build();
//     cin >> T;
//     query(T);
//     int mx = 0;
//     for(int i = 1;i <= n;i++){
//         mx = max(mx, cnt[ed[i]]);
//     }
//     cout << mx << endl;
//     for(int i = 1;i <= n;i++){
//         if(cnt[ed[i]] == mx){
//             cout << s[i] << endl;
//         }
//     }
// }

// signed main(){

//     IO;
//     int t = 1;
//     // cin >> t;
//     while(cin >> n, n){
//         solve();
//     }


//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define ls (tr[id].l)
// #define rs (tr[id].r)
// const int N = 2e5 + 10;
// const int M = N * 30;
// int n, m, a[N];

// int idx = 1;
// int tot, rt[N];
// struct node{
//     int l, r;
//     int sum;
// }tr[M];

// void up(int id){
//     tr[id].sum = tr[ls].sum + tr[rs].sum;
// }
// void modify(int& id, int l, int r, int x, int v){
//     if(!id) id = ++tot;
//     tr[id].sum += v;
//     if(l == r) return;
//     int mid = l + r >> 1;
//     if(x <= mid) modify(ls, l, mid, x, v);
//     else modify(rs, mid + 1, r, x, v);
// }
// int split(int& id, int l, int r, int ql, int qr){
//     if(!id) return 0;
//     int n = ++tot;
//     if(ql <= l && r <= qr){
//         tr[n] = tr[id];
//         id = 0;
//     }else{
//         int mid = l + r >> 1;
//         if(ql <= mid) tr[n].l = split(ls, l, mid, ql, qr);
//         if(qr > mid)  tr[n].r = split(rs, mid + 1, r, ql, qr);
//         up(id), up(n);
//     }
//     return n;
// }
// void merg(int&x, int y){
//     if(!x || !y) x |= y;
//     else{
//         tr[x].sum += tr[y].sum;
//         merg(tr[x].l, tr[y].l);
//         merg(tr[x].r, tr[y].r);
//     }
// }
// int query(int id, int l, int r, int ql, int qr){
//     if(!id) return 0;
//     if(ql <= l && r <= qr) return tr[id].sum;
//     int mid = l + r >> 1;
//     if(qr <= mid) return query(ls, l, mid, ql, qr);
//     else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
//     else return query(ls,l,mid,ql,qr) + query(rs,mid+1,r,ql,qr);
// }
// int rak(int id, int l, int r, int k){
//     if(l == r) return l;
//     int mid = l + r >> 1;
//     if(tr[ls].sum >= k) return rak(ls, l, mid, k);
//     else return rak(rs, mid + 1, r, k - tr[ls].sum);
// }
// int s_rak(int id, int l, int r, int k){
//     if(tr[id].sum < k) return -1;
//     else return rak(id, l, r, k);
// }

// void solve(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         modify(rt[1], 1, n, i, a[i]);
//     }
//     while(m--){
//         int op, p, x, y, t;
//         cin >> op;
//         switch(op){
//         case(0):
//             cin >> p >> x >> y;
//             rt[++idx] = split(rt[p], 1, n, x, y);
//             break;
//         case(1):
//             cin >> p >> t;
//             merg(rt[p], rt[t]);
//             break;
//         case(2):
//             cin >> p >> x >> t;
//             modify(rt[p], 1, n, t, x);
//             break;
//         case(3):
//             cin >> p >> x >> y;
//             cout << query(rt[p], 1, n, x, y) << endl;
//             break;
//         case(4):
//             cin >> p >> x;
//             cout << s_rak(rt[p], 1, n, x) << endl;
//             break;
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