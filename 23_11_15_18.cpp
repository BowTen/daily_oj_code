// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// const int N = 2e5 + 10;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n + 10);
//     vector<int>b(n + 10);
//     vector<int>ma(n + 10);
//     vector<int>mb(n + 10);
//     int ap = 0, bp = 0, am = N, bm = N;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(ap) am = min(am, a[i]);
//         if(a[i] == 1) ap = i;
//     }
//     for(int i = 1;i <= n;i++){
//         cin >> b[i];
//         if(bp) bm = min(bm, b[i]);
//         if(b[i] == 1) bp = i;
//     }
//     ma[1] = mb[1] = n + 1;
//     for(int i = 2;i <= n;i++){
//         ma[i] = min(ma[i-1], a[i-1]);
//         mb[i] = min(mb[i-1], b[i-1]);
//     }
//     int ans = 0;
//     int tmp = min(ap, bp) - 1;
//     ans += (tmp * (tmp + 1)) / 2;
//     if(max(ap, bp) < n - 1){
//         tmp = n - 1 - max(ap, bp);
//         ans += (tmp * (tmp + 1)) / 2;
//     }
//     if(ap != bp){
//         tmp = abs(ap - bp) - 1;
//         ans += (tmp * (tmp + 1)) / 2;
//     }


//     for(int i = 1;i <= n;i++){
//         if(ma[i] == mb[i]) ans++;
//     }
//     // for(int i = 1;i <= n;i++) cerr << ma[i] << ' ';
//     // cerr << endl;
//     // for(int i = 1;i <= n;i++) cerr << mb[i] << ' ';
//     // cerr << endl;
//     // cerr << ans << endl;
//     for(int i = 1;i <= min(ap, bp) && i < n;i++){
//         ma[i] = min(ma[i], am);
//         mb[i] = min(mb[i], bm);
//         if(ma[i] == mb[i]) ans++;
//     }
//     // for(int i = 1;i <= n;i++) cerr << ma[i] << ' ';
//     // cerr << endl;
//     // for(int i = 1;i <= n;i++) cerr << mb[i] << ' ';
//     // cerr << endl;

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
// const int N = 2e5 + 10;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n + 10);
//     vector<int>b(n + 10);
//     vector<int>pa(n + 10);
//     vector<int>pb(n + 10);
//     int ap = 0, bp = 0, am = N, bm = N;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         pa[a[i]] = i;
//     }
//     for(int i = 1;i <= n;i++){
//         cin >> b[i];
//         pb[b[i]] = i;
//     }
//     int ans = 0, l = min(pa[1], pb[1]), r = max(pa[1], pb[1]);
//     for(int i = 1;i <= n;i++){
//         int m = i + 1;
//         l = min({l, pa[i], pb[i]});
//         r = max({r, pa[i], pb[i]});
//         if((pa[m] >= l && pa[m] <= r) || (pb[m] >= l && pb[m] <= r)) continue;
//         int L = 1, R = n;
//         if(pa[m] < l) L = max(L, pa[m] + 1);
//         if(pb[m] < l) L = max(L, pb[m] + 1);
//         if(pa[m] > r) R = min(R, pa[m] - 1);
//         if(pb[m] > r) R = min(R, pb[m] - 1);
//         ans += (l - L + 1) * (R - r + 1);
//     }
//     int tmp = min(pa[1], pb[1]) - 1;
//     ans += (tmp * (tmp + 1)) / 2;
//     tmp = n - max(pa[1], pb[1]);
//     ans += (tmp * (tmp + 1)) / 2;
//     if(pa[1] != pb[1]){
//         tmp = abs(pa[1] - pb[1]) - 1;
//         ans += (tmp * (tmp + 1)) / 2;
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
// const int N = 2e5 + 10;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n + 1);
//     int cnt = 0;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         if(a[i] == 2) cnt++;
//     }
//     if(cnt & 1){
//         cout << "-1\n";
//         return;
//     }else{
//         int s = 0;
//         for(int i = 1;i <= n;i++){
//             if(a[i] == 2) s ++;
//             if(s == cnt / 2){
//                 cout << i << endl;
//                 return;
//             }
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
// const int N = 2e5 + 10;


// void solve(){
//     int n, a = 0, b = 0, as = 0, bs = 0, pw = 1;
//     cin >> n;
//     while(n){
//         int d = n % 10, d2 = d / 2;
//         n /= 10;
//         // cerr <<d << ' ' << d2 << endl;
//         a += d2 * pw;
//         b += d2 * pw;
//         as += d2;
//         bs += d2;
//         if(d & 1){
//             if(as < bs){
//                 as++;
//                 a += pw;
//             }else{
//                 bs++;
//                 b += pw;
//             }
//         }
//         // cerr << a << ' ' << b << endl;
//         pw *= 10;
//     }
//     cout << a << ' ' << b << endl;
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


// void solve(){
//     int n, m;
//     cin >> n;
//     m = n * 2;
//     int s = m * (1 + m) / 2;
//     s -= n * (n - 1) / 2;
//     if(s % n){
//         cout << "No\n";
//         return;
//     }
//     cout << "Yes\n";
//     int a = s / n;
//     int q = 1, p = a - 1, k = p - 1;;
//     while(p <= m){
//         cout << q << ' ' << p << endl;
//         q++, p++;
//     }
//     q--;
//     p = k;
//     k = q;
//     q += (p - q) / 2;
//     while(q > k){
//         cout << q << ' ' << p << endl;
//         q--;
//         p--;
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
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;

// int qpow(int a, int x){
//     int ret = 1;
//     while(x > 0){
//         if(x & 1) ret = ret * a % mod;
//         a = a * a % mod;
//         x >>= 1;
//     }
//     return ret;
// }

// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n + 10);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     a[0] = -3e9;
//     a[n + 1] = 3e9;
//     int ans = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = i + 1;j <= n;j++){
//             int d = a[j] - a[i];
//             int l = 0, r = i - 1;
//             while(l <= r){
//                 int mid = l + r >> 1;
//                 int s = a[i] - a[mid];
//                 if(s > d) l = mid + 1;
//                 else r = mid - 1;
//             } 
//             int L = r;
//             l = j + 1, r = n + 1;
//             while(l <= r){
//                 int mid = l + r >> 1;
//                 int s = a[mid] - a[j];
//                 if(s >= d) r = mid - 1;
//                 else l = mid + 1;
//             }
//             int R = l;
//             ans = (ans + qpow(2, L + n - R + 1)) % mod;
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



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n;

// int tr[N];
// int lowbit(int x){
//     return x & -x;
// }
// void update(int x, int v){
//     while(x <= n){
//         tr[x] = max(tr[x], v);
//         x += lowbit(x);
//     }
// }
// int getmax(int x){
//     int ret = -inf;
//     while(x){
//         ret = max(ret, tr[x]);
//         x -= lowbit(x);
//     }
//     return ret;
// }

// void solve(){
//     cin >> n;
//     for(int i = 1;i <= n;i++) tr[i] = -inf;
//     vector<int>a(n + 10);
//     vector<int>pre(n + 10);
//     vector<int>f(n + 10);
//     vector<int>idx;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         // if(a[i] >= 0) update(i, 0);
//     }
//     for(int i = 1;i <= n;i++){
//         pre[i] = pre[i-1] + a[i];
//         idx.push_back(pre[i]);
//     }
//     sort(all(idx));
//     idx.erase(unique(all(idx)), idx.end());
//     vector<int>id(n + 10);
//     for(int i = 1;i <= n;i++){
//         id[i] = lower_bound(all(idx), pre[i]) - idx.begin() + 1;
//     }

//     for(int i = 1;i <= n;i++){
//         f[i] = max(f[i-1], getmax(id[i]) + i);
//         if(a[i] >= 0) f[i] = max(f[i], 0ll);
//         if(pre[i] >= 0) f[i] = i;
//         update(id[i], f[i] - i);

//         // cerr << f[i] << ' ';
//     }

//     cout << f[n] << endl;
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
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n;

// void solve(){
//     cin >> n;
//     int a = 1, b = 0;
//     n--;
//     int d = 2;
//     int p = 0;
//     while(n > 0) {
//         if(p <= 1){
//             b += min(n, d);
//             n -= min(n, d);
//         }else{
//             a += min(n, d);
//             n -= min(n, d);
//         }
//         d++;
//         p = (p + 1) % 4;
//     }
//     cout << a << ' ' << b << endl;
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
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n;

// void solve(){
//     cin >> n;
//     int a[2] = {0, 1}, b[2] = {0};
//     n--;
//     int d = 2, st = 2;
//     int p = 0;
//     while(n > 0) {
//         int x = min(n, d);
//         if(p <= 1){
//             b[0] += x / 2;
//             b[1] += x / 2;
//             if(x & 1) b[st & 1]++;
//         }else{
//             a[0] += x / 2;
//             a[1] += x / 2;
//             if(x & 1) a[st & 1]++;
//         }
//         n -= x;
//         st += x;
//         d++;
//         p = (p + 1) % 4;
//     }
//     cout << a[1] << ' ' << a[0] << ' ' << b[1] << ' ' << b[0] << endl;
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
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, w, h;

// void solve(){
//     cin >> n >> w >> h;
//     vector<int>a(n + 10);
//     vector<int>b(n + 10);
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//         // cout << '[' << a[i] - w << ", " << a[i] + w << "] ";
//     }
//     // cout << endl;
//     for(int i = 1;i <= n;i++){
//         cin >> b[i];
//         // cout << '[' << b[i] - h << ", " << b[i] + h << "] ";

//     }
//     if(h > w){
//         cout << "NO\n";
//         return;
//     }

//     int l = 0, r = 0;
//     for(int i = 1;i <= n;i++){
//         if(a[i] + w < b[i] + h){
//             r = max(r, (b[i] + h) - (a[i] + w));
//         }
//         if(a[i] - w > b[i] - h){
//             l = max(l, (a[i] - w) - (b[i] - h));
//         }
//     }

//     bool f = true;
//     for(int i = 1;i <= n;i++){
//         if(a[i] + w + r < b[i] + h || a[i] - w + r > b[i] - h){
//             f = false;
//             break;
//         }
//     }
//     if(f){
//         cout << "YES\n";
//         return;
//     }
//     f = true;
//     for(int i = 1;i <= n;i++){
//         if(a[i] + w - l < b[i] + h || a[i] - w - l > b[i] - h){
//             f = false;
//             break;
//         }
//     }
//     if(f){
//         cout << "YES\n";
//         return;
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
// #define all(x) (x).begin(), (x).end()
// const int N = 2e5 + 10;
// const int mod = 1e9 + 7;
// const int inf = 2e9;
// int n, w, h;

// void solve(){
//     cin >> n;
//     vector<int>a(n);
//     for(auto& e : a) cin >> e;
//     sort(all(a));
//     int ans = 0;
//     int cur = 1;
//     for(int i = 0;i < n;i++){
//         if(a[i] >= cur){
//             ans += a[i] - cur;
//             cur++;
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
