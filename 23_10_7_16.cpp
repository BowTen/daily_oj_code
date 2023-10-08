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