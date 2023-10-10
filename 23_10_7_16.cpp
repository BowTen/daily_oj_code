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